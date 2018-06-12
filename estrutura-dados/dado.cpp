using namespace std;
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

typedef enum {rDown = 0, rLeft = 1, rUp = 2, rRight = 3}rollDirection;
typedef struct {int row, col;} Pair;
typedef struct {
    int top, front, left;
    Pair pos; 
} Dice;

/*
    Mantive os vetores e a solução como variáveis globais.
    Ainda não se é mais rápido dessa forma ou passando como argumento
*/
int **board;
bool *****moves;
Pair * solution;
int totalSteps = 0;

/* Função que rola o dado
    Utilizada para estender e retrocedor durante o backtracking e 
    configurar o dado no inicio da execucao*/
void roll (rollDirection r, Dice * d){
    int temp;
    temp = d->top;
    switch(r){
        case rDown: 
            d->top = 7 - d->front;
            d->front = temp;
            d->pos.row++;
            break;
        case rLeft: 
            d->top = 7 - d->left;
            d->left = temp;
            d->pos.col--;
            break;
        case rUp: 
            d->top = d->front;
            d->front = 7 - temp;
            d->pos.row--;
            break;
        case rRight: 
            d->top = d->left;
            d->left = 7 - temp;
            d->pos.col++;
            break;
    }
}
void setDice (Dice * d, int top, int front){
    /*  rola o dado para baixo e para esquerda até o topo ser igual ao lado de baixo desejado
        em seguida rola ele para baixo uma vez (baixodo dado igual ao baixo desejado)
        por ultimo rola ele para esquerda até o topo do dado ser igual ao topo desejado
    */
    d->top = 6; d->front = 4; d->left = 2;
    while (d->top != front){
        roll(rDown, d);
        if (d->top == front)
            break;
        roll(rLeft, d);
    }
    roll(rDown, d);
    while (d->top != top)
        roll(rLeft,d);
} 
void printSolution(){
    printf("%d ", totalSteps);
    for (int i = 0; i < totalSteps -1; i++){
        printf("(%d,%d) ", solution[i].row, solution[i].col);
    }
    printf("(%d,%d)\n", solution[totalSteps -1].row, solution[totalSteps -1].col);
}

/* Backtracking */
bool PathFinder(Dice dice, Pair pBegin, int steps){
    /*  Armazeno todas as variaveis do Tabuleiro e Quadro de Movimentos 
        que serão utilizadas nas comparações
        */
    Pair sol;
    bool result = false;
    int up = board[dice.pos.row - 1][dice.pos.col];
    int down = board[dice.pos.row + 1][dice.pos.col];
    int left = board[dice.pos.row][dice.pos.col - 1];
    int right = board[dice.pos.row ][dice.pos.col + 1];
    bool * move = moves[dice.pos.row][dice.pos.col][dice.top-1][dice.front-1];
    
    /*Verifica se aceita*/
    if ((steps > 0) && ((dice.pos.row == pBegin.row) && (dice.pos.col == pBegin.col))){
        totalSteps = steps+1;
        solution = (Pair *)malloc(totalSteps * sizeof(Pair));
        sol.col = dice.pos.col;
        sol.row = dice.pos.row;
        solution[steps] = sol;
        return true;
    } else {
        for (int s = rDown; ((s <= rRight) && (result == false)); s++){
            switch(s){
                case rDown:
                    if ((*move == true) && ((down == -1) || (down == dice.top))){
                        /* Estende */
                        steps++;
                        *move = false;
                        roll(rDown, &dice);
                        
                        /* Chama a Função */
                        result = PathFinder(dice, pBegin, steps);
                        
                        /* Retrocede */
                        roll(rUp, &dice);
                        *move = true;
                        steps--;
                    }
                    break;
                case rLeft: 
                    if ((*move == true) && ((left == -1) || (left == dice.top))){
                        steps++;
                        *move = false;
                        roll(rLeft, &dice);
                        
                        result = PathFinder(dice, pBegin, steps);
                        
                        roll(rRight, &dice);
                        *move = true;
                        steps--;
                    }
                    break;
                case rUp: 
                    if ((*move == true) && ((up == -1) || (up == dice.top))){
                        steps++;
                        *move = false;
                        roll(rUp, &dice);
                        
                        result = PathFinder(dice, pBegin, steps);
                        
                        roll(rDown, &dice);
                        *move = true;
                        steps--;
                        
                    }
                    break;
                case rRight: 
                    if ((*move == true) && ((right == -1) || (right == dice.top))){
                        steps++;
                        *move = false;
                        roll(rRight, &dice);
                        
                        result = PathFinder(dice, pBegin, steps);
                        
                        roll(rLeft, &dice);
                        steps--;
                    }
                    break;
            }
        }
    }
    if (result == true){
        sol.col = dice.pos.col;
        sol.row = dice.pos.row;
        solution[steps] = sol;
    }
    *move = false;
    return result;
}

