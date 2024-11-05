#ifndef _josephus_h
#define _josephus_h

#include "info.h"
#include "lista.h"

/*------JOSEPHUS------*/
bloco * sorteiaSoldadoInicial(pplista l);
int sorteiaNumeroChapeu(pplista l);
void removerElem(pplista l, char * elem);
bloco * removeSoldado(pplista l, bloco * soldadoInicial, int nChapeu);
void josephus (pplista l);

#endif