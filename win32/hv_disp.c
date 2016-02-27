#include "hv_defs.h"
#include "hypdebug.h"

/******************************************************************************/
/*** ---------------------------------------------------------------------- ***/
/******************************************************************************/

void HypDisplayPage(WINDOW_DATA *win)
{
	UNUSED(win);
	/* NYI */
}

/*** ---------------------------------------------------------------------- ***/

HYP_NODE *hypwin_node(WINDOW_DATA *win)
{
	return win->displayed_node;
}

/*** ---------------------------------------------------------------------- ***/

void HypPrepNode(WINDOW_DATA *win, HYP_NODE *node)
{
	win->displayed_node = node;
}