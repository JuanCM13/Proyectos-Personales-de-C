/*
 * Parser.h
 *
 *  Created on: 6 dic 2021
 *      Author: caand
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "input.h"
#include "Nexo.h"
#include "Nombres.h"

#endif /* PARSER_H_ */


int parser_flightFromText(FILE* pFile , LinkedList* listaVuelos);
int parser_pilotsFromText(FILE* pFile , LinkedList* listaPilotos);


int validarParametrosPilotos(char* idPiloto , char* nombreDelPiloto);
int validarParametrosVuelo(char* idVuelo, char* idAvion, char* idPiloto, char* fecha, char* destino, char* cantPasajeros,char* horaSalida, char* horaLlegada);

