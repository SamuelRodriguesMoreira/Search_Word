#include<stdio.h>
#include<stdlib.h>
#include<string.h>

	int utilizacaoHD = 0;

	int size = 1024 + 1024/2;
	int usoReserva = 0;
	
	struct lista{
		char palavra[21];
		int chave;
		int qunatidade;
	};

	typedef struct lista linhas;
	linhas linhaH[1536];
	
	
int valorASC(char *palavra){
	int i;
	int valor = 0;
	for(i=0;i<strlen(palavra);i++){
		valor+=(palavra[i]/8);
	}
	return valor;
}

//inserir na posicao e se houver colisao ja inseri na area reserva
void insereHD(char *palavra){
	int valor = valorASC(palavra);
	int cout = 1024 + usoReserva;
	if(linhaH[valor].qunatidade == 0){
		linhaH[valor].chave = valor;
		strcpy(linhaH[valor].palavra,palavra);
		linhaH[valor].qunatidade = 0;
		linhaH[valor].qunatidade = linhaH[valor].qunatidade + 1; 
	}
	else{
		if(strcmp(linhaH[valor].palavra,palavra)==0){
			linhaH[valor].qunatidade = linhaH[valor].qunatidade + 1;
		}
		else{
			for(int i=1024;i<1536;i++){
				if(usoReserva == 0){
					linhaH[i].chave = valor;
					strcpy(linhaH[i].palavra,palavra);
					linhaH[i].qunatidade = 0;
					linhaH[i].qunatidade = linhaH[i].qunatidade + 1;
					usoReserva ++;
					i = 2000;
				}
				else if(strcmp(linhaH[i].palavra,palavra)==0){
					linhaH[i].qunatidade = linhaH[i].qunatidade + 1;
					i = 2000;
				}
				else if(cout = i){
					linhaH[i].chave = valor;
					strcpy(linhaH[i].palavra,palavra);
					linhaH[i].qunatidade = 0;
					linhaH[i].qunatidade = linhaH[i].qunatidade + 1;
					usoReserva ++;
					i=2000;
				}
			}
		}
	}
}


//funcao pesquisa
void searche(char *palavra){
	int valor = valorASC(palavra);
	int i;
	
	if(linhaH[valor].qunatidade == 0){
		printf("\npalavra n�o encontrada\n");
	}
	else if(strcmp(linhaH[valor].palavra,palavra)==0){
		printf("\nPalavra encontrada.\nPalavra:%s\tchave:%i\tquantidade:%i\n",linhaH[valor].palavra,linhaH[valor].chave,linhaH[valor].qunatidade);
		utilizacaoHD++;
	}
	else if(strcmp(linhaH[valor].palavra,palavra)!=0){
		for(i=1024;i<1536;i++){
			if(strcmp(linhaH[i].palavra,palavra)==0){
				printf("\nPalavra encontrada.\nPalavra:%s\tchave:%i\tquantidade:%i\n",linhaH[i].palavra,linhaH[i].chave,linhaH[i].qunatidade);
			}
			else if(i>usoReserva){
				printf("\npalavra n�o encontrada\n");
				i=2000;
			}
		}
	}
}

void tabela(FILE *file){

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
			
			insereHD(palavra_temp);
		
		}
	}
	
	printf("Digite a palavra para procurar:");
	scanf("%s",&palavra_chave);
	searche(palavra_chave);
	printf("utilização: %i\n",utilizacaoHD);
	system("pause");
}
