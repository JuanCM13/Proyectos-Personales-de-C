/*
 * Flight.h
 *
 *  Created on: 2 ene 2022
 *      Author: caand
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_

#include "input.h"
#include "nombres.h"

#define TAMDATE 11
#define TAMDESTINY 60


typedef struct
{
	int idFly;
	int idFlight;
	int idPilot;
	char date[TAMDATE];
	char destiny[TAMDESTINY];
	int passengersCant;
	int departureTime;
	int arriveTime;
}eFlight;


eFlight* newFlight(void);
eFlight* newFlight_parameters(char* , char* , char* , char* , char* , char* , char* , char* );


//setters
int setFlightId(eFlight*  , int );
int setFlyId(eFlight*  , int );
int setPilotId(eFlight*  , int );
int setDateId(eFlight*  , char[] );
int setDestiny(eFlight*  , char[] );
int setPassengersCant(eFlight*  , int );
int setDepartureTime(eFlight*  , int );
int setArriveTime(eFlight* , int arrive);

//setters
int getFlightId(eFlight*  , int* );
int getFlyId(eFlight*  , int* );
int getPilotId(eFlight*  , int* );
int getDate(eFlight*  , char[] );
int getDestiny(eFlight*  , char[] );
int getPassengersCant(eFlight*  , int* );
int getdepartureTime(eFlight*  , int* );
int getArriveTime(eFlight*  , int* );


int passengersCounter(void* );
int passengersToChina(void* pElement);
int shortFlights(void* pElement);
int chinaFlights(void* pElement);
int excludeAlexLifesonFlights(void* pElement);


#endif /* FLIGHT_H_ */
