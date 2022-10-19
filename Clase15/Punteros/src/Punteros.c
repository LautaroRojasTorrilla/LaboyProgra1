/*
 ============================================================================
 Name        : s.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numero;
	int* puntero;
	int* puntero2;

	//acceder a la dirección de memoria de la variable.
	puntero = &numero;
	puntero2 = puntero;

	//le asigno 10 a mi variable numero
	numero = 10;

	//Hay que tener cuidado, se trabaja sobre direcciones de memoria
	//NO OLVIDAR EL *
	*puntero2 = 25;

	//accedo al valor, a través del .
	printf("%d\n", numero);

	return EXIT_SUCCESS;
}
