#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "acessory-functions.h"


void insertionSort(int arr[], int size, int *compara, int *movimenta);
void quickSort(int arr[], int low, int high, int *compara, int *movimenta);
int partition(int array[], int low, int high, int *compara, int *movimenta);


void insertionSort(int arr[], int size, int *compara, int *movimenta){
    int i, j, aux;
    for(i = 1; i <= size - 1; i++){
        aux = arr[i];
        j = i - 1;
        (*compara)++;
        while (j >= 0 && aux < arr[j]) {
            (*compara)++;
            arr[j+1] = arr[j];
            (*movimenta)++;
            j--;
        }
        arr[j+1] = aux;
    }
}


void quickSort(int arr[], int low, int high, int *compara, int *movimenta){

    if (low < high) {
      // find the pivot element such that
      // elements smaller than pivot are on left of pivot
      // elements greater than pivot are on right of pivot
      int pi = partition(arr, low, high, compara, movimenta);

      // recursive call on the left of pivot
      quickSort(arr, low, pi - 1, compara, movimenta);

      // recursive call on the right of pivot
      quickSort(arr, pi + 1, high, compara, movimenta);
    }
}


int partition(int array[], int low, int high, int *compara, int *movimenta) {
  // select the rightmost element as pivot
  int pivot = array[high];
  // pointer for greater element
  int i = (low - 1);
  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    (*compara)++;
    if (array[j] <= pivot) {
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      // swap element at i with element at j
      swap(&array[i], &array[j]);
      (*movimenta)++;
    }
  }
  // swap the pivot element with the greater element at i
  swap(&array[i + 1], &array[high]);
  (*movimenta)++;
  // return the partition point
  return (i + 1);
}



