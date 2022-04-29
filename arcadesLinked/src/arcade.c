#include "arcade.h"

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

//---------------------------------------------------------------------------------

eArcade* newArcade(void)
{
	eArcade* auxiliar;

	return auxiliar = (eArcade*) calloc(1 , sizeof(eArcade));

}

//---------------------------------------------------------------------------------

eArcade* newArcade_parameters(char* arcadeId , char* arcadeNacionalidad , char* arcadeTipoSonido , char* arcadeCantidadJugadores , char* arcadeCapacidadMaximaFichas, char* arcadeNombreSalon , char* arcadeNombreJuego)
{
	eArcade* auxiliar;
	int auxId;
	char auxNacionalidad[TAMNACIONALIDAD];
	int auxTipoSonido;
	int auxCantidadJugadores;
	int auxCantidadFichas;
	char auxNombreSala[TAMSALA];
	char auxNombreJuego[TAMJUEGO];

	auxiliar = NULL;

	if(arcadeId != NULL && arcadeNacionalidad != NULL && arcadeTipoSonido != NULL && arcadeCantidadJugadores != NULL && arcadeCapacidadMaximaFichas != NULL && arcadeNombreSalon != NULL && arcadeNombreJuego != NULL)
	{
		auxiliar = newArcade();

		if(auxiliar != NULL)
		{
			auxId = atoi(arcadeId);
			strncpy(auxNacionalidad , arcadeNacionalidad , sizeof(auxNacionalidad));
			auxTipoSonido = atoi(arcadeTipoSonido);
			auxCantidadJugadores = atoi(arcadeCantidadJugadores);
			auxCantidadFichas = atoi(arcadeCapacidadMaximaFichas);
			strncpy(auxNombreSala , arcadeNombreSalon , sizeof(auxNombreSala));
			strncpy(auxNombreJuego , arcadeNombreJuego , sizeof(auxNombreJuego));

			//SETTERS
			setArcadeId(auxiliar , auxId);
			setArcadeNacionalidad(auxiliar , auxNacionalidad);
			setArcadeSound(auxiliar , auxTipoSonido);
			setArcadeCantFichas(auxiliar , auxCantidadFichas);
			setArcadeCantJugadores(auxiliar , auxCantidadJugadores);
			setArcadeSala(auxiliar , auxNombreSala);
			setArcadeNombreJuego(auxiliar , auxNombreJuego);
		}
	}

	return auxiliar;
}

//---------------------------------------------------------------------------------

eArcade* addNewArcade(int *idCounter , int* guia)
{
	int ret;
	int sonido;
	char nacionalidad[TAMNACIONALIDAD];
	int cantidadJugadores;
	int cantidadFichas;
	char nombreSalon[TAMSALA];
	char nombreJuego[TAMJUEGO];
	int id;
	eArcade* auxiliar;

	auxiliar = NULL;
	ret = -1;

	if(idCounter != NULL)
	{
		ret = -2; //Cancelo operacion
		Get_nombre("Ingrese la nacionalidad del juego..","Error la nacionalidad no puede ser tan larga..",nacionalidad , TAMNACIONALIDAD);
		OrdenarNombre(nacionalidad , TAMNACIONALIDAD);

		Get_numeroConLimites("Ingrese el tipo de sonido del arcade \n1- MONO\n2-STEREO","Error ingrese una opcion entre las dadas..",1,2,&sonido);

		Get_numeroConLimites("Ingrese la cantidad maxima de jugadores que acepta el juego..","Error la cantidad no puede ser tan grande..",0 , INT_MAX,&cantidadJugadores);

		Get_numeroConLimites("Ingrese la cantidad maxima de fichas que acepta el juego..","Error la cantidad no puede ser tan grande..",0 , INT_MAX,&cantidadFichas);

		Get_cadena("Ingrese el nombre de la sala..","Error el nombre no puede ser tan grande..",nombreSalon, TAMSALA);

		Get_cadena("Ingrese el nombre del juego..","Error el nombre no puede superar los 63 caracteres..",nombreJuego, TAMJUEGO);

		if(QueresSeguir("Confirme la carga de el Arcade.. s/n") == 0)
		{
			auxiliar = newArcade();

			if(auxiliar != NULL)
			{
				id = *idCounter + 1;

				setArcadeId(auxiliar, id);
				setArcadeNacionalidad(auxiliar, nacionalidad);
				setArcadeSound(auxiliar, sonido);
				setArcadeCantJugadores(auxiliar, cantidadJugadores);
				setArcadeCantFichas(auxiliar, cantidadFichas);
				setArcadeSala(auxiliar, nombreSalon);
				setArcadeNombreJuego(auxiliar, nombreJuego);

				*idCounter = id;
				ret = 0;
			}

		}

		*guia = ret;
	}

	return auxiliar;
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

//---------------------------------------------------------------------------------

int getArcadeNacionalidad(eArcade* this , char* nacionalidad)
{
	int ret;

	ret = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(nacionalidad , this->nacionalidad);
		ret = 0;
	}

	return ret;
}

