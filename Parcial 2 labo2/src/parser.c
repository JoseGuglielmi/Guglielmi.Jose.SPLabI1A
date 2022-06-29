#include "parser.h"



/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE *pFile, LinkedList *lista)
{
	int todoOk = 0;
	int cant;

	if (pFile != NULL && lista != NULL)
	{
		while (!feof(pFile))
		{
			eMovies *movie = eMovies_new();
			if (movie != NULL)
			{
				cant = fscanf(pFile, "%d,%[^,],%[^,],%f\n", &movie->id, movie->nombre, movie->genero, &movie->rating);
				if (cant != 4)
				{
					break;
				}
				ll_add(lista, movie);
			}
			todoOk = 1;
		}
	}
	return todoOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE *pFile, LinkedList *lista)
{
	int todoOk = 0;
	int cant;

	if (pFile != NULL && lista != NULL)
	{
		while (!feof(pFile))
		{
			eMovies * movie = eMovies_new();
			if (movie != NULL)
			{
				cant = fread(movie, sizeof(eMovies), 1, pFile);
				if (cant != 1)
				{
					break;
				}
				ll_add(lista, movie);
			}
			todoOk = 1;
		}
	}
	return todoOk;
}
