/*
 * This file is part of RGBDS.
 *
 * Copyright (c) 1997-2018, Carsten Sorensen and RGBDS contributors.
 *
 * SPDX-License-Identifier: MIT
 */

/*
 * Fixedpoint math routines
 */

#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

#include "asm/mymath.h"
#include "asm/symbol.h"
#include "asm/warning.h"

#define fx2double(i)	((double)((i) / 65536.0))
#define double2fx(d)	((int32_t)round((d) * 65536.0))

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

/*
 * Return the _PI symbol value
 */
int32_t math_Callback_PI(void)
{
	warning(WARNING_OBSOLETE, "`_PI` is deprecated; use 3.14159\n");

	return double2fx(M_PI);
}

/*
 * Print a fixed point value
 */
void math_Print(int32_t i)
{
	uint32_t u = i;
	const char *sign = "";

	if (i < 0) {
		u = -u;
		sign = "-";
	}

	printf("%s%" PRIu32 ".%05" PRIu32, sign, u >> 16,
	       ((uint32_t)(fx2double(u) * 100000 + 0.5)) % 100000);
}

/*
 * Calculate sine
 */
int32_t math_Sin(int32_t i)
{
	return double2fx(sin(fx2double(i) * 2 * M_PI / 65536));
}

/*
 * Calculate cosine
 */
int32_t math_Cos(int32_t i)
{
	return double2fx(cos(fx2double(i) * 2 * M_PI / 65536));
}

/*
 * Calculate tangent
 */
int32_t math_Tan(int32_t i)
{
	return double2fx(tan(fx2double(i) * 2 * M_PI / 65536));
}

/*
 * Calculate arcsine
 */
int32_t math_ASin(int32_t i)
{
	return double2fx(asin(fx2double(i)) / 2 / M_PI * 65536);
}

/*
 * Calculate arccosine
 */
int32_t math_ACos(int32_t i)
{
	return double2fx(acos(fx2double(i)) / 2 / M_PI * 65536);
}

/*
 * Calculate arctangent
 */
int32_t math_ATan(int32_t i)
{
	return double2fx(atan(fx2double(i)) / 2 / M_PI * 65536);
}

/*
 * Calculate atan2
 */
int32_t math_ATan2(int32_t i, int32_t j)
{
	return double2fx(atan2(fx2double(i), fx2double(j)) / 2 / M_PI * 65536);
}

/*
 * Multiplication
 */
int32_t math_Mul(int32_t i, int32_t j)
{
	return double2fx(fx2double(i) * fx2double(j));
}

/*
 * Division
 */
int32_t math_Div(int32_t i, int32_t j)
{
	return double2fx(fx2double(i) / fx2double(j));
}

/*
 * Power
 */
int32_t math_Pow(int32_t i, int32_t j)
{
	return double2fx(pow(fx2double(i), fx2double(j)));
}

/*
 * Logarithm
 */
int32_t math_Log(int32_t i, int32_t j)
{
	return double2fx(log(fx2double(i)) / log(fx2double(j)));
}

/*
 * Round
 */
int32_t math_Round(int32_t i)
{
	return double2fx(round(fx2double(i)));
}

/*
 * Ceil
 */
int32_t math_Ceil(int32_t i)
{
	return double2fx(ceil(fx2double(i)));
}

/*
 * Floor
 */
int32_t math_Floor(int32_t i)
{
	return double2fx(floor(fx2double(i)));
}