//---------------------------------------------------------------------------------

int getArcadeSound(eArcade* this , int* sound)
{
	int ret;

	ret = -1;

	if(this != NULL && sound != NULL)
	{
		*sound = this->tipoSonido;
		ret = 0;
	}

	return ret;
}

//---------------------------------------------------------------------------------

int getArcadeCantFichas(eArcade* this , int* fichas)
{
	int ret;

	ret = -1;

	if(this != NULL && fichas != NULL)
	{
		*fichas = this->capacidadMaximaFichas;
		ret = 0;
	}

	return ret;
}

//---------------------------------------------------------------------------------

int getArcadeCantJugadores(eArcade* this , int* cantJugadores)
{
	int ret;

	ret = -1;

	if(this != NULL && cantJugadores != NULL)
	{
		*cantJugadores = this->cantidadJuegadores;
		ret = 0;
	}

	return ret;
}

//---------------------------------------------------------------------------------

int getArcadeSala(eArcade* this , char* sala)
{
	int ret;

	ret = -1;

	if(this != NULL && sala != NULL)
	{
		strcpy(sala , this->nombreSalon);
		ret = 0;
	}

	return ret;
}

//---------------------------------------------------------------------------------

int getArcadeNombreJuego(eArcade* this , char* juego)
{
	int ret;

	ret = -1;

	if(this != NULL && juego != NULL)
	{
		strcpy(juego , this->nombreJuego);
		ret = 0;
	}

	return ret;
}

//---------------------------------------------------------------------------------


//********************************FIN GETTES******************************************



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

//---------------------------------------------------------------------------------

int setArcadeNacionalidad(eArcade* this , char* nacionalidad)
{
	int ret;

	ret = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		strncpy(this->nacionalidad , nacionalidad , sizeof(this->nacionalidad));
		ret = 0;
	}

	return ret;
}

//---------------------------------------------------------------------------------

int setArcadeSound(eArcade* this , int sound)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->tipoSonido = sound;
		ret = 0;
	}

	return ret;
}

//---------------------------------------------------------------------------------

int setArcadeCantFichas(eArcade* this , int fichas)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->capacidadMaximaFichas = fichas;
		ret = 0;
	}

	return ret;
}

//---------------------------------------------------------------------------------

int setArcadeCantJugadores(eArcade* this , int cantJugadores)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->cantidadJuegadores = cantJugadores;
		ret = 0;
	}

	return ret;
}

//---------------------------------------------------------------------------------

int setArcadeSala(eArcade* this , char* sala)
{
	int ret;

	ret = -1;

	if(this != NULL && sala != NULL)
	{
		strncpy(this->nombreSalon , sala , sizeof(this->nombreSalon));
		ret = 0;
	}

	return ret;
}

//---------------------------------------------------------------------------------

int setArcadeNombreJuego(eArcade* this , char* juego)
{
	int ret;

	ret = -1;

	if(this != NULL && juego != NULL)
	{
		strncpy(this->nombreJuego , juego , sizeof(this->nombreJuego));
		ret = 0;
	}

	return ret;
}

//---------------------------------------------------------------------------------


//********************************FIN SETTERS******************************************


//---------------------------------------------------------------------------------

