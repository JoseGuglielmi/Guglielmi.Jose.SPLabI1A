/*
 * controller.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Matias
 */
#include "controller.h"


int controller_saveAsText(char *path, LinkedList *lista)
{
	int todoOk = 0;
	eMovies *movie;
	if (path != NULL && lista != NULL)
	{
		FILE *data = fopen(path, "a");
		if (data == NULL)
		{
			todoOk = 0;
			printf("error al abrir el archivo\n");
		}
		else if (ll_len(lista) > 0)
		{
			for (int i = 0; i < ll_len(lista); i++)
			{
				movie = (eMovies*)ll_get(lista, i);
				fprintf(data, "%d,%s,%s,%f\n", movie->id, movie->nombre, movie->genero, movie->rating);
			}
			todoOk = 1;
			fclose(data);
		}
	}
	return todoOk;
}
/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *lista)
{
	int todoOk = 0;
	eMovies* movie;

	if (path != NULL && lista != NULL)
	{
		FILE *data = fopen(path, "ab");
		int cant;
		if (data == NULL)
		{
			todoOk = 0;
			printf("\nerror al abrir el archivo\n");
		}

		if (ll_len(lista) > 0)
		{
			for (int i = 0; i < ll_len(lista); i++)
			{
				movie = (eMovies *)ll_get(lista, i);
				cant = fwrite(movie, sizeof(eMovies), 1, data);
				if (cant != 1)
				{
					break;
				}
			}
			todoOk = 1;
			fclose(data);
		}
	}
	return todoOk;
}


int controller_mapRating(LinkedList* lista){
int todoOk = 0;


	if(lista != NULL){
		lista= ll_map(lista, asignarRating);
		todoOk = 1;
	}
return todoOk;
}


int controller_mapGenero(LinkedList* lista){
	int todoOk = 0;

	if(lista != NULL){
		lista= ll_map(lista, asignarGenero);
		todoOk = 1;
	}
return todoOk;
}



int controller_filtrarGenero(LinkedList* lista, LinkedList* filter){
int todoOk = 0;
int opcion;

	if(lista != NULL){

do{
	switch(menuFiltrarGenero()){

		case 1:
			filter = ll_filter(lista, eMovies_filterDrama);
			//controller_saveAsText("filterDrama.csv", filter);
			break;
		case 2:
			filter = ll_filter(lista, eMovies_filterComedy);
			//controller_saveAsText("filterComedy.csv", filter);
					break;
		case 3:
			filter = ll_filter(lista, eMovies_filterAccion);
			//controller_saveAsText("filterAccion.csv", filter);
					break;
		case 4:
			filter = ll_filter(lista, eMovies_filterTerror);
			//controller_saveAsText("filterTerror.csv", filter);
					break;
		case 5:
			opcion = 12;
					break;
	}
	printMovies(filter);
	todoOk = 1;
}while(opcion != 12);

}
return todoOk;
}

int controller_sort(LinkedList* lista){
int todoOk = 0;

	if(lista != NULL){
		ll_sort(lista, eMovies_sortGenero, 1);
		ll_sort(lista,eMovies_sortRating, 1);
		todoOk = 1;

	}

return todoOk;
}



