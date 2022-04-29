#include "Arcades.h"

int imprimirMenu(int* opcion)
{
	int ret;

	ret = -1;

	if(opcion != NULL)
	{

		ret = 0;
		printf("\n\n|---------------------------------------------MENU-----------------------------------------------------|\n");
		printf("|	1. Cargar archivo de Arcades                                                                   |\n");
		printf("|	2. Cargar archivo de Sonido                                                                    |\n");
		printf("|	3. Cargar nuevo Arcade                                                                         |\n");
		printf("|	4. Mostrar lista de Arcades                                                                    |\n");
		printf("|	5. Modificar Arcade                                                                            |\n");
		printf("|	6. Eliminar Arcade                                                                             |\n");
		printf("|	7. Ordenar lista Arcades por juego de manera ascendente                                        |\n");
		printf("|	8. Generar/actualizar archivo de nombres de juegos cargados hasta el momento                   |\n");
		printf("|	9. Generar/actualizar archivo Arcades MultiPlayer                                              |\n");
		printf("|	10.Duplicar fichas cargadas por arcade hasta el momento                                        |\n");
		printf("|	11.Salir                                                                                       |\n");
		printf("|------------------------------------------------------------------------------------------------------|\n");

		Get_numeroConLimites("Ingrese la opcion del menu..","Error, ingrese una opcion entre las dadas..\n",1,11,opcion);
	}

	return ret;
}

eArcade* new_Arcade(void)
{
	eArcade* retorno;

	retorno = (eArcade*) calloc(1 , sizeof(eArcade));

	return retorno;
}

eArcade* newArcade_Parameters(char* id,char* nacionalidad,char* tipoSonido, char* cantidadJugadores, char* cantFichas, char* nombreJuego, char* nombreSala)
{
	int auxId;
	char auxNacionalidad[TAMNACIONALIDAD];
	int auxTipoSonido;
	int auxCantJugadores;
	int auxCantFichas;
	char auxNombreJuego[TAMJUEGO];
	char auxNombreSalon[TAMSALON];
	eArcade* auxArcade;

	auxArcade = NULL;

	if(id != NULL && nacionalidad != NULL && tipoSonido != NULL && cantidadJugadores != NULL && cantFichas != NULL && nombreJuego != NULL && nombreSala != NULL)
	{
		auxId = atoi(id);
		strncpy(auxNacionalidad , nacionalidad , sizeof(auxNacionalidad));
		auxTipoSonido = atoi(tipoSonido);
		auxCantJugadores = atoi(cantidadJugadores);
		auxCantFichas = atoi(cantFichas);
		strncpy(auxNombreJuego , nombreJuego , sizeof(auxNombreJuego));
		strncpy(auxNombreSalon , nombreSala , sizeof(auxNombreSalon));

		auxArcade = new_Arcade();
		if(auxArcade != NULL)
		{
			setArcadeId(auxArcade, auxId);
			setArcadeNacionalidad(auxArcade, auxNacionalidad);
			setArcadeSonido(auxArcade, auxTipoSonido);
			setArcadeJugadores(auxArcade, auxCantJugadores);
			setArcadeFichas(auxArcade, auxCantFichas);
			setArcadeNombreJuego(auxArcade, auxNombreJuego);
			setArcadeNombreSalon(auxArcade, auxNombreSalon);
		}

	}
	return auxArcade;
}

//********************************GETTERS******************************************

int getArcadeId(eArcade* this , int* id)
{
	int ret;

	ret = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->idArcade;
		ret = 0;
	}

	return ret;
}

int getNacionalidadArcade(eArcade* this , char* nacArcade)
{
	int ret;

	ret = -1;
	if(this != NULL && nacArcade != NULL)
	{
		ret = 0;
		strcpy(nacArcade , this->nacionalidadArcade);
	}

	return ret;
}

int getArcadeSound(eArcade* this , int* tipoSonido)
{
	int ret;

	ret = -1;

	if(this != NULL && tipoSonido != NULL)
	{
		*tipoSonido = this->tipoSonido;
		ret = 0;
	}

	return ret;
}

int getArcadeCantJugadores(eArcade* this , int* cantJugadores)
{
	int ret;

	ret = -1;

	if(this != NULL && cantJugadores != NULL)
	{
		*cantJugadores = this->cantidadJugadores;
		ret = 0;
	}

	return ret;
}

int getArcadeCantFichas(eArcade* this , int* cantFichas)
{
	int ret;

	ret = -1;

	if(this != NULL && cantFichas != NULL)
	{
		*cantFichas = this->capacidadMaximaFichasM;
		ret = 0;
	}

	return ret;
}

int getArcadeNombre(eArcade* this , char* nombreJuego)
{
	int ret;

	ret = -1;

	if(this != NULL && nombreJuego != NULL)
	{
		strcpy(nombreJuego , this->nombreJuego);
		ret = 0;
	}

	return ret;
}

int getArcadeSalon(eArcade* this , char* nombreSalon)
{
	int ret;

	ret = -1;

	if(this != NULL && nombreSalon != NULL)
	{
		strcpy(nombreSalon , this->nombreSalon);
		ret = 0;
	}

	return ret;
}

