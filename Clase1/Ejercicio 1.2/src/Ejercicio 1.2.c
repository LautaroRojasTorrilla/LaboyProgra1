/*
 ============================================================================
 Name        : Ejercicio 1.2
 Author      : Lautaro Rojas Torrilla
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int getInt(char *mensaje)
{
	int numero;

	printf("%s", mensaje);
	scanf("%d", &numero);

	return numero;
}
int main(void) {
	setbuf(stdout,NULL);

	int numeroIngresado1;
	int numeroIngresado2;
	int numeroIngresado3;

	numeroIngresado1 = getInt("\nFavor de ingresar el primer número: ");
	numeroIngresado2 = getInt("\nFavor de ingresar el segundo número: ");
	numeroIngresado3 = getInt("\nFavor de ingresar el tercer número: ");

	if(numeroIngresado1>numeroIngresado2 && numeroIngresado1>numeroIngresado3)
	{
		puts("\nEl mayor de los número es el primero.");
	}
	else
	{
		if(numeroIngresado2>numeroIngresado3)
		{
			puts("\nEl mayor de los número es el segundo.");
		}
		else
		{
			puts("\nEl mayor de los número es el tercero.");
		}
	}

	return EXIT_SUCCESS;
}
