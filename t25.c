#include <stdio.h>
#include <stdlib.h>
#define STRMAX 101
#define MAX 20001

struct FUNC{
	char nome[STRMAX];
	char *endereco;
	int n_reg;
	double salario;
};

int conta(char *s){
   int i;
   for(i=0;s[i];i++);
   return i;
}

int escreveByte(char *nome, struct FUNC *func, int qtd){
	
	FILE *arch1;
    arch1 = fopen(nome, "wb");
    
    if(arch1 == NULL){
        printf("erro ao abrir\n");
    }
    fwrite(&qtd, sizeof(int), 1, arch1);
    fclose(arch1);
    
	arch1 = fopen(nome, "ab");
    if(arch1 == NULL){
        printf("erro ao abrir\n");
    }
    fwrite(&func, sizeof(func), qtd, arch1);   
    fclose(arch1);
	
}

int leByteFunc(char *nome, struct FUNC *func, int qtd){
	int i;
    
	FILE *arch1;
    arch1 = fopen(nome, "rb");
    
    if(arch1 == NULL){
        printf("erro ao abrir\n");
    }
	fseek(arch1, sizeof(int), SEEK_CUR);
    fread(&func, sizeof(func), qtd, arch1);
    fclose(arch1);
    return(0);
}

int leByteInt(char *nome){
	
	
	int i;
    
	FILE *arch1;
    arch1 = fopen(nome, "rb");
    
    if(arch1 == NULL){
        printf("erro ao abrir\n");
    }

    fread(&i, sizeof(int), 1, arch1);
    fclose(arch1);
    return(i);
}



