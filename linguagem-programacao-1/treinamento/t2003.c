//Treinamento 2.003
//Estados e Capitais - usando ifs

#include <stdio.h>
#include <string.h>

int main(){

	char sigla[3];
	
	gets(sigla);
	
		if (strcmp(sigla,"AC")==0){
			printf("Acre - Rio Branco");}
		else if (strcmp(sigla,"AL")==0){
			printf("Alagoas - Maceio");}
		else if (strcmp(sigla,"AP")==0){
			printf("Amapa - Macapa");}
		else if (strcmp(sigla,"AM")==0){
			printf("Amazonas - Manaus");}
		else if (strcmp(sigla,"BA")==0){
			printf("Bahia - Salvador");}
		else if (strcmp(sigla,"CE")==0){
			printf("Ceara - Fortaleza");}
		else if (strcmp(sigla,"DF")==0){
			printf("Distrito Federal - Brasilia");}
		else if (strcmp(sigla,"ES")==0){
			printf("Espirito Santo - Vitoria");}
		else if (strcmp(sigla,"GO")==0){
			printf("Goias - Goiania");}
		else if (strcmp(sigla,"MA")==0){
			printf("Maranhao - Sao Luiz");}
		else if (strcmp(sigla,"MT")==0){
			printf("Mato Grosso - Cuiaba");}
		else if (strcmp(sigla,"MS")==0){
			printf("Mato Grosso do Sul - Campo Grande");}
		else if (strcmp(sigla,"MG")==0){
			printf("Minas Gerais - Belo Horizonte");}
		else if (strcmp(sigla,"PA")==0){
			printf("Para - Belem");}
		else if (strcmp(sigla,"PB")==0){
			printf("Paraiba - Joao Pessoa");}
		else if (strcmp(sigla,"PR")==0){
			printf("Parana - Curitiba");}
		else if (strcmp(sigla,"PE")==0){
			printf("Pernambuco - Recife");}
		else if (strcmp(sigla,"PI")==0){
			printf("Piaui - Terezina");}
		else if (strcmp(sigla,"RJ")==0){
			printf("Rio de Janeiro - Rio de Janeiro");}
		else if (strcmp(sigla,"RN")==0){
			printf("Rio Grande do Norte - Natal");}
		else if (strcmp(sigla,"RS")==0){
			printf("Rio Grande do Sul - Porto Alegre");}
		else if (strcmp(sigla,"RO")==0){
			printf("Rondonia - Porto Velho");}
		else if (strcmp(sigla,"RR")==0){
			printf("Roraima - Boa Vista");}
		else if (strcmp(sigla,"SC")==0){
			printf("Santa Catarina - Florianopolis");}
		else if (strcmp(sigla,"SP")==0){
			printf("Sao Paulo - Sao Paulo");}
		else if (strcmp(sigla,"SE")==0){
			printf("Sergipe - Aracaju");}
		else if (strcmp(sigla,"TO")==0){
			printf("Tocantins - Palmas");}
		else{
			printf("ESTADO INVALIDO");
		}


return 0;
}

