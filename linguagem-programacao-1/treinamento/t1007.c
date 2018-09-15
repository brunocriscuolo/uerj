//Treinamento 1.007
//Propriedades de um círculo

#include <stdio.h>
#include <math.h>

#define pi 3.14159265358979
   
int main()

{
	double r,p,a;
  
		printf("Digite uma medida de raio:\n");
		scanf("%lf", &r);

		if (r<0)
		{
			printf("\nO RAIO NAO PODE SER NEGATIVO\n");
		}
			
		else
		{
			p=2*pi*r;
			a=pi*pow(r,2);
					    
			printf("\nPerímetro: %.2lf", p);
			printf("\nÁrea: %.2lf", a);
		}
      
	return 0;
}
