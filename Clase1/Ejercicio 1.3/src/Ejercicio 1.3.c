/*
 ============================================================================
 Name        : Ejercicio 1.3
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

	//para que haya un número medio todos deben ser distintos
	if(numeroIngresado1 != numeroIngresado2 && numeroIngresado1 != numeroIngresado3
			&& numeroIngresado2 != numeroIngresado3)
	{
		//se hacen las validaciones para determinar cuál es el del medio
		if((numeroIngresado1 > numeroIngresado2 && numeroIngresado1 < numeroIngresado3)
			|| (numeroIngresado1 < numeroIngresado2 && numeroIngresado1 > numeroIngresado3))
		{
			printf("\nEl %d es el del medio", numeroIngresado1);
		}
		else
		{
			if((numeroIngresado2 > numeroIngresado1 && numeroIngresado2 < numeroIngresado3)
					|| (numeroIngresado2 < numeroIngresado1 && numeroIngresado2 > numeroIngresado3))
			{
				printf("\nEl %d es el del medio", numeroIngresado2);
			}
			else
			{
				printf("\nEl %d es el del medio", numeroIngresado3);
			}
		}
	}
	else
	{
		puts("\nNo hay número del medio");
	}

	return EXIT_SUCCESS;
}
