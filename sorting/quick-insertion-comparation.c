#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "acessory-functions.h"

#define MAX 10000


void insertionSort(int arr[], int size, int *compara, int *movimenta);
void quickSort(int arr[], int low, int high, int *compara, int *movimenta);
int partition(int array[], int low, int high, int *compara, int *movimenta);

void sorting(int array[], int size);


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
    int arr_ascd[MAX], arr_dscd[MAX], arr_rand[MAX];
    int sizes[] = {100, 1000, MAX}; 
    int length; 

    for (int i = 0; i < MAX; i++){
        arr_ascd[i] = i + 1;
        arr_dscd[i] = MAX - i;
        arr_rand[i] = rand();
    }

    length =  sizeof(sizes)/sizeof(sizes[0]);
    for(int i = 0; i < length; i++) {
        printf("\nTAMANHO %d:\n", sizes[i]);

        printf("\tascendente:\n");
        sorting(arr_ascd, sizes[i]);

        printf("\tdescendente:\n");
        sorting(arr_dscd, sizes[i]);

        printf("\taleatorio:\n");
        sorting(arr_rand, sizes[i]);
    }

    return 0;
}


void sorting(int array[], int size){
    static int arrcopy[MAX];
    int compara = 0, movimenta = 0;
    int low = 0,  high = size - 1; 
    time_t t;

    //quick sort
    copy_array(array, arrcopy, size);
    t = clock();
    quickSort(arrcopy, low, high, &compara, &movimenta);
    t = clock() - t;
    printf("\t\tQUICK SORT: comparações: %d, movimentações: %d, tempo: %ld clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );

    //insertion sort
    copy_array(array, arrcopy, size);
    compara = 0;
    movimenta = 0;
    t = clock();
    insertionSort(arrcopy, size, &compara, &movimenta);
    t = clock() - t;
    printf("\t\tINSERTION SORT: comparações: %d, movimentações: %d, tempo: %ld clicks (%f seconds)\n", compara, movimenta, t, ((float)t)/CLOCKS_PER_SEC );
}