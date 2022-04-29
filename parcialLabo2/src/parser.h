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
#include "nombres.h"

int parser_bookFromText(FILE* pFile , LinkedList* pArrayListBooks);

int parser_editorialsFromText(FILE* pFile , LinkedList* pArrayListEditorials);

int validarParametrosLibro(char* id , char* titulo , char* autor , char* precio , char*idEditorial);

int validarParametrosEditorial(char* idEditorial , char* nombreEditorial);

#endif /* PARSER_H_ */
