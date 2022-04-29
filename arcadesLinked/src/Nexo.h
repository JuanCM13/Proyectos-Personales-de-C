/*
 * Nexo.h
 *
 *  Created on: 3 dic 2021
 *      Author: caand
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "arcade.h"
#include "soundType.h"
#include "input.h"


int imprimirArcades(LinkedList* listaArcades , LinkedList* listaSonido);
int mostrarArcade(eArcade* arcade , eSoundType* sonido);


int modificarArcade(LinkedList* listaArcades , LinkedList* listaSonido);
int bajaArcade(LinkedList* listaArcades , LinkedList* listaSonido);

#endif /* NEXO_H_ */
