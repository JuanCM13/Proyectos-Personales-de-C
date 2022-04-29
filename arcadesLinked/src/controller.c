
#include "controller.h"

//------------------------------------------------------------------------------------------------------------------------------------------

int controller_readArcadesCsv(LinkedList* this)
{
	int ret;
	char path[TAMARCHIVO];
	FILE* archivo;

	ret = -1;

	if(this != NULL)
	{
		ret = -4; // no se encontro el archivo-

		Get_cadena("Ingrese el archivo .csv a abrir..","Error el nombre del archivo no puede ser tan grande..",path , TAMARCHIVO);

		archivo = fopen(path , "r");

		if(archivo != NULL)
		{
			//printf("Abrio el csv\n");
			ret = parser_arcadeFromText(archivo , this);
		}

	}

	return ret;

}

//------------------------------------------------------------------------------------------------------------------------------------------

int controller_readSoundCsv(LinkedList* this)
{
	int ret;
	char path[TAMARCHIVO];
	FILE* archivo;

	ret = -1;

	if(this != NULL)
	{
		ret = -4; // no se encontro el archivo-

		Get_cadena("Ingrese el archivo de sonido a abrir..","Error el nombre del archivo no puede ser tan grande..",path , TAMARCHIVO);

		archivo = fopen(path , "r");

		if(archivo != NULL)
		{
			//printf("Abrio el csv\n");
			ret = parser_soundFromText(archivo , this);
		}

	}

	return ret;

}

//------------------------------------------------------------------------------------------------------------------------------------------

