#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int matriz[4][4];
    int suma=0;
    float promedio;
    int min=1, max=50; // Rango de numeros

    // Se inicia la semilla
    srand(time(NULL));

    // Se llena matriz con numeros aleatorios y sumamos
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            matriz[i][j] = rand() % (max - min + 1) + min; 
            suma += matriz[i][j];
        }
    }

    // Promedio
    promedio = suma / 16.0;

    // Se imprime la matriz
    printf("Matriz 4x4:\n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Mostrar resultados
    printf("Suma de todos los elementos: %d\n", suma);
    printf("Promedio de los elementos: %.2f\n", promedio);

    return 0;
}
