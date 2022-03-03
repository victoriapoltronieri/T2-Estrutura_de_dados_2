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

    FILE* fp = fopen(argv[2], "r");
        if(fp == NULL){
            printf("ERRO: Arquivo não foi aberto\n");
        }
    if(argc != 5){
        printf("ERRO: Argumentos insuficientes!\n");
    }

    int tam_arq, i =0, espaco = 0;
    fscanf(fp, "%d\n", &tam_arq);

    char* texto = (char*)malloc(sizeof(char) * tam_arq);
    char leitura;
  
    while(fscanf(fp, "%c", &leitura) != EOF){
        if(leitura != '\n' && leitura != ' ' && leitura != '\0'){
            texto[i] = leitura;
            espaco = 0;
            i++;
        }
        if((leitura == '\n' ||leitura == ' ' || leitura == '\0') && espaco == 0){
            if(leitura != '\0'){
                texto[i] = ' ';
                espaco++;
                i++;
            }
        }
    }

    String *s = create_string(texto);

    for(int i = 0; i < tam_arq; i++){
        Suffix *suf = create_suffix(s, i);
    }

    /*FILE* resp = fopen("resp.txt", "w");
    fprintf(resp, "%s", texto);
    fclose(resp);*/
    

    char* comandos = malloc(strlen(argv[1])* sizeof(char));
    i = 0;

    while (*argv[1] != '\0' ) {
        comandos[i] = *argv[1]; 
            argv[1]++ ; 
            i++;
    }

    char tipo_ordenacao = comandos[1];
    printf("%c", tipo_ordenacao);
    

    switch (comandos[1]){
    case 'a':
        break;
    
    case 'o':
        break;
    
    case 'r':
        break;
    
    case 'c':
        break;
    
    case 's':
        break;

    default:
        printf("ERRO: Comando não identificado.\n");
    }
    

    fclose(fp);
    free(comandos);
    return 0;
}