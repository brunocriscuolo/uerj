//Trabalho 1
//Conversão de binário para decimal sem sinal

#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	
	char num;
	char bin[200];
	long long int i=0, tam, j, dec=0, exp=0;

	do{
		num=getchar();
		bin[i]=num;
		++i;
	}while (num!='\n');
	bin[i++]='\0';
	tam=strlen(bin)-2;
	for (j=tam; j>=0; j--){
		if (bin[j]=='1'){
			dec=dec+pow(2,exp);
		}
		exp++;
	}
	printf("%lld\n", dec);

return 0;
}
