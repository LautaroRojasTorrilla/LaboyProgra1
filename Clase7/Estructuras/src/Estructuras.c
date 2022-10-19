/*
 ============================================================================
 Name        : Estructuras.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANTIDAD 3
#define LIBRE 0
#define OCUPADO 1

typedef struct{
	int legajo;
	float salario;
	char sexo;
	char nombre[31];
	int estado;
}eEmpleado;

int main(void) {
	setbuf(stdout,NULL);

	eEmpleado empleado;
	eEmpleado empleado2;
	eEmpleado empleados[CANTIDAD];
	int i;

	for(i=0; i<CANTIDAD; i++){
		empleados[i].estado = LIBRE;
	}


	printf("Legajo: ");
	scanf("%d", &empleado.legajo);

	printf("Nombre: ");
	fflush(stdin);
	scanf("%[^\n]", empleado.nombre);

	printf("Sexo: ");
	fflush(stdin);
	scanf("%c", &empleado.sexo);

	printf("Salario: ");
	scanf("%f", &empleado.salario);

	empleado.estado = OCUPADO;

//	empleado2.legajo = empleado.legajo;
//	strcpy(empleado2.nombre, empleado.nombre);
//	empleado2.sexo = empleado.sexo;
//	empleado2.salario = empleado.salario;

	empleado2 = empleado;


	for(i=0; i<CANTIDAD; i++){
		if (empleados[i].estado == LIBRE) {
			empleados[i].legajo = (i+1);

			printf("Nombre: ");
			fflush(stdin);
			scanf("%[^\n]", empleados[i].nombre);

			printf("Sexo: ");
			fflush(stdin);
			scanf("%c", &empleados[i].sexo);

			printf("Salario: ");
			scanf("%f", &empleados[i].salario);

			empleados[i].estado = OCUPADO;
		}
	}


	for(i=0; i<80; i++){
		printf("-");
	}


	printf("\nImprimo los datos de un %cnico empleado de la variable emppleado\n\n", 163);

	printf("Legajo\tNombre\t\tSexo\tSalario\n\n");

	printf("%d\t%s\t\t%c\t%.2f\n\n", empleado.legajo, empleado.nombre, empleado.sexo, empleado.salario);

	printf("\nImprimo los datos de un %cnico empleado de la variable emppleado2\n\n", 163);

	printf("Legajo\tNombre\t\tSexo\tSalario\n\n");

	printf("%d\t%s\t\t%c\t%.2f\n\n", empleado2.legajo, empleado2.nombre, empleado2.sexo, empleado2.salario);


	printf("\n\nImprimo los datos del array de empleados.\n\n");
	printf("Legajo\tNombre\t\tSexo\tSalario\n\n");

	for (i = 0; i < CANTIDAD; ++i) {
		if(empleados[i].estado == OCUPADO)
		{
			printf("%d\t%s\t\t%c\t%.2f\n\n", empleados[i].legajo, empleados[i].nombre, empleados[i].sexo, empleados[i].salario);
		}
	}


	return EXIT_SUCCESS;
}
