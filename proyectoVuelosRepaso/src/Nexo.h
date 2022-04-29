
#ifndef NEXO_H_
#define NEXO_H_

#include "Pilots.h"
#include "Flights.h"

//-------------------------------------------------------------------------------------------------

int printMenu(int* );
int printFlightsData(LinkedList*  , LinkedList*);
int showFlight(eFlight*  , ePilot* );

int isAnyLoaded(LinkedList*  , LinkedList*);
int sortListByPilotName(void*  , void*  , LinkedList* );
int addNewFlight(LinkedList* flightList , LinkedList* pilotList , int flightId);

//-------------------------------------------------------------------------------------------------
#endif /* NEXO_H_ */
