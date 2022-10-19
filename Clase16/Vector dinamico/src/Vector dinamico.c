/*
 ============================================================================
 Name        : Vector.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5

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

	//int vector[5]; // pila
	int* pVector; // es el vector
	int* aux;

	pVector = (int*) malloc(sizeof(int)*5); // HEAP

	printf("%d--%d\n", &pVector, pVector);

	if (pVector != NULL)
	{

		for (int i = 0; i < TAM; ++i)
		{
			printf("Ingrese un numero: ");
			scanf("%d", pVector + i);
		}

		for (int i = 0; i < TAM; ++i)
		{
			printf("%d\n", *(pVector + i));
		}
	}

	printf("Reservo espacio para 5 mas\n");

	aux = (int*) realloc(pVector, sizeof(int)* (TAM+5));

	if (aux != NULL)
	{
		pVector = aux;

		for (int i = TAM; i < TAM+5; ++i)
		{
			printf("Ingrese un numero: ");
			scanf("%d", pVector + i);
		}

		for (int i = 0; i < TAM+5; ++i)
		{
			printf("%d\n", *(pVector + i));
		}

		printf("Necesito 4\n");
		aux = (int*) realloc(pVector, sizeof(int)* (4));
		if(aux != NULL)
		{
			pVector = aux;
			//free(aux); // NO HACERLO, APUNTA A LA MISMA DIRECCION QUE pVector.
			for (int i = 0; i < 4; ++i)
			{
				printf("%d\n", *(pVector + i));
			}
		}
	}
	else
	{
		printf("No hay espacio en memoria\n");
	}

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
