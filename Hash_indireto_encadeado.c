#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estruturas e variaveis utilizadas

	int utilizacaoHIE=0;

	typedef struct lista colunas;
	struct lista{
		char palavra[21];
		int quantidade;
		int chave;
		struct lista *next;
	};
	
	
	colunas posicao[1024];

int valorASCH(char *palavra){
	int i;
	int valor = 0;
	for(i=0;i<strlen(palavra);i++){
		valor+=(palavra[i]/8);
	}
	return valor;
}

//funcao para se caso ouver colição, essa função procura na lista encadeada
void procura_ponteiro(colunas *next, char *palavra_chave, int valor){
	if(next == NULL){
		printf("palavra não encontrada\n");
	}
	else if(strcmp(next->palavra,palavra_chave)==0){
		printf("palavra encontrada:\n%s\t%i\t%i\n",next->palavra,next->chave,next->quantidade);
		utilizacaoHIE++;
	}
	else{
		procura_ponteiro(next->next,palavra_chave,valor);
	}
	
}

//funcao para procurar a palavra
void procura_palavra(char *palavra_chave){
	int valor = valorASCH(palavra_chave);

	if(posicao[valor].quantidade == 0){
		printf("palavra não encontrada");
	}
	else{
		if(strcmp(posicao[valor].palavra,palavra_chave)==0){
			printf("Palavra encontrada:\n%s\t%i\t%i",posicao[valor].palavra,posicao[valor].chave,posicao[valor].quantidade);
			utilizacaoHIE++;
		}
		else{
			procura_ponteiro(posicao[valor].next,palavra_chave,valor);
		}
	}
	
}
// função para criar uma nova celula em caso de colisão
colunas *nova_celula(colunas *next,char *palavra, int valor){
	if( next == NULL){
		next = (colunas*)malloc(sizeof(colunas));
		strcpy(next->palavra,palavra);
		next->chave = valor;
		next->quantidade = 0;
		next->quantidade = next->quantidade + 1;
		next->next = NULL;
		return next;
	}
	else if(strcmp(next->palavra,palavra)==0){
		next->quantidade = next->quantidade + 1;
	}
	else{
		next->next =nova_celula(next->next,palavra,valor);
	}
	return next;
}
//função inserir
void *inserir(char *palavra_temp){
	int valor = valorASCH(palavra_temp);
	
	if(posicao[valor].quantidade == 0){
		strcpy(posicao[valor].palavra,palavra_temp);
		posicao[valor].quantidade = 0;
		posicao[valor].quantidade = posicao[valor].quantidade + 1;
		posicao[valor].chave = valor;
		posicao[valor].next = NULL;
	}
	else{
		if(strcmp(posicao[valor].palavra,palavra_temp)==0){
			posicao[valor].quantidade = posicao[valor].quantidade + 1;
		}
		else{
			posicao[valor].next = nova_celula(posicao[valor].next,palavra_temp,valor);
		}
	}
}

void tabela_hash(FILE *file){
	
	
	char linha[10000];
	char *palavras;
	char palavra_temp[21];
	char palavra_chave[21];

	for(int j=0;j<1024;j++){
		posicao[j].quantidade = 0;
	}

	while(fgets(linha,10000,file)){
		palavras = strtok(linha, " ´^`~*¨$#@:.,-_!?= \n\t");
		
		while(palavras != NULL){
			strcpy(palavra_temp, palavras);
			palavras = strtok(NULL, " ´^`~*¨$#@:.,-_!?= \n\t");
			strlwr(palavra_temp);
			inserir(palavra_temp);
		}
	}

	printf("digite a palavra para pesquisa:");
	scanf("%s",palavra_chave);
	printf("\nutilização: %i",utilizacaoHIE);
	procura_palavra(palavra_chave);
	system("pause");
}