//********************************SETTERS******************************************

int setArcadeId(eArcade* this , int id)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->idArcade = id;
		ret = 0;
	}

	return ret;
}

int setArcadeNacionalidad(eArcade* this , char* nacionalidad)
{
	int ret;

	ret = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(this->nacionalidadArcade , nacionalidad);
		ret = 0;
	}

	return ret;
}

int setArcadeSonido(eArcade* this , int tipoSonido)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->tipoSonido = tipoSonido;
		ret = 0;
	}

	return ret;
}

int setArcadeJugadores(eArcade* this , int cantJugadores)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->cantidadJugadores = cantJugadores;
		ret = 0;
	}

	return ret;
}

int setArcadeFichas(eArcade* this , int cantFichas)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->capacidadMaximaFichasM = cantFichas;
		ret = 0;
	}

	return ret;
}

int setArcadeNombreJuego(eArcade* this , char* nombreJuego)
{
	int ret;

	ret = -1;

	if(this != NULL && nombreJuego != NULL)
	{
		strcpy(this->nombreJuego , nombreJuego);
		ret = 0;
	}

	return ret;
}

int setArcadeNombreSalon(eArcade* this , char* nombreSalon)
{
	int ret;

	ret = -1;

	if(this != NULL && nombreSalon != NULL)
	{
		strcpy(this->nombreSalon , nombreSalon);
		ret = 0;
	}

	return ret;
}

eArcade* GenerateNewArcade(int* counter , int* ret)
{
	eArcade* auxArcade;
	int auxId;
	char nacionalidadAu[TAMNACIONALIDAD];
	int tipoSonido;
	int cantidadJugadoresAux;
	int cantidadFichasAux;
	char nombreAux[TAMJUEGO];
	char nombreSala[TAMSALON];

	auxArcade = NULL;
	if(counter != NULL && ret != NULL)
	{
		*ret = -2; //cancelo la operacion
		Get_cadena("Ingrese el nombre del juego..", "Error, no puede ser tan grande", nombreAux, sizeof(nombreAux));
		OrdenarNombre(nombreAux, sizeof(nombreAux));

		Get_cadena("Ingrese el nombre de la sala..", "Error, no puede ser tan grande", nombreSala, sizeof(nombreSala));
		OrdenarNombre(nombreSala, sizeof(nombreSala));

		Get_cadena("Ingrese la nacionalidad del juego..", "Error, no puede ser tan grande", nacionalidadAu, sizeof(nacionalidadAu));
		OrdenarNombre(nacionalidadAu, sizeof(nacionalidadAu));

		Get_numeroConLimites("Ingrese el tipo de sonido \n1-MONO\n2-STEREO", "Error, elija una de las dos opciones", 1, 2, &tipoSonido);

		Get_numeroConLimites("Ingrese la cantidad de jugadores que admite el juego..","Error", 1 , 100000, &cantidadJugadoresAux);

		Get_numeroConLimites("Ingrese la cantidad de fichas que admite el juego..", "Error", 1 , 100000, &cantidadFichasAux);

		if(QueresSeguir("Seguro que desea cargar este arcade?? s/n.. podra modificar los datos seleccioando la opcion del menu") == 0)
		{
			auxArcade = new_Arcade();
			if(auxArcade != NULL)
			{
				*ret = 0;
				auxId = *counter + 1;
				setArcadeId(auxArcade, auxId);
				setArcadeSonido(auxArcade, tipoSonido);
				setArcadeNacionalidad(auxArcade, nacionalidadAu);
				setArcadeJugadores(auxArcade, cantidadJugadoresAux);
				setArcadeFichas(auxArcade, cantidadFichasAux);
				setArcadeNombreJuego(auxArcade, nombreAux);
				setArcadeNombreSalon(auxArcade, nombreSala);

				*counter = auxId;
			}
		}
	}
	return auxArcade;
}

