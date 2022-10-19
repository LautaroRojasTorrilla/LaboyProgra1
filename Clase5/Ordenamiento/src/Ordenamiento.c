/*
 ============================================================================
 Name        : Ordenamiento.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 5

int main(void) {
	int i;
	int j;
	int vec[]={8,3,5,4,9};
	int aux;

	for(i = 0; i < CANTIDAD - 1; i++ ){
		for(j = i+1; j < CANTIDAD; j++){
			if(vec[i] > vec[j])
			{
				aux = vec[i];
				vec[i] = vec [j];
				vec [j] = aux;
			}
		}
	}


	return EXIT_SUCCESS;
}
