//Treinamento 1.004
//Cálculo de Juros 2

#include <stdio.h>
#include<math.h>

int main()
{
	double d,e,j;
	int m;
	
		printf("\nValor do Empréstimo:\n");
		scanf("%lf", &e);
		printf("\nTaxa Percentual de juros:\n");
		scanf("%lf", &j);
		printf("\nQuantidade de Meses:\n");
		scanf("%d", &m);

		if (e<0)
		{
			printf("\nO VALOR DO EMPRESTIMO NAO PODE SER NEGATIVO\n");
		}
			
		else
		{
			if (j<0)
			{
				printf("\nA TAXA DE JUROS NAO PODE SER NEGATIVA\n");
			}
			
			else
			{
				if(m<0)
				{
					printf("\nA QUANTIDADE DE MESES NAO PODE SER NEGATIVA\n");
				}
				
				else
				{
					d=e*pow(1+(j/100),m);
			
					printf("Valor da Dívida: %.2lf", d);
				}
			}
			
		}

	return 0;
}
