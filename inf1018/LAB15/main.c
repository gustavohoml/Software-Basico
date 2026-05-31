#include <stdio.h>
#include <math.h>
#define pi 3.141593

float foo (double a, float b);

float foo1 (float a, float b);

double foo2 (float a, float b);

double foo3 (double *a, int n);

int main(void) {
    //double a = 3;
    //float b = 2;
    //printf("(%.1f + %.1f) * (%.1f - %.1f) = %.1f \n", a, b, a, b, foo(a, b));

    //float c = pi / 6;
    //float d = 1.5;
    //printf("sen(30) + %.1f = %.1f \n", d, foo1(c, d));
    
    //float e = pi / 6;
    //float f = pi / 3;
    //printf("sen(30) + cos(60) = %.1f \n", foo2(e, f));

    double g[3] = {pi / 6, pi / 6, pi / 6};
    int h = 3;
    printf("soma = %.1f \n", foo3(g, h));

    return 0;
}
