#include<math.h>
#ifndef nuclear_PRECISION_H
#define nuclear_PRECISION_H

/**
* Defines a real number precision. nuclear can be compiled in
* single- or double-precision versions. By default, single
* precision is provided.
*/
typedef float real;
#define real_sqrt sqrt
#define real_pow powf   /** Defines the precision of the power operator. */
#define REAL_MAX 100000

#endif nuclear_PRECISION_H