/*
 * Arcades.h
 *
 *  Created on: 15 feb 2022
 *      Author: caand
 */

#ifndef ARCADES_H_
#define ARCADES_H_

#include "input.h"
#include "nombres.h"

#define TAMNACIONALIDAD 60
#define TAMSALON 100
#define TAMJUEGO 64

typedef struct
{
	int idArcade;
	char nacionalidadArcade[TAMNACIONALIDAD];
	int tipoSonido;
	int cantidadJugadores;
	int capacidadMaximaFichasM;
	char nombreSalon[TAMSALON];
	char nombreJuego[TAMJUEGO];
}eArcade;

int imprimirMenu(int* opcion);

eArcade* new_Arcade(void);
eArcade* newArcade_Parameters(char* ,char* ,char* , char* , char* , char* , char*);
eArcade* GenerateNewArcade(int* counter , int* ret);

//getters
int getArcadeId(eArcade* this , int* id);
int getNacionalidadArcade(eArcade* this , char* nacArcade);
int getArcadeSound(eArcade* this , int* tipoSonido);
int getArcadeCantJugadores(eArcade* this , int* cantJugadores);
int getArcadeCantFichas(eArcade* this , int* cantFichas);
int getArcadeNombre(eArcade* this , char* nombreJuego);
int getArcadeSalon(eArcade* this , char* nombreSalon);

//setters
int setArcadeId(eArcade* this , int id);
int setArcadeNacionalidad(eArcade* this , char* nacionalidad);
int setArcadeSonido(eArcade* this , int tipoSonido);
int setArcadeJugadores(eArcade* this , int cantJugadores);
int setArcadeFichas(eArcade* this , int cantFichas);
int setArcadeNombreJuego(eArcade* this , char* nombreJuego);
int setArcadeNombreSalon(eArcade* this , char* nombreSalon);


int findArcadeById(LinkedList* listaArcades , int idToFind);
int modifyArcade(LinkedList* listaArcades , int indexToModify);
int deleteArcade(LinkedList* listaArcades , int indexToDeletes);
int sortLinkedList(void* pElementUno , void* pElementDos);

LinkedList* generateGamesList(LinkedList* listaArcades);
int isMultiplayer(void* elemento);
int functionModArcadeCoins(void* pElement);


#endif /* ARCADES_H_ */
