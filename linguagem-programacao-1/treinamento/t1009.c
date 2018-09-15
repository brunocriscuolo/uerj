//Treinamento 1.009
//Hipotenusa

#include <stdio.h>
#include <math.h>

int main()

{
	double a,b,c;
  
		printf("Digite a medida de um cateto:\n");
		scanf("%lf", &a);
		printf("Digite a medida de outro cateto:\n");
		scanf("%lf", &b);

		if ((a<0) || (b<0))
		{
			printf("\nNENHUM CATETO PODE SER NEGATIVO\n");	
		}
			
		else
		{
			c=sqrt(pow(a,2)+pow(b,2));
					    
			printf("\nMedida da Hipotenusa: %.2lf", c);
		}
      
	return 0;
}
