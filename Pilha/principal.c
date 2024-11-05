/*  Calculadora
**
**	---------------------------------------------------------------
**
**	Funcoes:
**      ---------------------------------------------------------------
**
**      Calc calc_cria(char* f); 
**            instancia uma nova calculadora com formatação de números
**            definida pela cadeia f.
**
**      ---------------------------------------------------------------
**
**      void calc_operando(Calc* c, float v); 
**            coloca o operando passado como valor no topo da pilha.
**
**      ---------------------------------------------------------------
**
**      void calc_operador(Calc* c, char op); 
**            retira dois valores do topo da pilha (considerando que só 
**            estamos usando operadores binários), efetua a operação
**            correspondente e coloca o valor do resultado na pilha. As 
**            operações que voce deve implementar são +, -, * e /. Se não 
**            existirem operandos na pilha, consideramos que seus valores são zero.
**
**      ---------------------------------------------------------------
**
**      void calc_libera(Calc *c); 
**            libera a memória usada pela calculadora (incluindo a
**            Pilha).
**
*/

/*
**	---------------------------------------------------------------
**	Definicoes e variaveis globais:
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"

struct calc {
    char *f[21]; /* formato para impressão, por exemplo “%.2f\n” */
    Pilha *p; /* pilha de operandos */
};

typedef struct calc Calc;

Calc *calc_cria(char* f);
void calc_operando(Calc* c, float v);
void calc_operador(Calc* c, char op);
void calc_libera(Calc *c);

/*
**	---------------------------------------------------------------
**	Implementacao das funcoes comeca aqui:
*/

/*=========================  main  =========================*/

void main (void) {

    /* escaneia a formatação desejada pelo usuário */
    char *f[21];
    printf( "\nEntre a formatacao (exemplo: %%.2f): " );
    scanf( "%s", &f);

    /*cria a calculadora com a formatação informada*/
    Calc *c;
    c = calc_cria(f);

    /* laço para o usuário inserer números e operadores */
    while(1) 
    {
        char caracter[21];
        printf( "\nEntre um numero ou operador: " );
        scanf("%s", caracter);

        /* q para sair */
        if(caracter[0] == 'q')
        {
            break;
        }

        /* libera a calculadora */
        else if(caracter[0] == 'c')
        {
            calc_libera(c);
        }

        /* se o usuário inserir um operador, faz a operação em questão*/
        /* imprime o resultado e guarda na pilha */
        else if(caracter[0] == '+' || caracter[0] == '-' || 
            caracter[0] == '*' || caracter[0] == '/')
        {

            calc_operador(c, caracter[0]);
        }

        /* se o usuário inserir um número, imprime e guarda na pilha */
        else
        {
            calc_operando(c, atof(caracter));
        }
    }
}

/*=========================  calc_cria  =========================*/

Calc *calc_cria(char* f)
{
    Calc *c = (Calc*)malloc(sizeof(Calc));;
    c->p = pilha_cria();
    *c->f = f;
    return c;
}

/*=========================  calc_operando  =========================*/

void calc_operando(Calc* c, float v)
{
    pilha_push(c->p, v);
    printf(*c->f, v);
}

/*=========================  calc_operador  =========================*/

void calc_operador(Calc* c, char op)
{
    float v1 = pilha_pop(c->p);
    float v2 = pilha_pop(c->p);
    float v3;
    if(op == '+') {
        v3 = v2 + v1;
    }
    else if(op == '-') {
        v3 = v2 - v1;
    }
    else if(op == '*') {
        v3 = v2 * v1;
    }
    else if(op == '/') {
        v3 = v2 / v1;
    }
    pilha_push(c->p, v3);
    printf(*c->f, v3);
}

/*=========================  calc_libera  =========================*/

void calc_libera(Calc *c)
{
    pilha_libera(c->p);
}