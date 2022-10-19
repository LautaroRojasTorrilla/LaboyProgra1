/*
 ============================================================================
 Name        : 1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * Realizar una función que retorne un puntero a eProducto.
 * Dentro de esta función deberá crear un producto hardcodeado,
 * un puntero y se apuntará ese puntero al producto.
 * Mostrar el producto cargado 5 veces desde el main.
 * Observar el comportamiento del programa.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int idProducto;
	char descripcion[50];
	float importe;
	//int isEmpty;
}eProducto;

eProducto* eProducto_ForcedLoad();

int main(void) {
	setbuf(stdout,NULL);

	eProducto* producto;

	producto = eProducto_ForcedLoad();

	printf("--%d --%s --%.2f\n", producto->idProducto, producto->descripcion, producto->importe);
	printf("--%d --%s --%.2f\n", producto->idProducto, producto->descripcion, producto->importe);
	printf("--%d --%s --%.2f\n", producto->idProducto, producto->descripcion, producto->importe);
	printf("--%d --%s --%.2f\n", producto->idProducto, producto->descripcion, producto->importe);
	printf("--%d --%s --%.2f\n", producto->idProducto, producto->descripcion, producto->importe);

	return EXIT_SUCCESS;
}

eProducto* eProducto_ForcedLoad()
{

	eProducto auxProducto;
	eProducto* pProducto;

	auxProducto.idProducto = 100;
	strcpy(auxProducto.descripcion, "prueba");
	printf("\n%s", auxProducto.descripcion);
	auxProducto.importe = 15.50;

	pProducto = &auxProducto;

	return pProducto;
}

