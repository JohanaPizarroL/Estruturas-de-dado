//fila sequencial circular

#ifndef DEQUE_H
#define DEQUE_H

#include "item.h"
#include <stdbool.h>
#define TAM 100
#define ERRO -12364

typedef struct deque_ DEQUE;

	DEQUE *deque_criar(void);
	bool deque_inserir(DEQUE *deque, ITEM *item);
	ITEM *deque_remover(DEQUE *deque);
	int deque_tamanho(DEQUE *deque);
	void deque_print(DEQUE *deque);
	bool deque_vazia(DEQUE *deque);
	bool deque_cheia(DEQUE *deque);

	ITEM *deque_remover_fim(DEQUE *deque);
	bool deque_inserir_inicio(DEQUE *deque, ITEM *item);


#endif