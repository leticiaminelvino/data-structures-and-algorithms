#include <stdio.h>
#include <stdlib.h>

//matriz de adjacencia
typedef struct {
    int **adjacencia; //matriz de adjacencia
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
int grau(Grafo_ptr grafo, int vertice);
int vertice_com_maior_grau(Grafo_ptr grafo);
void vizinhos_dos_vizinhos(Grafo_ptr grafo, int vertice1);


Grafo_ptr criar_grafo(int num_vertices){
    int i, j;
    Grafo_ptr grafo = malloc(sizeof(Grafo));
    grafo->num_vertices = num_vertices;

    //alocar a matriz
    grafo->adjacencia = malloc(num_vertices * sizeof(int *));
    for(i = 0; i < num_vertices; i++){
        grafo->adjacencia[i] = calloc(num_vertices, sizeof(int)); //calloc pra preencher com 0
    }
    return grafo;
}

void destroi_grafo(Grafo_ptr grafo){
    int i;
    for(i = 0; i < grafo->num_vertices; i++){
        free(grafo->adjacencia[i]);
    free(grafo->adjacencia);
    free(grafo);
    }
}

void insere_aresta(Grafo_ptr grafo, int vertice1, int vertice2){
    grafo->adjacencia[vertice1][vertice2] = 1;
    grafo->adjacencia[vertice2][vertice1] = 1;
}

void remove_aresta(Grafo_ptr grafo, int vertice1, int vertice2){
    grafo->adjacencia[vertice1][vertice2] = 0;
    grafo->adjacencia[vertice2][vertice1] = 0;
}

int tem_aresta(Grafo_ptr grafo, int vertice1, int vertice2){
    return grafo->adjacencia[vertice1][vertice2];
}

void imprime_arestas(Grafo_ptr grafo){
    int vertice1, vertice2;
    for(vertice1 = 0; vertice1 < grafo->num_vertices; vertice1++){
        for( vertice2 = vertice1+1; vertice2 < grafo->num_vertices; vertice2++){ //so passar pela triangular superior, imprimir o menor primeiro e maior depois
            if(tem_aresta(grafo, vertice1, vertice2)){
                printf("{%d, %d}\n", vertice1, vertice2);
            }
        }
    }
}

int grau(Grafo_ptr grafo, int vertice){
    int vertice2, grau = 0;
    for(vertice2 = 0; vertice2 < grafo->num_vertices; vertice2++){
        if(tem_aresta(grafo, vertice, vertice2)){
            grau++;
        }
    }
    return grau;
}

int vertice_com_maior_grau(Grafo_ptr grafo){
    int vertice, max, grau_max, grau_atual;
    max = 0;
    grau_max = grau(grafo, 0);
    for(vertice = 1; vertice < grafo->num_vertices; vertice++){
        if ( grau_atual > grau_max ){
            grau_max = grau_atual;
            max = vertice;
        }
    }
    return max;
}

void vizinhos_dos_vizinhos(Grafo_ptr grafo, int vertice1){
    int vertice2, vizinho;
    for(vertice2 = 0; vertice2 < grafo-> num_vertices; vertice2++){
        if(grafo->adjacencia[vertice1][vertice2]){
            for(vizinho = 0; vizinho < grafo->num_vertices; vizinho++){
                if( (tem_aresta(grafo, vertice2, vizinho)) && (vizinho != vertice1) && (!tem_aresta(grafo, vertice1, vizinho)) ){
                    printf("%d\n", vizinho);
                }
            }
        }
    }
}


Grafo_ptr le_grafo(){
    int num_vertices, num_arestas, vertice1, vertice2, i;
    Grafo_ptr grafo;

    printf("numero de vertices e numero arestas (formato(x y)):");
    scanf("%d %d", &num_vertices, &num_arestas);

    grafo = criar_grafo(num_vertices);

    for (i = 0; i < num_arestas; i++){
        printf("\naresta formada entre os vertices...(formato(x y)):");
        scanf("%d %d", &vertice1, &vertice2);
        insere_aresta(grafo,vertice1,vertice2);
    }
    return grafo;
}


int main(){
   return 0;
}