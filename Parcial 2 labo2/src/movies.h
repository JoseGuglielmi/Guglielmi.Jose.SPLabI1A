#ifndef MOVIES_H_
#define MOVIES_H_

typedef struct{
	int id;
	char nombre[50];
	char genero[50];
	float rating;

}eMovies;

#endif /* MOVIES_H_ */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "LinkedList.h"

int menu();

/**
 * @brief creo una estructura de pelicula dinamica
 * 
 */
eMovies* eMovies_new();

/**
 * @brief cargo un archivo de texto y lo guardo en una LinkedList
 * 
 * @param lista LinkedList donde guardo las peliculas obtenidas del archivo
 * @return int 0 salio mal, 1 salio bien
 */
int cargarArchivo(LinkedList* lista);

/**
 * @brief imprimo en pantalla la lista de las peliculas
 * 
 * @param lista LinkedList donde guardo las peliculas obtenidas del archivo
 * @return int 0 salio mal, 1 salio bien
 */
int printMovies(LinkedList* lista);

/**
 * @brief 
 * 
 * @param lista imprimo en pantalla una pelicula
 * @return int int 0 salio mal, 1 salio bien
 */
int printMovie(eMovies* this);

/**
 * @brief menu de opciones de filtro de peliculas
 * 
 * @return int 0 salio mal, 1 salio bien
 */
int menuFiltrarPorGenero();

/**
 * @brief asigno un rating a cada pelicula (random)
 * 
 * @param a elemento de la lista (eMovies)
 * @return void* retorno un elemento de la lista con el rating asignado
 */
void* asignarRating(void* a);

/**
 * @brief asigno un genero a cada pelicula (random)
 * 
 * @param a elemento de la lista (eMovies)
 * @return void* retorno un elemento de la lista con el genero asignado
 */
void* asignarGenero(void* a);
int eMovies_fAccion(void* a);
int eMovies_fTerror(void* a);
int eMovies_fDrama(void* a);
int eMovies_fComedia(void* a);
int eMovies_sortGenero(void* a, void* b);
int eMovies_sortRating(void* a, void* b);
