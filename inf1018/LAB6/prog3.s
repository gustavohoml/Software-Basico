/*
int nums[] = {10, -21, -30, 45};
int main() {
    int i = 0; 
    int *p = nums;
    int resto = 0;
    while (i != 4) {
        resto = (*p << 31) >> 31;
        if (resto == 0)
            printf("%d\n", *p);
        i += 1;
        p += 1; 
    }
    return 0;
}
*/

.data
nums:  .int  10, -21, -30, 45
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
  movq  $nums, %r12  /* r12d = &nums */


L1:
  cmpl  $4, %ebx  /* if (ebx == 4) ? */
  je  L2          /* goto L2 */

  movl (%r12), %eax         
  movl %eax, %ecx       
/*****************************************************************************************/
  shl  $31, %ecx                                                
  shr  $31, %ecx                                            
  cmpl $0, %ecx
  jne Continue

  movq  $Sf, %rdi    /* primeiro parametro (ponteiro)*/
  movl  %eax, %esi   /* segundo parametro  (inteiro) */
  movb  $0, %al  
  call  printf       /* chama a funcao da biblioteca */

Continue:
/*****************************************************************************************/
  
  
  addl  $1, %ebx  /* ebx += 1; */
  addq  $4, %r12  /* r12d += 4; */
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



