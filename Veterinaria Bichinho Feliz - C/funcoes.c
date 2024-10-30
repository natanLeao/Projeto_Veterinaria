#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

/// Valor inicial do ID
#define ID_VALOR_INICIAL 10

#define INT_MAX 0

cadastro_t* petP(int idAtual) {
	cadastro_t *info = (cadastro_t*)malloc(sizeof(cadastro_t));
	info->ID = idAtual;

	printf("Digite o nome do Pet: ");
    scanf("%s", info->nome);

	printf("\nNivel de Gravidade\n"\
			"-----------------\n"\
			"1 - Leve         \n"\
			"2 - Media        \n"\
			"3 - Grave        \n"\
			"4 - Gravissima   \n");
	printf("Digite a gravidade do Pet [1:4]: ");
	scanf("%d", &(info->gravidade));

	info->prox = NULL;
	
	// Retorna o item recem criado
	return info;
}

cadastro_t* cadastroPet(cadastro_t *p, int *num_pets) {
	int proximoID = ID_VALOR_INICIAL + *num_pets;
	cadastro_t* novo_pet = petP(proximoID);

	if (p == NULL) {
        p = novo_pet;
    } else {
        cadastro_t *temp = p;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo_pet;
    }

    (*num_pets)++;
    return p;
}

void imprimeTabela(cadastro_t *p) {
	cadastro_t *temp = p;

  	printf("\n-------LISTA DE CADASTRO-------\n\n");
    printf("     ID     |    Nome    |    Gravidade    \n");
    printf("-------------------------------------------\n");

  	while (temp != NULL) {
        printf("     %d     |    %s    |        %d        \n", temp->ID, temp->nome, temp->gravidade);
        temp = temp->prox;
    }
}


lista_t* lista_cria() {
	return NULL;
}

void imprimeTabelaOrdenada(cadastro_t *p) {
    if (p == NULL) {
        printf("Nenhum pet cadastrado.\n");
        return;
    }

    // Conta o número de pets
    int count = 0;
    cadastro_t *temp = p;
    while (temp != NULL) {
        count++;
        temp = temp->prox;
    }

    // Cria um array para ordenação
    cadastro_t **array = (cadastro_t**)malloc(count * sizeof(cadastro_t*));
    temp = p;
    for (int i = 0; i < count; i++) {
        array[i] = temp;
        temp = temp->prox;
    }

    // Ordena o array pela gravidade
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (array[i]->gravidade < array[j]->gravidade) {
                cadastro_t *aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }

    // Imprime a tabela ordenada
    printf("\n----LISTA DE ATENDIMENTO (ORDENADA POR GRAVIDADE)----\n\n");
    printf("     ID     |    Nome    |    Gravidade    \n");
    printf("--------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("     %d     |    %s    |        %d        \n", array[i]->ID, array[i]->nome, array[i]->gravidade);
    }

    free(array);
}

int lista_maior_num(lista_t *l) {
    int maior = INT_MAX;

    for (lista_t *i = l; i != NULL; i = i->prox) { 
        if (i->info > maior) {
            maior = i->info;
        }
    }

    return maior;
}
