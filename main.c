#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pesquisa_sequencial.h"
#include "ordenacao.h"
#include "Arvore_binaria.h"
#include "Hash_direto.h"
#include "Hash_indireto_encadeado.h"
#include <time.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) {

	clock_t start_time, end_time;//variaveis para tempo
	FILE *fl;
    int c,i;
    char palavra[22];
	start_time  = clock();//inicio tempo

	//abrindo arquivo
	fl = fopen("texto.txt", "r");
    if(fl == NULL){
        perror("Erro: fopen");
    }

	//escolhendo pesquisa
	printf("digite um numero para escolher qual o modo de pesquisa:\n 1-Pesquisa Sequencial\n 2-Pesquisa binaria\n 3-Arvore Binaria\n 4-Hash Direto\n 5-Hash indireto\n 6-Ordenação\n");
	scanf("%i",&c);
	
	if(c==1){
		// pesquisa sequencial
		printf("digite a palavra que deseja procurar:\n");
		scanf("%s",&palavra);
		pesquisa_seq(fl, palavra);
	}
	else if(c==2){
		//pesquisa binaria
		ordenacao(fl,2);
	}
	else if(c==3){
		//arvore binaria
		arvore_binaria(fl);
		
	}
	else if(c==4){
		//tabela hash com area reserva
		tabela(fl);
		
	}
	else if(c==5){
		//tabela hash com lista encadeada
		tabela_hash(fl);
	}
	else if(c==6){
		//ordenação
		ordenacao(fl,1);
	}

	end_time = clock();

	printf("Tempo de execução: %lu em milesimos de segundos.\n",end_time-start_time);// printa o tempo
	system("pause");
	fclose(fl);
}

