#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void llenarMatriz(int matriz[4][4]);
void imprimirMatriz(const char *nombre, int matriz[4][4]);
void restarMatrices(int matrizA[4][4], int matrizB[4][4], int matrizResta[4][4]);

int main() {
    int matrizA[4][4], matrizB[4][4], matrizResta[4][4];

    srand(time(NULL));

    // Se llenan matrices
    llenarMatriz(matrizA);
    llenarMatriz(matrizB);
    restarMatrices(matrizA, matrizB, matrizResta);

    imprimirMatriz("Matriz A", matrizA);
    imprimirMatriz("Matriz B", matrizB);
    imprimirMatriz("Matriz A - B", matrizResta);

    return 0;
}

// Funcion para llenar una matriz aleatoriamente
void llenarMatriz(int matriz[4][4]) {
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            matriz[i][j] = rand() % 21;
}
// Funcion para imprimir una matriz con etiqueta
void imprimirMatriz(const char *nombre, int matriz[4][4]) {
    printf("%s:\n", nombre);
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++)
            printf("%3d ", matriz[i][j]);
        printf("\n");
    }
    printf("\n");
}
// Funcion para restar las matrices, y arrojar resultado
void restarMatrices(int matrizA[4][4], int matrizB[4][4], int matrizResta[4][4]) {
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            matrizResta[i][j] = matrizA[i][j] - matrizB[i][j];
}
