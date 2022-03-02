#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "suffix.h"
#include "str.h"

int main(int argc, char** argv){
    if(argc != 5){
        printf("ERRO: Argumentos insuficientes!");
    }

    char* comandos = malloc(strlen(argv[1])* sizeof(char));

    while ( *argv[1] != '\0' ) {
        comandos[i] = *argv[1]; 
            argv[1]++ ; 
            i++;
    }
    

    

    return 0;
}