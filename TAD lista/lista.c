//TAD lista - sequencial e ordenado, implementar itens ordenados

// lista.h

#include "lista.h"
#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct lista_{

	ITEM *lista[TAM_MAX];
	int inicio; //inicio da lista
	int fim; //fim da lista, atual tamanho, e posicao livre pra inserir elem
};

//cria uma lista vazia - "separa" espaco na mem para alocar a struct lista

LISTA *lista_criar(void){

	LISTA *lista = (LISTA*)malloc(sizeof(LISTA)); //alocando espaco na mem
	if(lista != NULL){
		lista->inicio = inicial; //var definida no .h = 0
		lista->fim = lista->inicio; //tambem aponta para o inicio
		//ja que a lista está vazia, sem elementos
	}

	return(lista); //retorna o endereco base da mem onde foi alocado
}


bool lista_inserir(LISTA *lista, ITEM *item){
//busca sequencial

	int inicio = lista->inicio;
	int tam = lista->fim;

	for(int i = inicio; i < tam; i++) {
        if(lista->lista[i]->chave == item->chave) {
            // Encontrou o item com a chave desejada
            return lista->lista[i];
        }
    }


	if((lista != NULL) && !lista_cheia(lista)){
		(lista->lista[lista->fim]) = item;
		lista->fim++; //o fim tambem eh usado como o tamanho final, incrementa a cada vez que adicionamos um novo item
		//se tudo der certo ao inserir item, e inicializar, devolvemos true
		return(true);
	}
	return(false);
}
 

/*
insercao de item na lista
precondicao - lista nao deve estar cheia
poscondicao - inserir o item em uma posicao em que a lista continua ordenada

*/


ITEM *lista_remover(LISTA *lista, int chave){

	if (lista != NULL && !lista_vazia(lista)) {

	    for (int i = lista->inicio; i < lista->fim; i++) {
	        if (lista->lista[i]->chave == chave) {
	            ITEM *removido = lista->lista[i];
	            // Move os itens subsequentes uma posição para trás
	            for (int j = i; j < lista->fim - 1; j++) {
	                lista->lista[j] = lista->lista[j + 1];
	            }
	            lista->fim--;
	            return removido;
	        }
	    }
	}

    return NULL;


}




void lista_apagar(LISTA **lista){
	//apagar a lista completa?? sim acho, que sim
    /*if (*lista != NULL) {
        free(*lista);
        *lista = NULL; //atribuindo valor null para aliberar mem completamente
    }*/

	if(lista && *lista) {
        for (int i = 0; i < (*lista)->fim; i++) {
            free((*lista)->lista[i]);
        }
        free(*lista);
        *lista = NULL;
    }




}


ITEM *lista_busca(LISTA *lista, int chave){

  	if(lista != NULL && !lista_vazia(lista)){

		for(int i = lista->inicio; i < lista->fim; i++) {
		    if(lista->lista[i]->chave == chave) {
		        // Encontrou o item com a chave desejada
		        return lista->lista[i];
		    }
		}
    }
    return NULL;
}



int lista_tamanho(LISTA *lista){
//retorna o tamanho atual da lista
	//acho valido apenas acessar o conteudo que está dentro da struct e imprimir
    if (lista != NULL) {
        return lista->fim - lista->inicio;
    }
    return ERRO;
	//return ((lista != NULL) ? lista->fim : ERRO);

}

bool lista_vazia(LISTA *lista){

	//compara com o numero de inicio
	//se fim  == inicio lista está vazia

	if(lista == NULL){
		return (true); 
		//se a lista aponta para null ou ela nao foi criada
		//ou que ela nao foi inicializada do jeito correto
		//ou ela está realmente vazia
	} 

	if((lista->inicio) == (lista->fim)){
		return (true);
	}
	return (false);
}



bool lista_cheia(LISTA *lista){

	//mostra se a lista está cheia, comparando o fim com o tamanhho final

	if(lista == NULL){
		return(false);
	}

	if(lista->fim == TAM_MAX){
		return(true);
	}
	return false;
}


void lista_imprimir(LISTA *lista){
	//imprimir a lista ordenada
	if (lista == NULL || lista_vazia(lista)){
        printf("Lista vazia\n");
    }

    for (int i = lista->inicio; i < lista->fim; i++) {
        printf("Chave: %d\n", lista->lista[i]->chave);
        // Você pode adicionar outras informações do item aqui
    }
}

	  