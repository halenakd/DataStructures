#ifndef _hash_h
#define _hash_h

struct aluno {
    int matricula;
    char * nome;
    char turma;
    char * email;
    struct aluno* prox;
};
typedef struct aluno Aluno;

#define N 127
typedef Aluno* Hash[N];

static int hash(int k);
void hsh_inicializa(Hash tab);
Aluno* hsh_get(Hash tab, int mat);
Aluno* hsh_set(Hash tab, int mat, char * n, char * e, char t);
void hsh_remove(Hash tab, int mat);
void hsh_imprime(Hash tab);

#endif