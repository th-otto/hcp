#include "hv_defs.h"
#include "hypdebug.h"
#include "resource.rh"
#include "w_draw.h"

/******************************************************************************/
/*** ---------------------------------------------------------------------- ***/
/******************************************************************************/

void SelectAll(WINDOW_DATA *win)
{
	BlockSelectAll(win, &win->selection);
	SendRedraw(win);
}

/*** ---------------------------------------------------------------------- ***/

void RemoveSelection(WINDOW_DATA *win)
{
	if (win->selection.valid)
	{
		win->selection.valid = FALSE;				/* invalidate selection */
		SendRedraw(win);
	}
}

/*** ---------------------------------------------------------------------- ***/

void DrawSelection(WINDOW_DATA *win)
{
	GRECT work;
	_WORD x1, y1, x2, y2;
	GRECT gr;
	short vis_height;
	HDC hdc;
	
	if (!win->selection.valid)				/* is something selected? */
		return;

	WindowCalcScroll(win);
	work = win->scroll;

	/* calculate window-relative coordinates of selection */
	x1 = (_WORD)(win->selection.start.x - win->docsize.x);
	y1 = (_WORD)(win->selection.start.y - win->docsize.y);
	x2 = (_WORD)(win->selection.end.x - win->docsize.x);
	y2 = (_WORD)(win->selection.end.y - win->docsize.y);

	vis_height = work.g_h;
	if ((y1 >= vis_height) || (y2 < 0))
		return;

	hdc = win->draw_hdc;
	
	/* start and end not on the same line */
	if (y1 != y2)
	{
		if (y1 < 0)
		{
			y1 = -win->y_raster;
			x1 = 0;
		} else if (x1 <= work.g_w)
		{
			/* draw from start of block to lineend */
			gr.g_x = work.g_x + x1;
			gr.g_y = work.g_y + y1;
			gr.g_w = work.g_w;
			gr.g_h = win->y_raster;
			W_Invert_Rect(hdc, &gr);
		}
		
		if (y2 > vis_height)
		{
			y2 = work.g_h;
			x2 = work.g_w;
		} else if (x2 > 0)
		{
			/* draw from start of line to blockend */
			gr.g_x = work.g_x;
			gr.g_y = work.g_y + y2;
			gr.g_w = x2;
			gr.g_h = win->y_raster;
			W_Invert_Rect(hdc, &gr);
		}

		/* draw whole lines */
		if (y2 > y1 + win->y_raster)
		{
			gr.g_x = work.g_x;
			gr.g_y = work.g_y + y1 + win->y_raster;
			gr.g_w = work.g_w;
			gr.g_h = y2 - (y1 + win->y_raster);
			W_Invert_Rect(hdc, &gr);
		}
	} else	/* start and end on same line */
	{
		/* Nur die Aenderung zeichnen */
		gr.g_x = work.g_x + x1;
		gr.g_y = work.g_y + y1;
		gr.g_w = x2 - x1;
		gr.g_h = win->y_raster;
		W_Invert_Rect(hdc, &gr);
	}
}

/*** ---------------------------------------------------------------------- ***/

static void GetMouseState(WINDOW_DATA *win, int *x, int *y, int *buttons)
{
	POINT p;
	
	GetCursorPos(&p);
	ScreenToClient(win->textwin, &p);
	*x = p.x;
	*y = p.y;
	*buttons = 0;
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
		*buttons += 1;
	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
		*buttons += 2;
	if (GetAsyncKeyState(VK_MBUTTON) & 0x8000)
		*buttons += 4;
}

/*** ---------------------------------------------------------------------- ***/

