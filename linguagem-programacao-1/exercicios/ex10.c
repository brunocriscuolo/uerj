//Exercício 10
//Palíndromo

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
	
	char work[50];
	int inicio=0, fim, tam; 
	bool palindromo=true;

	fgets(work, 50, stdin);
	tam = strlen(work)-1;

	work[tam] = '\0';
	fim=tam-1;
	
	while ((inicio<=fim)&&palindromo) 
	{
		if (work[inicio]!=work[fim]) {
			palindromo=false;
			break;}
		else {
			inicio++;
			fim--;}
	}

	if (palindromo){
		printf("SIM\n");}
	else{
		printf("NAO\n");}

return 0;
}
