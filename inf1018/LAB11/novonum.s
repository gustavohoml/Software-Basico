/*
int novonum(void) {
  int minhalocal;
  printf("numero: ");
  scanf("%d",&minhalocal);
  return minhalocal;
}
*/

.data
S1: .string "numero: "
S2: .string "%d"

.text
.globl novonum
novonum: 
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    movq $S1, %rdi
    call printf

    movq $S2, %rdi
    leaq -4(%rbp), %rsi
    call scanf

    movl -4(%rbp), %eax

    leave
    ret
