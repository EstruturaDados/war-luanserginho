#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QTD_TERRITORIOS 5

typedef struct {
    char nome[30];
    char cor[15];
    int tropas;
} Territorio;

void mostrarMapa(Territorio *t) {
    printf("\n=== Estado Atual do Mapa ===\n");
    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf("Nome: %s\n", t[i].nome);
        printf("Cor: %s\n", t[i].cor);
        printf("Tropas: %d\n", t[i].tropas);
    }
}

int main() {
    srand(time(NULL));

    Territorio *t = (Territorio *)calloc(QTD_TERRITORIOS, sizeof(Territorio));

    printf("=== Cadastro dos Territorios ===\n");
    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("\nTerritorio %d\n", i + 1);
        printf("Nome: ");
        fgets(t[i].nome, sizeof(t[i].nome), stdin);
        t[i].nome[strcspn(t[i].nome, "\n")] = '\0';

        printf("Cor do Exercito: ");
        fgets(t[i].cor, sizeof(t[i].cor), stdin);
        t[i].cor[strcspn(t[i].cor, "\n")] = '\0';

        printf("Numero de Tropas: ");
        scanf("%d", &t[i].tropas);
        getchar();
    }

    int atacante, defensor;
    while (1) {
        mostrarMapa(t);

        printf("\nEscolha o territorio atacante (1 a 5, 0 para sair): ");
        scanf("%d", &atacante);
        if (atacante == 0) break;

        printf("Escolha o territorio defensor (1 a 5): ");
        scanf("%d", &defensor);

        if (atacante == defensor || atacante < 1 || defensor < 1 || atacante > 5 || defensor > 5) {
            printf("Escolha invalida!\n");
            continue;
        }

        int dadoAtq = rand() % 6 + 1;
        int dadoDef = rand() % 6 + 1;

        printf("\n Dado atacante: %d | Dado defensor: %d\n", dadoAtq, dadoDef);

        if (dadoAtq >= dadoDef) {
            printf("Atacante venceu! Defensor perde 1 tropa.\n");
            t[defensor - 1].tropas--;
            if (t[defensor - 1].tropas <= 0) {
                printf("Territorio conquistado!\n");
                strcpy(t[defensor - 1].cor, t[atacante - 1].cor);
                t[defensor - 1].tropas = 1;
                t[atacante - 1].tropas--;
            }
        } else {
            printf("Defensor resistiu!\n");
        }
    }

    free(t);
    return 0;
}
