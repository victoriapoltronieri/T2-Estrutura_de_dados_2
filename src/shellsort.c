#include "suffix.h"
#include "str.h"
#include <string.h>
#include "ordena.h"
#include <stdio.h>
#include <stdlib.h>

void shellsort(Suffix **vet, int tam_vet)
{
    unsigned long int h = 1, i, j, m, loop;
    Suffix *aux;
    if (tam_vet > 1)
        while (h < tam_vet) // inicializa a variavel h, seu valor depende do tamanho do vetor
            h = 3 * h + 1;
    while (1)
    { // while infinito que irá acabar quando h igual a zero de acordo com a divisão de inteiros em c, 1/3=0;
        h /= 3;
        if (h == 0)
            break;
        for (i = h; i < tam_vet; i += h) // loop que irá movimentar o pivo h casas
        {
            aux = vet[i];
            for (j = i; j > 0; j -= h)//loop que irá fazer a comparação se o valor ques está no pivo é maior do que os anteriores
            {
                int comp = compare_suffix(aux, vet[j - h]);
                if (comp > 0)
                    break;
                vet[j] = vet[j - h]; //troca caso comp for maior q 0
            }
            vet[j] = aux;
        }
    }
}