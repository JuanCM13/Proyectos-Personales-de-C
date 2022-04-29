/*
 * ePendrive.h
 *
 *  Created on: 29 nov 2021
 *      Author: caand
 */

#ifndef EPENDRIVE_H_
#define EPENDRIVE_H_

#define TAMMARCA 20
#define TAMMODELO 20

#include <stdlib.h>

typedef struct
{
	int codigo;
	char marca[TAMMARCA];
	char modelo[TAMMODELO];
	int capacidad;

}ePendrive;


#endif /* EPENDRIVE_H_ */
