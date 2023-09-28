
//cliente tad lista

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){

	LISTA *lista_criar(void);


	int n;
	printf("Digite quantidade a ser inseridos: ");
	scanf("%d", &n);

	LISTA *lista_criar();d


	for(int i = 0; i < n; i++){

		lista_inserir(LISTA *lista, ITEM *item);

	}


    printf("Tamanho da lista eh: %d\n", lista_tamanho(lista));

    printf("Itens na lista:\n");
    lista_imprimir(lista);

    int chave = 2;
    ITEM *item_encontrado = lista_busca(lista, chave);

    if (item_encontrado != NULL) {
        printf("Item com chave %d encontrado: %s\n", chave, item_encontrado->nome);
    } else {
        printf("Item com chave %d não encontrado na lista.\n", chave);
    }

    lista_apagar(&lista);

    return 0;
}



