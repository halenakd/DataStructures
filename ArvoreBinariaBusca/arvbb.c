/*Arv* abb_cria(void): cria uma  ́arvore bin ́aria vazia (i.e., simples-
mente retorna NULL);

2. void abb_imprime(Arv *a): percorre a  ́arvore em ordem sim ́etrica
para imprimir seu conteu ́do (nu ́meros) em ordem crescente;
3. Arv* abb_busca(Arv* r, int v): esta  ́e a opera ̧c ̃ao para buscar um
elemento na  ́arvore, com desempenho computacional proporcional `a
sua altura (O(log n)), portanto, a fun ̧c ̃ao deve se valer do fato de a
`arvore estar ordenada. Caso o valor v seja encontrado, a fun ̧c ̃ao retorna
o endere ̧co do n ́o que armazena v. Caso contr ́ario, a fun ̧c ̃ao deve
retornar NULL;

4. Arv* abb_insere(Arv* a, int v): adiciona um novo elemento na

 ́arvore na posi ̧c ̃ao correta para que a propriedade fundamental de or-
dena ̧c ̃ao seja mantida. Importante notar a necessidade de atualizar os

ponteiros para sub `arvores `a esquerda ou `a direita quando da chamada
recursiva da fun ̧c ̃ao, pois a inser ̧c ̃ao pode alterar o valor do ponteiro
para a raiz da (sub) ́arvore;

5. Arv* abb_retira(Arv* r, int v): opera ̧c ̃ao para retirar um ele-
mento com valor v da  ́arvore. A fun ̧c ̃ao tem como valor de retorno

a eventual nova raiz da (sub) ́arvore.
6. void abb_imprimeDecrescente(Arv* a): implementa ̧c ̃ao semelhante
`a fun ̧c ̃ao abb_imprime, por ́em deve imprimir o elementos da  ́arvore em
ordem decrescente.*/

#include <stdio.h>
#include <stdlib.h>
#include "arvbb.h"

Arv* abb_cria(void)
{
    return NULL;
}

void abb_imprime(Arv *a)
{
    if(a != NULL) {
        abb_imprime(a->esq);
        printf("%d ", a->info);
        abb_imprime(a->dir);
    }
}

Arv* abb_busca(Arv* r, int v)
{
    if(r == NULL) {
        return NULL;
    }
    else {
        if(v < r->info) {
            return abb_busca(r->esq, v);
        }
        else {
            if(v > r->info) {
                return abb_busca(r->dir, v);
            }
            else {
                return r;
            }
        }
    }
}

Arv* abb_insere(Arv* a, int v)
{
    if(a == NULL) {
        a = (Arv*)malloc(sizeof(Arv));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    }
    else {
        if(v < a->info) {
            a->esq = abb_insere(a->esq, v);
        }
        else {
            a->dir = abb_insere(a->dir, v);
        }
    }
    return a;
}

Arv* abb_retira(Arv* r, int v)
{
    if(r == NULL) {
        return NULL;
    }
    else {
        if(v < r->info) {
            r->esq = abb_retira(r->esq, v);
        }
        else {
            if(v > r->info) {
                r->dir = abb_retira(r->dir, v);
            }
            else {
                if(r->esq == NULL) {
                    r = r->dir;
                }
                else {
                    if(r->dir == NULL) {
                        r = r->esq;
                    }
                    else {
                        Arv *p = r->esq;
                        while(p->dir != NULL) {
                            p = p->dir;
                        }
                        r->info = p->info;
                        p->info = v;
                        r->esq = abb_retira(r->esq, v);
                    }
                }
            }
        }
    }
    return r;
}

void abb_imprimeDecrescente(Arv* a)
{
    if(a != NULL) {
        abb_imprimeDecrescente(a->dir);
        printf("%d ", a->info);
        abb_imprimeDecrescente(a->esq);
    }
}