#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "suffix.h"
#include "str.h"

int main(int argc, char** argv){
    /*
    argv[0] == executável
    argv[1] == instrução
        Instruções possíveis de execução: 
            (a) Processa o texto e imprime o array de sufixos;
            (o) Processa o texto e imprime o array de sufixos ordenado;
            (r) Processa o texto, produz o array de sufixo, ordena usando dois (ou mais) métodos e imprime o tempo de ordenação para cada método;
            (c) Dado um contexto e uma query, imprime as ocorrências encontradas
            (s) Dado um contexto, lê queries do teclado e imprime as ocorrências encontradas, até que uma string vazia seja informada.
    

    argv[2] == caminho da entrada de teste
    argv[3] == contexto - tamanho de caracteres considerados
    argv[4] == query, a ser buscada
    */
    if(argc != 5){
        printf("ERRO: Argumentos insuficientes!");
    }

    char* comandos = malloc(strlen(argv[1])* sizeof(char));
    int i = 0;

    while (*argv[1] != '\0' ) {
        comandos[i] = *argv[1]; 
            argv[1]++ ; 
            i++;
    }

    char tipo_ordenacao = comandos[1];
    printf("%c", tipo_ordenacao);
    

    /*switch (comandos[1]){
    case /* constant-expression */:
        /* code 
        break;
    
    default:
        break;
    }*/


    

    
    free(comandos);
    return 0;
}