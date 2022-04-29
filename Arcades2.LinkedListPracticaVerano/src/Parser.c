#include "Parser.h"

int ParsearDataArcades(LinkedList* listaArcades , FILE* archivo)
{
	char auxId[100];
	char auxNacionalidad[100];
	char auxTipoSonido[100];
	char auxCantidadJugadores[100];
	char auxCantidadFichas[100];
	char auxNombreJuego[100];
	char auxNombreSala[100];
	int ret;

	eArcade* auxArcade;

	ret = -1; //fallan nulls
	if(listaArcades != NULL && archivo != NULL)
	{
		fscanf(archivo , "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", auxId , auxNacionalidad , auxTipoSonido , auxCantidadJugadores , auxCantidadFichas , auxNombreSala , auxNombreJuego );

		while(!feof(archivo))
		{
			if(feof(archivo))
			{
				break;
			}

			if(fscanf(archivo , "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", auxId , auxNacionalidad , auxTipoSonido , auxCantidadJugadores , auxCantidadFichas , auxNombreSala , auxNombreJuego) == 7)
			{
				if(validarData(auxId , auxNacionalidad , auxTipoSonido , auxCantidadJugadores , auxCantidadFichas) == 0)
				{
					auxArcade = newArcade_Parameters(auxId, auxNacionalidad, auxTipoSonido, auxCantidadJugadores, auxCantidadFichas, auxNombreJuego, auxNombreSala);
					if(auxArcade != NULL)
					{
						ret = 0;
						ll_add(listaArcades, auxArcade);
						printf("ID: %d\nNac: %s\nTipoSo: %d\nCant Jug: %d\nCant Fi: %d\nNombre Jug: %s\nNombre Sal: %s\n",auxArcade->idArcade , auxArcade->nacionalidadArcade , auxArcade->tipoSonido,auxArcade->cantidadJugadores,auxArcade->capacidadMaximaFichasM,auxArcade->nombreJuego,auxArcade->nombreSalon);
					}
					else
					{
						ret = -3; //no se pudo crear el dato de tipo Arcade
					}
				}
				else
				{
					ret = -2;
					break; //rompo si falla hay algun dato mal validado
				}
			}
			else
			{
				ret = -4; //fallo parseo de algun dato del archivo, no logro copiar los 7 datos
				break;
			}
		}
	}
	return ret;
}

int ParsearDataSound(LinkedList* listaSonido , FILE* archivo)
{
	char auxIdSonido[100];
	char auxTipoSonido[100];
	int ret;

	eSound* auxSonido;

	ret = -1; //fallan nulls
	if(listaSonido != NULL && archivo != NULL)
	{
		fscanf(archivo , "%[^,], %[^\n]\n", auxIdSonido , auxTipoSonido);

		while(!feof(archivo))
		{
			if(fscanf(archivo , "%[^,], %[^\n]\n", auxIdSonido , auxTipoSonido) == 2)
			{
				if(validarDataSonido(auxIdSonido , auxTipoSonido) == 0)
				{
					auxSonido = newSound_Parameters(auxIdSonido, auxTipoSonido);

					if(auxSonido != NULL)
					{
						ret = 0;
						ll_add(listaSonido, auxSonido);
						printf("%d \n%s \n\n" , auxSonido->soundId , auxSonido->soundType);
					}
					else
					{
						ret = -3; //no se pudo crear el dato de tipo sonido
					}
				}
				else
				{
					ret = -2;
					break; //rompo si falla hay algun dato mal validado
				}
			}
			else
			{
				ret = -4; //fallo parseo de algun dato del archivo, no logro copiar los 7 datos
				break;
			}
		}
	}
	return ret;
}

int validarData(char* id, char* nacionalidad, char* tipoSonido, char* cantJugadores , char* cantFichas)
{
	int varControl;

	if(id != NULL && nacionalidad != NULL && tipoSonido != NULL && cantJugadores != NULL && cantFichas != NULL)
	{
		varControl = -1;
		if(esNumero(id , strlen(id) == 0))
		{
			varControl = 0;
		}

		varControl = -1;
		if(sonLetras(nacionalidad , strlen(nacionalidad) == 0))
		{
			varControl = 0;
		}

		varControl = -1;
		if(esNumero(tipoSonido , strlen(tipoSonido) == 0))
		{
			varControl = 0;
		}

		varControl = -1;
		if(esNumero(cantJugadores , strlen(cantJugadores) == 0))
		{
			varControl = 0;
		}

		varControl = -1;
		if(esNumero(cantFichas , strlen(cantFichas) == 0))
		{
			varControl = 0;
		}
	}

	return varControl;

}

int validarDataSonido(char* id, char* tipoSonido)
{
	int varControl;

	varControl = -1;
	if(id != NULL && tipoSonido != NULL)
	{
		if(esNumero(id , strlen(id)) == 0)
		{
			varControl = 0;
		}

		varControl = -1;
		if(sonLetras(tipoSonido , strlen(tipoSonido)) == 0)
		{
			if(strcmp(tipoSonido , "MONO") == 0 || strcmp(tipoSonido , "STEREO") == 0)
			{
				varControl = 0;
			}
		}
	}

	return varControl;
}

int parserDataFromCounter(FILE* path , int* contador)
{
	int ret;
	char contadorAux[100];
	int auxConvertido;

	ret = -1;
	if(path != NULL && contador != NULL)
	{
		fscanf(path , "%[^ ] " , contadorAux);

		if(esNumero(contadorAux , strlen(contadorAux)) == 0)
		{
			ret = 0;
			auxConvertido = atoi(contadorAux);
			*contador = auxConvertido;
		}
	}

	return ret;
}
