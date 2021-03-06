#include "Nexo.h"


int printMenu(int* option)
{
	int ret;

	ret = -1;

	if(option != NULL)
	{

		ret = 0;
		printf("\n\n|---------------------------------------------MENU-------------------------------------------------------------|\n");
		printf("|	1. Cargar archivo Pilotos:                                                                             |\n");
		printf("|	2. Cargar archivo Vuelos:                                                                              |\n");
		printf("|	3. Imprimir vuelos:                                                                                    |\n");
		printf("|	4. Cantidad de pasajeros:                                                                              |\n");
		printf("|	5. Cantidad de pasajeros a China:                                                                      |\n");
		printf("|	6. Filtrar vuelos cortos:                                                                              |\n");
		printf("|	7. Listar vuelos a China:                                                                              |\n");
		printf("|	8. Filtrar a Alex Lifeson:                                                                             |\n");
		printf("|	9. Ordenar Listado por ID de vuelo                                                                     |\n");
		printf("|	10. Ordenar Listado por nombre piloto                                                                  |\n");
		printf("|	11.Agregar nuevo vuelo                                                                                 |\n");
		printf("|	12.Salir                                                                                               |\n");
		printf("|--------------------------------------------------------------------------------------------------------------|\n");

		Get_numeroConLimites("Ingrese la opcion del menu..","Error, ingrese una opcion entre las dadas..\n",1,12,option);
	}

		return ret;
}

int printFlightsData(LinkedList* pArrayFlightsList , LinkedList*pArrayPilotsList)
{
	int ret;
	eFlight* auxFlight;
	int idPilotAux;
	int pilotIndex;

	ePilot* auxPilot;

	ret = -1;
	if(pArrayFlightsList != NULL && pArrayPilotsList != NULL)
	{
		ret = -2; //lista vacia
		if(isAnyLoaded(pArrayFlightsList, pArrayPilotsList) == 0)
		{
			printf("\n\n|-----------------------------------------------------------------------------------------------------------------------------------|\n");
			printf("|VUELO     AVION         PILOTO              FECHA               DESTINO          PASAJEROS      HORA SALIDA       HORA LLEGADA     |\n");
			printf("|-----------------------------------------------------------------------------------------------------------------------------------|\n");

			for(int i=0 ; i<ll_len(pArrayFlightsList) ; i++)
			{
				auxFlight = ll_get(pArrayFlightsList, i);
				getPilotIdFromFlight(auxFlight, &idPilotAux);

				pilotIndex = findPilotId(pArrayPilotsList , idPilotAux);
				if(pilotIndex != -1)
				{
					auxPilot = ll_get(pArrayPilotsList, pilotIndex);
					showFlight(auxFlight, auxPilot);
					ret = 0;
				}
			}
			printf("|-----------------------------------------------------------------------------------------------------------------------------------|\n");
		}
	}

	return ret;
}

int isAnyLoaded(LinkedList* pArrayFlightsList , LinkedList*pArrayPilotsList)
{
	int ret;

	ret = -1;
	if(pArrayFlightsList != NULL && pArrayPilotsList != NULL)
	{
		if(ll_len(pArrayFlightsList) > 0 && ll_len(pArrayPilotsList) > 0)
		{
			ret = 0;
		}
	}
	return ret;
}

int showFlight(eFlight* flight , ePilot* pilot)
{
	int ret;

	//vuelo
	int idFlight;
	int idPlane;
	char date[TAMFECHA];
	char destiny[TAMDESTINO];
	int passengers;
	int departureTime;
	int arriveTime;

	//piloto
	char pilotName[TAMNAME];


	ret = -1;

	if(flight != NULL && pilot != NULL)
	{
		ret = 0;
		getFlightId(flight, &idFlight);
		getPlaneId(flight, &idPlane);
		getFlightDate(flight, date);
		getFlightDestiny(flight, destiny);
		getPassengersCount(flight, &passengers);
		getDepertyTime(flight, &departureTime);
		getArriveTime(flight, &arriveTime);

		getPilotName(pilot, pilotName);

		printf("|%-10d %-10d %-20s %-20s %-20s %-13d %-18d %-12d |\n",idFlight , idPlane , pilotName , date , destiny , passengers , departureTime , arriveTime);
	}

	return ret;
}

int sortListByPilotName(void* pElement , void* pElement2 , LinkedList* pilotsList)
{
	int ret;

	eFlight* elem1;
	ePilot* pilotElem1;
	int idPilotElem1;
	int indexPilotElem1;
	char elemen1PilotName[TAMNAME];

	eFlight* elem2;
	ePilot* pilotElem2;
	int idPilotElem2;
	int indexPilotElem2;
	char elemen2PilotName[TAMNAME];

	elem1 = (eFlight*) pElement;
	elem2 = (eFlight*) pElement2;

	if(elem1 != NULL && elem2 != NULL)
	{
		getPilotIdFromFlight(elem1, &idPilotElem1);
		getPilotIdFromFlight(elem2, &idPilotElem2);

		indexPilotElem1 = findPilotId(pilotsList, idPilotElem1);
		indexPilotElem2 = findPilotId(pilotsList, idPilotElem2);

		if(idPilotElem1 > -1 && idPilotElem2 > -1)
		{
			pilotElem1 = (ePilot*) ll_get(pilotsList, indexPilotElem1);
			pilotElem2 = (ePilot*) ll_get(pilotsList , indexPilotElem2);

			if(pilotElem1 != NULL && pilotElem2 != NULL)
			{
				getPilotName(pilotElem1, elemen1PilotName);
				getPilotName(pilotElem2, elemen2PilotName);

				ret = strcmp(elemen1PilotName , elemen2PilotName);
			}
		}
	}
	return ret;
}

int addNewFlight(LinkedList* flightList , LinkedList* pilotList , int flightId)
{
	int ret;
	int idPiloto;
	eFlight* flightAux;

	ret = -1;
	if(flightList != NULL && pilotList != NULL)
	{
		ret = -2; //no existe el id que ingreso
		printPilotsList(pilotList);
		Get_numeroConLimites("Seleccione el id del piloto..", "Error, reintente", 0, 1000, &idPiloto);

		if(findPilotId(pilotList, idPiloto) > -1)
		{
			ret = -3;//no se encontro lugar para crear el vuelo... memoria llena, casi imposible pero ue, lo atajamos
			flightAux = generateNewFlight(idPiloto, flightId);
			if(flightAux != NULL)
			{
				ret = 0;
				ll_add(flightList, flightAux);
			}
		}
	}
	return ret;
}
