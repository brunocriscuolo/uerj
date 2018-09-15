//Treinamento 1.003
//Cálculo de juros

#include <stdio.h>
#include<math.h>

int main()
{
	double d,e;
	
		printf("\nValor do Empréstimo:\n");
		scanf("%lf", &e);

		if (e<0)
		{
			printf("\nO VALOR DO EMPRESTIMO NAO PODE SER NEGATIVO\n");
		}
			
		else
		{
			d=e*pow(1.05,6);
			
			printf("Valor da Dívida: %.2lf\n", d);
		}

	return 0;
}
