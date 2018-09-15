//Treinamento 2.002
//Idade

#include <stdio.h>

int main()
{
	int id;
		scanf("%d", &id);
		if (id<0)
		{
			printf("\nA IDADE DEVE SER MAIOR OU IGUAL A ZERO\n");
		}
		else
		{
			if (id>=10 && id<=18)
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
