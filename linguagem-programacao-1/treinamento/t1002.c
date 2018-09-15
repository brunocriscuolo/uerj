//Treinamento 1.002
//Dividendo, divisor, quociente e resto

#include <stdio.h>
   
int main()
{
	int x,y;
  
		printf("Digite um número:\n");
		scanf("%d", &x);
		printf("Digite um número:\n");
		scanf("%d", &y);
		printf("\nDividendo: %d", x);
		printf("\nDivisor: %d", y);
		printf("\nQuociente: %d", x/y);
		printf("\nResto: %d\n", x%y);
       
   return 0;
}
    
