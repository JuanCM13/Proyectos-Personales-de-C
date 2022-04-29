/*
 * Pilotos.h
 *
 *  Created on: 6 dic 2021
 *      Author: caand
 */

#ifndef PILOTOS_H_
#define PILOTOS_H_

#include "nombres.h"

#define TAMPILOTOS 65

typedef struct
{

	int idPiloto;
	char nombrePiloto[TAMPILOTOS];

}ePiloto;


ePiloto* newPilot(void);
ePiloto* newPilot_parameters(char* idPiloto, char* piloto);


//GETTERS
int getIdPilot(ePiloto* this , int* idPiloto);
int getPilotName(ePiloto* this , char* nombrePiloto);


//SETTERS
int setIdPilot(ePiloto* this , int idPiloto);
int setPilotName(ePiloto* this , char* nombrePiloto);


ePiloto* findPilotId(LinkedList* this , int idPiloto);



#endif /* PILOTOS_H_ */