int main(){
    time_t t;

    int arr1_ascd[100], arr1_dscd[100], arr1_rand[100],
        arr2_ascd[1000], arr2_dscd[1000], arr2_rand[1000],
        arr3_ascd[10000], arr3_dscd[10000], arr3_rand[10000];

    int size;

    int compara,
        movimenta;

    int low,
        high;

    //preenchendo arrays
    for (int i = 0; i <100; i++){
        arr1_ascd[i]=i+1;
        arr1_dscd[i]=100-i;
        arr1_rand[i]= rand() % 100;
    }
    for (int i = 0; i <1000; i++){
        arr2_ascd[i]=i+1;
        arr2_dscd[i]=1000-i;
        arr2_rand[i]= rand() % 1000;
    }
    for (int i = 0; i <10000; i++){
        arr3_ascd[i]=i+1;
        arr3_dscd[i]=10000-i;
        arr3_rand[i]= rand() % 10000;
    }    


    //vetor tamanho 100
    printf("TAMANHO 100:\n");
    size = 100;
    int *arr_copy = malloc(sizeof(int) * size);

    low = 0;
    high = size - 1;

    //vetor ascendente tamanho 100 
    printf("  ascendente:\n");
        //quick sort
    compara = 0;
    movimenta = 0;
    copy_array(arr1_ascd, arr_copy, size);
    t = clock();
    quickSort(arr_copy, low, high, &compara, &movimenta);
    t = clock() - t;
    printf("    QUICK SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );
        //insertion sort
    compara = 0;
    movimenta = 0;
    t = clock();
    insertionSort(arr1_ascd, size, &compara, &movimenta);
    t = clock() - t;
    printf("    INSERTION SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );

    //vetor descendente tamanho 100
    printf("  descendente:\n");
        //quick sort
    compara = 0;
    movimenta = 0;
    copy_array(arr1_dscd, arr_copy, size);
    t = clock();
    quickSort(arr_copy, low, high, &compara, &movimenta);
    t = clock() - t;
    printf("    QUICK SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );
        //insertion sort
    compara = 0;
    movimenta = 0;
    t = clock();
    insertionSort(arr1_dscd, size, &compara, &movimenta);
    t = clock() - t;
    printf("    INSERTION SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );


    //vetor aleatorio tamanho 100
    printf("  aleatorio:\n");
        //quick sort
    compara = 0;
    movimenta = 0;
    copy_array(arr1_rand, arr_copy, size);
    t = clock();
    quickSort(arr_copy, low, high, &compara, &movimenta);
    t = clock() - t;
    printf("    QUICK SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );
        //insertion sort
    compara = 0;
    movimenta = 0;
    t = clock();
    insertionSort(arr1_rand, size, &compara, &movimenta);
    t = clock() - t;
    printf("    INSERTION SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );


    //vetor tamanho 1000
    printf("\nTAMANHO 1000:\n");
    size = 1000;
    arr_copy = realloc(arr_copy, size * sizeof(int));

    low = 0;
    high = size - 1;

    //vetor ascendente tamanho 1000
    printf("  ascendente:\n");
        //quick sort
    compara = 0;
    movimenta = 0;
    copy_array(arr2_ascd, arr_copy, size);
    t = clock();
    quickSort(arr_copy, low, high, &compara, &movimenta);
    t = clock() - t;
    printf("    QUICK SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );
        //insertion sort
    compara = 0;
    movimenta = 0;
    t = clock();
    insertionSort(arr2_ascd, size, &compara, &movimenta);
    t = clock() - t;
    printf("    INSERTION SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );

    //vetor descendente tamanho 1000
    printf("  descendente:\n");
    compara = 0;
    movimenta = 0;
    copy_array(arr2_dscd, arr_copy, size);
    t = clock();
    quickSort(arr_copy, low, high, &compara, &movimenta);
    t = clock() - t;
    printf("    QUICK SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );
        //insertion sort
    compara = 0;
    movimenta = 0;
    t = clock();
    insertionSort(arr2_dscd, size, &compara, &movimenta);
    t = clock() - t;
    printf("    INSERTION SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );

    //vetor aleatorio tamanho 1000
    printf("  aleatorio:\n");
    compara = 0;
    movimenta = 0;
    copy_array(arr2_rand, arr_copy, size);
    t = clock();
    quickSort(arr_copy, low, high, &compara, &movimenta);
    t = clock() - t;
    printf("    QUICK SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );
        //insertion sort
    compara = 0;
    movimenta = 0;
    t = clock();
    insertionSort(arr2_rand, size, &compara, &movimenta);
    t = clock() - t;
    printf("    INSERTION SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );

    //vetor tamanho 10000
    printf("\nTAMANHO 10000:\n");
    size = 10000;
    arr_copy = realloc(arr_copy, size * sizeof(int));

    low = 0;
    high = size - 1;

    //vetor ascendente tamanho 10000
    printf("  ascendente:\n");
        //quick sort
    compara = 0;
    movimenta = 0;
    copy_array(arr3_ascd, arr_copy, size);
    t = clock();
    quickSort(arr_copy, low, high, &compara, &movimenta);
    t = clock() - t;
    printf("    QUICK SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );
        //insertion sort
    compara = 0;
    movimenta = 0;
    t = clock();
    insertionSort(arr3_ascd, size, &compara, &movimenta);
    t = clock() - t;
    printf("    INSERTION SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );

    //vetor descendente tamanho 10000
    printf("  descendente:\n");
        //quick sort
    compara = 0;
    movimenta = 0;
    copy_array(arr3_dscd, arr_copy, size);
    t = clock();
    quickSort(arr_copy, low, high, &compara, &movimenta);
    t = clock() - t;
    printf("    QUICK SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );
        //insertion sort
    compara = 0;
    movimenta = 0;
    t = clock();
    insertionSort(arr3_dscd, size, &compara, &movimenta);
    t = clock() - t;
    printf("    INSERTION SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );

    //vetor aleatorio tamanho 10000
    printf("  aleatorio:\n");
        //quick sort
    compara = 0;
    movimenta = 0;
    copy_array(arr3_rand, arr_copy, size);
    t = clock();
    quickSort(arr_copy, low, high, &compara, &movimenta);
    t = clock() - t;
    printf("    QUICK SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );
        //insertion sort
    compara = 0;
    movimenta = 0;
    t = clock();
    insertionSort(arr3_rand, size, &compara, &movimenta);
    t = clock() - t;
    printf("    INSERTION SORT: comparações: %d, movimentações: %d, tempo: %d clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );


    free(arr_copy);
    return 0;
}