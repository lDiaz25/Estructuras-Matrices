#include <stdio.h>

int main() {
	int matriz[4][4];  //Se declara la matriz 4x4

	//Se llena la matriz con valores ingresados por el usuario
	printf("Ingresa los valores de la matriz 4x4:\n");
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
		   printf("Elemento [%d][%d]:  ", i, j);
		   scanf("%d", &matriz[i][j]);
		}
	}

	//Impresion de matriz en formato de tabla
	printf("Matriz ingresada:\n\n");
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			printf("%d  ", matriz[i][j]);
		}
		printf("\n");
	}
	return 0;
}
