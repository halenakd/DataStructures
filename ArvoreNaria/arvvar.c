/*  Arvore n-Aria
**
**	---------------------------------------------------------------
**
**	Funcoes:
**	---------------------------------------------------------------
**
**      ArvVar* arvv_cria(char c);
**
**                c	- caracter inserido
**
**            esta função cria um nó folha e retorna seu endereço de memória.
**            Sendo um nó folha, seus ponteiros para prim e prox devem ser 
**            inicializadas como NULL
**
**      ---------------------------------------------------------------
**
**      void arvv_insere(ArvVar* a, ArvVar* sa);
**
**                a	- arvore
**                sa - sub-arvore
**
**            insere uma sub-árvore sa como filha de um dado nó a.
**
**      ---------------------------------------------------------------
**
**      void arvv_imprime(ArvVar* a);
**
**                a	- arvore
**
**            deve imprimir a árvore em pré-ordem (primeiro o nó raiz, e 
**            depois cada uma das sub-árvores).
**
**      ---------------------------------------------------------------
**
**      int arvv_pertence(ArvVar* a, char c);
**
**                a - arvore
**                c	- caracter inserido
**
**            retorna 1 caso o caracter c estiver contido na árvore, e 
**            retorna 0 caso contrário.
**
**      ---------------------------------------------------------------
**
**      void arvv_libera(ArvVar* a);
**
**                a	- arvore
**
**            libera a memória alocada pela árvore.
**
**      ---------------------------------------------------------------
**
**      int arvv_folhas(ArvVar* a);
**
**                a	- arvore
**
**            retorna a quantidade de nós folha da árvore.
**
**      ---------------------------------------------------------------
**
**      int arvv_altura(ArvVar* a);
**
**                a	- arvore
**
**            retorna a altura da árvore (0 para árvore vazia).
**
**      ---------------------------------------------------------------
**
**      int arvv_igual(ArvVar * a1, ArvVar* a2);
**
**                a1	- arvore 1
**                a2	- arvore 2
**
**            retorna 1 se as árvores a1 e a2 são iguais. Retorna 0 caso
**            contrário. As duas árvores são iguais se seus nós armazenarem
**            informações iguais nas mesmas posições.
**
**      ---------------------------------------------------------------
**
**      ArvVar* arvv_copia(ArvVar* a);
**
**                a	- arvore
**
**            retorna uma cópia da árvore a. A nova árvore deve ter novos
**            nós instanciados.
**
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

/*=========================  arvv_cria  =========================*/

ArvVar* arvv_cria(char c)
{
    ArvVar * av = (ArvVar*)malloc(sizeof(ArvVar));
    av->info = c;
    av->prim = NULL;
    av->prox = NULL;
    return av;
}

/*=========================  arvv_insere  =========================*/

void arvv_insere(ArvVar* a, ArvVar* sa)
{
    sa->prox = a->prim;
    a->prim = sa;
}

/*=========================  arvv_pertence  =========================*/

int arvv_pertence(ArvVar* a, char c)
{
    if(a == NULL)
        return 0;
    return (a->info == c) || arvv_pertence(a->prim, c) || arvv_pertence(a->prox, c);
}

/*=========================  arvv_libera  =========================*/

void arvv_libera(ArvVar* a)
{
    if(a != NULL){
        arvv_libera(a->prim);
        arvv_libera(a->prox);
        a = NULL;
        free(a); 
    }
}

/*=========================  arvv_folhas  =========================*/

int arvv_folhas(ArvVar* a)
{
    if(a != NULL) {
        if(a->prim == NULL) {
            return +1 + arvv_folhas(a->prox);
        }
        else {
            return arvv_folhas(a->prim) + arvv_folhas(a->prox);
        }
    }
    return 0;
}

/*=========================  arvv_altura  =========================*/

int arvv_altura(ArvVar* a)
{
    int hmax = -1;
    ArvVar * p = a->prim;
    while(p != NULL) {
        int h = arvv_altura(p);
        if(h > hmax) {
            hmax = h;
        }
        p = p->prox;
    }
    return hmax + 1;
}

/*=========================  arvv_igual  =========================*/

int arvv_igual(ArvVar * a1, ArvVar* a2)
{
    if(a1 == NULL && a2 == NULL) return 1;
    if((a1 == NULL && a2 != NULL) || (a1 != NULL && a2 == NULL)) return 0;
    else {
        if(a1->info != a2->info) 
            return 0;
        else
            return arvv_igual(a1->prim, a2->prim), arvv_igual(a1->prox, a2->prox);
    }
}

/*=========================  arvv_copia  =========================*/

ArvVar* arvv_copia(ArvVar* a)
{
    if(a != NULL) {
        ArvVar * anova;
        anova = arvv_cria(a->info);
        if(a->prim != NULL){
            arvv_copia(a->prim); 
        }
        else if(a->prox != NULL) {
            arvv_copia(a->prox);
        }
        return anova;
    }
}