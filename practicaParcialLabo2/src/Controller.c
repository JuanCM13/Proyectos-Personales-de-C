#include "Controller.h"

#define MAXSTRING 250

int controller_loadPilotsFile(LinkedList* listaVuelos)
{
	FILE* punteroFile;
	int ret;
	char* archivo[MAXSTRING];

	ret = -1;

	if(listaVuelos != NULL)
	{
		ret = -2; //no se encontro el archivo

		Get_cadena("Ingrese el nombre del archivo de donde cargaremos la lista de vuelos..","Error el nombre no puede ser tan largo", archivo , MAXSTRING);

		punteroFile = fopen(archivo , "r");

		if(punteroFile != NULL)
		{
			ret = -3; //No se pudo parsear

			if(parser_flightFromText(punteroFile , listaVuelos) == 0)
			{
				ret = 0; //Se parseo bien
			}

			fclose(punteroFile);
		}

	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------
/*
int controller_loadFlightsFile(LinkedList* lista)
{
	FILE* punteroFile;
	int ret;

	ret = -1;

	if(lista != NULL)
	{
		ret = -2; //no se encontro el archivo

		punteroFile = fopen(archivo , "r");

		if(punteroFile != NULL)
		{
			ret = -3; //No se pudo parsear

			if(parserFromText(punteroFile , lista) == 0)
			{
				ret = 0; //Se parseo bien
			}

			fclose(punteroFile);
		}

	}
}
*/
//-----------------------------------------------------------------------------------------------------------



