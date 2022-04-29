#include "Controller.h"


//--------------------------------------------------------------------------------------------------------------------------------------

/** \brief Carga los datos de Vuelos desde archivo ingresado por el usuario (modo csv).
 *
 * \param listaVuelos LinkedList*
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se consigue lugar para cargar la lista , -2;
 * //FALLO EL PARSEO DE DATOS ,-4 No se encontro ese archivo
 *
 */

int controller_loadFlights(LinkedList* listaVuelos)
{
	int ret;
	FILE* archivo;
	char path[TAMARCHIVO];

	ret = -1;

	if(listaVuelos != NULL)
	{
		ret = -4; // no se encontro el archivo-

		Get_cadena("Ingrese el archivo .csv de vuelos a cargar..","Error el nombre del archivo no puede ser tan grande..",path , TAMARCHIVO);

		archivo = fopen(path , "r");

		if(archivo != NULL)
		{
			//printf("Abrio el csv\n");
			ret = parser_flightFromText(archivo , listaVuelos);
		}
	}

	return ret;
}


//--------------------------------------------------------------------------------------------------------------------------------------

/** \brief Carga los datos de Pilotos desde archivo ingresado por el usuario (modo csv).
 *
 * \param listaPilotos LinkedList*
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se consigue lugar para cargar la lista , -2;
 * //FALLO EL PARSEO DE DATOS ,-4 No se encontro ese archivo
 *
 */

