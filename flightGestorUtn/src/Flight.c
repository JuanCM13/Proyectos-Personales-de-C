#include "Flight.h"

eFlight* newFlight(void)
{
	eFlight* aux;

	return aux = (eFlight*) calloc(1, sizeof(eFlight));
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

eFlight* newFlight_parameters(char* flightId, char* flyId, char* pilotId, char* date, char* destiny, char* passengersCant, char* departureTime, char* arriveTime)
{
	eFlight* aux;
	int flightIdAux;
	int flyIdAux;
	int pilotIdAux;
	//char dateAux[TAMDATE];
	//char destinyAux[TAMDESTINY];
	int passengersCantAux;
	int departureTimeAux;
	int arriveTimeAux;

	aux = NULL;

	if(flightId != NULL && flyId != NULL && pilotId != NULL && date != NULL && destiny != NULL && passengersCant != NULL && departureTime != NULL && arriveTime != NULL)
	{
		aux = newFlight();
		if(aux != NULL)
		{
			//conversion
			flightIdAux = atoi(flightId);
			flyIdAux = atoi(flyId);
			pilotIdAux = atoi(pilotId);
			passengersCantAux = atoi(passengersCant);
			departureTimeAux = atoi(departureTime);
			arriveTimeAux = atoi(arriveTime);

			//setters
			setFlightId(aux, flightIdAux);
			setFlyId(aux, flyIdAux);
			setPilotId(aux, pilotIdAux);
			setDateId(aux, date);
			setDestiny(aux, destiny);
			setPassengersCant(aux, passengersCantAux);
			setDepartureTime(aux, departureTimeAux);
			setArriveTime(aux, arriveTimeAux);

		}
	}

	return aux;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  													//setters
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int setFlightId(eFlight* pFlight , int flightId)
{
	int ret;

	ret = -1;
	if(pFlight != NULL)
	{
		pFlight->idFlight = flightId;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int setFlyId(eFlight* pFlight , int flyId)
{
	int ret;

	ret = -1;
	if(pFlight != NULL)
	{
		pFlight->idFly = flyId;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int setPilotId(eFlight* pFlight , int pilotId)
{
	int ret;

	ret = -1;
	if(pFlight != NULL)
	{
		pFlight->idPilot = pilotId;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int setDateId(eFlight* pFlight , char date[])
{
	int ret;

	ret = -1;
	if(pFlight != NULL && date != NULL)
	{
		strcpy(pFlight->date , date);
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int setDestiny(eFlight* pFlight , char destiny[])
{
	int ret;

	ret = -1;
	if(pFlight != NULL && destiny != NULL)
	{
		strcpy(pFlight->destiny , destiny);
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int setPassengersCant(eFlight* pFlight , int passengers)
{
	int ret;

	ret = -1;
	if(pFlight != NULL)
	{
		pFlight->passengersCant = passengers;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int setDepartureTime(eFlight* pFlight , int departure)
{
	int ret;

	ret = -1;
	if(pFlight != NULL)
	{
		pFlight->departureTime = departure;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int setArriveTime(eFlight* pFlight , int arrive)
{
	int ret;

	ret = -1;
	if(pFlight != NULL)
	{
		pFlight->arriveTime = arrive;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  													//setters end
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  													//getters
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int getFlightId(eFlight* pFlight , int* flightId)
{
	int ret;

	ret = -1;
	if(pFlight != NULL && flightId != NULL)
	{
		*flightId = pFlight->idFlight;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int getFlyId(eFlight* pFlight , int* flyId)
{
	int ret;

	ret = -1;
	if(pFlight != NULL && flyId != NULL)
	{
		*flyId = pFlight->idFly;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int getPilotId(eFlight* pFlight , int* pilotId)
{
	int ret;

	ret = -1;
	if(pFlight != NULL && pilotId != NULL)
	{
		*pilotId = pFlight->idPilot;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int getDate(eFlight* pFlight , char date[])
{
	int ret;

	ret = -1;
	if(pFlight != NULL && date != NULL)
	{
		strcpy(date , pFlight->date);
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int getDestiny(eFlight* pFlight , char destiny[])
{
	int ret;

	ret = -1;
	if(pFlight != NULL && destiny != NULL)
	{
		strcpy(destiny , pFlight->destiny);
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int getPassengersCant(eFlight* pFlight , int* passengers)
{
	int ret;

	ret = -1;
	if(pFlight != NULL && passengers != NULL)
	{
		*passengers = pFlight->passengersCant;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int getdepartureTime(eFlight* pFlight , int* departure)
{
	int ret;

	ret = -1;
	if(pFlight != NULL && departure != NULL)
	{
		*departure = pFlight->departureTime;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int getArriveTime(eFlight* pFlight , int* arrive)
{
	int ret;

	ret = -1;
	if(pFlight != NULL && arrive != NULL)
	{
		*arrive = pFlight->arriveTime;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//  													//getters end
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


int passengersCounter(void* pElement)
{
	int counter;
	eFlight* aux;
	int passengersPerFlight;

	counter = 0;

	if(pElement != NULL)
	{
		aux = (eFlight*) pElement;
		getPassengersCant(aux, &passengersPerFlight);
		counter = passengersPerFlight;
	}

	return counter;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int passengersToChina(void* pElement)
{
	int counter;
	eFlight* aux;
	char place[TAMDESTINY];
	int passengersPerFlight;

	counter = 0;

	if(pElement != NULL)
	{
		aux = (eFlight*) pElement;

		getDestiny(aux, place);
		if(strcmp(place , "China") == 0)
		{
			getPassengersCant(aux, &passengersPerFlight);
			counter = passengersPerFlight;
		}
	}

	return counter;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int shortFlights(void* pElement)
{
	//Para declarar variable constante uso const y despues el tipo de dato.. como abajo muestro, uso const onda js
	//const int result = 0;
	int result;
	eFlight* aux;
	int departureTime;
	int arriveTime;
	int flightTime;

	result = 0;
	if(pElement != NULL)
	{
		aux = (eFlight*) pElement;
		getdepartureTime(aux, &departureTime);
		getArriveTime(aux, &arriveTime);

		flightTime = arriveTime - departureTime;

		if(flightTime > -1 && flightTime < 3)
		{
			result = 1;
		}
	}
	return result;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int chinaFlights(void* pElement)
{
	int result;
	eFlight* aux;
	char destiny[TAMDESTINY];


	result = 0;
	if(pElement != NULL)
	{
		aux = (eFlight*) pElement;
		getDestiny(aux, destiny);

		if(strcmp(destiny , "China") == 0)
		{
			result = 1;
		}

	}
	return result;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int excludeAlexLifesonFlights(void* pElement)
{
	int result;
	eFlight* aux;
	int pilotId;

	result = 0;
	if(pElement != NULL)
	{
		aux = (eFlight*) pElement;
		getPilotId(aux, &pilotId);

		if(pilotId != 1)
		{
			result = 1;
		}

	}
	return result;
}
