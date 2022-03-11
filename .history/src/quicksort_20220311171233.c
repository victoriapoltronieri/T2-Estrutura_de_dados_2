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
                comp = compare_suffix(esq[init], pivot);
                if(comp == 0){ // segunda é maior ou igual
                    init++;
                }   
            }

            dir[end] = esq[init]; //troca as strings

            while(comp > 0 && init < end){
                comp = compare_suffix(dir[end], pivot);
                if(comp > 0){ // primeira é maior
                    end--;
                }
            }
            esq[init] = dir[end];
        }
        vet[end] = pivot;
        quicksort(vet, inicio, end-1);
        quicksort(vet, init+1, fim);
    }
}