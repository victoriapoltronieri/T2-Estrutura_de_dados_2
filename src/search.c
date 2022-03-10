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
    for(int i=0; i<lgt; i++){
        int lgt;
        if(aux->len < suf[i]->s->len - suf[i]->index) lgt = aux->len;
        else lgt = suf[i]->s->len - suf[i]->index;
        int a=suf[i]->index;
        int verificador=0;
        for(int j=0; j<lgt; j++){
            if (toupper(suf[i]->s->c[j + a]) != toupper(aux->c[j])) {
                verificador=1;
                break;
            }
        }
        if(verificador==0){
            if(a>context && context+aux->len+suf[i]->index <= suf[i]->s->len)
                print_substring(suf[i]->s, a - context, a + context + aux->len);
        }

    }
    destroy_string(aux);
    /*int lgt_key = strlen(key);
    for (int i = 0; i < lgt && lgt_key > 0; i++){
        int a = (suf[i]->index);
        if (*(suf[i]->s->c + a) > *key)
            break;
        if (strncmp(suf[i]->s->c + a, key, lgt_key) == 0)
        {
            if (a > context && a < lgt - (lgt_key + context - 1))
            {
                print_substring(suf[i]->s, a - context, a + context + lgt_key);
            }
        }*/

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

}