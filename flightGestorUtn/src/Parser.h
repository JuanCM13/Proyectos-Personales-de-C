/*
 * Parser.h
 *
 *  Created on: 2 ene 2022
 *      Author: caand
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "Nexo.h"

int parserFlights_fromText(LinkedList* , FILE*);
int parserPilots_fromText(LinkedList* , FILE*);


int controlFlightParameters(char* , char* , char* , char* , char* , char* , char* , char* );
int controlPilotsParameters(char* , char* );



#endif /* PARSER_H_ */
