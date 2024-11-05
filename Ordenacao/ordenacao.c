/*  Ordenacao
**
**	---------------------------------------------------------------
**
**	Funcoes:
**	---------------------------------------------------------------
**
**      void troca(int *v, int i, int j)
**
**                v - vetor
**                i - posicao do vetor
**                j - posicao do vetor
**
**      ---------------------------------------------------------------
**
**      int* criaVetorEmbaralhado(int n)
**
**                n - tamanho do vetor
**
**            onde n é o n ́umero de elementos do vetor. Os valores
**            armazenados no vetor não podem ser repetidos e devem ter
**            valores de 1 a n (ou 0 a n-1 se você preferir). Note que
**            o vetor  ́e alocado dinamicamente, e deve ser usada uma 
**            função de geracão de números aleatórios para criar os 
**            elementos do vetor. Se o vetor tiver 10 elementos, os 
**            números devem ficar dentro do intervalo [1,10] (ou [0,9]).
**            Se o vetor tiver 1.000 de elementos, os valores devem
**            estar dentro do intervalo [1,1.000] (ou [0, 999]);
**
**      ---------------------------------------------------------------
**
**      void imprime(int n, int* v)
**
**                n - tamanho do vetor
**                V - Vetor
**
**      ---------------------------------------------------------------
**
**      void bubbleSort(int n, int* v);
**
**                n - tamanho do vetor
**                v - vetor
**
**      ---------------------------------------------------------------
**
**      int particiona(int* v, int a, int b)
**
**                v - vetor
**                a - indice do primeiro elemento a ser ordenado
**                b - indice do ultimo elemento a ser ordenado
**
**      ---------------------------------------------------------------
**
**      void quickSort(int n, int* v);
**
**                n - tamanho do vetor
**                v - vetor
**
**      ---------------------------------------------------------------
**
**      int merge(int* v, int a, int b, int c)
**
**                v - vetor
**                a - indice do primeiro elemento a ser ordenado
**                b - divide
**                c - indice do ultimo elemento a ser ordenado
**
**      ---------------------------------------------------------------
**
**      void mergeSort(int* v, int a, int c)
**
**                v - vetor
**                a - indice do primeiro elemento a ser ordenado
**                c - indice do ultimo elemento a ser ordenado
**
*/

/*
**	---------------------------------------------------------------
**	Definicoes e variaveis globais:
*/

#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "limits.h"
#include "ordenacao.h"

/*
**	---------------------------------------------------------------
**	Implementacao das funcoes comeca aqui:
*/

/*=========================  criaVetorEmbaralhado  =========================*/

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

/*=========================  bubbleSort  =========================*/

void bubbleSort(int n, int* v)
{
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n-i; j++) {
            if(v[j] > v[j + 1]) {
                troca(v, j, j+1);
            }
        }
    }
}

/*=========================  quickSort  =========================*/

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

/*=========================  mergeSort  =========================*/

int merge(int* v, int a, int b, int c)
{
    int n1 = b - a + 1;
    int n2 = c - b;
    int *L = (int *)calloc(n1 + 1, sizeof(int));
    int *R = (int *)calloc(n2 + 1, sizeof(int));
    //int *L = (int *)malloc(sizeof(int) * n1);
    //int *R = (int *)malloc(sizeof(int) * n2);
    for(int i = 0; i < n1; i++) {
        L[i] = v[a + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = v[b + j + 1];
    }
    L[n1] = INT_MAX, R[n2] = INT_MAX;
    int i = 0, j = 0;
    for(int k = a; k <= c; k++) {
        if(L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        }
        else {
            v[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int* v, int a, int c)
{

    if(a < c) {
        int b = (a + c)/2;
        mergeSort(v, a, b);
        mergeSort(v, b + 1, c);
        merge(v, a, b, c);
    }

}