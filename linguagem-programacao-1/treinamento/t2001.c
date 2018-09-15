//Treinamento 2.001 
//Divisor 3 e 6

#include <stdio.h>

int main()
{
	int n;
		scanf("%d", &n);
		if (n<0)
		{
			printf("\nO NUMERO DEVE SER MAIOR OU IGUAL A ZERO\n");
		}
		else
		{
			if (n%3==0 && n%6==0)
			{
				printf("\nSIM\n");
			}
			else
			{
				printf("NAO\n");
			}
		}
	return 0;
}
