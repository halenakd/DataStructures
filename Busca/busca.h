#ifndef _busca_h
#define _busca_h

void troca(int* v, int i, int j);
int* criaVetorEmbaralhado(int n);
void imprime(int n, int* v);
int particiona(int* v, int a, int b);
void quickSort(int n, int* v, int a, int b);
int buscaLinear(int n, int* vet, int elem);
int buscaBinaria(int n, int* vet, int elem);

#endif