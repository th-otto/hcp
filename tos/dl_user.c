/*
 * HypView - (c)      - 2006 Philipp Donze
 *               2006 -      Philipp Donze & Odd Skancke
 *
 * A replacement hypertext viewer
 *
 * This file is part of HypView.
 *
 * HypView is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * HypView is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HypView; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "hv_defs.h"
#include "hypdebug.h"
#include "tos/pchelp.h"
#if defined(HYPTREE_APP)
#include "hyptree.h"
#else
#include "hypview.h"
#endif

#ifdef HYPTREE_APP
#define OpenFileInWindow(win, path, chapter, node, find_default, new_window, no_message) tv_open_window(path)
#endif


/******************************************************************************/
/*** Events --------------------------------------------------------------- ***/
/******************************************************************************/

void DoButton(EVNT *event)
{
	UNUSED(event);

#if USE_BUBBLEGEM
	if (event->button == 2)
		Bubble(event->mx, event->my);
#endif
}

/*** ---------------------------------------------------------------------- ***/

void DoUserEvents(EVNT *event)
{
	if (event->mwhich & MU_MESAG)
	{
		switch (event->msg[0])
		{
		case AC_OPEN:
			{
				WINDOW_DATA *win;
				_WORD id = -1;
				
#ifndef HYPTREE_APP
				/*
				 * if we have to start remarker, do that now:
				 * when we are on SingleTOS,
				 * and open a window first, then starting remarker
				 * would just lead to an immediate AC_CLOSE message.
				 * maybe FIXME: we rely here to get a VA_START message
				 * from remarker, should be checked if we don't
				 */
				if (gl_profile.remarker.run_on_startup)
				{
					id = StartRemarker(NULL, remarker_check, FALSE);
					if (id < 0)
						id = StartRemarker(NULL, remarker_startup, FALSE);
				}
#endif
				if (id < 0 || _AESnumapps != 1)
				{
#ifndef HYPTREE_APP
					hfix_palette(vdi_handle);
#endif
					va_proto_init(NULL);
					win = top_window();
					if (win == NULL && !empty(gl_profile.viewer.last_file))
					{
						win = OpenFileInWindow(NULL, gl_profile.viewer.last_file, NULL, gl_profile.viewer.last_node, FALSE, TRUE, FALSE);
					}
		
					if (win == NULL)
					{
						if (!empty(gl_profile.viewer.default_file))
						{
							char *filename = path_subst(gl_profile.viewer.default_file);
							if (OpenFileInWindow(win, filename, NULL, HYP_NOINDEX, FALSE, TRUE, FALSE) == NULL)
							{
								g_freep(&gl_profile.viewer.default_file);
#if 0
								HypProfile_SetChanged();
#endif
								SelectFileLoad(NULL);
							}
							g_free(filename);
						} else
						{
							SelectFileLoad(NULL);
						}
					} else
					{
						SendTopped(win->whandle);
					}
				}
			}
			event->mwhich &= ~MU_MESAG;
			break;

		case AC_CLOSE:
			event->mwhich &= ~MU_MESAG;
			{
				/* window handles are no longer valid when we receive this message */
				CHAIN_DATA *ptr;
				for (ptr = all_list; ptr; ptr = ptr->next)
					ptr->whandle = -1;
			}
			RemoveItems();
			modal_items = -1;
#ifndef HYPTREE_APP
			MarkerSaveToDisk(FALSE);
#endif
			va_proto_init(NULL);
			break;

		case AC_HELP:
#ifndef HYPTREE_APP
			{
				char **pdata = (char **) &event->msg[3];
				char *data = *pdata;
	
				if (data != NULL)
				{
					char *name;
					
					HYP_DBG(("AC_HELP from %d: <%s>", event->msg[1], printnull(data)));
					name = hyp_conv_to_utf8(hyp_get_current_charset(), data, STR0TERM);
					search_allref(NULL, name, FALSE);
					g_free(name);
				}
			}
#endif
			event->mwhich &= ~MU_MESAG;
			break;

		case CH_EXIT:
#ifndef HYPTREE_APP
			HypfindFinish(event->msg[3], event->msg[4]);
#endif
			event->mwhich &= ~MU_MESAG;
			break;
		}

	} else if (event->mwhich & MU_KEYBD)
	{
		_WORD ascii = event->key;
		_WORD kstate = event->kstate;

		ConvertKeypress(&ascii, &kstate);

		ascii = ascii & 0xff;

		if (kstate & KbCTRL)
		{
			if (ascii == 'W')
			{
				short global_cycle = (kstate & KbSHIFT) ? !gl_profile.viewer.av_window_cycle : gl_profile.viewer.av_window_cycle;

				if (!global_cycle || !SendAV_SENDKEY(kstate & ~KbSHIFT, event->key))
				{
					CycleItems();
				}
				event->mwhich &= ~MU_KEYBD;
			}
		}
	}
}

