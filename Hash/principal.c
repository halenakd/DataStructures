#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main (void) {
    /* inicializando tabela hash */
    Hash tab;
    hsh_inicializa(tab);

    /* inserindo alunos na tabela hash */
    hsh_set(tab, 202201, "Joao", "joao@gmail.com", 'A');
    hsh_set(tab, 202202, "Amanda", "amanda@gmail.com", 'B');
    hsh_set(tab, 202203, "Luiza", "luiza@gmail.com", 'C');
    hsh_set(tab, 202204, "Mateus", "mateus@gmail.com", 'A');
    hsh_set(tab, 202205, "Ricardo", "ricardo@gmail.com", 'B');
    hsh_set(tab, 202206, "Felipe", "felipe@gmail.com", 'C');
    printf("\n------tabela hash atual------");
    hsh_imprime(tab); // imprimindo a tabela hash

    /* buscando alunos na tabela hash */
    printf("\n------busca------");
    if(hsh_get(tab, 202205) == NULL) printf("\nAluno 202205 não encontrado");
    else printf("\nAluno 202205 encontrado");
    if(hsh_get(tab, 202206) == NULL) printf("\nAluno 202206 não encontrado");
    else printf("\nAluno 202206 encontrado");
    printf("\n");

    /* removendo alunos da tabela hash */
    printf("\n------remocao------");
    hsh_remove(tab, 202203);
    /* testando se funcionou */
    if(hsh_get(tab, 202203) == NULL) printf("\nAluno 202203 não encontrado, pois foi removido");
    else printf("\nAluno 202203 encontrado");
    printf("\n");
    printf("\n------tabela hash atual------");
    hsh_imprime(tab); // imprimindo a tabela hash
}