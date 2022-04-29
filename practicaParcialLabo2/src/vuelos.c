#include "vuelos.h"

//------------------------------------------------------------------------------------------------------------------------

eVuelo* newFlight(void)
{
	eVuelo* auxiliar;

	auxiliar = NULL;

	auxiliar = (eVuelo*) calloc(1 , sizeof(eVuelo));

	return auxiliar;
}

//------------------------------------------------------------------------------------------------------------------------

eVuelo* flightNewParameters(char* vuelo , char* avion , char* piloto , char* fecha , char* destino , char* canPasajeros , char* horaDespegue , char* horaLlegada)
{
	eVuelo* auxiliar;
	int auxVuelo;
	int auxAvion;
	int auxPiloto;
	char auxFecha[TAMFECHA];
	char auxDestino[TAMDESTINO];
	int auxCantidadPasajeros;
	float auxHrDespegue;
	float auxHrLlegada;

	auxiliar = NULL;

	if(vuelo != NULL && avion != NULL && piloto != NULL && fecha != NULL && destino != NULL && canPasajeros != NULL && horaDespegue != NULL && horaLlegada != NULL)
	{
		 auxiliar = newFlight();

		 if(auxiliar != NULL)
		 {
			 	 if(	 esNumero(vuelo , sizeof(vuelo)) == 0 &&
						 esNumero(avion , sizeof(avion)) == 0 &&
						 esNumero(piloto, sizeof(piloto)) == 0 &&
						 esNumero(canPasajeros, sizeof(canPasajeros)) == 0 &&
						 esFloat(horaDespegue, sizeof(horaDespegue)) == 0 &&
						 esFloat(horaLlegada, sizeof(horaLlegada)) == 0 &&
						 sonLetras(destino, sizeof(destino)) == 0  )
			 	 {
			 		auxVuelo = atoi(vuelo);
			 		auxAvion = atoi(avion);
			 		auxPiloto = atoi(piloto);
			 		auxCantidadPasajeros = atoi(canPasajeros);
			 		auxHrDespegue = atof(horaDespegue);
			 		auxHrLlegada = atof(horaLlegada);
			 		strncpy(auxFecha , fecha , sizeof(auxFecha));
			 		strncpy(auxDestino , destino , sizeof(auxDestino));

			 		flightSetIdAvion(auxiliar , auxAvion);
			 		flightSetIdAVuelo(auxiliar , auxVuelo);
			 		flightSetIdPilotoPorVuelo(auxiliar , auxPiloto);
			 		flightSetCantidadPasajeros(auxiliar , auxCantidadPasajeros);
			 		flightSetHoraDespegue(auxiliar , auxHrDespegue);
			 		flightSetHoraLlegada(auxiliar , auxHrLlegada);
			 		flightSetFecha(auxiliar , auxFecha);
			 		flightSetDestino(auxiliar , auxDestino);

			 	 }
		 }
	}

	return auxiliar;

}



//------------------------------------------------------------------------------------------------------------------------


//---------------------------INICIO SETTERS-------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------
int flightSetIdAvion(eVuelo* this , int avion)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->idAvion = avion;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------

int flightSetIdAVuelo(eVuelo* this , int vuelo)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->idVuelo = vuelo;
		ret = 0;
	}

	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------


int flightSetIdPilotoPorVuelo(eVuelo* this , int piloto)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->idPilotoVuelo = piloto;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------


int flightSetCantidadPasajeros(eVuelo* this , int cantidadPasajeros)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->cantidadPasajeros = cantidadPasajeros;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------

int flightSetHoraDespegue(eVuelo* this , float horaDespegue)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->horaDespegue = horaDespegue;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------

int flightSetHoraLlegada(eVuelo* this , float horaLlegada)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->horaLlegada = horaLlegada;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------

int flightSetFecha(eVuelo* this , char* fecha)
{
	int ret;

	ret = -1;

	if(this != NULL && fecha != NULL)
	{
		strcpy(this->fecha , fecha);
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------

int flightSetDestino(eVuelo* this , char* destino)
{
	int ret;

	ret = -1;

	if(this != NULL && destino != NULL)
	{
		strcpy(this->destino , destino);
		ret = 0;
	}

	return ret;
}

//-------------------------------------------------------------------------------------------------------------------------


//---------------------------FIN SETTERS-------------------------------------------------------------------------------



//-------------------------------------------------------------------------------------------------------------------------
