#include <stdio.h>
#include <time.h>
#include "acessory-functions.h"


void selection_sort_crescente(int *vtr, int tam, int *compara, int *movimenta){
    int i, j, menor;

    for(i = 0; i < tam - 1; i++){
        menor = i;
        for(j = i +1; j <tam; j++){
            (*compara)++;
            if(vtr[j] < vtr[menor]){
                menor = j;
            }
        }
        swap(&vtr[menor], &vtr[i]);
        (*movimenta)++;
    }



}

void selection_sort_decrescente(int *vtr, int tam, int *compara, int *movimenta){
    int i, j, menor;

    for(i = 0; i < tam - 1; i++){
        menor = i;
        for(j = i +1; j <tam; j++){
            (*compara)++;
            if(vtr[j] > vtr[menor]){
                menor = j;
            }
        }
        swap(&vtr[menor], &vtr[i]);
        (*movimenta)++;
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
    selection_sort_crescente(arrcopy, size, &compara, &movimenta);
    t = clock() - t;

    printf("selection sort em ordem crescente:\n");

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
    selection_sort_decrescente(arrcopy, size, &compara, &movimenta);
    t = clock() - t;

    printf("\nselection sort em ordem decrescente:\n");

    print_array(arr, size);
    print_array(arrcopy, size);
    printf("%d comparações\n", compara);
    printf("%d movimentações\n", movimenta);
    printf("%d clicks (%f seconds)\n",t, ((float)t)/CLOCKS_PER_SEC);
    
  return 0;
}
