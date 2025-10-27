#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void loop (char c [3][3]);
void Intro_Primera (char c[3][3]);
void tablero (char c[3][3]);
void Intro_Yo (char c[3][3]);
void Intro_PC (char c[3][3]);
int  ganador (char c[3][3]); // 0=X gana, 1=O gana, 2=empate

int main() {
    char c [3][3];
    srand((unsigned)time(NULL));
    loop (c);
    return 0;
}

void loop (char c[3][3]){
   int i = 0;
   int g;

   Intro_Primera (c);

   do{
       system("clear");
       tablero (c);

       if(i % 2 == 0){
           Intro_Yo (c);
       } else {
           Intro_PC (c);
       }

       g = ganador(c);
       if (g != -1) {
           system("clear");
           tablero(c);
           if (g == 0)      printf("Has Ganado!\n");
           else if (g == 1) printf("¡Perdiste menso!\n");
           else             printf("¡Empate!\n");
           return;
       }

       i++;

   } while (i < 9); // solo 9 jugadas máximas
}

void Intro_Primera (char c[3][3]){
    int i, j;
    char aux = '1';                   // inicializa en '1'
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            c[i][j] = aux++;
        }
    }
}
void Intro_Yo (char c[3][3]){
    int i, j, k;
    char aux;
    char buffer[100];  // Para leer la linea completa

    do {
        do {
            printf("Elige una casilla (1-9): ");

            // lee toda la línea de entrada
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                printf("Error al leer entrada.\n");
                continue;
            }

            // verifica que solo haya un dígito y un salto de línea
            if (buffer[0] < '1' || buffer[0] > '9' || buffer[1] != '\n') {
                printf("Entrada inválida. Solo puedes poner un número del 1 al 9.\n\n");
                buffer[0] = 0; // fuerza repetir
                continue;
            }

            aux = buffer[0];
        } while (aux < '1' || aux > '9');

        k = 0;

        // mapeo aritmético 1..9  (i, j)
        int n = aux - '1';
        i = n / 3;
        j = n % 3;

        if (c[i][j] == 'X' || c[i][j] == 'O') {
            k = 1;
            printf("La casilla está ocupada, intenta con otro número.\n\n");
        }

    } while (k == 1);

    c[i][j] = 'X';
}

void Intro_PC (char c[3][3]){
    int i, j, k;
    do{
        i = rand() % 3;
        j = rand() % 3;
        k = (c[i][j] == 'X' || c[i][j] == 'O');
    } while(k == 1);

    c[i][j] = 'O';
}

void tablero (char c[3][3]){
    int i, j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(j<2){
                printf(" %c |",c[i][j]);
            }
            else {
                printf(" %c ",c[i][j]);
            }
        }
        if(i<2){
            printf("\n-----------\n");
        }
    }
    printf("\n\n");
}

int ganador (char c[3][3]){
    // Filas
    for (int r = 0; r < 3; r++) {
        if (c[r][0] == c[r][1] && c[r][1] == c[r][2] && (c[r][0] == 'X' || c[r][0] == 'O'))
            return (c[r][0] == 'X') ? 0 : 1;
    } // Columnas
    for (int col = 0; col < 3; col++) {
        if (c[0][col] == c[1][col] && c[1][col] == c[2][col] && (c[0][col] == 'X' || c[0][col] == 'O'))
            return (c[0][col] == 'X') ? 0 : 1;
    }
    // Diagonales
    if (c[0][0] == c[1][1] && c[1][1] == c[2][2] && (c[1][1] == 'X' || c[1][1] == 'O'))
        return (c[1][1] == 'X') ? 0 : 1;
    if (c[0][2] == c[1][1] && c[1][1] == c[2][0] && (c[1][1] == 'X' || c[1][1] == 'O'))
        return (c[1][1] == 'X') ? 0 : 1;

    // Empate
    int lleno = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (c[i][j] != 'X' && c[i][j] != 'O')
                lleno = 0;

    if (lleno) return 2;
    return -1; // sigue el juego
}
