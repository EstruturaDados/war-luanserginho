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

void inicializar(Territorio *t) {
    strcpy(t[0].nome, "Brasil"); strcpy(t[0].cor, "Verde"); t[0].tropas = 3;
    strcpy(t[1].nome, "Estados Unidos"); strcpy(t[1].cor, "Azul"); t[1].tropas = 2;
    strcpy(t[2].nome, "China"); strcpy(t[2].cor, "Vermelho"); t[2].tropas = 4;
    strcpy(t[3].nome, "Espanha"); strcpy(t[3].cor, "Amarelo"); t[3].tropas = 3;
    strcpy(t[4].nome, "Russia"); strcpy(t[4].cor, "Roxo"); t[4].tropas = 2;
}

void mostrarMapa(const Territorio *t) {
    printf("\n=== MAPA ATUAL ===\n");
    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("%d. %s | Cor: %s | Tropas: %d\n", i + 1, t[i].nome, t[i].cor, t[i].tropas);
    }
}

void atacar(Territorio *t) {
    int atq, def;
    printf("\nEscolha atacante (1-5): ");
    scanf("%d", &atq);
    printf("Escolha defensor (1-5): ");
    scanf("%d", &def);

    if (atq < 1 || def < 1 || atq > 5 || def > 5 || atq == def) {
        printf("Invalido!\n");
        return;
    }

    int dadoAtq = rand() % 6 + 1;
    int dadoDef = rand() % 6 + 1;

    printf("Atacante: %d | Defensor: %d\n", dadoAtq, dadoDef);

    if (dadoAtq >= dadoDef) {
        printf("Atacante venceu! Defensor perde 1 tropa.\n");
        t[def - 1].tropas--;
        if (t[def - 1].tropas <= 0) {
            printf("Territorio conquistado!\n");
            strcpy(t[def - 1].cor, t[atq - 1].cor);
            t[def - 1].tropas = 1;
            t[atq - 1].tropas--;
        }
    } else {
        printf("Defensor resistiu!\n");
    }
}

int verificarMissao(const Territorio *t, const char *missao) {
    if (strcmp(missao, "Destruir o exercito Verde") == 0) {
        for (int i = 0; i < QTD_TERRITORIOS; i++)
            if (strcmp(t[i].cor, "Verde") == 0)
                return 0;
        return 1;
    }
    if (strcmp(missao, "Conquistar 3 territorios") == 0) {
        int conquistas = 0;
        for (int i = 0; i < QTD_TERRITORIOS; i++)
            if (strcmp(t[i].cor, "Azul") == 0)
                conquistas++;
        return conquistas >= 3;
    }
    return 0;
}

int main() {
    srand(time(NULL));
    Territorio t[QTD_TERRITORIOS];
    inicializar(t);

    const char *missao = (rand() % 2) ? "Destruir o exercito Verde" : "Conquistar 3 territorios";

    int opcao;
    do {
        printf("\n=== MENU WAR ===\n");
        printf("1 - Atacar\n2 - Verificar Missao\n0 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: atacar(t); break;
            case 2:
                printf("\nMissao: %s\n", missao);
                if (verificarMissao(t, missao))
                    printf("Missao cumprida!\n");
                else
                    printf("Ainda nao completou a missao.\n");
                break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção invalida!\n");
        }
        mostrarMapa(t);
    } while (opcao != 0);

    return 0;
}
