#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#define infinito 100000
/*
    Algoritmo troco mínimo com Programação Dinâmica
*/
using namespace std;

void zerarVetor (int *vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        vetor[i] = 0;
    }
}

void imprimirResultado (int *vetor, int troco){ 
    int i;
    int qtd_moedas = 0;
    cout << "Moedas utilizadas " << endl;
    while (troco > 0){
        cout << vetor[troco] << " ";
        troco -= vetor[troco];
        qtd_moedas++;
    }
    cout << " " << endl;
    cout << "Quantidade de moedas: " << qtd_moedas << endl;
}

void trocoMinimo(int troco, int num_moedas, int *TM, int *moedas, int * escolha){
    int i,j;
    TM[0] = 0;
    for(i = 1; i < troco+1; i++){
        TM[i] = infinito;
        for(j = 0; ((j < num_moedas) && (moedas[j] <= i)); j++){ // para moeda pertence a M | moeda <= i faça
            if(1 + TM[i - moedas[j]] < TM[i]){
                TM[i] = 1 + TM[i - moedas[j]]; //sub estrutura ótima
                escolha[i] = moedas[j];
                //cout << "TM: " <<TM[i] << "| Escolha:  "<< escolha[i] << endl;
            }
        }
    }
    imprimirResultado(escolha, troco);
    
}

int main(int argc, char const *argv[]){
    
    int *moedas; // vetor moedas é "M" do slide
    int *TM; 
    int *escolha; // vetor que armazena a moeda que foi utilizada
    int num_moedas, troco;
    cout << "Insira o numero de moedas ";
    scanf("%d", &num_moedas);
    moedas = (int*)malloc(num_moedas*sizeof(int));
    cout << "Insira as moedas ";
    for (int i = 0; i < num_moedas; i++)
        scanf("%d", &moedas[i]);
    cout << "Insira o valor do troco ";
    scanf("%d", &troco);
    TM = (int*)malloc((troco+1) * sizeof(int));
    escolha = (int*)malloc((troco+1) * sizeof(int));
    zerarVetor(escolha, troco+1);
    trocoMinimo(troco, num_moedas, TM, moedas, escolha); // resposta: 4 moedas |  1 1 10 25

return 0;
}