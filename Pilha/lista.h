/*
**       lista.h:   Definicoes para listas simplesmente encadeadas (adpatado para pilhas).
**
*/

#ifndef _lista_h
#define _lista_h

struct noLista {
    float info;
    struct noLista *prox;
};

typedef struct noLista NoLista;

/* prototipo das funcoes */

int listaVazia(NoLista *l);
void insereInicio(NoLista **l, float i);
float retiraInicio(NoLista **l);
void imprimeLista (NoLista *l);

#endif