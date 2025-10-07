#include <stdio.h> 

int main() {
	int matriz[4][4];  //Se declara la matriz 4x4
	
	//Se inicia en 0 con ciclos anidados
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			matriz[i][j]=0; 
		}
	}

	//Impresion de matriz en formato de tabla
	printf("Matriz 4x4:\n\n");
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			printf("%d  ", matriz[i][j]); 
		}
		printf("\n"); 
	}
	return 0; 

}
