#include <stdlib.h>
#include <stdio.h>

#include "perf.h"

#include "src"
#include "result"


int main(void)
{
    size_t i, n;

    // Sum all values and print, to avoid optimization.
    double res, sum = 0.0;

    n = sizeof src / sizeof *src;
    if (n != sizeof result / sizeof *result) {
        fprintf(stderr, "array mismatch\n");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        res = blackscholes_call(src[i].S, src[i].X, src[i].T, src[i].r, src[i].v);
        if (!equalish(res, result[i])) {
            fprintf(stderr, "test %zu: expected %g, got %g\n", i, result[i], res);
            exit(1);
        }

        sum += res;
    }

    printf("%zu: %g\n", i, sum);
    exit(0);
}
