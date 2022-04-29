

#ifndef PARSER_H_
#define PARSER_H_

#include "Nexo.h"

int ParsearDataArcades(LinkedList* listaArcades , FILE* archivo);
int ParsearDataSound(LinkedList* listaSonido , FILE* archivo);


int validarData(char* id, char* nacionalidad, char* tipoSonido, char* cantJugadores , char* cantFichas);
int validarDataSonido(char* id, char* tipoSonido);
int parserDataFromCounter(FILE* path , int* contador);

#endif /* PARSER_H_ */
