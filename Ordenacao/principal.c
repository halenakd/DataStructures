/*  Ordenacao
**
**	---------------------------------------------------------------
*/

/*
**	---------------------------------------------------------------
**	Definicoes e variaveis globais:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

/*
**	---------------------------------------------------------------
**	Implementacao das funcoes comeca aqui:
*/

/*=========================  main  =========================*/

/*#define v 0*/
void main (void) {

    clock_t start, end;
    double cpu_time_usedBS1, cpu_time_usedBS2, cpu_time_usedBS3, cpu_time_usedBS4;
    double cpu_time_usedQS1, cpu_time_usedQS2, cpu_time_usedQS3, cpu_time_usedQS4;
    double cpu_time_usedMS1, cpu_time_usedMS2, cpu_time_usedMS3, cpu_time_usedMS4;

    printf("\n------teste das ordenacoes------\n");

    int n1 = 10, n2 = 100, n3 = 1000, n4 = 10000;

    printf("\n------BubbleSort------\n");
    printf("\n------10 na 1------\n");
    int *vetorBS1 = criaVetorEmbaralhado(n1);
    printf("vetor embaralhado: ");
    imprime(n1, vetorBS1);
    start = clock();
    bubbleSort(n1, vetorBS1);
    end = clock();
    printf("vetor ordenado: ");
    imprime(n1, vetorBS1);
    cpu_time_usedBS1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 2------\n");
    int *vetorBS2 = criaVetorEmbaralhado(n2);
    printf("vetor embaralhado: ");
    imprime(n2, vetorBS2);
    start = clock();
    bubbleSort(n2, vetorBS2);
    end = clock();
    printf("vetor ordenado: ");
    imprime(n2, vetorBS2);
    cpu_time_usedBS2 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 3------\n");
    int *vetorBS3 = criaVetorEmbaralhado(n3);
    printf("vetor embaralhado: ");
    imprime(n3, vetorBS3);
    start = clock();
    bubbleSort(n3, vetorBS3);
    end = clock();
    printf("vetor ordenado: ");
    imprime(n3, vetorBS3);
    cpu_time_usedBS3 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 4------\n");
    int *vetorBS4 = criaVetorEmbaralhado(n4);
    printf("vetor embaralhado: ");
    imprime(n4, vetorBS4);
    start = clock();
    bubbleSort(n4, vetorBS4);
    end = clock();
    printf("vetor ordenado: ");
    imprime(n4, vetorBS4);
    cpu_time_usedBS4 = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\n------QuickSort------\n");
    printf("\n------10 na 1------\n");
    int *vetorQS1 = criaVetorEmbaralhado(n1);
    printf("vetor embaralhado: ");
    imprime(n1, vetorQS1);
    start = clock();
    quickSort(n1, vetorQS1, 0, n1-1);
    end = clock();
    printf("vetor ordenado: ");
    imprime(n1, vetorQS1);
    cpu_time_usedQS1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 2------\n");
    int *vetorQS2 = criaVetorEmbaralhado(n2);
    printf("vetor embaralhado: ");
    imprime(n2, vetorQS2);
    start = clock();
    quickSort(n2, vetorQS2, 0, n2-1);
    end = clock();
    printf("vetor ordenado: ");
    imprime(n2, vetorQS2);
    cpu_time_usedQS2 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 3------\n");
    int *vetorQS3 = criaVetorEmbaralhado(n3);
    printf("vetor embaralhado: ");
    imprime(n3, vetorQS3);
    start = clock();
    quickSort(n3, vetorQS3, 0, n3-1);
    end = clock();
    printf("vetor ordenado: ");
    imprime(n3, vetorQS3);
    cpu_time_usedQS3 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 4------\n");
    int *vetorQS4 = criaVetorEmbaralhado(n4);
    printf("vetor embaralhado: ");
    imprime(n4, vetorQS4);
    start = clock();
    quickSort(n4, vetorQS4, 0, n4-1);
    end = clock();
    printf("vetor ordenado: ");
    imprime(n4, vetorQS4);
    cpu_time_usedQS4 = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\n------MergeSort------\n");
    printf("\n------10 na 1------\n");
    int *vetorMS1 = criaVetorEmbaralhado(n1);
    printf("vetor embaralhado: ");
    imprime(n1, vetorMS1);
    start = clock();
    mergeSort(vetorMS1, 0, n1-1);
    end = clock();
    printf("vetor ordenado: ");
    imprime(n1, vetorMS1);
    cpu_time_usedMS1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 2------\n");
    int *vetorMS2 = criaVetorEmbaralhado(n2);
    printf("vetor embaralhado: ");
    imprime(n2, vetorMS2);
    start = clock();
    mergeSort(vetorMS2, 0, n2-1);
    end = clock();
    printf("vetor ordenado: ");
    imprime(n2, vetorMS2);
    cpu_time_usedMS2 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 3------\n");
    int *vetorMS3 = criaVetorEmbaralhado(n3);
    printf("vetor embaralhado: ");
    imprime(n3, vetorMS3);
    start = clock();
    mergeSort(vetorMS3, 0, n3-1);
    end = clock();
    printf("vetor ordenado: ");
    imprime(n3, vetorMS3);
    cpu_time_usedMS3 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 4------\n");
    int *vetorMS4 = criaVetorEmbaralhado(n4);
    printf("vetor embaralhado: ");
    imprime(n4, vetorMS4);
    start = clock();
    mergeSort(vetorMS4, 0, n3-1);
    end = clock();
    printf("vetor ordenado: ");
    imprime(n4, vetorMS4);
    cpu_time_usedMS4 = ((double) (end - start)) / CLOCKS_PER_SEC;

    /*------------tempos------------*/
    printf("\n------------Tempos(segundos)------------\n");
    printf("\n-----Para 10 elementos-----\n");
    printf("BubbleSort: %f\nQuickSort: %f\nMergeSort: %f\n", cpu_time_usedBS1, cpu_time_usedQS1, cpu_time_usedMS1);
    printf("\n-----Para 100 elementos-----\n");
    printf("BubbleSort: %f\nQuickSort: %f\nMergeSort: %f\n", cpu_time_usedBS2, cpu_time_usedQS2, cpu_time_usedMS2);
    printf("\n-----Para 1000 elementos-----\n");
    printf("BubbleSort: %f\nQuickSort: %f\nMergeSort: %f\n", cpu_time_usedBS3, cpu_time_usedQS3, cpu_time_usedMS3);
    printf("\n-----Para 10000 elementos-----\n");
    printf("BubbleSort: %f\nQuickSort: %f\nMergeSort: %f\n", cpu_time_usedBS4, cpu_time_usedQS4, cpu_time_usedMS4);
}