#include "Controller.h"

int Controller_LoadFlightsFile(LinkedList* pArrayFlights)
{
	int ret;
	FILE* path;
	char fileDirection[TAMFILE];

	ret = -1;
	if(pArrayFlights != NULL)
	{
		ret = -2; //no se encontro el archivo....
		Get_cadena("Ingrese el nombre del archivo donde se aloja la data de vuelos", "Error, no puede superar los 100 caracteres", fileDirection, sizeof(fileDirection));

		path = fopen(fileDirection , "r");

		//si se encontro el archivo...
		if(path != NULL)
		{
			ret = ParserFlightData(pArrayFlights , path); //aca directamente crea llamando al constructor de vuelos
		}												//directamente el parser, sino llamarlo de aca implicaria traer la data

		fclose(path);
	}												//sacada del archivo con punteros y un re choclo seria :s

	return ret;
}


int Controller_LoadPilotsFile(LinkedList* pArrayPilots)
{
	int ret;
	FILE* path;
	char fileDirection[TAMFILE];

	ret = -1;
	if(pArrayPilots != NULL)
	{
		ret = -2; //no se encontro el archivo....
		Get_cadena("Ingrese el nombre del archivo donde se aloja la data de pilotos", "Error, no puede superar los 100 caracteres", fileDirection, sizeof(fileDirection));

		path = fopen(fileDirection , "r");

		//si se encontro el archivo...
		if(path != NULL)
		{
			ret = ParserPilotData(pArrayPilots , path); //aca directamente crea llamando al constructor de vuelos
		}												//directamente el parser, sino llamarlo de aca implicaria traer la data
		fclose(path);
	}												//sacada del archivo con punteros y un re choclo seria :s

	return ret;
}

int Controller_PrintFlights(LinkedList* pArrayFlights , LinkedList* pArrayPilots)
{
	int ret;

	ret = -1;
	if(pArrayFlights != NULL && pArrayPilots != NULL)
	{
			ret = printFlightsData(pArrayFlights , pArrayPilots);
	}
	return ret;
}

int Controller_CountPassengers(LinkedList* pArrayFlights , int especification)
{
	int ret;

	ret = -1;
	if(pArrayFlights != NULL && (especification > -1 && especification < 2) )
	{
		ret = countPassengersOrChinaPassengers(pArrayFlights , especification);
		if(ret != -1)
		{
			printf("La cantidad de pasajeros es de: %d\n",ret);
		}
	}
	return ret;
}

int Controller_ShortFlights(LinkedList* pArrayFlights , LinkedList* pArrayPilots)
{
	int ret;
	LinkedList* shortFlights;

	ret = -1;
	if(pArrayFlights != NULL && pArrayPilots != NULL)
	{
		shortFlights = ll_filter(pArrayFlights, filtShortFlights);
		if(shortFlights != NULL)
		{
			ret = Controller_SaveFlightsAsCsv(shortFlights, ARCHIVOVUELOSCORTOS);
			if(ret == 0)
			{
				ret = 1; //guardo pero no quiere imprimir el listado...
				if(QueresSeguir("Desea imprimir la lista? s/n") == 0)
				{
					printFlightsData(shortFlights, pArrayPilots);
					ret = 0;
				}
			}
			free(shortFlights);
		}
	}
	return ret;
}

int Controller_ChinaFlightsList(LinkedList* pArrayFlightsToSave , LinkedList* pArrayPilots)
{
	int ret;
	LinkedList* chinaList;

	ret = -1;
	if(pArrayFlightsToSave != NULL && pArrayPilots != NULL)
	{
		chinaList = ll_filter(pArrayFlightsToSave, filtChinaFlights);
		if(chinaList != NULL)
		{
			ret = 0;
			printFlightsData(chinaList, pArrayPilots);
			free(chinaList);
		}
	}
	return ret;
}

int Controller_ExpludePilotFromList(LinkedList* pArrayFlights , LinkedList* pArrayPilots)
{
	int ret;
	LinkedList* excludeAlexLifeson;

	ret = -1;
	if(pArrayFlights != NULL && pArrayPilots != NULL)
	{
		excludeAlexLifeson = ll_filter(pArrayFlights, filtExcludeAlexLifeson);
		if(excludeAlexLifeson != NULL)
		{
			ret = Controller_SaveFlightsAsCsv(excludeAlexLifeson, VUELOSSINALEXLIFESON);
			if(ret == 0)
			{
				ret = 1; //guardo pero no quiere imprimir el listado...
				if(QueresSeguir("Desea imprimir la lista? s/n") == 0)
				{
					printFlightsData(excludeAlexLifeson, pArrayPilots);
					ret = 0;
				}
			}
			free(excludeAlexLifeson);
		}
	}
	return ret;
}

