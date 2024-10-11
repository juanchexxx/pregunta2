#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

#define N 4  // Tamaño de la matriz (NxN)

// Función para imprimir una matriz
void imprimir_matriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int rank, size;
    int matrizA[N][N], matrizB[N][N], matrizC[N][N] = {0};
    int fila;

    // Inicializar MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Verificar que el número de procesos es adecuado
    if (size < 2) {
        if (rank == 0) {
            printf("Este programa necesita al menos 2 procesos.\n");
        }
        MPI_Finalize();
        return 0;
    }

    // Inicializar las matrices en el procesador 0
    if (rank == 0) {
        // Rellenar la matriz A
        printf("Matriz A:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrizA[i][j] = i + j;  // Solo un ejemplo, puedes cambiarlo
            }
        }
        imprimir_matriz(matrizA);

        // Rellenar la matriz B
        printf("Matriz B:\n");
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrizB[i][j] = i + 1;  // Solo un ejemplo, puedes cambiarlo
            }
        }
        imprimir_matriz(matrizB);
    }

    // Broadcast la matriz B a todos los procesadores
    MPI_Bcast(matrizB, N * N, MPI_INT, 0, MPI_COMM_WORLD);

    // Procesador 0 envía las filas de la matriz A a los demás procesadores
    for (fila = 0; fila < N; fila++) {
        if (rank == 0) {
            // Enviar cada fila de A a los procesos
            for (int dest = 1; dest < size; dest++) {
                if (fila % size == dest) {  // Solo enviar a los procesos apropiados
                    MPI_Send(matrizA[fila], N, MPI_INT, dest, fila, MPI_COMM_WORLD);
                }
            }
        } else if (rank == fila % size) {
            // Recibir la fila correspondiente de A
            MPI_Recv(matrizA[fila], N, MPI_INT, 0, fila, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            // Multiplicar la fila recibida de A por la matriz B
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    matrizC[fila][j] += matrizA[fila][k] * matrizB[k][j];
                }
            }
        }
    }

    // Procesador 0 recolecta resultados de los demás procesadores
    if (rank == 0) {
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < N; j++) {
                if (i < N) {  // Solo recibir resultados de procesos que han hecho cálculo
                    MPI_Recv(matrizC[i], N, MPI_INT, i, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                }
            }
        }
    } else {
        // Enviar el resultado de vuelta al procesador 0
        MPI_Send(matrizC[fila], N, MPI_INT, 0, rank, MPI_COMM_WORLD);
    }

    // El procesador 0 imprime la matriz resultado
    if (rank == 0) {
        printf("Matriz C (Resultado de A * B):\n");
        imprimir_matriz(matrizC);
    }

    // Finalizar MPI
    MPI_Finalize();
    return 0;
}
