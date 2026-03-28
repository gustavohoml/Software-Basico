.data
nums:  .byte  10, -21, -30, 45
Sf:  .string "%d "    # string de formato para printf
Sff:  .string "\n"    

.text
.globl  main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)
  movq    %r12, -16(%rbp)
/********************************************************/

  movl  $0, %ebx  /* ebx = 0; */
  movq  $nums, %r12  /* r12 = &nums */

L1:
  cmpl  $4, %ebx  /* if (ebx == 4) ? */
  je  L2          /* goto L2 */

  movsbl  (%r12), %esi   

/*************************************************************/
/* este trecho imprime o valor de %r10b (estraga %r10b)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movb  $0, %al
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/

  addl  $1, %ebx  /* ebx += 1; */
  addq  $1, %r12  /* r12 += 4; */
  jmp  L1         /* goto L1; */

L2:  
  movq    $Sff, %rdi
  call    printf 

/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq  -8(%rbp), %rbx
  movq  -16(%rbp), %r12
  leave
  ret      
/***************************************************************/
