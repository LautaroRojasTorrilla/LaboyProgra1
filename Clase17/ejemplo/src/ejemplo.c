/*
 ============================================================================
 Name        : ejemplo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout,NULL);

	FILE *parch;

	char nombre[20];

	printf("\nIngrese el nombre y ruta del archivo que desea abrir: ");
	scanf("%[^\n]", nombre);
	//gets(nombre);

	if((parch=fopen( nombre ,"rb"))==NULL)
	{
		if((parch=fopen( nombre ,"wb"))==NULL)
		{
			printf("\nEl archivo %s no puede ser abierto",nombre);
			exit (1);
		}
		fclose(parch);
	}

	return EXIT_SUCCESS;
}

/*
 	FILE *pArch;

	pArch = fopen("banco.dat", "rb"); //generalmente los binarios son .dat o .bin

	if(pArch == NULL)
	{
		printf("\nEl archivo no puede ser abierto");
	}
	else
	{
		// tiene que estar dentro del proyecto, no en src.
		printf("\nEl archivo se abrio correctamente");
	}

	//se cierra cuando termina el programa.
	fclose(pArch);

 */

/*
 	FILE *parch;

	//Se abre en modo lectura
	if((parch=fopen("banco.dat","rb"))==NULL)
	{
		//Si el modo anterior dio error el archivo
		if((parch=fopen("banco.dat","wb"))==NULL)
		{
			printf("\nEl archivo no puede ser abierto");
		}

		//no existe, por lo tanto se crea
		fclose(parch);
	}

 */
