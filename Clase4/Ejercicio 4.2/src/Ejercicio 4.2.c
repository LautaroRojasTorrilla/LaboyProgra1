/*
 ============================================================================
 Name        : Ejercicio 4.2
 Author      : Rojas Torrilla Lautaros
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	float temperatura1;
	float temperatura2;
	float conversion1;
	float conversion2;

	temperatura1 = GetFloatValMaxMin("Favor de ingresar temperatura en °C: ", MINC , MAXC);
	temperatura2 = GetFloatValMaxMin("Favor de ingresar temperatura en °F: ", MINF , MAXF);

	printf("La temperatura en °C ingresada es %.2f\n", temperatura1);
	printf("La temperatura en °F ingresada es %.2f\n", temperatura2);

    conversion1 = ConvertirCaF(temperatura1);
    conversion2 = ConvertirFaC(temperatura2);

    printf("La temperatura %.2f°C son %.2f°F\n", temperatura1, conversion1);
	printf("La temperatura %.2f°F son %.2f°C\n", temperatura2, conversion2);


	return EXIT_SUCCESS;
}
