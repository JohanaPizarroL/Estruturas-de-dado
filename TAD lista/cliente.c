//cliente tad lista

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "item.h"

int main(){

    LISTA *lista;

    lista = lista_criar();

	int num, num2;
	printf("Digite um num1: ");
	scanf("%d", &num);

   // printf("Digite um num2: ");
   // scanf("%d", &num2);

    //ITEM *item, *item2;

    /*item->chave = num;
    item2->chave = num2;*/

    ITEM *item_criar(num);


    lista_inserir(lista, &item);
   // lista_inserir(lista, &item2);



	/*for(int i = 0; i < n; i++){
        printf("Digite a chave a ser inserida: ");


	}*/

    //printf("Tamanho da lista eh: %d\n", lista_tamanho(lista));

    printf("Itens na lista:\n");
    lista_imprimir(lista);

    /*int chave = 2;
    ITEM *item_get_chave = lista_busca(lista, chave);

    if (item_get_chave != NULL) {
        item_get_chave(item);
    } else {
        printf("Item com chave %d não encontrado na lista.\n", item);
    }
*/
    lista_apagar(&lista);

    return 0;
}