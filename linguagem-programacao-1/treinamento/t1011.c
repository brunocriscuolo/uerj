//Treinamento 1.011
//PG

#include <stdio.h>
#include <math.h>

int main()

{
	int r,p,n,t;
  
		//printf("Digite o valor da Razão:\n");
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
			t=p*pow(r,(n-1));
								    
			printf("%d\n", t);
		}
      
	return 0;
}
