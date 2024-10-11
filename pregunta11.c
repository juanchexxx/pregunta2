#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 10  // Tamaño del vector

int main(int argc, char *argv[]) {
    int rank, size;
    int vector_a[N], vector_b[N], vector_resultado[N];
    int i;

    // Inicializar MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Inicialización de los vectores por el procesador maestro (rank 0)
    if (rank == 0) {
        for (i = 0; i < N; i++) {
            vector_a[i] = i;    // Ejemplo: Vector A = [0, 1, 2, 3, ..., N-1]
            vector_b[i] = i * 2;  // Ejemplo: Vector B = [0, 2, 4, 6, ..., 2*(N-1)]
        }

        printf("Vector A: ");
        for (i = 0; i < N; i++) {
            printf("%d ", vector_a[i]);
        }
        printf("\n");

        printf("Vector B: ");
        for (i = 0; i < N; i++) {
            printf("%d ", vector_b[i]);
        }
        printf("\n");
    }

    // Enviar los vectores a los demás procesadores
    MPI_Bcast(vector_a, N, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Bcast(vector_b, N, MPI_INT, 0, MPI_COMM_WORLD);

    // Sumar las posiciones pares y las posiciones impares
    if (rank == 1) {
        // Procesador 1 suma las posiciones impares
        for (i = 1; i < N; i += 2) {
            vector_resultado[i] = vector_a[i] + vector_b[i];
        }
    } else if (rank == 2) {
        // Procesador 2 suma las posiciones pares
        for (i = 0; i < N; i += 2) {
            vector_resultado[i] = vector_a[i] + vector_b[i];
        }
    }

    // Recoger el resultado en el procesador 0 (maestro)
    MPI_Reduce(rank == 1 ? vector_resultado : MPI_IN_PLACE, vector_resultado, N, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // El procesador maestro imprime el resultado
    if (rank == 0) {
        printf("Vector resultado (A + B): ");
        for (i = 0; i < N; i++) {
            printf("%d ", vector_resultado[i]);
        }
        printf("\n");
    }

    // Finalizar MPI
    MPI_Finalize();
    return 0;
}
