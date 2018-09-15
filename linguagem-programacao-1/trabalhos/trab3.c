//Trabalho 3
//Conversão de string hexadecimal para string binária

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	
	int i;
	char hex[9], bin[33];
	char num0[]="0000"; 
	char num1[]="0001"; 
	char num2[]="0010";
 	char num3[]="0011";
	char num4[]="0100";
	char num5[]="0101";
	char num6[]="0110";
	char num7[]="0111";
	char num8[]="1000";
	char num9[]="1001";
	char A[]="1010";
	char B[]="1011";
	char C[]="1100"; 
	char D[]="1101";
	char E[]="1110";
	char F[]="1111";

	for (i=0; i<=8; i++){
		hex[i]=getchar();}
	hex[i++]='\0';

	for (i=0; i<=33; i++){
		bin[i++]='\0';}

	for (i=0; i<=8; i++){

		if(isalpha(hex[i])){
			hex[i]=toupper(hex[i]);}

		if(hex[i]=='A'){
			strcat(bin, A);}

		if(hex[i]=='B'){
			strcat(bin, B);}

		if(hex[i]=='C'){
			strcat(bin, C);}

		if(hex[i]=='D'){
			strcat(bin, D);}

		if(hex[i]=='E'){
			strcat(bin, E);}

		if(hex[i]=='F'){
			strcat(bin, F);}

		if(hex[i]=='0'){
			strcat(bin, num0);}

		if(hex[i]=='1'){
			strcat(bin, num1);}

		if(hex[i]=='2'){
			strcat(bin, num2);}

		if(hex[i]=='3'){
			strcat(bin, num3);}

		if(hex[i]=='4'){
			strcat(bin, num4);}

		if(hex[i]=='5'){
			strcat(bin, num5);}

		if(hex[i]=='6'){
			strcat(bin, num6);}

		if(hex[i]=='7'){
			strcat(bin, num7);}

		if(hex[i]=='8'){
			strcat(bin, num8);}

		if(hex[i]=='9'){
			strcat(bin, num9);}
	}

	printf("%s\n", bin);

return 0;
}
