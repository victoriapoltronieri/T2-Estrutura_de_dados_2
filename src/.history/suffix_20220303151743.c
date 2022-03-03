#include <stdio.h>
#include <stdlib.h>
#include "str.h"
#include "suffix.h"

Suffix* create_suffix(String *s, int index){
    Suffix* suf = (Suffix*)malloc(sizeof(Suffix));
    suf->s = create_string(s);
    suf->index = index;
    return suf;
}


Suffix** create_suf_array(String *text, int N){
    Suffix *aux=(Suffix*)malloc(sizeof(Suffix)*N);
    for(int i = 0; i < N; i++, s->c++){
        creat_suffix(s->c, N-i);
    }
    return aux;
}

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