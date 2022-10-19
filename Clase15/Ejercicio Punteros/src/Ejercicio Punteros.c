/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Realizar un algoritmo que me permite cambiar los valores de dos variables por medio de una funcion
 https://onlinegdb.com/VwadNg3Z8
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SwapInt(int * num, int* num2);

int main(void) {
	setbuf(stdout, NULL);

	int numero = 10;
	int numero2 = 25;

	SwapInt(&numero, &numero2);

	printf("Numero 1: %d\nNumero 2: %d\n", numero, numero2);

	return EXIT_SUCCESS;
}

void SwapInt(int* num, int* num2)
{
	int auxNum;

	auxNum = *num;
	//se usa el * para acceder al valor de lo que está apuntando. El operador de indirección
	*num = *num2;
	*num2 = auxNum;
}
