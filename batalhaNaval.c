#include <stdio.h>

#define TAM_TAB 10
#define TAM_HAB 5

int main() {

    /* ================= TABULEIRO ================= */
    int tabuleiro[TAM_TAB][TAM_TAB] = {0};

    /* Navios (apenas para visualização) */
    tabuleiro[2][3] = 3;
    tabuleiro[4][6] = 3;
    tabuleiro[7][1] = 3;

    /* ================= MATRIZES DE HABILIDADE ================= */
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octaedro[TAM_HAB][TAM_HAB];

    int centro = TAM_HAB / 2;

    /* ================= CONE (apontando para baixo) ================= */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (i >= centro &&
                j >= centro - (i - centro) &&
                j <= centro + (i - centro)) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    /* ================= CRUZ ================= */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            if (i == centro || j == centro) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    /* ================= OCTAEDRO (losango) ================= */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int di = i - centro;
            if (di < 0) {
                di = -di;
            }

            int dj = j - centro;
            if (dj < 0) {
                dj = -dj;
            }

            if (di + dj <= centro) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    /* ================= SOBREPOSIÇÃO DAS HABILIDADES ================= */

    /* Pontos de origem no tabuleiro */
    int origem_cone_l = 3, origem_cone_c = 3;
    int origem_cruz_l = 6, origem_cruz_c = 6;
    int origem_octa_l = 8, origem_octa_c = 4;

    /* ---------- CONE ---------- */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int l = origem_cone_l + i - centro;
            int c = origem_cone_c + j - centro;

            if (l >= 0 && l < TAM_TAB && c >= 0 && c < TAM_TAB) {
                if (cone[i][j] == 1 && tabuleiro[l][c] == 0) {
                    tabuleiro[l][c] = 1;
                }
            }
        }
    }

    /* ---------- CRUZ ---------- */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int l = origem_cruz_l + i - centro;
            int c = origem_cruz_c + j - centro;

            if (l >= 0 && l < TAM_TAB && c >= 0 && c < TAM_TAB) {
                if (cruz[i][j] == 1 && tabuleiro[l][c] == 0) {
                    tabuleiro[l][c] = 1;
                }
            }
        }
    }

    /* ---------- OCTAEDRO ---------- */
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {

            int l = origem_octa_l + i - centro;
            int c = origem_octa_c + j - centro;

            if (l >= 0 && l < TAM_TAB && c >= 0 && c < TAM_TAB) {
                if (octaedro[i][j] == 1 && tabuleiro[l][c] == 0) {
                    tabuleiro[l][c] = 1;
                }
            }
        }
    }

    /* ================= EXIBIÇÃO DO TABULEIRO ================= */

    printf("\nTABULEIRO FINAL:\n\n");

    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
