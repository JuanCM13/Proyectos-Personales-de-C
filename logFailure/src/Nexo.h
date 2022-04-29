/*
 * Nexo.h
 *
 *  Created on: 19 dic 2021
 *      Author: caand
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "Logs.h"
#include "Services.h"

int showMedSeverityErrors(LinkedList* midRiskLosgs , LinkedList* services);
int printfServiceError(eLogEntry* logData , eService* serviceData);
int findServiceWithMoreErrors(LinkedList* logsList , LinkedList* serviceList , char* serviceName);

#endif /* NEXO_H_ */
