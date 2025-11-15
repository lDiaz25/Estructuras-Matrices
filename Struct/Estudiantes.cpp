#include<stdio.h>
#include<string.h>

struct Estudiante{
	char nombre[50];
	int edad;
	float promedio;
	
}Estudiante[3];  //Arreglo de 3 estudiantes 

int main(){
	printf("Datos de los estudiantes.\n\n");
	
	for(int i=0;i<3;i++){
		printf("Nombre: "); scanf(" %[^\n]", Estudiante[i].nombre); // [^\n] Esto lee toda la linea, permitiendo espacios
		printf("Edad: "); scanf("%i", &Estudiante[i].edad);
		printf("Promedio: "); scanf("%f", &Estudiante[i].promedio);
		while(getchar() !='\n');  // Aqui limpiamos el buffer y evitamos que se encime el texto 
		printf("----------------------- \n");
	}
	printf("\nDatos ingresados de los estudiantes. \n\n");
	for(int i=0;i<3;i++){
		printf("Estudiante %d. \n", i+1);
		printf("Nombre: %s \n",Estudiante[i].nombre);
		printf("Edad: %i \n", Estudiante[i].edad);
		printf("Promedio: %.2f \n", Estudiante[i].promedio);
		printf("----------------------- \n");
	}
		
		
	return 0;	
}
