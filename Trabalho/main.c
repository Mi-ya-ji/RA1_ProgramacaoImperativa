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

//funcao para ler o arquivo e armazenar cada linha no vetor alimentos
int readFile(const char *filename, Alimento alimentos[], int maxAlimentos) {
    FILE *filePointer = fopen("arquivo.csv" , "r");
    if (filePointer == NULL){
        printf("Falha ao abrir o arquivo");
    }

    char linha[200]; //linha é um buffer que define a capacidade máxima de armazenamento
    int quantidade = 0;  //quantidade de alimentos lidos

    // ignora o cabeçalho
    fgets(linha, sizeof(linha), filePointer);

    //lendo cada linha do arquivo até chegar no final (achar um valor nulo)
    while (fgets(linha, sizeof(linha), filePointer) != NULL) {
        linha[strcspn(linha, "\n")] = '\0'; //remove o \n

        char* strPointer = strtok(linha, ","); // Separa os elementos pela vírgula

        // Preenche a struct e muda os valores numericos de str para int ou float
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
    }
    fclose(filePointer); //fecha o arquivo
    return quantidade; // retorna quantos alimentos foram lidos
}

int ex2_A(){ // funcao pro item a - printa todas as categorias usadas no csv
        printf("Categorias de alimentos:\n 1. Cereais e derivados\n 2. Verduras, hortaliças e derivados\n 3. Frutas e derivados\n 4. Gorduras e óleos\n 5. Pescados e frutos do mar\n 6. Carnes e derivados\n 7. Leite e derivados\n 8. Bebidas (alcoólicas e não alcoólicas)\n 10. Produtos açucarados\n 13. Alimentos preparados");
    return 0;
}
int ex2_B(){ // funcao pro item b
//Liste todos os alimentos de certa categoria selecionada pelo usuário,
//em ordem alfabética de acordo com a descrição do alimento
    int categoriaEscolhida = scanf
}


int main() {

    Alimento alimentos[101]; //vetor de structs
    int quantidade = readFile("arquivo.csv", alimentos, 101);

    printf("Categorias de alimentos:\n 1. Cereais e derivados\n 2. Verduras, hortaliças e derivados\n 3. Frutas e derivados\n 4. Gorduras e óleos\n 5. Pescados e frutos do mar\n 6. Carnes e derivados\n 7. Leite e derivados\n 8. Bebidas (alcoólicas e não alcoólicas)\n 10. Produtos açucarados\n 13. Alimentos preparados");


    return 0;
}