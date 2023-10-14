//falta arrumar as funcoes de topo e o num que estamos desempilhando pq 
//devolve o endereco e nao o valor

#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

struct pilha_{
	ITEM *item[TAM];
	int tamanho;
};

PILHA* pilha_criar(void){

	PILHA* pilha = (PILHA *) malloc(sizeof (PILHA));

	if(pilha != NULL)
		pilha->tamanho = 0;

	return(pilha);
}


void pilha_apagar(PILHA **pilha){

	free(*pilha);
	*pilha = NULL;
}

bool pilha_vazia(PILHA* pilha){

	if(pilha != NULL)
		return((pilha->tamanho == 0) ? true : false);
	return(false);
}

bool pilha_cheia(PILHA *pilha){

	if (pilha != NULL)
		return ((pilha->tamanho == TAM) ? true : false);
	return(false);
}

int pilha_tamanho(PILHA *pilha){
	return ((pilha != NULL) ? pilha->tamanho: ERRO);
}


ITEM *pilha_topo(PILHA *pilha){
	if(!pilha_vazia(pilha)){
		return pilha->item[pilha->tamanho-1];
		//return pilha->tamanho-1;

	}else{
		return NULL;
	}
}


bool pilha_empilhar(PILHA *pilha, ITEM* item){
	if ((pilha!=NULL) && (!pilha_cheia(pilha))){
		pilha->item[pilha->tamanho] = item;
		pilha->tamanho++;
		return (true);
	}
	return (false);
}	


ITEM* pilha_desempilhar(PILHA* pilha){

	ITEM* i;

	if ((pilha != NULL) && (!pilha_vazia(pilha))){

		i = pilha_topo(pilha);
		pilha->item[pilha->tamanho-1] = NULL;
		pilha->tamanho--;
		return (i);
	}
	return (NULL);
}

void pilha_print(PILHA *p){

	printf("Pilha formada:\n");
	for(int i = p->tamanho - 1 ; i >= 0 ; i--){
		item_imprimir(p->item[i]);
	}

}


void pilha_inverter(PILHA *p){

	if(p){
		PILHA *pilha_aux = pilha_criar();

	    while (!pilha_vazia(p)) {
            ITEM *item = pilha_desempilhar(p);
            pilha_empilhar(pilha_aux, item);
        }

        // Transfira os elementos da pilha temporária de volta para a pilha original.
        while (!pilha_vazia(pilha_aux)) {
            ITEM *item = pilha_desempilhar(pilha_aux);
            pilha_empilhar(p, item);
        }

        // Apague a pilha temporária.
        pilha_apagar(&pilha_aux);
    }

}