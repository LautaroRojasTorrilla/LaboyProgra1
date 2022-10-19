/*
 ============================================================================
 Name        : Puntero.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 https://www.onlinegdb.com/d27vrX1mN
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
char nombre[20];
int nota;
}eAlumno;

int main(void) {
	setbuf(stdout, NULL);

	int i;

	eAlumno alumno[3] ={
			{"matias", 7},
			{"lautaro", 9},
			{"pepe", 3}
	};

	eAlumno* puntero;

	puntero = alumno;

	for (i = 0; i < 3; ++i)
	{
		printf("%s, %d\n", (puntero+i)->nombre, (puntero+i)->nota);
	}


	return EXIT_SUCCESS;
}

/*
 *

	strcpy(alumno.nombre, "lautaro");
	alumno.nota = 7;

	eAlumno* puntero;

	puntero = &alumno;

	//primero me muevo al valor *puntero y despues al campo .nota.
	//Por eso son importantes los paréntesis y el asterisco.
	printf("%d\n%s\n", (*puntero).nota, (*puntero).nombre);
	printf("%d\n%s\n", puntero->nota, puntero->nombre);

//	int peso = sizeof(*puntero);
//	printf("%d\n", peso);
 */
