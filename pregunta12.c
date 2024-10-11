#include <stdio.h>
#include <omp.h>

#define N 10  // Número de términos de la serie de Fibonacci

int main() {
    int fibonacci[N];
    
    // Inicializamos los dos primeros valores de la serie
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    // Establecemos que las variables `fibonacci` es shared (compartida)
    // y `i` es private (privada para cada hilo)
    #pragma omp parallel shared(fibonacci) private(i)
    {
        #pragma omp for
        for (int i = 2; i < N; i++) {
            fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
        }
    }

    // Imprimir la serie de Fibonacci
    printf("Serie de Fibonacci: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", fibonacci[i]);
    }
    printf("\n");

    return 0;
}
