#include "movies.h"
#include "parser.h"
#include "library.h"
#include "LinkedList.h"
#include "controller.h"

int menu()
{
	int opcion;
	printf("\n   ***Menu***\n\n");
	printf("1) Cargar archivo\n");
	printf("2) Imprimir lista \n");
	printf("3) Asignar rating\n");
	printf("4) Asignar género\n");
	printf("5) Filtrar por género\n");
	printf("6) Ordenar películas\n");
	printf("7) Guardar películas\n");
	printf("8) Salir\n\n");

	validarInt("Ingrese la opcion que desea elegir: ", "Error.Ingrese la opcion que desea elegir: ", &opcion, 0, 8);

	return opcion;
}

int cargarArchivo(LinkedList *lista)
{
	int todoOk;
	char archivo[30];

	if (lista != NULL)
	{

		printf("\nIngrese el nombre del archivo que desea cargar Ejemplo movies.csv: ");
		fflush(stdin);
		fgets(archivo, 30, stdin);
		limpiarBarraN(archivo);

		if (archivo > 0)
		{
			FILE *data = fopen(archivo, "r");

			if (data == NULL)
			{
				todoOk = 0;
				printf("error al abrir el archivo\n");
			}
			else
			{
				// Si esta vacio copia lo del archivo a la lista
				if (ll_len(lista) == 0)
				{
					todoOk = parser_PassengerFromText(data, lista);
					// si tiene datos, hacemos el backUp
					printf("Cargado\n");
				}
				else
				{
					if (!controller_saveAsText("backUp.csv", lista))
					{
						printf("Los datos fueron cargados, pero no se pudo hacer el backUp");
						ll_clear(lista);
						todoOk = parser_PassengerFromText(data, lista);
					}
					else
					{
						printf("Se han sobre-escrito los datos, se hizo un backUp en \"backUp.csv\"");
						ll_clear(lista);
						todoOk = parser_PassengerFromText(data, lista);
					}
				}
			}
			fclose(data);
		}
	}
	return todoOk;
}

int printMovie(eMovies *this)
{
	int todoOk = 0;

	if (this != NULL)
	{
		printf("%-5d %-30s %-15s  %.1f\n", this->id, this->nombre, this->genero, this->rating);
		todoOk = 1;
	}
	return todoOk;
}

int printMovies(LinkedList *lista)
{
	int todoOk = 0;
	eMovies *movie;
	if (lista != NULL)
	{
		printf("%-5s %-30s %-15s  %-5s\n", "Id", "Nombre", "Genero", "Rating");
		for (int i = 0; i < ll_len(lista); i++)
		{
			movie = ll_get(lista, i);
			printMovie(movie);
			todoOk = 1;
		}
	}
	return todoOk;
}

void eMovies_delete(eMovies *this)
{
	if (this != NULL)
	{
		free(this);
	}
}

eMovies *eMovies_new()
{
	eMovies *new;
	new = (eMovies *)malloc(sizeof(eMovies));
	if (new != NULL)
	{
	}
	else
	{
		eMovies_delete(new);
		new = NULL;
	}
	return new;
}

void *asignarRating(void *a)
{
	int min = 10;
	int max = 100;
	float valor;
	eMovies *movie = NULL;
	movie = (eMovies *)a;
	if (a != NULL && movie->rating == 0)
	{
		valor = (float)(rand() % (max - min + 1) + min) / 10;
		movie->rating = valor;
	}
	return a;
}

void *asignarGenero(void *a)
{
	int min = 1;
	int max = 4;
	int valor;
	eMovies *movie = NULL;
	movie = (eMovies *)a;
	if (a != NULL && strcmp(movie->genero, "sin genero") == 0)
	{
		valor = (rand() % (max - min + 1)) + min;

		if (valor == 1)
		{
			strcpy(movie->genero, "Drama");
		}
		if (valor == 2)
		{
			strcpy(movie->genero, "Comedia");
		}
		if (valor == 3)
		{
			strcpy(movie->genero, "Accion");
		}
		if (valor == 4)
		{
			strcpy(movie->genero, "Terror");
		}
	}

	return a;
}

int eMovies_fComedia(void *a)
{
	int todoOk = 0;
	eMovies *pMovie = NULL;
	if (a != NULL)
	{
		pMovie = (eMovies *)a;
		if (strcmp(pMovie->genero, "Comedia") == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int eMovies_fDrama(void *a)
{
	int todoOk = 0;
	eMovies *pMovie = NULL;
	if (a != NULL)
	{
		pMovie = (eMovies *)a;
		if (strcmp(pMovie->genero, "Drama") == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int eMovies_fTerror(void *a)
{
	int todoOk = 0;
	eMovies *pMovie = NULL;
	if (a != NULL)
	{
		pMovie = (eMovies *)a;
		if (strcmp(pMovie->genero, "Terror") == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int eMovies_fAccion(void *a)
{
	int todoOk = 0;
	eMovies *pMovie = NULL;
	if (a != NULL)
	{
		pMovie = (eMovies *)a;
		if (strcmp(pMovie->genero, "Accion") == 0)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int menuFiltrarPorGenero()
{
	int opcion;

	printf("1)Drama \n");
	printf("2)Comedia\n");
	printf("3)Accion\n");
	printf("4)Terror\n");
	printf("5)SALIR\n");

	validarInt("Ingrese el filtro: ", "Error.Ingrese el filtro: ", &opcion, 0, 5);

	return opcion;
}

int eMovies_sortGenero(void *a, void *b)
{
	if (a != NULL && b != NULL)
	{

		if ((strcmp(((eMovies *)a)->genero, ((eMovies *)b)->genero) > 0))
		{
			return 1;
		}
		if (strcmp(((eMovies *)a)->genero, ((eMovies *)b)->genero) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int eMovies_sortRating(void *a, void *b)
{

	if (a != NULL && b != NULL)
	{

		if ((strcmp(((eMovies *)a)->genero, ((eMovies *)b)->genero) == 0))
		{
			if (((eMovies *)a)->rating > ((eMovies *)b)->rating)
			{
				return 1;
			}
		}

		if ((strcmp(((eMovies *)a)->genero, ((eMovies *)b)->genero) == 0))
		{
			if (((eMovies *)a)->rating < ((eMovies *)b)->rating)
			{
				return -1;
			}
		}
	}
	return 0;
}
