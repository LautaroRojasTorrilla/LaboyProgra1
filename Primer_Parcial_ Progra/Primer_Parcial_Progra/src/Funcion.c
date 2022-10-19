/*
 * Funcion.c
 *
 *  Created on: 3 oct. 2022
 *      Author: Rojas Torrilla Lautaro
 *
 *      1. Realizar una función que reciba como parámetros un importe y un porcentaje.
 *      La función deberá calcular un descuento en base al porcentaje y aplicarlo,
 *      devolviendo el importe a pagar. Probar la función desde el main.
 *      Subir el GDB acá. En caso de no hacerlo solo rellenar el campo con un punto.
 */

#include "Funcion.h"

// las validaciones están en el input cuando se llame a la función con las funciones GET.
float FuncionCalculoDescuento(float importe, int porcentaje)
{

	float operacion;

	operacion = Restar(importe, Dividir(Multiplicacion(importe, porcentaje), 100));

	return operacion;
}

float Multiplicacion(float factor1, float factor2)
{
	float operacion;

	operacion = factor1 * factor2;

	return operacion;
}

float Dividir(float dividendo, float divisor)
{
	float operacion;

	if(divisor != 0)
	{
		operacion = dividendo / divisor;
	}
	else
	{
		puts("No es posible realizar una division por cero.");
	}

	return operacion;
}

float Restar(float minuendo, float sustraendo)
{
	float operacion;

	operacion = minuendo - sustraendo;

	return operacion;
}