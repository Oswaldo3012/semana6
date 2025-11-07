#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void ingresarDatos(char nombres[][MAX_NOMBRE], float precios[], int n) {
    char entrada[50];
    float valor;

    for (int i = 0; i < n; i++) {
        printf("\nProducto %d\n", i + 1);

        // Ingreso del nombre
        do {
            printf("Ingrese el nombre: ");
            scanf(" %[^\n]", nombres[i]);
            if (strlen(nombres[i]) == 0)
                printf("Error: el nombre no puede estar vacío.\n");
        } while (strlen(nombres[i]) == 0);

        // Ingreso del precio con validación
        while (1) {
            int esValido = 1;
            printf("Ingrese el precio (solo números positivos): ");
            scanf(" %[^\n]", entrada);

            if (strlen(entrada) == 0) {
                printf("Error: campo vacío.\n");
                continue;
            }

            int punto = 0;
            for (int j = 0; entrada[j] != '\0'; j++) {
                if (entrada[j] == '.') {
                    if (punto) {
                        esValido = 0;
                        break;
                    }
                    punto = 1;
                } else if (entrada[j] < '0' || entrada[j] > '9') {
                    esValido = 0;
                    break;
                }
            }

            if (!esValido) {
                printf("Error: solo se permiten números y un punto decimal.\n");
                continue;
            }

            valor = atof(entrada);
            if (valor <= 0) {
                printf("Error: el precio debe ser mayor que 0.\n");
                continue;
            }

            precios[i] = valor;
            break;
        }
    }
}

float calcularTotal(float precios[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += precios[i];
    }
    return total;
}

float calcularPromedio(float precios[], int n) {
    return calcularTotal(precios, n) / n;
}

int indiceMasCaro(float precios[], int n) {
    int indice = 0;
    for (int i = 1; i < n; i++) {
        if (precios[i] > precios[indice])
            indice = i;
    }
    return indice;
}

int indiceMasBarato(float precios[], int n) {
    int indice = 0;
    for (int i = 1; i < n; i++) {
        if (precios[i] < precios[indice])
            indice = i;
    }
    return indice;
}

void buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int n, char nombreBuscado[]) {
    int encontrado = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(nombres[i], nombreBuscado) == 0) {
            printf("El producto '%s' tiene un precio de %.2f\n", nombres[i], precios[i]);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("No se encontró el producto '%s'.\n", nombreBuscado);
    }
}