int Controller_SaveFlightsAsCsv(LinkedList* pArrayFlightsToSave , char* fileName)
{
	int ret;
	eFlight* auxFlight;
	FILE* path;

	//-----
	int flightId;
	int planeId;
	int pilotId;
	char date[TAMFECHA];
	char destiny[TAMDESTINO];
	int passengers;
	int deperty;
	int arrive;

	ret = -1; //nulls
	if(pArrayFlightsToSave != NULL && fileName != NULL)
	{
		ret = -2; //no se pudo crar el archivo
		path = fopen(fileName , "w");
		if(path != NULL)
		{
			ret = 0;
			fprintf(path ,"VUELO,AVION,ID PILOTO,FECHA,DESTINO,CANT PASAJEROS,HORA SALIDA,HORA LLEGADA\n");

			for(int i=0 ; i<ll_len(pArrayFlightsToSave) ; i++)
			{
				auxFlight = ll_get(pArrayFlightsToSave, i);
				//getters
				getFlightId(auxFlight, &flightId);
				getPlaneId(auxFlight, &planeId);
				getPilotIdFromFlight(auxFlight, &pilotId);
				getFlightDate(auxFlight, date);
				getFlightDestiny(auxFlight, destiny);
				getPassengersCount(auxFlight, &passengers);
				getDepertyTime(auxFlight, &deperty);
				getArriveTime(auxFlight, &arrive);

				fprintf(path , "%d,%d,%d,%s,%s,%d,%d,%d\n",flightId , planeId , pilotId , date , destiny , passengers , deperty , arrive);
			}
			fclose(path);
		}
	}
	return ret;
}

int Controller_SortListByFlightId(LinkedList* pArrayFlight , LinkedList* pArrayPilot , int order)
{
	int ret;

	//order 1 ascendentemente , order 0 descendentemente
	ret = -1;
	if(pArrayFlight != NULL && pArrayPilot != NULL && (order > -1 && order < 2) )
	{
		ret = -2; //no hay elementos cargados a la lista
		if(ll_len(pArrayFlight) > 0 && ll_len(pArrayPilot) > 0)
		{

			ret = ll_sort(pArrayFlight, sortListByFlightId , order);

			if(ret == 0)
			{
				ret = 1; //ordeno pero no la mostro...
				if(QueresSeguir("Desea visualizar la lista? s/n") == 0)
				{
					Controller_PrintFlights(pArrayFlight, pArrayPilot);
					ret = 0; //ordeno y mostro..
				}
			}
		}
	}
	return ret;
}

int Controller_SortListByPilotName(LinkedList* pArrayFlight , LinkedList* pArrayPilot , int order)
{
	int ret;

	ret = -1;
	if(pArrayFlight != NULL && pArrayPilot != NULL && (order > -1 && order < 2) )
	{
		ret = -2;
		if(ll_len(pArrayFlight) > 0 && ll_len(pArrayPilot) > 0)
		{
			ret = ll_sort2(pArrayFlight , sortListByPilotName , order , pArrayPilot);

			if(ret == 0)
			{
				ret = 1; //creo pero no muestra
				if(QueresSeguir("Desea imprimir el listado? s/n") == 0)
				{
					ret = 0;
					Controller_PrintFlights(pArrayFlight, pArrayPilot);
				}
			}
		}
	}
	return ret;
}

/*
 * Esta func, llama a addNewFlight, el usuario llena los campos y se carga un nuevo elemento a la lista y se actualiza el archivo de vuelos.
 * El id lo parsea de un archivo de ultimo vuelo cargado. Si es la primera vez, crea el archivo y recorre la lista de vuelos actual,
 * buscando el id mas grande... , extrae este y le suma 1
 */
int Controller_AddNewFlight(LinkedList* pArrayFlight , LinkedList* pArrayPilots)
{
	int ret;
	FILE* pFlightsCounterFlie;
	int lastFlight;

	//* solo si no se pudo generar
	//*
	ret = -1;
	if(pArrayFlight != NULL && pArrayPilots != NULL)
	{
		pFlightsCounterFlie = fopen(ARCHIVOULTIMOIDVUELO , "r");
		if(pFlightsCounterFlie == NULL)
		{
			pFlightsCounterFlie = fopen(ARCHIVOULTIMOIDVUELO , "w");
			if(pFlightsCounterFlie != NULL)
			{
				lastFlight = getLastFlightId(pArrayFlight);
				if(lastFlight != -1)
				{
					fprintf(pFlightsCounterFlie , "%d\n" , lastFlight);
				}
				fclose(pFlightsCounterFlie);
			}
		}
		else
		{
			fscanf(pFlightsCounterFlie , "%d\n", &lastFlight);
			fclose(pFlightsCounterFlie);
		}

		if(lastFlight != -1)
		{
			lastFlight += 1; //aca mando ya cambio el valor del id, agregandole 1 asi setea y actualizaa todo en base a ese id incrementado
			ret = addNewFlight(pArrayFlight, pArrayPilots, lastFlight);

			if(ret == 0)
			{
				ret = Controller_SaveFlightsAsCsv(pArrayFlight, "Vuelos.csv");
				pFlightsCounterFlie = fopen(ARCHIVOULTIMOIDVUELO , "w");
				if(pFlightsCounterFlie != NULL)
				{
					fprintf(pFlightsCounterFlie , "%d\n",lastFlight);
					fclose(pFlightsCounterFlie);
				}
			}
		}
	}
	return ret;
}
