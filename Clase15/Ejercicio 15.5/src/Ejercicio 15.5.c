/*
 ============================================================================
 Name        : Ejercicio 15.5
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>


int OrdenarEnteros(int* numero1, int* numero2);

int main()
{
	setbuf(stdout, NULL);

	int numero = 150;
	int numero2 = 20;

	OrdenarEnteros(&numero, &numero2);

	printf("Numero1: %d\nNumero2: %d\n", numero, numero2);



	return 0;
}

int OrdenarEnteros(int* numero1, int* numero2)
{
	int retorno = -1;
	int bufferNumero;

	if(numero1 != NULL && numero2 != NULL)
	{
		if(*numero1 > *numero2)
		{
			bufferNumero = *numero1;
			*numero1 = *numero2;
			*numero2 = bufferNumero;
			retorno = 0;
		}
	}

	return retorno;
}
