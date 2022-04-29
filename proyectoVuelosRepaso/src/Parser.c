#include "Parser.h"

int ParserFlightData(LinkedList* pFlightsArray , FILE* file)
{
	int ret;
	char auxFlightId[100];
	char auxPlaneId[100];
	char auxPilotId[100];
	char auxDate[100];
	char auxDestiny[100];
	char auxPassengers[100];
	char auxDeperty[100];
	char auxArrive[100];

	eFlight* auxFlight;

	ret = -1;
	if(pFlightsArray != NULL && file != NULL)
	{
		fscanf(file , "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n",auxFlightId , auxPlaneId ,auxPilotId , auxDate, auxDestiny, auxPassengers, auxDeperty, auxArrive);

		while(!feof(file))
		{
			if(fscanf(file , "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n",auxFlightId , auxPlaneId ,auxPilotId , auxDate, auxDestiny, auxPassengers, auxDeperty, auxArrive) == 8)
			{
				if(validateFlightData(auxFlightId , auxPlaneId ,auxPilotId , auxDate, auxDestiny, auxPassengers, auxDeperty, auxArrive) == 0)
				{
					auxFlight = newFlight_Parameters(auxFlightId , auxPlaneId ,auxPilotId , auxDate, auxDestiny, auxPassengers, auxDeperty, auxArrive);
					if(auxFlight != NULL)
					{
						//printf("%d - %d - %d - %s - %s - %d - %d - %d\n",auxFlight->flightId , auxFlight->planeId , auxFlight->pilotId , auxFlight->flightDate , auxFlight->flightDestiny , auxFlight->passengerCount , auxFlight->despityTime , auxFlight->arriveTime);
						ret = 0;
						ll_add(pFlightsArray, auxFlight);
					}
					else
					{
						ret = -5; //no se pudo crear el piloto en memory dinamica...
						break;
					}
				}
				else
				{
					ret = -4; //no se pudo validar algun dato
					break;
				}
			}
			else
			{
				ret = -3; //no se pudo parsear algun dato
				break;
			}
		}
	}

	return ret;
}

int ParserPilotData(LinkedList* pArrayPilots, FILE* path)
{
	int ret;
	char pilotIdAux[100];
	char pilotNameAux[100];

	ePilot* auxPilot;

	ret = -1;
	if(pArrayPilots != NULL && path != NULL)
	{
		fscanf(path , "%[^,], %[^\n]\n", pilotIdAux , pilotNameAux);

		while(!feof(path))
		{
			if(fscanf(path , "%[^,], %[^\n]\n", pilotIdAux , pilotNameAux) == 2)
			{
				if(validatePilotData(pilotIdAux , pilotNameAux) == 0)
				{
					auxPilot = newPilot_Parameters(pilotIdAux, pilotNameAux);
					if(auxPilot != NULL)
					{
						//printf("%d - %s\n",auxPilot->idPilot , auxPilot->pilotName);
						ll_add(pArrayPilots, auxPilot);
						ret = 0;
					}
					else
					{
						ret = -5; //no se encontro memoria o no pudo crearse por x motivo
					}
				}
				else
				{
					ret = -4; //algun dato no se pudo validar..
					break;
				}
			}
			else
			{
				ret = -3; //no se pudo cargar algun dato..
				break;
			}
		}
	}
	return ret;
}


int validateFlightData(char* flightId,char* planeId,char* pilotId,char* date,char* destiny,char* passengers,char* deperty,char* arrive)
{
	int ret;
	int flagControlUno = -1;
	int flagControlDos = -1;
	int flagControlTres = -1;
	int flagControlCuatro = -1;
	int flagControlCinco = -1;
	int flagControlSeis = -1;
	int flagControlSiete = -1;
	int flagControlOcho = -1;

	ret = -1;
	if(flightId != NULL && planeId != NULL && pilotId != NULL && date != NULL && destiny != NULL && passengers != NULL && deperty != NULL && arrive != NULL)
	{
		if(esNumero(flightId , sizeof(flightId)) == 0)
		{
			flagControlUno = 0;
		}

		if(esNumero(planeId , sizeof(planeId)) == 0)
		{
			flagControlDos = 0;
		}

		if(esNumero(pilotId , sizeof(pilotId)) == 0)
		{
			flagControlTres = 0;
		}

		if(esFecha(date) == 0)
		{
			flagControlCuatro = 0;
		}

		if(sonLetras(destiny , sizeof(destiny)) == 0)
		{
			flagControlCinco = 0;
		}

		if(esNumero(passengers , sizeof(passengers)) == 0)
		{
			flagControlSeis = 0;
		}

		if(esNumero(deperty , sizeof(deperty)) == 0)
		{
			flagControlSiete = 0;
		}

		if(esNumero(arrive , sizeof(arrive)) == 0)
		{
			flagControlOcho = 0;
		}
	}

	if(flagControlUno == 0 && flagControlDos == 0 && flagControlTres == 0 && flagControlCuatro == 0 && flagControlCinco == 0 && flagControlSeis == 0 && flagControlSiete == 0 && flagControlOcho == 0)
	{
		ret = 0;
	}

	return ret;
}

int validatePilotData(char* idPilot, char* pilotName)
{
	int ret;
	int flag1 = -1;
	int flag2 = -1;

	ret = -1;
	if(idPilot != NULL && pilotName != NULL)
	{
		//asi ahorro codigo, pero tengo que saber bien que devuelve cada func a la que asigno la var de control
		flag1 = esNumero(idPilot, sizeof(idPilot));
		flag2 = sonLetras(pilotName , sizeof(pilotName));
	}
	if(flag1 == 0 && flag2 == 0)
	{
		ret = 0;
	}

	return ret;
}