/******************************************************************************/
/*** menu selection ------------------------------------------------------- ***/
/******************************************************************************/

#if USE_MENU

static _WORD __CDECL HandleAbout(struct HNDL_OBJ_args args)
{
	OBJECT	*tree;
	GRECT rect;

	wdlg_get_tree(args.dialog, &tree, &rect);		/* get tree address */

	if (args.obj < 0)								/* event or object? */
	{
		if (args.obj == HNDL_CLSD)					/* closer selected? */
			return 0;								/* quit */ 
		if (args.obj == HNDL_MESG)
			SpecialMessageEvents(args.dialog, args.events);
	} else
	{
		tree[args.obj].ob_state &= ~OS_SELECTED;
		switch(args.obj)
		{
		case PROG_OK: 
			return 0;
		}
	}
	return 1;										/* continue */
}


static void do_about(void)
{
	OBJECT *tree = rs_tree(ABOUT_DIALOG);
	GRECT big, little;
	
	sprintf(tree[PROG_NAME].ob_spec.free_string, "%s %s", gl_program_name, gl_program_version);
	sprintf(tree[PROG_DATE].ob_spec.free_string, rs_string(PROGINFO_FROM), gl_compile_date);

	if (has_window_dialogs())
	{
		OpenDialog(HandleAbout, tree, rs_string(WDLG_ABOUT), -1, -1, NULL);
	} else
	{
		_WORD obj;
		
		little.g_x = little.g_y = little.g_w = little.g_h = 0;
		do {
			form_center_grect(tree, &big);
			wind_update(BEG_UPDATE);
			form_dial_grect(FMD_START, &little, &big);
			objc_draw_grect(tree, ROOT, MAX_DEPTH, &big);
			obj = form_do(tree, 0);
			form_dial_grect(FMD_FINISH, &little, &big);
			wind_update(END_UPDATE);
			if (obj > 0)
			{
				tree[obj].ob_state &= ~OS_SELECTED;
			}
		} while (obj > 0 && obj != PROG_OK);
	}
}


void SelectMenu(short title, short entry)
{
	UNUSED(title);
	switch (entry)
	{
	case ME_ABOUT:
		do_about();
		break;
	case ME_CLOSE:
		SendCloseWindow(top_window());
		break;
	case ME_QUIT:
		doneFlag = TRUE;
		if (_app)
			quitApp = TRUE;
		break;
	}
}
#endif


/******************************************************************************/
/*** dialog objects with extended edit fields ----------------------------- ***/
/******************************************************************************/

#if USE_LONGEDITFIELDS
LONG_EDIT long_edit[] = {
	{ MAIN, MA_EDIT, 20 },
	{ ABOUT, AB_EDIT, 40 }
};

short long_edit_count = (short) (sizeof(long_edit) / sizeof(LONG_EDIT));
#endif

/******************************************************************************/
/*** Drag&Drop protocol --------------------------------------------------- ***/
/******************************************************************************/

#if USE_DRAGDROP
/*
	Hier koennen je nach Zielobjekt <obj> die D&D-Daten <data> anders
	ausgewertet werden. <data> hat eines der gewuenschten Formate
	(<format>).
*/
void DD_Object(DIALOG *dial, GRECT *rect, OBJECT *tree, short obj, char *data, unsigned long format)
{
	char **argv;
	int i;
	
	UNUSED(format);
	UNUSED(obj);
	UNUSED(tree);
	UNUSED(rect);
	UNUSED(dial);
	
	argv = split_av_parameter(data);
	if (argv)
	{
		for (i = 0; argv[i]; i++)
			;
	}
	g_strfreev(argv);
}

/*** ---------------------------------------------------------------------- ***/

/*
 * select target format depending on object tree and object
 */
void DD_DialogGetFormat(OBJECT *tree, short obj, unsigned long format[])
{
	short i;

	UNUSED(obj);
	UNUSED(tree);

	for (i = 0; i < MAX_DDFORMAT; i++)
		format[i] = 0;

	format[0] = 0x41524753L;			/* 'ARGS' */
}
#endif

/******************************************************************************/
/*** AV protocol ---------------------------------------------------------- ***/
/******************************************************************************/

/*
 * The server activates the program and passes a command line.
 */
