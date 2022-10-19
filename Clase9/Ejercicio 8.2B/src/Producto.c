/*
 * Producto.c
 *
 *  Created on: 26 sep. 2022
 *      Author: Rojas Torrilla Lautaro
 */

#include "Producto.h"

static int genID(void);

int eProducto_initArray(eProducto arrayProducto[], int len)
{
	int retorno = -1;
	int i;

	if (arrayProducto != NULL)
	{
		if (len > 0)
		{
			retorno=0;
			for (i = 0; i < len; ++i)
			{
				arrayProducto[i].isEmpty = LIBRE;
			}
		}else{
			retorno = -2;
		}
	}else{
		retorno= -3;
	}
	return retorno;
}

void eProducto_printOne(eProducto prod)
{
	printf("ID: %d\nDescripción: %s\nNacionalidad: %d\nTipo: %d\nPrecio: %.2f\nStatus Empty:%d\n\n"
			,prod.id, prod.descripcion, prod.nacionalidad, prod.tipo, prod.precio, prod.isEmpty);
}

int eProducto_printAll(eProducto arrayProducto[], int len, int state)
{
	int retorno = -1;
	int i;

	if (arrayProducto != NULL)
	{
		if (len > 0)
		{
			retorno = 0;
			//para imprimir todos puedo cambiarle el estado a -1000 por ejemplo. Uno que no coincida.
			for (i = 0; i < len; ++i)
			{
				if (arrayProducto[i].isEmpty == state)
				{
					eProducto_printOne(arrayProducto[i]);
				}
			}
		}else{
			retorno = -2; // es el error del len
		}
	}else{
		retorno= -3; // error de que no es null
	}
	return retorno;
}

eProducto eProducto_LoadOne()
{
	eProducto p;
	eProducto bufferP;


	if(utn_getStringAndNum("Ingrese Descripción:\n", "Error, debe ingresar algo válido.\n", 1, MAX_CODE, bufferP.descripcion)==0)
	{
		strncpy(p.descripcion, bufferP.descripcion, sizeof(p.descripcion));
		printf("Ingresaste: %s\n", p.descripcion);
	}
	else
	{
		puts("Error\n");
	}

	if(utn_getInt("10. EEUU.\n11. CHINA\n12. OTRO.\n\nIngrese Nacionalidad:", "Ingrese un valor entre 10 y 12\n", EEUU, OTRO, 1, &bufferP.nacionalidad)==0)
	{
		p.nacionalidad=bufferP.nacionalidad;
		printf("Es: %d\n", p.nacionalidad);
	}
	else
	{
		puts("Error\n");
	}

	if(utn_getInt("100. IPHONE.\n101. MAC\n102. IPAD.\n103. ACCESORIOS.\n\nIngrese Tipo:", "Ingrese un valor entre 101 y 103\n", IPHONE, ACCESORIOS, 2, &bufferP.tipo)==0)
	{
		p.tipo=bufferP.tipo;
		printf("Es: %d\n", p.tipo);
	}
	else
	{
		puts("Error\n");
	}


	if(utn_getFloat("Ingrese el Precio:\n", "Error. debe ingresar un valor entre 1 y 150000\n", 0, MAX_PRICE, 2, &bufferP.precio)==0)
	{
		p.precio=bufferP.precio;
		printf("Es: %.2f\n", p.precio);
	}
	else
	{
		puts("Error\n");
	}

	return p;
}

int eProducto_SearchEmpty(eProducto arrayProducto[], int len)
{
	int retorno = -1;
	int i;

	if (arrayProducto != NULL)
	{
		if (len > 0)
		{
			retorno = 0;
			for (i = 0; i < len; i++)
			{
				if (arrayProducto[i].isEmpty == LIBRE)
				{
					retorno = i;
					break;
					//No tiene sentido seguir iterando
				}
			}
		}else{
			retorno = -2;
			//mal el tamaño
		}
	}else{
		retorno= -3;
		//vino NULL
	}
	return retorno;
}

int eProducto_SearchOcupado(eProducto arrayProducto[], int len)
{
	int retorno = -1;
	int i;

	if (arrayProducto != NULL)
	{
		if (len > 0)
		{
			retorno = 0;
			for (i = 0; i < len; i++)
			{
				if (arrayProducto[i].isEmpty == OCUPADO)
				{
					retorno = i;
					break;
					//No tiene sentido seguir iterando
				}
			}
		}else{
			retorno = -2;
			//mal el tamaño
		}
	}else{
		retorno= -3;
		//vino NULL
	}
	return retorno;
}

int eProducto_SearchIndexByID(eProducto arrayProducto[], int len, int id)
{
	int retorno = -1;
	int i;

	if (arrayProducto != NULL)
	{
		if (len > 0)
		{
			retorno = 0;
			for (i = 0; i < len; i++)
			{
				if (arrayProducto[i].isEmpty == OCUPADO)
				{
					if (arrayProducto[i].id == id)
					{
						retorno = i;
						break;
					}
				}
			}
		}else{
			retorno = -2;
			//mal el tamaño
		}
	}else{
		retorno= -3;
		//vino NULL
	}
	return retorno;
}

