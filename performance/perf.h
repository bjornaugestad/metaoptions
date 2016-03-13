#ifndef METAOPTIONS_PERF_H
#define METAOPTIONS_PERF_H

#include <math.h>

/* Our two functions' interface. */
extern double blackscholes_call(double S, double X, double T, double r, double v);
extern double cnd(double x);

static inline int equalish(double a, double b)
{
    #define LIMIT 0.0001
    double d = a - b;
    return (fabs(d) < LIMIT);
}


/* Our only constant. */
static const double one_div_sqrt2pi = 0.39894228040143270286;

#endif
