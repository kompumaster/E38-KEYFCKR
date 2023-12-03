/*
Confirmed on e38 seed/key.
It has this algorithm (0x92), which is part of current table.

7e 7d 58 2a b8 70 75 01 80 05 2f 98
#unsigned int E38(unsigned int seeds)
{
	int key = 0;
	key = ((seeds & 0x0000FF00) >> 8) | ((seeds & 0x000000FF) << 8);
	key = key + 0x7D58;
	key = ~key;
	key = key & 0xFFFF;
	key = key + 0x8001;
	key = ((key & 0x0000FF00) >> 8) | ((key & 0x000000FF) << 8);
	return key;
}
*/

unsigned char table_gmlan[3328] = {
	0x47, 0x47, 0x45, 0x76, 0x37, 0x45, 0x59, 0x2E, 0x45, 0x2A, 0x25, 0x1F, 0x00, 0x75, 0xFF, 0x78, 
	0x05, 0xF5, 0x3D, 0x98, 0x20, 0xA0, 0x6B, 0xB4, 0x04, 0xA0, 0x14, 0x0C, 0x4D, 0x05, 0x05, 0x3E, 
	0x75, 0xC0, 0x54, 0x4C, 0x04, 0xA1, 0xC0, 0x14, 0x54, 0x28, 0x7E, 0xA1, 0xD4, 0x6B, 0x80, 0x04, 
	0x75, 0x44, 0x0E, 0xF0, 0x7E, 0xC7, 0x44, 0x6B, 0x13, 0x01, 0xF8, 0xC9, 0x38, 0x4C, 0x02, 0xE8, 
	0x8C, 0x98, 0x32, 0xA6, 0x4C, 0x04, 0x2A, 0x7E, 0x8C, 0x71, 0x05, 0xB9, 0xAA, 0xFC, 0x75, 0x12, 
	0xA3, 0x2A, 0x91, 0x59, 0x14, 0x6A, 0xB9, 0x7E, 0x65, 0xAE, 0xAE, 0x2A, 0xC6, 0x59, 0x75, 0x6B, 
	0x09, 0x7E, 0x96, 0xF6, 0x4C, 0x03, 0x99, 0xEE, 0x7E, 0x99, 0x41, 0x6B, 0x0F, 0x06, 0x75, 0xC0, 
	0x48, 0x05, 0x8E, 0xA4, 0xA8, 0x05, 0xA4, 0x4A, 0x98, 0x72, 0x49, 0x2A, 0xA0, 0xA3, 0x7E, 0x92, 
	0x2E, 0x03, 0x14, 0x42, 0xC4, 0x98, 0xB6, 0xBC, 0x4C, 0x05, 0x2E, 0x7E, 0x30, 0x2C, 0x3D, 0x98, 
	0x38, 0x08, 0x7E, 0xF2, 0x94, 0x6B, 0xE0, 0x02, 0x4C, 0x03, 0x48, 0xC9, 0x7E, 0x72, 0xE0, 0x98, 
	0xB9, 0xB0, 0x14, 0x5C, 0x27, 0x2A, 0xAB, 0x08, 0xA0, 0x6B, 0xC0, 0x02, 0x75, 0x33, 0xFA, 0x4C, 
	0x04, 0x3B, 0x98, 0xEF, 0x92, 0xBE, 0x7E, 0xFA, 0xCA, 0x2A, 0x30, 0x50, 0x6B, 0x63, 0x02, 0xF8, 
	0x2B, 0x7B, 0x3B, 0x7E, 0x30, 0xCF, 0x6B, 0x04, 0x05, 0x2A, 0xD5, 0x2E, 0x98, 0xD9, 0xDA, 0x66, 
	0x14, 0xBF, 0x3E, 0x7E, 0x5C, 0xEE, 0x05, 0xCF, 0xFD, 0x4C, 0x04, 0x30, 0xF6, 0x98, 0x30, 0x91, 
	0x7E, 0x6B, 0xBD, 0x4C, 0x07, 0x7B, 0xF8, 0xED, 0x75, 0x03, 0x7E, 0xB0, 0x63, 0x4C, 0x01, 0x40, 
	0x14, 0x4E, 0x42, 0x98, 0xCA, 0x34, 0x7E, 0xF8, 0x49, 0x30, 0x7E, 0x0C, 0x71, 0x4C, 0x06, 0xC7, 
	0x98, 0xB8, 0xB8, 0xEC, 0x4C, 0x04, 0xE3, 0x14, 0x8E, 0x33, 0x7E, 0xC0, 0x02, 0x05, 0x75, 0x26, 
	0xD4, 0x4C, 0x04, 0xCF, 0x98, 0xDD, 0x07, 0x6B, 0xB7, 0x04, 0x05, 0xD4, 0x51, 0x42, 0x6B, 0x11, 
	0x05, 0x05, 0xD4, 0x51, 0x14, 0xBF, 0x45, 0x4C, 0x07, 0xF5, 0x64, 0x6B, 0xA1, 0x01, 0xF8, 0x46, 
	0x9D, 0x4C, 0x04, 0x57, 0x7E, 0x98, 0x88, 0x98, 0x75, 0x6E, 0x3F, 0x4C, 0x04, 0x47, 0x98, 0x68, 
	0x42, 0x05, 0x34, 0x04, 0x42, 0x05, 0x34, 0x04, 0x2A, 0xD0, 0xBF, 0x6B, 0x31, 0x04, 0x7E, 0x80, 
	0x1C, 0x0E, 0x6B, 0xE0, 0x04, 0x98, 0x4C, 0x08, 0x2A, 0x16, 0x49, 0xF8, 0xF0, 0xC0, 0xA0, 0x6B, 
	0x16, 0x06, 0x2A, 0xC0, 0x43, 0xF8, 0x7C, 0x08, 0x7E, 0x22, 0x5E, 0x5E, 0x2A, 0x62, 0x23, 0x05, 
	0xD2, 0x22, 0xF8, 0xC1, 0x44, 0x7E, 0x08, 0xC0, 0x44, 0x2A, 0xBC, 0x07, 0xF8, 0x10, 0x32, 0x6B, 
	0x21, 0x03, 0x05, 0x63, 0x24, 0x22, 0x14, 0x24, 0x32, 0x4C, 0x02, 0x23, 0x05, 0x11, 0x4C, 0x2A, 
	0x44, 0x8F, 0x00, 0x14, 0x41, 0xE4, 0x7E, 0x44, 0xC2, 0x6B, 0x44, 0x06, 0xF8, 0x24, 0x23, 0x24, 
	0x7E, 0x44, 0x5A, 0x6B, 0xEA, 0x02, 0x98, 0x34, 0x44, 0x05, 0xC6, 0x98, 0x7E, 0x4C, 0x04, 0x39, 
	0x98, 0x01, 0x12, 0x6B, 0x26, 0x05, 0x05, 0xC6, 0x98, 0x00, 0x98, 0x8C, 0xA9, 0x7E, 0x88, 0x8C, 
	0x6B, 0xF9, 0x01, 0xF8, 0x8C, 0xD9, 0xF8, 0xF8, 0x98, 0xC0, 0x6B, 0xD9, 0x04, 0x7E, 0xD2, 0x8C, 
	0x4C, 0x05, 0x98, 0xEE, 0x6B, 0x49, 0x07, 0x7E, 0x07, 0x4C, 0x05, 0x23, 0x04, 0xF8, 0x42, 0xA0, 
	0x40, 0x05, 0x23, 0x04, 0xF8, 0x42, 0xA0, 0x6B, 0x04, 0x02, 0x2A, 0x04, 0x49, 0x05, 0x14, 0x2A, 
	0x02, 0x6B, 0xD5, 0x01, 0x7E, 0xF8, 0x01, 0x2A, 0x25, 0x07, 0x04, 0x75, 0x62, 0x0A, 0x4C, 0x02, 
	0xB2, 0x05, 0xA9, 0x0E, 0xF8, 0xC1, 0x44, 0x80, 0x4C, 0x04, 0x6E, 0x75, 0x20, 0xA6, 0x7E, 0xAA, 
	0x22, 0x2A, 0x62, 0x69, 0xA6, 0x2A, 0x62, 0x69, 0x4C, 0x06, 0x9A, 0x7E, 0x2A, 0x31, 0x05, 0x3E, 
	0xA6, 0xAA, 0x2A, 0xA6, 0x75, 0x14, 0xAA, 0x38, 0x4C, 0x02, 0x63, 0x05, 0x3E, 0xA6, 0xFA, 0x14, 
	0x2A, 0x04, 0x05, 0x4C, 0x54, 0x98, 0xB1, 0x68, 0x7E, 0x0B, 0xC8, 0x0A, 0x98, 0xC6, 0x80, 0x4C, 
	0x04, 0x22, 0xF8, 0x6C, 0x13, 0x7E, 0x19, 0xC8, 0x80, 0x7E, 0x19, 0xC8, 0x4C, 0x01, 0xAC, 0x14, 
	0xC8, 0x02, 0x05, 0xC8, 0xEA, 0xC8, 0x2A, 0x82, 0x2B, 0xF8, 0xC8, 0x86, 0x4C, 0x04, 0x29, 0x98, 
	0xE2, 0x82, 0x1F, 0x7E, 0xF4, 0x1F, 0x2A, 0x0C, 0x4C, 0x98, 0x01, 0xAC, 0x4C, 0x06, 0x96, 0xC2, 
	0x6B, 0x6C, 0x05, 0x98, 0xEA, 0x83, 0x4C, 0x02, 0x4C, 0x75, 0x30, 0x14, 0xBE, 0x14, 0x74, 0xF0, 
	0x4C, 0x04, 0x0E, 0x98, 0x01, 0x30, 0x05, 0xB3, 0x01, 0x00, 0xF8, 0x14, 0x57, 0x2A, 0x19, 0xB2, 
	0x75, 0x70, 0x1C, 0x05, 0x37, 0x02, 0x00, 0x2A, 0x02, 0x2F, 0x05, 0x37, 0x02, 0xF8, 0x93, 0x02, 
	0x4C, 0x02, 0x0B, 0x70, 0x2A, 0x0B, 0x02, 0x4C, 0x03, 0x03, 0x75, 0x8F, 0x03, 0x6B, 0xC1, 0x04, 
	0x21, 0x14, 0xF0, 0x86, 0x6B, 0xB9, 0x06, 0x98, 0xB1, 0x09, 0x4C, 0x02, 0xC1, 0x44, 0x4C, 0x04, 
	0x0C, 0xF8, 0x06, 0x36, 0x6B, 0x60, 0x03, 0x98, 0x36, 0xE3, 0x61, 0x6B, 0x6F, 0x03, 0x4C, 0x09, 
	0x11, 0x14, 0x2A, 0x0D, 0x98, 0x2C, 0x91, 0x91, 0x4C, 0x01, 0x31, 0x98, 0x3A, 0x72, 0x2A, 0x9C, 
	0x3D, 0x7E, 0x99, 0xED, 0xED, 0x6B, 0x65, 0x07, 0x4C, 0x0A, 0x77, 0x7E, 0xF8, 0xDA, 0x98, 0x3F, 
	0x52, 0x4C, 0x98, 0x45, 0xD7, 0x6B, 0x60, 0x07, 0x75, 0xC1, 0x44, 0x4C, 0x04, 0x0D, 0x44, 0x4C, 
	0x04, 0x0D, 0x75, 0x1A, 0x1F, 0x7E, 0x40, 0xDC, 0x05, 0x70, 0x7B, 0x00, 0xF8, 0x22, 0x70, 0x2A, 
	0x02, 0xF6, 0x14, 0x70, 0xAF, 0x7E, 0x22, 0x50, 0x22, 0x7E, 0xD8, 0x37, 0x05, 0x97, 0xFC, 0x6B, 
	0xCC, 0x07, 0x14, 0x7D, 0xCF, 0xCC, 0x05, 0xDF, 0xFC, 0x14, 0xDF, 0xFC, 0x7E, 0xBD, 0x41, 0x6B, 
	0xC0, 0x06, 0x40, 0x6B, 0xC0, 0x06, 0x98, 0x3B, 0x21, 0x4C, 0x07, 0x92, 0x05, 0x79, 0x2A, 0x2A, 
	0x98, 0xD3, 0x22, 0x6B, 0x2F, 0x02, 0x7E, 0x23, 0xB9, 0x05, 0x92, 0xEB, 0x22, 0x4C, 0x05, 0x92, 
	0x75, 0x23, 0x79, 0x6B, 0x48, 0x03, 0x14, 0xB8, 0x02, 0x00, 0x4C, 0x02, 0xFB, 0x2A, 0x03, 0xFA, 
	0x7E, 0xB0, 0x73, 0x05, 0x17, 0xC2, 0xC1, 0x7E, 0xE4, 0x35, 0x6B, 0x78, 0x06, 0x2A, 0x10, 0x16, 
	0x98, 0xA7, 0x7B, 0x26, 0x2A, 0x7C, 0x16, 0x6B, 0xC7, 0x01, 0x05, 0x21, 0xC2, 0xF8, 0x22, 0xBC, 
	0x0C, 0x98, 0x4C, 0xA4, 0x6B, 0xF4, 0x04, 0x75, 0x39, 0xD4, 0x05, 0xC1, 0x3D, 0x05, 0x7E, 0xCC, 
	0x06, 0x14, 0xCD, 0xF6, 0x6B, 0x4A, 0x07, 0x4C, 0x05, 0x8F, 0xE2, 0xF8, 0xD0, 0x4A, 0x2A, 0xD6, 
	0x93, 0x6B, 0xF9, 0x04, 0x7E, 0x4F, 0xF9, 0x4E, 0x2A, 0xA4, 0x2F, 0x7E, 0x02, 0xF2, 0x6B, 0xD4, 
	0x07, 0x75, 0x91, 0xD4, 0xD4, 0x4C, 0x04, 0xFD, 0x75, 0xD4, 0x3F, 0x6B, 0x0A, 0x03, 0x98, 0x01, 
	0x50, 0x00, 0x7E, 0x87, 0x01, 0x2A, 0x20, 0x07, 0x6B, 0x30, 0x01, 0xF8, 0x10, 0xFE, 0x10, 0x4C, 
	0x04, 0x10, 0x14, 0xFE, 0x78, 0x2A, 0x04, 0x57, 0xF8, 0x91, 0x0B, 0xEB, 0x2A, 0x7E, 0x5A, 0x98, 
	0x08, 0x62, 0x4C, 0x05, 0x0C, 0x6B, 0xE5, 0x05, 0x82, 0x2A, 0xB8, 0x1F, 0x7E, 0x2E, 0xC8, 0x4C, 
	0x05, 0xB8, 0x75, 0x2E, 0xC8, 0x2D, 0x7E, 0xFF, 0x12, 0x14, 0xAD, 0xD3, 0x98, 0xE0, 0x35, 0x2A, 
	0x97, 0x27, 0xE4, 0x75, 0x08, 0x06, 0x05, 0xAA, 0x41, 0x4C, 0x04, 0xE1, 0x7E, 0x64, 0xD8, 0x03, 
	0x6B, 0xD2, 0x06, 0x2A, 0x4C, 0xA5, 0x4C, 0x03, 0x4C, 0x7E, 0xA2, 0x8E, 0x8F, 0x14, 0x1E, 0xB8, 
	0x7E, 0xE1, 0xA2, 0x6B, 0x84, 0x0B, 0x98, 0x60, 0x10, 0x11, 0x6B, 0x83, 0x03, 0x14, 0x60, 0xBC, 
	0x7E, 0x20, 0x9C, 0x98, 0x02, 0x18, 0x19, 0x2A, 0x1A, 0xEF, 0x6B, 0x1A, 0x02, 0x7E, 0x99, 0xF8, 
	0x4C, 0x01, 0x0C, 0x0D, 0x14, 0x14, 0x30, 0x4C, 0x0A, 0x07, 0x6B, 0x01, 0x01, 0x7E, 0xE8, 0x73, 
	0x26, 0x14, 0x81, 0x35, 0x4C, 0x06, 0x74, 0xF8, 0x1B, 0x71, 0x7E, 0x46, 0x23, 0x01, 0x14, 0xB4, 
	0x10, 0x2A, 0x3C, 0x2D, 0x7E, 0xB0, 0x85, 0x6B, 0xAC, 0x03, 0xB8, 0x7E, 0x10, 0x6E, 0x2A, 0x1B, 
	0x24, 0x14, 0xC6, 0x51, 0x05, 0x1B, 0x77, 0x14, 0x98, 0xB4, 0x85, 0x4C, 0x01, 0x31, 0x7E, 0xC8, 
	0x0B, 0x05, 0x09, 0x3D, 0x98, 0x98, 0x0B, 0x22, 0x05, 0x50, 0x32, 0x14, 0x94, 0x54, 0x6B, 0x02, 
	0x04, 0x0C, 0x98, 0x22, 0x8E, 0x6B, 0x02, 0x04, 0xF8, 0x9E, 0x1C, 0x2A, 0x38, 0x49, 0x38, 0x98, 
	0x98, 0xA0, 0x4C, 0x05, 0x28, 0xF8, 0x2A, 0x4A, 0x6B, 0x52, 0x02, 0x52, 0x98, 0xA3, 0x94, 0x2A, 
	0xC1, 0x43, 0xF8, 0xF0, 0xA3, 0x6B, 0xC1, 0x04, 0xA2, 0x2A, 0x7E, 0xAF, 0x4C, 0x04, 0x68, 0x98, 
	0xF8, 0xA2, 0x05, 0x57, 0x03, 0x56, 0xF8, 0x66, 0x37, 0x2A, 0x60, 0x25, 0x14, 0x07, 0x13, 0x6B, 
	0x01, 0x04, 0x02, 0x6B, 0x01, 0x04, 0x14, 0x65, 0x6E, 0x7E, 0x99, 0xB2, 0x05, 0x26, 0x33, 0x97, 
	0xF8, 0x8E, 0x65, 0x7E, 0x20, 0x07, 0x05, 0x26, 0x6E, 0x6B, 0x27, 0x04, 0x4D, 0xF8, 0x68, 0x13, 
	0x2A, 0x85, 0x35, 0x7E, 0xCD, 0x08, 0x05, 0x78, 0xE7, 0xE9, 0x14, 0x78, 0xE7, 0x4C, 0x04, 0x09, 
	0xF8, 0xF9, 0x82, 0x7E, 0xF6, 0x20, 0x9D, 0x6B, 0x48, 0x07, 0x98, 0xD2, 0x79, 0x7E, 0x46, 0x22, 
	0x05, 0x10, 0x14, 0x49, 0x4C, 0x06, 0xD2, 0x98, 0x8D, 0x74, 0x7E, 0x9D, 0xFB, 0x05, 0x10, 0x14, 
	0x27, 0x75, 0x30, 0x91, 0x05, 0x10, 0x14, 0x14, 0xC0, 0x38, 0x2A, 0x7A, 0x2F, 0x31, 0x75, 0x03, 
	0x30, 0x6B, 0x04, 0x06, 0x05, 0x81, 0x87, 0xF8, 0xE8, 0x22, 0x87, 0x7E, 0xE0, 0xA1, 0x6B, 0x78, 
	0x04, 0x05, 0x1E, 0x9A, 0x98, 0x87, 0x6E, 0xC1, 0x05, 0x13, 0xC9, 0x98, 0x48, 0x01, 0x7E, 0x91, 
	0xA6, 0x6B, 0x18, 0x01, 0x71, 0x2A, 0x69, 0x1D, 0x05, 0xEA, 0x87, 0x75, 0x96, 0x62, 0x6B, 0x39, 
	0x06, 0x29, 0xF8, 0x46, 0x8A, 0x7E, 0x91, 0xF6, 0x6B, 0xC1, 0x01, 0x75, 0x16, 0xF0, 0x75, 0x75, 
	0x16, 0xF0, 0x05, 0x3C, 0x4D, 0x98, 0x4F, 0xA7, 0x7E, 0xF0, 0xF4, 0x53, 0x7E, 0xF0, 0xF4, 0x4C, 
	0x04, 0xF5, 0xF8, 0x4F, 0x11, 0x05, 0xF0, 0xD4, 0xF1, 0x6B, 0x13, 0x04, 0x7E, 0x05, 0x4F, 0x2A, 
	0xC1, 0xD2, 0x05, 0x1A, 0x3C, 0x1B, 0x2A, 0xFD, 0x05, 0x05, 0x07, 0x20, 0x14, 0x2C, 0xA0, 0x7E, 
	0x07, 0xBA, 0xE9, 0x14, 0x16, 0xD5, 0x05, 0xC5, 0x20, 0x6B, 0x09, 0x03, 0x2A, 0xC2, 0x15, 0x29, 
	0x2A, 0xAA, 0x8A, 0xF8, 0x5A, 0xA3, 0x05, 0x2A, 0x38, 0x75, 0x20, 0x08, 0xBB, 0x7E, 0xAE, 0x52, 
	0x6B, 0x08, 0x07, 0x05, 0x46, 0xA0, 0x98, 0xE8, 0x15, 0x1D, 0x05, 0x15, 0x08, 0x6B, 0xDD, 0x02, 
	0x7E, 0x62, 0xE8, 0x4C, 0x04, 0x26, 0xB5, 0x75, 0x7A, 0x95, 0x4C, 0x04, 0x26, 0x7E, 0x21, 0x4C, 
	0x2A, 0x8E, 0x04, 0x8F, 0x6B, 0xC0, 0x02, 0x05, 0x5B, 0x8D, 0x98, 0x8E, 0x23, 0x7E, 0x82, 0x74, 
	0xC3, 0x6B, 0x7A, 0x04, 0x7E, 0x82, 0x74, 0x4C, 0x05, 0x43, 0x05, 0x1B, 0x9D, 0x5F, 0x98, 0x59, 
	0x5F, 0x7E, 0xD6, 0x1B, 0x4C, 0x05, 0x47, 0x05, 0xBC, 0xD6, 0x85, 0x7E, 0xB6, 0xB6, 0x6B, 0xAF, 
	0x05, 0x2A, 0xF0, 0x59, 0x05, 0xBC, 0xD6, 0xBD, 0x05, 0x46, 0x98, 0x14, 0x08, 0x72, 0x2A, 0x76, 
	0x08, 0x7E, 0xDD, 0x02, 0x09, 0x7E, 0xDD, 0x02, 0x2A, 0xC1, 0x5A, 0x6B, 0xF0, 0x06, 0xF8, 0xD1, 
	0xC1, 0xF5, 0x2A, 0x6F, 0xD0, 0x4C, 0x03, 0x7B, 0x75, 0x47, 0x98, 0x05, 0x50, 0x17, 0x05, 0x14, 
	0x0B, 0x10, 0x7E, 0x17, 0x06, 0x6B, 0xD5, 0x01, 0x75, 0x40, 0x5D, 0x41, 0xF8, 0x33, 0x50, 0x05, 
	0x11, 0xD4, 0x75, 0x04, 0x75, 0x7E, 0x17, 0x18, 0x5B, 0x7E, 0x17, 0x18, 0x6B, 0x75, 0x06, 0x14, 
	0xBD, 0x41, 0x05, 0x75, 0x0D, 0x57, 0xF8, 0xD4, 0xE5, 0x05, 0x75, 0x0D, 0x98, 0x84, 0x89, 0x4C, 
	0x02, 0x6F, 0x83, 0x6B, 0x6F, 0x02, 0x2A, 0x8B, 0x04, 0x14, 0xA2, 0x01, 0x05, 0xF0, 0xFB, 0xAF, 
	0x05, 0xF0, 0xFB, 0x14, 0x66, 0x02, 0x2A, 0xBB, 0x0A, 0xF8, 0xBF, 0xE6, 0xF1, 0x05, 0x0B, 0xFC, 
	0x14, 0x03, 0xBF, 0x6B, 0xC0, 0x07, 0x2A, 0xF0, 0xEA, 0x0F, 0x14, 0x66, 0x20, 0x7E, 0x01, 0x30, 
	0x6B, 0x0D, 0x07, 0xF8, 0x36, 0x0C, 0xF7, 0x2A, 0xC3, 0x46, 0x14, 0x70, 0x15, 0x4C, 0x07, 0x62, 
	0x75, 0xD8, 0xB0, 0xC3, 0x75, 0xD8, 0xB0, 0x2A, 0x36, 0x8B, 0x4C, 0x03, 0x63, 0x05, 0xD8, 0xF0, 
	0xD9, 0x2A, 0x3F, 0x35, 0xF8, 0x25, 0x4C, 0x6B, 0x58, 0x06, 0x05, 0x90, 0xE3, 0x8F, 0x05, 0x90, 
	0xE3, 0x2A, 0xE4, 0xF7, 0xF8, 0x56, 0x43, 0x7E, 0x15, 0x39, 0x91, 0x14, 0x4F, 0xE4, 0x7E, 0x15, 
	0x39, 0x2A, 0x8E, 0xAC, 0x75, 0x63, 0x72, 0x73, 0xF8, 0x38, 0x1F, 0x05, 0xC0, 0x12, 0x6B, 0x33, 
	0x05, 0x14, 0xD0, 0xA0, 0xA1, 0x4C, 0x06, 0xA8, 0x7E, 0x17, 0xAA, 0x6B, 0x86, 0x02, 0x75, 0x8E, 
	0x2A, 0x8B, 0x6B, 0x82, 0x04, 0x98, 0xC2, 0x86, 0x2A, 0x4C, 0x23, 0x14, 0x05, 0xC0, 0x73, 0x6B, 
	0xAA, 0x03, 0x75, 0x8D, 0xC8, 0x2A, 0xCA, 0x5F, 0x98, 0x59, 0x82, 0xAB, 0x14, 0xB6, 0x0C, 0x4C, 
	0x05, 0x07, 0xF8, 0x5F, 0x59, 0x2A, 0x91, 0x04, 0xE7, 0x14, 0x67, 0x47, 0x2A, 0x50, 0x43, 0x6B, 
	0x41, 0x05, 0x98, 0xF0, 0x59, 0xE5, 0xF8, 0xD6, 0xBC, 0x6B, 0x5F, 0x04, 0x14, 0x72, 0x0B, 0x2A, 
	0x95, 0x80, 0x1F, 0x14, 0xDD, 0x02, 0x2A, 0xF2, 0x52, 0x6B, 0xE6, 0x06, 0xF8, 0xD1, 0xC1, 0xE7, 
	0x98, 0xA5, 0x53, 0x2A, 0x69, 0x16, 0x05, 0x7A, 0x06, 0x4C, 0x06, 0xA5, 0xA5, 0x6B, 0x61, 0x01, 
	0x2A, 0x58, 0xF9, 0x7E, 0x96, 0x26, 0x05, 0xE9, 0x7D, 0x61, 0x7E, 0x7D, 0x58, 0x2A, 0xB8, 0x70, 
	0x75, 0x01, 0x80, 0x05, 0x2F, 0x98, 0x59, 0x98, 0x60, 0xD6, 0x7E, 0xF5, 0x10, 0x05, 0x84, 0x59, 
	0x2A, 0x98, 0x34, 0x61, 0x05, 0x72, 0x98, 0x6B, 0x42, 0x04, 0x98, 0x57, 0x80, 0x4C, 0x01, 0x6C, 
	0xB9, 0x98, 0x76, 0x01, 0x4C, 0x01, 0x6C, 0x14, 0x04, 0x80, 0x05, 0x76, 0x01, 0xF7, 0x98, 0x90, 
	0x83, 0x7E, 0xA0, 0x76, 0x6B, 0xA0, 0x05, 0xF8, 0x68, 0x5B, 0xD5, 0x05, 0x6D, 0x39, 0x6B, 0x5B, 
	0x07, 0x98, 0x16, 0x84, 0x2A, 0xA1, 0x6C, 0x6D, 0x4C, 0x04, 0xBB, 0x98, 0xD6, 0x85, 0x7E, 0x6D, 
	0x26, 0x05, 0xDA, 0x15, 0x05, 0x05, 0xDA, 0x15, 0x75, 0xB5, 0x7B, 0x6B, 0xEF, 0x02, 0xF8, 0xDA, 
	0xE1, 0xDB, 0x14, 0xA8, 0x77, 0x2A, 0x50, 0xEC, 0x98, 0xF0, 0xBB, 0x05, 0x3A, 0x20, 0xF9, 0x4C, 
	0x05, 0xFE, 0x98, 0x8B, 0x7F, 0x2A, 0xE3, 0xDE, 0x75, 0xB5, 0x93, 0xB5, 0xF8, 0xA0, 0xF0, 0x7E, 
	0xE1, 0x67, 0x6B, 0x78, 0x04, 0x98, 0x89, 0x86, 0x6F, 0x98, 0x86, 0x87, 0x4C, 0x04, 0x38, 0x75, 
	0x50, 0xED, 0x7E, 0x0C, 0xF8, 0x01, 0x98, 0xB3, 0x0C, 0x6B, 0x78, 0x04, 0x7E, 0xDE, 0x88, 0x05, 
	0xDA, 0x57, 0x1B, 0x75, 0x26, 0x2F, 0x7E, 0x03, 0x04, 0x4C, 0x06, 0x2F, 0x14, 0x50, 0x6D, 0x2F, 
	0x98, 0x40, 0x01, 0x7E, 0x6D, 0x14, 0x05, 0xDA, 0x57, 0x4C, 0x01, 0x01, 0x79, 0x75, 0x80, 0xD0, 
	0x05, 0xC7, 0xA3, 0x2A, 0x05, 0x2F, 0x98, 0x03, 0xAA, 0xAB, 0x6B, 0x81, 0x01, 0x98, 0x03, 0x46, 
	0x2A, 0xF4, 0x18, 0xF8, 0x10, 0x46, 0xF5, 0x05, 0x18, 0x5D, 0x98, 0x84, 0xD1, 0x6B, 0x61, 0x04, 
	0x2A, 0x9D, 0x1C, 0x19, 0x4C, 0x05, 0x46, 0x7E, 0xC1, 0x03, 0x05, 0xAD, 0x17, 0xF8, 0x5E, 0x37, 
	0x0D, 0x4C, 0x07, 0x02, 0x7E, 0x2D, 0x89, 0x2A, 0xB0, 0xBC, 0x75, 0x1D, 0x0E, 0x2F, 0x14, 0x0B, 
	0x24, 0x7E, 0xED, 0x72, 0x6B, 0xBD, 0x02, 0x75, 0x1D, 0x0E, 0xD7, 0x4C, 0x06, 0x32, 0x75, 0x1D, 
	0x0E, 0x2A, 0xF6, 0x31, 0x7E, 0x5E, 0x6E, 0x5F, 0x14, 0x6E, 0xF0, 0x7E, 0x1E, 0x7C, 0x05, 0xDF, 
	0xAB, 0xF8, 0x6A, 0x6B, 0x6B, 0x7E, 0xA1, 0xF0, 0x6B, 0xE0, 0x04, 0x75, 0x59, 0x81, 0x4C, 0x05, 
	0x5E, 0xBF, 0x4C, 0x05, 0x5E, 0xF8, 0x05, 0xAA, 0x6B, 0x85, 0x01, 0x98, 0xA0, 0x85, 0x01, 0x05, 
	0x85, 0x01, 0xF8, 0xA7, 0xF9, 0x7E, 0x04, 0x40, 0x6B, 0x83, 0x03, 0xD7, 0x75, 0x54, 0xC2, 0x6B, 
	0x03, 0x04, 0x7E, 0xA5, 0x97, 0x2A, 0x02, 0x49, 0x4B, 0x2A, 0x91, 0x63, 0x6B, 0x41, 0x04, 0x98, 
	0x78, 0x83, 0x05, 0x06, 0x36, 0x07, 0x14, 0x80, 0xA0, 0x6B, 0x03, 0x04, 0x05, 0xF0, 0x06, 0x75, 
	0x96, 0xE1, 0x97, 0x14, 0x0D, 0x63, 0x2A, 0x03, 0xEF, 0x7E, 0xC0, 0x02, 0x05, 0x18, 0xA0, 0x08, 
	0x2A, 0x90, 0x82, 0x98, 0x41, 0x50, 0x05, 0xFC, 0xE0, 0x14, 0x10, 0x40, 0x10, 0x75, 0xF1, 0x53, 
	0x6B, 0x36, 0x04, 0x2A, 0x0C, 0x72, 0x4C, 0x03, 0x08, 0x08, 0x7E, 0x4F, 0x07, 0x4C, 0x01, 0x4F, 
	0xF8, 0x1D, 0xD2, 0x6B, 0x0C, 0x01, 0x00, 0x98, 0x39, 0x80, 0x6B, 0x0C, 0x01, 0x05, 0xC1, 0xF7, 
	0x75, 0x87, 0x30, 0x30, 0x6B, 0x81, 0x06, 0x2A, 0xAF, 0x02, 0x98, 0xD0, 0x20, 0x05, 0x30, 0x34, 
	0xA2, 0x75, 0xB8, 0xC0, 0x4C, 0x06, 0x5A, 0x2A, 0x80, 0xD1, 0x98, 0x01, 0x94, 0x00, 0x75, 0x94, 
	0x26, 0x2A, 0x80, 0xD1, 0x4C, 0x05, 0x14, 0x05, 0x30, 0x34, 0x88, 0x05, 0x30, 0x34, 0x98, 0x91, 
	0xB0, 0x6B, 0x28, 0x04, 0x14, 0x8A, 0x82, 0x8A, 0x4C, 0x06, 0x3C, 0x2A, 0x14, 0x2F, 0xF8, 0x8E, 
	0x04, 0x05, 0x83, 0x7C, 0x82, 0x05, 0x88, 0xA2, 0x14, 0xE0, 0xCF, 0x7E, 0xB8, 0x02, 0x4C, 0x02, 
	0x48, 0x48, 0x14, 0x1F, 0x80, 0x4C, 0x07, 0x5B, 0x75, 0xD4, 0x40, 0x6B, 0xF0, 0x04, 0x02, 0x98, 
	0x14, 0x4D, 0x2A, 0x70, 0xE4, 0x6B, 0x0E, 0x06, 0x05, 0x06, 0x45, 0x00, 0x2A, 0x45, 0x12, 0x98, 
	0x0C, 0x3C, 0x6B, 0x68, 0x02, 0x75, 0x45, 0x4E, 0xA6, 0x6B, 0x02, 0x02, 0x7E, 0xDA, 0x98, 0x2A, 
	0x4E, 0x0A, 0x75, 0x38, 0x91, 0x40, 0x98, 0x91, 0x49, 0x2A, 0x40, 0x68, 0xF8, 0x87, 0x9D, 0x05, 
	0x2B, 0xB8, 0x9C, 0x05, 0x2B, 0xB8, 0x98, 0x68, 0xD5, 0x7E, 0x45, 0x46, 0x4C, 0x04, 0xB7, 0x73, 
	0x75, 0x0B, 0x0C, 0x2A, 0x77, 0x67, 0xF8, 0x21, 0xA8, 0x4C, 0x03, 0x02, 0x21, 0x4C, 0x06, 0xDA, 
	0x98, 0xC8, 0x08, 0x2A, 0x4E, 0x0A, 0x75, 0x38, 0x91, 0xD3, 0x75, 0x0A, 0x14, 0x2A, 0xAD, 0x68, 
	0xF8, 0x87, 0x9D, 0x4C, 0x07, 0xB8, 0x03, 0x75, 0x68, 0xD5, 0x2A, 0xB5, 0x46, 0x4C, 0x04, 0xB7, 
	0xF8, 0x6B, 0x73, 0xA3, 0x2A, 0x30, 0x0C, 0x4C, 0x02, 0x61, 0x75, 0xA1, 0x95, 0x6B, 0xF9, 0x01, 
	0xD9, 0x14, 0xE3, 0xA4, 0x6B, 0x3E, 0x03, 0x98, 0x32, 0x2D, 0x2A, 0x64, 0x50, 0x3F, 0x4C, 0x01, 
	0xD1, 0x98, 0xC0, 0xC4, 0x2A, 0xFB, 0xC7, 0x14, 0x60, 0x75, 0x83, 0x2A, 0xAC, 0x8E, 0x14, 0x44, 
	0x5F, 0x4C, 0x01, 0xAB, 0x98, 0xA8, 0x80, 0x37, 0x6B, 0xBF, 0x05, 0xF8, 0x40, 0xD5, 0x2A, 0xC3, 
	0x83, 0x14, 0xF0, 0xEB, 0x3D, 0x75, 0x62, 0xF4, 0x2A, 0x37, 0x24, 0x6B, 0xB2, 0x05, 0xF8, 0x40, 
	0x82, 0x03, 0x98, 0x44, 0xBC, 0x2A, 0xA7, 0x9B, 0x4C, 0x05, 0xE8, 0x75, 0x39, 0xB3, 0x03, 0x6B, 
	0x06, 0x04, 0x98, 0x04, 0x7A, 0x2A, 0xCA, 0xBE, 0x75, 0x50, 0x76, 0x61, 0xF8, 0xBC, 0xC5, 0x4C, 
	0x08, 0xEC, 0x75, 0xB7, 0x1B, 0x2A, 0x53, 0x53, 0x03, 0x4C, 0x02, 0xA0, 0x14, 0x0A, 0x01, 0x2A, 
	0x4E, 0x37, 0x98, 0x9C, 0xE9, 0xC1, 0x75, 0x06, 0xF5, 0x6B, 0x3E, 0x05, 0x2A, 0xA0, 0x37, 0xF8, 
	0x80, 0x9E, 0x0B, 0x75, 0xFA, 0x09, 0x2A, 0x94, 0x50, 0x6B, 0x75, 0x07, 0x98, 0x69, 0x18, 0xD8, 
	0x2A, 0x3D, 0x7F, 0xF8, 0x87, 0x32, 0x05, 0xC2, 0x1E, 0x4C, 0x01, 0x1D, 0x1C, 0x2A, 0xE0, 0x2E, 
	0x05, 0x0C, 0xD8, 0x98, 0x81, 0x26, 0x7E, 0x62, 0x22, 0x22, 0x98, 0x74, 0xB1, 0x4C, 0x04, 0x52, 
	0x2A, 0x48, 0x67, 0xF8, 0x4A, 0x8A, 0xD2, 0x98, 0x8A, 0x83, 0x6B, 0x13, 0x04, 0x05, 0x84, 0x39, 
	0x2A, 0x32, 0xC7, 0x38, 0x2A, 0x32, 0xC7, 0x75, 0x41, 0xD1, 0x7E, 0x45, 0x6E, 0x4C, 0x04, 0x47, 
	0x46, 0x75, 0x0F, 0xC2, 0x6B, 0x02, 0x04, 0x14, 0x91, 0xD9, 0x4C, 0x06, 0xB5, 0x02, 0x2A, 0x48, 
	0x90, 0x75, 0xBD, 0xC8, 0x6B, 0x28, 0x06, 0x05, 0x2B, 0x7E, 0x06, 0x05, 0x7E, 0x49, 0x98, 0x7E, 
	0x63, 0x6B, 0xE8, 0x06, 0xF8, 0xC6, 0x18, 0x60, 0xF8, 0x3A, 0x04, 0x05, 0xF9, 0x4F, 0x14, 0x14, 
	0xCD, 0x6B, 0xFD, 0x03, 0x68, 0x75, 0x43, 0x63, 0x6B, 0xC2, 0x04, 0x14, 0x90, 0x48, 0x05, 0x7A, 
	0x28, 0xC8, 0x14, 0x3F, 0x10, 0x6B, 0x28, 0x02, 0x7E, 0x28, 0x30, 0x05, 0x3E, 0xAC, 0x00, 0x7E, 
	0x08, 0x01, 0x05, 0x3E, 0xAC, 0x75, 0x63, 0x50, 0x6B, 0x93, 0x01, 0x50, 0xF8, 0xB0, 0x93, 0x7E, 
	0x26, 0xDD, 0x6B, 0xA0, 0x07, 0x14, 0x74, 0x54, 0xA0, 0xF8, 0x74, 0x54, 0x7E, 0x93, 0x04, 0x6B, 
	0x32, 0x05, 0x2A, 0x18, 0x91, 0xB8, 0x7E, 0xD4, 0xD3, 0x2A, 0x18, 0x91, 0x6B, 0x63, 0x04, 0xF8, 
	0x8C, 0x3F, 0x8C, 0x14, 0x5F, 0xC5, 0x4C, 0x02, 0x80, 0x2A, 0x20, 0x08, 0x05, 0x2A, 0xAC, 0x20, 
	0x14, 0x2C, 0x08, 0x4C, 0x02, 0xE8, 0x2A, 0xAC, 0xB1, 0x05, 0x38, 0xEC, 0x00, 0x98, 0x7D, 0x09, 
	0x4C, 0x06, 0xB4, 0x14, 0x68, 0x9E, 0x05, 0xAD, 0x0B, 0xE2, 0x6B, 0x36, 0x06, 0x98, 0x23, 0xA8, 
	0x4C, 0x04, 0xB3, 0x75, 0xA8, 0xE0, 0xDC, 0x7E, 0xF3, 0x6D, 0x2A, 0xE0, 0x8B, 0x05, 0xAD, 0x0B, 
	0xF8, 0xEB, 0x05, 0x04, 0x14, 0x9B, 0x1C, 0x2A, 0x32, 0x82, 0x4C, 0x03, 0xCC, 0x75, 0x46, 0x14, 
	0x14, 0x75, 0xC0, 0x22, 0x7E, 0xB4, 0xA6, 0x2A, 0xAE, 0xF5, 0x4C, 0x04, 0xC7, 0x9C, 0x75, 0x20, 
	0x80, 0x4C, 0x01, 0x5B, 0x2A, 0x41, 0xC9, 0x7E, 0x82, 0x40, 0x82, 0x75, 0x50, 0xB0, 0x6B, 0x2C, 
	0x01, 0x05, 0xC3, 0x42, 0x14, 0x40, 0x93, 0x42, 0x05, 0x90, 0x40, 0xF8, 0xD0, 0x1A, 0x6B, 0x4C, 
	0x01, 0x14, 0x02, 0x20, 0x00, 0x6B, 0x7E, 0x04, 0x7E, 0x42, 0x1D, 0x4C, 0x03, 0x40, 0x05, 0x23, 
	0x97, 0x96, 0x4C, 0x02, 0x6C, 0x2A, 0xB0, 0x4D, 0xF8, 0x24, 0x13, 0x6B, 0x4E, 0x03, 0xCC, 0xF8, 
	0x13, 0xB0, 0x2A, 0x1B, 0x34, 0x05, 0x81, 0xF3, 0x4C, 0x05, 0xAC, 0x12, 0x05, 0xCD, 0x45, 0x14, 
	0x1C, 0x74, 0x7E, 0x83, 0xF0, 0x6B, 0x70, 0x02, 0xEA, 0x14, 0x71, 0x70, 0x6B, 0x84, 0x04, 0x98, 
	0x30, 0xC4, 0x05, 0x2C, 0x6C, 0x0A, 0x14, 0xB0, 0xEC, 0x2A, 0x35, 0xD5, 0x7E, 0x6C, 0x0D, 0x05, 
	0x0B, 0x5E, 0x1E, 0x14, 0x0B, 0x17, 0x05, 0xC3, 0x32, 0x2A, 0x46, 0x68, 0x4C, 0x04, 0x9D, 0x9C, 
	0xF8, 0x1F, 0x80, 0x05, 0x31, 0x6B, 0x2A, 0x03, 0x4D, 0x75, 0x68, 0x15, 0xB2, 0x2A, 0x6A, 0xB0, 
	0x05, 0x30, 0xCD, 0xF8, 0x03, 0xE8, 0x6B, 0x08, 0x04, 0x00, 0x75, 0x65, 0x0C, 0x2A, 0xC3, 0x9F, 
	0x14, 0x20, 0x20, 0x4C, 0x02, 0xFF, 0xAE, 0x6B, 0xFF, 0x04, 0xF8, 0x8E, 0x34, 0x7E, 0x56, 0x26, 
	0x05, 0x8D, 0x11, 0x90, 0x75, 0xC2, 0x38, 0x7E, 0x56, 0x26, 0x6B, 0x01, 0x03, 0xF8, 0xC2, 0x6C, 
	0x14, 0x6B, 0x6C, 0x02, 0x2A, 0x11, 0xBF, 0x05, 0x9E, 0xCD, 0xF8, 0xDC, 0x38, 0x20, 0xF8, 0x37, 
	0xC1, 0x6B, 0x38, 0x04, 0x98, 0xCE, 0x27, 0x2A, 0x70, 0x11, 0x90, 0x2A, 0x70, 0x11, 0x14, 0xAE, 
	0x39, 0x4C, 0x04, 0xA3, 0x05, 0xBE, 0xEE, 0x78, 0x05, 0xA3, 0x97, 0x75, 0xEE, 0xE9, 0x6B, 0xEB, 
	0x07, 0xF8, 0x2E, 0xB7, 0xC7, 0xF8, 0x2E, 0xB7, 0x05, 0xA7, 0x9E, 0x75, 0xBA, 0x9B, 0x2A, 0x0F, 
	0x50, 0x0F, 0x14, 0xA2, 0x6C, 0x4C, 0x01, 0x27, 0x75, 0x90, 0x7B, 0x6B, 0x46, 0x04, 0x91, 0x2A, 
	0xE6, 0x45, 0x05, 0xB3, 0x79, 0x98, 0x8B, 0x4E, 0x7E, 0xA8, 0x3B, 0xA9, 0x09, 0x01, 0x07, 0x37, 
	0x00, 0x00, 0x07, 0xBC, 0xEA, 0x11, 0xD0, 0x43, 0x43, 0xFF, 0x75, 0x04, 0x2A, 0xA9, 0xB8, 0x07, 
	0x07, 0xE3, 0x11, 0x0F, 0x07, 0x9D, 0x09, 0x24, 0x45, 0x07, 0x11, 0x62, 0x08, 0x24, 0x99, 0xBB, 
	0xFF, 0xA0, 0xEA, 0x5F, 0xF8, 0xC8, 0xD2, 0xFA, 0xF5, 0xE4, 0x03, 0xF4, 0x2F, 0x18, 0xA1, 0x5C
};