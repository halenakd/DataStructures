/*
**       pilha.h:   Definicoes para pilhas.
**
*/

#ifndef _pilha_h
#define _pilha_h

#include "lista.h"

struct pilha {
    NoLista *topo;
};

typedef struct pilha Pilha;

/* prototipo das funcoes */

Pilha *pilha_cria();
void pilha_push(Pilha *p, float v);
float pilha_pop(Pilha *p); 
int pilha_vazia(Pilha *p); 
void pilha_libera(Pilha *p);
void pilha_imprime(Pilha *p);

#endif