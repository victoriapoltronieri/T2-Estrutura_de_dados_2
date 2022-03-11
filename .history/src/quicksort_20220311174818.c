#include "suffix.h"
#include "str.h"
#include "ordena.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quicksort(Suffix** vet, int inicio, int fim){
    int init = inicio, end = fim;
    int comp;
    Suffix** esq = vet;
    Suffix** dir = vet;
    Suffix* pivot = vet[fim];

    if(inicio < fim){
        while(init < end){
            comp = 0;
            
            //nesse loop o pivot deve ser sempre maior
            //os sufixos que estiverem à esquerda devem ser menores que o pivot, caso contrário, troca
            while(comp <= 0 && init < end){ // enquanto pivot é maior e a posição a esquerda é menor que a da direita
                comp = compare_suffix(esq[init], pivot);
                if(comp == 0){ // segunda (pivot) é maior ou igual
                    init++;
                }   
            }

            dir[end] = esq[init]; //troca as strings de posição
            //dessa forma, se o sufixo for maior que o pivô ele vai pro lado direito

            //verifica os sufixos à direita; eles devem ser maiores que o pivot
            while(comp > 0 && init < end){ // comparações
                comp = compare_suffix(dir[end], pivot);
                if(comp > 0){ // primeira é maior
                    end--;
                }
            }
            esq[init] = dir[end]; // troca as strings
            //dessa forma, se o sufixo for menor que o pivô ele vai pro lado esquerdo

        }
        vet[end] = pivot;
        quicksort(vet, inicio, end-1);
        quicksort(vet, init+1, fim);
    }
}