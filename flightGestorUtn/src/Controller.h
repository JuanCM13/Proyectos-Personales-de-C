
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Parser.h"

#define ARCHIVOVUELOSCORTOS "vuelosCortos.csv"
#define ARCHIVOVUELOSCHINA "VuelosAchina.csv"
#define ARCHIVOVUELOSSINALEXLIFESON "VuelosSinLifeson.csv"
#define TAMPATH 50


int controller_openFlightsFile(LinkedList* );
int controller_openPilotsFile(LinkedList* );
void controller_showFlightsList(LinkedList* flightsList , LinkedList* pilotsList);
void totalPassengersCounter(LinkedList* flightList);
void passengersToChinaCounter(LinkedList* flightList);
int saveAsText(LinkedList* list , char* fileName);
void shortFlightsList(LinkedList* flightList , LinkedList* pilotsList);
void chinaFlightsList(LinkedList* flightList , LinkedList* pilotsList);
void pilotsListExceptAlexLifeson(LinkedList* flightList , LinkedList* pilotsList);

#endif /* CONTROLLER_H_ */
