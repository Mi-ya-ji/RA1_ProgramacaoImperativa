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
    FILE *filePointer = fopen("Trabalho/arquivo.csv" , "r");
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
        printf("\nCategorias de alimentos:\n 1. Cereais e derivados\n 2. Verduras, hortalicas e derivados\n 3. Frutas e derivados\n 4. Gorduras e oleos\n 5. Pescados e frutos do mar\n 6. Carnes e derivados\n 7. Leite e derivados\n 8. Bebidas (alcolicas e nao alcoolicas)\n 10. Produtos acucarados\n 13. Alimentos preparados");
    return 0;
}
int ex2_B(Alimento alimentos[], int quantidade){ // funcao pro item b
//Liste todos os alimentos de certa categoria selecionada pelo usuário,
//em ordem alfabética de acordo com a descrição do alimento
    int categoriaEscolhida;
    int i, j;

    printf("\n \n  Insira a categoria desejada: ");
    scanf("%d", &categoriaEscolhida); // pede ao usuario a categoria

    Alimento filtrados[101]; // vetor original c dados dos alimentos servw como referencia (tipo int, float) pro filtrados que ta sendo criado
    int totalFiltrados = 0; //contador de filtrados


    for (i = 0; i < quantidade; i++) { // loop para percorrer cada alimento do original, comeca no primeiro termina no ultimo (qnt +1)
        if (alimentos[i].categoria == categoriaEscolhida){ //verifica se pertence a categoria esscolhida
            filtrados[totalFiltrados] = alimentos[i]; // copia todos os dados do vetor original pro filtrado
            totalFiltrados++; // adiciona ao contador de filtrados
        }
    }

    //bubble sort pra organizar em alfabetica
    for (i = 0; i < totalFiltrados - 1; i++) {
        for (j = 0;j < totalFiltrados - i - 1; j++ ){
            if (strcmp(filtrados[j].descricao, filtrados[j +1].descricao) > 0){
            Alimento temp = filtrados[j];
            filtrados[j] = filtrados[j + 1];
            filtrados[j+1] = temp;
            }
        }
    }

    printf("\n Alimentos da categoria em ordem alfabetica:\n");
    for (int i = 0; i < totalFiltrados; i++) {
        printf("%s\n", filtrados[i].descricao);
    }
    return 0;
}
int ex2_C(Alimento alimentos[], int quantidade){ // funcao pro item c
    //Liste todos os alimentos de certa categoria selecionada pelo usuário,
   //em ordem decrescente com respeito à capacidade energética dos
    // alimentos
    int categoriaEscolhida;
    int i, j;

    printf("\n \n  Insira a categoria desejada: ");
    scanf("%d", &categoriaEscolhida); // pede ao usuario a categoria

    Alimento filtrados[101]; // vetor original c dados dos alimentos servw como referencia (tipo int, float) pro filtrados que ta sendo criado
    int totalFiltrados = 0; //contador de filtrados


    for (i = 0; i < quantidade; i++) { // loop para percorrer cada alimento do original, comeca no primeiro termina no ultimo (qnt +1)
        if (alimentos[i].categoria == categoriaEscolhida){ //verifica se pertence a categoria escolhida
            filtrados[totalFiltrados] = alimentos[i]; // copia todos os dados do vetor original pro filtrado
            totalFiltrados++; // adiciona ao contador de filtrados
        }
    }

    //bubble sort pra organizar em decrescente
    for (i = 0; i < totalFiltrados - 1; i++) {
        for (j = 0;j < totalFiltrados - i - 1; j++ ){
            if (filtrados[j].energia < filtrados[j +1].energia) {
                Alimento temp = filtrados[j];
                filtrados[j] = filtrados[j + 1];
                filtrados[j+1] = temp;
            }
        }
    }

    printf("\n Alimentos da categoria em organizados por energia em ordem decrescente:\n");
    for (int i = 0; i < totalFiltrados; i++) {
    printf("%s - %.2f Kcal\n", filtrados[i].descricao, filtrados[i].energia);
    }
    return 0;
}
int ex2_D(Alimento alimentos[], int quantidade){ // funcao pro item d
    //Listar os N alimentos de certa categoria com maior percentual de
    //umidade, em ordem decrescente com respeito a esse percentual,
    // sendo a categoria e N definidos pelo usuário.
    int categoriaEscolhida;
    int quantiaEscolhida;
    int i, j;

    printf("\n \n  Insira a categoria desejada: ");
    scanf("%d", &categoriaEscolhida); // pede ao usuario a categoria
    printf("\n \n  Insira a quantia de itens desejada: ");
    scanf("%d", &quantiaEscolhida); // pede ao usuario a quantia de itens

    Alimento filtrados[101]; // vetor original c dados dos alimentos servw como referencia (tipo int, float) pro filtrados que ta sendo criado
    int totalFiltrados = 0; //contador de filtrados


    for (i = 0; i < quantidade; i++) { // loop para percorrer cada alimento do original, comeca no primeiro termina no ultimo (qnt +1)
        if (alimentos[i].categoria == categoriaEscolhida){ //verifica se pertence a categoria escolhida
            filtrados[totalFiltrados] = alimentos[i]; // copia todos os dados do vetor original pro filtrado
            totalFiltrados++; // adiciona ao contador de filtrados
        }
    }

    //bubble sort pra organizar em decrescente
    for (i = 0; i < totalFiltrados - 1; i++) {
        for (j = 0;j < totalFiltrados - i - 1; j++ ){
            if (filtrados[j].umidade < filtrados[j +1].umidade) {
                Alimento temp = filtrados[j];
                filtrados[j] = filtrados[j + 1];
                filtrados[j+1] = temp;
            }
        }
    }

    printf("\n Alimentos da categoria em organizados por porcentual de umidade em ordem decrescente:\n");
    for (int i = 0; i < quantiaEscolhida; i++) {
        printf("%s - %.2f %%\n", filtrados[i].descricao, filtrados[i].umidade);
    }
    return 0;
}
int ex2_E(Alimento alimentos[], int quantidade){ // funcao pro item E
    //Listar os N alimentos de certa categoria com maior capacidade
    //energética, em ordem decrescente com respeito a essa capacidade,
    //sendo a categoria e N definidos pelo usuário.
    int categoriaEscolhida;
    int quantiaEscolhida;
    int i, j;

    printf("\n \n  Insira a categoria desejada: ");
    scanf("%d", &categoriaEscolhida); // pede ao usuario a categoria
    printf("\n \n  Insira a quantia de itens desejada: ");
    scanf("%d", &quantiaEscolhida); // pede ao usuario a quantia de itens

    Alimento filtrados[101]; // vetor original c dados dos alimentos servw como referencia (tipo int, float) pro filtrados que ta sendo criado
    int totalFiltrados = 0; //contador de filtrados


    for (i = 0; i < quantidade; i++) { // loop para percorrer cada alimento do original, comeca no primeiro termina no ultimo (qnt +1)
        if (alimentos[i].categoria == categoriaEscolhida){ //verifica se pertence a categoria escolhida
            filtrados[totalFiltrados] = alimentos[i]; // copia todos os dados do vetor original pro filtrado
            totalFiltrados++; // adiciona ao contador de filtrados
        }
    }

    //bubble sort pra organizar em decrescente
    for (i = 0; i < totalFiltrados - 1; i++) {
        for (j = 0;j < totalFiltrados - i - 1; j++ ){
            if (filtrados[j].energia < filtrados[j +1].energia) {
                Alimento temp = filtrados[j];
                filtrados[j] = filtrados[j + 1];
                filtrados[j+1] = temp;
            }
        }
    }

    printf("\n Alimentos da categoria em organizados por capacidade energetica em ordem decrescente:\n");
    for (int i = 0; i < quantiaEscolhida; i++) {
        printf("%s - %.2f Kcal\n", filtrados[i].descricao, filtrados[i].energia);
    }
    return 0;
}
int ex2_F(Alimento alimentos[], int quantidade){ // funcao pro item f
    //Listar os N alimentos de certa categoria com maior quantidade de
    //proteína, em ordem decrescente com respeito a essa quantidade,
    //sendo a categoria e N definidos pelo usuário.
    int categoriaEscolhida;
    int quantiaEscolhida;
    int i, j;

    printf("\n \n  Insira a categoria desejada: ");
    scanf("%d", &categoriaEscolhida); // pede ao usuario a categoria
    printf("\n \n  Insira a quantia de itens desejada: ");
    scanf("%d", &quantiaEscolhida); // pede ao usuario a quantia de itens

    Alimento filtrados[101]; // vetor original c dados dos alimentos servw como referencia (tipo int, float) pro filtrados que ta sendo criado
    int totalFiltrados = 0; //contador de filtrados


    for (i = 0; i < quantidade; i++) { // loop para percorrer cada alimento do original, comeca no primeiro termina no ultimo (qnt +1)
        if (alimentos[i].categoria == categoriaEscolhida){ //verifica se pertence a categoria escolhida
            filtrados[totalFiltrados] = alimentos[i]; // copia todos os dados do vetor original pro filtrado
            totalFiltrados++; // adiciona ao contador de filtrados
        }
    }

    //bubble sort pra organizar em decrescente
    for (i = 0; i < totalFiltrados - 1; i++) {
        for (j = 0;j < totalFiltrados - i - 1; j++ ){
            if (filtrados[j].proteina < filtrados[j +1].proteina) {
                Alimento temp = filtrados[j];
                filtrados[j] = filtrados[j + 1];
                filtrados[j+1] = temp;
            }
        }
    }

    printf("\n Alimentos da categoria em organizados por quantidade de proteina em ordem decrescente:\n");
    for (int i = 0; i < quantiaEscolhida; i++) {
        printf("%s - %.2f g\n", filtrados[i].descricao, filtrados[i].proteina);
    }
    return 0;
}
int ex2_G(Alimento alimentos[], int quantidade){ // funcao pro item g
    //Listar os N alimentos de certa categoria com maior quantidade de
    //carboidrato, em ordem decrescente com respeito a essa quantidade,
    //sendo a categoria e N definidos pelo usuário.
    int categoriaEscolhida;
    int quantiaEscolhida;
    int i, j;

    printf("\n \n  Insira a categoria desejada: ");
    scanf("%d", &categoriaEscolhida); // pede ao usuario a categoria
    printf("\n \n  Insira a quantia de itens desejada: ");
    scanf("%d", &quantiaEscolhida); // pede ao usuario a quantia de itens

    Alimento filtrados[101]; // vetor original c dados dos alimentos servw como referencia (tipo int, float) pro filtrados que ta sendo criado
    int totalFiltrados = 0; //contador de filtrados


    for (i = 0; i < quantidade; i++) { // loop para percorrer cada alimento do original, comeca no primeiro termina no ultimo (qnt +1)
        if (alimentos[i].categoria == categoriaEscolhida){ //verifica se pertence a categoria escolhida
            filtrados[totalFiltrados] = alimentos[i]; // copia todos os dados do vetor original pro filtrado
            totalFiltrados++; // adiciona ao contador de filtrados
        }
    }

    //bubble sort pra organizar em decrescente
    for (i = 0; i < totalFiltrados - 1; i++) {
        for (j = 0;j < totalFiltrados - i - 1; j++ ){
            if (filtrados[j].carboidrato < filtrados[j +1].carboidrato) {
                Alimento temp = filtrados[j];
                filtrados[j] = filtrados[j + 1];
                filtrados[j+1] = temp;
            }
        }
    }

    printf("\n Alimentos da categoria em organizados por quantidade de carboidratos em ordem decrescente:\n");
    for (int i = 0; i < quantiaEscolhida; i++) {
        printf("%s - %.2f g\n", filtrados[i].descricao, filtrados[i].carboidrato);
    }
    return 0;
}

