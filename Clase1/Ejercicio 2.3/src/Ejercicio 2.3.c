/*
 ============================================================================
 Name        : Ejercicio 2.3
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define PRECIO 600
#define DESCUENTO 25

int getInt(char *mensaje)
{
	int numero;

	printf("%s", mensaje);
	scanf("%d", &numero);

	return numero;
}

float getFloat(char *mensaje)
{
	float numero;

	printf("%s", mensaje);
	scanf("%f", &numero);

	return numero;
}

char getChar(char *mensaje)
{
	char letra;

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%c", &letra);

	return letra;
}

int menuContinuar(char* mensaje)
{
	int seleccion;

	printf("%s", mensaje);
	printf("\n1. Sí\n2. No\n");
	fflush(stdin);
	scanf("%d", &seleccion);

	return seleccion;
}

int main(void) {
	setbuf(stdout,NULL);

	int numeroDeCliente;
	char estadoCivil;
	int edad;
	float temperaturaCorporal;
	char genero;
	int MujerSolteraMasJoven;
	int MujerSolteraMasJovenID;
	int totalViaje;
	int totalViajeConDescuento;

	int contadorViudoMayorA60 = 0;
	int contadorPasajero = 0;
	int contadorMayorA60;

	int flagMSMasJoven = 0;

	do {
		numeroDeCliente = getInt("Favor de ingresar el número de pasajero:\n");
		estadoCivil = getChar("Favor de ingresar el estado civil:\ns para soltero, c para casado o v viudo\n");
		while(estadoCivil != 's' && estadoCivil != 'c' && estadoCivil != 'v'){
			estadoCivil = getChar("Favor de ingresar s, c o v:\n");
		}
		edad = getInt("Favor de ingresar la edad del pasajero:\n");
		temperaturaCorporal = getFloat("Favor de ingresar la temperatura del pasajero:\n");
		while(temperaturaCorporal < 35 || temperaturaCorporal > 41){
			temperaturaCorporal = getFloat("Favor de ingresar entre 35 y 41:\n");
		}
		genero = getChar("Favor de ingresar el género:\nf para femenino, m para masculino, o para no binario\n");
		while(genero != 'f' && genero != 'm' && genero != 'o'){
			genero = getChar("Favor de ingresar f, m ó o:\n");
		}
		contadorPasajero++;
		system("cls");

		//a) La cantidad de personas con estado "viudo" de más de 60 años.
		if (edad > 60) {
			contadorMayorA60++;
			if (estadoCivil == 'v') {
				contadorViudoMayorA60++;
			}
		}

		//b) el número de cliente y edad de la mujer soltera más joven.
		if(estadoCivil == 's' && genero == 'f'){
			if(flagMSMasJoven == 0){
				MujerSolteraMasJoven = edad;
				MujerSolteraMasJovenID = numeroDeCliente;
				flagMSMasJoven = 1;
			}else{
				if(edad < MujerSolteraMasJoven){
					MujerSolteraMasJoven = edad;
					MujerSolteraMasJovenID = numeroDeCliente;;
				}
			}
		}


	} while (menuContinuar("\nDesea ingresar otro pasajero?") == 1);

	//c) cuánto sale el viaje total sin descuento.
	totalViaje = contadorPasajero * PRECIO;

	// faltan hacer la validación de informar si corresponde o no.

	//a) La cantidad de personas con estado "viudo" de más de 60 años.
	if(contadorViudoMayorA60 != 0){
		printf("\nLa cantidad de viudos mayores a 60 es: %d", contadorViudoMayorA60);
	}else{
		puts("No hay viudos mayores a 60.");
	}

	//b) el número de cliente y edad de la mujer soltera más joven.
	if(flagMSMasJoven == 1){
		printf("\nLa cliente %d es la mujer soltera más joven con %d años.", MujerSolteraMasJovenID, MujerSolteraMasJoven);
	}else{
		puts("No hay mujeres solteras.");

	}
	//c) cuánto sale el viaje total sin descuento.
	printf("\nEl viaje total sin descuenta sale: %d", totalViaje);

	//d) el precio final tiene un descuento del 25%
	if (contadorMayorA60 > (contadorPasajero/2)) {
		totalViajeConDescuento = totalViaje - (totalViaje*DESCUENTO/100);
		printf("\nEl viaje total con descuenta sale: %d", totalViajeConDescuento);
	}else{
		puts("No corresponde descuento.");
	}

	return EXIT_SUCCESS;
}

