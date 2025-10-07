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