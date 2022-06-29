#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "movies.h"
#include "LinkedList.h"


int parser_PassengerFromText(FILE *pFile, LinkedList *lista);

int parser_PassengerFromBinary(FILE *pFile, LinkedList *lista);
