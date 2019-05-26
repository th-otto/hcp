#include "config.h"
#include <portab.h>
#include <fonthdr.h>

static uint16_t const fnt_l9_8x16_off_table[] = {
	0x0000, 0x0008, 0x0010, 0x0018, 0x0020, 0x0028, 0x0030, 0x0038,
	0x0040, 0x0048, 0x0050, 0x0058, 0x0060, 0x0068, 0x0070, 0x0078,
	0x0080, 0x0088, 0x0090, 0x0098, 0x00a0, 0x00a8, 0x00b0, 0x00b8,
	0x00c0, 0x00c8, 0x00d0, 0x00d8, 0x00e0, 0x00e8, 0x00f0, 0x00f8,
	0x0100, 0x0108, 0x0110, 0x0118, 0x0120, 0x0128, 0x0130, 0x0138,
	0x0140, 0x0148, 0x0150, 0x0158, 0x0160, 0x0168, 0x0170, 0x0178,
	0x0180, 0x0188, 0x0190, 0x0198, 0x01a0, 0x01a8, 0x01b0, 0x01b8,
	0x01c0, 0x01c8, 0x01d0, 0x01d8, 0x01e0, 0x01e8, 0x01f0, 0x01f8,
	0x0200, 0x0208, 0x0210, 0x0218, 0x0220, 0x0228, 0x0230, 0x0238,
	0x0240, 0x0248, 0x0250, 0x0258, 0x0260, 0x0268, 0x0270, 0x0278,
	0x0280, 0x0288, 0x0290, 0x0298, 0x02a0, 0x02a8, 0x02b0, 0x02b8,
	0x02c0, 0x02c8, 0x02d0, 0x02d8, 0x02e0, 0x02e8, 0x02f0, 0x02f8,
	0x0300, 0x0308, 0x0310, 0x0318, 0x0320, 0x0328, 0x0330, 0x0338,
	0x0340, 0x0348, 0x0350, 0x0358, 0x0360, 0x0368, 0x0370, 0x0378,
	0x0380, 0x0388, 0x0390, 0x0398, 0x03a0, 0x03a8, 0x03b0, 0x03b8,
	0x03c0, 0x03c8, 0x03d0, 0x03d8, 0x03e0, 0x03e8, 0x03f0, 0x03f8,
	0x0400, 0x0408, 0x0410, 0x0418, 0x0420, 0x0428, 0x0430, 0x0438,
	0x0440, 0x0448, 0x0450, 0x0458, 0x0460, 0x0468, 0x0470, 0x0478,
	0x0480, 0x0488, 0x0490, 0x0498, 0x04a0, 0x04a8, 0x04b0, 0x04b8,
	0x04c0, 0x04c8, 0x04d0, 0x04d8, 0x04e0, 0x04e8, 0x04f0, 0x04f8,
	0x0500, 0x0508, 0x0510, 0x0518, 0x0520, 0x0528, 0x0530, 0x0538,
	0x0540, 0x0548, 0x0550, 0x0558, 0x0560, 0x0568, 0x0570, 0x0578,
	0x0580, 0x0588, 0x0590, 0x0598, 0x05a0, 0x05a8, 0x05b0, 0x05b8,
	0x05c0, 0x05c8, 0x05d0, 0x05d8, 0x05e0, 0x05e8, 0x05f0, 0x05f8,
	0x0600, 0x0608, 0x0610, 0x0618, 0x0620, 0x0628, 0x0630, 0x0638,
	0x0640, 0x0648, 0x0650, 0x0658, 0x0660, 0x0668, 0x0670, 0x0678,
	0x0680, 0x0688, 0x0690, 0x0698, 0x06a0, 0x06a8, 0x06b0, 0x06b8,
	0x06c0, 0x06c8, 0x06d0, 0x06d8, 0x06e0, 0x06e8, 0x06f0, 0x06f8,
	0x0700, 0x0708, 0x0710, 0x0718, 0x0720, 0x0728, 0x0730, 0x0738,
	0x0740, 0x0748, 0x0750, 0x0758, 0x0760, 0x0768, 0x0770, 0x0778,
	0x0780, 0x0788, 0x0790, 0x0798, 0x07a0, 0x07a8, 0x07b0, 0x07b8,
	0x07c0, 0x07c8, 0x07d0, 0x07d8, 0x07e0, 0x07e8, 0x07f0, 0x07f8,
	0x0800
};


