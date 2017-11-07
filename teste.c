#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *arq;
    int i, tam;
    char letra;

    if (argc != 2) {
        fprintf(stderr, "Erro. Faltou parametros\n");
        return (1);
    }

    arq = fopen(argv[1], "r+w");
    if (arq == NULL) {
        fprintf(stderr, "Nao pode abrir %s\n", argv[1]);
        return (2);
    }

    fseek(arq, 0, SEEK_SET);
    letra = fgetc(arq);
    while (!feof(arq)) {
    	printf("a");
        if (letra == 'A') {
            fseek(arq, -1, SEEK_CUR);
            fprintf(arq, " ");
        }
        letra = fgetc(arq);
    }

    fclose(arq);
}
