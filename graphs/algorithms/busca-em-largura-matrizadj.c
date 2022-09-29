//busca em largura, matriz adjacencia

#include <stdio.h>
#include "fila-listaligada.h"
#include "matrizadj-naodirecionado-naoponderado.c"


int * busca_em_largura(Grafo_ptr grafo, int s){
    int w, v;
    int *pai = malloc(grafo->num_vertices * sizeof(int));
    int *visitado = malloc(grafo->num_vertices * sizeof(int));
    Fila_ptr fila = criar_fila();
    for( v = 0; v < grafo->num_vertices; v++){
        pai[v] = -1;
        visitado[v] = 0;
    }
    enfileira(fila, s);
    pai[s] = s;
    visitado[s] = 1;
    while(!fila_vazia(fila)){
        v = desenfileira(fila);
        for ( w = 0; w < grafo->num_vertices; w++){
            if(grafo->adjacencia[v][w] && !visitado{w}){
                visitado[w] = 1; //evita repeti��o na fila
                pai[w] = v;
                enfileira(fila, w);
            }
        }
    }
    destroi_fila(fila);
    free(visitado);
    return pai;
}
