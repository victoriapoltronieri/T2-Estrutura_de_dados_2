#ifndef FUNCOES_LIB_H
#define FUNCOES_LIB_H

//organiza um vetor de sufixos de acordo com algoritmo de quick sort
void quicksort(Suffix** vet, int inicio, int fim);

//organiza um vetor de sufixos de acordo com algoritmo de heap sort
Suffix** heapsort(Suffix** vet, int tam_vetor);

//organiza um vetor de sufixos de acordo com algoritmo de shellsort
void shellsort(Suffix **vet, int tam_vet);

#endif