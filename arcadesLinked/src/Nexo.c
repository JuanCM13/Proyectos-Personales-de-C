#include "Nexo.h"

//------------------------------------------------------------------------------------------------------------------------

int imprimirArcades(LinkedList* listaArcades , LinkedList* listaSonido)
{
	int ret;
	int largoArcades;
	int largoSonido;
	int i;
	int j;
	eSoundType* auxSonido;
	eArcade* auxArcade;

	int idSonido;
	int sonidoArcade;

	ret = -1;

	if(listaArcades != NULL && listaSonido != NULL)
	{
		largoArcades = ll_len(listaArcades);
		largoSonido = ll_len(listaSonido);
		if(largoArcades > 0)
		{
			printf("\n|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
			printf("|ID         NACIONALIDAD              AUDIO       JUGADORES           FICHAS       SALA                              JUEGO                      |\n");
			printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");

			for(i=0 ; i<largoArcades ; i++)
			{
				for(j=0 ; j<largoSonido ; j++)
				{
					auxSonido = ll_get(listaSonido, j);
					auxArcade = ll_get(listaArcades, i);

					getArcadeSound(auxArcade, &sonidoArcade);
					getSoundId(auxSonido, &idSonido);

					if(sonidoArcade == idSonido)
					{
						mostrarArcade(auxArcade , auxSonido);
						ret = 0;
					}
				}
			}

			printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
		}
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------

int mostrarArcade(eArcade* arcade , eSoundType* sonido)
{
	int ret;

	//sonido
	char auxSoundType[TIPOSONIDO];
	//aux arcade
	int id;
	char nacionalidad[TAMNACIONALIDAD];
	int cantidadJugadores;
	int cantidadFichas;
	char sala[TAMSALA];
	char juego[TAMJUEGO];

	ret = -1;

	if(arcade != NULL && sonido != NULL)
	{
		//Arcde
		getArcadeId(arcade, &id);
		getArcadeNacionalidad(arcade, nacionalidad);
		getArcadeCantJugadores(arcade, &cantidadJugadores);
		getArcadeCantFichas(arcade, &cantidadFichas);
		getArcadeSala(arcade, sala);
		getArcadeNombreJuego(arcade, juego);

		//Sound
		getSoundType(sonido, auxSoundType);

		printf("|%-10d %-25s %-15s %-16d %-10d %-30s %-30s |\n",id,
										nacionalidad,auxSoundType,cantidadJugadores,cantidadFichas ,sala , juego);

		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------

int modificarArcade(LinkedList* listaArcades , LinkedList* listaSonido)
{
	int ret;
	int idAmodificar;
	int indexAmodificar;
	int campoAmodificar;

	int cantidadJugadores;
	char nombreJuego[TAMJUEGO];
	eArcade* auxiliarArcade;
	LinkedList* aux;

	ret = -1;

	if(listaArcades != NULL && listaSonido != NULL)
	{
		imprimirArcades(listaArcades , listaSonido);

		Get_numeroConLimites("Ingrese el id a modificar..\n","Error, solo se admiten numeros..",0,INT_MAX,&idAmodificar);

		indexAmodificar = encontrarIndiceId(listaArcades , idAmodificar);

		if(indexAmodificar > -1)
		{
			auxiliarArcade = ll_get(listaArcades, indexAmodificar);

			Get_numeroConLimites("Que campo desea modificar?\n1- Cantidad Jugadores\n2- Nombre Juego\n","Error, ingrese una opcion entre las dadas..",1,2,&campoAmodificar);

			ret = -2; //Cancelo operacion

			switch(campoAmodificar)
			{

				case 1:

					Get_numeroConLimites("Ingrese la cantidad maxima de jugadores que acepta el juego..","Error la cantidad no puede ser tan grande..",0 , INT_MAX,&cantidadJugadores);

					if(QueresSeguir("Seguro que desea modificar este campo..? s/n") == 0)
					{
						setArcadeCantJugadores(auxiliarArcade, cantidadJugadores);
						ret = 0;
					}

				break;

				case 2:

					aux = crearListaNombresJuegosCargados(listaArcades);
					mostrarJuegos(aux);
					Get_cadena("Ingrese el nombre del juego..","Error el nombre no puede superar los 63 caracteres..",nombreJuego, TAMJUEGO);

					if(QueresSeguir("Seguro que desea modificar este campo..? s/n") == 0)
					{
						setArcadeNombreJuego(auxiliarArcade, nombreJuego);
						ret = 0;
					}

					ll_deleteLinkedList(aux);

				break;

			}
		}
		else
		{
			ret = -3; //no se encontro el id
		}
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------

int bajaArcade(LinkedList* listaArcades , LinkedList* listaSonido)
{
	int ret;
	int indexAeliminar;
	int idAEliminar;
	int indexSonidoRelacionado;

	int idSonidoArcade;
	eArcade* auxArcade;
	eSoundType* auxSonido;

	ret = -1;

	if(listaArcades != NULL && listaSonido != NULL)
	{
		imprimirArcades(listaArcades , listaSonido);

		Get_numeroConLimites("Ingrese el id a eliminar..\n","Error, solo se admiten numeros..",0,INT_MAX,&idAEliminar);

		indexAeliminar = encontrarIndiceId(listaArcades , idAEliminar);

		if(indexAeliminar > -1)
		{
			auxArcade = ll_get(listaArcades, indexAeliminar);
			getArcadeSound(auxArcade, &idSonidoArcade);

			indexSonidoRelacionado = findIdSound(listaSonido , idSonidoArcade);

			if(indexSonidoRelacionado > -1)
			{
				auxSonido = ll_get(listaSonido, indexSonidoRelacionado);
				mostrarArcade(auxArcade, auxSonido);

				ret = -2; //Cancelo operacion

				if(QueresSeguir("Seguro que desea eliminar el Arcade mostrado?? s/n") == 0)
				{
					ll_remove(listaArcades, indexAeliminar);
					ret = 0;
				}
			}
		}
		else
		{
			ret = -3; //No se encontro el id
		}

	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------
