#include <stdio.h>
#define TAM 10000

int somador(int val[], int val2[], int contro){ //Verifiva se é negativo e transforma para positivo e calcula o valor sequencial
	int i;

	for(i=0;i<contro;i++){
		val2[i] = val[i];
		if(val2[i]<0){
			val2[i] *= -1;
		}
		printf("==>> %i\n", val2[i]);
		val2[i] = ((1+val2[i])*val2[i])/2;
		
	}

}

int ordenador(int vetor[], int contro){
	int i, j, aux;

	for( i=0; i<5; i++ ){
	    for( j=i+1; j<10; j++ ){
	        if( vetor[i] > vetor[j] ){
	            aux = vetor[i];
	            vetor[i] = vetor[j];
	            vetor[j] = aux;
	        }
		}
	}
}

int main(){
	int x, y, vet[TAM], vet2[TAM], i;

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
			

		}

		ordenador(vet,x);
		//somador(vet,vet2,x);

		printf("VOCE DIGITOU TODAS AS %i \n",x);
		for(i=0;i<x;i++){
			printf(">>> %i\n",vet[i]);
		}

	
	}//else principal
}

/*
vet[] == valores recebidos
vet2[] == valores ordenados
vet3[] == sequenciais



*/