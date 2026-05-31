#include <stdio.h>
#include <math.h>
#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)
#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))

typedef union { 
  float f;
  unsigned int i;
 } U;

float int2float(int i) {
    if (i == 0) 
    return 0;

    int s = 0;
    unsigned abs_i = i;

    if (i < 0) {
        s = 1;
        abs_i = -i;
    } 
    
    int E = 0;
    unsigned int temp = abs_i;
    while (temp != 1) {
        temp = temp >> 1;
        E++;
    }
    int exp = 127 + E;
    unsigned int frac = abs_i ^ (1u << E); 
    
    if (E <= 23) 
        frac = frac << (23 - E); 
    else
        frac = frac >> (E - 23); 
    
    U result;
    result.i = makefloat(s, exp, frac);
    return result.f;
}

int main(void) {
    printf("\n******** int2float ****************\n");
    int i = 0;
    printf(" %d -> %+10.4f\n", i, int2float(i));
    i = 1;  
    printf(" %d -> %+10.4f\n", i, int2float(i));
    i = -1;  
    printf(" %d -> %10.4f\n", i, int2float(i));
    i = 0x7fffffff;  
    printf(" %d -> %+10.4f\n", i, int2float(i));
    i = -i;
    printf(" %d -> %+10.4f\n", i, int2float(i));
    i = 12345;
    printf(" %d -> %+10.4f\n", i, int2float(i));
    i = -12345;
    printf(" %d -> %+10.4f\n", i, int2float(i));

    return 0;
}






