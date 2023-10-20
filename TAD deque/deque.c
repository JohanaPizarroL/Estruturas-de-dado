//implementacao de um deque em cima de uma fila
//apenas add duas funcoes bool inserir inicio e remover fim
#include "deque.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>

struct deque_{
	ITEM *deque[TAM];
	int inicio; /*posicao do 1o elemento da fila*/
	int fim; /*posicao do ultimo elemento da fila*/
	int tamanho;
};



DEQUE *deque_criar(void){
	/*pré-condição: existir espaço na memória.
	Na implementação estática não há o que verificar*/
	DEQUE *deque = (DEQUE *) malloc(sizeof(DEQUE));
	deque->inicio = 0;
	deque->fim = 0;
	deque->tamanho = 0; //deque vazia

	return (deque);
}


bool deque_cheia(DEQUE *deque) {
	return (deque->tamanho == TAM);
}

bool deque_vazia(DEQUE *deque) {
	return (deque->tamanho == 0);
}


bool deque_inserir(DEQUE *deque, ITEM *item){

	if (deque != NULL && (!deque_cheia(deque)) ){
		deque->deque[deque->fim] = item;
		deque->fim = (deque->fim+1) % TAM;
		deque->tamanho ++;

		return(true);
	}
	return(false);
}

bool deque_inserir_inicio(DEQUE *deque, ITEM *item) {
	if (deque != NULL && !deque_cheia(deque)) {
		deque->inicio = (deque->inicio - 1 + TAM) % TAM;
		deque->deque[deque->inicio] = item;
		deque->tamanho ++;
		return (true);
	}
	return (false);
}

ITEM *deque_remover(DEQUE *deque){
	if (deque != NULL && (!deque_vazia(deque)) ) {
		ITEM *removido = deque->deque[deque->inicio];
		deque->deque[deque->inicio] = NULL;
		deque->inicio = (deque->inicio + 1) % TAM;
		deque->tamanho --;
		return (removido);
	}
	return (NULL);
}


ITEM *deque_remover_fim(DEQUE *deque) {
	if (deque != NULL && !deque_vazia(deque)) {
		deque->fim = (deque->fim - 1 + TAM) % TAM;
		ITEM* i = deque->deque[deque->fim];
		deque->deque[deque->fim] = NULL;
		deque->tamanho --;
		return (i);
	}
	return (NULL);
	}


int deque_tamanho(DEQUE *deque) {
	if (deque != NULL)
		return (deque->tamanho);

	return (ERRO);
}


void deque_print(DEQUE *deque){
	
	//printf("deque formada:\n");

	for(int i = deque->inicio; i < deque->tamanho + deque->inicio ; i++){
		item_imprimir(deque->deque[i]);
	}

}
