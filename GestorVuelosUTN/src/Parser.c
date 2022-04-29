#include "Parser.h"

//------------------------------------------------------------------------------------------------------------------------------

/** \brief Parsea los datos del archivo de vuelos pasado por parametro (modo csv).
 *
 * \param pFile FILE* (archivo)
 * \param listaVuelos LinkedList* (lista vuelos)
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se consigue lugar para cargar la lista , -2;
 * /FALLO EL PARSEO DE DATOS ,-4 No se encontro ese archivo
 */

int parser_flightFromText(FILE* pFile , LinkedList* listaVuelos)
{

	int ret;
	char auxIdVuelo[100];
	char auxIdAvion[100];
	char auxIdPiloto[100];
	char auxFecha[100];
	char auxDestino[100];
	char auxCantPasajeros[100];
	char auxHoraDespegue[100];
	char auxHoraLlegada[100];
	eVuelo* vuelo;

	ret = -1;

	if(pFile != NULL && listaVuelos != NULL)
	{
		//printf("Entre al parser..\n");
		ret = 0;

		fscanf(pFile , "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n" , auxIdVuelo , auxIdAvion , auxIdPiloto , auxFecha , auxDestino , auxCantPasajeros , auxHoraDespegue , auxHoraLlegada);

		while(!feof(pFile))
		{
			if(fscanf(pFile , "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n" , auxIdVuelo , auxIdAvion , auxIdPiloto , auxFecha , auxDestino , auxCantPasajeros , auxHoraDespegue , auxHoraLlegada) == 8)
			{
				//printf(" %s  %s  %s  %s %s \n", auxiliarId , auxiliarTitulo , auxiliarAutor , auxiliarPrecio , auxiliarIdEditorial);

				if(validarParametrosVuelo(auxIdVuelo , auxIdAvion , auxIdPiloto , auxFecha , auxDestino , auxCantPasajeros , auxHoraDespegue , auxHoraLlegada) == 0)
				{
					vuelo = newFlight_parameters(auxIdVuelo , auxIdAvion , auxIdPiloto , auxFecha , auxDestino , auxCantPasajeros , auxHoraDespegue , auxHoraLlegada);

					if(vuelo != NULL)
					{
						printf(" %d - %d - %d - %s - %s - %d - %d - %d \n",vuelo->idVuelo , vuelo->idAvion , vuelo->idPiloto , vuelo->fecha , vuelo->destino , vuelo->cantPasajeros , vuelo->horaDespegue , vuelo->horaLlegada );
						ll_add( listaVuelos , vuelo);
					}
					else
					{
						ret = -3;
						break;
					}
				}
				else
				{
					ret = -2;
				}
			}
			else
			{
				ret = -2;
				break;
			}

		}

	}

    return ret;
}

//------------------------------------------------------------------------------------------------------------------------------

/** \brief Parsea los datos del archivo de pilotos pasado por parametro (modo csv).
 *
 * \param pFile FILE* (archivo)
 * \param listaPilotos LinkedList* (lista pilotos)
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se consigue lugar para cargar la lista , -2;
 * /FALLO EL PARSEO DE DATOS ,-4 No se encontro ese archivo
 */

int parser_pilotsFromText(FILE* pFile , LinkedList* listaPilotos)
{

	int ret;
	char auxIdPiloto[100];
	char nombrePiloto[TAMPILOTOS];

	ePiloto* piloto;

	ret = -1;

	if(pFile != NULL && listaPilotos != NULL)
	{
		//printf("Entre al parser..\n");

		fscanf(pFile , "%[^,], %[^\n]\n" , auxIdPiloto , nombrePiloto);
		while(!feof(pFile))
		{
			if(fscanf(pFile , "%[^,], %[^\n]\n" , auxIdPiloto , nombrePiloto) == 2)
			{
				//printf(" %s  %s  %s  %s %s \n", auxiliarId , auxiliarTitulo , auxiliarAutor , auxiliarPrecio , auxiliarIdEditorial);

				if(validarParametrosPilotos(auxIdPiloto, nombrePiloto) == 0)
				{
					piloto = newPilot_parameters(auxIdPiloto, nombrePiloto);

					if(piloto != NULL)
					{
						ret = 0;
						printf("%d -- %s \n",piloto->idPiloto , piloto->nombrePiloto);
						ll_add( listaPilotos , piloto);
					}
					else
					{
						ret = -3;
						break;
					}
				}
				else
				{
					ret = -2;
				}
			}
			else
			{
				ret = -2;
				break;
			}

		}

	}

    return ret;
}

//------------------------------------------------------------------------------------------------------------------------------

/** \brief Valida si los parametros recibidos sacados del archivo de vuelos estan bien cargados (que sean solo numeros, etc).
 *
 * \param char* idVuelo
 * \param char* idAvion
 * \param  char* idPiloto
 * \param char* fecha
 * \param char*destino
 * \param char*cantPasajeros
 * \param char*horaSalida
 * \param char*horaLlegada
 * \return 0 si los datos estan ok , -1 fallan nulls o algun dato esta mal validado
 *
 */

int validarParametrosVuelo(char* idVuelo, char* idAvion, char* idPiloto, char* fecha, char* destino, char* cantPasajeros,char* horaSalida, char* horaLlegada)
{
	int ret;

	ret = -1;

	if(idVuelo != NULL && idAvion != NULL && idPiloto != NULL && fecha != NULL && destino != NULL && cantPasajeros != NULL && horaSalida != NULL && horaLlegada != NULL)
	{
		if(esNumero(idVuelo , sizeof(idVuelo)) == 0)
		{
			ret = 0;
		}

		ret = -1;

		if(esNumero(idAvion , sizeof(idAvion)) == 0)
		{
			ret = 0;
		}

		ret = -1;

		if(esNumero(idPiloto , sizeof(idPiloto)) == 0)
		{
			ret = 0;
		}

		ret = -1;

		if(esFecha(fecha, sizeof(fecha)) == 0)
		{
			ret = 0;
		}

		ret = -1;

		if(sonLetras(destino , strlen(destino)) == 0)
		{
			//printf("Parse bien el titulo\n");
			ret = 0;
		}

		ret = -1;

		if(esNumero(cantPasajeros , sizeof(cantPasajeros)) == 0)
		{
			ret = 0;
		}

		ret = -1;

		if(esNumero(horaSalida , sizeof(horaSalida)) == 0)
		{
			ret = 0;
		}

		ret = -1;

		if(esNumero(horaLlegada , sizeof(horaLlegada)) == 0)
		{
			ret = 0;
		}
	}

	return ret;
}


//------------------------------------------------------------------------------------------------------------------------------

/** \brief Valida si los parametros recibidos sacados del archivo de pilotos estan bien cargados (que sean solo numeros, etc).
 *
 * \param char* idPiloto
 * \param char* nombreDelPiloto
 * \return 0 si los datos estan ok , -1 fallan nulls o algun dato esta mal validado
 *
 */

int validarParametrosPilotos(char* idPiloto , char* nombreDelPiloto)
{
	int ret;

	ret = -1;

	if(idPiloto != NULL && nombreDelPiloto != NULL)
	{
		if(esNumero(idPiloto , sizeof(idPiloto)) == 0)
		{
			ret = 0;
		}

		ret = -1;

		if(sonLetras(nombreDelPiloto, strlen(nombreDelPiloto)) == 0)
		{
			ret = 0;
		}
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------


