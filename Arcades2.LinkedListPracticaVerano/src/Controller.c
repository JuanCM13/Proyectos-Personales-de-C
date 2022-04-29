#include "Controller.h"

int controller_LoadArcadesData(LinkedList* lista)
{
	char ruta[TAMRUTA];
	FILE* archivo;
	int ret;

	ret = -1; //fallan nulls etc
	if(lista != NULL)
	{
		ret = -5; //no se pudo encontrar el archivo
		Get_cadena("Ingrese el nombre del archivo donde se aloja la data de arcades..", "Error, no puede superar los 100 caracteres", ruta, TAMRUTA);

		archivo = fopen(ruta , "r");

		if(archivo != NULL)
		{
			ret = ParsearDataArcades(lista, archivo);
			fclose(archivo);
		}
	}

	return ret;
}

int controller_LoadSoundData(LinkedList* lista)
{
	char ruta[TAMRUTA];
	FILE* archivo;
	int ret;

	ret = -1; //fallan nulls etc
	if(lista != NULL)
	{
		ret = -5; //no se pudo encontrar el archivo
		Get_cadena("Ingrese el nombre del archivo donde se aloja la data de sonido..", "Error, no puede superar los 100 caracteres", ruta, TAMRUTA);

		archivo = fopen(ruta , "r");

		if(archivo != NULL)
		{
			ret = ParsearDataSound(lista, archivo);
		}

		fclose(archivo);
	}

	return ret;
}

int controller_PrintArcades(LinkedList* listaArcades , LinkedList* listaSonido)
{
	int ret;

	ret = -1;
	if(listaArcades != NULL && listaSonido != NULL)
	{
		ret = printDataArcades(listaArcades , listaSonido);
	}
	return ret;
}

int controllerGenerateNewArcade(LinkedList* listaArcades)
{
	int ret;
	FILE* counter;
	int valorContador;
	eArcade* aux;
	int indexElementoAborrar;

	ret = -1;
	if(listaArcades != NULL)
	{
		counter = fopen("Contador.txt" , "r");

		if(counter == NULL)
		{
			counter = fopen("Contador.txt" , "w");
			if(counter != NULL)
			{
				fprintf(counter , "15");
				fclose(counter);

				fopen("Contador.txt" , "r");
			}
		}

		if(counter != NULL)
		{
			if(parserDataFromCounter(counter, &valorContador) == 0)
			{
				fclose(counter);
				aux = GenerateNewArcade(&valorContador , &ret);
				if(aux != NULL && ret == 0)
				{
					ll_add(listaArcades, aux);
					ret = Controller_SaveAsText(listaArcades);
					if(ret == 0)
					{
						//actualizo el archivo de contador
						counter = fopen("contador.txt" , "w");
						fprintf(counter , "%d" , valorContador);
						fclose(counter);
					}
					else
					{
						indexElementoAborrar = ll_len(listaArcades);
						ll_remove(listaArcades, indexElementoAborrar);
					}
				}
			}
		}
	}
	return ret;
}

