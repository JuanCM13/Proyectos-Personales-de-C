/*
 * arcade.h
 *
 *  Created on: 2 dic 2021
 *      Author: caand
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#include "input.h"
#include "nombres.h"

#define TAMNACIONALIDAD 100
#define	TAMSALA 100
#define	TAMJUEGO 63


typedef struct
{
	int idArcade;
	char nacionalidad[TAMNACIONALIDAD];
	int tipoSonido;
	int cantidadJuegadores;
	int capacidadMaximaFichas;
	char nombreSalon[TAMSALA];
	char nombreJuego[TAMJUEGO];

}eArcade;

int imprimirMenu(int* opcion);

eArcade* newArcade(void);
eArcade* newArcade_parameters(char* arcadeId , char* arcadeNacionalidad , char* arcadeTipoSonido , char* arcadeCantidadJugadores , char* arcadeCapacidadMaximaFichas, char* arcadeNombreSalon , char* arcadeNombreJuego);
eArcade* addNewArcade(int *idCounter , int* guia);


int getArcadeId(eArcade* this , int* id);
int getArcadeNacionalidad(eArcade* this , char* nacionalidad);
int getArcadeSound(eArcade* this , int* sound);
int getArcadeCantFichas(eArcade* this , int* fichas);
int getArcadeCantJugadores(eArcade* this , int* cantJugadores);
int getArcadeSala(eArcade* this , char* sala);
int getArcadeNombreJuego(eArcade* this , char* juego);


int setArcadeId(eArcade* this , int id);
int setArcadeNacionalidad(eArcade* this , char* nacionalidad);
int setArcadeSound(eArcade* this , int sound);
int setArcadeCantFichas(eArcade* this , int fichas);
int setArcadeCantJugadores(eArcade* this , int cantJugadores);
int setArcadeSala(eArcade* this , char* sala);
int setArcadeNombreJuego(eArcade* this , char* juego);


int encontrarIndiceId(LinkedList* this , int id);
int mostrarJuegos(LinkedList* this);
LinkedList* crearListaNombresJuegosCargados(LinkedList* listaArcades);

int ordenarArcadesPorNombreAscendente(void* elementoUno , void* elementoDos);
int filtrarArcadesMultijugador(void* elementoUno);
int duplicarFichas(void* elementoUno);


#endif /* ARCADE_H_ */
