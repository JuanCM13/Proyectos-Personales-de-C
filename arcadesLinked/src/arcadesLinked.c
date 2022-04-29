/*
 ============================================================================
 Name        : arcadesLinked.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "controller.h"

int main(void)
{
	setbuf(stdout, NULL);
	int respuesta;
	int banderaControl;
	int banderaSonido;

	//vars de control
	int respuestaCargaCsv;
	int respuestaCargaSonido;
	int respuestaAgregarArcade;
	int respuestaModificarArcade;
	int respuestaEliminarArcade;
	int respuestaGenerarArchivoJuegos;
	int respuestaListaMultiplayer;
	int respuestaActualizacionLicenciaFichas;

	LinkedList* arcadeList;
	LinkedList* soundList;


	arcadeList = ll_newLinkedList();
	soundList = ll_newLinkedList();


	if(arcadeList != NULL)
	{
		respuesta = 1;
		banderaControl = 0;
		banderaSonido = 0;

		do
		{
			imprimirMenu(&respuesta);

			switch(respuesta)
			{

				case 1:

					if(banderaControl == 0)
					{
						respuestaCargaCsv = controller_readArcadesCsv(arcadeList);

						switch(respuestaCargaCsv)
						{
							case 0:

								printf("\n--La carga de datos del archivo -data.csv- , fue exitosa..\n");
								banderaControl = 1;

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

					if(banderaSonido == 0)
					{
						respuestaCargaSonido = controller_readSoundCsv(soundList);

						switch(respuestaCargaSonido)
						{
							case 0:

								printf("\n--La carga de datos del archivo , fue exitosa..\n");
								banderaSonido = 1;

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

					if(banderaControl == 1 && banderaSonido == 1)
					{
						respuestaAgregarArcade = controller_loadNewArcade(arcadeList);
						switch(respuestaAgregarArcade)
						{
							case 0:

								printf("\n\nEl Arcade fue cargado con exito..\n");
								printf("\nLa lista fue actualizada con exito..\n");

							break;

							case -1:

								printf("Fallaron los nulls..\n");

							break;

							case -2:

								printf("La operacion fue cancelada..\n");

							break;

							case -3:

								printf("No se encontro el archivo donde guardar la lista, reintente..\n");

							break;
						}
					}
					else
					{
						printf("Debe haber cargado el archivo de Arcades para entrar a este campo..\n");
					}

				break;

				case 4:

					if(banderaControl == 1 && banderaSonido == 1)
					{
						if(controller_mostrarArcade(arcadeList , soundList) != 0)
						{
							printf("No se pudo imprimir la lista.. reintente\n");
						}
					}
					else
					{
						printf("Debe haber cargado el archivo de Arcades para entrar a este campo..\n");
					}

				break;

				case 5:

					if(banderaControl == 1 && banderaSonido == 1)
					{
						respuestaModificarArcade = controller_modificarArcade(arcadeList , soundList);

						switch(respuestaModificarArcade)
						{
							case 0:

								printf("\n\nEl Arcade fue modificado con exito..\n");
								printf("\nEl archivo fue modificado con exito..\n");

							break;

							case -1:

								printf("La modificacion fallo, reintente..\n");

							break;

							case -2:

								printf("La operacion fue cancelada..\n");

							break;

							case -3:

								printf("El ID ingresado no se encuentra en la lista, reintente..\n");

							break;

							case -4:

								printf("El archivo ingresado no se encontro.. reintente actualizar el archivo en la opcion 11\n");

							break;
						}
					}
					else
					{
						printf("Debe haber cargado el archivo de Arcades para entrar a este campo..\n");
					}

				break;

				case 6:

					if(banderaControl == 1 && banderaSonido == 1)
					{
						respuestaEliminarArcade = controller_eliminarArcade(arcadeList, soundList);

						switch(respuestaEliminarArcade)
						{
							case 0:

								printf("\n\nEl Arcade fue eliminado de la lista con exito..\n");
								printf("\nEl archivo fue modificado con exito..n");

							break;

							case -1:

								printf("La baja de Arcade fallo, reintente..\n");

							break;

							case -2:

								printf("La operacion fue cancelada..\n");

							break;

							case -3:

								printf("El ID ingresado no se encuentra en la lista, reintente..\n");

							break;

							case -4:

								printf("El archivo ingresado no se encontro.. reintente actualizar el archivo en la opcion 11\n");

							break;
						}
					}
					else
					{
						printf("Debe haber cargado el archivo de Arcades para entrar a este campo..\n");
					}

				break;

				case 7:

					if(banderaControl == 1 && banderaSonido == 1)
					{

						if(controller_ordenarListaArcadesAscendentemente(arcadeList , soundList) != 0)
						{
							printf("El ordenamiento de la lista fallo, reintente..\n");
						}

					}
					else
					{
						printf("Debe haber cargado el archivo de Arcades para entrar a este campo..\n");
					}

				break;

				case 8:

					if(banderaControl == 1 && banderaSonido == 1)
					{
						respuestaGenerarArchivoJuegos = controller_generarArchivoJuegos(arcadeList);

						switch(respuestaGenerarArchivoJuegos)
						{
							case 0:

								printf("\n\nEl archivo de Juegos cargados fue creado con exito..\n");

							break;

							case -1:

								printf("Uuuups algo fallo, reintente..\n");

							break;

							case -2:

								printf("Fallo el guardado del archivo, reintente..\n");

							break;

						}
					}
					else
					{
						printf("Debe haber cargado el archivo de Arcades para entrar a este campo..\n");
					}

				break;

				case 9:

					if(banderaControl == 1 && banderaSonido == 1)
					{
						respuestaListaMultiplayer = controller_generarListaMultijugadores(arcadeList , soundList);

						switch(respuestaListaMultiplayer)
						{
							case 0:

								printf("\n\nEl archivo de Arcades Multijugadores fue creado con exito..\n");

							break;

							case -1:

								printf("Uuuups algo fallo, reintente..\n");

							break;

							case -2:

								printf("Al momento no hay ningun Arcade multijugador, ingrese uno y se generara el archivo..\n");

							break;

							case -3:

								printf("El Archivo ingresado no se encuentra en su ordenador, reintente..\n");

							break;
						}
					}
					else
					{
						printf("Debe haber cargado el archivo de Arcades para entrar a este campo..\n");
					}

				break;

				case 10:

					if(banderaControl == 1 && banderaSonido == 1)
					{
						respuestaActualizacionLicenciaFichas = controller_duplicarFichas(arcadeList, soundList);

						switch(respuestaActualizacionLicenciaFichas)
						{
							case 0:

								printf("\n\nEl archivo junto con la actualizacion de fichas fue guardado con exito..\n");

							break;

							case -1:

								printf("Uuuups algo fallo, reintente..\n");

							break;

							case -2:

								printf("El Archivo ingresado no se encuentra en su ordenador, reintente..\n");

							break;
						}
					}
					else
					{
						printf("Debe haber cargado el archivo de Arcades para entrar a este campo..\n");
					}

				break;
			}

		}while(respuesta != 11);

		printf("\n\n\n *********************************************PROGRAMA FINALIZADO*********************************************\n");

	}



	return 0;
}
