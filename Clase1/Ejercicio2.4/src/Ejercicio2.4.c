/*
 ============================================================================
 Name        : Ejercicio 2.4
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 5

char getChar(char *mensaje)
{
	char letra;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &letra);

	return letra;
}

int main(void) {
	setbuf(stdout,NULL);

	int letra;
	int contadorP = 0;

	for (int i = 0; i < CANTIDAD; ++i) {
		letra = getChar("Favor de ingresar una letra: ");
		if(letra == 'p')
		{
			contadorP++;
		}
	}//fin del for

	printf("Se ingresaron %d letras p.", contadorP);

	return EXIT_SUCCESS;
}
