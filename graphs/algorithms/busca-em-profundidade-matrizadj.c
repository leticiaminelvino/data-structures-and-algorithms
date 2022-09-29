//busca em profundidade, matriz adjacencia
#include "pilha-listaligada.h"
#include "matrizadj-naodirecionado-naoponderado.c"


int * busca_em_profundidade(Grafo_ptr grafo, int s){
    int w, v;
    int *pai = malloc(grafo->num_vertices * sizeof(int));
    int *visitado = malloc(grafo->num_vertices * sizeof(int));
    Pilha_ptr pilha = criar_pilha();
    for( v = 0; v < grafo->num_vertices; v++){
        pai[v] = -1;
        visitado[v] = 0;
    }
    empilhar(pilha, s);
    pai[s] = s;
    while(!pilha_vazia(pilha)){
        v = desempilhar(pilha);
        visitado[v] = 1;
        for ( w = 0; w < grafo->num_vertices; w++){
            if(grafo->adjacencia[v][w] && !visitado{w}){
                pai[w] = v;
                empilhar(pilha, w);
            }
        }
    }
    destroi_pilha(pilha);
    free(visitado);
    return pai;
}