int ex2_H(Alimento alimentos[], int quantidade){ // funcao pro item h
    //Listar os N alimentos de certa categoria que possuam a relação mais
    //alta entre energia e proteína, em ordem decrescente com respeito a
    //essa relação, sendo a categoria e N definidos pelo usuário
    int categoriaEscolhida;
    int quantiaEscolhida;
    int i, j;

    printf("\n \n  Insira a categoria desejada: ");
    scanf("%d", &categoriaEscolhida); // pede ao usuario a categoria
    printf("\n \n  Insira a quantia de itens desejada: ");
    scanf("%d", &quantiaEscolhida); // pede ao usuario a quantia de itens

    Alimento filtrados[101]; // vetor original c dados dos alimentos servw como referencia (tipo int, float) pro filtrados que ta sendo criado
    int totalFiltrados = 0; //contador de filtrados


    for (i = 0; i < quantidade; i++) { // loop para percorrer cada alimento do original, comeca no primeiro termina no ultimo (qnt +1)
        if (alimentos[i].categoria == categoriaEscolhida){ //verifica se pertence a categoria escolhida
            filtrados[totalFiltrados] = alimentos[i]; // copia todos os dados do vetor original pro filtrado
            totalFiltrados++; // adiciona ao contador de filtrados
        }
    }

    //bubble sort pra organizar em decrescente com calculo de energia por proteina
    for (i = 0; i < totalFiltrados - 1; i++) {
        for (j = 0;j < totalFiltrados - i - 1; j++ ) {
            float rel1 = 0;
            float rel2 = 0;

            if (filtrados[j].proteina != 0) {
                rel1 = filtrados[j].energia / filtrados[j].proteina;
            }
            if (filtrados[j+1].proteina != 0) {
                rel2 = filtrados[j + 1].energia / filtrados[j + 1].proteina;
            }
                if (rel1 < rel2) {
                    Alimento temp = filtrados[j];
                    filtrados[j] = filtrados[j + 1];
                    filtrados[j+1] = temp;
            }
        }
    }

    printf("\n Alimentos da categoria em organizados por relacao mais alta  em ordem decrescente:\n");
    for (int i = 0; i < quantiaEscolhida && i < totalFiltrados; i++) {
        float rel = 0;
        if (filtrados[i].proteina != 0) {
            rel = filtrados[i].energia / filtrados[i].proteina;
        }
        printf("%s - %.2f Kcal - %.2f g - %.2f Kcal/g \n",filtrados[i].descricao, filtrados[i].energia, filtrados[i].proteina, rel);
    }
    return 0;
}
int ex2_I(Alimento alimentos[], int quantidade){ // funcao pro item i
    //Listar os N alimentos de certa categoria que possuam a relação mais
    //alta entre energia e carboidrato, em ordem decrescente com respeito a
    //essa relação, sendo a categoria e N definidos pelo usuário.
    int categoriaEscolhida;
    int quantiaEscolhida;
    int i, j;

    printf("\n \n  Insira a categoria desejada: ");
    scanf("%d", &categoriaEscolhida); // pede ao usuario a categoria
    printf("\n \n  Insira a quantia de itens desejada: ");
    scanf("%d", &quantiaEscolhida); // pede ao usuario a quantia de itens

    Alimento filtrados[101]; // vetor original c dados dos alimentos servw como referencia (tipo int, float) pro filtrados que ta sendo criado
    int totalFiltrados = 0; //contador de filtrados


    for (i = 0; i < quantidade; i++) { // loop para percorrer cada alimento do original, comeca no primeiro termina no ultimo (qnt +1)
        if (alimentos[i].categoria == categoriaEscolhida){ //verifica se pertence a categoria escolhida
            filtrados[totalFiltrados] = alimentos[i]; // copia todos os dados do vetor original pro filtrado
            totalFiltrados++; // adiciona ao contador de filtrados
        }
    }

    //bubble sort pra organizar em decrescente com calculo de energia por carboidrato
    for (i = 0; i < totalFiltrados - 1; i++) {
        for (j = 0;j < totalFiltrados - i - 1; j++ ) {
            float rel1 = 0;
            float rel2 = 0;

            if (filtrados[j].carboidrato != 0) {
                rel1 = filtrados[j].energia / filtrados[j].carboidrato;
            }
            if (filtrados[j+1].carboidrato != 0) {
                rel2 = filtrados[j + 1].energia / filtrados[j + 1].carboidrato;
            }
                if (rel1 < rel2) {
                    Alimento temp = filtrados[j];
                    filtrados[j] = filtrados[j + 1];
                    filtrados[j+1] = temp;
            }
        }
    }

    printf("\n Alimentos da categoria em organizados por relacao mais alta  em ordem decrescente:\n");
    for (int i = 0; i < quantiaEscolhida && i < totalFiltrados; i++) {
        float rel = 0;
        if (filtrados[i].carboidrato != 0) {
            rel = filtrados[i].energia / filtrados[i].carboidrato;
        }
        printf("%s - %.2f Kcal - %.2f g - %.2f Kcal/g \n",filtrados[i].descricao, filtrados[i].energia, filtrados[i].carboidrato, rel);
    }
    return 0;
}
int ex2_J() {
    printf("%s" "Encerrando.");
}
int main() {
        Alimento alimentos[101]; //vetor de structs
        int quantidade = readFile("arquivo.csv", alimentos, 101);
        ex2_A();
        ex2_B(alimentos, quantidade);
        ex2_C(alimentos, quantidade);
        ex2_D(alimentos, quantidade);
        ex2_E(alimentos, quantidade);
        ex2_F(alimentos, quantidade);
        ex2_G(alimentos, quantidade);
        ex2_H(alimentos, quantidade);
        ex2_I(alimentos, quantidade);
        ex2_J();
        return 0;
    }