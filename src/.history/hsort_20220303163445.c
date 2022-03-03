#include "suffix.h"
#include "str.h"
#include "ordena.h"
#include <stdio.h>
#include <stdlib.h>

/*Suffix** heapsort(Suffix **vet, int tam_vetor){
    int i;
    // cria uma heap com os dados do vetor; não está ordenado
    for(i = (tam_vetor/2) - 1; i >= 0; i--){ 
        criaHeap(vet, i, tam_vetor); 
    }

    suffix* aux;
    //? ordena a heap; os maiores valores ficam no topo
    for(i = tam_vetor-1; i >= 0; i--){
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        //refaz a heap colocando os menores valores nas últimas posições
        criaHeap(vet, 0, i);
    }
    return vet;
}

void criaHeap(Suffix** vet, int inicio_vet, int tam_vetor){
    int menor = inicio_vet;
    int esq = inicio_vet * 2 + 1; //primeiro filho 
    int dir = inicio_vet * 2 + 2; // segundo filho

    //Caso o filho da esquerda, filho 1, seja menor que o menor
    for(int i=0; i < vet[menor].s->c + vet[menor].s->index; i)
    if(esq < tam_vetor && vet[esq] < vet[menor]){
        menor = esq;
    }

    if(dir < tam_vetor && vet[dir] < vet[menor]){
        menor = dir;
    }

    if(menor != inicio_vet){
        int aux = vet[inicio_vet];
        vet[inicio_vet] = vet[menor];
        vet[menor] = aux;

        criaHeap(vet, menor, tam_vetor);
    }
}*/