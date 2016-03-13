#include <math.h>
#include "perf.h"

extern double blackscholes_call(double S, double X, double T, double r, double v) 
{
	double vst, d1;

	vst = v * sqrt(T);
    d1 = (log(S / X) + (r + pow(v, 2.0) / 2) * T) / vst;

	return S * cnd(d1) - X * exp(-r * T) * cnd((d1 - vst));
}
