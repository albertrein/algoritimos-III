#include <stdio.h>
#define TAM 10000

int ordenador(int vetor[], int vetor2[], int contro){ //O
	int i, j, aux;

	for(i=0;i<contro;i++){
	    for(j=i+1;j<contro;j++){
	        if( vetor2[i] > vetor2[j] ){
	            aux = vetor2[i];
	            vetor2[i] = vetor2[j];
	            vetor2[j] = aux;
	        }
		}
		//printf("==>> %i\n", vetor[i]);
	}
	printf("#ORDENADO COM SUCESSO\n\n");
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

	printf("# Somatorios: \n");
	for(i=0;i<contro;i++){
		(val2[i]<50001)?printf("Somatorio %i: %i\n",val[i], val2[i]):printf("Somatorio %i: ERRO \n",val[i]);
	}
	printf("\n\n");
}

int primosrelativos(int vetor0[],int vetor02[], int contro){
	int i,j, y, z, controle;
	int x1[9],x2[9];
	//div variaveis que contem o numero de valores divisiveis no vetor
	for(i=0;i<contro;i++){
		// if(vetor02[i] < 0){ 
		// 	vetor02[i] *= -1;
		// }//pegar o vet2 ordenado e trasfonrma todos em maiusculas
	}	

	for(i=0;i<contro;i++){
		y=0;
		z=i+1;
		if(z==contro){z=0;}
		for(j=2;j<=10;j++){			
			if(((vetor02[i]%j)==0)&&((vetor02[z]%j)==0)){
				printf("%i e %i: NÃO SÃO PRIMOS RELATIVOS\n",vetor02[i],vetor02[z]);
				break;
			}else{
				y++;
			}		
		}
		if(y!=0){
			printf("%i e %i: primos relativos\n",vetor02[i],vetor02[z]);
		}
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
		primosrelativos(vet,vet2,x);

		// printf("VOCE DIGITOU TODAS AS %i \n",x);
		// for(i=0;i<x;i++){
		// 	(vet3[i]<50001)?printf("Somatorio %i: %i\n",vet2[i], vet3[i]):printf("Somatorio %i: ERRO \n",vet2[i]);
		// }

		



	}//else principal
}

/*
vet[] == valores recebidos
vet2[] == valores ordenados
vet3[] == sequenciais



*/