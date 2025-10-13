#include <stdio.h>
#include <string.h>

int valorRomano(char simbolo) {
    char letras[]  = {'I','V','X','L','C','D','M'}; // Se asigna un valor a cada simbolo del sistema romano
    int  valores[] = {  1,  5, 10, 50,100,500,1000};
    int n = 7;

    for (int i = 0; i < n; i++) {
        if (simbolo == letras[i])
            return valores[i];
    }
    return 0; // símbolo no válido
}

// Convierte un número romano completo a decimal
// Recorre de derecha a izquierda aplicando reglas
int convertirRomano(const char *romano) {
    int total = 0;
    int previo = 0;
    int repeticiones = 1;
    int largo = strlen(romano);

    for (int i = largo - 1; i >= 0; i--) {
        char actual = romano[i];
        int valor = valorRomano(actual);

        // símbolo inválido
        if (valor == 0) {
            printf("Símbolo inválido: %c\n", actual);
            return -1;
        }

        // control de repeticiones
        if (i < largo - 1 && romano[i + 1] == actual)
            repeticiones++;
        else
            repeticiones = 1;

        if ((actual=='I'||actual=='X'||actual=='C'||actual=='M') && repeticiones > 3) {
            printf("Error: '%c' se repite más de 3 veces.\n", actual);
            return -1;
        }
        if ((actual=='V'||actual=='L'||actual=='D') && repeticiones > 1) {
            printf("Error: '%c' no puede repetirse.\n", actual);
            return -1;
        }

        // reglas de resta válidas
        if (i < largo - 1 && valor < valorRomano(romano[i + 1])) {
            char siguiente = romano[i + 1];

            // I solo puede restar a V o X
            if (actual == 'I' && !(siguiente == 'V' || siguiente == 'X')) {
                printf("Error: 'I' solo puede restar a V o X.\n");
                return -1;
            }

            // X solo puede restar a L o C
            if (actual == 'X' && !(siguiente == 'L' || siguiente == 'C')) {
                printf("Error: 'X' solo puede restar a L o C.\n");
                return -1;
            }

            // C solo puede restar a D o M
            if (actual == 'C' && !(siguiente == 'D' || siguiente == 'M')) {
                printf("Error: 'C' solo puede restar a D o M.\n");
                return -1;
            }

            // V, L, D, M nunca pueden restar
            if (actual == 'V' || actual == 'L' || actual == 'D' || actual == 'M') {
                printf("Error: '%c' no puede restarse.\n", actual);
                return -1;
            }

           total -= valor; // resta válida
        } else {
            total += valor; // suma normal
        }

        previo = valor;
    }

    return total;
}

// Función principal: pide número romano y muestra resultado
int main() {
    char romano[30];
    printf("Introduce un número romano (en MAYÚSCULAS): ");
    scanf("%29s", romano);

    int resultado = convertirRomano(romano);

    if (resultado != -1)
        printf("El valor en arábigo de %s es %d\n", romano, resultado);
    else
        printf("No se pudo convertir.\n");

    return 0;
}
