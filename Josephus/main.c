#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "josephus.h"

int main (void) {
    plista lst;

    criarLista(&lst);

    inserirInicio(&lst, 7, "joao");
    inserirInicio(&lst, 13, "jair");
    inserirFinal(&lst, 16, "jose");
    inserirPosK(&lst, 2, 10, "julio");

    // lista: jair(13), julio(10), joao(7), jose(16)

    josephus(&lst);
}