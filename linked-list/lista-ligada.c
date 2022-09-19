#include <stdio.h>

typedef struct Node{
    int dado;
    struct Node *proximo;
} Node;

typedef Node * Node_ptr;

Node_ptr criar_lista(){
    return NULL;
}

void destruir_lista(Node_ptr lista){
    if(lista != NULL){
        destruir_lista(lista->proximo);
        free(lista);
    }
}

Node_ptr adicionar_elemento(Node_ptr lista, int x){
    Node_ptr novo;
    novo = malloc(sizeof(Node));
    novo->dado = x;
    novo->proximo = lista;
    return novo;
}

