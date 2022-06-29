#ifndef CONTROLLER_H_
#define CONTROLLER_H_



#endif /* CONTROLLER_H_ */
#include "movies.h"
#include "LinkedList.h"


int controller_saveAsText(char *path, LinkedList *lista);
int controller_saveAsBinary(char *path, LinkedList *lista);

int controller_filtrarGenero(LinkedList* lista, LinkedList* filter);
int controller_mapDuracion(LinkedList* lista, LinkedList*  map);
int controller_sort(LinkedList* lista);
int controller_mapRating(LinkedList* lista);
int controller_mapGenero(LinkedList* lista);

