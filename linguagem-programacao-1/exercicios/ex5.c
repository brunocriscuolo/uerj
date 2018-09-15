//Exercício 5
//Removedor de Comentários

#include <stdio.h>
#include <stdbool.h>

void RemoveComentario(int);
void comentario(int);

int main()
{
	int c;

	while((c=getchar())!=EOF){
		RemoveComentario(c);}

return 0;
}


void RemoveComentario(int c1)
{
	int c2;
	bool coment=false;

		if(c1=='/'){
			if((c2=getchar())=='*'){
				coment=true;}
    		else if(c2=='/'){
				putchar(c1);
				RemoveComentario(c2);}
      	else{
				putchar(c1);
				putchar(c2);}
		}
		
		else if(c1=='\''||c1=='"'){
        	comentario(c1);}
        	
		else{
        	putchar(c1);}
	
		if(coment){
			c1=getchar();
			c2=getchar();

		while(c1!='*'||c2!='/'){
			c1=c2;
			c2=getchar();}
		}
}


void comentario(int c1)
{
	int c2;

	putchar(c1);
   while((c2=getchar())!=c1){
   	putchar(c2);
      if(c2='\\'){
			putchar(getchar());}
	}
	putchar(c2);
}
