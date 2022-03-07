#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "suffix.h"
#include "str.h"
#include "ordena.h"

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
        printf("ERRO: Argumentos insuficientes!\n");
    }

    FILE* fp = fopen(argv[2], "r");
    if(fp == NULL){
        printf("ERRO: Arquivo não foi aberto\n");
    }

    int tam_arq, i =0, espaco = 0;
    fscanf(fp, "%d\n", &tam_arq);

    char* texto = (char*)malloc(sizeof(char) * tam_arq);
    char leitura;
  
    while(fscanf(fp, "%c", &leitura) != EOF){ // realiza leitura caracter por caracter
    // verifica se os caracteres são blankspaces repetidos; caso seja quebra de linha é ignorado
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


    char* comandos = malloc(strlen(argv[1])* sizeof(char));
    i = 0;
    while (*argv[1] != '\0' ) { //transforma -c em c para identificação do comando
        comandos[i] = *argv[1]; 
            argv[1]++ ; 
            i++;
    }

    char tipo_ordenacao = comandos[1];
    clock_t t; //variável para armazenar tempo
    double time;
    
    String *s =create_string(texto);
    

    switch (tipo_ordenacao){
    case 'a':{ //ok
        Suffix** suf = create_suf_array(s, tam_arq);
        print_suf_array(suf, tam_arq);
        free(suf);
        break;
    }
    
    case 'o':{ //ok
        Suffix** suf = create_suf_array(s, tam_arq);
        sort_suf_array(suf, tam_arq);
        print_suf_array(suf, tam_arq);
        free(suf);
        break;
    }
    case 'r':{
        
        Suffix** suf = create_suf_array(s, tam_arq);
        t = clock(); //!armazena tempo
        sort_suf_array(suf, tam_arq);
        t = clock() - t; //!tempo final - tempo inicial
        time = ((double)t)/((CLOCKS_PER_SEC)); //!tempo em segundos
        printf("System qsort	%f (s)\n", time);
        //print_suf_array(suf, tam_arq);


        Suffix **suf_quick= create_suf_array(s, tam_arq);
        t = clock(); //!armazena tempo   
        quicksort(suf_quick, 0, tam_arq-1);
        t = clock() - t; //!tempo final - tempo inicial
        time = ((double)t)/((CLOCKS_PER_SEC)); //!tempo em segundos
        printf("Quicksort	%f (s)\n", time);
        //print_suf_array(suf_quick, tam_arq);

        Suffix **suf_heap = create_suf_array(s, tam_arq);
        t = clock(); //!armazena tempo
        heapsort(suf_heap, tam_arq);
        t = clock() - t; //!tempo final - tempo inicial
        time = ((double)t)/((CLOCKS_PER_SEC)); //!tempo em segundos
        printf("Heapsort	%f (s)\n", time);
        //print_suf_array(suf_heap, tam_arq);

        Suffix **suf_shell=create_suf_array(s, tam_arq);
        t = clock(); //!armazena tempo
        shellsort(suf_shell, tam_arq);
        t = clock() - t; //!tempo final - tempo inicial
        time = ((double)t)/((CLOCKS_PER_SEC)); //!tempo em segundos
        printf("Shellsort	%f (s)\n", time);
        //print_suf_array(suf_shell, tam_arq);

        }
        break;
    
    case 'c':
        query = (char *)malloc(sizeof(char) * strlen(argv[4]));
        context = atoi(argv[3]);
        while (*argv[4] != '\0')
        {
            if (*argv[4] != '"')
                query[q] = *argv[4];
            argv[4]++;
            q++;
        }
        heapsort(suf, tam_arq);
        search(suf, context, tam_arq, query);
        break;
    
    case 's':
        heapsort(suf, tam_arq);
        context = atoi(argv[3]);
        
        while (1)
        {   
            printf("Insira uma query para busca sem aspas:\n");
            if(!(scanf("%[^\n]%*c", query_s)))break;
            search(suf, context, tam_arq, query_s);
        }
        break;

    default:
        printf("ERRO: Comando não identificado.\n");
    }

    fclose(fp);
    free(comandos);
    destroy_string(s);
    return 0;
}