void MouseSelection(WINDOW_DATA *win, int mx, int my, gboolean extend)
{
	DOCUMENT *doc = win->data;
	GRECT work;
	int x, y;
	WP_UNIT ox, oy;
	TEXT_POS start, end, newpos;
	WP_UNIT scroll_x = 0, scroll_y = 0;
	HDC hdc = GetDC(win->textwin);
	int bstate;
	
	WindowCalcScroll(win);
	work = win->scroll;

	/* set clipping rectangle */
	SetRectRgn(win->cliprgn, work.g_x, work.g_y, work.g_x + work.g_w, work.g_y + work.g_h);
	SelectClipRgn(hdc, win->cliprgn);

	/* shift pressed? -> extend selection */
	if (extend && win->selection.valid)
	{
		start = win->selection.start;
		end = win->selection.end;
		if (end.y < win->docsize.y)
			oy = -win->y_raster;
		else if (end.y > win->docsize.y + work.g_h)
			oy = work.g_h + win->y_raster;
		else
			oy = end.y - win->docsize.y;
		ox = end.x - win->docsize.x;
		goto shift_entry;
	} else
	{
		/* removes old selection */
		if (win->selection.valid)
			RemoveSelection(win);
		win->selection.valid = FALSE;
		
		x = mx - work.g_x;
		y = my - work.g_y;
		y -= y % win->y_raster;

		doc->getCursorProc(win, x, y, &start);
		end = start;
	}

	for (;;)
	{
		ox = end.x - win->docsize.x;
		oy = end.y - win->docsize.y;

		GetMouseState(win, &mx, &my, &bstate);

		{
			int nbs, nmy, nmx;
			
			GetMouseState(win, &nmx, &nmy, &nbs);
			while (mx == nmx && my == nmy && bstate == nbs)
			{
				if (nmy > work.g_y + work.g_h || nmy < work.g_y ||
					nmx > work.g_x + work.g_w || nmx < work.g_x)
					break;
				GetMouseState(win, &nmx, &nmy, &nbs);
			}
			mx = nmx;
			my = nmy;
			bstate = nbs;
		}
		/* leave loop if button has been released */
		if ((bstate & 1) == 0)
			break;

	  shift_entry:
		/* mouse coordinates relative to actual working area */
		x = mx - work.g_x;
		y = my - work.g_y;

		/* mouse in work area? */
		if (x < 0)
		{
			x = -1;
			scroll_x = -win->x_raster;
		} else if (x >= work.g_w)
		{
			x = work.g_w;
			scroll_x = win->x_raster;
		} else
		{
			scroll_x = 0;
		}

		if (y < 0)
		{
			y = -win->y_raster;
			scroll_y = -win->y_raster;
			scroll_y *= 1 - ((my - work.g_y) >> 6);
		} else if (y >= work.g_h)
		{
			y = work.g_h;
			scroll_y = win->y_raster;
			scroll_y *= 1 + ((my - work.g_y - work.g_h) >> 6);
		} else
		{
			scroll_y = 0;
		}
		
		/* do we have to scroll? */
		if (scroll_x || scroll_y)
		{
			/* try to scroll inside window */
			WP_UNIT scrolled_x = win->docsize.x;
			WP_UNIT scrolled_y = win->docsize.y;
			if (hv_scroll_window(win, scroll_x, scroll_y))
			{
				scrolled_x = win->docsize.x - scrolled_x;
				scrolled_y = win->docsize.y - scrolled_y;

				oy -= scrolled_y;			/* did we scroll in y-direction? */
				ox -= scrolled_x;			/* did we scroll in x-direction? */
				UpdateWindow(win->textwin);
			}
		}

		/* calculate cursor position in text */
		doc->getCursorProc(win, x, y, &newpos);

		x = (int)(newpos.x - win->docsize.x);
		y = newpos.y - (win->docsize.y);
		if (y != oy)
		{
			GRECT gr;
			int py1, py2;
			int px1, px2;

			if (y < oy)					/* has selection been moved backwards? */
			{
				px1 = x;
				py1 = y;
				px2 = ox;
				py2 = oy;
			} else						/* has selection been moved forwards? */
			{
				px1 = ox;
				py1 = oy;
				px2 = x;
				py2 = y;
			}

			/* draw till end of line */
			if (px1 < work.g_w - 1)
			{
				gr.g_x = work.g_x + px1;
				gr.g_y = work.g_y + py1;
				gr.g_w = work.g_w;
				gr.g_h = win->y_raster;
				W_Invert_Rect(hdc, &gr);
			}

			/* draw whole lines */
			py1 += win->y_raster;

			if (py1 < py2)
			{
				gr.g_x = work.g_x;
				gr.g_y = work.g_y + py1;
				gr.g_w = work.g_w;
				gr.g_h = py2 - py1;
				W_Invert_Rect(hdc, &gr);
			}
			if (px2 > 0)
			{
				/* draw from beginning of line */
				gr.g_x = work.g_x;
				gr.g_y = work.g_y + py2;
				gr.g_w = px2;
				gr.g_h = win->y_raster;
				W_Invert_Rect(hdc, &gr);
			}
		} else if (x != ox)
		{
			int px1, px2;
			GRECT gr;

			if (x < ox)
			{
				px1 = x;
				px2 = ox;
			} else
			{
				px1 = ox;
				px2 = x;
			}

			/* draw only changes */
			gr.g_x = work.g_x + px1;
			gr.g_y = work.g_y + (_WORD)oy;
			gr.g_w = px2 - px1;
			gr.g_h = win->y_raster;
			W_Invert_Rect(hdc, &gr);
		}


		if (scroll_x || scroll_y)
		{
			/*
			 * small delay to make scrolling usable on fast machines
			 */
			/* XXX Add some config to this */
			Sleep(100);
		}

		end = newpos;

		if ((start.line == end.line) && (start.offset == end.offset))
		{
			win->selection.valid = FALSE;
		} else
		{
			win->selection.valid = TRUE;
			if (start.line < end.line)
			{
				win->selection.start.line = start.line;
				win->selection.start.y = start.y;
				win->selection.start.offset = start.offset;
				win->selection.start.x = start.x;
				win->selection.end.line = end.line;
				win->selection.end.y = end.y;
				win->selection.end.offset = end.offset;
				win->selection.end.x = end.x;
			} else if (start.line > end.line)
			{
				win->selection.start.line = end.line;
				win->selection.start.y = end.y;
				win->selection.start.offset = end.offset;
				win->selection.start.x = end.x;
				win->selection.end.line = start.line;
				win->selection.end.y = start.y;
				win->selection.end.offset = start.offset;
				win->selection.end.x = start.x;
			} else
			{
				win->selection.start.line = start.line;
				win->selection.start.y = start.y;
				win->selection.end.line = start.line;
				win->selection.end.y = start.y;

				if (start.x < end.x)
				{
					win->selection.start.offset = start.offset;
					win->selection.start.x = start.x;
					win->selection.end.offset = end.offset;
					win->selection.end.x = end.x;
				} else
				{
					win->selection.start.offset = end.offset;
					win->selection.start.x = end.x;
					win->selection.end.offset = start.offset;
					win->selection.end.x = start.x;
				}
			}
		}
	}
	
	ReleaseDC(win->textwin, hdc);
}
