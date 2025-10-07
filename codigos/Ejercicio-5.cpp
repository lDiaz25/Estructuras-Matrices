#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matriz[4][4];
    int max, min;
    int filaMaxima, colMaxima, filaMinima, colMinima;

    srand(time(NULL));

    // Se llena la matriz y se encuentran los maximos y minimos
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            matriz[i][j] = rand() % 51; // Numeros aleatorios 0-50

            if (i == 0 && j == 0) {
                max = min = matriz[i][j];
                filaMaxima = colMaxima = filaMinima = colMinima = 0;
            } else {
                if (matriz[i][j] > max) {
                    max = matriz[i][j];
                    filaMaxima = i;
                    colMaxima = j;
                }
                if (matriz[i][j] < min) {
                    min = matriz[i][j];
                    filaMinima = i;
                    colMinima = j;
                }
            }
        }
    }

    // Se imprime matriz
    printf("Matriz 4x4:\n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    // Se muestran resultados
    printf("\nMaximo: %d en posicion [%d][%d]\n", max, filaMaxima, colMaxima);
    printf("Minimo: %d en posicion [%d][%d]\n", min, filaMinima, colMinima);

    return 0;
}
