#ifndef FUNCAO_H
#define FUNCAO_H
#define NUM_MAX 50

/// Estrutura com os campos de dados da Veterinaria
typedef struct dados_vet_s{
	int ID;
	char nome[NUM_MAX];
	int info;
	int gravidade;
	struct dados_vet_s *prox;
} cadastro_t;

//lista encadeada
typedef struct lista_s{
	int info;
	struct lista_s *prox;
} lista_t;

cadastro_t *petP(int idAtual);
cadastro_t *cadastroPet(cadastro_t *p, int *num_pets);
void imprimeTabela(cadastro_t *p);
void imprimeTabelaOrdenada(cadastro_t *p);

lista_t *lista_cria();
int lista_maior_num(lista_t *l);

#endif
