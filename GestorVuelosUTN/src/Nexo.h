

#ifndef NEXO_H_
#define NEXO_H_

#include "Vuelos.h"
#include "Pilotos.h"


int imprimirMenu(int* opcion);

int imprimirVuelos(LinkedList* listaVuelos , LinkedList* listaPilotos);
int mostrarVuelo(eVuelo* vuelo , ePiloto* piloto);


#endif /* NEXO_H_ */
