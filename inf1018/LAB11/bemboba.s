/*
int bemboba (int num) {
  int local[qt];
  int *a;
  int i;

  for (i=0,a=local;i<qt;i++) {
    *a = num;
    a++;
  }
  return addl (local, qt);
}
*/

.data
qt: .int 4

.text
.globl bemboba
bemboba:    
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp
    leaq -16(%rbp), %r9
    /*  -16(%rbp) = local    */

    movl $0, %ecx  /* i = 0 */

loop:
    cmpl qt, %ecx
    jge fora

    movl %edi, (%r9)

    addq $4, %r9
    addl $1, %ecx
    jmp loop

fora:
    leaq -16(%rbp), %rdi
    movl qt, %esi
    call addl
    leave
    ret