int controller_loadPilots(LinkedList* listaPilotos)
{
	int ret;
	FILE* archivo;
	char path[TAMARCHIVO];

	ret = -1;

	if(listaPilotos != NULL)
	{
		ret = -4; // no se encontro el archivo-

		Get_cadena("Ingrese el archivo .csv de pilotos a cargar..","Error el nombre del archivo no puede ser tan grande..",path , TAMARCHIVO);

		archivo = fopen(path , "r");

		if(archivo != NULL)
		{
			//printf("Abrio el csv\n");
			ret = parser_pilotsFromText(archivo , listaPilotos);
		}
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------

/** \brief Imprime la lista de vuelos junto con su debido piloto (nombre)
 * \param listaVuelos LinkedList* (lista vuelos)
 * \param listaPilotos LinkedList* (lista pilotos)
 * \return -1 si imprimio mal
 *
 */

int controller_imprimirVuelos(LinkedList* listaVuelos , LinkedList* listaPilotos)
{
	int ret;

	ret = -1;

	if(listaPilotos != NULL && listaVuelos != NULL)
	{
		ret = imprimirVuelos(listaVuelos , listaPilotos);
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------

/** \brief Calcula y muestra la cantidad total de pasajeros de todos los vuelos hasta el momento
 * \param listaVuelos LinkedList* (lista vuelos)
 * \return -1 fallan Nulls o no se consiguio calcular el listado sino retorna el acumulado
 *
 */

int controller_acumularTotalPasajeros(LinkedList* listaVuelos)
{
	int acumulador;
	int ret;

	acumulador = -1;

	if(listaVuelos != NULL)
	{
		acumulador = ll_count(listaVuelos, contadorPasajerosTotales);

		if(acumulador != -1)
		{
			ret = 0;
			printf("Pasajeros Totales Hasta el Momento:\n%d\n",acumulador);
		}
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------

/** \brief Calcula y muestra la cantidad total de pasajeros en vuelos hacia CHINA hasta el momento..
 * \param listaVuelos LinkedList* (lista vuelos)
 * \return -1 fallan Nulls o no se consiguio calcular el listado sino retorna el acumulado
 *
 */

int controller_acumularPasajerosAchina(LinkedList* listaVuelos)
{
	int acumulador;

	acumulador = -1;

	if(listaVuelos != NULL)
	{
		acumulador = ll_count(listaVuelos, contadorPasajerosAchina);

		if(acumulador > 0)
		{
			printf("Pasajeros Totales Hasta el Momento A CHINA:\n%d\n",acumulador);
		}
	}

	return acumulador;
}

//--------------------------------------------------------------------------------------------------------------------------------------

/** \brief Genera listado de vuelos cortos (de menos de 3 hs de duracion) y guarda este creando o guardando en archivo ingresado por el usuario
 * \param listaVuelos LinkedList* (lista vuelos)
 * \param listaPilotos LinkedList* (lista pilotos)
 * \return -1 fallan Nulls, -2 si no se logra guardar el archivo, -3 si no se logro generar el listado. 0 si genero el listado y lo guardo bien
 *
 */

int controller_generarListadoVuelosCortos(LinkedList* listaVuelos , LinkedList* listaPilotos)
{
	int ret;
	LinkedList* listaVuelosCortos;

	ret = -1;

	if(listaVuelos != NULL && listaPilotos != NULL)
	{
		ret = -3; //No se pudo generar el listado
		listaVuelosCortos = ll_filter(listaVuelos, filtrarVuelosCortos);

		if(listaVuelosCortos != NULL)
		{
			if(controller_saveAsText(listaVuelosCortos) == 0)
			{
				ret = 0;
				if(QueresSeguir("Desea imprimir el listado generado? s/n") == 0)
				{
					imprimirVuelos(listaVuelosCortos, listaPilotos);
				}
			}
			else
			{
				ret = -2;
			}
		}
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------

/** \brief Genera listado de vuelos con destino a CHINA
 * \param listaVuelos LinkedList* (lista vuelos)
 * \param listaPilotos LinkedList* (lista pilotos)
 * \return -1 fallan Nulls, -2 si no se logra guardar el listado. 0 si genero el listado
 *
 */

int controller_generarListadoVuelosChina(LinkedList* listaVuelos , LinkedList* listaPilotos)
{
	int ret;
	LinkedList* listaVuelosChina;

	ret = -1;

	if(listaVuelos != NULL && listaPilotos != NULL)
	{
		ret = -2; //No se pudo generar el listado
		listaVuelosChina = ll_filter(listaVuelos, filtrarVuelosAchina);

		if(listaVuelosChina != NULL)
		{
			ret = 0;
			printf("Listado Vuelos a CHINA..\n");
			imprimirVuelos(listaVuelosChina, listaPilotos);
		}
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------

/** \brief Genera listado de vuelos que no conduce Alex Lifeson
 * \param listaVuelos LinkedList* (lista vuelos)
 * \param listaPilotos LinkedList* (lista pilotos)
 * \return -1 fallan Nulls, -2 si no se logra guardar el listado. 0 si genero el listado
 *
 */

int controller_generarListadoExcluyendoAlifesonAlex(LinkedList* listaVuelos , LinkedList* listaPilotos)
{
	int ret;
	LinkedList* listaVuelosSinAlexLifeson;

	ret = -1;

	if(listaVuelos != NULL && listaPilotos != NULL)
	{
		ret = -2; //No se pudo generar el listado
		listaVuelosSinAlexLifeson = ll_filter(listaVuelos, filtrarVuelosSinAlexLifeson);

		if(listaVuelosSinAlexLifeson != NULL)
		{
			ret = 0;
			printf("Listado Vuelos que no realiza Alex Lifeson..\n");
			imprimirVuelos(listaVuelosSinAlexLifeson, listaPilotos);
		}
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------

/** \brief Guarda listado con formato vuelos en archivo ya creado o a crear indicado por el usuario
 * \param listaVuelos LinkedList* (lista vuelos)
 * \return -1 fallan Nulls, -2 no se encontro el archivo ingresado por el usuario,si guardo el listado de manera correcta
 *
 */

int controller_saveAsText(LinkedList* listaVuelos)
{
	int ret;
	int i;
	int largo;
	char path[TAMARCHIVO];
	int opcionGuardado;

	FILE* pFile;

	eVuelo* aux;
	int idVueloAux;
	int idAvionAux;
	int idPilotooAux;
	char fechaAux[TAMFECHA];
	char destinoAux[TAMDESTINO];
	int cantPasajerosAux;
	int horaDespegueAux;
	int horaLlegadaAux;

	ret = -1;

	if(listaVuelos != NULL)
	{
		Get_numeroConLimites("Forma de guardado:\n1-Crear Archivo nuevo\n2-Guardar en archivo existente", "Error, elija una opcion dada..", 1, 2, &opcionGuardado);

		Get_cadena("Ingrese el archivo .csv a actualizar, la lista junto con la modificacion sera almacenada en este..","Error el nombre del archivo no puede ser tan grande..",path , TAMARCHIVO);

		switch(opcionGuardado)
		{
			case 1:

				pFile = fopen(path ,"w");

				if(pFile != NULL)
				{
					largo = ll_len(listaVuelos);
					fprintf(pFile , "ID VUELO,ID AVION,ID PILOTO,FECHA,DESTINO,CANTIDAD PASAJEROS,HORA SALIDA,HORA DESPEGUE\n");
					for(i=0 ; i<largo ; i++)
					{
						aux = (eVuelo*) ll_get(listaVuelos , i);

						getFlightId(aux, &idVueloAux);
						getPlaneId(aux, &idAvionAux);
						getPilotId(aux, &idPilotooAux);
						getFlightDate(aux, fechaAux);
						getFlightDestiny(aux, destinoAux);
						getFlightPassengers(aux, &cantPasajerosAux);
						getFlightDepartureTime(aux, &horaDespegueAux);
						getFlightArriveTime(aux, &horaLlegadaAux);

						fprintf(pFile , "%d , %d , %d , %s , %s , %d , %d , %d\n" , idVueloAux , idAvionAux , idPilotooAux , fechaAux , destinoAux , cantPasajerosAux , horaDespegueAux , horaLlegadaAux);
						ret = 0;
					}
				}

				fclose(pFile);

			break;

			case 2:

				ret = -2; //No se encontro el archivo
				pFile = fopen( path , "r+");

				if(pFile != NULL)
				{
					largo = ll_len(listaVuelos);
					fprintf(pFile , "ID VUELO,ID AVION,ID PILOTO,FECHA,DESTINO,CANTIDAD PASAJEROS,HORA SALIDA,HORA DESPEGUE\n");
					for(i=0 ; i<largo ; i++)
					{
						aux = (eVuelo*) ll_get(listaVuelos , i);

						getFlightId(aux, &idVueloAux);
						getPlaneId(aux, &idAvionAux);
						getPilotId(aux, &idPilotooAux);
						getFlightDate(aux, fechaAux);
						getFlightDestiny(aux, destinoAux);
						getFlightPassengers(aux, &cantPasajerosAux);
						getFlightDepartureTime(aux, &horaDespegueAux);
						getFlightArriveTime(aux, &horaLlegadaAux);

						fprintf(pFile , "%d , %d , %d , %s , %s , %d , %d , %d\n" , idVueloAux , idAvionAux , idPilotooAux , fechaAux , destinoAux , cantPasajerosAux , horaDespegueAux , horaLlegadaAux);
						ret = 0;
					}
				}

				fclose(pFile);

			break;
		}
	}

    return ret;
}
