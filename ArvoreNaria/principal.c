/*  Arvore n-Aria
**
**	---------------------------------------------------------------
*/

/*
**	---------------------------------------------------------------
**	Definicoes e variaveis globais:
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvvar.h"

/*
**	---------------------------------------------------------------
**	Implementacao das funcoes comeca aqui:
*/

/*=========================  main  =========================*/

void main (void) {

    printf("\n------teste de arvore------\n");
    printf("            a\n          / | \\\n         b  f  g\n        / \\   / \\\n       c   e  h  i\n       |         |\n       d         j\n");

    /* Cria nós como folhas */
    ArvVar* a = arvv_cria('a');
    ArvVar* b = arvv_cria('b');
    ArvVar* c = arvv_cria('c');
    ArvVar* d = arvv_cria('d');
    ArvVar* e = arvv_cria('e');
    ArvVar* f = arvv_cria('f');
    ArvVar* g = arvv_cria('g');
    ArvVar* h = arvv_cria('h');
    ArvVar* i = arvv_cria('i');
    ArvVar* j = arvv_cria('j');

    /* monta a hierarquia */
    arvv_insere(c,d);
    arvv_insere(b,e);
    arvv_insere(b,c);
    arvv_insere(i,j);
    arvv_insere(g,i);
    arvv_insere(g,h);
    arvv_insere(a,g);
    arvv_insere(a,f);
    arvv_insere(a,b);

    /* conferindo se o caracter k e d pertencem à árvore principal a*/
    printf("\n------arvv_pertence------\n");
    printf("Arvore a e caracter k: %i\n", arvv_pertence(a, 'k')); // resulta em 0 (não pertence)
    printf("Arvore a e caracter d: %i\n", arvv_pertence(a, 'd')); // resulta em 1 (pertence)

    /* conferindo o número de folhas da árvore principal */
    printf("\n------arvv_folhas------\n");
    printf("Arvore a: %i\n", arvv_folhas(a)); // resulta em 5

    /* conferindo a altura da árvore principal */
    printf("\n------arvv_altura------\n");
    printf("Arvore a: %i\n", arvv_altura(a)); // resulta em 3

    /* comparando se as árvores são iguais */
    printf("\n------arvv_igual------\n");
    printf("Arvore a e h: %i\n", arvv_igual(a, h)); // resulta em 0
    printf("Arvore a e a: %i\n", arvv_igual(a, a)); // resulta em 1

    /* copiando a árvore principal */
    printf("\n------arvv_copia------\n");
    ArvVar * anova;
    anova = arvv_copia(a);
    printf("Igualdade entre arvore a e arvore anova: %i\n\n", arvv_igual(a, anova)); // resulta em 1

    /* liberando toda a memória da árvore principal */
    arvv_libera(a);
}