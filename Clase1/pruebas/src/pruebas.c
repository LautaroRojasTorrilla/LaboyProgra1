/******************************************************************************

Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la aplicación con distintos valores.
Ejemplo 1:  3 - 5 - 7 - 9 - 1
Ejemplo 2:  2 - 1 - 8 -1 - 2

Alumna Daiana Paz 1F
 *******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	setbuf(stdout,NULL);

	int numero;
	int i;
	float promedio;
	int acumulador;

	acumulador = 0;

	for(i=0; i<5; i++)
	{
		printf("Ingresar un numero: ");
		scanf("%d", numero);

		acumulador += numero;
	}

	promedio = (float) acumulador/i;

	printf("El promedio de los numeros es : %f", promedio);




	return 0;
}