int controller_loadNewArcade(LinkedList* this)
{
	int ret;
	FILE* archivo;
	int contador;
	eArcade* auxiliar;


	int nodoAborrar; //solo se usa si no se encuentra el archivo donde guardar

	ret = -1;

	if(this != NULL)
	{
		archivo = fopen("Contador.txt","r");

		if(archivo == NULL)
		{
			archivo = fopen("Contador.txt" , "w");

			if(archivo != NULL)
			{
				fprintf(archivo , "12");
				fclose(archivo);

				fopen("contador.txt","r");
			}
		}

		if(archivo != NULL)
		{
			parserCounter(archivo , &contador);

			auxiliar = addNewArcade(&contador , &ret);

			fclose(archivo);

			if(auxiliar != NULL && ret == 0)
			{
				ll_add(this, auxiliar); //Sino no se actualiza el archivo, recien despues si vuelvo a guardar se guarda..
				if(controller_saveAsText(this) == 0)
				{
					//ll_add(this, auxiliar); //Asi si no encuentra el archivo no se carga en la lista hasta que ponga bien el nombre..
					archivo = fopen("contador.txt" , "w");
					fprintf(archivo , "%d", contador);
					fclose(archivo);
				}
				else
				{
					nodoAborrar = ll_len(this) -1;

					ll_remove(this, nodoAborrar); //Asi si no se encuentra el archivo si bien el ultimo no se guarda en el archivo queda cargado en la
													//linked list y el usuario si imprime lo ve...
					ret = -3; //No se encontro el archivo donde guardar la lista..
				}
			}
		}
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int controller_saveAsText(LinkedList* pArrayListArcades)
{
	int ret;
	int i;
	int largo;
	char path[TAMARCHIVO];

	int auxId;
	char auxNacionalidad[TAMNACIONALIDAD];
	int auxTipoSonido;
	int auxCantidadJugadores;
	int auxCantidadFichas;
	char auxNombreSala[TAMSALA];
	char auxNombreJuego[TAMJUEGO];
	int opcionGuardado;

	FILE* pFile;
	eArcade* aux;

	aux = NULL;
	ret = -1;

	if(pArrayListArcades != NULL)
	{
		ret = -2;
		largo = 0;

		Get_numeroConLimites("Forma de guardado:\n1-Crear Archivo nuevo\n2-Guardar en archivo existente", "Error, elija una opcion dada..", 1, 2, &opcionGuardado);

		Get_cadena("Ingrese el archivo .csv a actualizar, la lista junto con la modificacion sera almacenada en este..","Error el nombre del archivo no puede ser tan grande..",path , TAMARCHIVO);

		switch(opcionGuardado)
		{
			case 1:

				pFile = fopen(path ,"w");

				if(pFile != NULL)
				{
					largo = ll_len(pArrayListArcades);
					fprintf(pFile , "idArcade,nacionaliadArcade,tipoSonidoArcade,cantidadJugadores,cantidadFichas,nombreSalon,nombreJuego\n");
					for(i=0 ; i<largo ; i++)
					{
						aux = (eArcade*) ll_get(pArrayListArcades , i);

						getArcadeId(aux , &auxId);
						getArcadeNacionalidad(aux , auxNacionalidad);
						getArcadeSound(aux , &auxTipoSonido);
						getArcadeCantFichas(aux , &auxCantidadFichas);
						getArcadeCantJugadores(aux , &auxCantidadJugadores);
						getArcadeSala(aux , auxNombreSala);
						getArcadeNombreJuego(aux , auxNombreJuego);

						fprintf(pFile , "%d , %s , %d , %d , %d , %s , %s\n" , auxId , auxNacionalidad , auxTipoSonido , auxCantidadJugadores , auxCantidadFichas , auxNombreSala , auxNombreJuego);
						//printf(" %d  %s  %d  %d %d %s %s \n", aux->idArcade , aux->nacionalidad , aux->tipoSonido , aux->cantidadJuegadores , aux->capacidadMaximaFichas , aux->nombreSalon , aux->nombreJuego);
						ret = 0;
					}
				}

				fclose(pFile);

			break;

			case 2:

				pFile = fopen( path , "w+"); //cambie el r+ por w+ actualizacion 7/3/2022, haciendo el proyecto de nuevo no andaba con r+

				if(pFile != NULL)
				{
					printf("Entre a guardar...\n");
					ret = -3;
					largo = ll_len(pArrayListArcades);
					fprintf(pFile , "idArcade,nacionaliadArcade,tipoSonidoArcade,cantidadJugadores,cantidadFichas,nombreSalon,nombreJuego\n");
					for(i=0 ; i<largo ; i++)
					{
						aux = (eArcade*) ll_get(pArrayListArcades , i);

						getArcadeId(aux , &auxId);
						getArcadeNacionalidad(aux , auxNacionalidad);
						getArcadeSound(aux , &auxTipoSonido);
						getArcadeCantFichas(aux , &auxCantidadFichas);
						getArcadeCantJugadores(aux , &auxCantidadJugadores);
						getArcadeSala(aux , auxNombreSala);
						getArcadeNombreJuego(aux , auxNombreJuego);

						fprintf(pFile , "%d , %s , %d , %d , %d , %s , %s\n" , auxId , auxNacionalidad , auxTipoSonido , auxCantidadJugadores , auxCantidadFichas , auxNombreSala , auxNombreJuego);
						//printf(" %d  %s  %d  %d %d %s %s \n", aux->idArcade , aux->nacionalidad , aux->tipoSonido , aux->cantidadJuegadores , aux->capacidadMaximaFichas , aux->nombreSalon , aux->nombreJuego);
						ret = 0;
					}
				}

				fclose(pFile);

			break;
		}
	}

    return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int controller_mostrarArcade(LinkedList* listaArcades , LinkedList* listaSonido)
{
	int ret;

	ret = -1;

	if(listaArcades != NULL && listaSonido != NULL)
	{
		ret = imprimirArcades(listaArcades , listaSonido);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int controller_modificarArcade(LinkedList* listaArcades , LinkedList* listaSonido)
{
	int ret;

	ret = -1;

	if(listaArcades != NULL && listaSonido != NULL)
	{
		ret = modificarArcade(listaArcades , listaSonido);

		if(ret == 0)
		{
			ret = -4; //No se encontro el archivo a guardar..
			if(controller_saveAsText(listaArcades) == 0)
			{
				ret = 0;
			}
		}
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int controller_eliminarArcade(LinkedList* listaArcades , LinkedList* listaSonido)
{
	int ret;

	ret = -1;

	if(listaArcades != NULL && listaSonido != NULL)
	{
		ret = bajaArcade(listaArcades, listaSonido);

		if(ret == 0)
		{
			ret = -4; //No se encontro el archivo a guardar..
			if(controller_saveAsText(listaArcades) == 0)
			{
				ret = 0;
			}
		}
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int controller_ordenarListaArcadesAscendentemente(LinkedList* listaArcades , LinkedList* listaSonido)
{
	int ret;

	ret = -1;

	if(listaArcades != NULL && listaSonido != NULL)
	{
		ret = 0;
		ll_sort(listaArcades, ordenarArcadesPorNombreAscendente , 1);
		imprimirArcades(listaArcades, listaSonido);

	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int controller_generarArchivoJuegos(LinkedList* listaArcades)
{
	int ret;
	int i;
	LinkedList* aux;

	char path[TAMARCHIVO];
	FILE* pFile;
	int largoListaJuegos;
	eArcade* auxArcade;
	char auxNombreJuego[TAMJUEGO];

	ret = -1;

	if(listaArcades != NULL)
	{
		aux = crearListaNombresJuegosCargados(listaArcades);

		if(aux != NULL)
		{
			ret = -2; // No se pudo guardar el archivo

			Get_cadena("Ingrese el archivo .csv donde se guardara el archivo..","Error el nombre del archivo no puede ser tan grande..",path , TAMARCHIVO);

			pFile = fopen(path , "w");
			if(pFile != NULL)
			{
				ret = 0;
				largoListaJuegos = ll_len(aux);

				fprintf(pFile , "Lista Juegos ya cargados:\n");

				for(i=0 ; i<largoListaJuegos ; i++)
				{
					auxArcade = ll_get(aux, i);
					getArcadeNombreJuego(auxArcade, auxNombreJuego);

					fprintf(pFile , "-%s\n",auxNombreJuego);
				}
			}
		}

	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int controller_generarListaMultijugadores(LinkedList* listaArcades , LinkedList* listaSonido)
{
	int ret;
	LinkedList* listaMultijugador;

	ret = -1;

	if(listaArcades != NULL && listaSonido != NULL)
	{
		ret = -2; //No hay ningun juego multijugador cargado..

		listaMultijugador = ll_filter(listaArcades, filtrarArcadesMultijugador);

		if(listaMultijugador != NULL)
		{
			ret = -3; //No se encontro la lista donde guardarlo.. solo si elige la opcion de a<ctualizar algun archivo ya creado

			if(controller_saveAsText(listaMultijugador) == 0)
			{
				if(QueresSeguir("Desea imprimir la lista de Arcades MultiPlayer generada?? s/n ") == 0)
				{
					imprimirArcades(listaMultijugador, listaSonido);
				}


				ret = 0;
			}
		}

		ll_deleteLinkedList(listaMultijugador);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------

int controller_duplicarFichas(LinkedList* listaArcades , LinkedList* listaSonido)
{
	int ret;
	LinkedList* aux;

	ret = -1;

	if(listaArcades != NULL && listaSonido != NULL)
	{
		ret = 0;

		aux = ll_map(listaArcades, duplicarFichas);

		if(aux != NULL)
		{
			ret = -2; //No se encontro el archivo seleccionado a actualizar

			if(controller_saveAsText(aux) == 0)
			{
				ret = 0;

				if(QueresSeguir("Desea imprimir la lista de Arcades MultiPlayer generada?? s/n ") == 0)
				{
					imprimirArcades(aux, listaSonido);
				}
			}
		}
	}

	return ret;
}
