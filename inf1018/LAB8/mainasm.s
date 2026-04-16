.data
nums: .int 3, -5, 7, 8, -2
s1:   .string "%d\n"

.text
.globl main
main:
/* prologo */
    pushq %rbp
    movq  %rsp, %rbp
    subq  $16, %rsp
    movq  %rbx, -8(%rbp)
    movq  %r12, -16(%rbp)
  
/* coloque seu codigo aqui */
    movq $0, %rbx       /* int i = 0 */
    movq $nums, %r12    /* int* p = &nums */

loop:
    cmp $5, %rbx
    je fora

    movl    (%r12), %edi    /* primeiro parametro (inteiro)*/
    movl    $1, %esi   /* segundo parametro  (inteiro) */
    call filtro

    movq    $s1, %rdi    /* primeiro parametro (ponteiro)*/
    movl    %eax, %esi   /* segundo parametro  (inteiro) */
    movl  $0, %eax
    call  printf       /* chama a funcao da biblioteca */

    addq $1, %rbx
    addq $4, %r12
    jmp loop

fora:
  
/* finalizacao */
    movq -8(%rbp), %rbx
    movq -16(%rbp), %r12
    leave
    ret
