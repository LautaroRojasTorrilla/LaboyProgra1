/*
 * Funciones.c
 *
 *  Created on: 5 sep. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#include "Funciones.h"

int GetInt(char *mensaje, int minimo, int maximo)
{
	int numero;

	do{
		printf("%s", mensaje);
		scanf("%d", &numero);
	}
	while(numero > maximo || numero < minimo || minimo > maximo);

	return numero;
}

char GetChar(char *mensaje)
{
    char caracter;

	do
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &caracter);
	} while ((caracter != ' ') && (caracter < 'a' || caracter > 'z') && (caracter < 'A' || caracter > 'Z'));

	return caracter;
}

void CargarVectorEnteros(char *mensaje, int numeros[], int tam, int max, int min)
{
	for (int i = 0; i < tam; i++) {
		numeros[i] = GetInt(mensaje, min, max);
	}
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

int ContarNegativos (int numeros[], int tam)
{
	int contador = 0;

	for (int i = 0; i < tam; ++i) {
		if(numeros[i]<0)
		{
			contador++;
		}
	}
	return contador;
}

int AcumularVectorPares(int numeros[], int tam)
{
	int acumulador = 0;
	for (int i = 0; i < tam; i++) {
		if(numeros[i] % 2 == 0){
			acumulador += numeros[i];
		}
	}
	return acumulador;
}

int MayorVectorImpar(int numeros[], int tam)
{
	int mayorImpar;
	for(int i=0;i<tam;i++)
	{
		if(numeros[i]%2 != 0)
		{
			if(numeros[i]>mayorImpar||i==0)
			{
				mayorImpar = numeros[i];
			}
		}
	}
	return mayorImpar;
}

void MostrarVectorEnteros(int numeros[], int tam)
{
	for (int i = 0; i < tam; i++) {
		printf("%d\n", numeros[i]);
	}
}

void MostrarVectorPares(int numeros[], int tam)
{
	printf("\nLos numeros pares ingresados son:");
	for (int i = 0; i < tam; i++) {
		if (numeros[i] % 2 != 0) {
			printf("%d\n", numeros[i]);
		}
	}
}

void MostrarVectorPosicionImpar(int numeros[], int tam)
{
	printf("\nLos numeros de las posiciones impares son: ");
	for(int i=0; i < tam; i++)
	{
		if(i %2 != 0)
		{
			printf("\n%d en %d",numeros[i],i);
		}
	}
}

void MostrarVectorNumerosRepetidos(int numeros[], int tam)
{
	int b = 0;
	int auxVector[b];
	int existenRepetidos = 0;

	for(int i = 0; i < tam; i++){
		for(int a = i+1; a < tam; a++){
			if(numeros[i] == numeros[a]){
				auxVector[b] = numeros[i];
				b++;
				existenRepetidos = 1;
			}
		}
	}

	if(existenRepetidos == 1){
		printf("Los números repetidos fueron: \n");
		for(int i = 0; i < b; i++){
			if(i == b-1){
				printf("%d.\n", auxVector[i]);
			}else{
				printf("%d, ", auxVector[i]);
			}
		}
	}else{
		printf("No se ingresaron números repetidos.");
	}
}

void OrdenarVectorAscendente(int numeros[], int tam)
{
	int auxVector;

	for(int i = 0; i < tam - 1; i++ ){
		for(int j = i+1; j < tam; j++){
			if(numeros[i] > numeros[j])
			{
				auxVector = numeros[i];
				numeros[i] = numeros[j];
				numeros[j] = auxVector;
			}
		}
	}
}

void OrdenarVectorDescendente(int numeros[], int tam)
{
	int auxVector;

	for(int i = 0; i < tam - 1; i++ ){
		for(int j = i+1; j < tam; j++){
			if(numeros[i] < numeros[j])
			{
				auxVector = numeros[i];
				numeros[i] = numeros[j];
				numeros[j] = auxVector;
			}
		}
	}
}
