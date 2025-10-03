#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    FILE *arquivo = fopen("Trabalho/arquivo.csv" , "r");
    char buffer[1000];
    char *data;
    if (arquivo == NULL) {
        printf("Erro ao carregar arquivo \n");
        exit(-1);
    }
    printf("Arquivo aberto \n");

    //primeira linha
    fgets(buffer , sizeof(buffer) , arquivo);
    printf("%s\n" , buffer );


    //separacao dos valores
    data = strtok(buffer,",");
    printf("%s\n" , data);

    data = strtok(NULL,",");
    printf("%s\n" , data);

    data = strtok(NULL,",");
    printf("%s\n" , data);

    data = strtok(NULL,",");
    printf("%s\n" , data);

    data = strtok(NULL,",");
    printf("%s\n" , data);

    data = strtok(NULL,",");
    printf("%s\n" , data);

    data = strtok(NULL,",");
    printf("%s\n" , data);


    fgets(buffer , sizeof(buffer) , arquivo);
    printf("%s\n" , buffer );


    return 0;
}
