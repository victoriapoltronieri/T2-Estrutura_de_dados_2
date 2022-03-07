#include "suffix.h"
#include "str.h"
#include "ordena.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Suffix **heapsort(Suffix **vet, int tam_vetor)
{
    int i;
    // cria uma heap com os dados do vetor; não está ordenado
    for (i = (tam_vetor - 1) / 2; i >= 0; i--)
    {
        criaHeap(vet, i, tam_vetor - 1);
    }

    Suffix *aux;
    //? ordena a heap; os maiores valores ficam no topo
    for (i = tam_vetor - 1; i >= 0; i--)
    {
        aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        // refaz a heap colocando os menores valores nas últimas posições
        criaHeap(vet, 0, i - 1);
    }
    return vet;
}

void criaHeap(Suffix **vet, int inicio_vet, int tam_vetor)
{
    Suffix *aux = vet[inicio_vet];
    int j = inicio_vet * 2 + 1;
    while (j <= tam_vetor)
    {
        if (j < tam_vetor)
        {
            int a = (vet[j]->index);
            int b = (vet[j + 1]->index);
            int comp = strcmp(vet[j]->s->c + a, vet[j + 1]->s->c + b);

            if (comp < 0)
            {
                j += 1;
            }
        }
        int a = (aux->index);
        int b = (vet[j]->index);
        int comp = strcmp(aux->s->c + a, vet[j]->s->c + b);
        
        if(comp<0){
            vet[inicio_vet]=vet[j];
            inicio_vet=j;
            j=2*inicio_vet+1;
        }else j=tam_vetor+1;
    }
    vet[inicio_vet]=aux;
}