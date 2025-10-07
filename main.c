#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
        int numero;
        char descricao[100];
        float umidade;
        float energia;
        float proteina;
        float carboidrato;
        int categoria;
    } Alimento;

int main() {

    FILE *filePointer = fopen("Trabalho/arquivo.csv" , "r");
    if (filePointer == NULL){
        printf("Falha ao abrir o arquivo");
        }

    char linha[200]; //line é um buffer com a capacidade máxima de armazenamento igual a quantidade de caracteres que a maior linha da tabela possui
    Alimento alimentos[101]; //vetor de structs
    int quantidade = 0;  //quantidade de alimentos lidos

    // ignora o cabeçalho
    fgets(linha, sizeof(linha), filePointer);

    //lendo cada linha do arquivo até chegar no final (achar um valor nulo)
    while (fgets(linha, 200, filePointer) != NULL) {
        linha[strlen(linha) - 1] = '\0'; //remove o \n e encerra a string

        char* strPointer = strtok(linha, ","); // Separa os elementos pela vírgula

        alimentos[quantidade].numero = atoi(strPointer);

        strPointer = strtok(NULL, ",");
        strcpy(alimentos[quantidade].descricao, strPointer);

        strPointer = strtok(NULL, ",");
        alimentos[quantidade].umidade = atof(strPointer);

        strPointer = strtok(NULL, ",");
        alimentos[quantidade].energia = atof(strPointer);

        strPointer = strtok(NULL, ",");
        alimentos[quantidade].proteina = atof(strPointer);

        strPointer = strtok(NULL, ",");
        alimentos[quantidade].carboidrato = atof(strPointer);

        strPointer = strtok(NULL, ",");
        alimentos[quantidade].categoria = atoi(strPointer);

        quantidade++;


        printf("%s\n", linha);
    }

    fclose(filePointer); //fecha o arquivo

    return 0;
}
