/*
 * eEditoriales.h
 *
 *  Created on: 24 nov 2021
 *      Author: caand
 */

#define TAMNOMBREEDITORIAL 60
#include "input.h"

#ifndef EEDITORIALES_H_
#define EEDITORIALES_H_

typedef struct
{
	int idEditorial;
	char nombre[TAMNOMBREEDITORIAL];
}eEditorial;


eEditorial* newEditorial(void);

eEditorial* newEditorialParameters(char* idEditorial , char* nombreEditorial);

int setIdEditorial(eEditorial* this , int idEditorial);
int setNombreEditorial(eEditorial* this , char* nombreEditorial);


int getIdEditorial(eEditorial* this , int* idEditorial);
int getNombreEditorial(eEditorial* this , char* nombreEditorial);


eEditorial* buscarEditorialPorIdRelacion(LinkedList* this , int idRelacion);

#endif /* EEDITORIALES_H_ */


