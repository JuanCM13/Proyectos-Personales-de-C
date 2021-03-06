#include "Flights.h"

eFlight* newFlight()
{
	return (eFlight*) calloc(1 , sizeof(eFlight));
}

eFlight* newFlight_Parameters(char* flightId , char* planeId, char* pilotId, char* date, char* destiny, char* passengers, char* depertyTime, char* arriveTime)
{
	eFlight* flightAux;
	int auxFlightId;
	int auxPlaneId;
	int auxPilotId;
	char auxDate[TAMFECHA];
	char auxDestiny[TAMDESTINO];
	int auxPassengersCount;
	int auxDepertyTime;
	int auxArriveTime;

	flightAux = NULL;
	if(flightId != NULL && planeId != NULL && pilotId != NULL && date != NULL && destiny != NULL && passengers != NULL && depertyTime != NULL && arriveTime != NULL)
	{
		flightAux = newFlight();

		if(flightAux != NULL) //osea si encontro lugar en memoria dinamica, asigno...
		{
			//conversiones
			auxFlightId = atoi(flightId);
			//printf("EL ID ES:%d\n",auxFlightId);
			auxPlaneId = atoi(planeId);
			auxPilotId = atoi(pilotId);
			strncpy(auxDate , date , sizeof(auxDate));
			strncpy(auxDestiny , destiny , sizeof(auxDestiny));
			auxPassengersCount = atoi(passengers);
			auxDepertyTime = atoi(depertyTime);
			auxArriveTime = atoi(arriveTime);

			//setters
			setFlightId(flightAux, auxFlightId);
			setPlaneId(flightAux, auxPlaneId);
			setPilotIdFromFlight(flightAux, auxPilotId);
			setFlightDate(flightAux, auxDate);
			setFlightDestiny(flightAux, auxDestiny);
			setPassengersCount(flightAux, auxPassengersCount);
			setDepartyTime(flightAux, auxDepertyTime);
			setArriveTime(flightAux, auxArriveTime);
		}
	}

	return flightAux;
}

//--------------------GETTERS

int getFlightId(eFlight* this , int* flightId)
{
	int ret;

	ret = -1;
	if(this != NULL && flightId != NULL)
	{
		*flightId = this->flightId;
		ret = 0;
	}

	return ret;
}

int getPlaneId(eFlight* this , int* planeId)
{
	int ret;

	ret = -1;
	if(this != NULL && planeId != NULL)
	{
		*planeId = this->planeId;
		ret = 0;
	}

	return ret;
}

int getPilotIdFromFlight(eFlight* this , int* pilotId)
{
	int ret;

	ret = -1;
	if(this != NULL && pilotId != NULL)
	{
		*pilotId = this->pilotId;
		ret = 0;
	}

	return ret;
}

int getFlightDate(eFlight* this , char* date)
{
	int ret;

	ret = -1;
	if(this != NULL && date != NULL)
	{
		strcpy(date , this->flightDate);
		ret = 0;
	}

	return ret;
}

int getFlightDestiny(eFlight* this , char* dastiny)
{
	int ret;

	ret = -1;
	if(this != NULL && dastiny != NULL)
	{
		strcpy(dastiny , this->flightDestiny);
		ret = 0;
	}

	return ret;
}

int getPassengersCount(eFlight* this , int* passengers)
{
	int ret;

	ret = -1;
	if(this != NULL && passengers != NULL)
	{
		*passengers = this->passengerCount;
		ret = 0;
	}

	return ret;
}

int getDepertyTime(eFlight* this , int* depertyTime)
{
	int ret;

	ret = -1;
	if(this != NULL && depertyTime != NULL)
	{
		*depertyTime = this->despityTime;
		ret = 0;
	}

	return ret;
}

int getArriveTime(eFlight* this , int* arriveTime)
{
	int ret;

	ret = -1;
	if(this != NULL && arriveTime != NULL)
	{
		*arriveTime = this->arriveTime;
		ret = 0;
	}

	return ret;
}

//--------------------------SETTERS

int setFlightId(eFlight* this , int flightId)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->flightId = flightId;
		ret = 0;
	}

	return ret;
}

int setPlaneId(eFlight* this , int planeId)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->planeId = planeId;
		ret = 0;
	}

	return ret;
}

int setPilotIdFromFlight(eFlight* this , int pilotId)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->pilotId = pilotId;
		ret = 0;
	}

	return ret;
}

int setFlightDate(eFlight* this , char* date)
{
	int ret;

	ret = -1;

	if(this != NULL && date != NULL)
	{
		strcpy(this->flightDate , date);
		ret = 0;
	}

	return ret;
}

int setFlightDestiny(eFlight* this , char* destiny)
{
	int ret;

	ret = -1;

	if(this != NULL && destiny != NULL)
	{
		strcpy(this->flightDestiny , destiny);
		ret = 0;
	}

	return ret;
}

int setPassengersCount(eFlight* this , int passengers)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->passengerCount = passengers;
		ret = 0;
	}

	return ret;
}

int setDepartyTime(eFlight* this , int deperty)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->despityTime = deperty;
		ret = 0;
	}

	return ret;
}

int setArriveTime(eFlight* this , int arrive)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->arriveTime = arrive;
		ret = 0;
	}

	return ret;
}

