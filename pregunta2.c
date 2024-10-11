#include <stdio.h>

// Función para sumar dos números
int suma(int a, int b) {
    return a + b;
}

// Función para restar dos números
int resta(int a, int b) {
    return a - b;
}

// Función para multiplicar dos números
int multiplicacion(int a, int b) {
    return a * b;
}

// Función para dividir dos números
float division(int a, int b) {
    if (b != 0) {
        return (float)a / b;
    } else {
        printf("Error: División por cero no permitida.\n");
        return 0.0;
    }
}

int main() {
    int num1, num2;
    int opcion;
    
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
            printf("Resultado de la suma: %d\n", suma(num1, num2));
            break;
        case 2:
            printf("Resultado de la resta: %d\n", resta(num1, num2));
            break;
        case 3:
            printf("Resultado de la multiplicación: %d\n", multiplicacion(num1, num2));
            break;
        case 4:
            printf("Resultado de la división: %.2f\n", division(num1, num2));
            break;
        default:
            printf("Opción no válida.\n");
            break;
    }

    return 0;
}
