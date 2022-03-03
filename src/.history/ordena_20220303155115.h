#ifndef FUNCOES_LIB_H
#define FUNCOES_LIB_H

void quicksort(int* vet, int inicio, int fim, int *troca, int *comp);

int* heapsort(int *vet, int tam_vetor, unsigned long int* troca, unsigned long int* comp);

void criaHeap(int *vet, int inicio_vet, int tam_vetor, unsigned long int* troca, unsigned long int* comp);

#endif