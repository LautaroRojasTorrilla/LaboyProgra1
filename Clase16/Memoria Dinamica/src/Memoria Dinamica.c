/*
 ============================================================================
 Name        : Memoria.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
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

eProducto* nuevoProducto();
eProducto* nuevoProductoParametros(char*, int, float);
void MostrarProducto(eProducto*);

int main(void) {
	setbuf(stdout,NULL);

	eProducto* producto;
	eProducto* otroProducto;

	producto = nuevoProducto();
	otroProducto = nuevoProductoParametros("Macbook", 100, 1500);

	MostrarProducto(producto);
	MostrarProducto(otroProducto);


	return EXIT_SUCCESS;
}

// constructor por defecto, no recibe parametros y tiene datos por defecto
eProducto* nuevoProducto()
{

	eProducto* pProducto;

	//le pido que me reserve el tamaño de la estructura.
	// como es void, la sugerencia es castearlo
	pProducto = (eProducto*) malloc(sizeof(eProducto));
	if (pProducto != NULL)
	{
		pProducto->idProducto = 100;
		strcpy(pProducto->descripcion, "prueba");
		pProducto->importe = 15.50;
	}

	return pProducto;
}

// Existe la posibilidad de un constructor parametrizado.

eProducto* nuevoProductoParametros(char* descripcion, int id, float importe)
{
	eProducto* pProducto;

	//le pido que me reserve el tamaño de la estructura.
	// como es void, la sugerencia es castearlo
	pProducto = (eProducto*) malloc(sizeof(eProducto));
	if (pProducto != NULL)
	{
		pProducto->idProducto = id;
		strcpy(pProducto->descripcion, descripcion);
		pProducto->importe = importe;
	}

	return pProducto;
}

// Le paso el puntero por lo que pesa una cosa y la otra.
void MostrarProducto(eProducto* producto)
{
	printf("--%d --%s --%.2f\n", producto->idProducto, producto->descripcion, producto->importe);
}
