#include <stdio.h>

void print_array(int vtr[], int tam);
void copy_array(int vtr[], int cpy[], int tam);
void swap(int *xp, int *yp);

void print_array(int vtr[], int tam){
  int i;
  printf("[");
  for (i = 0; i < tam; i++){
  ( i == tam-1 ) ? printf("%d", vtr[i]) : printf("%d, ", vtr[i]);
  }
  printf("]\n");
}

void copy_array(int vtr[], int cpy[], int tam){
  int i;
  for (i = 0; i < tam; ++i){
    cpy [i] = vtr[i];
  }
}

void swap(int *xp, int *yp){
  int aux = *xp;
  *xp = *yp;
  *yp = aux;
}