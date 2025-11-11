#include <stdio.h>
#include <string.h>

#define QTD_TERRITORIOS 5

typedef struct {
    char nome[30];
    char cor[15];
    int tropas;
} Territorio;

int main() {
    Territorio territorios[QTD_TERRITORIOS];

    printf("=== Cadastro Inicial dos Territorios ===\n");

    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf( "Nome: ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Cor do Exercito: ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Numero de Tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar(); // limpa buffer
    }

    printf("\n=== Estado Atual do Mapa ===\n");
    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }

    return 0;
}
