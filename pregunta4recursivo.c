#include <stdio.h>

// Función recursiva para calcular Pi usando punteros
void calcular_pi_recursivo(int *n, int i, double termino, int signo, double *resultado) {
    if (i >= *n) {
        return;  // Condición base
    }
    
    *resultado += signo * termino;
    
    // Llamada recursiva
    calcular_pi_recursivo(n, i + 1, 4.0 / (2 * (i + 1) + 1), signo * -1, resultado);
}

int main() {
    int iteraciones;
    double pi_recursivo = 4.0;  // Iniciar con el primer término de la serie

    // Pedir al usuario el número de iteraciones
    printf("Ingrese el número de iteraciones: ");
    scanf("%d", &iteraciones);

    // Calcular Pi de manera recursiva
    calcular_pi_recursivo(&iteraciones, 0, 4.0 / 3.0, -1, &pi_recursivo);

    printf("Valor de Pi calculado recursivamente: %.15f\n", pi_recursivo);

    return 0;
}
