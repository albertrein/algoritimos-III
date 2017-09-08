#include <stdio.h>
#include <string.h>
#define TAM 20001

// int cript(char *st, int i, int n){
// 	int j;
// 	for(j = 0;j < n;j++){
// 		st[j] = 
// 	}
// }

int conta_Chars(char *st){
	int i;
	for(i=0;st[i];i++);
	return i;
}

int maiuscula(char *st){
	int i, n;
	n = conta_Chars(st);
	for(i=0;i<n;i++){
		if(st[i] >= 97 && st[i] <= 122){
			st[i] -= 32;
		}
	}
}

int minuscula(char *st){
	int i, n;
	n = conta_Chars(st);
	for(i=0;i<n;i++){
		if(st[i] >= 65 && st[i] <= 90){
			st[i] += 32;
		}
	}
}

int del_Token(char *st, char token1, int token2){
	int i, j, n;
	char aux;
	//for(n=0;st[n];n++); //CONTA CARACTERES
	n = conta_Chars(st);
	for(i=0;i<n;i++){
		if((st[i] == token1)||(st[i] == token2)){
			for(j=i+1;j<n;j++){
				st[j-1] = st[j];
				if(j+1 == st[j]){ //INSERI O ZERO ABSOLUTO PARA O FIM DA STRING
					st[j+1] = 0;
				}
			}
			i--;
		}
	}
}

int gerenciador(char *st, int i, int n){	//Gerencia qual função deve ser executada
	if(st[0] == '$'){
		printf("# DEOGRAFA\n");
	}else{
		printf("# CRIPTOGRAFA\n");
		del_Token(st,',',' '); //retira espaço e ','
		maiuscula(st);
		//cript(st, i, n);
	}	
}


int main(){
	char string[TAM];
	int i, n, j;


	while (n<=0){ //Problemas 
	   	printf("# Digite Quantas Frases Voce Quer Digitar:\n");
	   	if (scanf("%d",&n)==0){
	      	printf("ERRO ENTRADA\n");
	      	while(fgetc(stdin)!='\n');
	      	continue;   
	   }
	   if(n < 1 || n > TAM){
	   	n=0;
	   	printf("ERRO. TAMANHO INVALIDO\n");
	   }
	}

	for(i=0;i<n;i++){
		printf("#DIGITE A %i FRASE \n",i);
		fgets(string, TAM, stdin);

		if(strlen(string) < 2){
			i--;
			continue;
		}
		del_Token(string,',',' '); //retira espaço e ','
		j = conta_Chars(string);
		printf("a string = %s\n",string);
		printf("NUMERO DE CHARS%i\n",j);
		//gerenciador(string,i,n);
		maiuscula(string);
		printf("maiuscula = %s\n",string);
		minuscula(string);
		printf("minuscula = %s\n",string);
	}
		
}