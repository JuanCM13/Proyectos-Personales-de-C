/*
 * vuelos.h
 *
 *  Created on: 22 nov 2021
 *      Author: caand
 */

#ifndef VUELOS_H_
#define VUELOS_H_

#define TAMFECHA 11
#define TAMDESTINO 60

#include "input.h"

typedef struct
{
	int idVuelo; //*
	int idAvion; //*
	int idPilotoVuelo; //*
	char fecha[TAMFECHA];
	char destino[TAMDESTINO];
	int cantidadPasajeros; //*
	float horaDespegue; //*
	float horaLlegada; //*

}eVuelo;

//------------------------------------------------------------------------------------------------------------------------

eVuelo* newFlight(void);
eVuelo* flightNewParameters(char* vuelo , char* avion , char* piloto , char* fecha , char* destino , char* canPasajeros , char* horaDespegue , char* horaLlegada);
int flightSetIdAvion(eVuelo* this , int avion);
int flightSetIdAVuelo(eVuelo* this , int vuelo);
int flightSetIdPilotoPorVuelo(eVuelo* this , int piloto);
int flightSetCantidadPasajeros(eVuelo* this , int cantidadPasajeros);
int flightSetHoraDespegue(eVuelo* this , float horaDespegue);
int flightSetHoraLlegada(eVuelo* this , float horaLlegada);
int flightSetFecha(eVuelo* this , char* fecha);
int flightSetDestino(eVuelo* this , char* destino);


//------------------------------------------------------------------------------------------------------------------------

#endif /* VUELOS_H_ */
