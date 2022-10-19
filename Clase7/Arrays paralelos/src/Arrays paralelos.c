/*
 ============================================================================
 Name        : Arrays Paralelos.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 3

int main(void) {
	setbuf(stdout,NULL);

	int legajo[CANTIDAD];
	float salario[CANTIDAD];
	char sexo[CANTIDAD];
	char nombre[CANTIDAD][31];
	int i;

	for(i=0; i<CANTIDAD; i++)
	{
		legajo[i] = (i+1);

		printf("Nombre: ");
		fflush(stdin);
		scanf("%[^\n]", nombre[i]);

		printf("Sexo: ");
		fflush(stdin);
		scanf("%c", &sexo[i]);

		printf("Salario: ");
		scanf("%f", &salario[i]);
	}


	printf("Legajo\tNombre\t\tSexo\tSalario\n\n");
	for(i=0; i<CANTIDAD; i++)
	{
		if (salario[i] > 50000) {
			printf("%d\t%s\t\t%c\t%.2f\n", legajo[i], nombre[i], sexo[i], salario[i]);
		}
	}

	return EXIT_SUCCESS;
}
