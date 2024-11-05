/*  Lista
**
**	---------------------------------------------------------------
**
**	Funcoes:
**	---------------------------------------------------------------
**
**      int listaVazia(NoLista *l); 
**
**               l	- cabeça da lista
**
**            retorna se a lista está vazia ou não.
**
**      ---------------------------------------------------------------
**
**      void insereInicio(NoLista **l, float i);
**
**                l	- cabeça da lista
**                i	- valor inserido
**
**            instancia um novo nó da lista e o insere o novo valor. 
**
**      ---------------------------------------------------------------
**
**      float retiraInicio(NoLista **l)
**
**                l	- cabeça da lista
**
**            se a lista não estiver vazia, retira o elemento do início da
**            lista e retorna seu valor. 
**
**      ---------------------------------------------------------------
**
**      void imprimeLista (NoLista *l) 
**
**                l	- cabeça da lista
**
**            imprime os elementos da lista.
**
*/

/*
**	---------------------------------------------------------------
**	Definicoes e variaveis globais:
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*
**	---------------------------------------------------------------
**	Implementacao das funcoes comeca aqui:
*/

/*=========================  listaVazia  =========================*/

int listaVazia(NoLista *l) 
{
    return (l == NULL);
}

/*=========================  insereInicio  =========================*/

void insereInicio(NoLista **l, float i)
{
    NoLista *ln = (NoLista*)malloc(sizeof(NoLista));
    ln->info = i;
    ln->prox = *l;
    *l = ln;
}

/*=========================  retiraInicio  =========================*/

float retiraInicio(NoLista **l)
{
    if (!listaVazia(*l)) {
       float info = (*l)->info;

       NoLista *tmp = *l;
       *l = (*l)->prox;
       free(tmp);

       return info;
    }
}

/*=========================  imprimeLista  =========================*/

void imprimeLista (NoLista *l) 
{
    if (!listaVazia(l)) {
        NoLista *tmp = l;

        while (tmp != NULL) {
            printf ("\nElemento: %f", tmp->info);
            tmp = tmp->prox;
        }
    }
}