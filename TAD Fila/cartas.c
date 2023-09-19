#include <stdio.h>
#include "fila.h"
#include "item.h"


void cartas(int n){

    FILA *fila = fila_criar(); //criacao de uma fila vazia com a funcao fila criar


   /* for (int i = 1; i <= n; i++) {
        ITEM *item = item_criar(i);
        fila_inserir(fila, item);
    }*/

    printf("Discarded cards:");
    int first = 1; //controla se a virgula deve ser impressa

    while (fila_tamanho(fila) > 1) { //loop simulador do jogo de cartas
//cartas descartadas, e movidas para o final da fila até que sobre apenas
//uma carta

        if (!first) {
            printf(","); //se haver um numero a imprimir imprime uma virugla
         //para que visualmente esteja
        }
        printf(" %d", item_get_chave(fila_remover(fila)));
        ITEM *temp = fila_remover(fila);
        fila_inserir(fila, temp);
        first = 0;
    }

   	printf("\nRemaining card: %d\n", item_get_chave(fila_frente(fila)));
    fila_apagar(&fila);
}


