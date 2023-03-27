 /*Escreva um programa que leia dois números inteiros Min e Max. O programa deve garantir que Min seja um número maior que 1 e
Max seja um número maior que Min. Em seguida carregue um vetor dinâmico com todos os números primos situados no intervalo
fechado [Min, Max] e exiba-os na tela. Adicionalmente grave todos esses números primos em um arquivo de saída com o nome
PRIMOS.TXT, sendo um valor em cada linha.

# JOGNA2 – Entrega N1.A – Grupo // */ 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool Primo(int num){
	int n; 
		
	for(n=2; n<=sqrt(num); n++){
		if(num % n == 0){
			return false;
		}
	}
	return true; 
}

int main(){
	int Min, Max, i, cont, cont2, n, r; 
	int *Primos; 
	FILE *Arq;

	do{
		printf("Digite o Min maior que 1: ");
		scanf("%d", &Min);
	}while (Min <= 1);

	do{
		printf("Digite o Max maior que Min: ");
		scanf("%d", &Max);
	}while (Max <= Min);

	Primos = (int *) malloc(sizeof(int) * Max);
	cont = 0;
	for(i=Min; i<Max; i++){
	if (Primo(i)){
		Primos[cont++] = i;
		}
	}
	for (i=0; i < Max; i++){
		printf("%d", Primos[i]);
	}
	Arq = fopen("PRIMOS.txt", "w");
	for(r=0; r<cont; r++){
	printf("\nCont primos: %d", Primos[r]);
	fprintf(Arq, "%d\n", Primos[r]);
	}
	fclose(Arq);
	free(Primos);
	
	printf("\n\nFim do Programa.");
}
