#include <stdio.h>
#include <stdlib.h>
#include "str.h"
#include "suffix.h"

Suffix* create_suffix(String *s, int index){
    Suffix* suf = (Suffix*)malloc(sizeof(Suffix));
    suf->s = s;
    suf->index = index;
    return suf;
}


Suffix** create_suf_array(String* text, int N){
    Suffix** suf = (Suffix** )malloc(sizeof(Suffix* ) *N);
    for(int i = N-1; i >= 0; i--){
        suf[i] = create_suffix(text, N-i);
    }
    return suf;
}

void destroy_suffix(Suffix* suf){
    if(suf->s != NULL) destroy_string(suf->s);
    free(suf);
}

void destroy_suf_array(Suffix** a, int N){
    
    for(int i = 0; i < N; i++){
        destroy_suffix(a[i]);
    }
}

void print_suf_array(Suffix** a, int N){
    print_suffix(a[N]);
}

void print_suffix(Suffix* suf){
    print_string(suf->s);
}

// Use uma (ou mais) funcoes deste tipo para ordenar
// o arry de sufixos usando o qsort e outro metodo de sua escolha
void sort_suf_array(Suffix** a, int N){

}

int rank(Suffix** a, int N, String *query){
    
}