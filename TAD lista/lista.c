//TAD lista - sequencial e ordenado, implementar itens ordenados

// lista.h

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

struct lista_{

	ITEM *lista[TAM_MAX];
	int inicio; //inicio da lista
	int fim; //fim da lista, atual tamanho, e posicao livre pra inserir elem
};

//cria uma lista vazia - "separa" espaco na mem para alocar a struct lista

LISTA *lista_criar(void){

	LISTA *l = (LISTA*)malloc(sizeof(LISTA)); //alocando espaco na mem
	if(l != NULL){
		l->inicio = inicial; //var definida no .h = 0
		l->fim = l->inicio; //tambem aponta para o inicio
		//ja que a lista está vazia, sem elementos
	}

	return(l); //retorna o endereco base da mem onde foi alocado
}


bool lista_inserir(LISTA *l, ITEM *item){

	//busca sequencial

	int inicio = lista->inicio;
	int tam = lista->fim;

	if(l != NULL){

		for (int i = inicio; i < tam; i++) {
	        if (l->lista[i]->chave == chave) {
	            // Encontrou o item com a chave desejada
	            return lista->lista[i];
	        }
	    }
	}





	if((l != NULL) && !lista_cheia(l)){
		(l->lista[l->fim]) = item;
		l->fim++; //o fim tambem eh usado como o tamanho final, incrementa a cada vez que adicionamos um novo item
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

	if(lista != NULL){
		lista->inicio

	}


}




void lista_apagar(LISTA **lista){
	//apagar a lista completa?? sim acho, que sim
    if (*lista != NULL) {
        free(*lista);
        *lista = NULL; //atribuindo valor null para aliberar mem completamente
    }

}


ITEM *lista_busca(LISTA *lista, int chave){

  	if (lista == NULL || lista_vazia(lista)) {
        return NULL; //lista vazia ou não inicializada
    }

	for (int i = lista_->inicio; i < lista->fim; i++) {
        if (l->lista[i]->chave == chave) {
            // Encontrou o item com a chave desejada
            return lista->lista[i];
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
    return 0;
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
        return 0;
    }

    for (int i = lista->inicio; i < lista->fim; i++) {
        printf("Chave: %d\n", lista->lista[i]->chave);
        // Você pode adicionar outras informações do item aqui
    }


}

	  



//lista -> é o ponteiro onde estamos alocando a nossa struct LISTA
