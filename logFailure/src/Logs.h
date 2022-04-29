/*
 * Logs.h
 *
 *  Created on: 18 dic 2021
 *      Author: caand
 */

#ifndef LOGS_H_
#define LOGS_H_

#include "input.h"
#include "nombres.h"

#define TAMDATE 11
#define TAMTIME 6
#define TAMMSG 65


typedef struct
{
	char date[TAMDATE];
	char time[TAMTIME];
	int serviceId;
	int severity;
	char msg[TAMMSG];

}eLogEntry;

int printMenu(int* option);

eLogEntry* newLog(void);
eLogEntry* newLog_parameters(char* date, char* time, char* serviceId, char* severity, char* msg);


int getDate(eLogEntry* this , char* auxDate);
int getTime(eLogEntry* this , char* auxTime);
int getServiceId(eLogEntry* this , int* serviceId);
int getSeverity(eLogEntry* this , int* severity);
int getMsg(eLogEntry* this , char* msg);

int setDate(eLogEntry* this , char* date);
int setTime(eLogEntry* this , char* time);
int setServiceId(eLogEntry* this , int serviceId);
int setSeverity(eLogEntry* this , int severity);
int setMsg(eLogEntry* this , char* msg);


int filtByLowRiskError(void* element);
int filtByMidRiskError(void* element);
int filtByHighRiskError(void* element);
int countByServiceId(LinkedList* logsList , int serviceIdRelation);


#endif /* LOGS_H_ */
