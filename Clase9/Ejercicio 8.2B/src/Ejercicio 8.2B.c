/*
 ============================================================================
 Name        : 2B.c
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"

int main(void) {
	setbuf(stdout,NULL);

	int seleccion;
	eProducto listaProductos[TAM];

	eProducto_initArray(listaProductos, TAM);

	do {
		printf("1.ALTA\n2.BAJA\n3.MODIFICACION\n4.LISTADO\n5.LISTADO ORDENADO POR PRECIO"
				"\n6.LISTADO ORDENADO POR DESCRIPCION\n7.SALIR\n\nElija una opción: ");
		scanf("%d", &seleccion);
		switch (seleccion) {
		case 1:
			//tengo que usar los retornos para los mensajes.
			eProducto_Charge(listaProductos, TAM);
			break;
		case 2:
			eProducto_Discharge(listaProductos, TAM);
			break;
		case 3:
			eProducto_Modify(listaProductos, TAM);

			break;
		case 4:
			eProducto_printAll(listaProductos, TAM, OCUPADO);
			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;

		default:
			break;
		}//fin switch de seleccion
	} while (seleccion != 7);

	return EXIT_SUCCESS;
}
