/**
 * Dataprecision defines variables to contain
 * the precisions used in the ray tracer
 */

#pragma once

#include<math.h>

//Single precision is default
//Change to double for double precision
typedef double precision;

// Defines precision revelant functions
#define prec_sqrt(precision) sqrt(precision);
#define pow(precision) powd(precsion);

struct colour {
	int r, g, b;
};