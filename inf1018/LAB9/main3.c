#include <stdio.h>

void foo (int a[], int n);

void printa(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void) {
    int n = 6;
    int vet[] = {1, 4, 0, 5, 3, 6};
    foo(vet, n);
    printa(vet, n);
    return 0;
}