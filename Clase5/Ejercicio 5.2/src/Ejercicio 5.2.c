/*
 ============================================================================
 Name        : Ejercicio 5.2
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	char caracter;
//	int vector[INGRESO];
//
//	CargarVectorEnteros("Favor de ingresar un número entre -1000 y 1000: ", vector, INGRESO, 1000, -1000);
//
//	MostrarVectorEnteros(vector, INGRESO);
//
//	MostrarVectorNumerosRepetidos(vector, INGRESO);

	caracter = GetChar("Favor de ingresar una letra");

	printf("Ingresaste la letra: %c", caracter);

	return EXIT_SUCCESS;
}
