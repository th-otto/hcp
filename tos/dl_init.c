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
#if defined(HYPTREE_APP)
#include "hyptree.h"
#else
#include "hypview.h"
#endif
#include <mint/cookie.h>
#include <mint/arch/nf_ops.h>
#include "tos/cookie.h"

_WORD aes_fontid;
_WORD aes_fontsize;
_WORD pwchar;
_WORD phchar;
_WORD pwbox;
_WORD phbox;

_WORD __magix = 0;
_WORD __geneva = 0;

#if USE_GLOBAL_VDI
_WORD vdi_handle;
_WORD workin[16];
_WORD workout[57];
_WORD ext_workout[57];

#if SAVE_COLORS
static RGB1000 save_palette[256];
#endif
#endif

#ifndef AES_WDIALOG
#define AES_WDIALOG 7
#endif

OBJECT *dial_library_tree;
static char **string_addr;

static char const rsc_name[] = "hypview.rsc";
char const iconified_name[] = "HYPVIEW";
char const prghelp_name[] = "hypview.hyp";


_KEYTAB *key_table;

/******************************************************************************/
/*** ---------------------------------------------------------------------- ***/
/******************************************************************************/

OBJECT *rs_tree(_WORD nr)
{
	OBJECT *tree = NULL;
#if defined(HYPTREE_APP)
	hyptree_rsc_gaddr(R_TREE, nr, &tree);
#else
	hypview_rsc_gaddr(R_TREE, nr, &tree);
#endif
	return tree;
}

/*** ---------------------------------------------------------------------- ***/

char *rs_string(_WORD nr)
{
	return string_addr[nr];
}

/*** ---------------------------------------------------------------------- ***/

void dialog_set_iconify(DIALOG *dialog, GRECT *r)
{
	wdlg_set_iconify(dialog, r, iconified_name, iconified_tree, DI_ICON);
}

/*** ---------------------------------------------------------------------- ***/

void GetScreenSize(_WORD *width, _WORD *height)
{
	*width = workout[0] + 1;
	*height = workout[1] + 1;
}

/*** ---------------------------------------------------------------------- ***/

_WORD GetNumPlanes(void)
{
	return ext_workout[4];
}

/*** ---------------------------------------------------------------------- ***/

_WORD GetNumColors(void)
{
	static _WORD num_colors;
	
	if (num_colors == 0)
	{
		num_colors = workout[13];
		if (num_colors == 0 || num_colors == -1 || workout[39] == 0)
			num_colors = 32766; /* more than we need */
	}
	return num_colors;
}

/*** ---------------------------------------------------------------------- ***/

void singletos_fail_loop(void)
{
	if (_AESnumapps == 1 && !_app)
	{
		_WORD msg[8];
		
		for (;;)
			evnt_mesag(msg);
	}
}

/*
   Bit 0:           wdlg_xx()-funktions are available (1)
   Bit 1:           lbox_xx()-funktions are available (1)
   Bit 2:           fnts_xx()-funktions are available (1)
   Bit 3:           fslx_xx()-funktions are available (1)
   Bit 4:           pdlg_xx()-funktions are available (1)
 */
int has_window_dialogs(void)
{
	_WORD has = 0, dummy;
	return appl_xgetinfo(AES_WDIALOG, &has, &dummy, &dummy, &dummy) && (has & 1);
}

int has_listbox_dialog(void)
{
	_WORD has = 0, dummy;
	return appl_xgetinfo(AES_WDIALOG, &has, &dummy, &dummy, &dummy) && (has & 2);
}

int has_fonts_dialog(void)
{
	_WORD has = 0, dummy;
	return appl_xgetinfo(AES_WDIALOG, &has, &dummy, &dummy, &dummy) && (has & 4);
}

int has_filesel_dialog(void)
{
	_WORD has = 0, dummy;
	return appl_xgetinfo(AES_WDIALOG, &has, &dummy, &dummy, &dummy) && (has & 8);
}

int has_form_popup(void)
{
	_WORD has = 0, dummy;
	return appl_xgetinfo(AES_MENU, &dummy, &has, &dummy, &dummy) && has;
}

int has_iconify(void)
{
	_WORD has, dummy;
	return appl_xgetinfo(AES_WINDOW, &has, &dummy, &dummy, &dummy) && (has & 0x80);
}

/******************************************************************************/
/*** ---------------------------------------------------------------------- ***/
/******************************************************************************/

