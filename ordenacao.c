#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"
#define _GNU_SOURCE
   

   //variaveis usadas na pesquisa binaria e armazenamento de palavras
   typedef struct lista{
		char palavra[22];
		int quant;
	}Lista;

	Lista list[1024];

	char palavra_chave[21];
	int utilizacao = 0;

void ordenacao(FILE *file, int indice){
	 
	int resp=0;
	char aux[21];
	int posicao = 0;
	char linha[10000];
	char *palavras;
	int i = 0;
	int j = 0;
	int Total_palavra = 0;
	char palavra_temp[21];
	
//	palavra_chave == "pierre";

	for(i=0; i<1024;i++){
		list[i].quant = 0;
	}

	while(fgets(linha,10000,file)){
		palavras = strtok(linha, " ´^`~*¨$#@:.,-_!?= \n\t");
		
		while(palavras != NULL){
			strcpy(palavra_temp, palavras);
			palavras = strtok(NULL, " ´^`~*¨$#@:.,-_!?= \n\t");
			strlwr(palavra_temp);
			// printf(" palavra: %s",palavra_temp);
			
			if(Total_palavra == 0){				
				strcpy(list[0].palavra, palavra_temp);
				list[0].quant = 1;
				Total_palavra++; 
			}
			else{
				for(j=0; j<1024; j++){
					if(Total_palavra <= j){
						strcpy(list[j].palavra, palavra_temp);
						list[j].quant = list[j].quant + 1;
						Total_palavra++;
						j=1024;
					}
					else if(strcmp(list[j].palavra,palavra_temp) == 0){
						list[j].quant++;
						j=1024;
					}
				}
			}
			i++;
		}
	}	
	
	for(i=0;i<Total_palavra;i++){
		for(j=i+1;j<Total_palavra;j++){
			if(strcmp(list[j].palavra, list[i].palavra) < 0){
				strcpy(aux,list[j].palavra);
				strcpy(list[j].palavra,list[i].palavra);
				strcpy(list[i].palavra,aux);
			}
		}
	}
	
	for(i=0;i<Total_palavra;i++){
			printf(" \n %s \t %i \n ", list[i].palavra,list[i].quant);
	}
	printf("Total de palavras %i\n", Total_palavra);
	if(indice == 2){
		Total_palavra = Total_palavra - 1;
		// pesquisa binaria
		pesquisa_binaria(0,Total_palavra);
		printf("utilização da pesquisa binaria:%i\n",utilizacao);
	}
}

void pesquisa_binaria (int esq, int dir){

	int meio = (esq + dir)/2;

	if(utilizacao == 0){
		printf("Digite a palavra que deseja pesquisar:\n");
		scanf("%s",&palavra_chave);
	}

	if(strcmp(list[meio].palavra, palavra_chave) == 0){
		printf("achou!!!");
	}
	else if(strcmp(list[meio].palavra,palavra_chave)>0){
		utilizacao++;
		pesquisa_binaria(esq,meio - 1);
	}
	else if(strcmp(list[meio].palavra,palavra_chave)<0){
		utilizacao++;
		pesquisa_binaria(meio + 1, dir);
	}
}

