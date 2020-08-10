#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "pesquisa_sequencial.h"

int utilizacaoPS = 0;

void pesquisa_seq(FILE *file, char *palavra){
	
	char linha[10000];
	char *palavras = NULL;
	
	while(fgets(linha,10000,file)){
		
		palavras = strtok(linha, ":.,-_!?= \n\t");
		// printf("%s", palavras);
		//função ja pesquisa se existe a palavra no arquivo
		while(palavras != NULL){
			
			if(strcmp(palavras, palavra)==0){
				printf("achou!!!\n");				
				palavras = NULL;
			}
			utilizacaoPS++;
			palavras = strtok(NULL, ":.,-_!?= \n\t");
		}	
	}
	printf("\nUtilização: %i\n",utilizacaoPS);
	// system("pause");
}

