/* 1. static int hash(int k): fun ̧c ̃ao de dispers ̃ao. Calcula um  ́ındice
na tabela, a partir da chave k. No caso deste exerc ́ıcio, k  ́e o nu ́mero
de matr ́ıcula de um aluno. A fun ̧c ̃ao deve ser declarada est ́atica para
que seu esc opo seja local (restrito ao m ́odulo hash.c);

2. Aluno* hsh_get(Hash tab, int mat): opera ̧c ̃ao para buscar e re-
tornar a referˆencia para um Aluno com nu ́mero de matr ́ıcula mat. Se

o aluno n ̃ao for encontrado na tabela tab, retorna null.
3. Aluno* hsh_set(Hash tab, int mat, char* n, char *e, char t):

insere os dados de um novo aluno na tabela tab. Se j ́a existir o cadas-
tro do aluno na tabela, altere os dados inserindo os valores passados

para a fun ̧c ̃ao. A fun ̧c ̃ao deve retornar o ponteiro para o novo aluno
inserido, ou para o aluno com dados modificados;

4. void hsh_remove(Hash tab, int mat): remove da tabela tab o re-
gistro do aluno com matr ́ıcula mat. Caso este aluno n ̃ao seja encon-
trado, a fun ̧c ̃ao n ̃ao faz qualquer altera ̧c ̃ao na tabela;

5. void hsh_imprime(Hash tab):imprime o conteu ́do de toda a tabela
hash. */

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

static int hash(int k)
{
    return k % N;
}

void hsh_inicializa(Hash tab)
{
    for(int i = 0; i < N; i++) {
        tab[i] = NULL;
    }
}

Aluno* hsh_get(Hash tab, int mat)
{
    int chave = hash(mat);
    while(tab[chave] != NULL) {
        if(tab[chave]->matricula == mat) {
            return tab[chave];
        }
        chave = (chave + 1) % N;
    }
    return NULL;
}

Aluno* hsh_set(Hash tab, int mat, char * n, char * e, char t)
{
    int chave = hash(mat);
    Aluno * aux = tab[chave];
    while(aux != NULL) {
        if(aux->matricula == mat) break;
        aux = aux->prox;
    }
    if(aux == NULL) {
        aux = (Aluno*)malloc(sizeof(Aluno));
        aux->matricula = mat;
        aux->prox = tab[chave];
        tab[chave] = aux;
    }
    aux->nome = n;
    aux->turma = t;
    aux->email = e;
    return aux;
}

void hsh_remove(Hash tab, int mat)
{
    int chave = hash(mat);
    Aluno * aux = tab[chave];
    Aluno * ant = aux;
    while(aux != NULL){
        if(aux->matricula == mat) {
            if(aux == ant) {
                tab[chave] = aux->prox;
            }
            else {
                ant->prox = aux->prox;
            }
            ant = aux;
            free(aux);
            break;
        }
        aux = ant->prox;
    } 
}

void hsh_imprime(Hash tab)
{
    for(int i = 0; i < N; i++) {
        if(tab[i] != NULL) {
            printf("\nAluno: %s, Matricula: %i, Turma: %c, Email: %s", 
                tab[i]->nome, tab[i]->matricula, tab[i]->turma, tab[i]->email);
            /*Aluno * aux = tab[i]->prox;
            while(aux != NULL) {
                printf("Aluno: %s, Matricula: %i, Turma: %c, Email: %s", aux->nome, aux->matricula, aux->turma, aux->email);
                aux = aux->prox;
            }*/
        }
    }
    printf("\n");
}