int countPassengersOrChinaPassengers(LinkedList* pArrayFlightList , int election)
{
	int ret;
	int acum;
	eFlight* pFlight;
	int passengersAux;

	//---
	char destinyAux[TAMDESTINO];

	acum = 0;
	ret = -1;

	if(pArrayFlightList != NULL && (election > -1 && election < 2) )
	{
		for(int i=0 ; i<ll_len(pArrayFlightList) ; i++)
		{
			pFlight = ll_get(pArrayFlightList, i);
			getPassengersCount(pFlight, &passengersAux);

			if(election == 0)
			{
				acum += passengersAux;
			}
			else
			{
				getFlightDestiny(pFlight, destinyAux);
				if(strcmp(destinyAux , "China") == 0)
				{
					acum += passengersAux;
				}
			}
		}
		ret = acum;
	}

	return ret;
}

int filtShortFlights(void* pVoidElement)
{
	int ret;
	eFlight* auxFlight;
	int arriveTime;
	int depertyTime;

	ret = 0; //no guarda...
	if(pVoidElement != NULL)
	{
		auxFlight = (eFlight*) pVoidElement;
		if(auxFlight != NULL)
		{
			getArriveTime(auxFlight, &arriveTime);
			getDepertyTime(auxFlight, &depertyTime);

			if( (arriveTime - depertyTime) < 3)
			{
				ret = 1;
			}
		}
	}
	return ret;
}

int filtChinaFlights(void* pVoidElement)
{
	int ret;
	eFlight* auxFlight;
	char destiny[TAMDESTINO];

	ret = 0;
	if(pVoidElement != NULL)
	{
		auxFlight = (eFlight*) pVoidElement;
		if(auxFlight != NULL)
		{
			getFlightDestiny(auxFlight, destiny);
			if(strcmp(destiny , "China") == 0)
			{
				ret = 1;
			}
		}
	}
	return ret;
}

int filtExcludeAlexLifeson(void* pVoidElement)
{
	int ret;
	eFlight* auxFlight;
	int idPilot;


	ret = 0;
	if(pVoidElement != NULL)
	{
		auxFlight = (eFlight*) pVoidElement;
		if(auxFlight != NULL)
		{
			getPilotIdFromFlight(auxFlight, &idPilot);
			if(idPilot != 1)
			{
				ret = 1;
			}
		}
	}
	return ret;
}

int sortListByFlightId(void* pElement , void* pElement2)
{
	int ret;
	eFlight* element1;
	eFlight* element2;
	int flightIdEelement1;
	int flightIdEelement2;

	element1 = (eFlight*) pElement;
	element2 = (eFlight*) pElement2;

	ret = 0; //si algo falla no ordeno ninguno.. y si son iguales los dejo asi..
	if(element1 != NULL && element2 != NULL)
	{
		getFlightId(element1, &flightIdEelement1);
		getFlightId(element2, &flightIdEelement2);

		if(flightIdEelement1 > flightIdEelement2)
		{
			ret = 1;
		}
		else
		{
			if(flightIdEelement1 < flightIdEelement2)
			{
				ret = -1;
			}
		}
	}
	return ret;
}

eFlight* generateNewFlight(int idPiloto , int flightId)
{
	eFlight* flight;
	char flightDateAux[TAMFECHA];
	char destinyAux[TAMDESTINO];
	int passengers;
	int deperty;
	int arrive;
	int planeId;

	flight = newFlight();
	if(flight != NULL)
	{
		do
		{
			Get_cadena("Ingrese la fecha del viaje.. formato: ##/##/####", "Error, reingrese",flightDateAux , TAMFECHA);
			if(esFecha(flightDateAux) == 0)
			{
				break;
			}

			printf("Error, reingrese\n");
		}while(1);

		Get_cadena("Ingrese el destino..", "Error, reingrese",destinyAux , TAMDESTINO);
		OrdenarNombre(destinyAux, TAMDESTINO);

		Get_numeroConLimites("Ingrese la cantidad de pasajeros del vuelo", "Error, no pueden superar los 300", 0, 300, &passengers);
		Get_numeroConLimites("Ingrese la hora de salida, formato: ##,ej: 17", "Error, no pueden superar las 24", 0, 24, &deperty);
		Get_numeroConLimites("Ingrese la hora de llegada, formato: ##,ej: 24", "Error, no pueden superar las 24", 0, 24, &arrive);
		Get_numeroConLimites("Ingrese el id del avion", "Error, no puede ser menor a cero", 0, 10000, &planeId);

		//setFlightId(this, flightId)
		setFlightDate(flight, flightDateAux);
		setFlightDestiny(flight, destinyAux);
		setArriveTime(flight, arrive);
		setDepartyTime(flight, deperty);
		setPilotIdFromFlight(flight, idPiloto);
		setPlaneId(flight, planeId);
		setFlightId(flight, flightId);
		setPassengersCount(flight, passengers);
	}
	return flight;
}

int getLastFlightId(LinkedList* pArrayFlights)
{
	int ret = -1;
	LinkedList* auxList;
	eFlight* auxVuelo;
	int lastFlightId;

	if(pArrayFlights != NULL)
	{
		auxList = ll_clone(pArrayFlights); //clono la lista, asi la ordeno y saco le ultimo elemento (el ultimo id) y no afecta el orden
		if(auxList != NULL)					//de la verdadera lista, despues borro est linedList auxiliar...
		{
			ll_sort(auxList , sortListByFlightId , 1); //la ordeno de menor a mayor por id
			auxVuelo = (eFlight*) ll_get(auxList , (ll_len(auxList)-1) ); //guardo en el vuelo aux, el ultimo elemento (como arranca en la posision 0
																			//seria el ultinmo elemento que me devuelve el len, - (asi abarca el index 0)
			if(auxVuelo != NULL)
			{
				getFlightId(auxVuelo, &lastFlightId);
				ret = lastFlightId;
			}

			free(auxList); //ya libero la lista auxiliar..
		}
	}
	return ret;
}
