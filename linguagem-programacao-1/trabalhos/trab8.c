//Trabalho 8
//Crivo de Eratóstenes

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int i, j, tam, aux;
	scanf("%d", &tam);
	int *vet=(int*)malloc((tam)*sizeof(int));

    for (i=2; i<=tam; i++){
        *(vet+i)=1;}
 
    for (i=2; i<=tam; i++){
        if (*(vet+i)==1){
            for (j=i; (j*i)<=tam; j++){
                aux=j*i;
                *(vet+aux)=0;}
	    }
	}
 
    for (i=2; i<tam; i++){
        if (*(vet+i)==1){
            printf(" %d", i);}
    }

return 0;
}

