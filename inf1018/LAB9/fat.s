/*
int fat (int n) 
  if (n==0) return 1;
  else return n*fat(n-1);
*/

.text
.globl fat
fat:
    pushq %rbp             
    movq  %rsp, %rbp      
    subq  $16, %rsp      

    cmp $0, %edi     
    jne recursao

    movl $1, %eax
    jmp final

recursao:
    movl %edi, -4(%rbp)

    subl $1, %edi
    call fat

    imull -4(%rbp), %eax

final:
    leave 
    ret
    