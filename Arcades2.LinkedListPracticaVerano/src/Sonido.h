/*
 * Sonido.h
 *
 *  Created on: 3 mar 2022
 *      Author: caand
 */

#ifndef SONIDO_H_
#define SONIDO_H_

#include "input.h"
#include "nombres.h"

#define TAMSOUND 10

typedef struct
{
	int soundId;
	char soundType[TAMSOUND];
}eSound;


//-----------------------------------------

eSound* newSound(void);
eSound* newSound_Parameters(char* idSound, char* soundType);


int getSoundId(eSound* this , int* id);
int getSoundType(eSound* this , char* soundType);

int setIdSound(eSound* this , int idSonido);
int setSoundTypeSound(eSound* this , char* tipo);

int findSoundIndexById(LinkedList* listaSonido , int idToFind);


#endif /* SONIDO_H_ */
