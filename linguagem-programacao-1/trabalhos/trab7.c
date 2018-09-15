//Trabalho 7
//Produto de Matrizes com alocação fragmentada por linha 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 81

void FreeMat(int **matriz,int linha);

int main(){
    
	FILE *fp1,*fp2;	
	int **mA,**mB,**mC;
	int i,j,k,lA,lB,cA,cB,aux1,aux2,tam1,tam2,s=0;
	char name1[TAM],name2[TAM],c1,c2;
	
	fgets(name1,80,stdin);
	name1[strlen(name1)-1]='\0';
	fgets(name2,80,stdin);
	name2[strlen(name2)-1]='\0';

	fp1=fopen(name1,"r");
	fp2=fopen(name2,"r");
	fscanf(fp1,"%c %d %d %d %d",&c1,&aux1,&cA,&lA,&tam1);
	fscanf(fp2,"%c %d %d %d %d",&c2,&aux2,&cB,&lB,&tam2);

	if (cA!=lB){
		printf("Erro dimensoes incompativeis\n");}

	else{
		mA=(int**)malloc(lA*tam1);
		mB=(int**)malloc(lB*tam2);
		mC=(int**)malloc(lA*tam1);
		fprintf(stdout,"%d %d %d %d ",aux1,cB,lA,tam2);
		
		for(i=0;i<lA;i++){
			mA[i]=(int*)malloc(cA*tam1);
			mC[i]=(int*)malloc(cB*tam2);
			for(j=0;j<cA;j++){
				fscanf(fp1,"%d",&mA[i][j]);}	
		}
	
		for (i=0;i<lB;i++){
			mB[i]=(int*)malloc(cB*tam2);
			for(j=0;j<cB;j++){	
				fscanf(fp2,"%d",&mB[i][j]);}		
		}	
						
		for (i=0;i<lA;i++){
			for (j=0;j<cB;j++){
				int s=0;
				for (k=0;k<cA;k++){
					s+=mA[i][k]*mB[k][j];}
				mC[i][j]=s;	
				fprintf(stdout,"%d ",mC[i][j]);}
		}			
			
		fclose(fp1);
		fclose(fp2);
		
		FreeMat(mA,lA);
		free(mA);
		FreeMat(mB,lB);
		free(mB);
		FreeMat(mC,lA);
 		free(mC);	
				
	}
return 0;
}

void FreeMat(int **matriz,int linha)
{
	int i;
	
	for (i=0; i<linha; i++){
		free(matriz[i]);}
}