void DoVA_START(_WORD msg[8])
{
	if (modal_items < 0)				/* only do this if we have no modal dialog */
	{
		char *data;

		data = *(char **) &msg[3];
		if (data != NULL)
		{
			char *arg;
			char **argv;
			char *chapter = NULL;
			char *filename = NULL;
			char *freeme = NULL;
			WINDOW_DATA *win;
			int argc;
			int i;
			gboolean start_if_empty = TRUE;
			hyp_nodenr nodenr = HYP_NOINDEX;
			
#ifdef NO_UTF8
			arg = g_strdup(data);
#else
			arg = hyp_conv_to_utf8(hyp_get_current_charset(), data, STR0TERM);
#endif
			SendAV_STARTED(msg);
			win = top_window();
			argv = split_av_parameter(arg);
			argc = g_strv_length(argv);
			i = 0;
			if (argc > 0)
			{
				filename = path_subst(argv[i++]);
#ifndef HYPTREE_APP
				if (strcmp(filename, "-S1") == 0 ||
					strcmp(filename, "-s1") == 0||
					strcmp(filename, "-t") == 0)
				{
					/* start message from remarker or hyptree */
					g_free(filename);
					filename = path_subst(argv[i++]);
					start_if_empty = FALSE;
					if (empty(filename) && StartRemarker(NULL, remarker_check, FALSE) == msg[1])
						start_if_empty = TRUE;
					if (i < argc && !av_can_quote(msg[1]))
					{
						/*
						 * hyptree seems to always send the chapter name unquoted :(
						 */
						chapter = av_cmdline((const char *const*)argv, i, FALSE, FALSE);
						freeme = chapter;
					}
				} else if (strcmp(filename, "-S0") == 0 || strcmp(filename, "-s0") == 0)
				{
					/* stop message from remarker or hyptree */
					g_free(filename);
					filename = NULL;
					start_if_empty = FALSE;
				} else if (strcmp(filename, "-r1") == 0)
				{
					/* notification from remarker */
					g_free(filename);
					filename = NULL;
					start_if_empty = FALSE;
					if (win)
					{
						DOCUMENT *doc = win->data;
						doc->buttons.remarker = TRUE;
						ToolbarUpdate(win, TRUE);
					}
				} else if (strcmp(filename, "-r0") == 0)
				{
					/* notification from remarker */
					g_free(filename);
					filename = NULL;
					start_if_empty = FALSE;
					if (win)
					{
						DOCUMENT *doc = win->data;
						doc->buttons.remarker = FALSE;
						ToolbarUpdate(win, TRUE);
					}
				}
#endif
				if (i < argc && chapter == NULL)
					chapter = argv[i];
			} else
			{
				filename = NULL;
			}
			
			if (empty(filename) && start_if_empty)
			{
				g_free(filename);
				if (win)
				{
					/* no filename, but have window: just put in on top */
					filename = NULL;
#ifndef HYPTREE_APP
					StartRemarker(win, remarker_update, TRUE);
#endif
					if (win)
						SendTop(win->whandle);
				} else
				{
					if (!empty(gl_profile.viewer.last_file))
					{
						filename = g_strdup(gl_profile.viewer.last_file);
						nodenr = gl_profile.viewer.last_node;
					} else
					{
						filename = path_subst(empty(gl_profile.viewer.default_file) ? gl_profile.viewer.catalog_file : gl_profile.viewer.default_file);
					}
					chapter = NULL;
				}
			}
			if (empty(chapter))
			{
				chapter = NULL;
				if (nodenr == HYP_NOINDEX)
					nodenr = 0;
			} else if (strcmp(chapter, hyp_default_main_node_name) == 0)
			{
				nodenr = 0;
			}
			if (!empty(filename))
			{
				win = OpenFileInWindow(win, filename, chapter, nodenr, TRUE, gl_profile.viewer.va_start_newwin, FALSE);
			}
			g_free(freeme);
			g_strfreev(argv);
			g_free(filename);
			g_free(arg);
		} else
		{
			WINDOW_DATA *win = top_window();

			SendAV_STARTED(msg);
			if (gl_profile.viewer.va_start_newwin == 2 || !win)
				win = NULL;
			if (!empty(gl_profile.viewer.default_file))
			{
				char *filename = path_subst(gl_profile.viewer.default_file);
				win = OpenFileInWindow(win, filename, NULL, HYP_NOINDEX, FALSE, gl_profile.viewer.va_start_newwin, FALSE);
				g_free(filename);
			} else
			{
				SelectFileLoad(win);
			}
		}
	} else
	{
		SendAV_STARTED(msg);
	}
}

/*** ---------------------------------------------------------------------- ***/

void DoVA_DRAGACCWIND(_WORD msg[8])
{
	if (modal_items < 0)		/* only do this if we have no modal dialog */
	{
		char *data;

		data = *(char **) &msg[6];
		if (data != NULL)
		{
			char *arg;
			WINDOW_DATA *win;
			char **argv;
			
			HYP_DBG(("VA_DRAGACCWIND from %d: <%s>", msg[1], printnull(data)));
#ifdef NO_UTF8
			arg = g_strdup(data);
#else
			arg = hyp_conv_to_utf8(hyp_get_current_charset(), data, STR0TERM);
#endif
			argv = split_av_parameter(arg);

			win = find_window_by_whandle(msg[3]);
			if (win && win->owner != gl_apid)
				win = NULL;
			
			if (argv && !empty(argv[0]))
				win = OpenFileInWindow(win, argv[0], NULL, HYP_NOINDEX, FALSE, gl_profile.viewer.va_start_newwin, FALSE);
			g_strfreev(argv);
			g_free(arg);
		}
	}
}
