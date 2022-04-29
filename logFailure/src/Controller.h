
#include "parser.h"
#include "FilesManage.h"

#define NOMBREARCHIVOMINOTAURO "Listado_Minotauro.csv"
#define STRING_MAX 200
#define LOGSFILE "log.txt"
#define SERVICEFILE "services.txt"
#define WARNINGSFILE "logsWarningsFile.txt"
#define HIGHRISKERRORSFILE "logsHighRiskErrors.txt"


int controller_loadDataFromText(LinkedList* pArrayListLogs , LinkedList* pArrayListServices);

int controllerEvaluateSeverity(LinkedList* logsList , LinkedList* servicesList);
int controllerStatics(LinkedList* logsList , LinkedList* serviceList);

/*
int controller_loadBooksFromText(LinkedList* pArrayBookList);
int controller_loadEditorialsFromText(LinkedList* pArrayEditorialsList);
int controller_organizeAutors(LinkedList* this);
int controller_printBooks(LinkedList* this1 , LinkedList* this2);
int controller_generateMinotauroList(LinkedList* listaLibros , LinkedList* listaEditoriales);
int controller_saveBookAsText(LinkedList* pListaLibros);

int controllerDescount(LinkedList* listaLibros , LinkedList* listaEditoriales);
int controller_saveDescountListAsText(LinkedList* pListaLibros);*/
