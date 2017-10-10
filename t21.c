#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRMAX 501
#define MAXFUNC 1000

struct FUNC{
	char nome[STRMAX];
	char street[STRMAX];
	int n_reg;
	double salario;
};

 /*Nome do funcionário  (uma string de até STRMAX cars)
- Endereço residencial (uma string de até STRMAX cars)
- Número de registro (um inteiro)
- Salário em reais (double)*/


int lestring(char *s, int max)
{
    int i = 0;
    char a;

    for (i = 0; i < (max - 1); i++) {
	a = fgetc(stdin);

	if   ((a == '\n') && (i == 0)) {
	    i = i - 1;
	    continue;
	}
	if (a == '\n')
	    break;
		s[i] = a;
    }
    s[i] = 0;
    return (i);
}

int safeFflush(){
	while(fgetc(stdin)!='\n');    
}

int conta(char *s, int max){
   int i;
   for(i=0;s[i];i++);
   return i;
}

struct FUNC leitura_Valores(int qtd, int strmax, double *somatorio){
	struct FUNC xx;
	int i, j;

	printf("#Digite o nome do Funcionario: \n");
	lestring(xx.nome,strmax);
	
	printf("# Endereco\n");
	lestring(xx.street,strmax);

	do{ 
		printf("# Digite o registro do Funcionario:\n");
		if (scanf("%i",&xx.n_reg)==0){
			printf("ERRO entrada invalida\n");
		 	xx.n_reg=0;
		   	while(fgetc(stdin)!='\n');
		   	continue;   
		}
	}while(xx.n_reg<=0);

	do{ 
		printf("# Digite o salario, em reais:\n");
		if (scanf("%lf",&xx.salario)==0){
			printf("ERRO entrada invalida\n");
		 	xx.salario=0;
		   	while(fgetc(stdin)!='\n');
		   	continue;   
		}
	}while(xx.salario<=0);

	return xx;
}

int main(int argc, char *argv[]){
	int i, j, n, aux2, conta;
	struct FUNC x[MAXFUNC];
	struct FUNC aux;
	double soma = 0;


	//FALTA REALIZAR A VERIFICAÇÃO DA QUANTIDADE INSERIDO

	// //RARYSON:
	// if((atoi(argv[1]) <= 0) || (atoi(argv[1]) > MAXFUNC)){
	// 	if(argv[1] != NULL){
	// 		printf("ERRO %s\n", argv[1]);
	// 	}
	// 	do{
	// 		printf("#Digite a quantidade de pessoas da sua empresa:\n");
	// 		conta = scanf("%d",&n);
	// 		if(conta == 0){
	// 			printf("ERRO entrada invalida\n");
	// 			safeFflush();  
	// 		}
	// 	} while(n <= 0 || n > MAXFUNC || conta != 1);	
	// }else{
	// 	n = atoi(argv[1]);
	// }

	// //EU:
	// if(argc < 2){	//argc não passado por parametro
	// 	do{ 
	// 	   	printf("# Digite Quantos Funcionarios Voce Quer Registrar?\n");
	// 	   	if (scanf("%d",&n)==0){
	// 	   		printf("ERRO. %i\n",n);
	// 		   	n=0;
	// 	      	while(fgetc(stdin)!='\n');
	// 	      	continue;   
	// 	   }
	// 	   if(n < 1 || n > MAXFUNC){
	// 	   		printf("ERRO. %i\n",n);
	// 		   	n=0;
	// 	   }
	// 	}while(n<=0);			
	// }else{	//Recebido argc pela main
	// 	if(atoi(argv[1])==0){ //RECEBEU NULL
	// 		printf("ERRO. %s\n",argv[1]);
	// 		do{ 
	// 		   	printf("# Digite Quantos Funcionarios Voce Quer Registrar?\n");
	// 		   	if (scanf("%d",&n)==0){
	// 		      	printf("ERRO ENTRADA\n");
	// 		      	n = 0;
	// 		      	while(fgetc(stdin)!='\n');
	// 		      	continue;   
	// 		   }
	// 		   if(n < 1 || n > MAXFUNC){
	// 		   	printf("ERRO. %i\n",n);
	// 		   	n=0;
	// 		   }
	// 		}while(n<=0);
	// 	}else{
	// 		n = atoi(argv[1]);
	// 	}	
	// }

	

	for(i=0;i<n;i++){//Leitura de Valores
		x[i] = leitura_Valores(i,STRMAX,&soma);
	}

	for (i = 1; i < n; i++) {
	   for (j=1;j<n;j++) {
	      if (strcmp(x[j-1].nome, x[j].nome) > 0) {
	         aux = x[j-1];
	         x[j-1] = x[j];
	         x[j] = aux;
	      }
	   }
	}

	printf("*************************************\n");
	for(i=0;i<n;i++){//Leitura de Valores
		printf("Nome: %s\n",x[i].nome);
		printf("Endereco: %s\n",x[i].street);
		printf("Registro: %i\n",x[i].n_reg);
		printf("Salario: %lf\n",x[i].salario);
		printf("_______________________________\n");
	}
	//FALTA O MODO DE IMPRESSÃO REQUERIDO

	for (i = 1;i<n;i++) {
        for (j = 0;j<n-i;j++) {
            if (x[j].salario < x[j+1].salario) {
                aux = x[j];
                x[j] = x[j+1];
                x[j+1] = aux;
            }
            soma += x[i].salario;
        }
    }
	
		

	printf("*************************************\n");
	for(i=0;i<n;i++){//Leitura de Valores
		printf("Nome: %s\n",x[i].nome);
		printf("Endereco: %s\n",x[i].street);
		printf("Registro: %i\n",x[i].n_reg);
		printf("Salario: %lf\n",x[i].salario);
		printf("_______________________________\n");
	}
	//FALTA O MODO DE IMPRESSÃO REQUERIDO2
    printf("\n SOMATORIO: // %lf\n",soma);



	/*C:\> exerT21 2<ENTER>
# Digite os dados para 2 funcionários:

# --- func [0] ---
# Nome do funcionário:
Beltronildo fonseca<ENTER>

# Endereço:
Rua da Universidade, numero primo, Gravatai<ENTER>

# Número do registro
teste<ENTER>
ERRO entrada invalida
# ERRO. Digitou lixo

# Número do registro
50<ENTER>

# Valor do salário, em reais:
fdsafsad<ENTER>
ERRO entrada invalida
# ERRO. Digitou lixo

# Valor do salário, em reais:
21128.99<ENTER>*/

	
}