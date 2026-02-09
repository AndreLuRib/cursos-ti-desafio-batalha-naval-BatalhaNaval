#include <stdio.h>

int main() {

    // Identificação das linhas (A a J)
    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'};

    // Criando o tabuleiro 10x10
    int tabuleiro[10][10];

    int i, j;

    // Inicializando o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Criando os navios (tamanho fixo 3)
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3]   = {3, 3, 3};
    int navioDiagonal1[3]  = {3, 3, 3};
    int navioDiagonal2[3]  = {3, 3, 3};

    // Coordenadas iniciais
    int linhaH = 1, colunaH = 2; // Horizontal
    int linhaV = 4, colunaV = 6; // Vertical
    int linhaD1 = 2, colunaD1 = 1; // Diagonal principal (\)
    int linhaD2 = 6, colunaD2 = 8; // Diagonal secundária (/)

    // ===============================
    // Navio Horizontal
    // ===============================
    if (colunaH + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                printf("Erro: sobreposição no navio horizontal!\n");
                return 1;
            }
        }
        for (i = 0; i < 3; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }

    // ===============================
    // Navio Vertical
    // ===============================
    if (linhaV + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                printf("Erro: sobreposição no navio vertical!\n");
                return 1;
            }
        }
        for (i = 0; i < 3; i++) {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    } else {
        printf("Erro ao posicionar navio vertical!\n");
        return 1;
    }

    // ===============================
    // Navio Diagonal Principal (\)
    // ===============================
    if (linhaD1 + 3 <= 10 && colunaD1 + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
                printf("Erro: sobreposição no navio diagonal principal!\n");
                return 1;
            }
        }
        for (i = 0; i < 3; i++) {
            tabuleiro[linhaD1 + i][colunaD1 + i] = navioDiagonal1[i];
        }
    } else {
        printf("Erro ao posicionar navio diagonal principal!\n");
        return 1;
    }

    // ===============================
    // Navio Diagonal Secundária (/)
    // ===============================
    if (linhaD2 + 3 <= 10 && colunaD2 - 2 >= 0) {
        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
                printf("Erro: sobreposição no navio diagonal secundária!\n");
                return 1;
            }
        }
        for (i = 0; i < 3; i++) {
            tabuleiro[linhaD2 + i][colunaD2 - i] = navioDiagonal2[i];
        }
    } else {
        printf("Erro ao posicionar navio diagonal secundária!\n");
        return 1;
    }

    // ===============================
    // Exibição do tabuleiro
    // ===============================
    printf("\n   ");
    for (i = 0; i < 10; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (i = 0; i < 10; i++) {
        printf("%c  ", linha[i]);
        for (j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
