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
            
            while(comp <= 0 && init < end){ // pivot é maior 
                /*int index1 = esq[init]->index;
                int index2 = pivot->index;
                comp = strcmp(esq[init]->s->c + index1, pivot->s->c + index2);*/
                comp = compare_suffix(esq[init], pivot);
                if(comp == 1){ // segunda é maior ou igual
                    init++;
                }   
            }

            dir[end] = esq[init]; //troca as strings

            while(comp > 0 && init < end){
                /*int index1 = dir[end]->index;
                int index2 = pivot->index;
                comp = strcmp(dir[end]->s->c + index1, pivot->s->c + index2);*/
                comp = compare_suffix(dir[end], pivot);
                if(comp > 0){ // primeira é maior
                    end--;
                }
            }
            esq[init] = dir[end];
        }
        //dir[end] = pivot;
        vet[end] = pivot;
        quicksort(vet, inicio, end-1);
        quicksort(vet, init+1, fim);
    }
}