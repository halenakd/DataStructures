/*  Pilha
**
**	---------------------------------------------------------------
**
**	Funcoes:
**	---------------------------------------------------------------
**
**      Pilha *pilha_cria(void); 
**            instancia uma nova struct Pilha, criando uma pilha vazia e
**            inicializando o primeiro elemento (o topo da pilha) como NULL.
**
**      ---------------------------------------------------------------
**
**      void pilha_push(Pilha *p, float v); 
**
**                p	- pilha
**                v	- valor empilhado
**
**            instancia um novo nó da lista e o insere no topo da pilha. 
**            Note que o ponteiro para o topo da pilha sempre deve ser atualizado.
**
**      ---------------------------------------------------------------
**
**      float pilha_pop(Pilha *p); 
**
**                p	- pilha
**
**            retira o elemento do topo da pilha e retorna seu valor. Se
**            a pilha estiver vazia, a função deve exibir uma mensagem de 
**            erro e abortar o programa.
**
**      ---------------------------------------------------------------
**
**      int pilha_vazia(Pilha *p);
**
**                p	- pilha
**
**            a pilha está vazia se a lista estiver vazia.
**
**      ---------------------------------------------------------------
**
**      void pilha_libera(Pilha *p); 
**
**                p	- pilha
**
**            libera a pilha desalocando (liberando) todos os nós da lista.
**
*/

/*
**	---------------------------------------------------------------
**	Definicoes e variaveis globais:
*/
#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"
#include "lista.h"

/*
**	---------------------------------------------------------------
**	Implementacao das funcoes comeca aqui:
*/

/*=========================  pilha_cria  =========================*/

Pilha *pilha_cria()
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

/*=========================  pilha_push  =========================*/

void pilha_push(Pilha *p, float v)
{
    insereInicio(&p->topo, v);
}

/*=========================  pilha_pop  =========================*/

float pilha_pop(Pilha *p)
{
    if(pilha_vazia(p)) {
        printf("A pilha está vazia\n");
        return 0;
    }
    else {
        return retiraInicio(&p->topo);
    }
}
  
/*=========================  pilha_vazia  =========================*/

int pilha_vazia(Pilha *p)
{
    if(listaVazia(p->topo))
        return 1;
    return 0;
}

/*=========================  pilha_libera  =========================*/

void pilha_libera(Pilha *p)
{
    while(!pilha_vazia)
        retiraInicio(&p->topo);
}

/*=========================  pilha_imprime  =========================*/

void pilha_imprime(Pilha *p)
{
    imprimeLista(p->topo); 
}