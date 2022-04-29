  /*
 * parser.h
 *
 *  Created on: 2 nov. 2021
 *      Author: caand
 */

#ifndef PARSER_H_
#define PARSER_H_

#define ESPACIOCONTADORID 100

#include "Nexo.h"

int parser_logsFromText(FILE* pFile , LinkedList* pArrayListLogs);
int parser_servicesFromText(FILE* pFile , LinkedList* pArrayListServices);


int controlLogsEntry(char* date , char* time , char* serviceId , char* severity);
int controlServicesEntry(char* id);

#endif /* PARSER_H_ */
