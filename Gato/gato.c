#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Intro_Primera (char c[3][3]);
void tablero (char c[3][3]);
void Intro_Yo (char c[3][3]);
void Intro_PC (char c[3][3]);
int  ganador (char c[3][3]);   // 0 jugador, 1 pc, 2 empate, -1 sigue

int  menu();
void mostrar_marcador(int jug, int pc, int emp);
void pausa_enter();
int  partida(char c[3][3]);

int main(void) {
    char c[3][3];
    int jug = 0, pc = 0, emp = 0;   // marcador 
    srand((unsigned)time(NULL));

    for (;;) {
        int op = menu();
        if (op == 1) {
            int r = partida(c);   // devuelve resultado de la partida 
            while (1) {
                int res = (r >= 100) ? (r - 100) : r;
                if (res == 0) jug++;
                else if (res == 1) pc++;
                else if (res == 2) emp++;
                if (r >= 100) {
                    r = partida(c);
                    continue;
                }
                break;
            }
            pausa_enter();
        } else if (op == 2) {
            mostrar_marcador(jug, pc, emp);
            pausa_enter();
        } else if (op == 3) {
            printf("Saliendo...\n");
            break;
        } else {
            printf("Opcion invalida.\n");
            pausa_enter();
        }
    }
    return 0;
}
// menu principal 
int menu() {
    char buf[32];
    system("clear");
    printf("========== JUEGO DEL GATO ==========\n");
    printf("1) Jugar\n");
    printf("2) Ver marcador\n");
    printf("3) Salir\n");
    printf("Elige una opcion (1-3): ");
    if (!fgets(buf, sizeof(buf), stdin)) return 0;
    if (buf[0] >= '1' && buf[0] <= '3' && buf[1] == '\n') return buf[0]-'0';
    return 0;
}
// muestra el marcador actual 
void mostrar_marcador(int jug, int pc, int emp) {
    system("clear");
    printf("====== MARCADOR ======\n");
    printf("Jugador (X): %d\n", jug);
    printf("PC      (O): %d\n", pc);
    printf("Empates    : %d\n", emp);
    printf("======================\n");
}
// pausa para leer msj 
void pausa_enter() {
    printf("\nPresiona ENTER para continuar...");
    fflush(stdout);
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

int partida(char c[3][3]) {
    int turnos = 0;
    int g;
    char buffer[32];

    Intro_Primera(c);

    do {
        system("clear");
        tablero(c);

        if (turnos % 2 == 0)  Intro_Yo(c);
        else                  Intro_PC(c);

        if (turnos >= 4) {
            g = ganador(c);
            if (g != -1) {
                system("clear");
                tablero(c);
                if (g == 0)      printf("¡Has ganado crack!\n");
                else if (g == 1) printf("¡Perdiste menso!\n");
                else             printf("¡Empate!\n");
		// volver a jugar  regresar al menu
                while (1) {
                    printf("\n¿Deseas jugar otra vez o volver al menu?\n");
                    printf("1) Jugar otra partida\n");
                    printf("2) Regresar al menu principal\n");
                    printf("Elige una opcion (1-2): ");
                    if (!fgets(buffer, sizeof(buffer), stdin)) continue;
                    if (buffer[0] == '1' && buffer[1] == '\n') return 100 + g;
                    if (buffer[0] == '2' && buffer[1] == '\n') return g;
                    printf("Opcion invalida. Intenta de nuevo.\n");
                }
            }
        }
        turnos++;
    } while (turnos < 9);
	// si llega aqui, es empate 
    system("clear");
    tablero(c);
    printf("¡Empate!\n");

    while (1) {
        printf("\n¿Deseas jugar otra vez o volver al menu?\n");
        printf("1) Jugar otra partida\n");
        printf("2) Regresar al menu principal\n");
        printf("Elige una opcion (1-2): ");
        if (!fgets(buffer, sizeof(buffer), stdin)) continue;
        if (buffer[0] == '1' && buffer[1] == '\n') return 100 + 2;
        if (buffer[0] == '2' && buffer[1] == '\n') return 2;
        printf("Opcion invalida. Intenta de nuevo.\n");
    }
}

void Intro_Primera (char c[3][3]) {
    int i, j;
    char aux = '1';
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            c[i][j] = aux++;
}
// pide movimiento al jugador 
void Intro_Yo (char c[3][3]) {
    int i, j, k;
    char aux;
    char buffer[100];

    do {
        do {
            printf("Elige una casilla (1-9): ");
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
                printf("Error de lectura.\n");
                continue;
            }
		// verifico que sea un solo digito valido 
            if (buffer[0] < '1' || buffer[0] > '9' || buffer[1] != '\n') {
                printf("Entrada invalida. Solo un numero del 1 al 9.\n\n");
                buffer[0] = 0;
                continue;
            }
            aux = buffer[0];
        } while(aux < '1' || aux > '9');

        k = 0;
        {
        // mapeo 1.. 9 posiciones del tablero
	    int n = aux - '1';
            i = n / 3;
            j = n % 3;
        }
        if(c[i][j] == 'X' || c[i][j] == 'O') {
            k = 1;
            printf("La casilla esta ocupada, intenta con otro numero\n\n");
        }
    } while (k == 1);

    c[i][j] = 'X';
}
// jugada de la pc 
void Intro_PC (char c[3][3]) {
    int i, j, k;
    do {
        i = rand() % 3;
        j = rand() % 3;
        k = (c[i][j] == 'X' || c[i][j] == 'O');
    } while(k == 1);
    c[i][j] = 'O';
}
// Muestra tablero
void tablero (char c[3][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(j<2) printf(" %c |", c[i][j]);
            else    printf(" %c ", c[i][j]);
        }
        if(i<2) printf("\n-----------\n");
    }
    printf("\n\n");
}

int ganador (char c[3][3]) {  // comprobrar ganador 
// filas
    for (int r = 0; r < 3; r++)
        if (c[r][0] == c[r][1] && c[r][1] == c[r][2] && (c[r][0] == 'X' || c[r][0] == 'O'))
            return (c[r][0] == 'X') ? 0 : 1;
// columnas 
    for (int col = 0; col < 3; col++)
        if (c[0][col] == c[1][col] && c[1][col] == c[2][col] && (c[0][col] == 'X' || c[0][col] == 'O'))
            return (c[0][col] == 'X') ? 0 : 1;
// diagonales
    if (c[0][0] == c[1][1] && c[1][1] == c[2][2] && (c[1][1] == 'X' || c[1][1] == 'O'))
        return (c[1][1] == 'X') ? 0 : 1;

    if (c[0][2] == c[1][1] && c[1][1] == c[2][0] && (c[1][1] == 'X' || c[1][1] == 'O'))
        return (c[1][1] == 'X') ? 0 : 1;
// si hay casillas libres continua
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (c[i][j] != 'X' && c[i][j] != 'O')
                return -1;

    return 2;
}
