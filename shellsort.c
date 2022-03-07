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
        while (h < tam_vet)
            h = 3 * h + 1;
    while (1)
    {
        h /= 3;
        if (h == 0)
            break;
        for (i = h; i < tam_vet; i += h)
        {
            aux = vet[i];
            for (j = i; j > 0; j -= h)
            {
                int comp = compare_suffix(aux, vet[j - h]);
                if (comp > 0)
                    break;
                vet[j] = vet[j - h];
            }
            vet[j] = aux;
        }
    }
}