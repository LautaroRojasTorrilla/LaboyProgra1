/*
 ============================================================================
 Name        : Ejercicio 4.1
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int factorial (int);

int main(void) {
	setbuf(stdout, NULL);

	int valor, result;

	printf("\nIngrese un numero: ");
	scanf("%d", &valor);

	result = factorial(valor);

	printf("El factorial es: %d", result);

	return EXIT_SUCCESS;
}

//int factorial(int n){
//	int retorno;
//
//	if(n==1)
//	{
//		retorno = 1;
//	}
//	else{
//		retorno = n * factorial(n-1);
//	}
//	return retorno;
//}

int factorial(int n){

	int resultado = 1;

	for (int i = 1; i <= n; ++i) {
		resultado = resultado * i;
	}

	return resultado;
}
