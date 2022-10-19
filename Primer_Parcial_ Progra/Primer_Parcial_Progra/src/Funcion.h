/*
 * Funcion.h
 *
 *  Created on: 3 oct. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#ifndef FUNCION_H_
#define FUNCION_H_
#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#define MIN_IMPORTE 1
#define MAX_IMPORTE 50000
#define MAX_PORCENTAJE 100


float FuncionCalculoDescuento(float importe, int porcentaje);
float Multiplicacion(float factor1, float factor2);
float Dividir(float dividendo, float divisor);
float Restar(float minuendo, float sustraendo);

#endif /* FUNCION_H_ */
