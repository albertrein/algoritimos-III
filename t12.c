#include <stdio.h>
#define TAM 10000

int ordenador(int val[], int val2[], int contro){
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

int main(){
	int x, y, vet[TAM], vett[TAM], i;

	printf("# DIGITE QUANTOS VALORES VOCE QUER REGISTRAR != (> 10000 & ==0)\n");
	scanf("%i",&x);

	if((x > TAM) || (x == 0)){
		printf("#ERRO VALOR INVÁIDO\n");
		printf("ERRO. TAMANHO INVALIDO\n");
	}else{
		printf("Digite %i numeros positivos ou negativos sem repetir\n",x);

		for(i=0;i<x; i++){ // FOr para
			scanf("%i",&vet[i]);
			//y=0;
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

		ordenador(vet,vett,x);

		printf("VOCE DIGITOU TODAS AS %i \n",x);
		for(i=0;i<x;i++){
			printf(">>> %i\n",vett[i]);
		}

	
	}//else principal
}