#include <stdio.h>

int pode_inserir(int matriz[9][9], int linha, int coluna, int valor);
void proxima_posicao(int linha, int coluna, int *nova_linha, int *nova_coluna);
int sudoku(int matriz[9][9]);
int sudokuR(int matriz[9][9], int fixo[9][9], int linha, int coluna);
void imprime_sudoku(int matriz[9][9]);


void imprime_sudoku(int matriz[9][9]){
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n"); 
    }
}

int pode_inserir(int matriz[9][9], int linha, int coluna, int valor){
    int i, j, subgrade_linha, subgrade_coluna;
    
    for(i = 0; i < 9; i++){
        if(matriz[linha][i] == valor){ //aparece na linha?
            return 0;
        } 
    }
    for (i = 0; i < 9; i++){
        if(matriz[i][coluna] == valor){  //aparece na coluna?
            return 0;
        }
    }

    //vai para o quadrado na primeira linha e coluna da subgrade 3x3 que o valor está
    subgrade_linha = 3 * ( linha / 3); 
    subgrade_coluna = 3 * (coluna / 3);
    //aparece na subgrade?
    for ( i = subgrade_linha; i < subgrade_linha + 3; i++){
        for( j = subgrade_coluna; j < subgrade_coluna + 3; j++){
            if(matriz[i][j] == valor){
                return 0;
            }
        }
    }
    return 1;
}


int sudoku(int matriz[9][9]){
    int i, j, fixo[9][9];
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            fixo[i][j] = matriz[i][j]; 
        }
    }
    return sudokuR(matriz, fixo, 0, 0);
}


int sudokuR(int matriz[9][9], int fixo[9][9], int linha, int coluna){
    int valor, nova_linha, nova_coluna;
    if( linha == 9 ){ 
        imprime_sudoku(matriz);
        return 1;
    }
    proxima_posicao(linha, coluna, &nova_linha, &nova_coluna);
    if(fixo[linha][coluna]){ //se for diferente de 0, ou seja, se já tiver um número nessa posição
        return sudokuR(matriz, fixo, nova_linha, nova_coluna);
    }
    for ( valor = 1; valor <=9; valor++){
        if(pode_inserir(matriz, linha, coluna, valor)){ //verdadeiro se a função "pode_inserir" retornar 1
            matriz[linha][coluna] = valor;
            if(sudokuR(matriz, fixo, nova_linha, nova_coluna)){ //chama recursivamente com a prox linha e coluna
                return 1; //termina quando chega na linha 9
            }
        }
    }
    matriz[linha][coluna] = 0;
    return 0; 
}


void proxima_posicao(int linha, int coluna, int *nova_linha, int *nova_coluna){
    if(coluna < 8){
        *nova_linha = linha;
        *nova_coluna = coluna + 1;
    }
    else {
        *nova_linha = linha + 1;
        *nova_coluna = 0;
    }
}


int main(){
    int grid_inicial[9][9] =   {{ 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                                { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                                { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                                { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                                { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                                { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                                { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                                { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                                { 0, 0, 5, 2, 0, 6, 3, 0, 0 }};

    sudoku(grid_inicial);


    return 0;
}

/*
Output esperado

3 1 6 5 7 8 4 9 2 
5 2 9 1 3 4 7 6 8 
4 8 7 6 2 9 5 3 1 
2 6 3 4 1 5 9 8 7 
9 7 4 8 6 3 1 2 5 
8 5 1 7 9 2 6 4 3 
1 3 8 9 4 7 2 5 6 
6 9 2 3 5 1 8 7 4 
7 4 5 2 8 6 3 1 9 

*/