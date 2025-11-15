#include<stdio.h>
#include<string.h>

struct Estudiante{
	char nombre[50];
	int edad;
	float promedio;
	
}Estudiante[3];  //Arreglo de 3 estudiantes 

int main(){
    float promedioGrupo=0;
    float sumaProm=0;
    int mejorProm=0;

	printf("Datos de los estudiantes.\n\n");
	
	for(int i=0;i<3;i++){
		printf("Nombre: "); scanf(" %[^\n]", Estudiante[i].nombre); // [^\n] Esto lee toda la linea, permitiendo espacios
		printf("Edad: "); scanf("%i", &Estudiante[i].edad);
		printf("Promedio: "); scanf("%f", &Estudiante[i].promedio);
		while(getchar() !='\n');  // Aqui limpiamos el buffer y evitamos que se encime el texto 
		printf("----------------------- \n");
	}
    FILE *archivo= fopen("estudiantes.txt", "w");   // "w" write, para escribir los datos dentre del archivo
    if(archivo==NULL){
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    for(int i=0;i<3;i++){
        fprintf(archivo, "%s\n",Estudiante[i].nombre);
        fprintf(archivo, "%i\n",Estudiante[i].edad);
        fprintf(archivo, "%.2f\n",Estudiante[i].promedio);
    }
    fclose(archivo);
    printf("Datos guardados en estudiantes.txt\n");

    for(int i=0; i<3; i++){
        sumaProm+=Estudiante[i].promedio;
        
        if(Estudiante[i].promedio>Estudiante[mejorProm].promedio){
            mejorProm=i;
        }
    }
    promedioGrupo=sumaProm/3; 
		
	archivo=fopen("estudiantes.txt", "r"); // "r" read, para leer los datos del archivo 
    if(archivo==NULL){
        printf("Error al abrir el archivo\n");
        return 1; 
    }
    printf("\nDatos cargados desde el archivo\n");
    for (int i = 0; i < 3; i++) {
    fscanf(archivo, " %[^\n]", Estudiante[i].nombre);
    fscanf(archivo, "%d", &Estudiante[i].edad);
    fscanf(archivo, "%f", &Estudiante[i].promedio);

    printf("\nEstudiante %d:\n\n", i+1);
    printf("Nombre: %s\n", Estudiante[i].nombre);
    printf("Edad: %d\n", Estudiante[i].edad);
    printf("Promedio: %.2f\n", Estudiante[i].promedio);
    printf("----------------------- \n");
}

fclose(archivo);

printf("\nPromedio del grupo: %.2f\n ", promedioGrupo);
    printf("----------------------- \n\n");
    printf("Mejor estudiante:\n");
    printf(" Nombre: %s\n",Estudiante[mejorProm].nombre);
    printf(" Edad: %i\n",Estudiante[mejorProm].edad);
    printf(" Promedio: %.2f\n",Estudiante[mejorProm].promedio);

    return 0;	
}
