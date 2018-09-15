//Trabalho Extra
//Índice Remissivo

#include<stdio.h>
#include<stdlib.h>
#include<string.h> // a função strupr não está funcionando
#include <ctype.h> //para usar a função toupper (int ch);
#define tam 50

struct palavra{
    char palavra[tam];
    struct linha *pl;
    struct palavra *p;//aponta para o proximo
};

struct linha{
    int linha;
    struct linha *pl;
};

struct palavra* criar(char *, int );
struct palavra* buscarPalavra(struct palavra *, char *);
struct linha* criarLinha(int );
void inserir(struct palavra **, struct palavra *);
void insereLinha(struct linha **, struct linha * , int );
void imprimir(struct palavra *);
void imp(struct linha *);
void freeLista(struct palavra **);
void freeSublista(struct linha **);

int main(){
   FILE *arq;
   char nArq[tam], str[tam];
   int i=0, c, estado= 0, linha=1;
   struct palavra *pLista= NULL, *a;
	fscanf(stdin,"%s",nArq);
	arq= fopen(nArq,"r");
	
    if(!arq)    {
        fprintf(stdout,"\nErro na abertura do arquivo\n");
        return 1;
    }    else    {
		do{
	          if((c>='a' && c<='z')||(c>='A' && c<='Z')) {
                estado= 1;
               (*(str+i++))= toupper (c);
            }  else            {
                if(estado == 1)                {
                    (*(str+i))='\0';
                   // strupr(str) ; não está funcionando aqui no moodle,usar o toupper então
                i= 0;
                a= buscarPalavra(pLista,str);
                if(a== NULL){
                     inserir(&pLista,criar(str,linha));
                }else{
                     	 insereLinha(&(a->pl),criarLinha(linha),linha);
                     }
                }         
                estado= 0;
           }  if(c=='\n')
                linha++;
        }while((c=fgetc(arq))!= EOF)  ;
    }
    fclose(arq);
    imprimir(pLista);
    freeLista(&pLista);
    return 0;
}
void freeLista(struct palavra **l){
    struct palavra *a;
    if (*l==NULL){
        free(*l);
    }else{
		  freeSublista(&(*l)->pl);
        a= *l;
        *l= a->p;
        free(a);
        freeLista(&(*l));
    }           
}

void freeSublista(struct linha ** l){
    struct linha *a;
    if (*l == NULL){
        free(*l);
    }else{
        a= *l;
        *l= a->pl;
        free(a);
        freeSublista(&(*l));
        
    }       
}

struct palavra* criar(char *s, int n)  /* aloca  o tipo palavra , preenche a string, a primeira apariçao na linha */{
    struct palavra *e;
    e= (struct palavra*)malloc(sizeof(struct palavra));
    strcpy((e->palavra),s);
    e->pl= (struct linha*)malloc(sizeof(struct linha));
    (e->pl)->linha= n;
    (e->pl)->pl= NULL;
    return e;
}
struct linha* criarLinha(int n){
    struct linha *e;
    e= (struct linha*)malloc(sizeof(struct linha));
    e->linha= n;
    return e;
}

struct palavra* buscarPalavra(struct palavra *l, char *s) /* Se achar a string retorna 1 se nao acha retorna 0 */{
    if(l==NULL)
    	return NULL;
    else	
        if(strcmp(l->palavra,s)==0)
            return l;
        else
            return buscarPalavra(l->p,s);       
}

void imprimir(struct palavra *l){
    if(l!=NULL)    {
        printf("%s: %d",l->palavra,(l->pl)->linha);
        imp((l->pl)->pl);
        imprimir(l->p);
    }
}

void imp(struct linha *l){ //imprime com a formatação solicitada para a linha
    if(l==NULL)    
        printf("\n");
    else{
        printf(", %d",l->linha);
        imp(l->pl);
    }         
}

void insereLinha(struct linha **l, struct linha* e, int n){
    if(*l == NULL)    {
        e->pl= NULL;
        *l= e;
    }else    {
        if((*l)->linha==n)
            return;
        insereLinha(&((*l)->pl),e,n);
    }
}


void inserir(struct palavra **l, struct palavra *e){
    if(*l!=NULL)    {
		if (strcmp((*l)->palavra,e->palavra)==1)      {
            e->p= *l;
            *l= e;
        } else
            inserir(&((*l)->p),e);
    }
    else    {
        e->p= *l;
        *l= e;
    }
}



