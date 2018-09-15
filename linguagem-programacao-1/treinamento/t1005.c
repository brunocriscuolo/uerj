//Treinamento 1.005
//Propriedades de um retângulo

#include <stdio.h>
#include <math.h>
   
int main()
{
	double b,h,p,a,d;
  
      printf("Digite um valor de Base:\n");
      scanf("%lf", &b);
      printf("Digite um valor de Altura:\n");
      scanf("%lf", &h);
		if (b<0 || h<0)
		{
			if (b<0)
			{
				printf("\nA BASE NAO PODE SER NEGATIVA\n");
			}
			if (h<0)
			{
				printf("\nA ALTURA NAO PODE SER NEGATIVA");
			}
		}
		else
		{
		    p=2*(b+h);
		    a=b*h;
		    d=sqrt(pow(b,2)+pow(h,2));
		    
			printf("\nPerímetro: %.2lf", p);
			printf("\nÁrea: %.2lf", a);
			printf("\nDiagonal: %.2lf\n", d);
		}      
       	return 0;
}
    
