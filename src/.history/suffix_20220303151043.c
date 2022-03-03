#include <stdio.h>
#include <stdlib.h>
#include "str.h"
#include "suffix.h"

Suffix* create_suffix(String *s, int index){
    Suffix* suf;
    suf->s = s;
    suf->index = index;

    return suf;
}


/*
Suffix* create_suffix(String *s, int index){
    Suffix *aux=(Suffix*)malloc(sizeof(Suffix)*index);
    for(int i=0; i<index; i++, s->c++){
        aux[i].s=create_string(s->c);
        aux[i].index=index-i;
        printf("%s", s->c);
    }
    return aux;
}
*/
Suffix** create_suf_array(String *text, int N){
    
}

void destroy_suffix(Suffix *suf){
    destroy_string(suf->s);
    free(suf);
}

void destroy_suf_array(Suffix* *a, int N);

void print_suf_array(Suffix* *a, int N){
    print_suffix(a[N]);
}

void print_suffix(Suffix *suf){
    print_string(suf->s);
}

// Use uma (ou mais) funcoes deste tipo para ordenar
// o arry de sufixos usando o qsort e outro metodo de sua escolha
void sort_suf_array(Suffix* *a, int N);

int rank(Suffix* *a, int N, String *query);