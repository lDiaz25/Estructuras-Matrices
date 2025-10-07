#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int matriz[4][4];
	int pares=0, impares=0;
	
	//Se inicia la semilla para numeros aleatorios
	srand(time(NULL));

	//Se llena la matriz con numeros aleatorios del 0 al 9
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			matriz[i][j] = rand() % 10; //Se generan entre 0 y 9 
			//Se cuentan pares e impares
			if(matriz[i][j] % 2 == 0)
			  pares++;
			else 
			  impares++;
		}
	}
	//Se imprime matriz
	printf("Matriz 4x4:\n");
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	//Se muestran pares e impares
	printf("Cantidad de pares: %d\n", pares);
	printf("Cantidad de impares: %d\n", impares);

	return 0;
}

