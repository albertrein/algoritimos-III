#include <stdio.h>
#include <stdlib.h>
#define STRMAX 101
#define MAX 20001

struct FUNC{
	char nome[STRMAX];
	char *street;
	int n_reg;
	double salario;
};


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
int conta(char *s){
   int i;
   for(i=0;s[i];i++);
   return i;
}

int letraMaiuscula(char *frases){
	int contador;
	for(contador = 0; frases[contador]; contador++){
		if((frases[contador] >= 'A') && (frases[contador] <= 'Z') || frases[contador] == ' ' || (frases[contador] >= '1' && frases[contador] <= '9' )){
			continue;
		}
		frases[contador] = frases[contador] -32 ;
	}
}

int leitura_Valores(struct FUNC *xx, int qtd, int strmax, double *somatorio, int max){
	//struct FUNC xx;
	int i, j;
	char *st_aux;

	st_aux = (char *) malloc(max);

	printf("#Digite o nome do Funcionario: \n");
	lestring(xx->nome,strmax);
	letraMaiuscula(xx->nome);
	
	printf("# Endereco\n");
	lestring(st_aux,strmax);
	j = conta(st_aux);
	
	//xx->street= malloc(sizeof(char)*j);
	xx->street = (char *) malloc(j);
	

	do{ 
		printf("# Digite o registro do Funcionario:\n");
		if (scanf("%i",&xx->n_reg)==0){
			printf("ERRO entrada invalida\n");
		 	xx->n_reg=0;
		   	while(fgetc(stdin)!='\n');
		   	continue;   
		}
	}while(xx->n_reg<=0);

	do{ 
		printf("# Digite o salario, em reais:\n");
		if (scanf("%lf",&xx->salario)==0){
			printf("ERRO entrada invalida\n");
		 	xx->salario=0;
		   	while(fgetc(stdin)!='\n');
		   	continue;   
		}
	}while(xx->salario<=0);

	//return xx;
}
int inteiroslidos(){
    int aux;

    while (scanf("%d", &aux) == 0) {
        printf("ERRO entrada invalida\n\n");
        printf("# ERRO. Digitou lixo\n\n");
        while (fgetc(stdin) != '\n');
    }
    return (aux);
}

int strCMP(char *a, char *b){
    while (*a && *b && *a == *b) { ++a; ++b; }
    return (unsigned char)(*a) - (unsigned char)(*b);
}

int main(int argc, char *argv[]){
	int i, j, n, aux2, conta;
	struct FUNC *x;
	struct FUNC aux;
	double soma = 0;

	if (argc > 1) {
        n = atoi(argv[1]);
        if ((n <= 0)){
            printf("ERRO %s\n", argv[1]);
            printf("# ERRO: quantidade de funcionarios deve ser maior que 0\n");
        }
    }
    
    while (n <= 0) {
        printf("# Quantos funcionarios voce quer cadastrar:\n");
        n = inteiroslidos();
        if ((n <= 0)) {
            printf("ERRO %i\n", n);
            printf("# ERRO: quantidade de funcionarios deve ser maior que 0\n");
        }
    }

    x = (struct FUNC *) malloc(n);


	for(i=0;i<n;i++){//Leitura de Valores
		leitura_Valores(x,i,STRMAX,&soma,MAX);
	}

	for (i = 1; i < n; i++) {
	   for (j=1;j<n;j++) {
	      if (strCMP(x[j-1].nome, x[j].nome) > 0) {
	         aux = x[j-1];
	         x[j-1] = x[j];
	         x[j] = aux;
	      }
	   }
	}

	printf("#*************************************#\n");
	for(i=0;i<n;i++){//Leitura de Valores
		printf("%06d %s, %s, R$ %.2lf\n",x[i].n_reg,x[i].nome,x[i].street,x[i].salario);
		
	}
	for (i = 0;i<n;i++) {
        for (j = 0;j<n-i;j++) {
            if (x[j].salario < x[j+1].salario) {
                aux = x[j];
                x[j] = x[j+1];
                x[j+1] = aux;
            }
        }
    }	

	printf("#*************************************#\n");
	if(n < 10){
		for(i = 0; i < n; i++){
			printf("R$    %.2lf %s\n",x[i].salario,x[i].nome);
		}
	
	}else{
		for(i = 0; i < 10; i++){
			printf("R$    %.2lf %s\n",x[i].salario,x[i].nome);
		}	
	}
	
	for(i = 0; i < n; i++){
		soma=soma+x[i].salario;
	}
	printf("#Folha de salario total:");
    printf("\nR$ %.2lf\n",soma);
    printf("\n# FIM\n");
}