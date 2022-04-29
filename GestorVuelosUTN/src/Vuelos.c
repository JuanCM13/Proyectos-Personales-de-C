#include "Vuelos.h"


//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Crea un dato de tipo eVuelo* en memoria dinamica
 *
 * \param void
 * \return el auxiliar creado o NULL si no se consiguio espacio
 *
 */

eVuelo* newFlight(void)
{
	eVuelo* ret;

	return ret = (eVuelo*) calloc(1,sizeof(eVuelo));

}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief crea un dato de tipo eVuelo* y completa sus campos..
 *
 * \param char* auxIdVuelo (id del vuelo)
 * \param char* auxIdAvion (id del avion)
 * \param char* auxIdPiloto (id del piloto)
 * \param char* auxFecha (fecha del vuelo)
 * \param char*auxDestino (destino del vuelo)
 * \param char*auxCantPasajeros (cantidad de pasajeros del vuelo)
 * \param char*auxHoraSalida (hora de despegue)
 * \param char*auxHoraLlegada (hora de llegada)
 * \return el auxiliar creado o NULL si no se logro crear
 *
 */

eVuelo* newFlight_parameters(char* idVuelo, char* idAvion, char* idPiloto, char* fecha, char* destino, char* cantPasajeros, char* horaSalida, char* horaLlegada)
{
	eVuelo* aux;
	int auxIdVuelo;
	int auxIdAvion;
	int auxIdPiloto;
	char auxFecha[TAMFECHA];
	char auxDestino[TAMDESTINO];
	int auxCantPasajeros;
	int auxHoraSalida;
	int auxHoraLlegada;

	aux = NULL;

	if(idVuelo != NULL && idAvion != NULL && idPiloto != NULL && fecha != NULL && destino != NULL && cantPasajeros != NULL && horaSalida != NULL && horaLlegada != NULL)
	{
		aux = newFlight();

		if(aux != NULL)
		{
			auxIdVuelo = atoi(idVuelo);
			auxIdAvion = atoi(idAvion);
			auxIdPiloto = atoi(idPiloto);
			strncpy(auxFecha , fecha , sizeof(auxFecha));
			strncpy(auxDestino , destino , sizeof(auxDestino));
			auxCantPasajeros = atoi(cantPasajeros);
			auxHoraSalida = atoi(horaSalida);
			auxHoraLlegada = atoi(horaLlegada);

			setFlightId(aux, auxIdVuelo);
			setPlaneId(aux, auxIdAvion);
			setPilotId(aux, auxIdPiloto);
			setFlightDate(aux, auxFecha);
			setFlightDestiny(aux, auxDestino);
			setFlightPassengers(aux, auxCantPasajeros);
			setFlightDepartureTime(aux, auxHoraSalida);
			setFlightArriveTime(aux, auxHoraLlegada);
		}
	}

	return aux;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------------------------------------

//                        ************************************GETTERS*********************************
//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief retorna el id del vuelo del dato de tipo eVuelo pasado por parametro...
 *
 * \param eVuelo* this (dato de tipo eVuelo)
 * \param *idVuelo (espacio donde se va a almacenar y retornar el id del vuelo)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */

int getFlightId(eVuelo* this , int* idVuelo)
{
	int ret;

	ret = -1;

	if(this != NULL && idVuelo != NULL)
	{
		ret = 0;
		*idVuelo = this->idVuelo;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief retorna el id del avion del dato de tipo eVuelo pasado por parametro...
 *
 * \param eVuelo* this (dato de tipo eVuelo)
 * \param *idAvion (espacio donde se va a almacenar y retornar el id del avion)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */

int getPlaneId(eVuelo* this , int* idAvion)
{
	int ret;

	ret = -1;

	if(this != NULL && idAvion != NULL)
	{
		ret = 0;
		*idAvion = this->idAvion;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief retorna el id del piloto del dato de tipo eVuelo pasado por parametro...
 *
 * \param eVuelo* this (dato de tipo eVuelo)
 * \param *idPiloto (espacio donde se va a almacenar y retornar el id del piloto)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */

int getPilotId(eVuelo* this , int* idPiloto)
{
	int ret;

	ret = -1;

	if(this != NULL && idPiloto != NULL)
	{
		ret = 0;
		*idPiloto = this->idPiloto;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief retorna la fecha del vuelo del dato de tipo eVuelo pasado por parametro...
 *
 * \param eVuelo* this (dato de tipo eVuelo)
 * \param *fecha (espacio donde se va a almacenar y retornar la fecha del vuelo)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */

int getFlightDate(eVuelo* this , char* fecha)
{
	int ret;

	ret = -1;

	if(this != NULL && fecha != NULL)
	{
		ret = 0;
		strcpy(fecha , this->fecha);
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief retorna el destino del vuelo del dato de tipo eVuelo pasado por parametro...
 *
 * \param eVuelo* this (dato de tipo eVuelo)
 * \param *destino (espacio donde se va a almacenar y retornar el destino del vuelo)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */

int getFlightDestiny(eVuelo* this , char* destino)
{
	int ret;

	ret = -1;

	if(this != NULL && destino != NULL)
	{
		ret = 0;
		strcpy(destino , this->destino);
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief retorna la cantidad de pasajeros del vuelo del dato de tipo eVuelo pasado por parametro...
 *
 * \param eVuelo* this (dato de tipo eVuelo)
 * \param *cantPasajeros (espacio donde se va a almacenar y retornar la cantidad de pasajeros del vuelo)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */

int getFlightPassengers(eVuelo* this , int* cantPasajeros)
{
	int ret;

	ret = -1;

	if(this != NULL && cantPasajeros != NULL)
	{
		ret = 0;
		*cantPasajeros = this->cantPasajeros;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief retorna la hora de despegue del vuelo del dato de tipo eVuelo pasado por parametro...
 *
 * \param eVuelo* this (dato de tipo eVuelo)
 * \param *horaSalida (espacio donde se va a almacenar y retornar la hora de salida del vuelo)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */

int getFlightDepartureTime(eVuelo* this , int* horaSalida)
{
	int ret;

	ret = -1;

	if(this != NULL && horaSalida != NULL)
	{
		ret = 0;
		*horaSalida = this->horaDespegue;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief retorna la hora de llegada del vuelo del dato de tipo eVuelo pasado por parametro...
 *
 * \param eVuelo* this (dato de tipo eVuelo)
 * \param *horaLlegada (espacio donde se va a almacenar y retornar la hora de llegada del vuelo)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */

int getFlightArriveTime(eVuelo* this , int* horaLlegada)
{
	int ret;

	ret = -1;

	if(this != NULL && horaLlegada != NULL)
	{
		ret = 0;
		*horaLlegada = this->horaLlegada;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

//                        ************************************FIN GETTERS*********************************
//--------------------------------------------------------------------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------------------------------------------------------------------

//                        ************************************SETTERS*********************************
//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief asigna el id del vuelo a un dato de tipo eVuelo ..
 *
 * \param eVuelo* this (dato de tipo eVuelo)
 * \param idVuelo (id del vuelo)
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */

int setFlightId(eVuelo* this , int idVuelo)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->idVuelo = idVuelo;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief asigna el id del avion a un dato de tipo eVuelo ..
 *
 * \param eVuelo* this (dato de tipo eVuelo)
 * \param idAvion (id del avion)
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */

int setPlaneId(eVuelo* this , int idAvion)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->idAvion = idAvion;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief asigna el id del piloto a un dato de tipo eVuelo ..
 *
 * \param eVuelo* this (dato de tipo eVuelo)
 * \param idPiloto (id del piloto)
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */

int setPilotId(eVuelo* this , int idPiloto)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->idPiloto = idPiloto;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief asigna la fecha de un vuelo a un dato de tipo eVuelo ..
 *
 * \param eVuelo* this (dato de tipo vuelo)
 * \param fecha (fecha del vuelo)
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */

int setFlightDate(eVuelo* this , char* fecha)
{
	int ret;

	ret = -1;

	if(this != NULL && fecha != NULL)
	{
		ret = 0;
		strcpy(this->fecha , fecha);
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief asigna el destino de un vuelo a un dato de tipo eVuelo ..
 *
 * \param eVuelo* this (dato de tipo vuelo)
 * \param destino (destino del vuelo)
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */

int setFlightDestiny(eVuelo* this , char* destino)
{
	int ret;

	ret = -1;

	if(this != NULL && destino != NULL)
	{
		ret = 0;
		strcpy(this->destino , destino);
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief asigna la cantidad de pasajeros de un vuelo a un dato de tipo eVuelo ..
 *
 * \param eVuelo* this (dato de tipo vuelo)
 * \param cantPasajeros (cantidad de pasajeros del vuelo)
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */

int setFlightPassengers(eVuelo* this , int cantPasajeros)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->cantPasajeros = cantPasajeros;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief asigna la hora de despegue de un vuelo a un dato de tipo eVuelo ..
 *
 * \param eVuelo* this (dato de tipo vuelo)
 * \param horaSalida (hora de despegue del vuelo)
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */

int setFlightDepartureTime(eVuelo* this , int horaSalida)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->horaDespegue = horaSalida;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief asigna la hora de llegada de un vuelo a un dato de tipo eVuelo ..
 *
 * \param eVuelo* this (dato de tipo vuelo)
 * \param horaLlegada (hora de llegada del vuelo)
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */

int setFlightArriveTime(eVuelo* this , int horaLlegada)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->horaLlegada = horaLlegada;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

//                        ************************************FIN SETTERS*********************************
//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief devuelve la cantidad de pasajeros de un vuelo recibido por parametro ..
 *
 * \param void* pElement (puntero a void)
 * \return 0 si fallan nulls, sino retorna la cantidad de pasajeros de ese vuelo
 *
 */

int contadorPasajerosTotales(void* pElement)
{
	int ret;
	eVuelo* auxVuelo;
	int cantidadDePasajeros;

	ret = 0;

	if(pElement != NULL)
	{
		auxVuelo = (eVuelo*) pElement;

		getFlightPassengers(auxVuelo, &cantidadDePasajeros);

		ret = cantidadDePasajeros;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief devuelve la cantidad de pasajeros de un vuelo recibido por parametro solo si tiene destino a CHINA ..
 *
 * \param void* pElement (puntero a void)
 * \return 0 si fallan nulls, sino retorna la cantidad de pasajeros de ese vuelo a china
 *
 */

int contadorPasajerosAchina(void* pElement)
{
	int ret;
	eVuelo* auxVuelo;
	char destino[TAMDESTINO];
	int cantPasajeros;

	ret = 0;

	if(pElement != NULL)
	{
		auxVuelo = (eVuelo*) pElement;
		getFlightDestiny(auxVuelo, destino);

		if(strcmp(destino , "China") == 0)
		{
			//printf("Entre a china..\n");
			getFlightPassengers(auxVuelo, &cantPasajeros);
			ret = cantPasajeros;
		}
	}

	return ret;
}

//-----------------------------------------------------------------------------------

/** \brief Calcula la duracion del vuelo, si dura menos de 3hs devuelve 1 sino devuelve 0 ..
 *
 * \param void* pElement (puntero a void)
 * \return 1 si dura menos de 3hs devuelve 1 sino devuelve 0
 *
 */

int filtrarVuelosCortos(void* pElement)
{
	int ret;
	eVuelo* auxVuelo;
	int horaLlegada;
	int horaDespegue;

	ret = 0; //No se agrega a la lista

	if(pElement != NULL)
	{
		auxVuelo = (eVuelo*) pElement;

		getFlightDepartureTime(auxVuelo, &horaDespegue);
		getFlightArriveTime(auxVuelo, &horaLlegada);

		if( (horaLlegada - horaDespegue) < 3)
		{
			ret = 1;
		}
	}

	return ret;
}

//-----------------------------------------------------------------------------------

/** \brief Corrobora si un vuelo tiene destino a china, si es asi devuelve 1 de lo contrario 0 ..
 *
 * \param void* pElement (puntero a void)
 * \return 1 si el vuelo va a china, sino 0
 *
 */

int filtrarVuelosAchina(void* pElement)
{
	int ret;
	eVuelo* auxVuelo;
	char destinoAux[TAMDESTINO];

	ret = 0; //No se agrega a la lista

	if(pElement != NULL)
	{
		auxVuelo = (eVuelo*) pElement;
		getFlightDestiny(auxVuelo, destinoAux);

		if(strcmp(destinoAux , "China") == 0)
		{
			ret = 1;
		}
	}

	return ret;
}

//-----------------------------------------------------------------------------------

/** \brief Corrobora si un vuelo no tiene como piloto a Alex Lifeson, si no lo tiene devuelve 1 de lo contrario devuelve 0..
 *
 * \param void* pElement (puntero a void)
 * \return 0 si el vuelo lo maneja Alex Lifeson , sino devuelve 1
 *
 */

int filtrarVuelosSinAlexLifeson(void* pElement)
{
	int ret;
	eVuelo* auxVuelo;
	int idPiloto;

	ret = 0; //No se agrega a la lista

	if(pElement != NULL)
	{
		auxVuelo = (eVuelo*) pElement;
		getPilotId(auxVuelo, &idPiloto);

		if(idPiloto != 1)
		{
			ret = 1;
		}
	}

	return ret;
}
