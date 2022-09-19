#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int dado;
    struct Node *prox;
} Node;
typedef Node * Node_ptr;


Node_ptr criar_lista(){
    return NULL;
}

void destruir_lista(Node_ptr lista){
    if(lista != NULL){
        destruir_lista(lista->prox);
        free(lista);
    }
}

Node_ptr insere_na_lista(Node_ptr lista, int v){
    Node_ptr novo = (Node *)malloc(sizeof(Node));
    novo->dado = v;
    novo->prox = lista;
    return novo;
}

Node_ptr remove_da_lista(Node_ptr lista, int v){
    Node_ptr proximo;
    if(lista == NULL)
        return NULL;
    else if (lista->dado = v){
        proximo = lista->prox;
        free(lista);
        return proximo;
    } else {
        lista->prox = remove_da_lista(lista->prox, v);
        return lista;
    }
}