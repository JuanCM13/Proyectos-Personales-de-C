  /*
 * parser.h
 *
 *  Created on: 2 nov. 2021
 *      Author: caand
 */

#ifndef PARSER_H_
#define PARSER_H_

#define ESPACIOCONTADORID 100

#include "input.h"
#include "Nexo.h"
#include "nombres.h"


int parser_arcadeFromText(FILE* pFile , LinkedList* pArrayListArcades);
int parser_soundFromText(FILE* pFile , LinkedList* pArrayListSound);

//int parser_editorialsFromText(FILE* pFile , LinkedList* pArrayListEditorials);

int validarParametrosArcade(char* arcadeId , char* arcadeNacionalidad , char* arcadeTipoSonido , char* arcadeCantidadJugadores , char* arcadeCapacidadMaximaFichas);

int parserCounter(FILE* pFile , int* contador);
//int validarParametrosEditorial(char* idEditorial , char* nombreEditorial);

#endif /* PARSER_H_ */
