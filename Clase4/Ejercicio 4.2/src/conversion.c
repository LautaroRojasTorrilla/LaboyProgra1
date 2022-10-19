/*
 * conversion.c
 *
 *  Created on: 30 ago. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#include "conversion.h"

float ConvertirCaF(float numero)
{
	float resultado;

    resultado = (numero * 9 / 5 ) + 32;

    return resultado;
}

float ConvertirFaC(float numero)
{
    float resultado;

    resultado = (numero - 32) * 5 / 9;

    return resultado;
}
