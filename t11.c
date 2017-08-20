#include <stdio.h>
#define MAX 10000


int faz_a_porra_toda(int contro, int max){
	int i, j, primo ,b, soma=0;
	int vet[max];
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
		faz_a_porra_toda(controle, MAX);
		printf("# FIM\n");
	}
}




// C:\> exercT11.exe <ENTER>
// # Quantos elementos você quer? (1 a 10000)
// 0<ENTER>
// # Erro. Valor 0 inválido
// ENCERRADO: ERRO

// C:\> exercT11.exe <ENTER>
// # Quantos elementos você quer? (1 a 10000)
// -5<ENTER>
// # Erro. Valor -5 inválido
// ENCERRADO: ERRO

// C:\> exercT11.exe <ENTER>
// # Quantos elementos você quer? (1 a 10000)
// 534000<ENTER>
// # Erro. Valor 534000 inválido
// ENCERRADO: ERRO

// C:\> exercT11.exe <ENTER>
// # Quantos elementos você quer? (1 a 10000)
// 9<ENTER>

// # Digite 9 números inteiros positivos ou negativos:
// 1199993<ENTER>
// 0<ENTER>
// 1<ENTER>
// 10<ENTER>
// 55<ENTER>
// -7<ENTER>
// 10<ENTER>
// 2<ENTER>
// 8921<ENTER>

// # Lido com sucesso 9 inteiros
//      1199993 IMPAR PRIMO
//            0 PAR   NAO PRIMO
//            1 IMPAR NAO PRIMO
//           10 PAR   NAO PRIMO (DIVIDE POR 2)
//           55 IMPAR NAO PRIMO (DIVIDE POR 5)
//           -7 IMPAR PRIMO
//           10 PAR   NAO PRIMO (DIVIDE POR 2)
//            2 PAR   PRIMO
//         8921 IMPAR NAO PRIMO (DIVIDE POR 11)

// SOMA 1208992
// # FIM
// C:\> 