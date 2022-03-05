#ifndef SUFFIX_H
#define SUFFIX_H

#include "str.h"

typedef struct {
    String *s; //ABRACADABRA
    int index; //4 
    //ISSO SIGNIFICA QUE O SUFIXO: CADABRA
} Suffix;

Suffix* create_suffix(String *s, int index);

Suffix** create_suf_array(String *text, int N);

void destroy_suffix(Suffix *suf);

void destroy_suf_array(Suffix* *a, int N);

void print_suf_array(Suffix* *a, int N);

void print_suffix(Suffix *suf);

int compare_suffix(Suffix* a, Suffix* b);

// Use uma (ou mais) funcoes deste tipo para ordenar
// o arry de sufixos usando o qsort e outro metodo de sua escolha
void sort_suf_array(Suffix* *a, int N);

int rank(Suffix* *a, int N, String *query);

#endif
