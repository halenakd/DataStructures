/*
**       arvvar.h:   Definicoes para arvore n-arias.
**
*/

#ifndef _arvvar_h
#define _arvvar_h

struct arvvar {
    char info;
    struct arvvar* prim;
    struct arvvar* prox;
};

typedef struct arvvar ArvVar;

/* prototipo das funcoes */

ArvVar* arvv_cria(char c);
void arvv_insere(ArvVar* a, ArvVar* sa);
int arvv_pertence(ArvVar* a, char c);
void arvv_libera(ArvVar* a);
int arvv_folhas(ArvVar* a);
int arvv_altura(ArvVar* a);
int arvv_igual(ArvVar * a1, ArvVar* a2);
ArvVar* arvv_copia(ArvVar* a);

#endif