/*
 ============================================================================
 Name        : proyectoVuelosRepaso.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Inform.h"

int main(void)
{
	setbuf(stdout , NULL);
	LinkedList* flightsList;
	LinkedList* pilotsList;

	int flightsListLoadStatus;
	int pilotsListLoadStatus;

	int menuOption;
	char exit;

	flightsList = ll_newLinkedList();
	pilotsList = ll_newLinkedList();

	exit = 'n';
	flightsListLoadStatus = 0;
	pilotsListLoadStatus = 0;

	if(flightsList != NULL && pilotsList != NULL)
	{
		do
		{
			printMenu(&menuOption);

			switch(menuOption)
			{
				case 1:
					if(flightsListLoadStatus == 0)
					{
						InformOptionOne(flightsList, &flightsListLoadStatus);
					}
					else
					{
						printf("Ya ha cargado un archivo de vuelos en el programa, reinicie para ejecutar otro...\n");
					}
				break;
				case 2:
					if(pilotsListLoadStatus == 0)
					{
						InformOptionTwo(pilotsList, &pilotsListLoadStatus);
					}
					else
					{
						printf("Ya ha cargado un archivo de pilotos en el programa, reinicie para ejecutar otro...\n");
					}
				break;
				case 3:
					if(pilotsListLoadStatus == 1 && flightsListLoadStatus == 1)
					{
						InformOptionThree(flightsList, pilotsList);
					}
					else
					{
						printf("Debe haber cargado tanto el archivo de vuelos como el de pilotos, para ingresar a esta opcion...\n");
					}
				break;
				case 4:
					if(pilotsListLoadStatus == 1 && flightsListLoadStatus == 1)
					{
						InformOptionFour(flightsList);
					}
					else
					{
						printf("Debe haber cargado tanto el archivo de vuelos como el de pilotos, para ingresar a esta opcion...\n");
					}
				break;
				case 5:
					if(pilotsListLoadStatus == 1 && flightsListLoadStatus == 1)
					{
						InformOptionFive(flightsList);
					}
					else
					{
						printf("Debe haber cargado tanto el archivo de vuelos como el de pilotos, para ingresar a esta opcion...\n");
					}
				break;
				case 6:
					if(pilotsListLoadStatus == 1 && flightsListLoadStatus == 1)
					{
						InformOptionSix(flightsList , pilotsList);
					}
					else
					{
						printf("Debe haber cargado tanto el archivo de vuelos como el de pilotos, para ingresar a esta opcion...\n");
					}
				break;
				case 7:
					if(pilotsListLoadStatus == 1 && flightsListLoadStatus == 1)
					{
						InformOptionSeven(flightsList , pilotsList);
					}
					else
					{
						printf("Debe haber cargado tanto el archivo de vuelos como el de pilotos, para ingresar a esta opcion...\n");
					}
				break;
				case 8:
					if(pilotsListLoadStatus == 1 && flightsListLoadStatus == 1)
					{
						InformOptionEight(flightsList , pilotsList);
					}
					else
					{
						printf("Debe haber cargado tanto el archivo de vuelos como el de pilotos, para ingresar a esta opcion...\n");
					}
				break;
				case 9:
					if(pilotsListLoadStatus == 1 && flightsListLoadStatus == 1)
					{
						InformOptionNine(flightsList , pilotsList);
					}
					else
					{
						printf("Debe haber cargado tanto el archivo de vuelos como el de pilotos, para ingresar a esta opcion...\n");
					}
				break;
				case 10:
					if(pilotsListLoadStatus == 1 && flightsListLoadStatus == 1)
					{
						InformOptionTen(flightsList , pilotsList);
					}
					else
					{
						printf("Debe haber cargado tanto el archivo de vuelos como el de pilotos, para ingresar a esta opcion...\n");
					}
				break;
				case 11:
					if(pilotsListLoadStatus == 1 && flightsListLoadStatus == 1)
					{
						InformOptionEleven(flightsList , pilotsList);
					}
					else
					{
						printf("Debe haber cargado tanto el archivo de vuelos como el de pilotos, para ingresar a esta opcion...\n");
					}
				break;
				case 12:
					if(QueresSeguir("Seguro que desea salir? s/n") == 0)
					{
						exit = 's';
					}
				break;
			}

		}while(exit != 's');
	}




}
