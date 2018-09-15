//Exercício 4
//Histograma

#include <stdio.h>
#include <ctype.h>

float Percentual(int numero, int total);

int main(){

	int n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0,total=0,outros=0;
	char c;

	while((c=getchar())!=EOF){
		total=total+1; 
		if (isdigit(c)){
			if(c=='0'){
				n0=n0+1;}
			if(c=='1'){
				n1=n1+1;}
			if(c=='2'){
				n2=n2+1;}
			if(c=='3'){
				n3=n3+1;}
			if(c=='4'){
				n4=n4+1;}
			if(c=='5'){
				n5=n5+1;}
			if(c=='6'){
				n6=n6+1;}
			if(c=='7'){
				n7=n7+1;}
			if(c=='8'){
				n8=n8+1;}
			if(c=='9'){
				n9=n9+1;}
		}
		else
		{
			outros=outros+1;
		}
	}
	
	printf("0 - %.2f%%\n1 - %.2f%%\n2 - %.2f%%\n3 - %.2f%%\n4 - %.2f%%\n5 - %.2f%%\n6 - %.2f%%\n7 - %.2f%%\n8 - %.2f%%\n9 - %.2f%%\noutros - %.2f%%", Percentual(n0,total), Percentual(n1,total), Percentual(n2,total), Percentual(n3,total), Percentual(n4,total), Percentual(n5,total), Percentual(n6,total), Percentual(n7,total), Percentual(n8,total), Percentual(n9,total), Percentual(outros,total)); 

}

float Percentual(int numero, int total)
{
	float percentual;
	
	percentual=(float)(numero*100)/total;
	return percentual;
}

