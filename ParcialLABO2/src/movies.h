/*
 * movies.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Matias
 */

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
void eMovies_delete(eMovies* this);
eMovies* eMovies_new();
eMovies* eMovies_newParametros(char* id,char* titulo,char* duracion, char* genero);
int eMovies_getGenero(eMovies* this,char* auxChar);
int eMovies_setGenero(eMovies* this,char* auxChar);
int eMovies_getNombre(eMovies* this,char* auxChar);
int eMovies_setNombre(eMovies* this,char* auxChar);
int eMovies_setRating(eMovies* this,int auxInt);
int eMovies_getRating(eMovies* this,int* auxInt);
int eMovies_getId(eMovies* this,int* auxId);
int eMovies_setId(eMovies* this,int auxId);


int eMovies_filterComedy(void* a);
int cargarArchivo(LinkedList* lista);
int printMovies(LinkedList* lista);
int printMovie(eMovies* this);
int menuFiltrarGenero();
void* asignarTiempos(void* a);
int sortMoviesDuracion(void* a, void* b);
int sortMoviesGenero(void* a, void* b);
void* asignarRating(void* a);
void* asignarGenero(void* a);
int eMovies_filterAccion(void* a);
int eMovies_filterTerror(void* a);
int eMovies_filterDrama(void* a);
int eMovies_filterComedy(void* a);
int eMovies_sortGenero(void* a, void* b);
int eMovies_sortRating(void* a, void* b);
