#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "suffix.h"
#include "str.h"
#include "ordena.h"
#include "search.h"

void search(Suffix **suf, int context, int lgt, char *key){
<<<<<<< HEAD
    int lgt_key = strlen(key);

    for (int i = 0; i < lgt && lgt_key > 0; i++){
        int a = (suf[i]->index);
        if (*(suf[i]->s->c + a) > *key)
            break;
        if (strncmp(suf[i]->s->c + a, key, lgt_key) == 0)
        {
            if (a > context && a < lgt - (lgt_key + context - 1))
            {
                print_substring(suf[i]->s, a - context, a + context + lgt_key);
=======
    String* aux=create_string(key);
    for(int i=0; i<lgt; i++){ // loop que ira varrer todos os sufixos
        int lgt;
        if(aux->len < suf[i]->s->len - suf[i]->index) lgt = aux->len; // compara para ver qual é o maior, a query ou o sufixo, o meior é usado no proximo loop
        else lgt = suf[i]->s->len - suf[i]->index;
        int a=suf[i]->index;
        int verificador=0;
        for(int j=0; j<lgt; j++){ // loop que irar varrer a menor palavra e comparar se a query esta presente em um dos sufixos
            if (toupper(suf[i]->s->c[j + a]) != toupper(aux->c[j])) {
                verificador=1;
                break;
>>>>>>> a0ceb2e372e4f69f06ab9ddeb57ac2d3a9a94ca7
            }
        }
        if(verificador==0){ //imprime de acordo com o contexto
            if(a>context && context+aux->len+suf[i]->index <= suf[i]->s->len)
                print_substring(suf[i]->s, a - context, a + context + aux->len);
        }

    }
<<<<<<< HEAD

    /*int lgt_key = strlen(key);

    for (int i = 0; i < lgt && lgt_key > 0; i++){
        int a = (suf[i]->index);
        for (int j = 0; j < lgt_key && lgt_key > 0; j++){
            /*if (*(suf[i]->s->c + a) > *key)
                break;
            if (*(suf[i]->s->c + a) == *(key+j)){
                a++;
            }
                if (a > context && a < lgt - (lgt_key + context - 1))
                {
                    print_substring(suf[i]->s, a - context, a + context + lgt_key);
                }
        }
    }*/




=======
    destroy_string(aux);
>>>>>>> a0ceb2e372e4f69f06ab9ddeb57ac2d3a9a94ca7
}