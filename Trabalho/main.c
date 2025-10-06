#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *filePointer = fopen("Trabalho/arquivo.csv" , "r");

    char line [200]; //line é um buffer com a capacidade máxima de armazenamento igual a quantidade de caracteres que a maior linha da tabela possui

    //lendo cada linha do arquivo até chegar no final (achar um valor nulo)
    while (fgets(line, 200, filePointer) != NULL) {
        line[strlen(line) - 1] = '\0';
        printf("%s\n", line);

        char* strPointer = strtok(line, ",");
        for (int i=0; i<6; i++) {
            strPointer = strtok(NULL, ",");
        }
        printf("%s\n", strPointer);
        strPointer[strlen(strPointer) - 1] = '\0';
        float categoria = atof(strPointer+1);
        printf("Categoria: %f\n", categoria);
    }

    fclose(filePointer); //fecha o arquivo
    return 0;
}