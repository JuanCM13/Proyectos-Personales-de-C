#include "Nexo.h"

//-----------------------------------------------------------------------------

/** \brief Imprime el menu de opciones y pide y retorna la opcion elegida por el usuario
 *
 * \param int* opcion (donde se retorna la opcion elegida)
 * \return 0 si esta todo ok , -1 fallaron nulls
 *
 */

int printMenu(int* option)
{
	int ret;

	ret = -1;

	if(option != NULL)
	{

		ret = 0;
		printf("\n\n|---------------------------------------------MENU-------------------------------------------------------------|\n");
		printf("|	1. Cargar archivo Vuelos:                                                                              |\n");
		printf("|	2. Cargar archivo Pilotos:                                                                             |\n");
		printf("|	3. Imprimir vuelos:                                                                                    |\n");
		printf("|	4. Cantidad de pasajeros:                                                                              |\n");
		printf("|	5. Cantidad de pasajeros a China:                                                                      |\n");
		printf("|	6. Filtrar vuelos cortos:                                                                              |\n");
		printf("|	7. Listar vuelos a China:                                                                              |\n");
		printf("|	8. Filtrar a Alex Lifeson:                                                                             |\n");
		printf("|	9. Salir.                                                                                              |\n");
		printf("|--------------------------------------------------------------------------------------------------------------|\n");

		Get_numeroConLimites("Ingrese la opcion del menu..","Error, ingrese una opcion entre las dadas..\n",1,10,option);
	}

		return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------

int printFlights(LinkedList* flightsList , LinkedList* pilotsList)
{
	int ret;
	int i;
	int flightsListLen;
	int idPilot;

	eFlight* flightAux;
	ePilot* pilotAux;

	ret = -1;
	if(flightsList != NULL && pilotsList != NULL)
	{
		ret = -2; //la lista se encuentra vacia
		flightsListLen = ll_len(flightsList);
		if(flightsListLen > 0)
		{
			printf("\n\n|-----------------------------------------------------------------------------------------------------------------------------------|\n");
			printf("|VUELO     AVION         PILOTO              FECHA               DESTINO          PASAJEROS      HORA SALIDA       HORA LLEGADA     |\n");
			printf("|-----------------------------------------------------------------------------------------------------------------------------------|\n");
			for(i=0 ; i<flightsListLen ; i++)
			{
				flightAux = ll_get(flightsList, i);
				getPilotId(flightAux, &idPilot);

				pilotAux = findPilotById(pilotsList , idPilot);
				if(pilotAux != NULL)
				{
					ret = 0;
					printOneFlight(flightAux , pilotAux);
				}
			}
			printf("|-----------------------------------------------------------------------------------------------------------------------------------|\n\n");
		}
	}
	return ret;
}

int printOneFlight(eFlight* flight , ePilot* pilot)
{
	int ret;

	//vuelo
	int idFlightAux;
	int idFlyAux;
	char dateAux[TAMDATE];
	char destinyAux[TAMDESTINY];
	int passengersAux;
	int departureAux;
	int arriveAux;

	//piloto
	char pilotNameAux[TAMNAME];


	ret = -1;

	if(flight != NULL && pilot != NULL)
	{
		ret = 0;

		getFlightId(flight, &idFlightAux);
		getFlyId(flight, &idFlyAux);
		getDate(flight, dateAux);
		getDestiny(flight, destinyAux);
		getPassengersCant(flight, &passengersAux);
		getdepartureTime(flight, &departureAux);
		getArriveTime(flight, &arriveAux);

		//--------
		getPilotName(pilot, pilotNameAux);

		printf("|%-10d %-10d %-20s %-20s %-20s %-13d %-18d %-12d |\n",idFlightAux , idFlyAux , pilotNameAux , dateAux , destinyAux , passengersAux , departureAux , arriveAux);
	}

	return ret;
}

