/*
 * Producto.h
 *
 *  Created on: 26 sep. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

#define TAM 1
#define MAX_CODE 500
#define MAX_PRICE 150000

#define LIBRE 0
#define OCUPADO 1
#define BORRADO -1

#define EEUU 10
#define CHINA 11
#define OTRO 12

#define IPHONE 100
#define MAC 101
#define IPAD 102
#define ACCESORIOS 103

typedef struct{
	int id;
	char descripcion[MAX_CODE];
	int nacionalidad;
	int tipo;
	float precio;
	int isEmpty;
}eProducto;

int eProducto_initArray(eProducto arrayProducto[], int len);
void eProducto_printOne(eProducto prod);
int eProducto_printAll(eProducto arrayProducto[], int len, int state);
eProducto eProducto_LoadOne();
int eProducto_SearchEmpty(eProducto arrayProducto[], int len);
int eProducto_SearchOcupado(eProducto arrayProducto[], int len);
int eProducto_SearchIndexByID(eProducto arrayProducto[], int len, int id);
int eProducto_Charge(eProducto arrayProducto[], int len);
int eProducto_Discharge(eProducto arrayProducto[], int len);
int eProducto_Modify(eProducto arrayProducto[], int len);

#endif /* PRODUCTO_H_ */
