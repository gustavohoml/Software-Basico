/*
void boo (struct X *px, int n, int val) 
  while (n--) 
    px->val2 = f(px->val1, val);
    px++;
*/

.text
.globl boo
boo:
    pushq %rbp
    movq %rsp, %rbp
    subq $32, %rsp 
    pushq %rbx 
    pushq %r12
    pushq %r13
    
    /*  boo(rdi, esi, edx)  */
    movq %rdi, %rbx
    movl %esi, %r12d
    movl %edx, %r13d
    /*  boo(rbx, r12d, r13d)  */

loop:
    cmpl $0, %r12d
    je fora
    
    movl (%rbx), %edi
    movl %r13d, %esi
    call f

    movl %eax, 4(%rbx) 
    
    addq $8, %rbx
    subl $1, %r12d
    jmp loop

fora:
    popq %r13
    popq %r12
    popq %rbx
    leave
    ret
