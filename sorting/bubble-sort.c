#include <stdio.h>
#include <time.h>
#include "acessory-functions.h"


void bubble_sort_crescente(int *vtr, int tam, int *compara, int *movimenta){  
    int i, j, aux;
    for (i = tam - 1; i > 0; i--){
        for (j = 0; j < tam-1; j ++){
            (*compara)++;
            if (vtr[j] > vtr[j+1]){
                aux = vtr[j];
                vtr[j] = vtr[j+1];
                vtr[j+1] = aux;
                (*movimenta)++;
            }
        }
    }
}



void bubble_sort_decrescente(int *vtr, int tam, int *compara, int *movimenta){  
    int i, j, aux;
    for (i = tam - 1; i > 0; i--){
        for (j = 0; j < tam-1; j ++){
            (*compara)++;
            if (vtr[j] < vtr[j+1]){
                aux = vtr[j];
                vtr[j] = vtr[j+1];
                vtr[j+1] = aux;
                (*movimenta)++;
            }
        }
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
    bubble_sort_crescente(arrcopy, size, &compara, &movimenta);
    t = clock() - t;

    printf("bubble sort em ordem crescente:\n");

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
    bubble_sort_decrescente(arrcopy, size, &compara, &movimenta);
    t = clock() - t;

    printf("\nbubble sort em ordem decrescente:\n");

    print_array(arr, size);
    print_array(arrcopy, size);
    printf("%d comparações\n", compara);
    printf("%d movimentações\n", movimenta);
    printf("%d clicks (%f seconds)\n",t, ((float)t)/CLOCKS_PER_SEC);
    
  return 0;
}