

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Parser.h"

#define TAMFILE 100
#define ARCHIVOVUELOSCORTOS "VuelosCortos.csv"
#define VUELOSSINALEXLIFESON "VuelosSinAlexLifeson.csv"
#define ARCHIVOULTIMOIDVUELO "ContadorUltimoVueloCargado.txt"

//--------------------------------------------

int Controller_LoadFlightsFile(LinkedList* );
int Controller_LoadPilotsFile(LinkedList* );
int Controller_PrintFlights(LinkedList*  , LinkedList* );
int Controller_CountPassengers(LinkedList* , int );
int Controller_ShortFlights(LinkedList*  , LinkedList* );
int Controller_ShortFlights(LinkedList*  , LinkedList* );
int Controller_SaveFlightsAsCsv(LinkedList*  , char* );
int Controller_ChinaFlightsList(LinkedList*  , LinkedList* );
int Controller_ExpludePilotFromList(LinkedList*  , LinkedList* );
int Controller_SortListByFlightId(LinkedList*  , LinkedList*  , int );
int Controller_SortListByPilotName(LinkedList*  , LinkedList*  , int );
int Controller_AddNewFlight(LinkedList* pArrayFlight , LinkedList* pArrayPilots);



//--------------------------------------------
#endif /* CONTROLLER_H_ */
