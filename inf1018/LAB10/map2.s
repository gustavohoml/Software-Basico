/*
int f(int x);

void map2 (int* um, int * outro, int n) {
  int i;
  for (i=0; i<n; i++)
    *(outro+i) = f(*(um+i));
}
*/

.text
.globl map2
map2:
    pushq %rbp
    movq %rsp, %rbp

    subq $32, %rsp
    movq %r12, -8(%rbp)
    movq %rbx, -16(%rbp)
    movl %r14d, -20(%rbp)
    movl %r13d, -24(%rbp)
    
    /* map2(rdi, rsi, edx) */
    /* f(edi)              */

    movq %rdi, %rbx
    movq %rsi, %r12
    movl %edx, %r13d

    movl $0, %r14d

loop:
    cmpl %r14d, %r13d
    jle fora 

    movl (%rbx), %edi
    call f
 
    movl %eax, (%r12)

    addq $4, %rbx
    addq $4, %r12
    addl $1, %r14d
    jmp loop
    
fora:
    leave
    ret 
