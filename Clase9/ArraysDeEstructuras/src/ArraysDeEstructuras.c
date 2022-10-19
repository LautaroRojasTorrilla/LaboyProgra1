/*
 ============================================================================
 Name        : ArraysDeEstructuras.c
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 https://www.youtube.com/watch?v=lyZQPjUT5B4&t=80s&ab_channel=AlgoRythmics
 https://www.youtube.com/watch?v=BKorP55Aqvg&ab_channel=LaurisBeinerts
 https://www.youtube.com/watch?v=i_cVJgIz_Cs&ab_channel=JorgeRubiraSantos
 https://onlinegdb.com/3_hrxV3Ia
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Empleado.h"

#define TAM 4


int main(void) {
	setbuf(stdout,NULL);

	//eEmpleado unEmpleado = {1000, "Juan", 15000};

	eEmpleado listaEmpleados[TAM] = {
			{1000,"Maria",75000,OCUPADO,{10,12,1999}, 1},
			{1501,"Ana",10500,OCUPADO, {10,12,1999}, 2},
			{1023,"Enrique",75820.33,OCUPADO, {10,12,1999}, 3},
			{999,"Pedro",154222.33,OCUPADO, {10,12,1999}, 2}
	};

	eSector listaSectores[3]= {{1, "Programacion", 1590, "Raul"}, {2, "QA", 1300, "Karina"},
			{3, "Analisis", 1000, "Ricardo"}};

	int auxiliarLegajo;
	int opcion;
	char descripcion[100];

	//	for (int i = 0; i < TAM; ++i) {
	//		listaEmpleados[i].estado = LIBRE;
	//	}

	do {
		printf("1.ALTA\n2.BAJA\n3.MODIFICACION\n4.MOSTRAR\n5.ORDENAR\n6.LISTAR con DESCRIPCION\n7. LISTAR SECTORES CON SUS EMPLEADOS\n10.SALIR\n\nElija una opción: ");
		scanf("%d", &opcion);
		switch (opcion) {
		case 1:
			CargarEmpleado(listaEmpleados, TAM);//refactorizar
			break;
		case 2:
			//1*llevarlo a funcion y realizar funciones mas pequeñas y utilizables.buscar un legajo
			//2*interaccion con el usuario: que encuentra el legajo y se modifique el dato
			//								que encuentre el legajo y el usuario cancele la modificacion
			//								que no encuentre el leagjo.
			//3*permitir que el usuario elija que dato quiere modificar.
			//4*detectar si hay dependencia en los datos. Si elimino un dato, que impacto tiene con otras estructuras.
			MostrarNominaEmpleados(listaEmpleados, TAM);
			printf("Ingrese el legajo del empleado: ");
			scanf("%d", &auxiliarLegajo);
			for (int i = 0; i < TAM; ++i)
			{
				if(auxiliarLegajo == listaEmpleados[i].legajo)//lo encontró hacer doble validación, que esté ocupado
				{
					listaEmpleados[i].estado = LIBRE;// puedo ponerle otro estado como baja
					break;
				}
			}
			break;
		case 3:
			//1*llevarlo a funcion y realizar funciones mas pequeñas y utilizables.buscar un legajo
			//2*interaccion con el usuario: que encuentra el legajo y se modifique el dato
			//								que encuentre el legajo y el usuario cancele la modificacion
			//								que no encuentre el leagjo.
			//3*permitir que el usuario elija que dato quiere modificar.
			//4*detectar si hay dependencia en los datos.
			MostrarNominaEmpleados(listaEmpleados, TAM);
			printf("Ingrese el legajo del empleado: ");
			scanf("%d", &auxiliarLegajo);
			for (int i = 0; i < TAM; ++i)
			{
				if(auxiliarLegajo == listaEmpleados[i].legajo)//lo encontró hacer doble validación, que esté ocupado
				{
					printf("Ingrese nuevo sueldo:");
					scanf("%f", &listaEmpleados[i].sueldo);
					break;
				}
			}
			break;
		case 4:
			printf("Lista Ingresada\n");
			MostrarNominaEmpleados(listaEmpleados, TAM);

			break;
		case 5:
			printf("Lista Ordenada\n");
			OrdenarEmpleadosPorNombre(listaEmpleados, TAM);
			MostrarNominaEmpleados(listaEmpleados, TAM);

			break;
		case 6:
			//for dentro de for no. Atomizarlo en 2 funciones.
			for (int i = 0; i < TAM; ++i)//EMPLEADO
			{
				for (int j = 0; j < 3; ++j)//SECTOR
				{
					if (listaEmpleados[i].idSector == listaSectores[j].idSector) // validar //se compara FK vs PK
					{
						strcpy(descripcion,listaSectores[j].descripcionSector);
						break;
					}
				}
				printf("%4d %15s %15s\n", listaEmpleados[i].legajo, listaEmpleados[i].nombre, descripcion);
			}
			break;
		case 7:
			for (int i = 0; i < 3; ++i) //SECTOR
			{
				printf("%s\n", listaSectores[i].descripcionSector);
				for (int j = 0; j < TAM; ++j)//empleados
				{
					if(listaSectores[i].idSector == listaEmpleados[j].idSector) //PK-FK
					{
						printf("\t*%4d %15s\n", listaEmpleados[j].legajo, listaEmpleados[j].nombre);
						//no pongo break porque sino me quedo con el primer empleado que encontre
					}
				}
			}
			break;
		case 10:
			break;
		default:
			break;
		}
	} while (opcion != 10);

	//CargarEmpleado(listaEmpleados, TAM);


	//unEmpleado = CrearUnEmpleado();
	//MostrarUnEmpleado(unEmpleado);

	return EXIT_SUCCESS;
}