int eProducto_Charge(eProducto arrayProducto[], int len)
{
	int retorno = 0;
	int indexLibre;
	eProducto bufferProducto;

	indexLibre = eProducto_SearchEmpty(arrayProducto, len);

	if (arrayProducto != NULL)
	{
		if (len > 0)
		{
			if (indexLibre > -1)
			{
				//CARGO DATOS NO GENERICOS
				bufferProducto = eProducto_LoadOne();

				//SI ESTA TODO BIEN - LE DOY UN ID UNICO
				bufferProducto.id = genID();
				//CAMBIO ESTADO A OCUPADO
				bufferProducto.isEmpty = OCUPADO;
				//PLUS - PREGUNTAR SI ESTA SEGURO
				//COPIA AUXILIAR EN ARRAY EN POSICION OBTENIDA LIBRE
				arrayProducto[indexLibre] = bufferProducto;
				retorno = indexLibre;
			}else{
				//array lleno
				retorno = -3;
				puts("retorno el -3");
			}
		}else{
			// len mal definido
			retorno = -2;
			puts("retorno el -2");
		}
	}else{
		//array nulo
		retorno= -1;
		puts("retorno el -1");
	}
	return retorno;
}

int eProducto_Discharge(eProducto arrayProducto[], int len)
{
	int retorno = -1;
	int bufferId;

	if (arrayProducto != NULL)
	{
		if (len > 0)
		{
			eProducto_printAll(arrayProducto, len, OCUPADO);
			fflush(stdin);
			utn_getInt("Seleccione el ID que desea dar de baja: ", "Error, debe seleccionar un ID valido: ", 1000, 1010, 2, &bufferId);
			for (int i = 0; i < len; ++i)
			{
				if(bufferId == arrayProducto[i].id)//lo encontró hacer doble validación, que esté ocupado
				{
					arrayProducto[i].isEmpty = BORRADO;
					retorno = 0;
					break;
				}
			}
		}else{
			// len mal definido
			retorno = -2;
			puts("retorno el -2");
		}
	}else{
		//array nulo
		retorno= -1;
		puts("retorno el -1");
	}
	return retorno;
}


int eProducto_Modify(eProducto arrayProducto[], int len)
{
	int retorno = -1;;
	int bufferID;
	int bufferIndex;
	int atributoAModificar;
	eProducto bufferProducto;

	eProducto_printAll(arrayProducto, len, OCUPADO); // lo único que tengo bien de la función

	if(utn_getInt("Ingrese el ID que desa modificar: \n", "Error, ingrese un ID válido. Entre 1000 y 1005: \n",1000, 1005, 2, &bufferID) == 0)
	{
		bufferIndex = eProducto_SearchIndexByID(arrayProducto, len, bufferID);

		if(bufferIndex > -1)
		{
			bufferProducto = arrayProducto[bufferIndex];
			eProducto_printOne(bufferProducto);
		}

		utn_getInt("1. Descripcion.\n2.Nacionalidad.\n3.Tipo\n4.Precio.\n\nIndique el campo a modificar: \n",
				"Error. Elija entre 1 y 4", 1, 4, 2, &atributoAModificar);
		switch (atributoAModificar)
		{
		case 1:
			if(utn_getStringAndNum("Ingrese Descripción:\n", "Error, debe ingresar algo válido.\n", 1, MAX_CODE, bufferProducto.descripcion)==0)
			{
				strncpy(arrayProducto[bufferIndex].descripcion, bufferProducto.descripcion, sizeof(arrayProducto[bufferIndex].descripcion));
				printf("Ingresaste: %s\n", arrayProducto[bufferIndex].descripcion);
			}
			else
			{
				puts("Error\n");
			}
			break;
		case 2:
			if(utn_getInt("10. EEUU.\n11. CHINA\n12. OTRO.\n\nIngrese Nacionalidad:", "Ingrese un valor entre 10 y 12\n", EEUU, OTRO, 1, &bufferProducto.nacionalidad)==0)
			{
				arrayProducto[bufferIndex].nacionalidad=bufferProducto.nacionalidad;
				printf("Es: %d\n", arrayProducto[bufferIndex].nacionalidad);
			}
			else
			{
				puts("Error\n");
			}
			break;
		case 3:
			if(utn_getInt("100. IPHONE.\n101. MAC\n102. IPAD.\n103. ACCESORIOS.\n\nIngrese Tipo:", "Ingrese un valor entre 101 y 103\n", IPHONE, ACCESORIOS, 2, &bufferProducto.tipo)==0)
			{
				arrayProducto[bufferIndex].tipo=bufferProducto.tipo;
				printf("Es: %d\n", arrayProducto[bufferIndex].tipo);
			}
			else
			{
				puts("Error\n");
			}
			break;
		case 4:
			if(utn_getFloat("Ingrese el Precio:\n", "Error. debe ingresar un valor entre 1 y 150000\n", 0, MAX_PRICE, 2, &bufferProducto.precio)==0)
			{
				arrayProducto[bufferIndex].precio=bufferProducto.precio;
				printf("Es: %.2f\n", arrayProducto[bufferIndex].precio);
			}
			else
			{
				puts("Error\n");
			}
			break;
		default:
			break;
		}//final del switch
		retorno = 0;
	}



	return retorno;
}

static int genID(void)
{
	static int contador = 1000;

	return contador++;
}
