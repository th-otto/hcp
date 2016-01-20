#include "hv_gtk.h"
#include "hypdebug.h"


#define MAX_MARKEN		10
#define UNKNOWN_LEN		10
#define PATH_LEN		128
#define NODE_LEN		40


typedef struct
{
	hyp_nodenr node_num;
	short line;
	char unknown[UNKNOWN_LEN];
	char path[PATH_LEN];				/* full path */
	char node_name[NODE_LEN];			/* display title */
} MARKEN;

static gboolean marken_change;
static MARKEN marken[MAX_MARKEN];

/******************************************************************************/
/*** ---------------------------------------------------------------------- ***/
/******************************************************************************/

static void MarkerDelete(short num)
{
	char *dst;
	
	memset(&marken[num], 0, sizeof(MARKEN));
	marken[num].node_num = HYP_NOINDEX;
	dst = marken[num].node_name;
	strcpy(dst, _("free"));
}

/*** ---------------------------------------------------------------------- ***/

void MarkerSave(DOCUMENT *doc, short num)
{
	WINDOW_DATA *win = doc->window;
	const char *src;
	char *dst, *end;

	/* avoid illegal parameters */
	if (num < 0 || num >= MAX_MARKEN)
		return;

	marken[num].node_num = doc->getNodeProc(doc);
	marken[num].line = 0; /* YYY: win->docsize.y */
	UNUSED(win); /* YYY */
	strncpy(marken[num].path, doc->path, PATH_LEN - 1);
	marken[num].path[PATH_LEN - 1] = 0;

	/* copy marker title */
	src = doc->window_title;
	dst = marken[num].node_name;
	end = &marken[num].node_name[NODE_LEN - 1];
	while (dst < end)
	{
		if (*src)
			*dst++ = *src++;
		else
			break;
	}
	if (dst < end)
		*dst++ = ' ';
	if (dst < end)
		*dst++ = ' ';
	*dst = 0;

	{
		char ZStr[255];
		long len;

		strcpy(ZStr, "(");
		src = hyp_basename(marken[num].path);
		strcat(ZStr, src);
		strcat(ZStr, ") ");
		len = strlen(ZStr);
		if (strlen(marken[num].node_name) + len > NODE_LEN)
			marken[num].node_name[NODE_LEN - len] = '\0';
		strcat(marken[num].node_name, ZStr);
	}

	marken_change = TRUE;
}

/*** ---------------------------------------------------------------------- ***/

void MarkerShow(DOCUMENT *doc, short num, gboolean new_window)
{
	WINDOW_DATA *win = doc->window;

	/* avoid illegal parameters */
	if (num < 0 || num >= MAX_MARKEN)
		return;

	if (marken[num].node_num != HYP_NOINDEX)
	{
		win = OpenFileInWindow(win, marken[num].path, NULL, marken[num].node_num, TRUE, new_window, FALSE);
		if (win != NULL)
		{
			doc = win->data;
			GotoPage(doc, marken[num].node_num, marken[num].line, FALSE);
		}
	}
}

/*** ---------------------------------------------------------------------- ***/

static void marker_selected(GtkWidget *w, void *user_data)
{
	DOCUMENT *doc = (DOCUMENT *)user_data;
	void *psel = g_object_get_data(G_OBJECT(w), "item-num");
	int sel = (int)(intptr_t)psel;
	WINDOW_DATA *win = doc->window;
	GdkModifierType mask;

	gdk_display_get_pointer(gtk_widget_get_display(win->hwnd), NULL, NULL, NULL, &mask);
	if (sel >= 0 && sel < MAX_MARKEN)
	{
		if (mask & GDK_SHIFT_MASK)
		{
			MarkerSave(doc, sel);
		} else if (marken[sel].node_num == HYP_NOINDEX)
		{
			char *buff;

			buff = g_strdup_printf(_("Do you want to add\n%s\nto your bookmarks?"), doc->window_title);
			if (ask_yesno(GTK_WINDOW(win->hwnd), buff))
				MarkerSave(doc, sel);
			g_free(buff);
		} else
		{
			if (mask & GDK_MOD1_MASK)
			{
				char *buff;

				buff = g_strdup_printf(_("Do you want to remove\n%s\nfrom your bookmarks?"), marken[sel].node_name);
				if (ask_yesno(GTK_WINDOW(win->hwnd), buff))
				{
					MarkerDelete(sel);
					marken_change = TRUE;
				}
				g_free(buff);
			} else
			{
				MarkerShow(doc, sel, (mask & GDK_CONTROL_MASK) != 0);
			}
		}
	}
}

/*** ---------------------------------------------------------------------- ***/

void MarkerPopup(DOCUMENT *doc, int button, guint32 event_time)
{
	WINDOW_DATA *win = doc->window;
	int i;
	GtkWidget *menu;
	struct popup_pos popup_pos;
	
	if (!win->m_buttons[TO_MEMORY])
		return;
	
	menu = gtk_menu_new();
	if (g_object_is_floating(menu))
		g_object_ref_sink(menu);
	
	for (i = 0; i < MAX_MARKEN; i++)
	{
		GtkWidget *item = gtk_menu_item_new_with_label(marken[i].node_name);
		g_object_set_data(G_OBJECT(item), "item-num", (void *)(intptr_t)i);
		g_signal_connect(G_OBJECT(item), "activate", G_CALLBACK(marker_selected), doc);
		gtk_widget_show(item);
		gtk_menu_append(menu, item);
	}
	
	popup_pos.doc = doc;
	popup_pos.obj = TO_MEMORY;
	gtk_menu_popup(GTK_MENU(menu), NULL, NULL, position_popup, &popup_pos, button, event_time);
	gtk_widget_unref(menu);
}

/*** ---------------------------------------------------------------------- ***/

void MarkerSaveToDisk(void)
{
	char *filename;
	
	if (!marken_change)
		return;

	if (!empty(gl_profile.viewer.marker_path))
	{
		int ret;

		if (gl_profile.viewer.marken_save_ask)
		{
			if (ask_yesno(top_window(), _("Save bookmarks?")) == FALSE)
				return;
		}
		filename = path_subst(gl_profile.viewer.marker_path);
		ret = open(filename, O_WRONLY | O_TRUNC | O_CREAT | O_BINARY, 0644);
		if (ret >= 0)
		{
			write(ret, marken, sizeof(MARKEN) * MAX_MARKEN);
			close(ret);
		} else
		{
			HYP_DBG(("Error %ld: saving %s", ret, printnull(filename)));
		}
		g_free(filename);
	}
}

/*** ---------------------------------------------------------------------- ***/

void MarkerInit(void)
{
	short i;
	int ret;
	char *filename;
	
	/* initialize markers */
	for (i = 0; i < MAX_MARKEN; i++)
	{
		MarkerDelete(i);
	}

	/* load file if it exists */
	if (!empty(gl_profile.viewer.marker_path))
	{
		filename = path_subst(gl_profile.viewer.marker_path);
		ret = open(filename, O_RDONLY | O_BINARY);
		if (ret >= 0)
		{
			read(ret, marken, sizeof(MARKEN) * MAX_MARKEN);
			for (i = 0; i < MAX_MARKEN; i++)
			{
				if (marken[i].node_name[0] == 0)
					MarkerDelete(i);
			}
			close(ret);
		}
		g_free(filename);
	}

	marken_change = FALSE;
}
