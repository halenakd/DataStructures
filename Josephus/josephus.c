#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "josephus.h"

/*----------------------JOSEPHUS----------------------*/

// sorteia um soldado para começar
bloco * sorteiaSoldadoInicial(pplista l)
{
    srand(time(NULL));
    bloco *soldadoInicial = (*l)->inicio; // a partir do começo da lista
    int n1 = rand() % (*l)->dimensao; // sorteia um numero para chegar no soldado que vai ser o inicio
    for(int i = 0; i < n1; i++) { // chega no soldado que vai ser o inicio
        soldadoInicial = soldadoInicial->prox;
    }
    //printf("soldado inicial: %s \n", soldado_inicial->nome); // mostra por qual soldado vai começar
    return soldadoInicial->prox; // retorna o prox soldado depois do sorteado é o número 1 na contagem
}

// sorteia o numero do chapeu de um soldado
int sorteiaNumeroChapeu(pplista l)
{
    bloco *nChapeu = (*l)->inicio; // a partir do começo da lista
    int n1 = rand() % (*l)->dimensao; // sorteia um numero para chegar no soldado que o numero do chapeu vai ser usado
    for(int i = 0; i < n1; i++) { // chega no soldado
        nChapeu = nChapeu->prox;
    }
    //printf("numero do soldado: %d \n", num_chapeu_soldado->numero); // mostra o numero do chapeu
    return nChapeu->numero; // retorna o numero do chapeu
}

// remove o elemento a partir do nome
void removerElem(pplista l, char * elem)
{
    if ((*l)->dimensao > 0) {
        if ((*l)->inicio->nome == elem)
            removerInicio(l);
        else {
            bloco *tmp = (*l)->inicio;
            bloco *ant = NULL;

            while (tmp->nome != elem) {
                ant = tmp;
                tmp = tmp->prox;
            }

            ant->prox = tmp->prox;
            (*l)->dimensao--;
            free(tmp);
        }
    }
}

// a partir do soldado inicial sorteado, conta o número do chapeu sorteado e remove o soldado em que parar
bloco * removeSoldado(pplista l, bloco * soldadoInicial, int nChapeu)
{
    bloco *soldadoRemovido = soldadoInicial; // inicia o soldado que vai ser removido
    for(int i = 1; i < nChapeu; i++) { // chega no soldado que vai ser removido
        soldadoRemovido = soldadoRemovido->prox;
    }
    soldadoInicial = soldadoRemovido->prox; // define o proximo soldado inicial da contagem
    removerElem(l, soldadoRemovido->nome); // remove o soldado, encontrando o elemento a partir do nome
    return soldadoInicial; // retorna o soldado proximo ao removido para iniciar uma nova contagem
}

void josephus (pplista l) 
{
    // imprime a lista original
    imprimirLista(*l);
    // sorteia soldado para iniciar
    bloco *soldadoInicial = sorteiaSoldadoInicial(l);
    // processo enquanto tiver mais que 1 soldado na lista
    while((*l)->dimensao > 1) {
        // sorteia o numero do chapeu de um soldado para a contagem
        int nChapeu = sorteiaNumeroChapeu(l);
        // remove o soldado e redefine o soldado inicial da proxima contagem
        soldadoInicial = removeSoldado(l, soldadoInicial, nChapeu);
        // imprime a lista
        imprimirLista(*l);
    }
    printf("Soldado que vai buscar ajuda: ");
    imprimirLista(*l);
}