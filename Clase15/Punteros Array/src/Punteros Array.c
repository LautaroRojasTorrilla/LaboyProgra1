/*
 ============================================================================
 Name        : Punteros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 https://www.onlinegdb.com/lteh9Npy_
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numeros[5];
	int i;

	int* num;

	num = &numeros[0];


	//ARITMETICA VECTORIAL
	/*
	for (i = 0; i < 5; ++i) {
		printf("ingrese 5 numeros: \n\n");
		scanf("%d", &numeros[i]);
	}

	for (i = 0; i < 5; ++i) {
		printf("%d\n", numeros[i]);
	}
	*/

	//ARITMETICA DE PUNTEROS
	for (i = 0; i < 5; ++i)
	{
		printf("ingrese 5 numeros: \n\n");
		scanf("%d", num + i);
	}

	for (i = 0; i < 5; ++i)
	{
		// es muy importante saber a qué tiene que acceder.
		//me muevo por las posiciones de memorias.
		printf("%d\n", *(num + i));
	}

	return EXIT_SUCCESS;
}
