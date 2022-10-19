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

#define LEN 5

void CargarVectorEnteros(int numeros[], int tam);
void MostrarVectorEnteros(int numeros[], int tam);
int AcumularVectorEnteros(int numeros[], int tam);
float PromediarNumeros(int numeros[], int tam);
int ContarPositivos (int numeros[], int tam);


int main(void) {
	setbuf(stdout, NULL);
	int lista[LEN]; // = {5,8,6,3,1};//cargar el vector por extensión
	int suma; // no hace falta inicializarlo porque hay una función que lo hace.
	int contadorPositivos=0;
	float promedio;

	CargarVectorEnteros(lista, LEN);

	suma = AcumularVectorEnteros(lista, LEN);

	promedio = PromediarNumeros(lista, LEN);

	contadorPositivos = ContarPositivos(lista, LEN);

	printf("La suma es: %d\n", suma);
	printf("El promedio es: %.2f\n", promedio);
	printf("La cantidad de positivos es: %d", contadorPositivos);

	MostrarVectorEnteros(lista, LEN);

	return EXIT_SUCCESS;
}

void CargarVectorEnteros(int numeros[], int tam)
{
	for (int i = 0; i < tam; i++) {
		printf("Ingrese un número: ");
		scanf("%d", &numeros[i]);
	}
}

void MostrarVectorEnteros(int numeros[], int tam)
{
	for (int i = 0; i < tam; i++) {
		printf("%d\n", numeros[i]);
	}
}

int AcumularVectorEnteros(int numeros[], int tam)
{
	int acumulador = 0;
	for (int i = 0; i < tam; i++) {
		acumulador +=numeros[i];
	}
	return acumulador;
}

float PromediarNumeros(int numeros[], int tam)
{
	int suma;
	float promedio;

	suma = AcumularVectorEnteros(numeros, tam);
	promedio = (float) suma / tam;

	return promedio;
}

int ContarPositivos (int numeros[], int tam)
{
	int contador = 0;

	for (int i = 0; i < tam; ++i) {
		if(numeros[i]>0)
		{
			contador++;
		}
	}
	return contador;
}

