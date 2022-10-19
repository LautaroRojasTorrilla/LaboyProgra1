/*
 ============================================================================
 Name        : Ejercicio 3.5
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void sumar1(void);
void sumar2(int, int);
int sumar3(void);
int sumar4(int, int);

int main(void) {
	setbuf(stdout, NULL);

	int primerNumero = 9;
	int segundoNumero = 11;
	int suma;

	//	sumar1();
	//
	//	sumar2(primerNumero, segundoNumero);
	//	sumar2(15,25);

	suma=sumar4(primerNumero, segundoNumero);

	printf("La suma es: %d\n",suma);

	return EXIT_SUCCESS;
}

void sumar1(void)
{
	int numero1;
	int numero2;

	int suma;

	printf("Ingrese un numero: ");
	scanf("%d",&numero1);
	printf("Ingrese otr numero: ");
	scanf("%d",&numero2);

	suma = numero1 + numero2;

	printf("La suma es: %d\n",suma);

}

void sumar2(int numero1, int numero2)
{
	int suma;

	suma = numero1 + numero2;

	printf("La suma es: %d\n",suma);
}

int sumar3(void)
{
	int numero1;
	int numero2;

	int suma;

	printf("Ingrese un numero: ");
	scanf("%d",&numero1);
	printf("Ingrese otr numero: ");
	scanf("%d",&numero2);

	suma = numero1 + numero2;

	return suma;
}

int sumar4(int numero1, int numero2)
{
	int suma;

	suma = numero1 + numero2;

	return suma;
}
