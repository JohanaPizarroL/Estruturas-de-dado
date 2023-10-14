//cliente.c - TAD pilha sequencial - transformando decimal em binario

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "item.h"

int main(void){

	PILHA *mypilha = pilha_criar();

	printf("Este codigo transformara seu num decimal em binario\n");

	printf("Digite o tamanho da sua pilha: ");
	int tam;
	scanf("%d", &tam);
	printf("Digite seus numeros aqui: ");

	int num;

	for (int i = 0; i < tam; i++){
		scanf("%d", &num);
	    pilha_empilhar(mypilha, item_criar(num));
   }

	if(pilha_vazia(mypilha))
		printf("Pilha estah vazia\n");

	if(pilha_cheia(mypilha))
		printf("Pilha estah cheia\n");

	pilha_print(mypilha);
	printf("\n");

	printf("O tamanho da sua pilha eh: %d\n", pilha_tamanho(mypilha));


    ITEM* item_desempilhado = pilha_desempilhar(mypilha);
    printf("Desempilhando o item: %d\n", item_get_chave(item_desempilhado));
    item_apagar(&item_desempilhado);

	
	printf("O tamanho da sua pilha eh: %d\n", pilha_tamanho(mypilha));

	ITEM* topo = pilha_topo(mypilha);
    printf("O topo atual da sua pilha é: %d\n", item_get_chave(topo));

	//printf("Pilha original:\n");
	pilha_print(mypilha);

	pilha_inverter(mypilha);

	//printf("Pilha invertida:\n");
	//pilha_print(mypilha);

	pilha_apagar(&mypilha);

	return 0; 
}