int findArcadeById(LinkedList* listaArcades , int idToFind)
{
	int ret;
	int largo;
	eArcade* arcadeAux;
	int arcadeId;

	ret = -1;
	if(listaArcades != NULL)
	{
		largo = ll_len(listaArcades);
		for(int i=0 ; i<largo ; i++)
		{
			arcadeAux = (eArcade*)ll_get(listaArcades, i);
			getArcadeId(arcadeAux, &arcadeId);

			if(arcadeId == idToFind)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}

int modifyArcade(LinkedList* listaArcades , int indexToModify)
{
	int ret;
	int campo;
	char nombreAux[TAMJUEGO];
	char salaAux[TAMSALON];
	int cantidadJugadoresAux;
	int cantidadFichasAux;

	eArcade* arcadeToModify;

	ret = -1;
	if(listaArcades != NULL)
	{
		ret = -3; //cancelo operacion
		Get_numeroConLimites("Ingrese el campo a modificar:\n1.Nombre Juego\n2.Nombre Sala\n3.Cant players\n4.Cant Fichas", "Error, elija entre las opciones dadas", 1, 4, &campo);

		if(QueresSeguir("Seguro que desea modificar el campo? s/n") == 0)
		{
			ret = 0;
			arcadeToModify = ll_get(listaArcades, indexToModify);
			switch(campo)
			{
				case 1:
					Get_cadena("Ingrese el nombre del juego..", "Error, no puede ser tan grande", nombreAux, sizeof(nombreAux));
					OrdenarNombre(nombreAux, sizeof(nombreAux));

					setArcadeNombreJuego(arcadeToModify, nombreAux);
				break;
				case 2:
					Get_cadena("Ingrese el nombre de la sala..", "Error, no puede ser tan grande", salaAux, sizeof(salaAux));
					OrdenarNombre(salaAux, sizeof(salaAux));

					setArcadeNombreSalon(arcadeToModify, salaAux);
				break;
				case 3:
					Get_numeroConLimites("Ingrese la cantidad de jugadores que admite el juego..","Error", 1 , 100000, &cantidadJugadoresAux);

					setArcadeJugadores(arcadeToModify, cantidadJugadoresAux);
				break;
				case 4:
					Get_numeroConLimites("Ingrese la cantidad de fichas que admite el juego..","Error", 1 , 100000, &cantidadFichasAux);

					setArcadeFichas(arcadeToModify, cantidadFichasAux);
				break;
			}
		}
	}

	return ret;
}

int deleteArcade(LinkedList* listaArcades , int indexToDeletes)
{
	int ret;

	ret = -1;
	if(listaArcades != NULL)
	{
		ret = -3; //cancelo operacion
		if(QueresSeguir("Seguro que desea eliminar este campo? s/n") == 0)
		{
			ret = 0;
			ll_remove(listaArcades, indexToDeletes);
		}
	}

	return ret;
}

int sortLinkedList(void* pElementUno , void* pElementDos)
{
	eArcade* elementoUno;
	eArcade* elementoDos;
	char nombreUno[TAMJUEGO];
	char nombreDos[TAMJUEGO];
	int ret;

	ret = 0;
	if(pElementUno != NULL && pElementDos != NULL)
	{
		elementoUno = (eArcade*) pElementUno;
		elementoDos = (eArcade*) pElementDos;

		getArcadeNombre(elementoUno, nombreUno);
		getArcadeNombre(elementoDos, nombreDos);

		ret = strcmp(nombreUno , nombreDos);
	}
	return ret;
}

LinkedList* generateGamesList(LinkedList* listaArcades)
{
	LinkedList* listaOrdenada;
	LinkedList* listaJuegosCreada = NULL;
	eArcade* juegoFuturo;
	eArcade* juegoAmirar;
	char nombreJuego[TAMJUEGO];
	char nombreJuegoFuturo[TAMJUEGO];

	if(listaArcades != NULL)
	{
		listaJuegosCreada = ll_newLinkedList();

		listaOrdenada = ll_clone(listaArcades);
		ll_sort(listaOrdenada,sortLinkedList , 1);

		for(int i=0 ; i<ll_len(listaOrdenada)-1 ; i++) //sino se extende en el i+1 del final. y me toma la basura que se guarda en esa posision
		{
			if(i==0)
			{
				juegoAmirar = ll_get(listaOrdenada, i);
				getArcadeNombre(juegoAmirar, nombreJuego);
			}
			else
			{
				juegoFuturo = ll_get(listaOrdenada, i+1);
				getArcadeNombre(juegoFuturo, nombreJuegoFuturo);

				printf("Juego a evaluar: %s\n",nombreJuego);
				printf("Juego proximo: %s\n",nombreJuegoFuturo);

				if(strcmp(nombreJuego , nombreJuegoFuturo) != 0)
				{
					ll_add(listaJuegosCreada, juegoAmirar);
					printf("Es distinto, guarde: Nombre: %s\n",nombreJuego);
					juegoAmirar = juegoFuturo;
					strcpy(nombreJuego , nombreJuegoFuturo);
				}
			}
		}

		if(listaJuegosCreada != NULL)
		{
			ll_add(listaJuegosCreada , juegoAmirar); //como rompe antes de llegar al ultimo elemento el for, agrego el ultimo elemento
		}											//guardado en la variable juego a mirar osea el que le sigue al ultimo juego guardado
													//y lo agrego a la lista, total ya se que no se repite duh..

	}
	return listaJuegosCreada;
}

int isMultiplayer(void* elemento)
{
	int ret;
	eArcade* pArcadeAevaluar;
	int cantJugadores;

	ret = -1;
	pArcadeAevaluar = (eArcade*) elemento;

	if(pArcadeAevaluar != NULL)
	{
		getArcadeCantJugadores(pArcadeAevaluar, &cantJugadores);
		if(cantJugadores > 1)
		{
			ret = 1;
		}
	}
	return ret;
}

int functionModArcadeCoins(void* pElement)
{
	//duplica las monedas del arcade..
	eArcade* aux;
	int newCoins;

	if(pElement != NULL)
	{
		aux = (eArcade*) pElement;
		if(aux != NULL)
		{
			getArcadeCantFichas(aux, &newCoins);
			newCoins = newCoins * 2;
			setArcadeFichas(aux, newCoins);
		}
	}

	return 0;
}
