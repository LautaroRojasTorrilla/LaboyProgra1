/*
 * Empleado.c
 *
 *  Created on: 19 sep. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#include "Empleado.h"

void MostrarUnEmpleado(eEmpleado miEmpleado)
{
	printf("%10d %20s %5.2f \t %d/%d/%d\n", miEmpleado.legajo, miEmpleado.nombre, miEmpleado.sueldo,
			miEmpleado.fechadeNacimiento.dia, miEmpleado.fechadeNacimiento.mes, miEmpleado.fechadeNacimiento.anio);
}

void MostrarNominaEmpleados(eEmpleado lista[], int tam)
{
	for (int i= 0; i < tam; i++)
	{
		if(lista[i].estado == OCUPADO)
		{
			MostrarUnEmpleado(lista[i]); // le estoy pasadno el tipo de dato, una struct
		}
	}
}

eEmpleado CrearUnEmpleado()
{
	eEmpleado empleadoFuncion;

	printf("Ingrese el legajo del empleado: ");
	scanf("%d", &empleadoFuncion.legajo); // a la dirección de memoria de legajo, le asigno un valor.

	printf("Ingrese el nombre del empleado: ");
	fflush(stdin);
	gets(empleadoFuncion.nombre);

	printf("Ingrese el sueldo del empleado: ");
	scanf("%f", &empleadoFuncion.sueldo);

	return empleadoFuncion;
}

void CargarEmpleado(eEmpleado lista[], int tam)
{
	for (int i= 0; i < tam; i++)
	{
		if (lista[i].estado == LIBRE) {
			lista[i] = CrearUnEmpleado();
			lista[i].estado = OCUPADO;
			break;
		}
	}
}
//Busque en qué infice guardar el dato. el void para a otro tipo de dato y que en el main pueda recibir el retorno


void OrdenarEmpleadosPorNombre(eEmpleado lista[], int tam)
{
	eEmpleado auxiliarEmpleado;

	for (int i = 0; i <tam-1; ++i) // tiene que terminar 1 elemento antes del final de array
	{
		for (int j = i+1; j <tam; j++)
		{
			if(strcmp(lista[i].nombre, lista[j].nombre) > 0)
			{
				auxiliarEmpleado = lista[i];
				lista[i] = lista[j];
				lista[j] = auxiliarEmpleado;
			}
		}
	}
}