int DoAesInit(void)
{
	_WORD attrib[10];
	
	/* gl_apid = appl_init(); moved to hypmain.h */
	if (gl_apid < 0)
		return FALSE;

	aes_handle = graf_handle(&pwchar, &phchar, &pwbox, &phbox);
	vqt_attributes(aes_handle, attrib);
	aes_fontid = attrib[0];
	aes_fontsize = phchar >= 13 ? 10 : 9;
	
	vq_extnd(aes_handle, 0, workout);
	vq_extnd(aes_handle, 1, ext_workout);

#if defined(HYPTREE_APP)
	if (hyptree_rsc_load(pwchar, phchar) == 0)
#else
	if (hypview_rsc_load(pwchar, phchar) == 0)
#endif
	{
		char *str = g_strdup_printf(_("[1][Error while loading |'%s'.][Cancel]"), rsc_name);
		form_alert(1, str);
		g_free(str);
		singletos_fail_loop();
		appl_exit();
		return FALSE;
	}
#if defined(HYPTREE_APP)
	hyptree_rsc_gaddr(R_FRSTR, 0, &string_addr);
#else
	hypview_rsc_gaddr(R_FRSTR, 0, &string_addr);
#endif
	dial_library_tree = rs_tree(DIAL_LIBRARY);

	{
		_WORD dummy, level = 0;
		
		if (appl_xgetinfo(AES_SHELL, &level, &dummy, &dummy, &dummy) && (level & 0x00FF) >= 9)
			shel_write(SWM_NEWMSG, 1, 1, "", "");			/* we understand AP_TERM! */
	}

	{
		long l;
		
		if (Cookie_ReadJar(C_MiNT, &l) != FALSE)
			__mint = (_WORD)l;
		if (Cookie_ReadJar(C_MagX, &l) != FALSE)
			__magix = ((short **)l)[2][24];
		if (Cookie_ReadJar(C_Gnva, &l) != FALSE)
			__geneva = 1;
	}
	
	iconified_tree = dial_library_tree;
#if 0
	/* center iconify-icon */
	if (has_iconify())
	{
		GRECT icon= { 0, 0, 72, 72 };
		_WORD w, h, dummy;
		
		if (wind_get(0,WF_ICONIFY, &dummy, &w, &h, &dummy))
		{
			icon.g_w = w;
			icon.g_h = h;
		}
		wind_calc(WC_WORK, NAME, &icon, &icon);
		dial_library_tree[DI_ICON].ob_x = (icon.g_w - dial_library_tree[DI_ICON].ob_width) >> 1;
		dial_library_tree[DI_ICON].ob_y = (icon.g_h - dial_library_tree[DI_ICON].ob_height) >> 1;
	}
#endif

	return TRUE;
}

/*** ---------------------------------------------------------------------- ***/

int DoInitSystem(void)
{
#if USE_GLOBAL_VDI
	{
		short i;

		for (i = 0; i < 10; i++)
			workin[i] = 1;
		workin[10] = 2;
		vdi_handle = aes_handle;
		v_opnvwk(workin, &vdi_handle, workout);
		if (!vdi_handle)
		{
			form_alert(1, rs_string(DI_VDI_WKS_ERROR));
#if defined(HYPTREE_APP)
			hyptree_rsc_free();
#else
			hypview_rsc_free();
#endif
			return FALSE;
		}
		vq_extnd(vdi_handle, 1, ext_workout);

#if SAVE_COLORS
		for (i = 0; i < 256; i++)
			vq_color(vdi_handle, i, 1, &save_palette[i].red);
#endif
#ifndef HYPTREE_APP
		hfix_palette(vdi_handle);
#endif
	}
#endif
#if USE_LONGEDITFIELDS
	DoInitLongEdit();
#endif
#if USE_BUBBLEGEM
	DoInitBubble();
#endif

	key_table = (_KEYTAB *)Keytbl(((void *) -1), ((void *) -1), ((void *) -1));	/* fetch keytable */

	return TRUE;
}

/*** ---------------------------------------------------------------------- ***/

void DoExitSystem(void)
{
	if (_app)
		va_proto_exit();
#if USE_BUBBLEGEM
	DoExitBubble();
#endif
#if USE_LONGEDITFIELDS
	DoExitLongEdit();
#endif
#if USE_GLOBAL_VDI
	if (vdi_handle)
	{
#if SAVE_COLORS
		short i;

		for (i = 0; i < 256; i++)
			vs_color(vdi_handle, i, &save_palette[i].red);
#endif
		v_clsvwk(vdi_handle);
		vdi_handle = 0;
	}
#endif

#if defined(HYPTREE_APP)
	hyptree_rsc_free();
#else
	hypview_rsc_free();
#endif
	appl_exit();
}
