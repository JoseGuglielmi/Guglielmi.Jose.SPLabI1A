/*
 ============================================================================
 Name        : ParcialLABO2.c
 Author      : Matias Corta
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "movies.h"
#include "controller.h"

int main(void) {
	setbuf(stdout, NULL);
		int opcion;
		srand(time(NULL));
		LinkedList* lista = ll_newLinkedList();
		LinkedList* filter = NULL;
		do{
			switch(menu()){

			case 1:
				cargarArchivo(lista);
				break;
			case 2:
				if(ll_len(lista) > 0)
				{
					printMovies(lista);
				}
						break;
			case 3:
				if(ll_len(lista) > 0)
				{
					controller_mapRating(lista);
					printMovies(lista);
				}
						break;
			case 4:
				if(ll_len(lista) > 0)
				{
					controller_mapGenero(lista);
					printMovies(lista);
				}
						break;
			case 5:
				if(ll_len(lista) > 0)
				{
					controller_filtrarGenero(lista, filter);
				}

						break;
			case 6:
				if(ll_len(lista) > 0)
				{
					controller_sort(lista);
					printMovies(lista);
				}
						break;
			case 7:
				if(ll_len(lista) > 0)
				{
					controller_saveAsText("sort.csv", lista);
				}
						break;


			case 8:
				opcion = 8;
						break;

			}

		}while(opcion != 8);
	return EXIT_SUCCESS;
}
