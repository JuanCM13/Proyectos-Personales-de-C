/*
 ============================================================================
 Name        : GestorVuelosUTN.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "Controller.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int banderaControlCargaVuelos;
	int banderaControlCargaPilotos;

	//Controladores
	int respuestaCargaVuelos;
	int respuestaCargaPilotos;
	int respuestaContadorPasajerosAchina;
	int respuestaFiltrarVuelosCortos;
	int respuestaFiltrarVuelosAchina;
	int respuestaFiltrarAlexLifeson;

	LinkedList* listaVuelos;
	LinkedList* listaPilotos;


	listaPilotos = ll_newLinkedList();
	listaVuelos = ll_newLinkedList();

	if(listaPilotos != NULL && listaVuelos != NULL)
	{
		banderaControlCargaVuelos = 0;
		banderaControlCargaPilotos = 0;

		do
		{
			imprimirMenu(&opcion);
			switch(opcion)
			{

				case 1:

					if(banderaControlCargaPilotos == 0)
					{
						respuestaCargaPilotos = controller_loadPilots(listaPilotos);

						switch(respuestaCargaPilotos)
						{
							case 0:

								printf("\n--La carga de datos del archivo de pilotos , fue exitosa..\n");
								banderaControlCargaPilotos = 1;

							break;

							case -1:

								printf("--Fatal error , reintente..\n");

							break;

							case -2:

								printf("--Error no se pudieron recuperar los datos del archivo data.csv..\n");

							break;

							case -3:

								printf("--Error no encontro el archivo data.csv..\n");

							break;

							case -4:

								printf("No se encontro el archivo..\n");

								break;

						}
					}
					else
					{
						printf("--Un archivo ya se encuentra cargado en la lista, reinicie el programa para volver a cargar \nrecuerde antes guardar los cambios en la opcion 8, de lo contrario el progreso sera borrado..\n");
					}

				break;

				case 2:

					if(banderaControlCargaVuelos == 0)
					{
						respuestaCargaVuelos = controller_loadFlights(listaVuelos);

						switch(respuestaCargaVuelos)
						{
							case 0:

								printf("\n--La carga de datos del archivo de vuelos , fue exitosa..\n");
								banderaControlCargaVuelos = 1;

							break;

							case -1:

								printf("--Fatal error , reintente..\n");

							break;

							case -2:

								printf("--Error no se pudieron recuperar los datos del archivo data.csv..\n");

							break;

							case -3:

								printf("--Error no encontro el archivo data.csv..\n");

							break;

							case -4:

								printf("No se encontro el archivo..\n");

								break;

						}
					}
					else
					{
						printf("--Un archivo ya se encuentra cargado en la lista, reinicie el programa para volver a cargar \nrecuerde antes guardar los cambios en la opcion 8, de lo contrario el progreso sera borrado..\n");
					}

				break;

				case 3:

					if(banderaControlCargaPilotos == 1 && banderaControlCargaVuelos == 1)
					{
						if(controller_imprimirVuelos(listaVuelos , listaPilotos) != 0)
						{
							printf("Algo fallo al mostrar el listado de vuelos, por favor reintente...\n");
						}
					}
					else
					{
						printf("Para ingresar a esta opcion ambos archivos -Vuelos y Pilotos- deben estar cargados..\n");
					}

				break;

				case 4:

					if(banderaControlCargaPilotos == 1 && banderaControlCargaVuelos == 1)
					{
						if(controller_acumularTotalPasajeros(listaVuelos) == -1)
						{
							printf("Algo fallo al mostrar el listado de vuelos, por favor reintente...\n");
						}

					}
					else
					{
						printf("Para ingresar a esta opcion ambos archivos -Vuelos y Pilotos- deben estar cargados..\n");
					}

				break;

				case 5:

					if(banderaControlCargaPilotos == 1 && banderaControlCargaVuelos == 1)
					{
						respuestaContadorPasajerosAchina = controller_acumularPasajerosAchina(listaVuelos);
						if(respuestaContadorPasajerosAchina == -1)
						{
							printf("Algo fallo, reintente..");
						}
						else
						{
							if(respuestaContadorPasajerosAchina == -2)
							{
								printf("No hay Vuelos con pasajeros con destino a China cargados al momento...\n");
							}
						}

					}
					else
					{
						printf("Para ingresar a esta opcion ambos archivos -Vuelos y Pilotos- deben estar cargados..\n");
					}

				break;

				case 6:

					if(banderaControlCargaPilotos == 1 && banderaControlCargaVuelos == 1)
					{
						respuestaFiltrarVuelosCortos = controller_generarListadoVuelosCortos(listaVuelos , listaPilotos);
						switch(respuestaFiltrarVuelosCortos)
						{
							case 0:

								printf("El archivo de vuelos cortos fue generado con exito..\nEl archivo fue creado/actualizado con exito..\n");

							break;
							case -1:

								printf("Algo fallo, por favor reintente..\n");

							break;
							case -2:

								printf("El archivo ingresado no se encuentra en su ordenador, reintente..\n");

							break;
							case -3:

								printf("El archivo no pudo generarse de manera adecuada, reintente..\n");

							break;
						}
					}
					else
					{
						printf("Para ingresar a esta opcion ambos archivos -Vuelos y Pilotos- deben estar cargados..\n");
					}

				break;

				case 7:

					if(banderaControlCargaPilotos == 1 && banderaControlCargaVuelos)
					{

						respuestaFiltrarVuelosAchina = controller_generarListadoVuelosChina(listaVuelos , listaPilotos);
						switch(respuestaFiltrarVuelosAchina)
						{
							case -1:

								printf("Algo fallo, por favor reintente..\n");

							break;
							case -2:

								printf("No pudo generarse el listado de vuelos a China reintente..\n");

							break;
						}

					}
					else
					{
						printf("Para ingresar a esta opcion ambos archivos -Vuelos y Pilotos- deben estar cargados..\n");
					}

				break;

				case 8:

					if(banderaControlCargaPilotos == 1 && banderaControlCargaVuelos)
					{

						respuestaFiltrarAlexLifeson = controller_generarListadoExcluyendoAlifesonAlex(listaVuelos , listaPilotos);
						switch(respuestaFiltrarAlexLifeson)
						{
							case -1:

								printf("Algo fallo, por favor reintente..\n");

							break;
							case -2:

								printf("No pudo generarse el listado de vuelos que no realiza Alex Lifeson, reintente..\n");

							break;
						}

					}
					else
					{
						printf("Para ingresar a esta opcion ambos archivos -Vuelos y Pilotos- deben estar cargados..\n");
					}

				break;

			}

		}while(opcion != 9);

		printf("\n\n\n*********************************************PROGRAMA TERMINADO*********************************************");
	}

	return 0;
}