int encontrarIndiceId(LinkedList* this , int id)
{
	int ret;
	int largo;
	int i;
	eArcade* aux;
	int auxId;

	ret = -1;

	if(this != NULL && id > 0)
	{
		largo = ll_len(this);

		if(this > 0)
		{
			for(i=0 ; i<largo ; i++)
			{
				aux = ll_get(this, i);
				getArcadeId(aux, &auxId);

				if(auxId == id)
				{
					ret = i;
				}
			}
		}
	}

	return ret;
}

//---------------------------------------------------------------------------------

int mostrarJuegos(LinkedList* this)
{
	int ret;
	int largo;
	int i;
	eArcade* aux;
	char nombre[TAMJUEGO];

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		largo = ll_len(this);

		printf("Listado de Juegos ya cargados:\n");
		for(i=0 ; i<largo ; i++)
		{
			aux = ll_get(this, i);
			getArcadeNombreJuego(aux, nombre);

			printf("%s\n",nombre);
		}

	}

	return ret;
}

//---------------------------------------------------------------------------------

int ordenarArcadesPorNombreAscendente(void* elementoUno , void* elementoDos)
{
	int ret;
	eArcade* arcadeUno;
	eArcade* arcadeDos;
	char juegoUno[TAMJUEGO];
	char juegoDos[TAMJUEGO];

	if(elementoUno != NULL && elementoDos != NULL)
	{
		arcadeUno = (eArcade*) elementoUno;
		arcadeDos = (eArcade*) elementoDos;

		if( (getArcadeNombreJuego(arcadeUno, juegoUno) == 0) && (getArcadeNombreJuego(arcadeDos, juegoDos) == 0) )
		{
			ret = strcmp(juegoUno , juegoDos);
		}
	}

	return ret;
}

//---------------------------------------------------------------------------------

int filtrarArcadesMultijugador(void* elementoUno)
{
	int ret;
	eArcade* arcade;
	int cantJugadores;

	ret = 0;

	if(elementoUno != NULL)
	{
		arcade = (eArcade*) elementoUno;
		getArcadeCantJugadores(arcade, &cantJugadores);

		if(cantJugadores > 1)
		{
			ret = 1;
		}
	}

	return ret;
}

//---------------------------------------------------------------------------------

int duplicarFichas(void* elementoUno)
{
	int ret;
	eArcade* arcade;
	int cantFichas;

	ret = -1;

	if(elementoUno != NULL)
	{
		ret = 0;

		arcade = (eArcade*) elementoUno;
		getArcadeCantFichas(arcade, &cantFichas);

		cantFichas = cantFichas * 2;

		setArcadeCantFichas(arcade, cantFichas);
	}

	return ret;
}

//---------------------------------------------------------------------------------

LinkedList* crearListaNombresJuegosCargados(LinkedList* listaArcades)
{
	LinkedList* aux;

	//Vars respecto a listaArcades
	int i;
	eArcade* arcade;
	char nombre[TAMJUEGO];
	int largo;

	//Vars respecto a aux
	int j;
	eArcade* arcadeAuxiliar;
	char auxiliarNombreAcomparar[TAMJUEGO];
	int largoNuevaLista;
	int controlador;


	aux = NULL;

	if(listaArcades != NULL)
	{
		 aux = ll_newLinkedList();

		 if(aux != NULL)
		 {
			 largo = ll_len(listaArcades);

			 for(i=0 ; i<largo ; i++)
			 {
				 arcade = ll_get(listaArcades, i);
				 getArcadeNombreJuego(arcade, nombre);

				 if(i==0)
				 {
					ll_add(aux, arcade);
				 }
				 else
				 {
					 controlador = 0;

					 largoNuevaLista = ll_len(aux);
					 for(j=0 ; j<largoNuevaLista ; j++)
					 {
						 arcadeAuxiliar = ll_get(aux, j);
						 getArcadeNombreJuego(arcadeAuxiliar, auxiliarNombreAcomparar);

						 if(strcmp(nombre , auxiliarNombreAcomparar) == 0)
						 {
							 controlador++;
						 }
					 }

					 if(controlador == 0)
					 {
						 ll_add(aux, arcade);
					 }
				 }
			 }
		 }
	}

	//mostrarJuegos(aux);
	return aux;
}
