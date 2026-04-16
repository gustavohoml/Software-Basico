/*
int add2 (struct X *x) 
  if (x == NULL) return 0;
  else return x->val + add2(x->next);
*/

.text
.globl add
add:
    /*  PROLOGO  */
    pushq %rbp
    movq %rsp, %rbp
    pushq %rbx

    cmpq $0, %rdi
    jne recursao
    movl $0, %eax
    jmp fim

recursao:
    movl (%rdi), %ebx
    movq 8(%rdi), %rdi
    call add

    addl %ebx, %eax
    
fim:
    popq %rbx
    leave 
    ret
