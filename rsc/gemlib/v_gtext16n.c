#include "gem_vdiP.h"

/** same as v_gtext()
 *
 *  @param handle Device handle
 *  @param x
 *  @param y 
 *  @param wstr string, with 16 bits per character.
 *  @param num len of the string
 *
 *  @since all VDI versions
 *
 */

void
v_gtext16n (short handle, short x, short y, const vdi_wchar_t *wstr, short num)
{
	short vdi_control[VDI_CNTRLMAX]; 
	short vdi_ptsin[2];   

	VDI_PARAMS(vdi_control, (short *)NO_CONST(wstr), vdi_ptsin, vdi_dummy, vdi_dummy );
	
	vdi_ptsin[0] = x;
	vdi_ptsin[1] = y;

	VDI_TRAP (vdi_params, handle, 8, 1,num);
}
