#include <stdio.h>
#include <stdlib.h>

#define FALSE   0
#define TRUE    1

void mostra_solucao(int n, int rainha_coluna[]);
void rainhas(int n);

int main(int argc, char *argv[])
{ 
    int n;

    if (argc == 1)  {
        printf("Forma de utilizar: %s  <num_rainhas>\n", argv[0]);
        return 1;
    }
    n = atoi(argv[1]);
    if (n <= 0) {
        printf("O argumento deve ser um numero maior que zero.\n");
        return 1;
    }
    rainhas(n);
    return 0;
}       

void rainhas(int n)
{
    int *coluna_livre;    /* (coluna_livre[k] == TRUE) se nao existe rainha na coluna k */
                          
    int *rainha_coluna;   /* rainha_coluna[k] eh a coluna da rainha na linha k */

    int *diagonal_livre;   /* (diagonal_livre[k] == TRUE) se nao existe rainha na diagonal principal k-n+1 */

    int *diagonal_principal_livre; /* (diagonal_principal_livre[k] == TRUE) se nao existe rainha na diagonal principal k */

    int *diagonal_secundaria_livre; /* (diagonal_secundaria_livre[k] = TRUE) se nao existe rainha na diagonal secundaria k */

    int linha, coluna, k, n_solucoes;
    int fim;
    int achou_posicao;

    coluna_livre = (int*) malloc(n * sizeof(int));
    diagonal_livre = (int*) malloc((2 * n - 1) * sizeof(int));
    diagonal_secundaria_livre = (int*) malloc((2 * n - 1) * sizeof(int));
    diagonal_principal_livre = diagonal_livre + n - 1; /* faz diagonal_principal_livre apontar para o 
                                          meio do vetor diagonal_livre */
    rainha_coluna = (int*) malloc(n * sizeof(int));

    for (k = 0; k < n; k++)
        coluna_livre[k] = TRUE; /* Inicializa todas as colunas do tabuleiro como livres*/

    for (k = 0; k < 2 * n - 1; k++)  
        diagonal_livre[k] = diagonal_secundaria_livre[k] = TRUE; /* Inicializa todas as diagonais do tabuleiro como livres*/
  
    linha = 0;  
    coluna = 0; 
    n_solucoes = 0;  
    fim = FALSE;
    while (!fim)   {
        achou_posicao = FALSE;
        while (coluna < n && !achou_posicao)  { 
            /* verifica se a posicao (linha, coluna) eh possivel */
            if (coluna_livre[coluna] && diagonal_principal_livre[linha - coluna] 
                               && diagonal_secundaria_livre[linha + coluna]) {
                coluna_livre[coluna] = FALSE;
                diagonal_principal_livre[linha - coluna] = FALSE;
                diagonal_secundaria_livre[linha + coluna] = FALSE;
                rainha_coluna[linha] = coluna;
                achou_posicao = TRUE;
                /*printf("rainha em (%d, %d)\n", linha, coluna);*/
            }
            else {
                /*printf("          (%d, %d): posicao impossivel\n", linha, coluna);*/
                coluna++;
            }
        }
        if (achou_posicao)  {
            if (linha != n - 1)  { 
                /* tenta posicionar a proxima rainha */
                linha++;
                coluna = 0;
            }
            else  {  
                /* determina mais uma solucao */
                n_solucoes++; 
                mostra_solucao(n, rainha_coluna);

                /* retira a ultima rainha colocada para tentar encontrar uma outra solucao */
                coluna_livre[coluna] = TRUE;
                diagonal_principal_livre[linha - coluna] = TRUE;
                diagonal_secundaria_livre[linha + coluna] = TRUE;

                /* esta atribuicao forca um backtrack para a linha anterior */
                coluna = n;
            }
        }
        else  {
            /* coluna eh n */
            /* testa todas as colunas para linha : fazer backtracking */
            if (linha == 0)  /* testa todas as possibilidades */
                fim = TRUE;
            else  {
                /* tenta uma outra posicao para a rainha na linha anterior */
                linha--;
                /*printf("backtrack: volta para linha %d\n", linha);*/
                coluna = rainha_coluna[linha];
                coluna_livre[coluna] = TRUE;
                diagonal_principal_livre[linha - coluna] = TRUE;
                diagonal_secundaria_livre[linha + coluna] = TRUE;
                coluna++;
            }
        }
    }
    if (n_solucoes == 0) {
        printf("Nenhuma solucao para %d rainhas encontrada.\n", n);
    }
    free(rainha_coluna);
    free(coluna_livre);
    free(diagonal_livre);
    free(diagonal_secundaria_livre);
}

void mostra_solucao(int n, int rainha_coluna[]) 
{
    static int conta = 0;
    int coluna, linha;

    printf("Solucao %i:\n", ++conta);
    for (linha = 0; linha < n; linha++) {
        for (coluna = 0; coluna < n; coluna++) {
            printf((rainha_coluna[linha] == coluna) ? "|R" : "|_");
        }
        printf("|\n");
    }
    printf("\n");
}