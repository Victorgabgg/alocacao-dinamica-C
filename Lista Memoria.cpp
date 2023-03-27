#include <stdio.h>
#include <stdlib.h>
#define ex03

#ifdef ex01
/*Escreva um programa que leia um número N (entre 0 e 50) e em seguida leia N números reais em um vetor A. O
programa deve separar os valores lidos em A em outros dois vetores NEG e POS, o primeiro contendo somente os
valores negativos e o segundo contendo os valores positivos e zero. Apresentar na tela os vetores NEG e POS e a
quantidade de valores contidos em cada um.*/


/*Programa utilizando vetores estáticos*/ 
void exibir(double *POS, double *NEG, int contp, int contn){
	int i; 
	for(i=0; i<contp; i++){
		printf("\nOs valores positivos: %.2lf", POS[i]);
	}
	printf("\n\n");
	for(i=0; i<contn; i++){
		printf("\nOs valores negativos: %.2lf", NEG[i]);
	} 	
	
	printf("\n\n\nValores positivos: %d", contp);
	printf("\nValores negativos: %d", contn);
}


int main(){
	int n, i=0, contp=0, contn=0;
	double A[50], NEG[50], POS[50];

do{
	printf("Digite um numero entre 0 e 50: ");
	scanf("%d", &n);
}while(n < 1 || n > 50);

for(i=0;i<n;i++){
printf("\nDigite a quantidade de valores reais: ");
scanf("%lf",&A[i]);
}

for(i=0;i<n;i++){
if(A[i] >= 0)
{
	POS[contp] = A[i];
	contp++;
} 
else {
if(A[i] < 0){
	NEG[contn] = A[i];
	contn++;
}}}

exibir(POS, NEG, contp, contn);

}
#endif


#ifdef ex02
/*Teoria malloc*/ 
int main(){
	//int p* = malloc(4); 
	int *p = (int *) malloc(sizeof(int));
	*p = 1000;
	//O valor da memória pode conter lixo.  
	
	if (p == NULL){
		printf("malloc não funcinou.");
	}
	
	printf("%i", *p); 
	
	free(p);
	
	return 0;
}
#endif



#ifdef ex03
/*Utilizando vetores dinâmicos*/ 
void exibir(double *POS, double *NEG, int contp, int contn){
	int i;
	
	for(i=0;i<contp;i++){
	printf("\n\nValores positivos digitados: %.2lf", POS[i]);
	}
	
	for(i=0;i<contn;i++){
	printf("\n\nValores negativos digitados: %.2lf", NEG[i]);
	}
	
	printf("\n\nA quantidade de positivos digitados: %d", contp);
	printf("\nA quantidade de negativos digitados: %d", contn);
}


int main(){
	int n, i=0, contp=0, contn=0; 
	double *POS, *NEG, *A; 

	do{
	printf("Digite a quantidade de N: ");
	scanf("%d", &n);
	}while (n < 1 || n > 50);
	
	A = (double *) malloc(sizeof(double) * n);
	
	for(i=0;i<n;i++){
		printf("Digite os termos: ");
		scanf("%lf", &A[i]);
	}
	
	
	POS = (double *) malloc(sizeof(double) * n);
	NEG = (double *) malloc(sizeof(double) * n );
	
	for(i=0;i<n;i++){
		if (A[i] >= 0){
			POS[contp] = A[i];
			contp++;
		}
		else{
			NEG[contn] = A[i];
			contn++;
		}
	}
	exibir(POS, NEG, contp, contn);

	free(A);
	free(POS);
	free(NEG);
	
	return 0;
}
#endif
