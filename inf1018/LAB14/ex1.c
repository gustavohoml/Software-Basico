#include <stdio.h>
#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)
#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))

typedef union { 
  float f;
  unsigned int i;
 } U;

float float2(float f) {
    unsigned int u1;
    float f1 = f;
    U u;
    u.f = f1;  /* armazena o float na union */
    u1 = u.i;  /* obtem a representação "manipulavel" do float */
    unsigned int sig = getsig(u1);
    unsigned int exp = getexp(u1);
    unsigned int frac = getfrac(u1);
    exp = exp + 1;
    u.i = makefloat(sig, exp, frac);
    return u.f;  /* obtem o float correspondente a essa representação */
}

int main(void) {
    float f = 1.2F;
    printf("%.1f -> %.1f", f, float2(f));  

    return 0;
}