int Controller_SaveAsText(LinkedList* listaAguardar)
{
	int ret;
	FILE* archivo;
	char path[100];
	int largoLista;
	int metodoGuardado;

	eArcade* arcadeAux;
	//data del arcade
	int auxId;
	char nacionalidadAu[TAMNACIONALIDAD];
	int tipoSonido;
	int cantidadJugadoresAux;
	int cantidadFichasAux;
	char nombreAux[TAMJUEGO];
	char nombreSala[TAMSALON];

	ret = -1;
	if(listaAguardar != NULL)
	{
		Get_numeroConLimites("Ingrese la opcion de guardado:\n1-Crear archivo nuevo\n2-Archivo existente..", "Error, elija una opcion", 1, 2, &metodoGuardado);
		Get_cadena("Ingrese el nombre del archivo a actualizar o crear..", "Error, no puede ser tan grande", path, sizeof(path));

		largoLista = ll_len(listaAguardar);
		switch(metodoGuardado)
		{
			case 1:
				printf("Entre..\n");
				archivo = fopen(path , "w");
				if(archivo != NULL)
				{
					fprintf(archivo , "id , nacionalidad , tipo sonido , cantidad jugadores , cantidad fichas , sala , nombre\n");

					for(int i=0 ; i<largoLista ; i++)
					{
						arcadeAux = (eArcade*) ll_get(listaAguardar, i);
						if(arcadeAux != NULL)
						{
							getArcadeId(arcadeAux, &auxId);
							getNacionalidadArcade(arcadeAux, nacionalidadAu);
							getArcadeSound(arcadeAux, &tipoSonido);
							getArcadeCantJugadores(arcadeAux, &cantidadJugadoresAux);
							getArcadeCantFichas(arcadeAux, &cantidadFichasAux);
							getArcadeNombre(arcadeAux, nombreAux);
							getArcadeSalon(arcadeAux, nombreSala);

							fprintf(archivo ,"%d , %s , %d , %d , %d , %s , %s\n",auxId ,nacionalidadAu ,tipoSonido ,cantidadJugadoresAux ,cantidadFichasAux , nombreSala , nombreAux);

							ret = 0;
						}
						else
						{
							ret = -3; //un elemento de la lista quedo en null...
							break;
						}
					}
				}
				fclose(archivo);
			break;

			case 2:
				archivo = fopen(path , "w+ ");
				if(archivo != NULL)
				{
					fprintf(archivo , "id , nacionalidad , tipo sonido , cantidad jugadores , cantidad fichas , sala , nombre\n");

					for(int i=0 ; i<largoLista ; i++)
					{
						arcadeAux = (eArcade*) ll_get(listaAguardar, i);
						if(arcadeAux != NULL)
						{
							getArcadeId(arcadeAux, &auxId);
							getNacionalidadArcade(arcadeAux, nacionalidadAu);
							getArcadeSound(arcadeAux, &tipoSonido);
							getArcadeCantJugadores(arcadeAux, &cantidadJugadoresAux);
							getArcadeCantFichas(arcadeAux, &cantidadFichasAux);
							getArcadeNombre(arcadeAux, nombreAux);
							getArcadeSalon(arcadeAux, nombreSala);

							fprintf(archivo ,"%d , %s , %d , %d , %d , %s , %s\n",auxId ,nacionalidadAu ,tipoSonido ,cantidadJugadoresAux ,cantidadFichasAux ,nombreSala , nombreAux);
							printf("\nDatos guardados: %d , %s , %d , %d , %d , %s , %s\n",auxId ,nacionalidadAu ,tipoSonido ,cantidadJugadoresAux ,cantidadFichasAux ,nombreSala , nombreAux);
							ret = 0;
						}
						else
						{
							ret = -3; //un elemento de la lista quedo en null...
							break;
						}
					}
				}
				else
				{
					ret = -4; //no se encontro el archivo especificado...
				}
				fclose(archivo);
			break;
		}
	}
	return ret;
}

int Controller_ModArcade(LinkedList* pArcadeList , LinkedList* pSoundList)
{
	int ret;
	int idToModify;
	int indexOfTheElement;

	ret = -1;
	if(pArcadeList != NULL && pSoundList != NULL)
	{
		ret = -2; //no se encontro ese id...
		printDataArcades(pArcadeList, pSoundList);
		Get_numeroConLimites("Ingrese el id del elemento a modificar..", "Error, no puede ser tan gigante", 1 , 1000000, &idToModify);

		indexOfTheElement = findArcadeById(pArcadeList, idToModify);
		if(indexOfTheElement > -1)
		{
			ret = modifyArcade(pArcadeList , indexOfTheElement);
			if(ret == 0)
			{
				if(Controller_SaveAsText(pArcadeList) != 0)
				{
					ret = -4; //no se pudo guardar, no se encontro el archivo
				}
			}
		}
	}
	return ret;
}

int Controller_DeleteArcade(LinkedList* pArcadeList , LinkedList* pSoundList)
{
	int ret;
	int idToDelete;
	int indexOfTheElement;

	ret = -1;
	if(pArcadeList != NULL && pSoundList != NULL)
	{
		ret = -2; //no se encontro ese id...
		printDataArcades(pArcadeList, pSoundList);
		Get_numeroConLimites("Ingrese el id del elemento a eliminar..", "Error, no puede ser tan gigante", 1 , 1000000, &idToDelete);

		indexOfTheElement = findArcadeById(pArcadeList, idToDelete);
		if(indexOfTheElement > -1)
		{
			ret = deleteArcade(pArcadeList , indexOfTheElement);

			if(ret == 0)
			{
				if(Controller_SaveAsText(pArcadeList) != 0)
				{
					ret = -4; //no se pudo guardar, no se encontro el archivo
				}
			}
		}
	}
	return ret;
}

