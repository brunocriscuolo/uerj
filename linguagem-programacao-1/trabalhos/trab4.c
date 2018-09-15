//Trabalho 4
//Projeto top-down

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 10
#define t 100

void leitura_arquivo_funcionarios();
void leitura_arquivo_mes();
void imprime_lista_funcionarios();
void imprime_lista_mes();
void imprime_folha_pagamento();
void imprime_folha_pagamento_arquivo();
typedef struct {
    char nFunc[t];/*nome funcionario*/
    char codFunc[t]; /*codigo funcionario*/
    char endFunc[t];/*endereço funcionario*/
    char cpfFunc[t]; /*cpf funcionario*/
    char codBanco[t]; /*codigo do banco*/
    char codAgencia[t]; /*codigo agencia*/
    char CCFunc[t];/*conta corrente*/
    float vHora;/*valor da hora trabalhada*/
} RegFunc;
typedef struct{
    char codFunc[t];
    int horas;
} RegMes;
void main() {
    RegFunc func[tam];
    RegMes mes[tam];
    leitura_arquivo_funcionarios(func);
    leitura_arquivo_mes(mes);
    int op;
    printf("\n_________________________________TRABALHO 04_________________________________ \n \n");
    printf("1 - Imprimir Lista Funcion%crios \n",160);
    printf("2 - Imprimir Lista M%cs \n",136);
    printf("3 - Imprimir Folha de Pagamento \n");
    printf("4 - Imprimir Folha de Pagamento arquivo \n\n");
    printf("Digite a op%cao desejada: ",128);
    scanf("%d",&op);
    printf("_____________________________________________________________________________\n");
    switch (op){
        case 1: imprime_lista_funcionarios(func); break;
        case 2: imprime_lista_mes(mes); break;
        case 3: imprime_folha_pagamento(func,mes); break;
        case 4: imprime_folha_pagamento_arquivo(func,mes); break;
    }
    system("pause");
}
void leitura_arquivo_mes(RegMes mes[tam]){
    char linha[t];
    int a=0;
    FILE *arqMes = fopen("maio.txt","r");
    if (arqMes==NULL){
        printf("imposs%cvel abrir o arquivo requisitado! ",161);
    }else {
        while (!feof(arqMes)){
            fgets(mes[a].codFunc,t,arqMes);
            fgets(linha, t, arqMes);
            mes[a].horas=atoll(linha);
            a++;
        }
    }
    fclose(arqMes);
}
void leitura_arquivo_funcionarios(RegFunc func[tam]){
    int b=0;
    char linha[t];
    FILE *arqFunc = fopen("funcionarios.txt", "r");
    if (arqFunc==NULL){
        printf("imposs%cvel abrir o arquivo requisitado! ",161);
    }else {
        while (!feof(arqFunc)){
            fgets(func[b].nFunc,t,arqFunc);
            fgets(func[b].codFunc,t,arqFunc);
            fgets(func[b].endFunc,t,arqFunc);
            fgets(func[b].cpfFunc,t,arqFunc);
            fgets(func[b].codBanco,t,arqFunc);
            fgets(func[b].codAgencia,t,arqFunc);
            fgets(func[b].CCFunc,t,arqFunc);
            fgets(linha,t,arqFunc);
            func[b].vHora = atof(linha);
            b++;
        }
    }
    fclose(arqFunc);
}
void imprime_lista_funcionarios(RegFunc func[tam]){
    int b;
    printf("---------------------------Dados do Funcion%crio--------------------------- \n\n",160);
    for (b=0;b<tam;b++){
        printf("Nome Funcion%crio: %s \n",160,func[b].nFunc);
        printf("C%cdigo Funcion%crio: %s \n",162,160,func[b].codFunc);
        printf("Endere%co: %s \n",128,func[b].endFunc);
        printf("CPF: %s \n",func[b].cpfFunc);
        printf("C%cdigo Banco: %s \n",162,func[b].codBanco);
        printf("C%cdigo Ag%cncia: %s \n",162,136,func[b].codAgencia);
        printf("Conta Corrente: %s \n",func[b].CCFunc);
        printf("Custo Horas: %.2f \n",func[b].vHora);
        printf("--------------------------------------------------------------------------- \n");
    }
}
void imprime_lista_mes(RegMes mes[tam]){
    int a;
    printf("---------------------------Dados do M%cs--------------------------- \n",136);
    for (a=0;a<tam;a++){
       printf("C%cdigo Funcion%crio: %s \n",162,160,mes[a].codFunc);
       printf("Horas Trabalhadas: %d \n",mes[a].horas);
       printf("------------------------------------------------------------------\n");
    }
}
void imprime_folha_pagamento(RegFunc func[tam],RegMes mes[tam]){
    int i,j,retorno;

    printf("\n\n-----------------------------Folha de Pagamento------------------------------\n\n\n");
    for (i=0;i<tam;i++){
        for (j=0;j<tam;j++){
            retorno = strcmp(func[i].codFunc,mes[j].codFunc);
            if (retorno ==0){
                printf("-----------------------------------------------------------------------------\n");
                printf("| Nome: %s \n",func[i].nFunc);
                printf("| CPF: %s \n",func[i].cpfFunc);
                printf("| C%cdigo do Banco: %s \n",162,func[i].codBanco);
                printf("| Ag%cncia: %s \n",136,func[i].codAgencia);
                printf("| Conta Corrente: %s \n",func[i].CCFunc);
                printf("| Sal%cario L%cquido: R$ %.2f \n",160,161,func[i].vHora*mes[j].horas);
            }
        }
     }printf("-----------------------------------------------------------------------------\n");
}
void imprime_folha_pagamento_arquivo(RegFunc func[tam],RegMes mes[tam]){
    FILE *arq;
    arq = fopen("folha_de_pagamento.txt","w");
    int i,j,retorno;
    printf("Arquivo constru%cdo com sucesso! \n\n",161);
    fprintf(arq,"-----------------------------Folha de Pagamento------------------------------\n\n\n");
    for (i=0;i<tam;i++){
        for (j=0;j<tam;j++){
            retorno = strcmp(func[i].codFunc,mes[j].codFunc);
            if (retorno ==0){
                fprintf(arq,"-----------------------------------------------------------------------------\n");
                fprintf(arq,"| Nome: %s \n",func[i].nFunc);
                fprintf(arq,"| CPF: %s \n",func[i].cpfFunc);
                fprintf(arq,"| Código do Banco: %s \n",func[i].codBanco);
                fprintf(arq,"| Agência: %s \n",func[i].codAgencia);
                fprintf(arq,"| Conta Corrente: %s \n",func[i].CCFunc);
                fprintf(arq,"| Salário Líquido: R$ %.2f \n",func[i].vHora*mes[j].horas);
            }
        }
     }fprintf(arq,"-----------------------------------------------------------------------------\n");
    fclose(arq);
}




