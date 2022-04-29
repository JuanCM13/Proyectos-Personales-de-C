/*
 * Pilots.h
 *
 *  Created on: 2 ene 2022
 *      Author: caand
 */

#ifndef PILOTS_H_
#define PILOTS_H_

#include "input.h"
#include "nombres.h"

#define TAMNAME 60

typedef struct
{
	int pilotId;
	char pilotName[TAMNAME];
}ePilot;

ePilot* newPilot(void);
ePilot* newPilot_parameters(char* , char* );


//setters
int setIdFromPilot(ePilot* , int );
int setPilotName(ePilot* , char* );


//getters
int getIdFromPilot(ePilot* , int* );
int getPilotName(ePilot* , char* );


ePilot* findPilotById(LinkedList* , int );


#endif /* PILOTS_H_ */
