/*
float foo (double a, float b) {
    return (a+b)*(a-b);
}
*/

.globl foo
foo: 
    cvtss2sd %xmm1, %xmm1
    movsd %xmm0, %xmm2
    addsd %xmm1, %xmm2
    subsd %xmm1, %xmm0
    mulsd %xmm2, %xmm0
    
    cvtsd2ss %xmm0, %xmm0
    ret
