#include <mpi.h>
#include <stdio.h>
#include <string.h>

#define N 6  // Tamaño del vector de cadenas
#define MAX_LEN 100  // Longitud máxima de cada cadena

int main(int argc, char *argv[]) {
    int rank, size;
    char vector_cadenas[N][MAX_LEN] = {
        "cadena0", "cadena1", "cadena2", 
        "cadena3", "cadena4", "cadena5"
    };

    // Inicializar MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Verificar que hay al menos 3 procesos
    if (size < 3) {
        if (rank == 0) {
            printf("Este programa necesita al menos 3 procesos.\n");
        }
        MPI_Finalize();
        return 0;
    }

    // Procesador 0 es el distribuidor
    if (rank == 0) {
        printf("Procesador 0 distribuyendo el vector de cadenas...\n");
        for (int i = 0; i < N; i++) {
            printf("Posición %d: %s\n", i, vector_cadenas[i]);
        }
    }

    // Distribuir el vector de cadenas a todos los procesadores
    MPI_Bcast(vector_cadenas, N * MAX_LEN, MPI_CHAR, 0, MPI_COMM_WORLD);

    // Procesador 1: Desplegar posiciones pares
    if (rank == 1) {
        printf("\nProcesador 1 desplegando posiciones pares:\n");
        for (int i = 0; i < N; i += 2) {
            printf("Posición %d: %s\n", i, vector_cadenas[i]);
        }
    }

    // Procesador 2: Desplegar posiciones impares
    if (rank == 2) {
        printf("\nProcesador 2 desplegando posiciones impares:\n");
        for (int i = 1; i < N; i += 2) {
            printf("Posición %d: %s\n", i, vector_cadenas[i]);
        }
    }

    // Finalizar MPI
    MPI_Finalize();
    return 0;
}