int main() {
    int boardWidth, boardHeight, mazesNumber;
    Pair pBegin, pDice;
    Dice dice;
    dice.pos.row = dice.pos.col = 0;
    clock_t Ticks[2];
    scanf("%d", &mazesNumber);  // Lê o numero de labirintos
    for (int x = 0; x < mazesNumber; x++){
        Ticks[0] = clock();
        scanf("%d %d", &boardHeight, &boardWidth);  // Lê o tamanho do tabuleiro
        scanf("%d %d", &pBegin.row, &pBegin.col);   // Lê posição inicial no tabuleiro
        scanf("%d %d", &pDice.row, &pDice.col);         // Lê face do topo e de baixo
        setDice(&dice, pDice.row, pDice.col);           // Ajusta a posição do dado
        dice.pos.row = pBegin.row;
        dice.pos.col = pBegin.col;
        
        boardHeight += 2;                           // Cria uma borda em volta do tabuleiro
        boardWidth += 2;
        board = (int **) malloc(boardHeight * sizeof(int *));     // Instacia o tabuleiro
        moves = (bool *****) malloc(boardHeight * sizeof(bool ****));    // Instacia o quadro de movimentos
        
        /*  Lê e atribui o valor do tabuleiro e do quadro de movimentos 
            Tabuleiro:
            Se for borda valor zero; se nao lê o valor de entrada;
            
            Quadro de Movimentos:
            para cada posição do tabuleiro cria um vetor de tamanho 4
            esse vetor armazena quais são as possíveis direções independente do valor do tabuleiro
            isso impedirá que o programa entre em um loop infinito
            exemplo: ao mover o dado para baixo na linha 4 e coluna 5, a posicao 0 (rDown) do vetor naquela linha e coluna passa a ser falso
            caso o dado entre na mesma linha e coluna ele nao poderá ir para baixo, evitando o loop
        */
        for (int i = 0; i < boardHeight; i++){
            board[i] = (int*) malloc(boardWidth * sizeof(int));
            moves[i] = (bool****) malloc(boardWidth * sizeof(bool ***));
            for (int j = 0; j < boardWidth; j++){
                if ((i == 0) || (i == boardHeight-1) || (j == 0) || (j == boardWidth-1))
                    board[i][j] = 0;
                else{
                    scanf("%d", &board[i][j]);
                }
                moves[i][j] = (bool***) malloc(6 * sizeof(bool **));
                for (int l = 0; l < 6; l++) {
                    moves[i][j][l] = (bool**) malloc(6 * sizeof(bool *));
                    for (int m = 0; m < 6; m++) {
                        moves[i][j][l][m] = (bool*) malloc(sizeof(bool));
                        *moves[i][j][l][m] = true;
                    }
                }
            }
        }
        cout << "Labirinto " << x+1 << endl;
        if (PathFinder(dice, pBegin, 0)){
            printSolution();
        } else {
            printf("0 IMPOSSÍVEL\n");
        }
        Ticks[1] = clock();
        double timeSpent = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
        cout << "Tempo gasto " << timeSpent <<"s" << endl << endl;
    }
    
    
    return 0;
}