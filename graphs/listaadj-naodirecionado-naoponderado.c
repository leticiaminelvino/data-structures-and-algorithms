#include "lista-ligada.h"
typedef struct {
    Node_ptr *adjacencia; 
    int num_vertices; //numero de vertices no grafo
} Grafo;
typedef Grafo * Grafo_ptr;

Grafo_ptr criar_grafo(int num_vertices);
Grafo_ptr le_grafo();
void destroi_grafo(Grafo_ptr grafo);
void insere_aresta(Grafo_ptr grafo, int vertice1, int vertice2);
void remove_aresta(Grafo_ptr grafo, int vertice1, int vertice2);
int tem_aresta(Grafo_ptr grafo, int vertice1, int vertice2);
void imprime_arestas(Grafo_ptr grafo);

Grafo_ptr criar_grafo(int num_vertices){
    int i;

    Grafo_ptr grafo = malloc(sizeof(Grafo));
    grafo->num_vertices = num_vertices;
    //grafo->adjacencia = calloc(num_vertices, sizeof(Node_ptr)); //substitui tudo abaixo, soq com 0 ao inves de NULL
    grafo->adjacencia = malloc(num_vertices * sizeof(Node_ptr));
    for(i = 0; i < num_vertices; i++){
        grafo->adjacencia[i] == NULL;
    }
    return grafo;
}


void destroi_grafo(Grafo_ptr grafo){
    int i;
    for( i = 0; i < grafo->num_vertices; i++){
        libera_lista(grafo->adjacencia[i]);
    }
    free(grafo->adjacencia);
    free(grafo);
}


void insere_aresta(Grafo_ptr grafo, int vertice1, int vertice2){
    grafo->adjacencia[vertice2] = insere_na_lista(grafo->adjacencia[vertice2], vertice1);
    grafo->adjacencia[vertice1] = insere_na_lista(grafo->adjacencia[vertice1], vertice2);
}


void remove_aresta(Grafo_ptr grafo, int vertice1, int vertice2){
    grafo->adjacencia[vertice1] = remove_da_lista(grafo->adjacencia[vertice1], vertice2);
    grafo->adjacencia[vertice2] = remove_da_lista(grafo->adjacencia[vertice2], vertice1);
}

int tem_aresta(Grafo_ptr grafo, int vertice1, int vertice2){
    Node_ptr t;
    for(t = grafo->adjacencia[vertice1]; t != NULL; t = t->prox){
        if(t->dado== vertice2){
            return 1;
        }
    }
    return 0;
}

void imprime_arestas(Grafo_ptr grafo){
    int u;
    Node_ptr t;
    for(u = 0; u < grafo->num_vertices; u++){
        for(t = grafo->adjacencia[u]; t != NULL; t = t->prox){
            printf("{%d, %d}\n", u, t->dado);
        }
    }
}


int main(){

    return 0;
}