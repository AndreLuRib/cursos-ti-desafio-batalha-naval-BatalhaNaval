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

    // Coordenadas iniciais
    // Navio horizontal começa na linha B, coluna 2
    int linhaH = 1;
    int colunaH = 2;

    // Navio vertical começa na linha E, coluna 6
    int linhaV = 4;
    int colunaV = 6;

    // Posicionando o navio horizontal
    if (colunaH + 3 <= 10) {
        for (i = 0; i < 3; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    } else {
        printf("Erro ao posicionar navio horizontal!\n");
        return 1;
    }

    // Verificando sobreposição e posicionando o navio vertical
    if (linhaV + 3 <= 10) {

        for (i = 0; i < 3; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                printf("Erro: sobreposição de navios!\n");
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

    // Exibindo o tabuleiro
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
