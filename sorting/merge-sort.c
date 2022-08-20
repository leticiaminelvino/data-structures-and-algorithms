#include <stdio.h>
#include <time.h>
#include "acessory-functions.h"

void merge(int arr[], int p, int q, int r, int *compara, int *movimenta);
void mergeSort(int arr[], int l, int r, int *compara, int *movimenta);


void mergeSort(int arr[], int l, int r, int *compara, int *movimenta){

  if (l < r){
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m, compara, movimenta);
    mergeSort(arr, m + 1, r, compara, movimenta);
    // Merge the sorted subarrays
    merge(arr, l, m, r, compara, movimenta);
  }
}


void merge(int arr[], int p, int q, int r, int *compara, int *movimenta) {
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], M[n2];
  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];
  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    (*compara)++;
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
      (*movimenta)++;
    } else {
      arr[k] = M[j];
      j++;
      (*movimenta)++;
    }
    k++;
  }
  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    (*movimenta)++; 
    i++;
    k++;
  }
  while (j < n2) {
    arr[k] = M[j];
    (*movimenta)++;
    j++;
    k++;
  }
}



int main(){
    time_t t;

    int arr[] = {3, 4, 2, 5, 1, 7, 6, 9, 8},
        size = sizeof(arr) / sizeof(arr[0]),
        arrcopy[size];

    int compara = 0,
        movimenta = 0;

    int l = 0,
        r = size - 1;


    copyArray(arr, arrcopy, size);

    t = clock();
    mergeSort(arrcopy, l, r, &compara, &movimenta);
    t = clock() - t;

    printf("merge sort:\n");

    printArray(arr, size);
    printArray(arrcopy, size);
    printf("%d comparações\n", compara);
    printf("%d movimentações\n", movimenta);
    printf("%d clicks (%f seconds)\n",t, ((float)t)/CLOCKS_PER_SEC);
    
  return 0;
}