#include "Nexo.h"


int printDataArcades(LinkedList* listaArc , LinkedList* listaSon)
{
	int ret;
	eArcade* auxArcade;
	eSound* auxSound;
	int soundType;
	int indexSound;

	ret = -1;
	if(listaArc != NULL && listaSon != NULL)
	{
		printf("\n|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|ID         NACIONALIDAD              AUDIO       JUGADORES           FICHAS       SALA                              JUEGO                      |\n");
		printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
		for(int i=0 ; i<ll_len(listaArc) ; i++)
		{
			auxArcade = ll_get(listaArc, i);
			getArcadeSound(auxArcade, &soundType);

			indexSound = findSoundIndexById(listaSon, soundType);
			if(indexSound != -1)
			{
				auxSound = ll_get(listaSon, indexSound);
				ret = MostrarArcadeConSonido(auxArcade , auxSound);
			}
		}
		printf("|-----------------------------------------------------------------------------------------------------------------------------------------------|\n");
	}

	return ret;
}


int MostrarArcadeConSonido(eArcade* arcade ,eSound* sound)
{
	int ret;

	//aux info arcade
	int arcadeId;
	char arcadeNac[TAMNACIONALIDAD];
	int auxCantPlayers;
	int auxCantidadFichas;
	char auxNombre[TAMJUEGO];
	char auxSalon[TAMSALON];

	//aux info sonido
	char tipoSonido[TAMSOUND];

	ret = -1;
	if(arcade != NULL && sound != NULL)
	{
		ret = 0;
		getArcadeId(arcade, &arcadeId);
		getNacionalidadArcade(arcade, arcadeNac);
		getArcadeCantJugadores(arcade, &auxCantPlayers);
		getArcadeCantFichas(arcade , &auxCantidadFichas);
		getArcadeNombre(arcade, auxNombre);
		getArcadeSalon(arcade, auxSalon);

		//sonido
		getSoundType(sound, tipoSonido);

		printf("|%-10d %-25s %-15s %-16d %-10d %-30s %-30s |\n",arcadeId ,arcadeNac , tipoSonido ,auxCantPlayers ,auxCantidadFichas ,auxSalon, auxNombre);
	}

	return ret;
}
