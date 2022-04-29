/*
 * locality.h
 *
 *  Created on: 26 dic 2021
 *      Author: caand
 */

#ifndef LOCALITY_H_
#define LOCALITY_H_

#define TAMSTATE 60

#include "input.h"
#include "nombres.h"

typedef struct
{
	int idLocality;
	char state[TAMSTATE];
	int postalCode;
	int locality;
	int isEmpty;

}eLocality;

int loadLoc(eLocality* locArray , int arrayLen , int* locId);
eLocality generateLoc(void);
int getFreeIndexLoc(eLocality* locArray , int arrayLen);
int inityLocList(eLocality* locArray , int arrayLen);
int isThereAnyLoadedLoc(eLocality* locArray , int arrayLen);
int findLocalityByOwnerId(eLocality* locArray , int arrayLen , int idToFind);


#endif /* LOCALITY_H_ */
