#ifndef FUNCIONES_H
#define FUNCIONES_H

#define MAX_NOMBRE 50
#define MAX_PRODUCTOS 10

// Prototipos
void ingresarDatos(char nombres[][MAX_NOMBRE], float precios[], int n);
float calcularTotal(float precios[], int n);
float calcularPromedio(float precios[], int n);
int indiceMasCaro(float precios[], int n);
int indiceMasBarato(float precios[], int n);
void buscarProducto(char nombres[][MAX_NOMBRE], float precios[], int n, char nombreBuscado[]);

#endif
