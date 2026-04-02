/*
int nums[4] = {65, -105, 111, 34};
int main (void) {
  int i;
  int s = 0;
  for (i=0;i<4;i++)
    s = s+nums[i];
  printf ("soma = %d\n", s);
  return 0;
}
*/

.data
nums: .int  65, -105, 111, 34
Sf:  .string "soma = %d "    /* primeira string de formato para printf */
Sf2: .string "\n"    /* segunda string de formato para printf */

.text
.globl  main
main:

/********************************************************/
/* mantenha este trecho aqui e nao mexa - prologo !!!   */
  pushq   %rbp
  movq    %rsp, %rbp
  subq    $16, %rsp
  movq    %rbx, -8(%rbp)  /* guarda rbx */
  movq    %r12, -16(%rbp)  /* guarda r12 */
/********************************************************/

  movq  $nums, %r12 
  movl  $0, %ebx
  movl  $0, %eax

L1:
  cmpl  $4, %ebx  /* if (ebx == 4) ? */
  je  L2          /* goto L2 */


  addl (%r12), %eax


  addq  $4, %r12  /* r12 += 1; */
  addl  $1, %ebx
  jmp  L1         /* goto L1; */

L2:


/*************************************************************/
/* este trecho imprime o valor de %eax (estraga %eax)  */
  movq    $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl    %eax, %esi   /* segundo parametro  (inteiro) */
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/


/*************************************************************/
/* este trecho imprime o \n (estraga %eax)                  */
  movq    $Sf2, %rdi    /* primeiro parametro (ponteiro)*/
  movl  $0, %eax
  call  printf       /* chama a funcao da biblioteca */
/*************************************************************/

/***************************************************************/
/* mantenha este trecho aqui e nao mexa - finalizacao!!!!      */
  movq  $0, %rax  /* rax = 0  (valor de retorno) */
  movq    -16(%rbp), %r12 /* recupera r12 */
  movq    -8(%rbp), %rbx  /* recupera rbx */
  leave
  ret      
/***************************************************************/
