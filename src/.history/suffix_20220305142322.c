#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    for(int i = 0; i < N; i++){
        suf[i] = create_suffix(text, i);
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
    for(int i = 0; i < N; i++){
        print_suffix(a[i]);
    }
}

void print_suffix(Suffix* suf){
    print_substring(suf->s, suf->index, suf->s->len);
}

int compare_suffix(Suffix* a, Suffix* b){
   /* int index1 = a->index;
    int index2 = b->index;
    int comp = strcmp(a->s->c + index1, b->s->c + index2);*/

    int comp = compare(a->s, b->s, a->index, b->index);
    if(comp <= 0){ // caso a segunda seja maior ou igual
        return 0;
    }
    else if(comp > 0){ // caso a primeira seja maior
        return 1;
    }
}

int sufcmp(const void * a, const void *b){
    Suffix* um = (Suffix*) a;
    Suffix* dois = (Suffix*) b;
    
    int comp = compare_suffix(um, dois);
    if(comp == -1){
        return -1;
    }
    else if(comp == 0){
        return 0;
    }
    else if(comp == 1){
        return 1;
    }

}

// Use uma (ou mais) funcoes deste tipo para ordenar
// o arry de sufixos usando o qsort e outro metodo de sua escolha
void sort_suf_array(Suffix** a, int N){
    printf("oi aqui\n");
    qsort(a, N, sizeof(Suffix*), sufcmp);
}

int rank(Suffix** a, int N, String *query){
    
}