
#ifndef VUELOS_H_
#define VUELOS_H_

#include "input.h"

#define TAMFECHA 11
#define TAMDESTINO 50

typedef struct
{
	int idVuelo;
	int idAvion;
	int idPiloto;
	char fecha[TAMFECHA];
	char destino[TAMDESTINO];
	int cantPasajeros;
	int horaDespegue;
	int horaLlegada;

}eVuelo;

eVuelo* newFlight(void);
eVuelo* newFlight_parameters(char* idVuelo, char* idAvion, char* idPiloto, char* fecha, char* destino, char* cantPasajeros, char* horaSalida, char* horaLlegada);


//GETTERS
int getFlightId(eVuelo* this , int* idVuelo);
int getPlaneId(eVuelo* this , int* idAvion);
int getPilotId(eVuelo* this , int* idPiloto);
int getFlightDate(eVuelo* this , char* fecha);
int getFlightDestiny(eVuelo* this , char* destino);
int getFlightPassengers(eVuelo* this , int* cantPasajeros);
int getFlightDepartureTime(eVuelo* this , int* horaSalida);
int getFlightArriveTime(eVuelo* this , int* horaLlegada);


//SETTERS
int setFlightId(eVuelo* this , int idVuelo);
int setPlaneId(eVuelo* this , int idAvion);
int setPilotId(eVuelo* this , int idPiloto);
int setFlightDate(eVuelo* this , char* fecha);
int setFlightDestiny(eVuelo* this , char* destino);
int setFlightPassengers(eVuelo* this , int cantPasajeros);
int setFlightDepartureTime(eVuelo* this , int horaSalida);
int setFlightArriveTime(eVuelo* this , int horaLlegada);


int contadorPasajerosTotales(void* pElement);
int contadorPasajerosAchina(void* pElement);


int filtrarVuelosCortos(void* pElement);
int filtrarVuelosAchina(void* pElement);
int filtrarVuelosSinAlexLifeson(void* pElement);


#endif /* VUELOS_H_ */
