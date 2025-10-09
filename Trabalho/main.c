#include <stdio.h>
#include "funcoes.c"
#include <ctype.h> // pra usar toupper()

int main() {
    Alimento alimentos[101]; //vetor de structs
    int quantidade = readFile("arquivo.csv", alimentos, 101);
    char opcao;

    do {
        printf("\nA. Listar categorias de alimentos\n");
        printf("B. Listar alimentos em ordem alfabetica\n");
        printf("C. Listar alimentos por energia (decrescente)\n");
        printf("D. Listar alimentos com maior umidade\n");
        printf("E. Listar alimentos com maior energia\n");
        printf("F. Listar alimentos com maior proteina\n");
        printf("G. Listar alimentos com maior carboidrato\n");
        printf("H. Listar alimentos com maior relacao energia/proteina\n");
        printf("I. Listar alimentos com maior relacao energia/carboidrato\n");
        printf("J. Encerrar programa\n");

        printf("\nEscolha uma opcao: ");
        scanf(" %c", &opcao); // lê uma letra (com espaço antes pra ignorar \n)
        opcao = toupper(opcao); // transforma em maiúscula pra evitar erro

        switch (opcao) {
            case 'A': ex2_A(alimentos, quantidade); break;
            case 'B': ex2_B(alimentos, quantidade); break;
            case 'C': ex2_C(alimentos, quantidade); break;
            case 'D': ex2_D(alimentos, quantidade); break;
            case 'E': ex2_E(alimentos, quantidade); break;
            case 'F': ex2_F(alimentos, quantidade); break;
            case 'G': ex2_G(alimentos, quantidade); break;
            case 'H': ex2_H(alimentos, quantidade); break;
            case 'I':ex2_I(alimentos, quantidade); break;
            case 'J': printf("\nEncerrando o programa...\n"); break;
            default: printf("\nOpcao invalida! Opções de A - J.\n");
        }
    } while (opcao != 'J');

        return 0;
}