/*
 * Pilots.h
 *
 *  Created on: 15 mar 2022
 *      Author: caand
 */

#ifndef PILOTS_H_
#define PILOTS_H_

#include "input.h"
#include "nombres.h"

#define TAMNAME 100

typedef struct
{
	int idPilot;
	char pilotName[TAMNAME];

}ePilot;


//---------------------------------------------------------------------------------------------------------------------------------

//creadores de estructura en memoria dinamica

ePilot* newPilot();
ePilot* newPilot_Parameters(char* , char* );


//getters
int getPilotId(ePilot* this , int* pilotId);
int getPilotName(ePilot* this , char* pilotName);


//setters
int setPilotId(ePilot* this , int pilotId);
int setPilotName(ePilot* this , char* pilotName);

int findPilotId(LinkedList*  , int );
int printPilotsList(LinkedList* );


//---------------------------------------------------------------------------------------------------------------------------------


#endif /* PILOTS_H_ */
