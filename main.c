#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
    float precios[MAX_PRODUCTOS];
    int n;
    char nombreBuscado[MAX_NOMBRE];
    int opcion;

    do {
        printf("Ingrese la cantidad de productos (1 a 10): ");
        scanf("%d", &n);
        if (n < 1 || n > MAX_PRODUCTOS)
            printf("Error: cantidad fuera de rango.\n");
    } while (n < 1 || n > MAX_PRODUCTOS);

    ingresarDatos(nombres, precios, n);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Calcular precio total del inventario\n");
        printf("2. Mostrar producto más caro\n");
        printf("3. Mostrar producto más barato\n");
        printf("4. Calcular precio promedio\n");
        printf("5. Buscar producto por nombre\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Precio total del inventario: %.2f\n", calcularTotal(precios, n));
                break;

            case 2: {
                int idx = indiceMasCaro(precios, n);
                printf("El producto más caro es '%s' con un precio de %.2f\n", nombres[idx], precios[idx]);
                break;
            }

            case 3: {
                int idx = indiceMasBarato(precios, n);
                printf("El producto más barato es '%s' con un precio de %.2f\n", nombres[idx], precios[idx]);
                break;
            }

            case 4:
                printf("El precio promedio de los productos es: %.2f\n", calcularPromedio(precios, n));
                break;

            case 5:
                printf("Ingrese el nombre del producto a buscar: ");
                scanf(" %[^\n]", nombreBuscado);
                buscarProducto(nombres, precios, n, nombreBuscado);
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;

            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 6);

    return 0;
}
