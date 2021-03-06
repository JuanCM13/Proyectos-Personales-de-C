/*
 * Flights.h
 *
 *  Created on: 15 mar 2022
 *      Author: caand
 */

#ifndef FLIGHTS_H_
#define FLIGHTS_H_

#include "input.h"
#include "nombres.h"

#define TAMFECHA 11
#define TAMDESTINO 100
typedef struct
{
	int flightId;
	int planeId;
	int pilotId;
	char flightDate[TAMFECHA];
	char flightDestiny[TAMDESTINO];
	int passengerCount;
	int despityTime;
	int arriveTime;

}eFlight;

//---------------------------------------------------------------------------------------------------------------------------------

//creadores de estructura en memoria dinamica
eFlight* newFlight();
eFlight* newFlight_Parameters(char*  , char* , char* , char* , char* , char* , char* , char* );
eFlight* generateNewFlight(int  , int );



//getters
int getFlightId(eFlight* this , int* flightId);
int getPlaneId(eFlight* this , int* planeId);
int getPilotIdFromFlight(eFlight* this , int* pilotId);
int getFlightDate(eFlight* this , char* date);
int getFlightDestiny(eFlight* this , char* dastiny);
int getPassengersCount(eFlight* this , int* passengers);
int getDepertyTime(eFlight* this , int* depertyTime);
int getArriveTime(eFlight* this , int* arriveTime);


//setters
int setFlightId(eFlight* this , int flightId);
int setPlaneId(eFlight* this , int planeId);
int setPilotIdFromFlight(eFlight* this , int pilotId);
int setFlightDate(eFlight* this , char* date);
int setFlightDestiny(eFlight* this , char* destiny);
int setPassengersCount(eFlight* this , int passengers);
int setDepartyTime(eFlight* this , int deperty);
int setArriveTime(eFlight* this , int arrive);


int countPassengersOrChinaPassengers(LinkedList*  , int );
int filtShortFlights(void* );
int filtChinaFlights(void* );
int filtExcludeAlexLifeson(void* );
int sortListByFlightId(void*  , void* );
int getLastFlightId(LinkedList* pArrayFlights);


//---------------------------------------------------------------------------------------------------------------------------------

#endif /* FLIGHTS_H_ */
