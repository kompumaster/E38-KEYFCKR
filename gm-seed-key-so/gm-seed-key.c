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

unsigned short get_key(unsigned short seed, unsigned char algo, unsigned char proto)
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

int main(int argc, char **argv)
{
	unsigned char  algo = 0;
	unsigned short seed = 0;
	unsigned char  proto = 0;
	unsigned char  algo_max = 0xff;
	unsigned short seed_max = 0xffff;
	int a, c;

	while ((c = getopt (argc, argv, "a:s:p:h")) != -1)
		switch (c) {
			case 'a':
				algo = algo_max = strtol(optarg, NULL, 16);
				if (algo > 255 || algo < 0) {
					fprintf (stderr, "Algo should by in [0x00:0xff] range.\n");
					return 1;
				}
				break;
			case 's':
				seed = seed_max = strtol(optarg, NULL, 16);
				if (seed > 0xffff || seed < 0) {
					fprintf (stderr, "Seed should by in [0x0000:0xffff] range.\n");
					return 1;
				}
				break;
			case 'p':
				proto = strtol(optarg, NULL, 16);
				if (proto != 1 && proto != 2 && proto != 3) {
					fprintf (stderr, "Protocol should be one of: 1=gmlan, 2=class2, 3=others.\n");
					return 1;
				}
				break;
			case 'h':
			default:
				printf("Usage: %s <-a algo> <-s seed> <-p protocol>\n", argv[0]);
				printf("Print key(s) for provided algo, seed and protocol.\n\n");
				printf(" -a <algo>     Algorithm to use. Hex value in the range [00:ff].\n");
				printf("               If not provided - will print the keys for all algos.\n");
				printf(" -s <seed>     Input seed. Hex value in the range [0000:ffff].\n");
				printf("               If not provided - will print the keys for all seeds.\n");
				printf(" -p <protocol> Protocol to use. Acceptable vlues 1=gmlan, 2=class2, 3=others.\n");
				printf("               Default protocol is 1=gmlan.\n");
				return 0;
		}

#ifdef WITH_TESTS
	int i;
	for (i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
		if (tests[i][2] != get_key(tests[i][1], tests[i][0], table))
			printf("key(%2x, %4x) != %4x\n", tests[i][0],
				tests[i][1], tests[i][2]);
#endif

	for (; seed <= seed_max; seed++)
		for (a = algo; a <= algo_max; a++)
			printf("%04x %2x %04x\n",
				(unsigned short)seed, (unsigned char)a,
				get_key ((unsigned short)seed, (unsigned char)a, (unsigned char)proto));
	return 0;
}
