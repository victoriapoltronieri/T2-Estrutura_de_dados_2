#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "suffix.h"
#include "str.h"
#include "ordena.h"
#include "search.h"

void search(Suffix **suf, int context, int lgt, char *key){
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
            }
        }
        if(verificador==0){ //imprime de acordo com o contexto
            if(a>context && context+aux->len+suf[i]->index <= suf[i]->s->len)
                print_substring(suf[i]->s, a - context, a + context + aux->len);
        }

    }
    destroy_string(aux);
}