/*
 * nexo.h
 *
 *  Created on: 26 nov 2021
 *      Author: caand
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "input.h"
#include "eEditoriales.h"
#include "eLibros.h"

int imprimirMenu(int* opcion);
int imprimirLibros(LinkedList* listaLibros , LinkedList* listaEditoriales);
int imprimirUnLibro(eLibro* this1 , eEditorial* this2);


#endif /* NEXO_H_ */
