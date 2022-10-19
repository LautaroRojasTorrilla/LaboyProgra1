/*
 ============================================================================
 Name        : Ejercicio 2.1
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
  Ingresar 5 números enteros calcular
  y mostrar el promedio de los números.
  Probar la aplicación con distintos valores.
*/
#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 5

int getInt(char *mensaje)
{
	int numero;

	printf("%s", mensaje);
	scanf("%d", &numero);

	return numero;
}

int main(void) {
	setbuf(stdout,NULL);

	int numeroIngresado;
	int contador = 0;
	int acumulador = 0;
	float promedio;

	for (int i = 0; i < CANTIDAD; ++i) {
		numeroIngresado = getInt("\nFavor de ingresar un valor: ");
		contador++;
		acumulador = acumulador + numeroIngresado;
	}

	promedio = (float) acumulador / contador;

	printf("El promedio de las edad ingresada es: %.2f", promedio);

	return EXIT_SUCCESS;
}
