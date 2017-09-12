#include <stdio.h>
#define MAX 20001

int quant_elementos(char *string, int opc){
	int i;
	if(opc == 1){
		//printf("# COntagem ELEMENTOS\n");
		for(i=0;string[i];i++);
		return i;	
	}
		//printf("# COntagem SEM enter\n");
		for(i=0;string[i];i++){
			if(string[i] == '\n'){
				string[i] == ' ';
				//i--;
				break;
			}
		}	
	return i;
}

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

int cCLEANER(char *string){
	int i, n;
	n = quant_elementos(string, 1);
	for (i=n;i>=0; i--){
		string[i] = 0;
	}
}

int encryption(char *aux, int opc){
	int j, n;
	n = quant_elementos(aux,1);	
	if(opc == 1){	//ENCRIPTAR
		for(j = 1;j<n;j++){
	 		//if(st[0] == '$'){continue;}
	 		if((aux[j] >= 65)&&(aux[j] <= 87)){
	 			aux[j] += 3; 			
	 		}else{
	 			aux[j] -= 23;
	 		} 		
	 	}
		return 0;
	}
	//DESCRIPTAR
	for(j=0;j<n;j++){
 		//if(aux[0] == '$'){continue;}
		if((aux[j] >= 68)&&(aux[j] <= 90)){
			aux[j] -= 3; 			
		}else{
			aux[j] += 23;
		} 	
	}
}

int minusc_MAIUSC(char *aux, int opc){
	int i, n;
	n = quant_elementos(aux,1);
	if(opc == 1){
		for(i=0;i<n;i++){
			if(aux[i] >= 65 && aux[i] <= 90){
				aux[i] += 32;
			}
		}
		return 0;
	}

	for(i=1;i<n;i++){
		if(aux[i] >= 97 && aux[i] <= 122){
			aux[i] -= 32;
		}
	}

}

int string_tok(char *string, char *aux, int opc){
	int i, j = 1, quant, cont = 0;

	//if(opc == 1){
		quant = quant_elementos(string,1);
		//(opc == 1)?aux[0] = ' ':j = 0;
		if(opc == 1){
			aux[0] = ' ';
		}else{
			j = 0;
		}
		for(i=0;i<quant;i++){
			if(((string[i] >= 65)&&(string[i] <= 90)) || ((string[i] >= 97)&&(string[i] <= 122))){
				aux[j] = string[i];
				j++;
				cont++;
			}
		}
		//printf("=== %s\n",aux);
		return cont;
}

int main(){
	int i, j, n, q = 0, x=0, y=0;
	char frase[MAX];
	char suporte[MAX];

	do{ 
	   	printf("# Digite Quantas Frases Voce Quer Digitar:\n");
	   	if (scanf("%d",&n)==0){
	      	printf("ERRO ENTRADA\n");
	      	while(fgetc(stdin)!='\n');
	      	continue;   
	   }
	   if(n < 1 || n > MAX){
	   	n=0;
	   	printf("ERRO. TAMANHO INVALIDO\n");
	   }
	}while(n<=0);

for(i=0;i<n;i++){
		printf("# DIGITE FRASE\n");
		//fgets(frase, MAX, stdin);
		lestring(frase,MAX);
		x += quant_elementos(frase,2);
		if(x < 1){
			i--;
			continue;
		}
		
		if(frase[0] == '$'){
			x--;
			printf("# DECIFRA\n");
			//printf("%s\n",frase);
			y += string_tok(frase,suporte,2);
			encryption(suporte,2);
			minusc_MAIUSC(suporte,1);
			printf("%s\n",suporte);
			cCLEANER(suporte);
		}else{
			printf("# CIFRA\n");
			y += string_tok(frase, suporte, 1);
			minusc_MAIUSC(suporte,2);
			//printf("FINAL 1 %s\n",suporte);
			minusc_MAIUSC(suporte,2);
			encryption(suporte,1);
			suporte[0] = '$';
			printf("%s\n",suporte);
			cCLEANER(suporte);
		}
	}
	printf("%i CARS DIGITADOS\n",x);
	printf("%i LETRAS\n",y);
	printf("FIM\n");
}


// quant_elementos (string, contagem com enter (1) || contagem sem enter != 1)
// minusc_MAIUSC(strng, 1 para minuscula, 2 para maiuscula);
//encrypter (string, 1 para encript, 2 para descript)
