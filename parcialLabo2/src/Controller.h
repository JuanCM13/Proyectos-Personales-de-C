#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "nexo.h"
#include "parser.h"

#define NOMBREARCHIVOMINOTAURO "Listado_Minotauro.csv"
#define STRING_MAX 200


int controller_loadBooksFromText(LinkedList* pArrayBookList);
int controller_loadEditorialsFromText(LinkedList* pArrayEditorialsList);
int controller_organizeAutors(LinkedList* this);
int controller_printBooks(LinkedList* this1 , LinkedList* this2);
int controller_generateMinotauroList(LinkedList* listaLibros , LinkedList* listaEditoriales);
int controller_saveBookAsText(LinkedList* pListaLibros);

int controllerDescount(LinkedList* listaLibros , LinkedList* listaEditoriales);
int controller_saveDescountListAsText(LinkedList* pListaLibros);
