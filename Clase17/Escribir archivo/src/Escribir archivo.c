/*
 ============================================================================
 Name        : Escribir.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 https://www.onlinegdb.com/cDyUd_IZj
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nombre[10];
	int edad;
}a;

int main(void) {
	setbuf(stdout,NULL);

	FILE *bin;

	a pers;

	bin=fopen("bin.dat","wb");

	if (bin == NULL)
	{
		printf("el archivo no pudo ser abierto");
	}
	else
	{
		printf("\n Ingrese el nombre: ");
		scanf("%[^\n]", pers.nombre);

		printf("Ingrese la edad: ");
		scanf("%d",&pers.edad);

		fflush(stdin);
		fwrite(&pers,sizeof(pers),1,bin);
		fclose(bin);
	}

	return EXIT_SUCCESS;
}
