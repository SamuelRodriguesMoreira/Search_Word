#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Arvore_binaria.h"

//estruturas usadas em arvore binaria

	int utilizacaoThree = 0;

int Total_palavra = 0;

	struct node{
		char palavra[21];
		int quantidade;
		struct node *dir;
		struct node *esq;
	};
	
	typedef struct node no;
	
// função para inserir valor na arvore
no *insere(no *raiz, char *palavra_temp){
	if(raiz == NULL){
		no *aux = (no*)malloc(sizeof(no));
		strcpy(aux->palavra,palavra_temp);
		aux->quantidade = 0;
		aux->quantidade = aux->quantidade + 1;
		aux->dir = NULL;
		aux->esq = NULL;
		Total_palavra ++;
		return aux;
	}
	else if(strcmp(raiz->palavra,palavra_temp) == 0){
		raiz->quantidade = raiz->quantidade + 1;
		 return raiz;
	}
	else{
		if(strcmp(raiz->palavra,palavra_temp)>0){
			raiz->dir = insere(raiz->dir,palavra_temp);
		}
		else if(strcmp(raiz->palavra,palavra_temp)<0){
			raiz->esq = insere(raiz->esq,palavra_temp);
		}
	}
	return raiz;
	
}

//funcao de pesquisa na arvore
no *search(no *root,char *palavra_chave){
	int achou=0;
	if(root!=NULL){
		if(strcmp(root->palavra,palavra_chave)==0){
			printf("%s\t%i",root->palavra,root->quantidade);
			return root;
			utilizacaoThree = utilizacaoThree + 1;
		}
		else{
			if(strcmp(root->palavra,palavra_chave)>0){
				search(root->dir,palavra_chave);
				utilizacaoThree = utilizacaoThree + 1;
			}
			else if(strcmp(root->palavra,palavra_chave)<0){
				search(root->esq,palavra_chave);
				utilizacaoThree = utilizacaoThree + 1;
			}
		}
	}
	else{
		return NULL;
	}
}

//função para limpar a arvore
void *tfree(no *root){
	if(root != NULL){
		tfree(root->dir);
		tfree(root->esq);
		free(root);
	}
}

//funcao para inicializar a arvore
no *inicializar(){
	return NULL;
}

//função para printar todos os valores da arvore
void printar(no *raiz){
	if(raiz != NULL){
		printf("%s\t%i\n",raiz->palavra,raiz->quantidade);
		printar(raiz->dir);
		printar(raiz->esq);
	}
}

void arvore_binaria(FILE *file){
	
	// algumas variaveies principais
	no *raiz = inicializar();//função para inicializar
	char linha[10000];
	char *palavras;
	char palavra_temp[21];
	char palavra_chave[21];

	while(fgets(linha,10000,file)){
		palavras = strtok(linha, " ´^`~*¨$#@:.,-_!?= \n\t");
		
		while(palavras != NULL){
			strcpy(palavra_temp, palavras);
			palavras = strtok(NULL, " ´^`~*¨$#@:.,-_!?= \n\t");
			strlwr(palavra_temp);
		
			raiz = insere(raiz,palavra_temp);// chama a função insere na linha 18
		}
	}

	printar(raiz);// chama função para printar todos os valores
	printf("digite a palavra para procurar;\n");
	scanf("%s",&palavra_chave);
	no *achar = search(raiz,palavra_chave);//pesquisa na arvore
	if(achar == NULL){
		printf("palavra n�o encontrada");
	}
	printf("\nTotal de palavras �: %i\n",Total_palavra);
	system("pause");
	printf("\nutilizada: %i\n",utilizacaoThree);
	tfree(raiz);
}
