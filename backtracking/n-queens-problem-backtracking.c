#include <stdio.h>

#define N 8 //tamanho do tabuleiro NxN

void imprime_tabuleiro(int matriz[N][N]);
int pode_inserir(int tabuleiro[N][N], int linha, int coluna);
int place_queensR(int tabuleiro[N][N], int coluna);
int queens_problem(int tabuleiro[N][N]);

int main(){
    int tabuleiro[N][N];

    if(!queens_problem(tabuleiro)){
        printf("no solution");
    }

    return 0;
}

void imprime_tabuleiro(int matriz[N][N]){
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n"); 
    }
}

int pode_inserir(int tabuleiro[N][N], int linha, int coluna){
    int i, j;
    
    /* Check this row on left side */
    for (i = 0; i < coluna; i++)
        if (tabuleiro[linha][i])
            return 0;
  
    /* Check upper diagonal on left side */
    for (i = linha, j = coluna; i >= 0 && j >= 0; i--, j--)
        if (tabuleiro[i][j])
            return 0;
  
    /* Check lower diagonal on left side */
    for (i = linha, j = coluna; j >= 0 && i < N; i++, j--)
        if (tabuleiro[i][j])
            return 0;
  
    return 1;

}

int queens_problem(int tabuleiro[N][N]){
    int i, j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            tabuleiro[i][j] = 0; 
        }
    }
    return place_queensR(tabuleiro, 0);
}

int place_queensR(int tabuleiro[N][N], int coluna){
    int linha;
    if(coluna >= N){
        imprime_tabuleiro(tabuleiro);
        return 1;
    }
    for ( int linha = 0; linha < N; linha++ ) {
        if(pode_inserir(tabuleiro, linha, coluna) ) {
            tabuleiro[linha][coluna] = 1;
            if(place_queensR(tabuleiro, coluna + 1)){
                return 1;
            }
            tabuleiro[linha][coluna] = 0; 
        }
    }
    return 0;
}