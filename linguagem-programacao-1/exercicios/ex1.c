//Exercício 1
//Tabela de temperatura Célsius - Fahrenheit usando while

#include <stdio.h>

float cels2fahr (int);

int main()
{
	int cels;

	cels=-10;
	while (cels<=50){
		printf("%d %f\n", cels, cels2fahr(cels));
		cels=cels+10;
	}

	return 0;
}

float cels2fahr (int cels)
{
 return (((9.0/5)*cels)+32);
}