int letraMaiuscula(char *aux, int opc){
	int i, n;
	n = conta(aux);
	if(opc == 1){
		for(i=0;i<n;i++){
			if(aux[i] >= 65 && aux[i] <= 90){
				aux[i] += 32;
			}
		}
		return 0;
	}
	for(i=0;i<n;i++){
		if(aux[i] >= 97 && aux[i] <= 122){
			aux[i] -= 32;
		}
	}
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

int lestring(char *s, int max){
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

int strCMP(char *a, char *b){
    while (*a && *b && *a == *b) { ++a; ++b; }
    return (unsigned char)(*a) - (unsigned char)(*b);
}

int strnCPY(char *s, char *s2, int controle) {
   int i;
   	for (i = 0; i < controle; ++i){ 
      s[i] = s2[i];
    } 
   s[i] = '\0';
}

int leitura_struct(struct FUNC p[], int n, int max, int strmax, int opt, FILE *arch, int qtdBinario){
	int i, j, y, controle;
	char *aux, string;

	aux = (char*)malloc(max+1);
	
	if(opt == 1){
		for(i=qtdBinario;i<n;i++){	//leitura
	    	printf("#Digite o nome do Funcionario %i: \n",i);
			lestring(p[i].nome,strmax);
			letraMaiuscula(p[i].nome,2);

	    	printf("#Le endereco: \n");
	    	lestring(aux,max);
	    	j = conta(aux);
	    	p[i].endereco = (char *)malloc((j+1) * sizeof(char));

	    	if(p[i].endereco == NULL){ //VERIFICAÇÃO DA ALOCAÇÃO DA STRING
	    		printf("# ERRO. LIMITE DE ALOCAÇÃO DA STRING FOI ALCANÇADO.\n");
	    		return 1;
	    	}
	    	controle = conta(aux);
	    	strnCPY(p[i].endereco,aux,controle+1);

		    do{ 
				printf("# Digite o registro do Funcionario:\n");
				if (scanf("%i",&p[i].n_reg)==0){
					printf("ERRO entrada invalida\n");
				 	p[i].n_reg=0;
				   	while(fgetc(stdin)!='\n');
				   	continue;   
				}
			}while(p[i].n_reg<=0);

			do{ 
				printf("# Digite o salario, em reais:\n");
				if (scanf("%lf",&p[i].salario)==0){
					printf("ERRO entrada invalida\n");
				 	p[i].salario=0;
				   	while(fgetc(stdin)!='\n');
				   	continue;   
				}
			}while(p[i].salario<=0);
	    } 
	}else{
		printf("# LENDO CONTEUDO DO ARQUIVO ...\n");
		for(i=qtdBinario;i<n;i++){	//leitura

			fscanf(arch,"%i",&y); //pega primeira posi��o
			
	  		//printf("#Digite o nome do Funcionario %i: \n",i);
			// lestring(p[i].nome,strmax);
			// letraMaiuscula(p[i].nome,2);

			// fgets(p[i].nome, strmax, arch);
			// letraMaiuscula(p[i].nome,2);

			y=0;
			while (!feof(arch)) {
				fscanf(arch, "%c", &string);
				if (feof(arch)) {
				    y = 0;
		            break;
				}
		        if(string == '\n'){
		            p[i].nome[y] = 0;
		            break;
		        }
				//fprintf(arch1, "%c", string);
		        p[i].nome[y] = string;
		        y++;
			}    

			letraMaiuscula(p[i].nome,2);


	    	// printf("#Le endereco: \n");
	    	// lestring(aux,max);
	    	// j = conta(aux);
	    	// p[i].endereco = (char *)malloc((j+1) * sizeof(char));

	    	// fgets(aux, strmax, arch);

			y=0;
			while (!feof(arch)) {
				fscanf(arch, "%c", &string);
				if (feof(arch)) {
				    y = 0;
		            break;
				}
		        if(string == '\n'){
		            aux[y] = 0;
		            break;
		        }
				//fprintf(arch1, "%c", string);
		        aux[y] = string;
		        y++;
			}  
	    	

	    	j = conta(aux);
	    	p[i].endereco = (char *)malloc((j+1) * sizeof(char));


	    	if(p[i].endereco == NULL){ //VERIFICAÇÃO DA ALOCAÇÃO DA STRING
	    		printf("# ERRO. LIMITE DE ALOCACAOO DA STRING FOI ALCANCADO.\n");
	    		return 1;
	    	}

	    	controle = conta(aux);
	    	strnCPY(p[i].endereco,aux,(controle+1));


			do{ 
				if (fscanf(arch,"%i",&p[i].n_reg)==0){
					printf("ERRO entrada invalida\n");
				 	p[i].n_reg=0;
				   	while(fgetc(stdin)!='\n');
				   	continue;   
				}
			}while(p[i].n_reg<=0);

			do{ 
				printf("# Digite o salario, em reais:\n");
				if (fscanf(arch,"%lf",&p[i].salario)==0){
					printf("ERRO entrada invalida\n");
				 	p[i].salario=0;
				   	while(fgetc(stdin)!='\n');
				   	continue;   
				}
			}while(p[i].salario<=0);

	    }
	    //perror("#ERRO1.");
	    fclose(arch); 
	}
	  
}

int main(int argc, char *argv[]){
	int n = 0, i, j, qtdBinario; 
	struct FUNC *p;
	struct FUNC aup;
	double soma = 0;

	FILE *arch, *arch1;
	
	if(argc < 3){
	    while (n <= 0){
	        printf("# Quantos funcionarios voce quer cadastrar:\n");
	        n = inteiroslidos();
	        if ((n <= 0)) {
	            printf("ERRO %i\n", n);
	            printf("# ERRO: quantidade de funcionarios deve ser maior que 0\n");
	        }
	    }
	    arch1 = fopen("dados2.txt","w");
	    if(arch1 == NULL){
	    	printf("#ERRO AO ABRIR O ARQUIVO.\n");
	    	return 1;
	    }
	}else{
		
		arch = fopen(("%s",argv[1]),"r");
		arch1 = fopen(("%s",argv[2]),"w");
		if((arch == NULL) || (arch1 == NULL)){
			perror("# ERRO 3."); //imprime o erro ocorrido
			return 1;
		}
		fscanf(arch,"%i",&n);
		if(argc == 4){
			qtdBinario = leByteInt(argv[3]);
			n += qtdBinario;
		}		
	}

    p = (struct FUNC*) malloc(n* sizeof(struct FUNC));

    if(p == NULL){ //VERIFICA��O DA ALOCA��O
    	printf("# ERRO. LIMITE DE ALOCACAO DA STRUTURA FOI ALCANCADO.\n");
    	return 1;
    }

	if(argc == 4){
		leByteFunc(argv[3], p, qtdBinario);
		printf("%d", p[0].n_reg);
	}

    if(argc < 3){
    	leitura_struct(p, n, MAX, STRMAX,1,arch1, qtdBinario); 
    }else{
    	leitura_struct(p, n, MAX, STRMAX,2,arch, qtdBinario); 
    }

    for (i = 1; i < n; i++) {
	   for (j=1;j<n;j++) {
	      if (strCMP(p[j-1].nome, p[j].nome) > 0) {
	         aup = p[j-1];
	         p[j-1] = p[j];
	         p[j] = aup;
	      }
	   }
	}

	printf("#***************ORDEM ALFABETICA***************#\n");
	fprintf(arch1,"ORDEM ALFABETICA ... \n");
	for(i=0;i<n;i++){
		printf("%06d %s, %s, R$ %.2lf\n",p[i].n_reg,p[i].nome,p[i].endereco,p[i].salario);
		fprintf(arch1,"%06d %s, %s, R$ %.2lf\n",p[i].n_reg,p[i].nome,p[i].endereco,p[i].salario);		
	}

	for (i = 1;i<n;i++) {
        for (j = 0;j<n-i;j++) {
            if (p[j].salario < p[j+1].salario) {
                aup = p[j];
                p[j] = p[j+1];
                p[j+1] = aup;
            }
        }
    }
	printf("#***************LISTA MAIORES SALARIOS****************#\n");
	fprintf(arch1,"TOP 10 MAIORES SALARIOS ... \n");
	if(n < 10){
		for(i = 0; i < n; i++){
			printf("R$    %.2lf %s\n",p[i].salario,p[i].nome);
			fprintf(arch1,"R$    %.2lf %s\n",p[i].salario,p[i].nome);
		}
	
	}else{
		for(i = 0; i < 10; i++){
			printf("R$    %.2lf %s\n",p[i].salario,p[i].nome);
			fprintf(arch1,"R$    %.2lf %s\n",p[i].salario,p[i].nome);
		}	
	}
	
	for(i = 0; i < n; i++){
		soma=soma+p[i].salario;
	}
	printf("#Folha de salario total:");
    printf("\nR$ %.2lf\n",soma);
    printf("\n# FIM\n");

    fprintf(arch1,"#Folha de salario total:");
    fprintf(arch1,"\nR$ %.2lf\n",soma);
    fprintf(arch1,"\n# FIM\n");

    perror("#ERRO2.");
    if(argc == 3){
    	printf("%i registros salvos em %s\n",n, argv[2]);
    	//fclose(arch);
    	fclose(arch1);
    	return 0;
    }
    
   	printf("%i Registros salvos em 'dados2.txt'\n",n);
   	escreveByte(argv[3], p, n);
    fclose(arch1);
    return 0;
}
