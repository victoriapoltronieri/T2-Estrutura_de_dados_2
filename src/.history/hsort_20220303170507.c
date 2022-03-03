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
    Suffix* aux = vet[inicio_vet];
    int j = inicio_vet * 2 + 1; //primeiro filho; j + 1 == segundo filho
    
    //Enquanto o filho estiver dentro do vetor, continua a verificação do tamanho dos filhos
    while(j <= tam_vetor){
        if(j < tam_vetor){
            //if(vet[j] < vet[j + 1]){
            //    j = j + 1;
            //}
            for(int k = 0; k < vet[j].index; i++){
                if((vet[j].s->c + ((vet[j].s->len-vet[j].index)+k)) < (vet[j+1].s->c + ((vet[j].s->len-vet[j].index) + k))){
                    j = j + 1;
                    break;
                }
            }
        }

        if(aux < vet[j]){
            vet[inicio_vet] = vet[j];
            inicio_vet = j;
            j = inicio_vet * 2 + 1;
        }

        else{
            j = tam_vetor + 1;
        }
    }
    vet[inicio_vet] = aux;
}