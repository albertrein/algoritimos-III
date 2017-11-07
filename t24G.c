#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 5000

int conta(char *s){
   int i;
   for(i=0;s[i];i++);
   return i;
}


int quest3(char *name){
    FILE *arch1;
    arch1 = fopen(name, "r+w");
    int i, j;
    char letra;
	    
    
	fseek(arch1, 0, SEEK_SET);
    
    while (!feof(arch1)) {
   		letra = fgetc(arch1);	
    	if(letra >= 97 && letra <= 122){
    		
	        letra -= 32;
	        printf("%c", letra);
	       
	        fseek(arch1, -1, SEEK_CUR);
            fprintf(arch1, letra);
            continue;

        }
        
        
    }
   
//    fseek(arch1, 0, SEEK_SET);
//    letra = fgetc(arch1);
//    while (!feof(arch1)){
//    
//        j = feof(arch1);
//        printf("%d", j);
//        if((j % 2) == 0){
//            if(letra >= 97 && letra <= 122){
//                letra -= 32;
//            }
//			fseek(arch1, -1, SEEK_CUR);
//            /*fprintf(arch1, "%c",letra);*/    
//        }
//    	letra = fgetc(arch1);
//
//    }
   	fclose(arch1);

}

int tamanhoDoArquivo(char *arquivo){
    
    int tam, i;
    FILE *arq;
    
    arq = fopen(arquivo, "r");
    if (arq == NULL) {
        fprintf(stderr, "Nao pode abrir %s\n", arquivo);
        return (2);
    }

    fseek(arq, 0, SEEK_END);

    tam = ftell(arq);
    fclose(arq);
    return(tam);
    
}

int checaExtensao(char *arquivo){
    
    char linha[MAXTAM];
    int tamanho = 0, i;
    FILE *arq;
    
    arq = fopen(arquivo, "r");
    if (arq == NULL) {
        fprintf(stderr, "ERRO. Não pode abrir %s\n", arquivo);
        return (2);
    }

    do {
        fgets(linha, MAXTAM, arq);
        if (feof(arq)) {
            break;
        }
        
        tamanho += conta(linha);
    } while (!feof(arq));
    
    if(tamanho == tamanhoDoArquivo(arquivo)){
        return (1);
    }else{
        return (0);
    }
}

int escreveBinario(char *arquivo){
    
    FILE *arq;
    char linha[MAXTAM];
    int i, tamanho = 0;
    
    arq = fopen(arquivo, "wb");
    if (arq == NULL) {
        fprintf(stderr, "ERRO. Não pode abrir %s\n", arquivo);
        return (2);
    }else{
        fprintf(arq, "raryson\n\n");
    }
    
    fclose(arq);
        
}

int escreveTexto(char *arquivo){
    
    FILE *arq;
    char linha[MAXTAM];
    int i, tamanho = 0;
    
    arq = fopen(arquivo, "w");
    if (arq == NULL) {
        fprintf(stderr, "ERRO. Não pode abrir %s\n", arquivo);
        return (2);
    }else{
        fprintf(arq, "Raryson\n\n");
    }
    
    fclose(arq);
        
}

int main(int argc, char *argv[])
{
    FILE *arq;
    char linha[MAXTAM];
    int i, tamanho = 0;
//  
//  escreveBinario("oi");
  escreveTexto("T_oi.txt");
          
    if (argc < 2) {
        fprintf(stderr, "ERRO. Precisa passar nome de arquivo\n");
        /* Agora enviando mensagens de erro para stderr */
        return (1);
    }

    arq = fopen(argv[1], "r");
    if (arq == NULL) {
        fprintf(stderr, "ERRO. Não pode abrir %s\n", argv[1]);
        return (2);
    }
    
    
    for(i = 1; i < argc; i++){
   		printf("\n\nO tamanho do %s e %d", argv[i], tamanhoDoArquivo(argv[i]));
		tamanho = checaExtensao(argv[i]);
		if(tamanho == 0){
			printf("\n O %s e .txt :)", argv[i]);
			if((argv[i][0] == 'T') && argv[i][1] == '_'){
            	printf("\nnome arquivo == T_\n");
            quest3(argv[i]);
        	}	
		}	       
    }
    fclose(arq);
}

