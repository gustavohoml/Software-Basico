/* programa 1*/
#include <stdio.h>

int main (void) {
    printf("PROGRAMA 1: \n");
    int x = 0xffffffff;
    int y = 2;
    printf("x=%d, y=%d\n", x, y);
    printf("x é menor do que y? %s\n", (x<y)?"sim":"nao");
    printf("x=%u, y=%u\n", x, y);
    printf("x é menor do que y? %s\n\n", (x<y)?"sim":"nao");

    printf("PROGRAMA 2: \n");
    unsigned int m = 0xffffffff;
    unsigned int n = 2;
    printf("x=%d, y=%d\n", m, n);
    printf("x é menor do que y? %s\n", (m<n)?"sim":"nao");
    printf("x=%u, y=%u\n", m, n);
    printf("x é menor do que y? %s\n\n", (m<n)?"sim":"nao");

    printf("PROGRAMA 3: \n");
    int f = 0xffffffff;
    unsigned int g = 2;
    printf("x=%d, y=%d\n", f, g);
    printf("x é menor do que y? %s\n", (f<g)?"sim":"nao");
    printf("x=%u, y=%u\n", f, g);
    printf("x é menor do que y? %s\n\n", (f<g)?"sim":"nao");

    return 0;
}