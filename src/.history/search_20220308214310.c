#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "suffix.h"
#include "str.h"
#include "ordena.h"
#include "search.h"

void search(Suffix **suf, int context, int lgt, char *key)
{
    int lgt_key = strlen(key);

    for (int i = 0; i < lgt && lgt_key > 0; i++){
        int a = (suf[i]->index);

        char c = toupper(*(suf[i]->s->c + a));

        //if (*(suf[i]->s->c + a) > *key)
        if (c > *key)
            break;
        //if (strncmp(suf[i]->s->c + a, key, lgt_key) == 0)
        if (strncmp(c, key, lgt_key) == 0)
        {
            if (a > context && a < lgt - (lgt_key + context - 1))
            {
                print_substring(suf[i]->s, a - context, a + context + lgt_key);
            }
        }
    }
}