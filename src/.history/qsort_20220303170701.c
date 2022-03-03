#include "suffix.h"
#include "str.h"
#include "ordena.h"
#include <stdio.h>
#include <stdlib.h>

void quicksort(Suffix** suf, int inicio, int fim){
    int esq = inicio;
    int dir = fim;
    Suffix pivot = suf[esq];

    //Os números à direita devem ser os menores e os à esquerda os maiores
    if(inicio < fim){
        while(esq < dir){
            //Começa a verificação da direita para esquerda
            //Os números da direita devem ser menores que os da esquerda
            //Caso o numero da direita seja menor que o pivô, está ok; passa para o número do lado à direita
            //esq deve ser menor que dir, se não for significa que dir "está na posição à esquerda de" esq
            while(vet[dir] >= pivot && esq < dir){
                dir--;
            }
            //vet[esq] vai receber o número de vet[dir] quando o número a direita for maior que o pivô
            vet[dir] = vet[esq];
            
            
            //Verifica se os números que estão à esquerda são maiores que o pivô, como deve ser
            while(vet[esq] <= pivot && esq < dir){
                esq++;
            } 
            //Caso o número à esquerda não seja maior que o pivô, a última posição verificada à direita, recebe esse número  
            vet[esq] = vet[dir];
        }

        //A última posição à esquerda recebe o pivô pq já tem certeza que as posições menores são maiores
        vet[dir] = pivot;

        //a verificação para ordenar os números do inicio do vetor até a posição do vetor antes do pivô
        //Todos à esquerda do pivô são maiores que ele, mas não estão necessariamente ordenados
        quicksort(suf, inicio, esq - 1); 
        //a verificação para ordenar os números do inicio do vetor até a posição do vetor antes do pivô
        //Todos à direita do pivô são menores que ele, mas não estão necessariamente ordenados
        quicksort(suf, dir + 1, fim);
    }
}