/*
 ============================================================================
 Name        : Ejercicio 3.4
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getInt(char *mensaje, int minimo, int maximo);

int main(void) {
	setbuf(stdout, NULL);

	int numero;

	numero = getInt("Favor de ingresar un númer entra 1 y 150: ", 1, 150);

	printf("El numero ingresado es %d", numero);

	return EXIT_SUCCESS;
}

int getInt(char *mensaje, int minimo, int maximo)
{
	int numero;

	do{
		printf("%s", mensaje);
		scanf("%d", &numero);
	}
	while(numero > maximo || numero < minimo || minimo > maximo);

	return numero;
}
