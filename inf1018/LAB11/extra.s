/*
int foo (int a[], int tam) 
  int i;
  int b[tam];
  for (i = 0; i<tam; i++)
    b[i] = calcula (&(a[i]), tam-i);
  return calcula (b, tam);
*/

.text
.globl foo
foo:
    pushq %rbp
    movq %rsp, %rbp
    subq $8, %rsp
    movl %ebx, -4(%rbp)

    movl $0, %ebx /* int i = 0 */
    movl %esi, %r15d
    movq %rdi, %r13  
    movl %r15d, %r14d  /* tam */

    imul $4, %r15d, %edi 
    call malloc
    movq %rax, %r12  /* int b[tam] */

loop:
    cmpl %ebx, %r15d
    je fora

    leaq (%r13), %rdi
    movl %r14d, %esi
    call calcula
    movl %eax, (%r12)

    addq $4, %r12
    addq $4, %r13
    addl $1, %ebx
    subl $1, %r14d

fora:
    call calcula
    leave
    ret 
