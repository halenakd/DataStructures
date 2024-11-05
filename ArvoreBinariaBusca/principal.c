#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arvbb.h"

void main (void) {

    printf("\n------teste da arvore binaria de busca------\n");

    /* criando a arvore e inserindo elementos */
    Arv *a;
    a = abb_cria();
    a = abb_insere(a, 3);
    a = abb_insere(a, 4);
    a = abb_insere(a, 10);
    a = abb_insere(a, 0);
    a = abb_insere(a, 2);
    a = abb_insere(a, 9);
    a = abb_insere(a, 7);
    a = abb_insere(a, 1);

    /* imprimindo a arvore */
    printf("\n------cria, insere e imprime------");
    printf("\nOrdem crescente\n");
    abb_imprime(a); // resulta em 0 1 2 3 4 7 9 10
    printf("\nOrdem decrescente\n");
    abb_imprimeDecrescente(a); // resulta em 10 9 7 4 3 2 1 0
    printf("\n");

    /* buscando elementos na arvore */
    printf("\n------busca------\n");
    Arv *a2 = abb_busca(a, 2); // resulta no endereco do no
    if(a2 == NULL) {
        printf("O elemento 2 nao foi encontrado\n");
    }
    else {
        printf("No do elemento 2: ");
        abb_imprime(a2);
        printf("\n");
    }
    Arv *a9 = abb_busca(a, 9); // resulta no endereco do no 
    if(a9 == NULL) {
        printf("O elemento 9 nao foi encontrado\n");
    }
    else {
        printf("No do elemento 9: ");
        abb_imprime(a9);
        printf("\n");
    }
    Arv *a11 = abb_busca(a, 11); // resulta em NULL
    if(a11 == NULL) {
        printf("O elemento 11 nao foi encontrado\n");
    }
    else {
        printf("No do elemento 11: ");
        abb_imprime(a11);
        printf("\n");
    }

    /* removendo elementos da arvore */
    printf("\n------retira------\n");
    a = abb_retira(a, 4);
    a = abb_retira(a, 9);
    printf("Arvore sem os elementos 4 e 9: ");
    abb_imprime(a); // resulta em 0 1 2 3 7 10
    printf("\n");
}