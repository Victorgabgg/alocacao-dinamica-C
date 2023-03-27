/*Escreva um programa que leia um arquivo de entrada chamado SCORES.TXT. Esse arquivo contém um número inteiro em cada linha
que devem ser obrigatoriamente carregados em um vetor dinâmico. Em seguida, mostre na tela os 5 maiores valores. Para efeito de
testes sabe-se que o arquivo de entrada tem pelo menos 5 linhas e que os valores não estão em qualquer ordem.*/

#include <stdio.h>
#include <stdlib.h>

void exibe(int cont, int *Scores){
	int i;
	
	for(i=0; i<5; i++){
	printf("%d\n", Scores[i]);
	}
}

void MaioresCont(int cont, int *Scores){
	int i, j, aux;
	
	for(i=0; i<cont; i++){
		for(j=i+1; j<cont; j++){
			if (Scores[i] < Scores[j]){
			aux = Scores[j];
			Scores[j] = Scores[i];
			Scores[i] = aux; 
			}
		}
	}
}

int main(){
	int i=0, cont=0, X;
	int *Scores;
	FILE *file; 
	
	//Leitura do arquivo
	file = fopen("SCORES.txt", "r");
	if (file == NULL){
		printf("Arquivo inexistente.");
		return 0;
	}

	while(fscanf(file, "%d", &X) != EOF){
	cont++;
	Scores = (int *) realloc(Scores, sizeof(int) * cont);
	Scores[cont-1] = X;
	}
	MaioresCont(cont, Scores);
	exibe(cont, Scores);
	
	printf("\n\nFim do Programa");
	fclose(file);
	free(Scores);
	return 0;
}
