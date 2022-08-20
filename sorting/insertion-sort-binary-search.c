#include <stdio.h>
#include <time.h>
#include "acessory-functions.h"

int busca_binaria(int *vetor, int inicio, int fim, int chave, int *compara){
    (*compara)++;
    if (fim > inicio){
        int meio = inicio + (fim - inicio) / 2;
        if (vetor[meio] == chave)
            return meio;

        if (vetor[meio] > chave)
            return busca_binaria(vetor, inicio, meio - 1, chave, compara);

        return busca_binaria(vetor, meio + 1, fim, chave, compara);
    }
    return (chave > vetor[inicio]) ? (inicio + 1) : inicio;
}

void insertion_sort_BB_crescente(int *vtr, int tam, int *compara, int *movimenta){
    int i, j, aux, posicaoInsercao;

    for (i = 1; i < tam; i++){
        j = i - 1;
        aux = vtr[i];
        
        posicaoInsercao = busca_binaria(vtr, 0, j, aux, compara);

        while (j >= 0 && j >= posicaoInsercao){
            (*compara)++;
            vtr[j + 1] = vtr[j];
            (*movimenta)++;
            j--;
        }
        vtr[j + 1] = aux;
    }
}

void insertion_sort_BB_decrescente(int *vtr, int tam, int *compara, int *movimenta){
    int i, j, aux, posicaoInsercao;

    for (i = 1; i < tam; i++){
        j = i - 1;
        aux = vtr[i];
        
        posicaoInsercao = busca_binaria(vtr, 0, j, aux, compara);

        while (j >= 0 && j < posicaoInsercao){
            (*compara)++;
            vtr[j + 1] = vtr[j];
            (*movimenta)++;
            j--;
        }
        vtr[j + 1] = aux;
    }
}


int main(){
    time_t t;

    int arr[] = {3, 4, 2, 5, 1, 7, 6, 9, 8},
        size = sizeof(arr) / sizeof(arr[0]),
        arrcopy[size];

    int compara = 0,
        movimenta = 0;


    //crescente
    copy_array(arr, arrcopy, size);

    t = clock();
    insertion_sort_BB_crescente(arrcopy, size, &compara, &movimenta);
    t = clock() - t;

    printf("insertion sort com busca binária em ordem crescente:\n");
    print_array(arr, size);
    print_array(arrcopy, size);
    printf("%d comparações\n", compara);
    printf("%d movimentações\n", movimenta);
    printf("%d clicks (%f seconds)\n",t, ((float)t)/CLOCKS_PER_SEC);


    //decrescente
    compara = 0,
    movimenta = 0;
    copy_array(arr, arrcopy, size);

    t = clock();
    insertion_sort_BB_decrescente(arrcopy, size, &compara, &movimenta);
    t = clock() - t;

    printf("\ninsertion sort com busca binária em ordem decrescente:\n");
    print_array(arr, size);
    print_array(arrcopy, size);
    printf("%d comparações\n", compara);
    printf("%d movimentações\n", movimenta);
    printf("%d clicks (%f seconds)\n",t, ((float)t)/CLOCKS_PER_SEC);
    
  return 0;
}