#ifndef _lista_h
#define _lista_h

#include "info.h"

int listaVazia (plista l);
void criarLista (pplista l);
void destruirLista (pplista l);
void inserirInicio (pplista l, int d, char * n);
void inserirFinal (pplista l, int d, char * n);
void inserirPosK (pplista l, int p, int d, char * n);
int removerInicio (pplista l);
int removerFinal (pplista l);
int removerPosK (pplista l, int p);
void inserirOrdenado(pplista l, int d, char * n);
void imprimirLista (plista l);

#endif