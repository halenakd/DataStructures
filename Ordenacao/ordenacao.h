/*
**       ordenacao.h:   Definicoes para ordenacoes
**
*/

#ifndef _ordenacao_h
#define _ordenacao_h

/* prototipo das funcoes */

void troca(int* v, int i, int j);
int* criaVetorEmbaralhado(int n);
void imprime(int n, int* v);
void bubbleSort(int n, int* v);
int particiona(int* v, int a, int b);
void quickSort(int n, int* v, int a, int b);
int merge(int* v, int a, int b, int c);
void mergeSort(int* v, int a, int b);

#endif