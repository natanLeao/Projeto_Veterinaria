#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "funcoes.c"
#include "funcoes.h"

/* Constantes */
#define SUCESSO 0

int main() {
	int opcao, num_pets = 0;
	char lixo;
	cadastro_t* info = NULL;

	do {

		// Impressao do menu de opcoes
		printf("\nVeterinaria Bichinho Feliz  \n"\
				"-----------------------------\n"\
			   	"1 - Cadastrar Pet            \n"\
				"2 - Listar Pets              \n"\
				"3 - Lista de Gravidade       \n"\
				"0 - Sair                     \n");
		printf("Digite a opcao [0:3]: ");
		scanf("%d%c", &opcao, &lixo);
		printf("\n");

		// Opcoes
		switch (opcao) {

		case 0: 
			break;

		case 1:
			info = cadastroPet(info, &num_pets);
			break;

		case 2:
			imprimeTabela(info);
			break;

		case 3:
		imprimeTabelaOrdenada(info);
			break;

		default:
			printf("Opcao invalida!\n");
			break;
		}

	} while (opcao != 0);

	printf("Volte Sempre na Veterinaria Bichinho Feliz!\n");  

	return SUCESSO;
}
