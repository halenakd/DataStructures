/*  Arvore Binaria
**
**	---------------------------------------------------------------
*/

/*
**	---------------------------------------------------------------
**	Definicoes e variaveis globais:
*/

#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

/*
**	---------------------------------------------------------------
**	Implementacao das funcoes comeca aqui:
*/

/*=========================  main  =========================*/

void main (void) {

    printf("\n------teste de arvore------\n");
    printf("            a\n            /\\\n           e  d\n");

    // criando uma árvore a
    Arv *a;

    // criando sub-árvores esquerda e direita
    Arv *esq;
    Arv *dir;

    // criando sub-árvores vazias para as sub-árvores
    Arv *esq1 = arv_criavazia();
    Arv *esq2 = arv_criavazia();
    Arv *dir1 = arv_criavazia();
    Arv *dir2 = arv_criavazia();

    // preenchendo
    esq = arv_cria('e', esq1, esq2);
    dir = arv_cria('d', dir1, dir2);
    a = arv_cria('a', esq, dir);

    /* conferindo se a árvore principal e a sub-árvore 1
    da sub-árvore esquerda estão vazias */
    printf("\n------arv_vazia------\n");
    printf("arvore a: %i\n", arv_vazia(a)); // resulta em 0 (não está vazia)
    printf("Sub-arvore esq1: %i\n", arv_vazia(esq1)); // resulta em 1 (está vazia)

    /* conferindo se o caracter h e d pertence à árvore principal */
    printf("\n------arv_pertence------\n");
    printf("Arvore a e caracter h: %i\n", arv_pertence(a, 'h')); // resulta em 0 (não pertence)
    printf("Arvore a e caracter d: %i\n", arv_pertence(a, 'd')); // resulta em 1 (pertence)

    /* imprimindo a árvore principal */
    printf("\n------arv_imprime------\n");
    printf("\nPre-ordem: ");
    arv_imprime_pre(a); // pré-ordem: <a<e<><>><d<><>>>
    printf("\nOrdem simetrica: ");
    arv_imprime_sim(a); // ordem simétrica: <<e<><>>a<d<><>>>
    printf("\nPos-ordem: ");
    arv_imprime_pos(a); // pós-ordem: <<e<><>><d<><>>a>
    printf("\n");

    /* conferindo o número de folhas da árvore principal */
    printf("\n------arv_folhas------\n");
    printf("Arvore a: %i\n", arv_folhas(a)); // resulta em 2

    /* conferindo a altura da árvore principal */
    printf("\n------arv_altura------\n");
    printf("Arvore a: %i\n", arv_altura(a)); // resulta em 1

    /* comparando se as árvores são iguais */
    printf("\n------arv_igual------\n");
    printf("Arvore a e esq: %i\n", arv_igual(a, esq)); // resulta em 0
    printf("Arvore a e a: %i\n", arv_igual(a, a)); // resulta em 1

    /* copiando a árvore principal */
    printf("\n------arv_copia------\n");
    Arv * anova;
    anova = arv_copia(a);
    printf("Copia de a: ");
    arv_imprime_pre(anova); // resulta em <a<e<><>><d<><>>>
    printf("\n");
    printf("Igualdade entre arvore a e arvore anova: %i\n\n", arv_igual(a, anova)); // resulta em 1
    
    /* liberando toda a memória da árvore principal */
    arv_libera(a);
}
