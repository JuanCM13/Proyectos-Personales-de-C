/*
 * Parser.h
 *
 *  Created on: 16 mar 2022
 *      Author: caand
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "Nexo.h"
#include "LinkedList.h"

//-----------------------------------------------

int ParserFlightData(LinkedList* , FILE*);
int validateFlightData(char* ,char* ,char* ,char* ,char* ,char* ,char* ,char* );

int ParserPilotData(LinkedList* , FILE*);
int validatePilotData(char* , char* );


//-----------------------------------------------
#endif /* PARSER_H_ */
