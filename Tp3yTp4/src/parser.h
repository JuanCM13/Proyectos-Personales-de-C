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

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

//------------------------------------------------
//AGREGADAS POR MI

int parserCounter(FILE* pFile , int* contador);

#endif /* PARSER_H_ */
