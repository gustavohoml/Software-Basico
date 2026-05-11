/*
int boo(int lim, int *v, int n) {
    int i, soma = 0;
    for(i=0; i<n; i++) {
        if (valida(v[i], lim))
            soma += v[i];
    }
    return soma;
}
*/

.text
.globl boo
boo:
    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp
    movq %r12, -8(%rbp)
    movl %ebx, -12(%rbp)
    movl %r13d, -16(%rbp)    
    movl %r14d, -20(%rbp)    
    movl %r15d, -24(%rbp)    

    movl %edi, %r13d
    movq %rsi, %r12
    movl %edx, %ebx

    movl $0, %r14d
    movl $0, %r15d

loop:
    cmpl %r15d, %ebx
    je fora 

    movl (%r12), %edi
    movl %r13d, %esi
    call valida

    cmpl $1, %eax
    jne else

    addl (%r12), %r14d

else:
    addl $1, %r15d
    addq $4, %r12
    jmp loop

fora: 
    movl %r14d, %eax
    leave
    ret

