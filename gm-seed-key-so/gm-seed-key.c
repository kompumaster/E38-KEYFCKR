/* 
 * gm-seed-key.c
 * seed to key generator for old GM units with 2 unsigned chars keys.
 *
 * Based on: 
 * https://github.com/YustasSwamp/gm-seed-key
 * http://www.gearhead-efi.com/Fuel-Injection/showthread.php?7286-Gm-Seed-key-algorithms
 * https://github.com/SCResearch/GM-Seed-key-Tester
 *
 *
 */ 

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_class2.h"
#include "table_gmlan.h"
#include "table_others.h"



/* flip unsigned chars */
unsigned short op_05(unsigned short val)
{
	return (val << 8) | (val >> 8);
}

/* addition */
unsigned short op_14(unsigned short val, unsigned char hh, unsigned char ll)
{
	return val + (((unsigned short)hh << 8) | ll);
}

/* 1's (or 2's) complement */
unsigned short op_2a(unsigned short val, unsigned char hh, unsigned char ll)
{
	val = ~val;
	if ( hh < ll )
		val++;
	return val;
}

/* and with flipped operand */
static unsigned short op_37(unsigned short val, unsigned char hh, unsigned char ll)
{
	return val & (((unsigned short)ll << 8) | hh);
}

/* ratate left by hh */
static unsigned short op_4c(unsigned short val, unsigned char hh, unsigned char ll)
{
	return ( val << hh) | (val >> ( 16 - hh ));
}

/* or with flipped operand */
static unsigned short op_52(unsigned short val, unsigned char hh, unsigned char ll)
{
	return val | hh | ((unsigned short)ll << 8);
}

/* rotate right by ll */
static unsigned short op_6b(unsigned short val, unsigned char hh, unsigned char ll)
{
	return (val >> ll) | (val << (16 - ll));
}

/* addition with flipped operand */
static unsigned short op_75(unsigned short val, unsigned char hh, unsigned char ll)
{
	return val + (((unsigned short)ll << 8) | hh);
}

/* filp unsigned chars, and add (flipped) operand */
static unsigned short op_7e(unsigned short val, unsigned char hh, unsigned char ll)
{
	if ( hh >= ll )
		return op_14(op_05(val), hh, ll);
	return op_75(op_05(val), hh, ll);
}

/* substraction */
static unsigned short op_98(unsigned short val, unsigned char hh, unsigned char ll)
{
	return val - (((unsigned short)hh << 8) | ll);
}

/* substraction of flipped operand */
static unsigned short op_f8(unsigned short val, unsigned char hh, unsigned char ll)
{
	return val - (((unsigned short)ll << 8) | hh);
}

unsigned short get_key_gmlan(unsigned short seed, unsigned char algo, unsigned char proto)
{
	int idx, i;
	unsigned char hh, ll, code;
	unsigned char *table = table_gmlan;

	switch (proto) {
		case 0x02:
			table = table_class2;
			break;
		case 0x03:
			table = table_others;
			break;
	}

	if (algo == 0)
		return ~seed;

	idx = algo * 13;
	for (i = 0; i < 4; i++) {
		code = table[idx];
		hh = table[idx + 1];
		ll = table[idx + 2];
		switch (code) {
			case 0x05:
				seed = op_05(seed);
				break;
			case 0x14:
				seed = op_14(seed, hh, ll);
				break;
			case 0x2A:
				seed = op_2a(seed, hh, ll);
				break;
			case 0x37:
				seed = op_37(seed, hh, ll);
				break;
			case 0x4C:
				seed = op_4c(seed, hh, ll);
				break;
			case 0x52:
				seed = op_52(seed, hh, ll);
				break;
			case 0x6b:
				seed = op_6b(seed, hh, ll);
				break;
			case 0x75:
				seed = op_75(seed, hh, ll);
				break;
			case 0x7e:
				seed = op_7e(seed, hh, ll);
				break;
			case 0x98:
				seed = op_98(seed, hh, ll);
				break;
			case 0xf8:
				seed = op_f8(seed, hh, ll);
				break;

		}
		idx += 3;
	}
	return seed;
}
