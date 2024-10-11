#include <stdio.h>

// Función para sumar dos números usando punteros
void suma(int *a, int *b, int *resultado) {
    *resultado = *a + *b;
}

// Función para restar dos números usando punteros
void resta(int *a, int *b, int *resultado) {
    *resultado = *a - *b;
}

// Función para multiplicar dos números usando punteros
void multiplicacion(int *a, int *b, int *resultado) {
    *resultado = (*a) * (*b);
}

// Función para dividir dos números usando punteros
void division(int *a, int *b, float *resultado) {
    if (*b != 0) {
        *resultado = (float)(*a) / (*b);
    } else {
        printf("Error: División por cero no permitida.\n");
        *resultado = 0.0;
    }
}

int main() {
    int num1, num2;
    int opcion;
    int resultado_int;
    float resultado_float;
    
    // Pedir al usuario los dos números
    printf("Ingrese el primer número: ");
    scanf("%d", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);
    
    // Mostrar el menú de opciones
    printf("\nSeleccione una operación:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicación\n");
    printf("4. División\n");
    printf("Opción: ");
    scanf("%d", &opcion);
    
    // Realizar la operación seleccionada
    switch(opcion) {
        case 1:
            suma(&num1, &num2, &resultado_int);
            printf("Resultado de la suma: %d\n", resultado_int);
            break;
        case 2:
            resta(&num1, &num2, &resultado_int);
            printf("Resultado de la resta: %d\n", resultado_int);
            break;
        case 3:
            multiplicacion(&num1, &num2, &resultado_int);
            printf("Resultado de la multiplicación: %d\n", resultado_int);
            break;
        case 4:
            division(&num1, &num2, &resultado_float);
            printf("Resultado de la división: %.2f\n", resultado_float);
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }

    return 0;
}
