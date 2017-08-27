#include <stdio.h>
#define TAM 10000

int ordenador(int vetor[], int vetor2[], int contro){ //O
	int i, j, aux;

	for( i=0; i<contro; i++ ){
	    for( j=i+1; j<contro; j++ ){
	        if( vetor2[i] > vetor2[j] ){
	            aux = vetor2[i];
	            vetor2[i] = vetor2[j];
	            vetor2[j] = aux;
	        }
		}
		//printf("==>> %i\n", vetor[i]);
	}
}

int somador(int val[], int val2[], int contro){ //Verifiva se é negativo e transforma para positivo e calcula o valor sequencial
	int i;

	for(i=0;i<contro;i++){
		val2[i] = val[i];
		if(val2[i]<0){
			val2[i] *= -1;
		}
		
		val2[i] = ((1+val2[i])*val2[i])/2;
		
	}

}


int main(){
	int x, y, vet[TAM], vet2[TAM], vet3[TAM], i;

	printf("# DIGITE QUANTOS VALORES VOCE QUER REGISTRAR != (> 10000 & ==0)\n");
	scanf("%i",&x);

	if((x > TAM) || (x == 0)){
		printf("#ERRO VALOR INVÁIDO\n");
		printf("ERRO. TAMANHO INVALIDO\n");
	}else{
		printf("Digite %i numeros positivos ou negativos sem repetir\n",x);

		for(i=0;i<x; i++){ // FOr para
			scanf("%i",&vet[i]);
			for(y=0;y<i;y++){
				if(y==i){
					continue;
				}
				if(vet[y] == vet[i]){
					printf("ERRO. JA EXISTE\n");
					printf("# Digite Novamente\n");
					i--;
				}
			
			}
			
		vet2[i] = vet[i];
		
		}

		ordenador(vet,vet2,x);
		somador(vet2,vet3,x);

		printf("VOCE DIGITOU TODAS AS %i \n",x);
		for(i=0;i<x;i++){
			(vet3[i]<50001)?printf("Somatorio %i: %i\n",vet2[i], vet3[i]):printf("Somatorio %i: ERRO \n",vet2[i]);
		}

		



	}//else principal
}

/*
vet[] == valores recebidos
vet2[] == valores ordenados
vet3[] == sequenciais



*/