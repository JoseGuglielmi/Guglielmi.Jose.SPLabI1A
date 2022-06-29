
#include <stdio.h>
#include <stdlib.h>
#include "movies.h"
#include "controller.h"

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	srand(time(NULL));
	LinkedList *lista = ll_newLinkedList();
	LinkedList *filter = NULL;

	int flagCarga = 0;
	int flagRarting = 0;
	int flagGenero = 0;
	int flagOrdenar = 0;

	do
	{
		switch (menu())
		{

		case 1:
			if (cargarArchivo(lista))
			{
				flagCarga = 1;
			}
			break;
		case 2:
			if (ll_len(lista) > 0 && flagCarga)
			{
				printMovies(lista);
			}
			else
			{
				printf("No hay nada en la lista, carge la lista\n");
			}
			break;
		case 3:
			if (ll_len(lista) > 0 && flagCarga)
			{
				if (controller_mapRating(lista))
				{
					printf("cargados los rating con exito\n");
					flagRarting = 1;
				}
				else
				{
					printf("Error al cargar el rating\n");
				}
			}
			else
			{
				printf("No hay peliculas, agrege peliculas\n");
			}
			break;
		case 4:
			if (ll_len(lista) > 0)
			{
				if (flagRarting)
				{
					if (flagCarga)
					{
						if (controller_mapGenero(lista))
						{
							flagGenero = 1;
							printf("asignados los generos con exito\n");
						}
					}
					else
					{
						printf("Carga un archivo antes de ingresar a esta opcion\n");
					}
				}
				else
				{
					printf("Agrege rating antes de usar esta opcion\n");
				}
			}
			else
			{
				printf("No hay peliculas, agrege peliculas antes de usar esta opcion\n");
			}
			break;
		case 5:
			if (ll_len(lista) > 0)
			{
				if (flagRarting)
				{
					if (flagCarga)
					{
						if (flagGenero)
						{
							controller_filtrarGenero(lista, filter);
						}
						else
						{
							printf("asigne generos antes de usar esta opcion\n");
						}
					}
					else
					{
						printf("Carga un archivo antes de ingresar a esta opcion\n");
					}
				}
				else
				{
					printf("asigne rating antes de usar esta opcion\n");
				}
			}
			else
			{
				printf("No hay peliculas, agrege peliculas antes de usar esta opcion\n");
			}

			break;
		case 6:
			if (ll_len(lista) > 0)
			{
				if (flagRarting)
				{
					if (flagCarga)
					{
						if (flagGenero)
						{
							if (controller_sort(lista))
							{
								flagOrdenar = 1;
								printf("Peliculas ordenadas con exito\n");
							}
						}
						else
						{
							printf("asigne generos antes de usar esta opcion\n");
						}
					}
					else
					{
						printf("Carga un archivo antes de ingresar a esta opcion\n");
					}
				}
				else
				{
					printf("asigne rating antes de usar esta opcion\n");
				}
			}
			else
			{
				printf("No hay peliculas, agrege peliculas antes de usar esta opcion\n");
			}

			break;
		case 7:
			if (ll_len(lista) > 0)
			{
				if (flagRarting)
				{
					if (flagCarga)
					{
						if (flagGenero)
						{
							if (flagOrdenar)
							{
								if (controller_saveAsText("ordenado.csv", lista))
								{
									flagOrdenar = 1;
									printf("se a guardado con exito con el nombre: ordenado.csv\n");
								}
							}else{
								printf("ordene las peliculas antes de usar esta opcion\n");
							}
						}
						else
						{
							printf("asigne generos antes de usar esta opcion\n");
						}
					}
					else
					{
						printf("Carga un archivo antes de ingresar a esta opcion\n");
					}
				}
				else
				{
					printf("asigne rating antes de usar esta opcion\n");
				}
			}
			else
			{
				printf("No hay peliculas, agrege peliculas antes de usar esta opcion\n");
			}

			break;

		case 8:
			opcion = 8;
			break;
		}

	} while (opcion != 8);
	return EXIT_SUCCESS;
}
