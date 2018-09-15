//Treinamento 1.008
//Propriedades de um paralelepípedo

#include <stdio.h>
#include <math.h>

int main()

{
	double l1,l2,l3,a,v,d;
  
		//printf("Digite a medida de L1:\n");
		scanf("%lf", &l1);
		//printf("Digite a medida de L2:\n");
		scanf("%lf", &l2);
		//printf("Digite a medida de L3:\n");
		scanf("%lf",&l3);

		if ((l1<0) || (l2<0) || (l3<0))
		{
			printf("\nNENHUM LADO PODE SER NEGATIVO\n");	
		}
			
		else
		{
			a=2*((l1*l2)+(l1*l3)+(l2*l3));
			v=l1*l2*l3;
			d=sqrt(pow(l1,2)+pow(l2,2)+pow(l3,2));
					    
			printf("\nÁrea Total das Faces: %.2lf", a);
			printf("\nVolume: %.2lf", v);
			printf("\nDiagonal: %.2lf", d);
		}
      
	return 0;
}
