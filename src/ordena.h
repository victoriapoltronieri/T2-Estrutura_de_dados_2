#ifndef FUNCOES_LIB_H
#define FUNCOES_LIB_H

void quicksort(Suffix** suf, int inicio, int fim);

Suffix** heapsort(Suffix** vet, int tam_vetor);

void criaHeap(Suffix** vet, int inicio_vet, int tam_vetor);

void shellsort(Suffix **vet, int tam_vet);

#endif