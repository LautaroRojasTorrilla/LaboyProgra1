/*
 ============================================================================
 Name        : Ejercicio 3.3.
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getInt(char *mensaje);

int main(void) {
	setbuf(stdout, NULL);

	int numero;

	numero = getInt("Favor de ingresar un número: ");

	printf("El númer ingresado es %d", numero);

	return EXIT_SUCCESS;
}

int getInt(char *mensaje)
{
	int numero;

	printf("%s", mensaje);
	scanf("%d", &numero);

	return numero;
}
