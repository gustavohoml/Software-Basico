#include <ctype.h>
#include <stdio.h>
 
int string2num (char *s, int base) {
    int a = 0;
    for (; *s; s++)
        a = a*10 + (*s - '0');

    if (base == 10)
        return a;

    if (base < 10) {
        int result = 0;
        int quociente = 0;
        int i = 1;

        do {
            quociente = a / base;
            result += ((a % base) * i);
            a = quociente;
            i = i * 10;
        } while (a >= 1);

        return result;
    }


}

int main (void) {
    //printf("%d\n", string2num("777", 10));
    //printf("%d\n", string2num("777", 8));
    //printf("%d\n", string2num("97", 8));
    //printf("%d\n", string2num("12", 8));
    //printf("%d\n", string2num("10", 2));
    printf("%d\n", string2num("256", 16));

    return 0;
}