static uint8_t const fnt_l9_8x16_dat_table[] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x04,
	0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c,
	0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x60, 0x06, 0x18, 0x32, 0x00, 0x3c, 0x00, 0x00, 0x60, 0x06, 0x18, 0x00, 0x60, 0x06, 0x18, 0x00,
	0x00, 0x32, 0x60, 0x06, 0x18, 0x32, 0x00, 0x00, 0x00, 0x60, 0x06, 0x18, 0x00, 0x06, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0xa0,
	0x7c, 0x00, 0x7c, 0x7c, 0x00, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x28,
	0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
	0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x18, 0xe0, 0x00, 0x00,
	0x00, 0x00, 0x06, 0x18, 0x00, 0x60, 0x1c, 0x00, 0x18, 0x00, 0x60, 0x00, 0x18, 0x60, 0x66, 0x66,
	0x0c, 0x00, 0x3e, 0x18, 0x00, 0x60, 0x18, 0x60, 0x00, 0x66, 0x66, 0x00, 0x0e, 0x00, 0x00, 0x00,
	0x06, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe,
	0x38, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0x00,
	0x30, 0x0c, 0x3c, 0x7a, 0x66, 0x66, 0x3e, 0x00, 0x30, 0x0c, 0x3c, 0x66, 0x30, 0x0c, 0x3c, 0x66,
	0x00, 0x7a, 0x30, 0x0c, 0x3c, 0x7a, 0x66, 0x00, 0x01, 0x30, 0x0c, 0x3c, 0x66, 0x0c, 0x00, 0x00,
	0x60, 0x06, 0x18, 0x32, 0x00, 0x1c, 0x00, 0x00, 0x60, 0x06, 0x18, 0x00, 0x60, 0x06, 0x18, 0x00,
	0x00, 0x32, 0x60, 0x06, 0x18, 0x32, 0x00, 0x00, 0x00, 0x60, 0x06, 0x18, 0x00, 0x06, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x30, 0x0c, 0x7c, 0xfe, 0xee, 0x01, 0x00, 0x00, 0x08, 0x78, 0x38, 0x05, 0xa0,
	0xba, 0x02, 0x3a, 0x3a, 0x82, 0xb8, 0xb8, 0xba, 0xba, 0xba, 0x00, 0x78, 0x00, 0x00, 0x0d, 0xd8,
	0x00, 0x18, 0x66, 0x66, 0x3e, 0x66, 0x6c, 0x18, 0x06, 0x60, 0x66, 0x00, 0x00, 0x00, 0x00, 0x06,
	0x3c, 0x18, 0x3c, 0x7e, 0x0c, 0x7e, 0x1c, 0x7e, 0x3c, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c,
	0x38, 0x18, 0x7c, 0x3c, 0x78, 0x7e, 0x7e, 0x3e, 0x66, 0x7e, 0x06, 0xcc, 0x60, 0xc6, 0x66, 0x3c,
	0x7c, 0x3c, 0xf8, 0x3e, 0x7e, 0x66, 0x66, 0xc6, 0x66, 0x66, 0x7e, 0x1e, 0x60, 0x78, 0x10, 0x00,
	0x70, 0x00, 0x60, 0x00, 0x06, 0x00, 0x0e, 0x00, 0x60, 0x18, 0x0c, 0xc0, 0x38, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x30, 0x00, 0x00,
	0x3c, 0x66, 0x0c, 0x3c, 0x66, 0x30, 0x36, 0x00, 0x3c, 0x66, 0x30, 0x66, 0x3c, 0x30, 0x66, 0x3c,
	0x18, 0x00, 0x7e, 0x3c, 0x66, 0x30, 0x3c, 0x30, 0x66, 0x66, 0x66, 0x18, 0x1e, 0x66, 0x18, 0x0e,
	0x0c, 0x00, 0x18, 0x1e, 0x1c, 0x66, 0x18, 0x1c, 0x66, 0x7c, 0x3c, 0x00, 0x00, 0x00, 0x7c, 0xfe,
	0x6c, 0x00, 0x30, 0x78, 0x18, 0x00, 0x7a, 0x00, 0x66, 0x18, 0x3c, 0x00, 0x7e, 0x00, 0x66, 0x18,
	0x18, 0x18, 0x66, 0x4c, 0x66, 0x3c, 0x7e, 0x3c, 0x18, 0x18, 0x66, 0x66, 0x18, 0x18, 0x66, 0x66,
	0x78, 0x4c, 0x18, 0x18, 0x66, 0x4c, 0x66, 0x00, 0x3d, 0x18, 0x18, 0x66, 0x66, 0x18, 0x60, 0x18,
	0x30, 0x0c, 0x3c, 0x7a, 0x66, 0x36, 0x00, 0x00, 0x30, 0x0c, 0x3c, 0x66, 0x30, 0x0c, 0x3c, 0x66,
	0x66, 0x7a, 0x30, 0x0c, 0x3c, 0x7a, 0x66, 0x00, 0x00, 0x30, 0x0c, 0x3c, 0x66, 0x0c, 0x00, 0x66,
	0x00, 0x18, 0x3c, 0x38, 0x1c, 0x38, 0xfe, 0xc6, 0x01, 0x3c, 0x00, 0x0e, 0x40, 0x40, 0x05, 0xa0,
	0xc6, 0x06, 0x06, 0x06, 0xc6, 0xc0, 0xc0, 0xc6, 0xc6, 0xc6, 0x00, 0x40, 0x00, 0x00, 0x06, 0x28,
	0x00, 0x18, 0x66, 0x66, 0x7e, 0x66, 0x6c, 0x18, 0x0c, 0x30, 0x66, 0x18, 0x00, 0x00, 0x00, 0x06,
	0x7e, 0x18, 0x7e, 0x7e, 0x0c, 0x7e, 0x3c, 0x7e, 0x7e, 0x7e, 0x00, 0x00, 0x0e, 0x00, 0xe0, 0x7e,
	0x7c, 0x3c, 0x7e, 0x7e, 0x7c, 0x7e, 0x7e, 0x7e, 0x66, 0x7e, 0x06, 0xcc, 0x60, 0xc6, 0x66, 0x7e,
	0x7e, 0x7e, 0xfc, 0x7e, 0x7e, 0x66, 0x66, 0xc6, 0x66, 0x66, 0x7e, 0x1e, 0x60, 0x78, 0x38, 0x00,
	0x38, 0x00, 0x60, 0x00, 0x06, 0x00, 0x1e, 0x00, 0x60, 0x18, 0x0c, 0xc0, 0x38, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x30, 0x00, 0x00,
	0x7e, 0x66, 0x18, 0x66, 0x66, 0x18, 0x1c, 0x00, 0x66, 0x66, 0x18, 0x66, 0x66, 0x18, 0x18, 0x18,
	0x7e, 0x00, 0xf8, 0x66, 0x66, 0x18, 0x66, 0x18, 0x66, 0x00, 0x00, 0x18, 0x38, 0x66, 0x3c, 0x1e,
	0x18, 0x18, 0x18, 0x38, 0x3e, 0x66, 0x3e, 0x36, 0x3c, 0xc6, 0x06, 0x00, 0x00, 0x00, 0xc6, 0x00,
	0x44, 0x18, 0x48, 0x18, 0x7e, 0x00, 0xca, 0x00, 0x3c, 0x78, 0x66, 0x00, 0xfe, 0x00, 0x00, 0x18,
	0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0xf8, 0x7e, 0x7e, 0x7e, 0x00, 0x00, 0x7e, 0x7e, 0x00, 0x00,
	0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x3c,
	0x18, 0x18, 0x66, 0x4c, 0x66, 0x1c, 0x00, 0x00, 0x18, 0x18, 0x66, 0x66, 0x18, 0x18, 0x66, 0x66,
	0x18, 0x4c, 0x18, 0x18, 0x66, 0x4c, 0x66, 0x18, 0x00, 0x18, 0x18, 0x66, 0x66, 0x18, 0x60, 0x66,
	0x00, 0x3c, 0x24, 0x2c, 0x34, 0xba, 0xfe, 0xd6, 0x03, 0x66, 0x18, 0x0f, 0x70, 0x40, 0x05, 0xa0,
	0xc6, 0x06, 0x06, 0x06, 0xc6, 0xc0, 0xc0, 0xc6, 0xc6, 0xc6, 0x00, 0x70, 0x00, 0x00, 0x07, 0xd0,
	0x00, 0x18, 0x66, 0xff, 0x60, 0x6c, 0x38, 0x18, 0x1c, 0x38, 0x3c, 0x18, 0x00, 0x00, 0x00, 0x06,
	0x66, 0x38, 0x66, 0x0c, 0x1c, 0x60, 0x70, 0x06, 0x66, 0x66, 0x18, 0x18, 0x1c, 0x7e, 0x70, 0x66,
	0xe6, 0x7e, 0x66, 0x66, 0x6e, 0x60, 0x60, 0x60, 0x66, 0x18, 0x06, 0xd8, 0x60, 0xee, 0x66, 0x66,
	0x66, 0x66, 0xcc, 0x60, 0x18, 0x66, 0x66, 0xc6, 0x66, 0x66, 0x0c, 0x18, 0x60, 0x18, 0x38, 0x00,
	0x1c, 0x00, 0x60, 0x00, 0x06, 0x00, 0x18, 0x00, 0x60, 0x00, 0x00, 0xc0, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x30, 0x00, 0x00,
	0x66, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x3c,
	0x7e, 0x00, 0xd8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x66, 0x3c, 0x30, 0x66, 0x66, 0x18,
	0x00, 0x18, 0x3c, 0x30, 0x66, 0x66, 0x7e, 0x32, 0x18, 0x82, 0x7e, 0x00, 0x00, 0x00, 0x82, 0x00,
	0x6c, 0x18, 0x18, 0x30, 0x7e, 0x00, 0xca, 0x00, 0x18, 0x18, 0x66, 0x00, 0xd8, 0x00, 0x66, 0x00,
	0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0xd8, 0x66, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e,
	0x6e, 0x66, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0xc3, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x60, 0x66,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x6c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00,
	0x00, 0x66, 0x24, 0xe6, 0x67, 0x92, 0xfc, 0x92, 0x03, 0xc3, 0x3c, 0x09, 0x40, 0x40, 0x0d, 0xb0,
	0xc6, 0x06, 0x06, 0x06, 0xc6, 0xc0, 0xc0, 0xc6, 0xc6, 0xc6, 0x7c, 0x40, 0x00, 0x00, 0x2e, 0x10,
	0x00, 0x18, 0x66, 0xff, 0x60, 0x0c, 0x38, 0x18, 0x18, 0x18, 0x3c, 0x18, 0x00, 0x00, 0x00, 0x0c,
	0x66, 0x38, 0x66, 0x0c, 0x1c, 0x60, 0x60, 0x06, 0x66, 0x66, 0x18, 0x18, 0x38, 0x7e, 0x38, 0x66,
	0xc2, 0x66, 0x66, 0x66, 0x66, 0x60, 0x60, 0x60, 0x66, 0x18, 0x06, 0xd8, 0x60, 0xee, 0x76, 0x66,
	0x66, 0x66, 0xcc, 0x60, 0x18, 0x66, 0x66, 0xc6, 0x3c, 0x66, 0x0c, 0x18, 0x30, 0x18, 0x6c, 0x00,
	0x0c, 0x3c, 0x7c, 0x3c, 0x3e, 0x3c, 0x18, 0x3e, 0x7c, 0x38, 0x0c, 0xcc, 0x18, 0x6c, 0x3c, 0x3c,
	0x7c, 0x3e, 0x7c, 0x3e, 0x7e, 0x66, 0x66, 0xc6, 0x66, 0x66, 0x7e, 0x18, 0x18, 0x30, 0x62, 0x18,
	0x66, 0x66, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x38, 0x38, 0x38, 0x7e, 0x7e,
	0x60, 0x76, 0xd8, 0x3c, 0x3c, 0x3c, 0x66, 0x66, 0x66, 0x7e, 0x66, 0x7e, 0x30, 0x66, 0x66, 0x18,
	0x3c, 0x00, 0x7e, 0x30, 0x60, 0x66, 0x60, 0x18, 0x3e, 0xba, 0x66, 0x00, 0x00, 0x00, 0xba, 0x00,
	0x38, 0x18, 0x30, 0x18, 0x0c, 0x66, 0xca, 0x00, 0x7e, 0x18, 0x66, 0x00, 0xd8, 0x7e, 0x66, 0x18,
	0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0xd8, 0x66, 0x60, 0x60, 0x7e, 0x7e, 0x18, 0x18, 0x7e, 0x7e,
	0x66, 0x66, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7c, 0x66,
	0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x76, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x38, 0x38, 0x38, 0x38,
	0x06, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0x3d, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7c, 0x66,
	0x00, 0xc3, 0x24, 0x83, 0xc1, 0xd6, 0xfc, 0xba, 0x06, 0x91, 0x3c, 0x08, 0x40, 0x38, 0x0d, 0xb0,
	0x82, 0x02, 0x3a, 0x3a, 0xba, 0xb8, 0xb8, 0x82, 0xba, 0xba, 0x7e, 0x78, 0x00, 0x00, 0x39, 0xe0,
	0x00, 0x18, 0x66, 0x66, 0x7c, 0x18, 0x70, 0x18, 0x18, 0x18, 0xff, 0x7e, 0x00, 0x7e, 0x00, 0x0c,
	0x66, 0x18, 0x0c, 0x18, 0x3c, 0x7c, 0x60, 0x0c, 0x3c, 0x7e, 0x18, 0x18, 0x70, 0x00, 0x1c, 0x0c,
	0xda, 0x66, 0x7e, 0x60, 0x66, 0x7c, 0x7c, 0x6e, 0x7e, 0x18, 0x06, 0xf0, 0x60, 0xfe, 0x76, 0x66,
	0x66, 0x66, 0xcc, 0x70, 0x18, 0x66, 0x66, 0xc6, 0x3c, 0x3c, 0x18, 0x18, 0x30, 0x18, 0x6c, 0x00,
	0x04, 0x3e, 0x7e, 0x7c, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x38, 0x0c, 0xdc, 0x18, 0xfe, 0x7e, 0x7e,
	0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x66, 0x66, 0xc6, 0x66, 0x66, 0x7e, 0x38, 0x18, 0x38, 0xf2, 0x18,
	0x60, 0x66, 0x7e, 0x3e, 0x3e, 0x3e, 0x3e, 0x7c, 0x7e, 0x7e, 0x7e, 0x38, 0x38, 0x38, 0x66, 0x66,
	0x60, 0x7f, 0xde, 0x7e, 0x7e, 0x7e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x30, 0x7e, 0x66, 0x18,
	0x3e, 0x18, 0x66, 0x30, 0xfc, 0x7e, 0x70, 0x3c, 0x7e, 0xa2, 0x66, 0x1a, 0x00, 0x3c, 0xaa, 0x00,
	0x00, 0x7e, 0x60, 0x48, 0x0c, 0x66, 0xca, 0x00, 0x7e, 0x18, 0x66, 0xb0, 0xde, 0xff, 0x66, 0x18,
	0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xde, 0x60, 0x60, 0x60, 0x60, 0x60, 0x18, 0x18, 0x18, 0x18,
	0x76, 0x76, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x6e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7e, 0x66,
	0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x7f, 0x7c, 0x7e, 0x7e, 0x7e, 0x7e, 0x38, 0x38, 0x38, 0x38,
	0x1e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7e, 0x66,
	0x00, 0x81, 0xe7, 0x83, 0xc1, 0xc6, 0xf8, 0x38, 0x06, 0x91, 0x3c, 0x08, 0x00, 0x00, 0x1d, 0xb8,
	0x00, 0x00, 0x7c, 0x7c, 0x7c, 0x7c, 0x7c, 0x00, 0x7c, 0x7c, 0x06, 0x00, 0x00, 0x00, 0x38, 0x00,
	0x00, 0x18, 0x66, 0x66, 0x3e, 0x18, 0x70, 0x18, 0x18, 0x18, 0xff, 0x7e, 0x00, 0x7e, 0x00, 0x18,
	0x6e, 0x18, 0x0c, 0x18, 0x3c, 0x7e, 0x7c, 0x0c, 0x3c, 0x3e, 0x18, 0x18, 0xe0, 0x00, 0x0e, 0x0c,
	0xd6, 0x66, 0x7c, 0x60, 0x66, 0x7c, 0x7c, 0x6e, 0x7e, 0x18, 0x06, 0xf0, 0x60, 0xd6, 0x7e, 0x66,
	0x66, 0x66, 0xfc, 0x38, 0x18, 0x66, 0x66, 0xd6, 0x18, 0x3c, 0x18, 0x18, 0x18, 0x18, 0xc6, 0x00,
	0x00, 0x06, 0x66, 0x60, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x18, 0x0c, 0xf8, 0x18, 0xfe, 0x66, 0x66,
	0x66, 0x66, 0x66, 0x60, 0x18, 0x66, 0x66, 0xd6, 0x3c, 0x66, 0x0c, 0xf0, 0x18, 0x1e, 0xbe, 0x3c,
	0x60, 0x66, 0x66, 0x06, 0x06, 0x06, 0x06, 0x60, 0x66, 0x66, 0x66, 0x18, 0x18, 0x18, 0x66, 0x66,
	0x7c, 0x1b, 0xde, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x60, 0x30, 0x3c, 0x7c, 0x7e,
	0x06, 0x18, 0x60, 0x30, 0x60, 0x3c, 0x38, 0x66, 0x60, 0xa2, 0x3e, 0x36, 0x00, 0x3c, 0xb2, 0x00,
	0x00, 0x7e, 0x78, 0x30, 0x18, 0x66, 0xca, 0x18, 0x0c, 0x7c, 0x3c, 0xd8, 0xde, 0xdb, 0x66, 0x18,
	0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xde, 0x60, 0x7c, 0x7c, 0x60, 0x60, 0x18, 0x18, 0x18, 0x18,
	0xf6, 0x76, 0x66, 0x66, 0x66, 0x66, 0x66, 0x18, 0x6e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7c,
	0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x1b, 0x60, 0x66, 0x66, 0x66, 0x66, 0x18, 0x18, 0x18, 0x18,
	0x3e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
	0x00, 0xe7, 0x81, 0xe6, 0x67, 0xd6, 0xfa, 0xba, 0x8c, 0x9d, 0x3c, 0x78, 0x1e, 0x1c, 0x39, 0x9c,
	0x82, 0x02, 0xb8, 0x3a, 0x3a, 0x3a, 0xba, 0x02, 0xba, 0x3a, 0x06, 0x0e, 0x07, 0xf0, 0x00, 0x00,
	0x00, 0x18, 0x00, 0xff, 0x06, 0x30, 0xde, 0x00, 0x18, 0x18, 0x3c, 0x18, 0x00, 0x00, 0x00, 0x18,
	0x76, 0x18, 0x18, 0x0c, 0x6c, 0x06, 0x7e, 0x18, 0x66, 0x06, 0x00, 0x00, 0x70, 0x7e, 0x1c, 0x18,
	0xd6, 0x7e, 0x66, 0x60, 0x66, 0x60, 0x60, 0x66, 0x66, 0x18, 0x06, 0xd8, 0x60, 0xd6, 0x7e, 0x66,
	0x7e, 0x66, 0xf8, 0x1c, 0x18, 0x66, 0x66, 0xd6, 0x18, 0x18, 0x30, 0x18, 0x18, 0x18, 0xc6, 0x00,
	0x00, 0x3e, 0x66, 0x60, 0x66, 0x66, 0x18, 0x66, 0x66, 0x18, 0x0c, 0xf0, 0x18, 0xd6, 0x66, 0x66,
	0x66, 0x66, 0x60, 0x70, 0x18, 0x66, 0x66, 0xd6, 0x3c, 0x66, 0x18, 0xf0, 0x18, 0x1e, 0x9c, 0x24,
	0x60, 0x66, 0x66, 0x3e, 0x3e, 0x3e, 0x3e, 0x60, 0x66, 0x66, 0x66, 0x18, 0x18, 0x18, 0x7e, 0x7e,
	0x7c, 0x7b, 0xf8, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x60, 0xfe, 0x18, 0x66, 0x18,
	0x3e, 0x18, 0x60, 0xfe, 0xf8, 0x18, 0x1c, 0x66, 0x70, 0xa2, 0x00, 0x6c, 0x00, 0x00, 0xba, 0x00,
	0x00, 0x18, 0x00, 0x00, 0x18, 0x66, 0x7a, 0x18, 0x18, 0x00, 0x00, 0x6c, 0xd8, 0xdb, 0x3c, 0x30,
	0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0xf8, 0x60, 0x7c, 0x7c, 0x7c, 0x7c, 0x18, 0x18, 0x18, 0x18,
	0xe6, 0x7e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x76, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x66, 0x7c,
	0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x7b, 0x60, 0x66, 0x66, 0x66, 0x66, 0x18, 0x18, 0x18, 0x18,
	0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x6e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
	0x00, 0x24, 0xc3, 0x2c, 0x34, 0x92, 0xf2, 0x92, 0x8c, 0x81, 0x3c, 0xf8, 0x10, 0x12, 0x79, 0x9e,
	0xc6, 0x06, 0xc0, 0x06, 0x06, 0x06, 0xc6, 0x06, 0xc6, 0x06, 0x7e, 0x10, 0x0f, 0xf8, 0x00, 0x00,
	0x00, 0x18, 0x00, 0xff, 0x06, 0x36, 0xde, 0x00, 0x18, 0x18, 0x3c, 0x18, 0x00, 0x00, 0x00, 0x30,
	0x66, 0x18, 0x18, 0x0c, 0x6c, 0x06, 0x66, 0x18, 0x66, 0x06, 0x00, 0x00, 0x38, 0x7e, 0x38, 0x18,
	0xdc, 0x7e, 0x66, 0x60, 0x66, 0x60, 0x60, 0x66, 0x66, 0x18, 0x06, 0xd8, 0x60, 0xc6, 0x6e, 0x66,
	0x7c, 0x66, 0xd8, 0x0e, 0x18, 0x66, 0x66, 0xfe, 0x3c, 0x18, 0x30, 0x18, 0x0c, 0x18, 0x00, 0x00,
	0x00, 0x7e, 0x66, 0x60, 0x66, 0x7e, 0x18, 0x66, 0x66, 0x18, 0x0c, 0xf8, 0x18, 0xd6, 0x66, 0x66,
	0x66, 0x66, 0x60, 0x3c, 0x18, 0x66, 0x66, 0xfe, 0x18, 0x66, 0x18, 0x38, 0x18, 0x38, 0x00, 0x66,
	0x60, 0x66, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x60, 0x7e, 0x7e, 0x7e, 0x18, 0x18, 0x18, 0x7e, 0x7e,
	0x60, 0xff, 0xf8, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x30, 0x7e, 0x66, 0x18,
	0x7e, 0x18, 0x66, 0x30, 0x60, 0x7e, 0x0e, 0x3c, 0x3c, 0xba, 0x00, 0xd8, 0x7e, 0x00, 0xaa, 0x00,
	0x00, 0x18, 0x00, 0x00, 0x30, 0x66, 0x0a, 0x00, 0x18, 0x00, 0x00, 0x36, 0xd8, 0xdf, 0x3c, 0x30,
	0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0xf8, 0x60, 0x60, 0x60, 0x7c, 0x7c, 0x18, 0x18, 0x18, 0x18,
	0x66, 0x6e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x76, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x7e, 0x66,
	0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0xff, 0x60, 0x7e, 0x7e, 0x7e, 0x7e, 0x18, 0x18, 0x18, 0x18,
	0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x18, 0x7e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
	0x00, 0x24, 0x66, 0x38, 0x1c, 0xba, 0xf6, 0xd6, 0xd8, 0xc3, 0x7e, 0x70, 0x1c, 0x1c, 0x71, 0x8e,
	0xc6, 0x06, 0xc0, 0x06, 0x06, 0x06, 0xc6, 0x06, 0xc6, 0x06, 0x66, 0x0c, 0x1f, 0xec, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x66, 0x7e, 0x66, 0xcc, 0x00, 0x18, 0x18, 0x66, 0x18, 0x18, 0x00, 0x18, 0x30,
	0x66, 0x18, 0x30, 0x66, 0x7e, 0x06, 0x66, 0x30, 0x66, 0x06, 0x18, 0x18, 0x1c, 0x00, 0x70, 0x18,
	0xc0, 0x66, 0x66, 0x66, 0x66, 0x60, 0x60, 0x66, 0x66, 0x18, 0x66, 0xcc, 0x60, 0xc6, 0x6e, 0x66,
	0x60, 0x66, 0xcc, 0x06, 0x18, 0x66, 0x3c, 0xfe, 0x3c, 0x18, 0x60, 0x18, 0x0c, 0x18, 0x00, 0x00,
	0x00, 0x66, 0x66, 0x60, 0x66, 0x60, 0x18, 0x66, 0x66, 0x18, 0x0c, 0xd8, 0x18, 0xd6, 0x66, 0x66,
	0x66, 0x66, 0x60, 0x0e, 0x18, 0x66, 0x3c, 0xfe, 0x3c, 0x66, 0x30, 0x18, 0x18, 0x30, 0x00, 0x42,
	0x66, 0x66, 0x60, 0x66, 0x66, 0x66, 0x66, 0x60, 0x60, 0x60, 0x60, 0x18, 0x18, 0x18, 0x66, 0x66,
	0x60, 0xd8, 0xd8, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7e, 0x30, 0x18, 0x66, 0x18,
	0x66, 0x18, 0x7e, 0x30, 0x60, 0x18, 0x06, 0x18, 0x0e, 0x82, 0x00, 0x6c, 0x7e, 0x00, 0x82, 0x00,
	0x00, 0x18, 0x00, 0x00, 0x30, 0x66, 0x0a, 0x00, 0x30, 0x00, 0x00, 0x6c, 0xd8, 0xd8, 0x18, 0x66,
	0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xd8, 0x66, 0x60, 0x60, 0x60, 0x60, 0x18, 0x18, 0x18, 0x18,
	0x66, 0x6e, 0x66, 0x66, 0x66, 0x66, 0x66, 0xc3, 0x66, 0x66, 0x66, 0x66, 0x66, 0x18, 0x7c, 0x66,
	0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xd8, 0x60, 0x60, 0x60, 0x60, 0x60, 0x18, 0x18, 0x18, 0x18,
	0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x18, 0x76, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
	0x00, 0x24, 0x3c, 0x30, 0x0c, 0x38, 0xe6, 0xc6, 0x58, 0x66, 0xff, 0x00, 0x10, 0x14, 0x71, 0x8e,
	0xc6, 0x06, 0xc0, 0x06, 0x06, 0x06, 0xc6, 0x06, 0xc6, 0x06, 0x66, 0x02, 0x18, 0x04, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x66, 0x7c, 0x66, 0xcc, 0x00, 0x1c, 0x38, 0x66, 0x00, 0x18, 0x00, 0x18, 0x60,
	0x66, 0x18, 0x30, 0x66, 0x7e, 0x66, 0x66, 0x30, 0x66, 0x0e, 0x18, 0x18, 0x0e, 0x00, 0xe0, 0x00,
	0xe2, 0x66, 0x66, 0x66, 0x6e, 0x60, 0x60, 0x66, 0x66, 0x18, 0x66, 0xcc, 0x60, 0xc6, 0x66, 0x66,
	0x60, 0x6a, 0xcc, 0x06, 0x18, 0x66, 0x3c, 0xee, 0x66, 0x18, 0x60, 0x18, 0x06, 0x18, 0x00, 0x00,
	0x00, 0x66, 0x66, 0x60, 0x66, 0x60, 0x18, 0x7e, 0x66, 0x18, 0x0c, 0xcc, 0x18, 0xc6, 0x66, 0x66,
	0x66, 0x66, 0x60, 0x06, 0x18, 0x66, 0x3c, 0xee, 0x3c, 0x7e, 0x30, 0x18, 0x18, 0x30, 0x00, 0xc3,
	0x66, 0x66, 0x60, 0x66, 0x66, 0x66, 0x66, 0x60, 0x60, 0x60, 0x60, 0x18, 0x18, 0x18, 0x66, 0x66,
	0x60, 0xd8, 0xd8, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7e, 0x66, 0x66, 0x3c, 0x30, 0x18, 0x7c, 0x18,
	0x66, 0x18, 0x3c, 0x30, 0x66, 0x18, 0x06, 0x4c, 0x06, 0xc6, 0x00, 0x36, 0x06, 0x00, 0xc6, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x60, 0x7f, 0x0a, 0x00, 0x30, 0x00, 0x00, 0xd8, 0xd8, 0xd8, 0x18, 0x66,
	0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xd8, 0x66, 0x60, 0x60, 0x60, 0x60, 0x18, 0x18, 0x18, 0x18,
	0x6e, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x18, 0x60, 0x66,
	0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xd8, 0x60, 0x60, 0x60, 0x60, 0x60, 0x18, 0x18, 0x18, 0x18,
	0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7e, 0x66, 0x7e,
	0x00, 0x3c, 0x18, 0x00, 0x00, 0x7c, 0xee, 0xee, 0x70, 0x3c, 0x10, 0x00, 0x10, 0x12, 0x61, 0x86,
	0xba, 0x02, 0xb8, 0x3a, 0x02, 0x3a, 0xba, 0x02, 0xba, 0x3a, 0x7e, 0x1c, 0x18, 0x04, 0x00, 0x00,
	0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0xfe, 0x00, 0x0c, 0x30, 0x00, 0x00, 0x18, 0x00, 0x18, 0x60,
	0x7e, 0x7e, 0x7e, 0x7e, 0x0c, 0x7e, 0x7e, 0x30, 0x7e, 0x3c, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18,
	0x7e, 0x66, 0x7e, 0x7e, 0x7c, 0x7e, 0x60, 0x7e, 0x66, 0x7e, 0x7e, 0xc6, 0x7e, 0xc6, 0x66, 0x7e,
	0x60, 0x7c, 0xc6, 0x7e, 0x18, 0x7e, 0x18, 0xc6, 0x66, 0x18, 0x7e, 0x1e, 0x06, 0x78, 0x00, 0xfe,
	0x00, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x18, 0x3e, 0x66, 0x3c, 0x0c, 0xce, 0x3c, 0xc6, 0x66, 0x7e,
	0x7e, 0x7e, 0x60, 0x7e, 0x1e, 0x7e, 0x18, 0xc6, 0x66, 0x3e, 0x7e, 0x18, 0x18, 0x30, 0x00, 0xff,
	0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x3c, 0x3c, 0x3c, 0x66, 0x66,
	0x7e, 0xff, 0xde, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x3e, 0x7e, 0x7e, 0x18, 0x7f, 0x18, 0x6c, 0x18,
	0x7e, 0x18, 0x18, 0x7f, 0x3e, 0x18, 0x7e, 0x6c, 0x7e, 0x7c, 0x00, 0x1a, 0x06, 0x00, 0x7c, 0x00,
	0x00, 0x7e, 0x00, 0x00, 0x7e, 0x5d, 0x0a, 0x00, 0x7e, 0x00, 0x00, 0xb0, 0xfe, 0xff, 0x18, 0x7e,
	0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xde, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e,
	0x7c, 0x66, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x00, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x18, 0x60, 0x66,
	0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0xff, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x3c, 0x3c, 0x3c, 0x3c,
	0x7e, 0x66, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x00, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x3e, 0x7e, 0x3e,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x38, 0x00, 0x00, 0x00, 0x41, 0x82,
	0x7c, 0x00, 0x7c, 0x7c, 0x00, 0x7c, 0x7c, 0x00, 0x7c, 0x7c, 0x3c, 0x00, 0x10, 0x04, 0x00, 0x00,
	0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x76, 0x00, 0x06, 0x60, 0x00, 0x00, 0x18, 0x00, 0x18, 0x60,
	0x3c, 0x7e, 0x7e, 0x3c, 0x0c, 0x3c, 0x3c, 0x30, 0x3c, 0x38, 0x18, 0x18, 0x00, 0x00, 0x00, 0x18,
	0x3c, 0x66, 0x7c, 0x3c, 0x78, 0x7e, 0x60, 0x3c, 0x66, 0x7e, 0x3c, 0xc6, 0x7e, 0xc6, 0x66, 0x3c,
	0x60, 0x36, 0xc6, 0x7c, 0x18, 0x3c, 0x18, 0x82, 0x66, 0x18, 0x7e, 0x1e, 0x06, 0x78, 0x00, 0xfe,
	0x00, 0x3e, 0x7c, 0x3e, 0x3e, 0x3e, 0x18, 0x06, 0x66, 0x3c, 0x0c, 0xc6, 0x3c, 0xc6, 0x66, 0x3c,
	0x7c, 0x3e, 0x60, 0x7c, 0x0e, 0x3e, 0x18, 0x82, 0x66, 0x06, 0x7e, 0x18, 0x18, 0x30, 0x00, 0x00,
	0x3c, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3c, 0x3c, 0x3c, 0x66, 0x66,
	0x7e, 0x7f, 0xde, 0x3c, 0x3c, 0x3c, 0x3e, 0x3e, 0x06, 0x3c, 0x3c, 0x18, 0xff, 0x18, 0x60, 0x70,
	0x3e, 0x18, 0x18, 0xff, 0x1c, 0x18, 0x7c, 0x38, 0x7c, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
	0x00, 0x7e, 0x00, 0x00, 0x7e, 0xc0, 0x0a, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x7e, 0x7f, 0x18, 0x3c,
	0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xde, 0x3c, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e, 0x7e,
	0x78, 0x66, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0xbc, 0x3c, 0x3c, 0x3c, 0x3c, 0x18, 0x60, 0x6c,
	0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x7f, 0x3e, 0x3e, 0x3e, 0x3e, 0x3e, 0x3c, 0x3c, 0x3c, 0x3c,
	0x3c, 0x66, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x00, 0xbc, 0x3e, 0x3e, 0x3e, 0x3e, 0x06, 0x7c, 0x06,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x3c, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x60, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x0e, 0x18, 0xe0, 0x00, 0x00,
	0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x60,
	0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x60, 0x7e,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0x54, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x60, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x60, 0x7c
};


FONT_HDR const fnt_l9_8x16 = {
	2,		/* font_id */
	10,		/* point */
	"8x16 system font",		/* name */
	0,		/* first_ade */
	255,	/* last_ade */
	13,		/* top */
	11,		/* ascent */
	8,		/* half */
	2,		/* descent */
	2,		/* bottom */
	7,		/* max_char_width */
	8,		/* max_cell_width */
	1,		/* left_offset */
	7,		/* right_offset */
	1,		/* thicken */
	1,		/* ul_size */
	0x5555,	/* lighten */
	0x5555,	/* skew */
	0x000d,	/* flags */
	NULL,	/* hor_table */
	fnt_l9_8x16_off_table,	/* off_table */
	fnt_l9_8x16_dat_table,	/* dat_table */
	256,	/* form_width */
	16,		/* form_height */
	NULL
};

