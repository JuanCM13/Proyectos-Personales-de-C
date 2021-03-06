#include "Inform.h"

void InformOptionOne(LinkedList* pArrayFlights , int* statusFlightsLoad)
{
	int result;

	result = Controller_LoadFlightsFile(pArrayFlights);
	switch(result)
	{
		case 0:
			printf("El archivo de vuelos fue cargado de manera exitosa...\n");
			*statusFlightsLoad = 1;
		break;
		case -1:
			printf("Falla de nullidad...\n");
		break;
		case -2:
			printf("El archivo ingresado no se encontro en el sistema...\n");
		break;
		case -3:
			printf("No se pudo parsear algun dato del archivo...\n");
		break;
		case -4:
			printf("Alguno de los datos, vino mal, no paso la validacion...\n");
		break;
		case -5:
			printf("No pudo generarse la estructura de el vuelo, no hay memoria seguramente...\n");
		break;
	}
}

void InformOptionTwo(LinkedList* pArrayPilots , int* statusPilotsLoad)
{
	int result;

	result = Controller_LoadPilotsFile(pArrayPilots);
	switch(result)
	{
		case 0:
			printf("El archivo de pilotos fue cargado de manera exitosa...\n");
			*statusPilotsLoad = 1;
		break;
		case -1:
			printf("Falla de nullidad...\n");
		break;
		case -2:
			printf("El archivo ingresado no se encontro en el sistema...\n");
		break;
		case -3:
			printf("No se pudo parsear algun dato del archivo...\n");
		break;
		case -4:
			printf("Alguno de los datos, vino mal, no paso la validacion...\n");
		break;
		case -5:
			printf("No pudo generarse la estructura de el piloto, no hay memoria seguramente...\n");
		break;
	}
}

void InformOptionThree(LinkedList* pArrayFlights , LinkedList* pArrayPilots)
{
	int result;

	result = Controller_PrintFlights(pArrayFlights, pArrayPilots);
	switch(result)
	{
		case -1:
			printf("Falla de nullidad...\n");
		break;
		case -2:
			printf("Ambas listas deben tener al menos 1 elemento cargado...\n");
		break;
	}
}

void InformOptionFour(LinkedList* pArrayFlights)
{
	int result;

	result = Controller_CountPassengers(pArrayFlights , 0);

	if(result == -1)
	{
		printf("Falla de nuliudad...\n");
	}
}

void InformOptionFive(LinkedList* pArrayFlights)
{
	int result;

	result = Controller_CountPassengers(pArrayFlights , 1);

	if(result == -1)
	{
		printf("Falla de nuliudad...\n");
	}
}

void InformOptionSix(LinkedList* pArrayFlights , LinkedList* pArrayPilots)
{
	int result;

	result = Controller_ShortFlights(pArrayFlights, pArrayPilots);

	switch(result)
	{
		case 0:
			printf("Podra encontrar el archivo con el nombre, %s\n",ARCHIVOVUELOSCORTOS);
		break;
		case -1:
			printf("Falla de nuliudad...\n");
		break;
		case 1:
			printf("La lista fue creada con exito\nPodra encontrar el archivo con el nombre, %s\n",ARCHIVOVUELOSCORTOS);
		break;
		case -2:
			printf("No pudo crearse el archivo, no se encontro memoria... reintente\n");
		break;
	}
}

void InformOptionSeven(LinkedList* pArrayFlights , LinkedList* pArrayPilots)
{
	int result;

	result = Controller_ChinaFlightsList(pArrayFlights, pArrayPilots);

	switch(result)
	{
		case -1:
			printf("Falla de nuliudad...\n");
		break;
	}
}

void InformOptionEight(LinkedList* pArrayFlights , LinkedList* pArrayPilots)
{
	int result;

	result = Controller_ExpludePilotFromList(pArrayFlights, pArrayPilots);

	switch(result)
	{
		case 0:
			printf("Podra encontrar el archivo con el nombre, %s\n",VUELOSSINALEXLIFESON);
		break;
		case -1:
			printf("Falla de nuliudad...\n");
		break;
		case 1:
			printf("La lista fue creada con exito\nPodra encontrar el archivo con el nombre, %s\n",VUELOSSINALEXLIFESON);
		break;
		case -2:
			printf("No pudo crearse el archivo, no se encontro memoria... reintente\n");
		break;
	}
}

void InformOptionNine(LinkedList* pArrayFlights , LinkedList* pArrayPilots)
{
	int result;

	result = Controller_SortListByFlightId(pArrayFlights, pArrayPilots , 1);

	switch(result)
	{
		case 0:
			printf("Lista ordenada con exito...");
		break;
		case -1:
			printf("Falla de nuliudad...\n");
		break;
		case 1:
			printf("Lista ordenada con exito\nPodra visualizar la lista en la opcion 3 del menu..");
		break;
	}
}

void InformOptionTen(LinkedList* pArrayFlights , LinkedList* pArrayPilots)
{
	int result;

	result = Controller_SortListByPilotName(pArrayFlights, pArrayPilots, 1);

	switch(result)
	{
		case 0:
			printf("Lista ordenada con exito...");
		break;
		case -1:
			printf("Falla de nuliudad...\n");
		break;
		case 1:
			printf("Lista ordenada con exito\nPodra visualizar la lista en la opcion 3 del menu..");
		break;
	}
}

void InformOptionEleven(LinkedList* pArrayFlights , LinkedList* pArrayPilots)
{
	int result;

	result = Controller_AddNewFlight(pArrayFlights, pArrayPilots);

	switch(result)
	{
		case 0:
			printf("El elemento fue creado y la lista actualizada con exito...");
		break;
		case -1:
			printf("Falla de nuliudad...\n");
		break;
		case -2:
			printf("No existe el id ingresado...");
		break;
		case -3:
			printf("No se encontro lugar para crear el vuelo...");
		break;
		case -4:
			printf("No existe el id ingresado...");
		break;
	}
}
