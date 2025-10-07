#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matriz[4][4];
    int sumaFilas[4] = {0};
    int sumaColumnas[4] = {0};

    srand(time(NULL));

    // Se llena la matriz aleatoriamente y se realiza la suma de filas y columnas
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            matriz[i][j] = rand() % 51; // Números aleatorios 0-50
            sumaFilas[i] += matriz[i][j];
            sumaColumnas[j] += matriz[i][j];
        }
    }

    // Se imprime matriz con suma de filas
    printf("Matriz con suma de filas:\n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf(" | Suma fila %d: %d\n", i, sumaFilas[i]);
    }

    // Se imprime suma de columnas
    printf("\nSuma de columnas: ");
    for (int j=0; j<4; j++) {
        printf("%3d ", sumaColumnas[j]);
    }
    printf("\n");

    return 0;
}
