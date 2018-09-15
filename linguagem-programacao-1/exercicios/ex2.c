//Exercício 2
//Tabela de temperatura Célsius - Fahrenheit usando for


#include <stdio.h>

float cels2fahr (int);

int main()
{
	int cels;
	for (cels = -10; cels <= 50; cels = cels+10)
		printf("%d %f\n", cels, cels2fahr(cels));
	return 0;
}

float cels2fahr (int cels)
{
 return (((9.0/5)*cels)+32);
}
