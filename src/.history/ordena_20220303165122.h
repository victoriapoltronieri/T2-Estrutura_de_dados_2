#ifndef FUNCOES_LIB_H
#define FUNCOES_LIB_H

void quicksort(int* vet, int inicio, int fim,unsigned long int *troca,unsigned long int *comp);

Suffix** heapsort(Suffix** vet, int tam_vetor);

void criaHeap(Suffix** vet, int inicio_vet, int tam_vetor);

#endif