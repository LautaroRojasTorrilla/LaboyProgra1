/*
 ============================================================================
 Name        : Ejercicio 3.1
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void imprimirFloat (float numero);

int main(void) {
	setbuf(stdout, NULL);

	float flotante = 1.25;

	imprimirFloat(flotante);

	return EXIT_SUCCESS;
}

void imprimirFloat (float numero)
{
	printf("El número flotante es: %.2f", numero);
}
