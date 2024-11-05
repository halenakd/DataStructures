#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include <time.h>

int listaVazia (plista l) {

    return (l->dimensao == 0);
}

void criarLista (pplista l) {
    *l = (struct lista*)malloc(sizeof(struct lista)); // mudei a forma de declaracao do malloc e resolveu o segmentation fault
    (*l)->inicio = NULL;
    (*l)->final = NULL;
    (*l)->dimensao = 0;
}

void inserirInicio (pplista l, int d, char * n) {

    pbloco b = (bloco *) malloc (sizeof(bloco));
    b->numero = d;
    b->nome = n;

    if ((*l)->dimensao != 0) {
        b->prox = (*l)->inicio;
        (*l)->inicio = b;
        (*l)->final->prox = b;   
    }
    else {
        b->prox = b;
        (*l)->inicio = b;
        (*l)->final = b;
    }
    
    (*l)->dimensao+= 1;
}

void inserirFinal (pplista l, int d, char * n) {

    bloco *b = (bloco *)malloc(sizeof(bloco));
    b->numero = d;
    b->nome = n;

    if ((*l)->dimensao != 0) {
        b->prox = (*l)->inicio;
        (*l)->final->prox = b;
        (*l)->final = b;
    }
    else {
        b->prox = b;
        (*l)->inicio = (*l)->final = b;
    }

    (*l)->dimensao++;
}

void inserirPosK (pplista l, int p, int d, char * n) {

    if ((*l)->dimensao > 0) {
        if (p == 1)
           inserirInicio(l, d, n);
        else {
            if (p > (*l)->dimensao)
               inserirFinal(l, d, n);
            else {
               int pos = 1;
               bloco *tmp = (*l)->inicio;
               bloco *ant = NULL;
               bloco *b = (bloco *)malloc(sizeof(bloco));

               b->numero = d;
               b->nome = n;
               b->prox = NULL;

               while (pos < p) {
                 ant = tmp;
                 tmp = tmp->prox;
                 pos++;
               }
    
               ant->prox = b;
               b->prox = tmp;
               (*l)->dimensao++;
            }
        }
    }
    else
       inserirInicio(l, d, n);
}

int removerInicio (pplista l) {
    if ((*l)->dimensao > 0) {
        int numero = (*l)->inicio->numero;
        bloco *tmp = (*l)->inicio;

        if ((*l)->inicio != (*l)->final) {
           (*l)->inicio = (*l)->inicio->prox;
           (*l)->final->prox = (*l)->inicio;
        }
        else
            (*l)->inicio = (*l)->final = NULL;

        free(tmp);
        (*l)->dimensao--;
        return numero;
    }
}

int removerFinal (pplista l) {
    if ((*l)->dimensao > 0) {
        int numero;
    
        if ((*l)->dimensao == 1)
           numero = removerInicio(l);
        else {
            bloco *tmp = (*l)->inicio;
            bloco *ant = NULL;

            while (tmp->prox != (*l)->inicio) {
                ant = tmp;
                tmp = tmp->prox;
            }

            ant->prox = (*l)->inicio;
            numero = tmp->numero;
            free(tmp);
            (*l)->dimensao--;
        }

        return numero;
    }
}

int removerPosK (pplista l, int p) {

    if ((*l)->dimensao > 0) {
        int numero;
        if (p == 1)
           numero = removerInicio(l);
        else {
            if (p > (*l)->dimensao)
               numero = removerFinal(l);
            else {
                int pos = 1;
                bloco *tmp = (*l)->inicio;
                bloco *ant = NULL;

                while (pos < p) {
                    ant = tmp;
                    tmp = tmp->prox;
                    pos++;
                }

                numero = tmp->numero;
                ant->prox = tmp->prox;
                (*l)->dimensao--;
                free(tmp);
            }
        }

        return numero;
    }
}

void imprimirLista (plista l) {

    if (l->dimensao > 0) {
        int i = 1;
        bloco *tmp = l->inicio;

        while (i < l->dimensao) {
            printf ("%s, ", tmp->nome);
            tmp = tmp->prox;
            i++;
        }
        printf("%s.\n", tmp->nome);
    }
}