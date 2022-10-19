/*
 ============================================================================
 Name        : 2.c
 Author      : Rojas Torrilla Lautaro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 https://www.onlinegdb.com/cAeBcW4rZ
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define SALIR 7

//Nacionalidades
#define EEUU 11
#define CHINA 22
#define OTRO 33

//tipos de producto
#define IPHONE 44
#define MAC 55
#define IPAD 66
#define ACCESORIOS 77

#define CANT_PRODUCTOS 2

typedef struct {
	int idProducto;
	char descripcion[1000];
	int nacionalidad;
	int tipo;
	float precio;
	int isEmpty;
} eProducto;

int opcionesMenu(eProducto productos[], int len);
int inicializarProductos( eProducto productos[], int len );
int lugaresDisponibles( eProducto productos[], int len );
int buscarPosicionLibre( eProducto productos[], int len );
eProducto cargarProducto(eProducto productos[], int len);
static int genID(void);

int main(void) {
	setbuf(stdout, NULL);

	int menu;
	eProducto productos[CANT_PRODUCTOS];
	inicializarProductos( productos, CANT_PRODUCTOS );

	do {
	        menu = opcionesMenu( productos, CANT_PRODUCTOS );
	        switch( menu ) {
	            case 1:
	            	if((AgregarProducto(productos, CANT_PRODUCTOS)==0)) {
						printf("Carga exitosa\n");
					} else {
						printf("Error\n");
					}
	                break;
	            case 2:

	                break;
	            case 3:
	                break;
	            case 4:
	            	mostrarTodosLosProductos(productos, CANT_PRODUCTOS);
	                break;
	            case 5:
	                break;
	            case 6:
					break;
	            case 7:
	            	printf("\nHasta pronto !");
					break;
	        }
	    } while( menu != SALIR );

	return EXIT_SUCCESS;
}

int opcionesMenu(eProducto productos[], int len) {
    int menu;
    int cantLugaresLibres = lugaresDisponibles( productos, len );
    printf("\n");
    printf("\n1) Alta producto - Lugares libres: %d", cantLugaresLibres);
    printf("\n2) Baja producto");
    printf("\n3) Modificacion producto");
    printf("\n4) Listado productos");
    printf("\n5) Listado ordenado por precio");
    printf("\n6) Listado ordenado por descripcion");
    printf("\n7) Salir.\n");
    printf("\nSeleccionar una opcion <1-7>: ");
    scanf( "%d" , &menu );
    printf("\n");
    return menu;
}

int inicializarProductos( eProducto productos[], int len ) {
    int salida = -1;
    if ( productos != NULL && len > 0 ) {
		for( int i = 0 ; i < len ; i++ ) {
			productos[i].isEmpty = TRUE;
		}
		salida = 0;
    }
    return salida;
};

int lugaresDisponibles( eProducto productos[], int len ) {
    int lugaresDisponibles = 0;
    for( int i = 0 ; i < len ; i++ ) {
		if( productos[i].isEmpty == TRUE ) {
			lugaresDisponibles++;
		}
	}
    return lugaresDisponibles;
}

int buscarPosicionLibre( eProducto productos[], int len ) {
    int posicion = -1;
    if ( productos != NULL && len > 0 ) {
		for( int i = 0 ; i < len ; i++ ) {
			if( productos[i].isEmpty == TRUE ) {
				posicion = i;
				break;
			}
		}
    }

    return posicion;
}

int AgregarProducto(eProducto productos[], int len)
{
	int salida = -1;
	int index;

	index = buscarPosicionLibre(productos, len);

	if(productos != NULL && len > 0)
	{
		if ( index != -1 ) {

			//pedir datos
			printf("Ingrese la descripcion del producto: ");
			fflush(stdin);

			fgets(productos[index].descripcion, sizeof(productos[index].descripcion), stdin);
			productos[index].descripcion[strlen(productos[index].descripcion)-1] = '\0';

			printf("Ingrese la nacionalidad <EEUU(11)-CHINA(22)-OTRO(33)>: ");
			scanf("%d", &productos[index].nacionalidad);

			printf("Ingrese tipo del producto: ");
			scanf("%d", &productos[index].tipo);

			printf("Ingrese precio del producto: ");
			scanf("%f", &productos[index].precio);

			(*productos).idProducto = genID();

			productos->isEmpty = FALSE;
			salida = 0;
		}
		else
		{
			salida = -2;
		}
	}
    return salida;
}



void eProducto_printOne(eProducto producto) {

	printf("%d %s %d %d %.2f", producto.idProducto, producto.descripcion, producto.nacionalidad, producto.tipo, producto.precio );

}

int mostrarTodosLosProductos(eProducto productos[], int len) {
	int retorno = 0;
	int i;

	if (productos != NULL) {
		for (i = 0; i < len; i++) {
			eProducto_printOne(productos[i]);
		}
	} else {
		retorno = -1;
	}

	return retorno;
}

static int genID(void)
{
	static int contador = 1000;

	return contador++;
}

/*
int ePassenger_searchIndexById(ePassenger arrayPassenger[], int len, int id) {
	int retorno = 0;
	int flag = 0;
	int i;
	int buscarID;

	if (arrayPassenger != NULL) {
		if (len) {
			//ESTA OK

			//MUESTRO TODOS - Le muestro al usuario todos los dados de alta para que elija cual ID dar de baja
			ePassenger_printAll(arrayPassenger, len, OCUPADO);

			//PEDIR UN ID

			buscarID = id;

			for (i = 0; i < len; i++) {
				if (arrayPassenger[i].isEmpty == FALSE) {
					if (arrayPassenger[i].id == buscarID) {
						flag = 1;
						retorno = i; //retorno index del ID que estoy buscando
						break;
					}
				}
			}

			if (flag == 0) {
				retorno = -2;
			}
		} else {
			retorno = -1;
		}
	} else {
		retorno = -1;
	}

	return retorno;
}
*/

