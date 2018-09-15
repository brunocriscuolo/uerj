//Exercício 9
//Somatório dos elementos de um vetor de N elementos

#include <stdio.h>
#include <stdlib.h>

int main ()
{

	int tam, *vet, i;
	float elem, soma=0;
	scanf("%d", &tam);
	if (tam<=0){
		printf("Erro: o vetor de entrada deve ter tamanho > 0!\n");}
	else{
		vet=(int*)malloc(tam*sizeof(int));
		for (i=0; i<tam; i++){
			*(vet+i)=scanf("%f",&elem);
			soma+=elem;}
		printf("%.1f\n",soma);
		free(vet);
	}

return 0;
}
