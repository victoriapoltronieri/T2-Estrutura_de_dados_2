#include "suffix.h"
#include "str.h"
#include "ordena.h"
#include <stdio.h>
#include <stdlib.h>

void quicksort(int* vet, int inicio, int fim, int *troca, int *comp){
    int pivot;

    if(fim > inicio){
        pivot = separa(vet, inicio, fim, &troca, &comp);
        quicksort(vet, inicio, pivot-1, troca, comp); // 
        quicksort(vet, pivot+1, fim, troca, comp);
    }
}

int separa(int* vet, int inicio, int fim, int **troca, int **comp){
    int esq = inicio;
    int dir = fim;
    int pivot = vet[inicio];

    while (esq < dir){
        //enquanto for menor que o pivô, está ok, já que os números da esquerda devem ser menores que o pivô
        while(vet[esq] <= pivot){
            **comp += 1;
            esq++;
        }
        //enquanto for maior que o pivô, está ok, já que os números da direita devem ser maiores que o pivô
        while(vet[dir] > pivot){ 
            **comp += 1;
            dir--;
        }

        //quando sair dos loops, caso a posição da direita seja maior que o da esquerda, significa que
        // ... o número da posição a esquerda é maior que o pivô. logo é preciso colocá-lo a direita do mesmo. 
        if(esq < dir){
           int aux = vet[esq];
           vet[esq] = vet[dir];
           vet[dir] = aux;
           **troca += 1;
        }
    }
    // o inicio passa a ser na posição pivô+1, já que tem-se certeza que à esquerda os números são menores
    vet[inicio] = vet[dir];
    vet[dir] = pivot;

    return dir; // passa a ser a posição do pivô
}