#include<stdio.h>
#include<string.h>

struct Materia{
    char nombre[30];
    float calificacion;
};
struct Estudiante{
    int matricula;
    char nombre[50];
    int edad;
    float promedio;
    struct Materia materias[3]; // Cada estudiante llevara 3 materias 
};

struct Estudiante estudiantes[50];  // aqui guardo a todos los estudiantes 
int numeroEstudiantes = 0;         // estudiantes capturados

void capturar(), mostrar(), buscar(), guardar(), cargar(); 

int main() {
    int opcion;

    do {
       printf("||||||||| MENU PRINCIPAL |||||||||\n\n");
       printf("1. Capturar estudiantes\n");
       printf("2. Mostrar estudiantes\n");
       printf("3. Buscar por matricula\n");
       printf("4. Salir\n\n");  
       printf("Opcion:  ");
       scanf("%i",&opcion);
       while (getchar() != '\n'); // limpiar buffer

       switch (opcion) {
        case 1: capturar(); break;
        case 2: mostrar(); break;
        case 3: buscar(); break;
        case 4: printf("Saliendo....\n"); break;
        default: printf("Opcion invalida, selecciona 1-4\n");
       }

       int continuar;    // opcion para salir del programa desde dentro de un apartado, o volver al menu principal
       printf("\nDeseas volver al menu principal?\n");
       printf("1. Si\n"); printf("2. No (Salir del programa)\n");
       printf("Opcion:  "); scanf("%i",&continuar);
       while (getchar()!='\n');

       if(continuar==2)
       {
        printf("\nPrograma finalizado.\n");
        break;
       }
       
    } while(opcion!=4);
    return 0;   
}

void capturar(){
    printf("Cuantos estudiantes deseas capturar?  "); scanf("%i", &numeroEstudiantes);
    while (getchar()!='\n');

    for(int i=0; i<numeroEstudiantes; i++){
        printf("\n~~~~~~~~~ Estudiante %i ~~~~~~~~~~~\n", i+1);
        printf("Matricula: "); scanf("%i", &estudiantes[i].matricula);
        while(getchar()!='\n');
        printf("Nombre: "); scanf(" %[^\n]", estudiantes[i].nombre);
        printf("Edad: "); scanf("%i", &estudiantes[i].edad);

        float sumaMaterias=0;

        // Aqui capturamos las 3 materias
        for(int m=0; m<3; m++){
            printf("\nMateria %i, Nombre: ", m+1);
            scanf(" %[^\n]", estudiantes[i].materias[m].nombre);
            printf("Calificacion: "); scanf("%f",&estudiantes[i].materias[m].calificacion); 

            sumaMaterias+=estudiantes[i].materias[m].calificacion;
        }
        estudiantes[i].promedio=sumaMaterias/3;
        printf("\nPromedio final del estudiante: %.2f", estudiantes[i].promedio);
        
    }

    guardar();

}
void mostrar() {
	cargar();
    if(numeroEstudiantes==0){
        printf("\nNo hay estudiantes capturados.\n");
        return;
    }
printf("\n~~~~ Lista de Estudiantes ~~~~\n");
for(int i=0; i<numeroEstudiantes; i++){
    printf("\nEstudiante %i\n",i+1);
    printf("Matricula: %i\n",estudiantes[i].matricula);
    printf("Nombre: %s\n",estudiantes[i].nombre);
    printf("Edad: %i\n",estudiantes[i].edad);
    printf("Promedio: %.2f\n", estudiantes[i].promedio);
    printf("Materias:\n");
    for(int j=0;j<3;j++){
        printf("  -%s: %.2f\n",estudiantes[i].materias[j].nombre,estudiantes[i].materias[j].calificacion);
    }
    printf("-----------------------------------------\n");
}
int mejorPromedio=0;
for(int i=0;i<numeroEstudiantes;i++){
    if(estudiantes[i].promedio>estudiantes[mejorPromedio].promedio){
        mejorPromedio=i;
    }
}
printf("\n~~~~~ Estudiante con mejor promedio del grupo ~~~~~~\n");
printf("Matricula: %i\n", estudiantes[mejorPromedio].matricula);
printf("Nombre: %s\n", estudiantes[mejorPromedio].nombre);
printf("Edad: %i\n", estudiantes[mejorPromedio].edad);
printf("Promedio: %f\n", estudiantes[mejorPromedio].promedio);

printf("Materias:\n");
for(int m=0;m<3;m++){
    printf("  - %s: %.2f\n",estudiantes[mejorPromedio].materias[m].nombre,estudiantes[mejorPromedio].materias[m].calificacion);
}
printf("---------------------------------------\n");
}

