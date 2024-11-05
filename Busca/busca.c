#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "busca.h"

void troca(int *v, int i, int j)
{
	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

int* criaVetorEmbaralhado(int n)
{
    int *vetor = (int *)calloc(n, sizeof(int));
    for(int i = 0, j = 1; i < n, j < n+1; i++, j++) {
        vetor[i] = j;
    }
    srand(time(NULL));
    for (int i = 0; i < n; i++)
	{
		int r = rand() % n;
        troca(vetor, i, r);
	}
    return vetor;
}

void imprime(int n, int* v)
{
    for(int i = 0; i < n-1; i++)
        printf("%d, ", v[i]);
    printf("%d \n", v[n-1]);
}

int particiona(int* v, int a, int b)
{
    int x = v[a];
    while(a < b) {
        while(v[a] < x)
            a++;
        while(v[b] > x)
            b--;
        troca(v, a, b);
    }
    return a;
}

void quickSort(int n, int* v, int a, int b)
{
    if(a < b) {
        int indicePivo = particiona(v, a, b);
        quickSort(n, v, a, indicePivo - 1);
        quickSort(n, v, indicePivo + 1, b);
    }
}

int buscaLinear(int n, int* vet, int elem)
{
    for(int i = 0; i <= n-1; i++) {
        if(elem == vet[i]) {
            return i;
        }
    }
    return -1;
}

int buscaBinaria(int n, int* vet, int elem)
{
    int ini = 0;
    int fim = n - 1;
    int meio;
    while(ini <= fim) {
        meio = (ini + fim)/2;
        if(elem < vet[meio]) {
            fim = meio -1;
        }
        else {
            if(elem > vet[meio]) {
                ini = meio + 1;
            }
            else {
                return meio;
            }
        }
    }
    return -1;
}