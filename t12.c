#include <stdio.h>
#define TAM 10000

int ordenador(int vetor[], int vetor2[], int contro){ //O
	int i, j, aux;

	for(i=0;i<contro;i++){	//ORDENA EM CRESCENTE
		j=i+1;
	    for(;j<contro;j++){
	        if(vetor2[i] > vetor2[j]){
	            aux = vetor2[i];
	            vetor2[i] = vetor2[j];
	            vetor2[j] = aux;
	        }
		}
	}	
}

int somador(int val[], int val2[], int contro){ //Verifiva se é negativo e transforma para positivo e calcula o valor sequencial
	int i;

	for(i=0;i<contro;i++){
		val2[i] = val[i];
		if(val2[i]<0){
			val2[i] *= -1;
		}		
		val2[i] = ((1+val2[i])*val2[i])/2; //Formula matematica para a soma da progressão aritimética
	}	
}

int primosrelativos(int vetor0[],int vetor02[], int contro){
	int i,j, y, z, controle;
	
	for(i=0;i<contro;i++){
		y=1;
		z=i+1;
		if(z==contro){
			z=0;
		} //Verifica se terminou o for

		//(vetor02[i]<vetor02[z])?controle=vetor02[i]:controle=vetor02[z];
		if(vetor02[i] < vetor02[z]){
			controle = vetor02[i];
		}else{
			controle = vetor02[z];
		}

		if(controle < 0){
			controle *= -1;
		}
		//(controle<0)?controle = controle * -1:controle= controle * 1;

		for(j=2;j<=controle;j++){			
			if(((vetor02[i]%j)==0)&&((vetor02[z]%j)==0)){				
				y++;				
			}		
		}
		(y==1)?printf("%i e %i: PRIMOS RELATIVOS\n",vetor02[i],vetor02[z]):printf("# %i e %i: NÃO SÃO PRIMOS RELATIVOS\n",vetor02[i],vetor02[z]);;
	}
}

int main(){
	int x, y, vet[TAM], vet2[TAM], vet3[TAM], i;

	printf("# DIGITE QUANTOS VALORES VOCE QUER REGISTRAR != (> 10000 & ==0)\n");
	scanf("%i",&x);

	if((x > TAM) || (x <= 0)){
		printf("ERRO. TAMANHO INVALIDO\n");
	}else{
		printf("# Digite %i numeros positivos ou negativos sem repetir\n",x);

		for(i=0;i<x; i++){ // FOr para ler os valores
			scanf("%i",&vet[i]);

			for(y=0;y<i;y++){ //FOR DE VERIFICAÇÃO DE OCORRENCIA
				// if(y==i){
				// 	continue;
				// }
				if(vet[y] == vet[i]){
					printf("ERRO. JA EXISTE\n");
					printf("# Digite Novamente\n");
					i--;
					continue;
				}
			
			}			
			vet2[i] = vet[i]; //VET2 recebe vet1 para alterações futuras		
		}

		ordenador(vet,vet2,x);
		printf("#ORDENADO COM SUCESSO\n\n");

		somador(vet2,vet3,x);
		printf("# Somatorios: \n");
		for(i=0;i<x;i++){
			(vet2[i]<50001)?printf("Somatorio de %i: %i\n",vet2[i], vet3[i]):printf("Somatorio de %i: ERRO \n",vet2[i]);
		}
		printf("\n");
		primosrelativos(vet,vet2,x);

	}//else principal
}

/*
vet[] == valores recebidos
vet2[] == valores ordenados
vet3[] == somatorios
*/