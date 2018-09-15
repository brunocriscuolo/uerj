//Treinamento 2.004
//Pódio

#include <stdio.h>

int main()
{
	int p1, p2, p3;
		scanf("%d", &p1);
		scanf("%d", &p2);
		scanf("%d", &p3);
		if (p1<=0 || p2<=0 || p3<=0)
		{
			printf("\nAS PONTUACOES DEVEM SER MAIORES QUE ZERO\n");
		}
		else
		{ 
			if(p1==p2 || p2==p3 || p1==p3)
			{
				printf("AS PONTUACOES DEVEM SER DIFERENTES\n");
			}
			else
			{
				if(p1>p2 && p2>p3)
				{
					printf("1o lugar - Camila \n2o lugar - Leandro \n3o lugar - Rodrigo");
				}
				else
				{
					if(p2>p3 && p3>p1)
					{
						printf("1o lugar - Leandro \n2o lugar - Rodrigo \n3o lugar - Camila");
					}
					else
					{
						if(p3>p1 && p1>p2)
						{
							printf("1o lugar - Rodrigo \n2o lugar - Camila \n3o lugar - Leandro");
						}
					}
				}
			}
		}
	return 0;
}
