#include <math.h>

#include "perf.h"

extern double cnd(double x)
{
	static const double 
		a1 = +0.31938153,
		a2 = -0.356563782,
		a3 = +1.781477937,
		a4 = -1.821255978,
		a5 = +1.330274429;

	const double L = fabs(x);
	const double K = 1.0 / (1.0 + (0.2316419 * L));
    const double KK = K * K;
	const double a12345k 
		= (a1 * K)
		+ (a2 * KK) 
		+ (a3 * KK * K) 
		+ (a4 * KK * KK) 
		+ (a5 * KK * KK * K); 

	double result = 1.0 - one_div_sqrt2pi * exp(-(L * L) / 2.0) * a12345k;
		
	if(x < 0.0) 
		result = 1.0 - result;

	return result;
}
