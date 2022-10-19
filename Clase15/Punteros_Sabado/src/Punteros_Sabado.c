/*
 ============================================================================
 Name        : Punteros_Sabado.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Duncion que reciba en un array cual es el numero negativo mas grande.
 Además debe retornar si encontró o no un número negativo.

 int RetornarNegativoMax_SiHay(int* array, int len, int* resultado);
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>


int main(void) {
	setbuf(stdout, NULL);

	int numero;
	int* pEntero;

	pEntero = NULL;
	numero = 5;

	pEntero = &numero; //estoy guardando en el puntero la dirección de memoria del numero.

	printf("numero: %d\n", numero);//valor
	printf("&numero: %d\n", &numero);//direcciones
	printf("pEntero: %d\n", pEntero);//direcciones
	printf("*pEntero: %d\n", *pEntero);//valor
	printf("&pEntero: %d\n", &pEntero);//direccion del puntero

	return EXIT_SUCCESS;
}
