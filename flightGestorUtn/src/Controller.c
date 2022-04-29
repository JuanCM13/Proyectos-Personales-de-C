#include "Controller.h"

//---------------------------------------------------------------------------------------------------------------------------------------

int controller_openFlightsFile(LinkedList* flightsArray)
{
	int ret;
	char Path[TAMPATH];
	FILE* pFileFlights;
	int parserFlow;

	ret = -1;

	if(flightsArray != NULL)
	{
		Get_cadena("Ingrese el nombre del archivo de vuelos..", "Error, el nombre no puede ser tan largo..", Path, sizeof(Path));

		pFileFlights = fopen(Path , "r");

		if(pFileFlights != NULL)
		{
			parserFlow = parserFlights_fromText(flightsArray , pFileFlights);
			switch(parserFlow)
			{
				case 0:
					printf("El archivo %s , fue cargado con exito..\n",Path);
					ret = 0;
				break;
				case -1:
					printf("Algo fallo, reintente...\n");
				break;
				case -2:
					printf("El archivo %s ,fue encontrado, pero no pudo ser leido..\n",Path);
				break;
				case -3:
					printf("Uno/s parametros del archivo %s a procesar no son validos, revise..\n",Path);
				break;
			}
			fclose(pFileFlights);
		}
		else
		{
			printf("El archivo %s , no se encontro en su dispositivo, ingrese bien el nombre..\n",Path);
		}
	}
	else
	{
		printf("Algo fallo, reintente..\n");
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------

int controller_openPilotsFile(LinkedList* pilotsArray)
{
	int ret;
	char Path[TAMPATH];
	FILE* pFilePilots;
	int parserFlow;

	ret = -1;

	if(pilotsArray != NULL)
	{
		Get_cadena("Ingrese el nombre del archivo de pilotos..", "Error, el nombre no puede ser tan largo..", Path, sizeof(Path));

		pFilePilots = fopen(Path , "r");

		if(pFilePilots != NULL)
		{
			parserFlow = parserPilots_fromText(pilotsArray , pFilePilots);
			switch(parserFlow)
			{
				case 0:
					printf("El archivo %s , fue cargado con exito..\n",Path);
					ret = 0;
				break;
				case -1:
					printf("Algo fallo, reintente...\n");
				break;
				case -2:
					printf("El archivo %s ,fue encontrado, pero no pudo ser leido..\n",Path);
				break;
				case -3:
					printf("Uno/s parametros del archivo %s a procesar no son validos, revise..\n",Path);
				break;
			}
			fclose(pFilePilots);
		}
		else
		{
			printf("El archivo %s , no se encontro en su dispositivo, ingrese bien el nombre..\n",Path);
		}
	}
	else
	{
		printf("Algo fallo, reintente..\n");
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------

void controller_showFlightsList(LinkedList* flightsList , LinkedList* pilotsList)
{
	int ret;

	if(flightsList != NULL && pilotsList != NULL)
	{
		ret = printFlights(flightsList , pilotsList);
		switch(ret)
		{
			case -1:
				printf("Algo fallo, reintente..\n");
			break;
			case -2:
				printf("La lista se encuentra vacia, reintente..\n");
			break;
		}
	}
	else
	{
		printf("Algo fallo, reintente..\n");
	}

}

//---------------------------------------------------------------------------------------------------------------------------------------

void totalPassengersCounter(LinkedList* flightList)
{
	int result;

	if(flightList != NULL)
	{
		result = ll_count(flightList, passengersCounter);
		if(result > -1)
		{
			printf("El total de pasageros, contados en todos los vuelos es de: %d\n",result);
		}
		else
		{
			printf("Algo fallo al calcular los pasageros, reintente..\n");
		}
	}
	else
	{
		printf("Algo fallo, reintente..\n");
	}

}

//---------------------------------------------------------------------------------------------------------------------------------------

void passengersToChinaCounter(LinkedList* flightList)
{
	int result;

	if(flightList != NULL)
	{
		result = ll_count(flightList, passengersToChina);
		if(result > -1)
		{
			printf("El total de pasageros con destino a china es de: %d\n",result);
		}
		else
		{
			printf("Algo fallo al calcular los pasageros, reintente..\n");
		}
	}
	else
	{
		printf("Algo fallo, reintente..\n");
	}

}

//---------------------------------------------------------------------------------------------------------------------------------------

void shortFlightsList(LinkedList* flightList , LinkedList* pilotsList)
{
	LinkedList* shortFlightsList;
	int saveFileStatus;

	if(flightList != NULL && pilotsList != NULL)
	{
		shortFlightsList = ll_filter(flightList, shortFlights);
		if(shortFlightsList != NULL)
		{
			saveFileStatus = saveAsText(shortFlightsList , ARCHIVOVUELOSCORTOS);
			switch(saveFileStatus)
			{
				case 0:
					if(QueresSeguir("Lista creada/actualizada con exito..\nDesea imprimir la lista??") == 0)
					{
						controller_showFlightsList(shortFlightsList , pilotsList);
					}

					printf("Podra encontrar el archivo con el nombre: --%s--\n",ARCHIVOVUELOSCORTOS);
				break;
				case -1:
					printf("Algo fallo con el guardado del archivo reintente..\n");
				break;
				case -2:
					printf("No se puede guardar una lista vacia, corrobore que la lista tenga algo cargado y guarde..\n");
				break;
				case -3:
					printf("No se pudo encontrar lugar disponible para guardar la lista, reintente..\n");
				break;
			}
		}
		else
		{
			printf("No se pudo crear la lista de vuelos cortos, reintente..\n");
		}

	}
	else
	{
		printf("Algo fallo, reintente..\n");
	}

}

//---------------------------------------------------------------------------------------------------------------------------------------

int saveAsText(LinkedList* list , char* fileName)
{
	int ret;
	int i;
	FILE* path;
	int listLen;

	//flight data
	eFlight* flightAux;
	int idFlight;
	int idFly;
	int idPilot;
	char date[TAMDATE];
	char destiny[TAMDESTINY];
	int passengers;
	int departure;
	int arrive;

	ret = -1;

	if(list != NULL && fileName != NULL)
	{
		ret = -3; //cant save an empty list..
		listLen = ll_len(list);

		if(listLen > 0)
		{
			ret = -2; //something go wrong with the path, no space to create..
			path = fopen(fileName , "w");
			if(path != NULL)
			{
				ret = 0; //save all ggood
				fprintf(path , "ID VUELO,ID AVION,ID PILOTO,FECHA,DESTINO,CANTIDAD PASAJEROS,HORA SALIDA,HORA DESPEGUE\n");
				for(i=0 ; i<listLen ; i++)
				{
					//flightData
					flightAux = (eFlight*) ll_get(list, i);
					getFlightId(flightAux, &idFlight);
					getFlyId(flightAux, &idFly);
					getPilotId(flightAux, &idPilot);
					getDate(flightAux, date);
					getDestiny(flightAux, destiny);
					getPassengersCant(flightAux, &passengers);
					getdepartureTime(flightAux, &departure);
					getArriveTime(flightAux, &arrive);

					fprintf(path , "%d , %d , %d , %s , %s , %d , %d , %d\n",idFlight , idFly , idPilot , date , destiny , passengers , departure , arrive);
				}

				fclose(path);
			}
		}
	}
	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------

void chinaFlightsList(LinkedList* flightList , LinkedList* pilotsList)
{
	LinkedList* chinaFlightsList;
	int saveFileStatus;

	if(flightList != NULL && pilotsList != NULL)
	{
		chinaFlightsList = ll_filter(flightList, chinaFlights);
		if(chinaFlightsList != NULL)
		{
			saveFileStatus = saveAsText(chinaFlightsList , ARCHIVOVUELOSCHINA);
			switch(saveFileStatus)
			{
				case 0:

					if(QueresSeguir("Lista creada/actualizada con exito..\nDesea imprimir la lista??") == 0)
					{
						controller_showFlightsList(chinaFlightsList , pilotsList);
					}

					printf("Podra encontrar el archivo con el nombre: --%s--\n",ARCHIVOVUELOSCHINA);

				break;
				case -1:
					printf("Algo fallo con el guardado del archivo reintente..\n");
				break;
				case -2:
					printf("No se puede guardar una lista vacia, corrobore que la lista tenga algo cargado y guarde..\n");
				break;
				case -3:
					printf("No se pudo encontrar lugar disponible para guardar la lista, reintente..\n");
				break;
			}
		}
		else
		{
			printf("No se pudo crear la lista de vuelos cortos, reintente..\n");
		}

	}
	else
	{
		printf("Algo fallo, reintente..\n");
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------

void pilotsListExceptAlexLifeson(LinkedList* flightList , LinkedList* pilotsList)
{
	LinkedList* excludeLifesonList;
	int saveFileStatus;

	if(flightList != NULL && pilotsList != NULL)
	{
		excludeLifesonList = ll_filter(flightList, excludeAlexLifesonFlights);
		if(excludeLifesonList != NULL)
		{
			saveFileStatus = saveAsText(excludeLifesonList , ARCHIVOVUELOSSINALEXLIFESON);
			switch(saveFileStatus)
			{
				case 0:

					if(QueresSeguir("Lista creada/actualizada con exito..\nDesea imprimir la lista??") == 0)
					{
						controller_showFlightsList(excludeLifesonList , pilotsList);
					}

					printf("Podra encontrar el archivo con el nombre: --%s--\n",ARCHIVOVUELOSSINALEXLIFESON);

				break;
				case -1:
					printf("Algo fallo con el guardado del archivo reintente..\n");
				break;
				case -2:
					printf("No se puede guardar una lista vacia, corrobore que la lista tenga algo cargado y guarde..\n");
				break;
				case -3:
					printf("No se pudo encontrar lugar disponible para guardar la lista, reintente..\n");
				break;
			}
		}
		else
		{
			printf("No se pudo crear la lista de vuelos cortos, reintente..\n");
		}

	}
	else
	{
		printf("Algo fallo, reintente..\n");
	}
}
