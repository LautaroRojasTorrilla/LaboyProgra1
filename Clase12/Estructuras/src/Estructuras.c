/*
 ============================================================================
 Name        : Estructuras.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	char ApeNom[51];
	char dni[9];//porque no se le hace ningun calculo aritmetico o matematico
	eFecha fechaNac;
	char sexo;
	int nacionalidad;
}ePersona;

typedef struct{
	int id;
	char descripcion[31];
}ePais;

typedef struct{
	int id;
	char descripcion[31];
	int idPais;
}eProvincia;
//1. BUENOS AIRES
//2. LA PAMPA
//3. MISIONES

typedef struct{
	int id;
	char descripcion[31];
	int idProvincia;
}eLocalidad;
//1. AVELLANEDA
//2. QUILMES
//3. LANUS
//Manera correcto de relacionarlo es qué pertenece a qupe

eProvincia provincias[3];

//provincias[0].id = 1;
//strcpy(provincias[0].descripcion, "Buenos Aires");
//provincias[0].idPais = 1;
//
//provincias[1].id = 2;
//strcpy(provincias[1].descripcion, "la pampa");
//provincias[1].idPais = 1;

//eLocalidad localidad;
//localidad[0].id = 1; //avellaneda
//localidad[0].idProvincia = 1; // buens aires.
////(1;1)
//localidad[1].id = 2;//QUILMES
//localidad[1].idProvincia = 1; // buenos aires
////(2;1)
//localidad[2].id = 3;//lanus
//localidad[2].idProvincia = 1; // buenos aires
////(3;1)

/*
 * proveedores 1 1 2
 * productos   1 2 1
 */


int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */


	return EXIT_SUCCESS;
}
