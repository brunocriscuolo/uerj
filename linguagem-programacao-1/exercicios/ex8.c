//Exercício 8
//Passagem de parâmetros por referência

#include <stdio.h>

void maxmin(float *max, float *min);
void swap(float **a, float **b);

int main(){

float a, b;


scanf("%f", &a);
scanf("%f", &b); 

maxmin(&a, &b); 
printf("%f\n%f\n", a, b); 

}


void swap(float **a, float **b){
	float aux;
	aux=**a; 
	**a=**b;
	**b=aux;
}

void maxmin(float *max, float *min){
        if(*max < *min){
                swap(&max, &min); 
        }
}
    