void buscar(){
    if(numeroEstudiantes==0){
        printf("\nNo hay estudiantes capturados.\n"); return;
    }
    int buscarMatricula;
    printf("\nIngresa la matricula a buscar: "); scanf("%i", &buscarMatricula);
    while(getchar()!='\n');

    int encontrado=-1;              //Buscamos linealmente, Si queda en -1, el estudiante no existe
    for(int i=0; i<numeroEstudiantes; i++){    
        if(estudiantes[i].matricula==buscarMatricula){
            encontrado=i;
            break;
        }
    }
    if(encontrado==-1){
        printf("\nEstudiante no encontrado.\n"); return;
    }

    printf("\n~~~~~~ Estudiante encontrado ~~~~~~~\n");
    printf("Matricula: %i\n", estudiantes[encontrado].matricula);
    printf("Nombre: %s\n", estudiantes[encontrado].nombre);
    printf("Edad: %i\n", estudiantes[encontrado].edad);
    printf("Promedio: %.2f\n", estudiantes[encontrado].promedio);
    printf("Materias:\n"); 
    for(int j=0; j<3;j++){
        printf("  -%s: %f\n", estudiantes[encontrado].materias[j].nombre,estudiantes[encontrado].materias[j].calificacion);
    }

}
void guardar(){
    FILE *archivo=fopen("estudiantes.txt","w");

    if(!archivo) {
        printf("Error al abrir el archivo estudiantes.txt\n"); return;
    }
    fprintf(archivo, "%i\n", numeroEstudiantes);
    for(int i=0;i<numeroEstudiantes;i++){
        fprintf(archivo, "%i\n",estudiantes[i].matricula);
        fprintf(archivo, "%s\n",estudiantes[i].nombre);
        fprintf(archivo, "%i\n",estudiantes[i].edad);
        fprintf(archivo, "%f\n",estudiantes[i].promedio);

        for(int m=0;m<3;m++){
            fprintf(archivo, "%s\n",estudiantes[i].materias[m].nombre);
            fprintf(archivo, "%f\n",estudiantes[i].materias[m].calificacion);
        }
    }
    fclose(archivo);
    printf("\nDatos guardados en estudiantes.txt correctamente.\n");
}

void cargar(){
    FILE *archivo=fopen("estudiantes.txt", "r");
    if(!archivo){
        printf("\nNo se pudo abrir estudiantes.txt\n"); return;
    }
    fscanf(archivo, "%i", &numeroEstudiantes);
    fgetc(archivo); //aqui limpiamos el salto de linea

    for(int i=0;i<numeroEstudiantes;i++){
        fscanf(archivo, "%i", &estudiantes[i].matricula); fgetc(archivo);
        fgets(estudiantes[i].nombre,50,archivo);
        estudiantes[i].nombre[strcspn(estudiantes[i].nombre, "\n")]=0; //para quitar el salto

        fscanf(archivo, "%i", &estudiantes[i].edad); 
        fscanf(archivo, "%f",&estudiantes[i].promedio); fgetc(archivo);

        for(int m=0;m<3;m++){
            fgets(estudiantes[i].materias[m].nombre,30,archivo);
            estudiantes[i].materias[m].nombre[strcspn(estudiantes[i].materias[m].nombre,"\n")]=0;

            fscanf(archivo,"%f",&estudiantes[i].materias[m].calificacion); fgetc(archivo);
        }
    }
    fclose(archivo);
    printf("\nDatos cargados correctamente desde estudiantes.txt.\n");
}

   