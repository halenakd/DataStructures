/*  Arvore Binaria
**
**	---------------------------------------------------------------
**
**	Funcoes:
**	---------------------------------------------------------------
**
**      Arv* arv_criavazia(void);
**
**            instancia uma nova árvore binária vazia. Esta função 
**            simplesmente deve retornar NULL.
**
**      ---------------------------------------------------------------
**
**      Arv* arv_cria(char c, Arv* e, Arv* d);
**
**                c	- caracter inserido
**                e	- sa da esquerda
**                d	- sa da direita
**
**            instancia uma nova árvore. A função recebe ponteiros 
**            para as suas duas sub-árvores e a informação (char) a 
**            ser armazenada no nó raiz. A função deve retornar o 
**            endereço do novo nó raiz.
**
**      ---------------------------------------------------------------
**
**      Arv* arv_libera(Arv* a);
**
**                a	- arvore
**
**            libera toda a memória ocupada pela árvore (em outras 
**            palavras, “apaga” a árvore). 
**
**      ---------------------------------------------------------------
**
**      int arv_vazia(Arv* a);
**
**                a - arvore
**
**            retorna 1 ou 0 caso a árvore esteja vazia ou não, respectivamente.
**            arvore vazia retorna n-1.
**
**      ---------------------------------------------------------------
**
**      int arv_pertence(Arv* a, char c);
**
**                a	- arvore
**                c	- caracter inserido
**
**            retorna 1 caso o caracter c estiver contido na árvore,
**            e retorna 0 caso contrário. 
**
**      ---------------------------------------------------------------
**
**      void arv_imprime_pre(Arv* a);
**
**                a	- arvore
**
**            imprime a árvore em saída de texto em pré-ordem.
**
**      ---------------------------------------------------------------
**
**      void arv_imprime_sim(Arv* a);
**
**                a	- arvore
**
**            imprime a árvore em saída de texto em ordem simétrica.
**
**      ---------------------------------------------------------------
**
**      void arv_imprime_pos(Arv* a);
**
**                a	- arvore
**
**            imprime a árvore em saída de texto em pós-ordem.
**
**      ---------------------------------------------------------------
**
**      int arv_folhas(Arv* a);
**
**                a	- arvore
**
**            retorna a quantidade de nós folha da árvore.
**
**      ---------------------------------------------------------------
**
**      int arv_altura(Arv* a);
**
**                a	- arvore
**
**            retorna a altura da árvore (0 para árvore vazia).
**
**      ---------------------------------------------------------------
**
**      int arv_igual(Arv* a1, Arv* a2);
**
**                a1 - arvore 1
**                a2 - arvore 2
**
**            retorna 1 se as árvores a1 e a2 são iguais. Retorna 0
**            caso contrário. As duas árvores são iguais se seus
**            nós armazenarem informações iguais nas mesmas posições.
**
**      ---------------------------------------------------------------
**
**      Arv* arv_copia(Arv* a);
**
**                a	- arvore
**
**            retorna uma cópia da árvore a. A nova árvore deve ter 
**            novos nós instanciados.
**
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

/*=========================  arv_criavazia  =========================*/

Arv* arv_criavazia(void)
{
    /*Arv *a = (Arv*)malloc(sizeof(Arv));
    a->info = NULL;
    a->esq = NULL;
    a->dir = NULL;
    return a;*/
    return NULL;
}

/*=========================  arv_cria  =========================*/

Arv* arv_cria(char c, Arv* e, Arv* d)
{
    Arv *a = (Arv*)malloc(sizeof(Arv));
    a->info = c;
    a->esq = e;
    a->dir = d;
    return a;
}

/*=========================  arv_libera  =========================*/

Arv* arv_libera(Arv* a)
{
    if(!arv_vazia(a)){
        arv_libera(a->esq);
        arv_libera(a->dir);
        a = NULL;
        free(a); 
    }
    return a;
}

/*=========================  arv_vazia  =========================*/

int arv_vazia(Arv* a)
{
    /*if(a->info == NULL && a->dir == NULL && a->esq == NULL)
        return 1;
    return 0;*/
    return(a == NULL);
}

/*=========================  arv_pertence  =========================*/

int arv_pertence(Arv* a, char c)
{
    if(arv_vazia(a))
        return 0;
    return (a->info == c) || arv_pertence(a->esq, c) || arv_pertence(a->dir, c);
}

/*=========================  arv_imprime_pre  =========================*/

void arv_imprime_pre(Arv* a)
{
    printf("<");
    if(!arv_vazia(a)) {
        printf("%c", a->info);
        arv_imprime_pre(a->esq);
        arv_imprime_pre(a->dir);
    }
    printf(">");
}

/*=========================  arv_imprime_sim  =========================*/

void arv_imprime_sim(Arv* a)
{
    printf("<");
    if(!arv_vazia(a)) {
        arv_imprime_sim(a->esq);
        printf("%c", a->info);
        arv_imprime_sim(a->dir);
    }
    printf(">");
}

/*=========================  arv_imprime_pos  =========================*/

void arv_imprime_pos(Arv* a)
{
    printf("<");
    if(!arv_vazia(a)) {
        arv_imprime_pos(a->esq);
        arv_imprime_pos(a->dir);
        printf("%c", a->info);
    }
    printf(">");
}

/*=========================  arv_folhas  =========================*/

int arv_folhas(Arv* a)
{
    if(!arv_vazia(a)) {
        if(arv_vazia(a->dir) || arv_vazia(a->esq)) {
            return +1;
        }
        else {
            return arv_folhas(a->esq) + arv_folhas(a->dir);
        }
    }
    return 0;
}

/*=========================  arv_altura  =========================*/

int arv_altura(Arv* a)
{
    if(arv_vazia(a)) return -1;
    else {
        if(arv_altura(a->esq) > arv_altura(a->dir)) return 1 + arv_altura(a->esq);
        else return 1 + arv_altura(a->dir);
    }
}

/*=========================  arv_igual  =========================*/

int arv_igual(Arv* a1, Arv* a2)
{
    if(arv_vazia(a1) && arv_vazia(a2)) return 1;
    if((!arv_vazia(a1) && arv_vazia(a2)) || (arv_vazia(a1) && !arv_vazia(a2))) return 0;
    else {
        if(a1->info != a2->info) 
            return 0;
        else
            return arv_igual(a1->esq, a2->esq), arv_igual(a1->dir, a2->dir);
    }
}

/*=========================  arv_copia  =========================*/

Arv* arv_copia(Arv* a)
{
    if(!arv_vazia(a)){
        Arv * anova;
        if(!arv_vazia(a->esq) && !arv_vazia(a->dir)){
            anova = arv_cria(a->info, a->esq, a->dir);
            arv_copia(a->esq); 
            arv_copia(a->dir);
            return anova;
        }
    }
}
