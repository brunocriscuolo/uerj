//Exercício 6
//Discrepância em dois arquivos

#include <stdio.h> 
#include <string.h>

int main()
{

	FILE *fp1,*fp2;     
	char arq1[81],arq2[81],c1,c2;
	int lin=1,col=1;  
        
	fgets(arq1,80,stdin);
	arq1[strlen(arq1)-1]='\0';
	fgets(arq2,80,stdin);
	arq2[strlen(arq2)-1]='\0';

	fp1=fopen(arq1,"r");
	fp2=fopen(arq2,"r"); 
	
	while((c1=fgetc(fp1))&&(c2=fgetc(fp2))&&(c1!=EOF)&&(c2!=EOF)&&(c1==c2)){
		if(c1=='\n'){
			lin+=1;
			col=0;}
		col+=1; 
	}
 
 	if(c1==c2){
		printf("Os arquivos %s e %s são idênticos.\n", arq1, arq2);}
 	else{
		printf("Discrepância: Linha %d, Coluna %d.\n", lin, col);}

	fclose(fp1);
	fclose(fp2);

return 0;
}
	
