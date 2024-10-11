#include <stdio.h>

// Función iterativa para calcular Pi usando punteros
void calcular_pi_iterativo(int *n, double *resultado) {
    double pi = 0.0;
    int signo = 1;  // Alterna entre positivo y negativo

    for (int i = 0; i < *n; i++) {
        pi += signo * (4.0 / (2 * i + 1));
        signo *= -1;  // Cambia de signo
    }

    *resultado = pi;
}

int main() {
    int iteraciones;
    double pi_iterativo;

    // Pedir al usuario el número de iteraciones
    printf("Ingrese el número de iteraciones: ");
    scanf("%d", &iteraciones);

    // Calcular Pi de manera iterativa
    calcular_pi_iterativo(&iteraciones, &pi_iterativo);

    printf("Valor de Pi calculado iterativamente: %.15f\n", pi_iterativo);

    return 0;
}
