/*
 ============================================================================
 Name        : Parcial_1.c
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 https://onlinegdb.com/-clO6p8kk
 */

#include <stdio.h>
#include <stdlib.h>
#include "Libro.h"

int main(void) {
	setbuf(stdout,NULL);

	ePais arrayPaises[MAX_EDPAIS] = {
			{1,"ARGENTINA",OCUPADO},
			{2,"EEUU",OCUPADO},
			{3,"ALEMANIA",OCUPADO},
			{4,"RUSIA",OCUPADO},
			{5,"OTRO",OCUPADO}
	};
	eEditorial arrayEditoriales[MAX_EDPAIS] = {
			{1,"KAPELUSZ",OCUPADO},
			{2,"ESTRADA",OCUPADO},
			{3,"ZORZAL",OCUPADO},
			{4,"MINOTAURO",OCUPADO},
			{5,"SUDAMERICANA",OCUPADO}
	};

	eAutor arrayAutores[MAX_AUTOR] = {
			{1,"BORGES",1,OCUPADO},
			{2,"MARX",3,OCUPADO},
			{3,"TWAIN",2,OCUPADO},
			{4,"TOLSTOI",4,OCUPADO},
			{5,"GARCIA MARQUEZ",5,OCUPADO},
			{6,"SUSKIND",3,OCUPADO},
			{7,"DOSTOYEVSKI",4,OCUPADO},
			{8,"SORIANO",1,OCUPADO},
			{9,"POE",2,OCUPADO},
			{10,"HERNANDEZ",1,OCUPADO}
	};

	eTipo arrayTipos[MAX_TIPOS] = {
			{1, "PAPEL", OCUPADO},
			{2, "EBOOK", OCUPADO}
	};

	//HARDCODEO de prueba, con un MAX_LIBROS de 10.
//	eLibro arrayLibros[MAX_LIBROS] = {
//			{100, "Don quijote", {10, 12, 2022}, 154.15, 1, 2, 1 ,OCUPADO},
//			{102, "Las Nereidas", {9, 12, 2022}, 1120.15, 1, 2, 2, OCUPADO},
//			{103, "Una sombra ya pronto seras", {20, 1, 2010}, 1200.15, 3, 1, 1, OCUPADO},
//			{104, "El capital", {9, 12, 1776}, 154.15, 4, 2, 1, OCUPADO},
//			{105, "Juicio y castigo", {8, 6, 1950}, 154.15, 4, 1, 2, OCUPADO},
//			{106, "Libro Random", {9, 77, 1986}, 154.15, 5, 5, 1, OCUPADO},
//			{107, "A las 12", {15, 11, 2000}, 154.15, 1, 5, 2, OCUPADO},
//			{108, "Boca Campeon", {25, 03, 2014}, 154.15, 9, 4, 2, OCUPADO},
//			{109, "ZZ TOP", {20, 04, 2022}, 154.15, 1, 4, 2 ,OCUPADO},
//			{110, "10 escaleras", {9, 12, 1852}, 154.15, 2, 3, 2, OCUPADO}
//	};

	eLibro arrayLibros[MAX_LIBROS];
	eAuxiliar arrayAux[MAX_LIBROS];
	float bufferPromedio;
	float promedio;
	int seleccion;
	int seleccionInformar;
	int seleccionListado;


	eLibro_initArray(arrayLibros, MAX_LIBROS);
	eAuxiliar_initArray(arrayAux, arrayLibros, MAX_LIBROS);


	do {
		MenuPrincipal();
		utn_getInt("Elija una opción: \n", "Error. Elija entre 1 y 6: \n", 1, 6, 2, &seleccion);
		switch (seleccion) {
		case 1:
			eLibro_Charge(arrayLibros, MAX_LIBROS);
			break;
		case 2:
			if (eLibro_SearchOcupado(arrayLibros, MAX_LIBROS) < 0) {
				puts("PARA PODER REALIZAR UNA MODIFICACION DEBE HABER ALGO CARGADO.\n\n");
			}
			else
			{
				eLibro_Modify(arrayLibros, MAX_LIBROS);
			}
			break;
		case 3:
			if (eLibro_SearchOcupado(arrayLibros, MAX_LIBROS) < 0) {
				puts("PARA PODER REALIZAR UNA BAJA DEBE HABER ALGO CARGADO.\n\n");
			}
			else
			{
				eLibro_Discharge(arrayLibros, MAX_LIBROS);

			}
			break;
		case 4:
			if (eLibro_SearchOcupado(arrayLibros, MAX_LIBROS) < 0) {
				puts("PARA PODER REALIZAR UNA BAJA DEBE HABER ALGO CARGADO.\n\n");
			}
			else
			{
				MenuInformar();
				utn_getInt("Elija una opción: \n", "Error. Elija entre 1 y 2: \n", 1, 2, 2, &seleccionInformar);

				switch (seleccionInformar) {
				case 1:
					eAuxiliar_Count(arrayAux, arrayLibros, MAX_LIBROS);
					printf("La cantidad de libros ingresados es: %d\n", arrayAux->contador);

					eAuxiliar_Accum(arrayAux, arrayLibros, MAX_LIBROS);
					printf("La suma de precios es: %.2f\n", arrayAux->acumulador);

					if (eAuxiliar_Dividir(&bufferPromedio, arrayAux->acumulador, arrayAux->contador) == 0)
					{
						promedio = bufferPromedio;
					}
					else
					{
						puts("No se puede realizar el calculo.");
					}
					printf("El promedio de precios es: %.2f\n", promedio);
					eAuxiliar_CountNoSup(arrayAux, arrayLibros, MAX_LIBROS, promedio);
					printf("La cantidad de libros que no superan el promedio es: %d\n\n\n", arrayAux->contadorNoSup);
					break;
				case 2:
					eAuxiliar_CountFecha(arrayAux, arrayLibros, MAX_LIBROS, 1999);
					printf("La cantidad de libros con fecha posterior a 31/12/1999 es: %d\n\n\n", arrayAux->contadorFecha);
					break;
				default:
					puts("Elija una opción valida");
					break;
				}//fin switch punto 4
			}// fin del else punto 4
			break;
		case 5:
			if (eLibro_SearchOcupado(arrayLibros, MAX_LIBROS) < 0) {
				puts("PARA PODER REALIZAR UNA BAJA DEBE HABER ALGO CARGADO.\n\n");
			}
			else
			{
				MenuListado();
				utn_getInt("Elija una opción: \n", "Error. Elija entre 1 y 10: \n", 1, 10, 2, &seleccionListado);
				switch (seleccionListado) {
				case 1:
					eEditorial_printAll(arrayEditoriales, MAX_EDPAIS, OCUPADO);
					break;
				case 2:
					ePais_printAll(arrayPaises, MAX_EDPAIS, OCUPADO);
					break;
				case 3:
					eAutor_printAll(arrayAutores, MAX_AUTOR, OCUPADO);
					break;
				case 4:
					eLibro_printAllAutoryEditorial(arrayLibros, arrayEditoriales, arrayAutores, MAX_LIBROS, MAX_AUTOR, MAX_EDPAIS, OCUPADO);
					break;
				case 5:
					eLibro_SortByAutor_Titulo(arrayLibros, MAX_LIBROS, -1);
					eLibro_printAll(arrayLibros, MAX_LIBROS, OCUPADO);
					break;
				case 6:
					// es el listado del hardcodeo
					eLibro_printAll(arrayLibros, MAX_LIBROS, OCUPADO);
					break;
				case 7:
					eTipo_printAll(arrayTipos, MAX_TIPOS, OCUPADO);
					break;
				case 8:
					eLibro_printTipoPapel(arrayLibros, arrayTipos, MAX_LIBROS, MAX_TIPOS, OCUPADO);
					break;
				case 9:
					// no llegue a hacer la parte de la decada por teclado. Lo iba a hacer en un switch
					eLibro_printExtyDecada(arrayLibros, arrayAutores, arrayPaises, MAX_LIBROS, MAX_AUTOR, MAX_EDPAIS, 1990, OCUPADO);
					break;
				case 10:
					break;
				default:
					break;
				}//fin switch punto 5
			}//fin else punto 5
			break;
		case 6:
			puts("\n\nGracias por utilizar este programa, desarrollado por Lautaro Rojas Torrila. Estudiante UTN");
			break;
		default:
			puts("Elija una opción valida\n\n");
			break;
		}//fin switch de seleccion
	} while (seleccion != 6);

	return EXIT_SUCCESS;
}
