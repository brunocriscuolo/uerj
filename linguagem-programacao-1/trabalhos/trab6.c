//Trabalho 6 
//Soma de matrizes com alocação dinâmica

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **MatAlloc(int linha, int coluna, FILE *fp);
int **SomaMatriz(int **mat1, int **mat2, int linha, int coluna);
void PrintMat(int **matriz, int linha, int coluna);


int main()
{
	FILE *fp;
	int l,c;
	int **A,**B,**C;
	char name[81];
		
	fgets(name,80,stdin);
	name[strlen(name)-1]='\0';
	fp=fopen(name,"r");
	if(fp==NULL){
		printf("ERRO AO ABRIR O ARQUIVO!");
		return 0;}
	fscanf(fp,"%d;%d",&l,&c);
	
	A=MatAlloc(l,c,fp);
	B=MatAlloc(l,c,fp);
	C=SomaMatriz(A,B,l,c);
	
	printf("%d;%d\n",l,c);
	PrintMat(C,l,c);

	fclose(fp);

	free(A);
	free(B);
	free(C);
	
return 0;
}


int **MatAlloc(int linha, int coluna, FILE *fp)
{
	int **matriz;
	int i,j;

	matriz=(int**)malloc(linha*sizeof(int*));
 	for(i=0;i<linha;i++){
		matriz[i]=(int*)malloc(coluna*sizeof(int));
		for(j=0;j<coluna;j++){
			fscanf(fp,"%i",&matriz[i][j]);}
	}
return matriz;
}


int **SomaMatriz(int **mat1, int **mat2, int linha, int coluna)
{
	int **mat3;
	int i,j;

	mat3=(int**)malloc(linha*sizeof(int*));
	for (i=0;i<linha;i++){
		mat3[i]=(int*)malloc(coluna*sizeof(int));
		for (j=0;j<coluna;j++){
			mat3[i][j]=mat1[i][j]+mat2[i][j];}
	}
return mat3;
}


void PrintMat(int **matriz, int linha, int coluna)
{
	int i,j;
	for(i=0;i<linha;i++){
		for(j=0;j<coluna;j++){
			fprintf(stdout,"%i",matriz[i][j]);
			if(j!=coluna-1){
				putchar(' ');}
		}
		putchar('\n');
	}
}
