//Treinamento 1.006
//Propriedades de um quadrado

#include <stdio.h>
#include <math.h>
   
int main()
{
	double l,p,a,d;
  
		printf("Digite uma medida de lado:\n");
		scanf("%lf", &l);

		if (l<0)
		{
			printf("\nO LADO NAO PODE SER NEGATIVO\n");
		}
			
		else
		{
			p=4*l;
			a=pow(l,2);
			d=sqrt(2)*l;
		    
			printf("\nPerímetro: %.2lf", p);
			printf("\nÁrea: %.2lf", a);
			printf("\nDiagonal: %.2lf\n", d);
		}
      
	return 0;
}
