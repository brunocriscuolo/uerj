//Treinamento 1.010
//PA

#include <stdio.h>

int main()

{
	int r,p,n,t;
  
		//printf("Digite o Valor da Razão:\n");
		scanf("%d", &r);
		//printf("Digite o valor do Primeiro Termo:\n");
		scanf("%d", &p);
		//printf("Digite a Quantidade de Termos:\n");
		scanf("%d", &n);

		if (n<=0)
		{
			printf("\nA QUANTIDADE DE TERMOS DEVE SER MAIOR QUE ZERO\n");	
		}
			
		else
		{
			t=p+(n-1)*r;
								    
			printf("%d\n", t);
		}
      
	return 0;
}
