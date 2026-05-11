#include <stdio.h>

int valida(int val, int lim) {
    return ((val <= lim) ? 1 : 0);
}

int boo(int lim, int *v, int n);
 
int main(void) {
    int v[4] = {1, 2, 3, 4};
    int lim = 3;
    int n = sizeof(v)/sizeof(v[0]);
    
    printf("soma: %d\n", boo(lim, v, n));
    
    return 0;
}
 