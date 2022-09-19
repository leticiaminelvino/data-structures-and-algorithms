//�pilha com lista ligada

#include <stdio.h>
#include "lista-ligada.c"

typedef struct {
    Node_ptr topo;
} Pilha;

typedef Pilha * Pilha_ptr;

void destroi_pilha();

void empilhar(Node_ptr pilha, int x){
    Node_ptr novo = malloc(sizeof(Node));
    novo->dado = x;
    novo->proximo = pilha->topo;
    pilha->topo = novo;
}

int desempilhar(Node_ptr pilha){
    Node_ptr topo = pilha->topo;
    int x = topo->dado;
    pilha->topo = pilha->topo->proximo;
    free(topo);
    return x;
}



