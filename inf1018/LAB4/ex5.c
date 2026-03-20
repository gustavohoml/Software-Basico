#include <stdio.h>

int main(void) {
    signed char sc = -1;
    unsigned int ui = sc;
    printf("sc=%d, ui=%u\n", sc, ui);

    return 0;
}