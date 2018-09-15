//Trabalho 2
//Formatação em 80 colunas

#include <stdio.h>
#include <stdbool.h>

#define LINHA 81

void termina_string(char[], int);

int main(){

	int caractere,palavra,cont=0,i=0;
	char word[LINHA];


	palavra=false;
	
	caractere=getchar();
	while (caractere!=EOF){

		if (caractere!=' ' && caractere!='\n' && caractere!='\t'){
			palavra=true;}

		if (palavra){
			if (caractere==' ' || caractere=='\n' || caractere=='\t'){
				palavra=false;
				word[i]='\0';
				
				if (i<(LINHA-cont)){
					printf("%s",word);
					cont=cont+i;}
				else{
					printf("\n%s",word);
					cont=i;}

				if(cont>=LINHA-1){
					putchar('\n');
					putchar(caractere);
					cont=1;}

				else{
					putchar(caractere);
					cont=cont+1;}

				i=0;
				termina_string(word,LINHA);
			}

			else{
				word[i]=caractere;
				++i;
				if(i>LINHA){
					printf("ERRO!");
					i=0;}
			}
		}


		else{
			if (caractere=='\n'){
				cont=0;
				putchar(caractere);}
				
			else{
				putchar(caractere);
				cont++;}
		}

	caractere=getchar();
	}

return 0;
}


void termina_string(char string[], int tam){
	int i;

	for (i=0;i<=tam;++i){
		string[i]='\0';}
}
