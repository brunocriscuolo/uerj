//Treinamento 1.012
//Salários mínimos

#include <stdio.h>

int main()

{
	float m,s,qtd;
  
		printf("Digite o valor do Salário Mínimo:\n");
		scanf("%f", &m);
		printf("Digite o Valor do Salário Recebido:\n");
		scanf("%f", &s);
		
		if (m<=0)
		{
			printf("\nO SALARIO MINIMO DEVE SER MAIOR QUE ZERO\n");	
		}
			
		else
		{
			if (s<m)
			{
				printf("\nO SALARIO DO FUNCIONARIO NAO PODE SER MENOR QUE O MINIMO\n");
			}

			else
			{
				qtd=(float)s/m;
				printf("\nO funcionário recebe %.2f salário(s) mínimo(s)\n", qtd);				    
			}
		}
      
	return 0;
}
