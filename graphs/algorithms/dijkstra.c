#include "lista-ligada.h"
#include "heap-min.h"

typedef struct {
    Node_ptr *adjacencia; 
    int num_vertices; //numero de vertices no grafo
} Grafo;
typedef Grafo * Grafo_ptr;

