/*
 ============================================================================
 Name        : Funciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//prototipo o firma.
//tipo o clase que retorna - nombre de la función - parámetros de la función.
//se usan parámetros variables, cuyo scope es dentro de la función
//existen y se pueden utilizar dentro de la función.

int calcularSuma(int numero1, int numero2);

int main(void) {

	int edad1= 20;
	int edad2= 30;
	int precio1=100;
	int precio2=200;

	int resultadoEdad;
	int resultadoPrecio;

	//llamada o invocación de la función.

	resultadoEdad = calcularSuma(edad1, edad2);
	resultadoPrecio = calcularSuma(precio1, precio2);

	return EXIT_SUCCESS;
}

int calcularSuma(int numero1, int numero2)
{
	int resultado;

	resultado = numero1 + numero2;

	return resultado;
	//evalua que condición tiene la entrada y devuelve un estado.
}