int Controller_SortArcades(LinkedList* pArcadeList , LinkedList* pSoundList)
{
	int ret;

	ret = -1;
	if(pArcadeList != NULL && pSoundList != NULL)
	{
		ret = 1; //la lista fue ordenada con exito...
		ll_sort(pArcadeList, sortLinkedList , 1 );

		if(QueresSeguir("Desea imprimir el listado? s/n") == 0)
		{
			ret = 0; //decidio imprimirla asi que no muestro mensaje de exito.. onda ya imprimirlo lo demuestra duh
			printDataArcades(pArcadeList, pSoundList);
		}
	}
	return ret;
}

int Controller_GamesListAtTheMoment(LinkedList* pArcadeList , LinkedList* pSoundList)
{
	int ret;
	FILE* archivo;
	char path[100];
	LinkedList* listaDeJuegos;

	eArcade* auxArcade;
	char auxNombre[TAMJUEGO];

	ret = -1;
	if(pArcadeList != NULL && pSoundList != NULL)
	{
		ret = -2; //no se pudo crear el archivo
		Get_cadena("Ingrese el nombre del archivo donde se almacenara el listado..", "Error, no puede ser tan grande..", path , sizeof(path));

		archivo = fopen(path , "w"); //si existe lo sobreescribe sino lo crea..

		if(archivo != NULL)
		{
			ret = -3; //no se pudo generar el listado...
			listaDeJuegos = generateGamesList(pArcadeList); //anda a saber por que tengo que convertir explicitamente duh

			if(listaDeJuegos != NULL)
			{
				ret = 0; //Guardo pero no mostro la lista...

				fprintf(archivo , "Lista Juegos ya cargados:\n");
				for(int i=0 ; i<ll_len(listaDeJuegos) ; i++)
				{
					auxArcade = ll_get(listaDeJuegos, i);
					getArcadeNombre(auxArcade, auxNombre);

					fprintf(archivo , "%s\n",auxNombre);
				}

				if(QueresSeguir("Desea imprimir la lista?? s/n") == 0)
				{
					printDataArcades(listaDeJuegos, pSoundList);
					ret = 1; //mostro la lista asi que no imprimo nada en el main, onda ya con que la imprimi se da cuenta que guardo duh
				}
			}
		}
		fclose(archivo);
	}
	return ret;
}

int Controller_MultiplayerGamesList(LinkedList* pArcadeList , LinkedList* pSoundList)
{
	int ret;
	FILE* archivo;
	char path[100];
	LinkedList* listaDeJuegosMp;

	eArcade* auxArcade;
	char auxNombre[TAMJUEGO];

	ret = -1;
	if(pArcadeList != NULL && pSoundList != NULL)
	{
		ret = -2; //no se pudo crear el archivo
		Get_cadena("Ingrese el nombre del archivo donde se almacenara el listado..", "Error, no puede ser tan grande..", path , sizeof(path));

		archivo = fopen(path , "w"); //si existe lo sobreescribe sino lo crea..

		if(archivo != NULL)
		{
			ret = -3; //no se pudo generar el listado...
			listaDeJuegosMp = ll_filter(pArcadeList, isMultiplayer);
			if(listaDeJuegosMp != NULL)
			{
				ret = 0; //Guardo pero no mostro la lista...

				fprintf(archivo , "Lista Juegos Multijugador:\n");
				for(int i=0 ; i<ll_len(listaDeJuegosMp) ; i++)
				{
					auxArcade = ll_get(listaDeJuegosMp, i);
					getArcadeNombre(auxArcade, auxNombre);

					fprintf(archivo , "%s\n",auxNombre);
				}

				if(QueresSeguir("Desea imprimir la lista?? s/n") == 0)
				{
					printDataArcades(listaDeJuegosMp, pSoundList);
					ret = 1; //mostro la lista asi que no imprimo nada en el main, onda ya con que la imprimi se da cuenta que guardo duh
				}
			}
		}
		fclose(archivo);
	}
	return ret;
}

int Controller_UpdateArcadeCoins(LinkedList* pArcadeList , LinkedList* pSoundList)
{
	int ret;
	LinkedList* listaAux;

	ret = -1;
	if(pArcadeList != NULL && pSoundList != NULL)
	{
		listaAux = ll_clone(pArcadeList);
		listaAux = ll_map(listaAux, functionModArcadeCoins); //igual no hace falta asignarla por que la modifica directamente asi que al pedo que retorne

		ret = 1; //no desea imprimirla, igual le aviso que quedo creada...
		if(QueresSeguir("Desea imprimir el listado actualizado? s/n") == 0)
		{
			printDataArcades(listaAux, pSoundList);
			ret = 0;
		}

		free(listaAux); //ya la termine de usar asi que libero la memoria
	}
	return ret;
}
