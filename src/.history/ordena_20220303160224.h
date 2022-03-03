#ifndef FUNCOES_LIB_H
#define FUNCOES_LIB_H

void quicksort(int* vet, int inicio, int fim, int *troca, int *comp);

int* heapsort(Suffix** vet, int tam_vetor);

void criaHeap(Suffix** vet, int inicio_vet, int tam_vetor);

int separa(int* vet, int inicio, int fim, int **troca, int **comp);

#endif