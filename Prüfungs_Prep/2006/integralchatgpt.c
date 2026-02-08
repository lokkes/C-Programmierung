#include <stdio.h>

typedef double (*fVonX)(double);

double integral(fVonX f, double x1, double xn, int n)
{
    double h = (xn - x1) / n;
    double sum = 0.0;
    double x = x1;

    for (int i = 0; i < n; i++) {
        sum += (f(x) + f(x + h)) * 0.5 * h;
        x += h;
    }

    return sum;
}

