/*
int add (struct X *x) 
  int a = 0;
  for (; x != NULL; x = x->next)
    a += x->val;
  return a;
*/

.text
.globl add
add:
    /* PROLOGO */
    pushq %rbp
    movq %rsp, %rbp

    movl $0, %eax

loop:
    cmpq $0, %rdi
    je fora

    addl (%rdi), %eax
    movq 8(%rdi), %rdi

    jmp loop

fora:
    leave
    ret
    