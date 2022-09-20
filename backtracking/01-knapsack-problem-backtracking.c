#include <stdio.h>
#include <stdlib.h>

#define NUM_OBJ 4           //numero de objetos
#define CAPACIDADE 10.0    //capacidade da mochila

typedef struct {
    int nome;
    float valor;
    float peso;
} Objeto;

typedef struct{
    Objeto *vetor;
    int qtd_de_elem;
} Lista;

typedef Lista *Lista_ptr;


int main(){
    return 0;
}