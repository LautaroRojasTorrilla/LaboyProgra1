/*
 ============================================================================
 Name        : Cadenas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setbuf(stdout,NULL);

	char cadena[20] = "ALBERTO";
	char cadena2[20] = "mariano";
	char buffer[1024];
	int resultado;

	int len;
//
//	printf("Ingrese texto: ");
//	fflush(stdin);

	//scanf("%s", cadena);

	//gets(cadena); // preparada para trabjar con cad. de caracteres tomadas del buffer de entr.
	//fgets(cadena, 200, stdin); // trabaja con archivos. F de FILE, lee cadenas desde un archivo
	//desde donde, hacia dónde y cuántos caracteres.

//	scanf("%[^\n]", buffer);
//
//	while(strlen(buffer)>19)
//	{
//		printf("Ingrese texto: ");
//		fflush(stdin);
//		scanf("%[^\n]", buffer);
//	}
//
//	strcpy(cadena, buffer);
//
//	len = strlen(cadena);//no cuenta el \0
//
//	cadena[len-1] = '\0';
//
//	len = strlen(cadena);
//
//	printf("El largo de la cadena es %d\n", len);
//
//	printf("Ud ingresó: %s\n", cadena);
//	puts(cadena);

//	resultado = strcmp(cadena, cadena2);//=0, >0
//
//	if (resultado < 0) {
//		printf("El nombre: %d está antes", resultado);
//	}
//
//	printf("Ud ingresó: %s\n", cadena);
//
//	//concatena 2 cadenas de caracteres
//	strcat(cadena, cadena2);
//
//	printf("Ud ingresó: %s\n", cadena);


	//strlwr y strupr

	printf("Ud ingresó: %s\n", cadena);

	strlwr(cadena);

	printf("Ud ingresó: %s\n", cadena);

	return EXIT_SUCCESS;
}
