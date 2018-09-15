//Trabalho 5
//Algoritmo Recursivo que imprime conteúdo de arquivo de trás para frente

#include <stdio.h>
#include <string.h>

void le_arq(char [], char []);
void inverteRec(char v[], int i);

int main()
{
	char nome[81];
	char vet[800];

	fgets(nome, 80, stdin);
	nome[strlen(nome)-1]='\0';
	le_arq(vet,nome);
	inverteRec(vet, 0);
}

void le_arq(char v[], char nome[])
{
	FILE * fp = fopen(nome, "r");
	int i=0;
	char c;

	while ((c=fgetc(fp))!=EOF){
		v[i]=c;
		i++;}
	v[i]='\0';
	fclose(fp);
}

void inverteRec(char v[], int i)
{
	if (v[i]!='\0'){
		inverteRec(v, i+1);
		printf("%c", v[i]);}
}

