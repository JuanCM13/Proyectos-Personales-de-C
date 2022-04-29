#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Nexo.h"
#include "Parser.h"
#include "LinkedList.h"

#define TAMARCHIVO 100


int controller_loadFlights(LinkedList* listaVuelos);
int controller_loadPilots(LinkedList* listaPilotos);
int controller_imprimirVuelos(LinkedList* listaVuelos , LinkedList* listaPilotos);


int controller_acumularTotalPasajeros(LinkedList* listaVuelos);
int controller_acumularPasajerosAchina(LinkedList* listaVuelos);


int controller_generarListadoVuelosCortos(LinkedList* listaVuelos , LinkedList* listaPilotos);
int controller_generarListadoVuelosChina(LinkedList* listaVuelos , LinkedList* listaPilotos);
int controller_generarListadoExcluyendoAlifesonAlex(LinkedList* listaVuelos , LinkedList* listaPilotos);


int controller_saveAsText(LinkedList* listaVuelos);


#endif /* CONTROLLER_H_ */
