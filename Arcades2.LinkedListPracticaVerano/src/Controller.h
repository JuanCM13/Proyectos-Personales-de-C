/*
 * Controller.h
 *
 *  Created on: 3 mar 2022
 *      Author: caand
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#define TAMRUTA 100

#include "Parser.h"

int controller_LoadArcadesData(LinkedList* lista);
int controller_LoadSoundData(LinkedList* lista);
int controller_PrintArcades(LinkedList* listaArcades , LinkedList* listaSonido);
int controllerGenerateNewArcade(LinkedList* listaArcades);
int Controller_ModArcade(LinkedList* pArcadeList , LinkedList* pSoundList);
int Controller_DeleteArcade(LinkedList* pArcadeList , LinkedList* pSoundList);
int Controller_SortArcades(LinkedList* pArcadeList , LinkedList* pSoundList);
int Controller_GamesListAtTheMoment(LinkedList* pArcadeList , LinkedList* pSoundList);
int Controller_SaveAsText(LinkedList* listaAguardar);
int Controller_MultiplayerGamesList(LinkedList* pArcadeList , LinkedList* pSoundList);
int Controller_UpdateArcadeCoins(LinkedList* pArcadeList , LinkedList* pSoundList);



#endif /* CONTROLLER_H_ */
