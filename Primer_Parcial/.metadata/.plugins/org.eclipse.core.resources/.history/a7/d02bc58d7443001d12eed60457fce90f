/*
 * Input.c
 *
 *  Created on: 28 sep. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#include "Input.h"


int utn_getInt(char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos, int *pResultado)
{
	int retorno = -1;
	int bufferInt;
	int retorno_getInt;

	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pResultado != NULL && reintentos > 0)
	{
		printf("\n%s",mensaje);
		fflush(stdin);
		retorno_getInt = getInt(&bufferInt);
		do
		{
			if(retorno_getInt == -1 || bufferInt > maximo || bufferInt < minimo)
			{
				printf("\n%s",mensajeError);
				reintentos--;
				printf("\nQuedan %d reintentos.",reintentos);
				printf("\n%s",mensaje);
				fflush(stdin);
				retorno_getInt = getInt(&bufferInt);
			}
			else
			{
				reintentos = 0;
				*pResultado = bufferInt;
				retorno = 0;
			}
		}while(reintentos > 0);
	}
	return retorno;
}

int getInt(int* pNumeroTomado)
{
	int retorno = -1;
	char bufferNum[200];

	if(myGets(bufferNum, sizeof(bufferNum)) == 0 && esNumerica(bufferNum) == 0)
	{
		*pNumeroTomado= atoi(bufferNum);
		retorno = 0;
	}
	return retorno;
}

int myGets(char cadena[], int len)
{
	int retorno = -1;

	if(cadena != NULL && len > 0 && fgets(cadena, len, stdin) == cadena)
	{
		retorno = 0;
	}
	return retorno;
}

float utn_getFloat(char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos, float *pResultado)
{
	int retorno = -1;
	float bufferFloat;
	int retorno_getFloat;

	if(mensaje != NULL && minimo < maximo && mensajeError != NULL && pResultado != NULL && reintentos > 0)
	{
		printf("\n%s",mensaje);
		retorno_getFloat = getFloat(&bufferFloat);
		do
		{
			if(retorno_getFloat == -1 || bufferFloat > maximo || bufferFloat < minimo)
			{
				printf("\n%s",mensajeError);
				retorno_getFloat = getFloat(&bufferFloat);
				reintentos--;
				printf("Quedan %d reintentos.\n",reintentos);
			}
			else
			{
				reintentos = 0;
				*pResultado = bufferFloat;
				retorno = 0;
			}
		}while(reintentos > 0);
	}
	return retorno;
}

float getFloat(float* pFloatTomado)
{
	int retorno = -1;
	char bufferString[200];

	if(myGets(bufferString, sizeof(bufferString)) == 0 && esFloat(bufferString) == 0)
	{
		*pFloatTomado= atof(bufferString);
		retorno = 0;
	}
	return retorno;
}

float esFloat(char cadena[])
{
	int retorno = 0; //favorable
	int i = 0;
	int contadorPuntos = 0;

	if(cadena[0]=='+' || cadena[0]=='-')
				{
					i++;
				}
	while(cadena[i]!='\0' || (cadena[i]>'9' && cadena[i]!='.')) //No hay nada menor a cero en ASCII?
	{
		i++;
		if(cadena[i]=='.')
		{
			contadorPuntos++;
		}
		if(contadorPuntos>1)
		{
			retorno = -1; //error
			puts("Error1 mas de un punto");
			break;
		}
	}
	return retorno;
}

int esNumerica(char cadena[])
{
	int retorno = 0;
	int i;

	if(cadena != NULL)
	{
		i = 0;

		if(cadena[strlen(cadena)-1]=='\n')
		{
			cadena[strlen(cadena)-1]='\0'; //Porque toma el "enter" como �ltimo caracter.
		}
		if(cadena[0]=='-')
		{
			i++; // Para que empiece el while en 2da posici�n a chequear que sean todos n�meros (luego de pasar el signo menos)
		}
		while(cadena[i] != '\0')
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = -1;
				break;
			}
			i++;
		}
	}
	else
	{
		retorno = -1 ;
	}
	return retorno;
}

int utn_getOnlyString(char* mensaje, char* mensajeError, int reintentos,  int len, char* pResultado)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("\n%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 &&	strnlen(bufferString,sizeof(bufferString)) < len)
		{
			strncpy(pResultado,bufferString,len);
			retorno = 0;
			break;
		}
		printf("\n%s",mensajeError);
	}
	return retorno;
}

int getNombre(char* pResultado, int len)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer))==0 &&
    			esNombre(buffer, sizeof(buffer)) &&
				strnlen(buffer,sizeof(buffer))<len)
    	{
    		strncpy(pResultado,buffer,len);
			retorno = 0;
		}
    }
    return retorno;
}

int getString(char* cadena, int len)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(cadena,bufferString,len);
				retorno=0;
			}
		}
	}
	return retorno;
}

int esNombre(char* cadena,int len)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && len > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < len; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && cadena[i] == ' ')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int utn_getStringAndNum(char* mensaje, char* mensajeError, int reintentos,  int len, char* pResultado)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("\n%s",mensaje);
		if(getNombreAndNum(bufferString, sizeof(bufferString)) == 0 &&	strnlen(bufferString,sizeof(bufferString)) < len)
		{
			strncpy(pResultado,bufferString,len);
			retorno = 0;
			break;
		}
		printf("\n%s",mensajeError);
	}
	return retorno;
}

int getNombreAndNum(char* pResultado, int len)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && strnlen(buffer,sizeof(buffer))<len)
    	{
    		strncpy(pResultado,buffer,len);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getChar(char* mensaje, char* mensajeError, int reintentos, char* pResultado)
{
	char bufferString[128];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("\n%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 &&	strnlen(bufferString,sizeof(bufferString)) <= 1)
		{
			strncpy(pResultado,bufferString,1);
			retorno = 0;
			break;
		}
		printf("\n%s",mensajeError);
		printf("\nQuedan %d reintentos.",reintentos);
	}
	return retorno;
}

static int utn_getCharSinReint(char* mensaje, char* mensajeError, char* pResultado)
{
	char bufferString[128];
	int retorno = -1;

	printf("\n%s",mensaje);
	if(getNombre(bufferString,sizeof(bufferString)) == 0 &&	strnlen(bufferString,sizeof(bufferString)) <= 1)
	{
		strncpy(pResultado,bufferString,1);
		retorno = 0;
	}else{
	printf("\n%s",mensajeError);
	}

	return retorno;
}

int menu_confirmation(char mensaje[], char mensajeError[])
{
	int retorno = -1;
	char c;
	char bufferC;

	fflush(stdin);
	while (c != 'S' && c != 'N')
	{
		if(utn_getCharSinReint(mensaje, mensajeError, &bufferC)==0)
		{
			fflush(stdin);
			c=bufferC;
			c = toupper(c);
			//printf("ingresaste: %c\n", c);
		}
		else
		{
			printf("\n%s",mensajeError);
		}
	}

	if (c == 's')
	{
		retorno = 0;
	}

	return retorno;
}

