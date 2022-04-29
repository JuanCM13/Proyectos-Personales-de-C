
#include "parser.h"

/** \brief Parsea los datos de los libros desde el archivo pasado por parametro (modo texto).
 *
 * \param pFile FILE* (archivo)
 * \param pArrayListBooks LinkedList* (lista libros)
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se consigue lugar para cargar la lista , -2;
 * /FALLO EL PARSEO DE DATOS ,-4 No se encontro ese archivo
 */
int parser_arcadeFromText(FILE* pFile , LinkedList* pArrayListArcades)
{

	int ret;
	char auxId[100];
	char auxNacionalidad[100];
	char auxTipoSonido[100];
	char auxCantidadJuegadores[100];
	char auxCapacidadMaximaFichas[100];
	char auxNombreSalon[100];
	char auxNombreJuego[100];
	eArcade* auxArcade;

	ret = -1;

	if(pFile != NULL && pArrayListArcades != NULL)
	{
		//printf("Entre al parser..\n");
		ret = 0;

		fscanf(pFile , "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n" , auxId , auxNacionalidad , auxTipoSonido , auxCantidadJuegadores , auxCapacidadMaximaFichas , auxNombreSalon , auxNombreJuego);

		while(!feof(pFile))
		{
			if(fscanf(pFile , "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n" , auxId , auxNacionalidad , auxTipoSonido ,
														auxCantidadJuegadores , auxCapacidadMaximaFichas , auxNombreSalon , auxNombreJuego) == 7)
			{
				//printf(" %s  %s  %s  %s %s \n", auxiliarId , auxiliarTitulo , auxiliarAutor , auxiliarPrecio , auxiliarIdEditorial);

				if(validarParametrosArcade(auxId , auxNacionalidad , auxTipoSonido , auxCantidadJuegadores , auxCapacidadMaximaFichas) == 0)
				{
					auxArcade = newArcade_parameters(auxId , auxNacionalidad , auxTipoSonido , auxCantidadJuegadores , auxCapacidadMaximaFichas , auxNombreSalon , auxNombreJuego);

					if(auxArcade != NULL)
					{
						//printf(" %d  %s  %d  %d %d %s %s \n", auxArcade->idArcade , auxArcade->nacionalidad , auxArcade->tipoSonido , auxArcade->cantidadJuegadores , auxArcade->capacidadMaximaFichas , auxArcade->nombreSalon , auxArcade->nombreJuego);
						ll_add( pArrayListArcades , auxArcade);
					}
					else
					{
						ret = -3;
						break;
					}
				}
				else
				{
					ret = -2;
				}
			}
			else
			{
				ret = -2;
				break;
			}

		}

	}

    return ret;
}

//------------------------------------------------------------------------------------------------------------------------


int parser_soundFromText(FILE* pFile , LinkedList* pArrayListSound)
{

	int ret;
	char id[10];
	int auxId;
	char sonido[TIPOSONIDO];
	eSoundType* auxSonido;

	ret = -1;

	if(pFile != NULL && pArrayListSound != NULL)
	{
		//printf("Entre al parser..\n");
		ret = 0;

		fscanf(pFile , "%[^,], %[^\n]\n" , id , sonido);

		while(!feof(pFile))
		{
			if(fscanf(pFile , "%[^,], %[^\n]\n" , id , sonido) == 2)
			{

				auxId = atoi(id);

				auxSonido = newSoundParameters(auxId, sonido);

					if(auxSonido != NULL)
					{
						//printf(" %d  %s \n", auxSonido->soundId , auxSonido->soundType );
						ll_add( pArrayListSound , auxSonido);
					}
					else
					{
						ret = -3;
						break;
					}
				}
				else
				{
					ret = -2;
				}
			}
		}

    return ret;
}


/** \brief Valida si los parametros recibidos sacados del archivo de libros estan bien cargados (que sean solo numeros, etc).
 *
 * \param char* id
 * \param char* titulo
 * \param  char* autor
 * \param char* precio
 * \param char*idEditorial
 * \return 0 si los datos estan ok , -1 fallan nulls o algun dato esta mal validado
 *
 */
int validarParametrosArcade(char* arcadeId , char* arcadeNacionalidad , char* arcadeTipoSonido , char* arcadeCantidadJugadores , char* arcadeCapacidadMaximaFichas)
{
	int ret;

	ret = -1;

	if(arcadeId != NULL && arcadeNacionalidad != NULL && arcadeTipoSonido != NULL && arcadeCantidadJugadores != NULL && arcadeCapacidadMaximaFichas != NULL)
	{

		if(esNumero(arcadeId,strlen(arcadeId)) == 0)
		{
			//printf("Parse bien el id\n");
			ret = 0;
		}
		ret = -1;

		if(esNumero(arcadeTipoSonido , strlen(arcadeTipoSonido)))
		{
			//printf("Parse bien el id de la editorial\n");
			ret = 0;
		}
		ret = -1;

		if(esNumero(arcadeCantidadJugadores , strlen(arcadeCantidadJugadores)) == 0)
		{
			//printf("Parse bien el precio\n");
			ret = 0;
		}
		ret = -1;

		if(esNumero(arcadeCapacidadMaximaFichas , strlen(arcadeCapacidadMaximaFichas)) == 0)
		{
			//printf("Parse bien el precio\n");
			ret = 0;
		}
		ret = -1;

		if(sonLetras(arcadeNacionalidad , strlen(arcadeNacionalidad)) == 0)
		{
			//printf("Parse bien el titulo\n");
			ret = 0;
		}

	}

	return ret;
}

//---------------------------------------------------------------------------------------


int parserCounter(FILE* pFile , int* contador)
{
	char contadorAux[10];
	int aux;
	int ret;

	ret = -1;

	if(pFile != NULL && contador != NULL)
	{
		fscanf(pFile , "%[^ ] " , contadorAux);

		aux = atoi (contadorAux);

		*contador = aux;
		ret = 0;
	}

	return ret;
}
