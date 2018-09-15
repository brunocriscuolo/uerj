//Exercício 3
//Contador de espaços, caracteres de tabulação e linhas 


#include <stdio.h>

int main(){

int sp=0,tb=0,ln=0;
char c;

while ((c=getchar())!=EOF){
	if(c==' '){
		sp++;}
	else if(c=='\t'){
		tb++;}
	else if(c=='\n'){
		ln++;}
}

printf("%d\n %d\n %d\n",sp,tb,ln);

return 0;
}
