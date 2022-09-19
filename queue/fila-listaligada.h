#include "lista-ligada.h"

typedef struct {
    Node_ptr inicio, fim;
}Fila;
typedef Fila * Fila_ptr;

Fila_ptr criar_fila(){
    Fila_ptr fila;
    fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

void destruir_fila(Fila_ptr fila){
    destruir_lista(fila->inicio);
    free(fila);
}

void enfileira(Fila_ptr fila, int x){
    Node_ptr novo;
    novo = (Node *)malloc(sizeof(Node));
    novo->dado = x;
    novo->prox = NULL;
    if(fila->inicio == NULL){
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
    }
    fila->fim = novo;
}

int desenfileira(Fila_ptr fila){
    Node_ptr primeiro = fila->inicio;
    int x = primeiro->dado;
    fila->inicio = fila->inicio->prox;
    if(fila->inicio == NULL){
        fila->fim = NULL;
    }
    free(primeiro);
    return x;
}
