/*
 * Empleado.h
 *
 *  Created on: 19 sep. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#define LIBRE 0
#define OCUPADO 1
#define BORRADO -1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//las anidadas se definen por arriba de las estructuras principales.
//se puede crear una biblioteca para fecha y funciones para utilizar ese dato.
typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int idSector; //PK
	char descripcionSector[25];
	float valorHora;
	char encargadoSector[25];
}eSector;

typedef struct
{
	int legajo; // atributos o campos
	char nombre[50];
	float sueldo;
	int estado;
	eFecha fechadeNacimiento;
	int idSector; //fk
}eEmpleado;

void MostrarUnEmpleado(eEmpleado miEmpleado);
eEmpleado CrearUnEmpleado(); // se podría parametrizar con lo queramos. Es una función input.
void MostrarNominaEmpleados(eEmpleado lista[], int tam);
void CargarEmpleado(eEmpleado lista[], int tam);
void OrdenarEmpleadosPorNombre(eEmpleado lista[], int tam);


#endif /* EMPLEADO_H_ */
