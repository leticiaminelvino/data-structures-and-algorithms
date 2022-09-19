#include "lista-ligada.h"

typedef struct {
    Node_ptr topo;
} Pilha;

typedef Pilha * Pilha_ptr;

void empilhar(Pilha_ptr pilha, int x){
    Node_ptr novo = (Node *)malloc(sizeof(Node));
    novo->dado = x;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

int desempilhar(Pilha_ptr pilha){
    Node_ptr topo = pilha->topo;
    int x = topo->dado;
    pilha->topo = pilha->topo->prox;
    free(topo);
    return x;
}

void destroi_pilha();