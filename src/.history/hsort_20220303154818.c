#include "suffix.h"
#include "str.h"
#include "ordena.h"
#include <stdio.h>
#include <stdlib.h>

int* heapsort(int *vet, int tam_vetor, unsigned long int* troca, unsigned long int* comp){
    int i;
    //? cria uma heap com os dados do vetor; não está ordenado
    for(i = (tam_vetor/2) - 1; i >= 0; i--){ 
        //vet = criaHeap(vet, i, tam_vetor-1);
        criaHeap(vet, i, tam_vetor, troca, comp); 
    }

    int aux;
    //? ordena a heap; os maiores valores ficam no topo
    for(i = tam_vetor-1; i >= 0; i--){
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        *troca +=1;
        //refaz a heap colocando os menores valores nas últimas posições
        criaHeap(vet, 0, i, troca, comp);
    }

    return vet;
}

void criaHeap(int *vet, int inicio_vet, int tam_vetor, unsigned long int* troca, unsigned long int* comp){
    int menor = inicio_vet;
    int esq = inicio_vet * 2 + 1; //primeiro filho 
    int dir = inicio_vet * 2 + 2; // segundo filho

    //Caso o filho da esquerda, filho 1, seja menor que o menor
    if(esq < tam_vetor && vet[esq] < vet[menor]){
        menor = esq;
        *comp += 1;
    }

    if(dir < tam_vetor && vet[dir] < vet[menor]){
        menor = dir;
        *comp += 1;
    }

    if(menor != inicio_vet){
        int aux = vet[inicio_vet];
        vet[inicio_vet] = vet[menor];
        vet[menor] = aux;
        *troca += 1;

        criaHeap(vet, menor, tam_vetor, troca, comp);
    }
}

