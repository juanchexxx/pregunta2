#include <stdio.h>

// Función para calcular el n-ésimo término de Fibonacci usando un vector de tamaño 2
int fibonacci(int n) {
    if (n == 0) return 0;  // Caso base
    if (n == 1) return 1;  // Caso base

    // Vector para almacenar solo los dos últimos términos
    int fib[2] = {0, 1};
    int resultado;

    // Iterar y actualizar el vector con los últimos dos términos
    for (int i = 2; i <= n; i++) {
        resultado = fib[0] + fib[1];  // Calcular el siguiente término
        fib[0] = fib[1];              // Desplazar el valor anterior
        fib[1] = resultado;           // Almacenar el nuevo valor
    }

    return fib[1];  // El último valor almacenado es el resultado
}

int main() {
    int n;

    // Pedir al usuario un número
    printf("Ingrese el número n para calcular el término n-ésimo de Fibonacci: ");
    scanf("%d", &n);

    // Calcular el término n-ésimo de Fibonacci
    int resultado = fibonacci(n);

    printf("El término número %d de la secuencia de Fibonacci es: %d\n", n, resultado);

    return 0;
}
