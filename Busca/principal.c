#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "busca.h"

int main (void) {

    clock_t start, end;
    double cpu_time_usedBL1, cpu_time_usedBL2, cpu_time_usedBL3, cpu_time_usedBL4, cpu_time_usedBL5;
    double cpu_time_usedBB1, cpu_time_usedBB2, cpu_time_usedBB3, cpu_time_usedBB4, cpu_time_usedBB5;

    printf("\n------teste das buscas------\n");

    int n1 = 10, n2 = 100, n3 = 1000, n4 = 10000, n5 = 100000;

    printf("\n------Busca Linear------\n");
    printf("\n------10 na 1------\n");
    int *vetorBL1 = criaVetorEmbaralhado(n1);
    printf("vetor embaralhado: ");
    imprime(n1, vetorBL1);
    start = clock();
    int BL = buscaLinear(n1, vetorBL1, 9);
    end = clock();
    if(BL == -1)
        printf("O elemento não foi encontrado\n");
    else
        printf("O elemento esta na posicao %d\n", BL);
    cpu_time_usedBL1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 2------\n");
    int *vetorBL2 = criaVetorEmbaralhado(n2);
    printf("vetor embaralhado: ");
    imprime(n2, vetorBL2);
    start = clock();
    BL = buscaLinear(n2, vetorBL2, 90);
    end = clock();
    if(BL == -1)
        printf("O elemento não foi encontrado\n");
    else
        printf("O elemento esta na posicao %d\n", BL);
    cpu_time_usedBL2 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 3------\n");
    int *vetorBL3 = criaVetorEmbaralhado(n3);
    printf("vetor embaralhado: ");
    imprime(n3, vetorBL3);
    start = clock();
    BL = buscaLinear(n3, vetorBL3, 900);
    end = clock();
    if(BL == -1)
        printf("O elemento não foi encontrado\n");
    else
        printf("O elemento esta na posicao %d\n", BL);
    cpu_time_usedBL3 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 4------\n");
    int *vetorBL4 = criaVetorEmbaralhado(n4);
    printf("vetor embaralhado: ");
    imprime(n4, vetorBL4);
    start = clock();
    BL = buscaLinear(n4, vetorBL4, 9000);
    end = clock();
    if(BL == -1)
        printf("O elemento não foi encontrado\n");
    else
        printf("O elemento esta na posicao %d\n", BL);
    cpu_time_usedBL4 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 5------\n");
    int *vetorBL5 = criaVetorEmbaralhado(n5);
    printf("vetor embaralhado: ");
    imprime(n5, vetorBL5);
    start = clock();
    BL = buscaLinear(n5, vetorBL5, 90000);
    end = clock();
    if(BL == -1)
        printf("O elemento não foi encontrado\n");
    else
        printf("O elemento esta na posicao %d\n", BL);
    cpu_time_usedBL5 = ((double) (end - start)) / CLOCKS_PER_SEC;


    printf("\n------Busca Binaria------\n");
    printf("\n------10 na 1------\n");
    int *vetorBB1 = criaVetorEmbaralhado(n1);
    quickSort(n1, vetorBB1, 0, n1-1);
    printf("vetor ordenado: ");
    imprime(n1, vetorBB1);
    start = clock();
    int BB = buscaBinaria(n1, vetorBB1, 9);
    end = clock();
    if(BB == -1)
        printf("O elemento não foi encontrado\n");
    else
        printf("O elemento esta na posicao %d\n", BB);
    cpu_time_usedBB1 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 2------\n");
    int *vetorBB2 = criaVetorEmbaralhado(n2);
    quickSort(n1, vetorBB2, 0, n2-1);
    printf("vetor ordenado: ");
    imprime(n2, vetorBB2);
    start = clock();
    BB = buscaBinaria(n2, vetorBB2, 90);
    end = clock();
    if(BB == -1)
        printf("O elemento não foi encontrado\n");
    else
        printf("O elemento esta na posicao %d\n", BB);
    cpu_time_usedBB2 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 3------\n");
    int *vetorBB3 = criaVetorEmbaralhado(n3);
    quickSort(n1, vetorBB3, 0, n3-1);
    printf("vetor ordenado: ");
    imprime(n3, vetorBB3);
    start = clock();
    BB = buscaBinaria(n3, vetorBB3, 900);
    end = clock();
    if(BB == -1)
        printf("O elemento não foi encontrado\n");
    else
        printf("O elemento esta na posicao %d\n", BB);
    cpu_time_usedBB3 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 4------\n");
    int *vetorBB4 = criaVetorEmbaralhado(n4);
    quickSort(n1, vetorBB4, 0, n4-1);
    printf("vetor ordenado: ");
    imprime(n4, vetorBB4);
    start = clock();
    BB = buscaBinaria(n4, vetorBB4, 9000);
    end = clock();
    if(BB == -1)
        printf("O elemento não foi encontrado\n");
    else
        printf("O elemento esta na posicao %d\n", BB);
    cpu_time_usedBB4 = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n------10 na 5------\n");
    int *vetorBB5 = criaVetorEmbaralhado(n5);
    quickSort(n1, vetorBB5, 0, n5-1);
    printf("vetor ordenado: ");
    imprime(n5, vetorBL5);
    start = clock();
    BB = buscaBinaria(n5, vetorBB5, 90000);
    end = clock();
    if(BB == -1)
        printf("O elemento não foi encontrado\n");
    else
        printf("O elemento esta na posicao %d\n", BB);
    cpu_time_usedBB5 = ((double) (end - start)) / CLOCKS_PER_SEC;


    /*------------tempos------------*/
    printf("\n------------Tempos(segundos)------------\n");
    printf("\n-----Para 10 elementos-----\n");
    printf("Busca Linear: %f\nBusca Binaria: %f\n", cpu_time_usedBL1, cpu_time_usedBB1);
    printf("\n-----Para 100 elementos-----\n");
    printf("Busca Linear: %f\nBusca Binaria: %f\n", cpu_time_usedBL2, cpu_time_usedBB2);
    printf("\n-----Para 1000 elementos-----\n");
    printf("Busca Linear: %f\nBusca Binaria: %f\n", cpu_time_usedBL3, cpu_time_usedBB3);
    printf("\n-----Para 10000 elementos-----\n");
    printf("Busca Linear: %f\nBusca Binaria: %f\n", cpu_time_usedBL4, cpu_time_usedBB4);
    printf("\n-----Para 100000 elementos-----\n");
    printf("Busca Linear: %f\nBusca Binaria: %f\n", cpu_time_usedBL5, cpu_time_usedBB5);
}