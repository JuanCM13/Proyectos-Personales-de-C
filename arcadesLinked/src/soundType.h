/*
 * soundType.h
 *
 *  Created on: 2 dic 2021
 *      Author: caand
 */

#ifndef SOUNDTYPE_H_
#define SOUNDTYPE_H_

#define TIPOSONIDO 50

#include "input.h"

typedef struct
{
	int soundId;
	char soundType[TIPOSONIDO];

}eSoundType;

int getSoundId(eSoundType* this , int* soundId);
int getSoundType(eSoundType* this , char* soundType);

int findIdSound(LinkedList* listaSonido , int idAencontrar);

eSoundType* newSoundParameters(int id, char* sonido);

#endif /* SOUNDTYPE_H_ */
