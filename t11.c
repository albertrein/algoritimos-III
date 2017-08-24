#include <stdio.h>
#define MAX 10000


int faz_tudo(int contro, int max){	//<<<===== ERRO: NUNCA USAR UMA FUNÇÃO FAZ TUDO 
	int i, j, primo ,b, soma=0;
	int vet[max];						//<<<==== ERRO: NÃO PODE DEFINIR O TAMANHO DO VETOR COM UMA VARIAVEL 
	printf("#Digite %i números inteiros positivos ou negativos:\n",contro);
	for(i=0;i<contro;i++){
		scanf("%i",&vet[i]);
	}

	printf("# Lido %i valores\n",contro);

	for(i=0;i<contro;i++){
		printf("\t%i ", vet[i]);
		(((vet[i] % 2)==0))?printf(" PAR "):printf(" IMPAR ");
		(vet[i] > 0)?soma += vet[i]:vet[i];

		(vet[i] < 1)?vet[i] *= -1: vet[i];
		primo = 0;
		for(j=vet[i];j<=vet[i] && j > 1;j--){			
			if((vet[i] % j) == 0){
				primo++;
				b = j;
			}
		}		
		
		if(primo == 1){
			printf("PRIMO \n");			
		}else{
			(vet[i] == 1 || vet[i] == 0)?printf("NAO PRIMO\n"):printf("NAO PRIMO  (%i)\n",b);			
		}
	}

	printf("\n SOMA %i\n",soma);

}

int main(){
	int controle, a;

	printf("# Quantos elementos você quer? (1 a 10000)\n");
	scanf("%i",&controle);

	if((controle > MAX) || (controle < 1)){
		printf("# Erro. Valor %i inválido\n", controle);
		printf("ENCERRADO: ERRO\n");
	}else{
		faz_tudo(controle, MAX);
		printf("# FIM\n");
	}
}
