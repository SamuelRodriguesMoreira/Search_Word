#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pesquisa_binaria.h"
/*	
int pesquisa_bi(int esq, int dir,char linha[10000],char *palavra){
	int meio = (esq+dir)/2;
	int resp = -1;

	if(strcmp(linha[meio],*palavra )==0){
		resp = meio;
	} else if(strcmp(palavra, linha[meio])<0){ 
		resp = pesquisa_bi(esq, meio-1, linha, *palavra);
	} else if(strcmp(palavra, linha[meio])>0){
		resp = pesquisa_bi(meio+1, dir, linha, *palavra);
	}
	return resp;
}*/
