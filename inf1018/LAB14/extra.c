#include <stdio.h>
#include <math.h>

#define getsig(x)        ((x)>>31 & 1)
#define getexp(x)        ((x)>>23 & 0xff)
#define getfrac(x)       ((x) & 0x7fffff)
#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))

typedef union {
  float f;
  unsigned int i;
} U; 
   
int float2int(float f) {
    //if (f == 0)
        //return 0;

    U u;
    u.f = f;
    unsigned int num = u.i;
    
    printf("%d \n", num);
    // 0100 0000 | 1010 0000 | 0000 0000 | 0000 0000 
    // 1084227584
    int E = getexp(num) - 127;
    int mask = 0x1 << E;
    int M = (getfrac(num) >> (23 - E)) | mask;
    if (getsig(num) == 1) 
        M = M * (-1);
    
    return M;
}

int main() {
   float f;

   printf("\n******** float2int ****************\n");
   f = 0.0;  
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = 1.0;  
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = -1.0;  
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = 12345.0;
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = -12345.0;
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = 1.5;
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = 2.5;
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = 2.4;
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = 0.5;
   printf(" %+10.4f -> %d\n", f, float2int(f));
   f = (float) pow(2,31);
   printf(" %+10.4f (2^31) = overflow -> %d\n", f, float2int(f));
   f = -f;
   printf(" %+10.4f (-2^31) -> %d\n", f, float2int(f));
   f = (float) pow(2,32);
   printf(" %+10.4f (-2^32 = overflow) -> %d\n", f, float2int(f));
   f = -f;

   return 0;
}