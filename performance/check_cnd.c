#include <stdio.h>

#include "perf.h"


int main(void)
{
    size_t i, n = 10 * 1000 * 1000;
    double sum = 0;

    for (i = 0; i < n; i++)
        sum += cnd(i);

    printf("sum: %g\n", sum);
    return 0;
}
