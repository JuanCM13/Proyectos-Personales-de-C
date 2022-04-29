#include "Nexo.h"

//-----------------------------------------------------------------------------

/** \brief Imprime el menu de opciones y pide y retorna la opcion elegida por el usuario
 *
 * \param int* opcion (donde se retorna la opcion elegida)
 * \return 0 si esta todo ok , -1 fallaron nulls
 *
 */

int imprimirMenu(int* opcion)
{
	int ret;

	ret = -1;

	if(opcion != NULL)
	{

		ret = 0;
		printf("\n\n|---------------------------------------------MENU-------------------------------------------------------------|\n");
		printf("|	1. Cargar archivo Pilotos:                                                                             |\n");
		printf("|	2. Cargar archivo Vuelos:                                                                              |\n");
		printf("|	3. Imprimir vuelos:                                                                                    |\n");
		printf("|	4. Cantidad de pasajeros:                                                                              |\n");
		printf("|	5. Cantidad de pasajeros a China:                                                                      |\n");
		printf("|	6. Filtrar vuelos cortos:                                                                              |\n");
		printf("|	7. Listar vuelos a China:                                                                              |\n");
		printf("|	8. Filtrar a Alex Lifeson:                                                                             |\n");
		printf("|	9. Salir.                                                                                              |\n");
		printf("|--------------------------------------------------------------------------------------------------------------|\n");

		Get_numeroConLimites("Ingrese la opcion del menu..","Error, ingrese una opcion entre las dadas..\n",1,11,opcion);
	}

		return ret;
}

//-----------------------------------------------------------------------------

/** \brief Imprime la lista de vuelos pasada por parametro con su respectivo piloto
 *
 * \param LinkedList* listaVuelos (lista vuelos)
 * \param LinkedList* listaPilotos (lista pilotos)
 * \return 0 si imprime bien la lista , -1 fallaron nulls
 *
 */

int imprimirVuelos(LinkedList* listaVuelos , LinkedList* listaPilotos)
{
	int ret;
	int largo;
	int i;

	eVuelo* auxVuelo;
	int idPilotoAux;

	ePiloto* auxPiloto;

	ret = -1;
	if(listaVuelos != NULL && listaPilotos != NULL)
	{
		largo = ll_len(listaVuelos);

		if(largo > 0)
		{
			printf("\n\n|-----------------------------------------------------------------------------------------------------------------------------------|\n");
			printf("|VUELO     AVION         PILOTO              FECHA               DESTINO          PASAJEROS      HORA SALIDA       HORA LLEGADA     |\n");
			printf("|-----------------------------------------------------------------------------------------------------------------------------------|\n");
			for(i=0 ; i<largo ; i++)
			{
				auxVuelo = ll_get(listaVuelos, i);
				getPilotId(auxVuelo, &idPilotoAux);

				auxPiloto = findPilotId(listaPilotos, idPilotoAux);

				if(auxPiloto != NULL)
				{
					ret = 0;
					mostrarVuelo(auxVuelo , auxPiloto);
				}
			}
			printf("|-----------------------------------------------------------------------------------------------------------------------------------|\n\n");
		}
	}

	return ret;
}

//-----------------------------------------------------------------------------

/** \brief Imprime un vuelo pasado por parametro con su respectivo piloto (nombre)
 *
 * \param eVuelo* vuelo  (dato de tipo eVuelo)
 * \param ePiloto* piloto  (dato de tipo ePiloto)
 * \return 0 si imprime bien , -1 fallaron nulls
 *
 */

int mostrarVuelo(eVuelo* vuelo , ePiloto* piloto)
{
	int ret;

	//vuelo
	int idVuelo;
	int idAvion;
	char fecha[TAMFECHA];
	char destino[TAMDESTINO];
	int pasajeros;
	int horaSalida;
	int horaDeLlegada;

	//piloto
	char nombrePiloto[TAMPILOTOS];


	ret = -1;

	if(vuelo != NULL && piloto != NULL)
	{
		ret = 0;

		getFlightId(vuelo, &idVuelo);
		getPlaneId(vuelo, &idAvion);
		getFlightDate(vuelo, fecha);
		getFlightDestiny(vuelo, destino);
		getFlightPassengers(vuelo, &pasajeros);
		getFlightDepartureTime(vuelo, &horaSalida);
		getFlightArriveTime(vuelo, &horaDeLlegada);

		//--------
		getPilotName(piloto, nombrePiloto);

		printf("|%-10d %-10d %-20s %-20s %-20s %-13d %-18d %-12d |\n",idVuelo , idAvion , nombrePiloto , fecha , destino , pasajeros , horaSalida , horaDeLlegada);
	}

	return ret;
}
