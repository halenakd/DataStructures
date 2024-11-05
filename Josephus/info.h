#ifndef _info_h
#define _info_h


typedef struct nodo {
      int numero;
      char *nome;
      struct nodo *prox;
} bloco, *pbloco; // bloco/nodo/elemento da lista

typedef struct lista {
      bloco *inicio;
      bloco *final;
      int dimensao;  
} *plista, **pplista; // descritor da lista

#endif