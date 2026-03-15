#include <ctype.h>
#include <stdio.h>
 
int is_digit(char c) {
    return (((c >= 'a') && (c <= 'z')) ? 1 : 0);
}

int string2num (char *s, int base) {
    int a = 0;
    for (; *s; s++) {
        if (is_digit(*s))
            a = a*base + (*s - 'a' + 10);
        else
            a = a*base + (*s - '0');
    }
    return a;
}

int main (void) {
    printf("%d\n", string2num("1a", 16));
    printf("%d\n", string2num("a09b", 16));
    printf("%d\n", string2num("z09b", 36));

    return 0;
}