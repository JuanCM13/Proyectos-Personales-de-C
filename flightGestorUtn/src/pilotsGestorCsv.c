/*
 ============================================================================
 Name        : pilotsGestorCsv.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Controller.h"

int main(void)
{
	setbuf(stdout , NULL);
	int option;
	int flightsLoadFlag;
	int pilotsLoadFlag;

	LinkedList* flightList;
	LinkedList* pilotsList;

	flightList = ll_newLinkedList();
	pilotsList = ll_newLinkedList();

	if(flightList != NULL && pilotsList != NULL)
	{
		flightsLoadFlag = 0;
		pilotsLoadFlag = 0;
		do
		{
			printMenu(&option);

			switch(option)
			{
				case 1:
					if(flightsLoadFlag == 0)
					{
						if(controller_openFlightsFile(flightList) == 0)
						{
							printf("Entre\n");
							flightsLoadFlag = 1;
						}
					}
					else
					{
						printf("Ya hay un archivo cargado, reinicie el programa para cargar otro archivo de vuelos..\n");
					}
				break;

				case 2:
					if(pilotsLoadFlag == 0)
					{
						if(controller_openPilotsFile(pilotsList) == 0)
						{
							pilotsLoadFlag = 1;
						}
					}
					else
					{
						printf("Ya hay un archivo cargado, reinicie el programa para cargar otro archivo de pilotos..\n");
					}
				break;

				case 3:
					if(pilotsLoadFlag == 1 && flightsLoadFlag == 1)
					{
						controller_showFlightsList(flightList , pilotsList);
					}
					else
					{
						printf("Para ingresar a esta opcion debe haber cargado el archivo de vuelos y pilotos, carguelos y reintente..\n");
					}
				break;

				case 4:
					if(pilotsLoadFlag == 1 && flightsLoadFlag == 1)
					{
						totalPassengersCounter(flightList);
					}
					else
					{
						printf("Para ingresar a esta opcion debe haber cargado el archivo de vuelos y pilotos, carguelos y reintente..\n");
					}
				break;

				case 5:
					if(pilotsLoadFlag == 1 && flightsLoadFlag == 1)
					{
						passengersToChinaCounter(flightList);
					}
					else
					{
						printf("Para ingresar a esta opcion debe haber cargado el archivo de vuelos y pilotos, carguelos y reintente..\n");
					}
				break;

				case 6:
					if(pilotsLoadFlag == 1 && flightsLoadFlag == 1)
					{
						shortFlightsList(flightList , pilotsList);
					}
					else
					{
						printf("Para ingresar a esta opcion debe haber cargado el archivo de vuelos y pilotos, carguelos y reintente..\n");
					}
				break;

				case 7:
					if(pilotsLoadFlag == 1 && flightsLoadFlag == 1)
					{
						chinaFlightsList(flightList , pilotsList);
					}
					else
					{
						printf("Para ingresar a esta opcion debe haber cargado el archivo de vuelos y pilotos, carguelos y reintente..\n");
					}
				break;

				case 8:
					if(pilotsLoadFlag == 1 && flightsLoadFlag == 1)
					{
						pilotsListExceptAlexLifeson(flightList , pilotsList);
					}
					else
					{
						printf("Para ingresar a esta opcion debe haber cargado el archivo de vuelos y pilotos, carguelos y reintente..\n");
					}
				break;
			}

		}while(option != 9);
	}

	printf("\n\n\n\n-----------------------------------------------------------------Programa TERMINADO-----------------------------------------------------------------\n");

}
