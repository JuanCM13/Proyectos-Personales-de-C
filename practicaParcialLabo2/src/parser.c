#include "input.h"
#include "LinkedList.h"
#include "pilotos.h"
#include "parser.h"
#include "vuelos.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si esta todo okey , -1 si fallan nulls , -2 si no pudo cargar algun elemento , -3 no se consiguio espacio en la memoria dinamica
 *
 */
int parser_flightFromText(FILE* pFile , LinkedList* pListaVuelos)
{

	int ret;
	char auxVuelo[50];
	char auxAvion[50];
	char auxPiloto[50];
	char auxFecha[50];
	char auxDestino[50];
	char auxCantPasajeros[50];
	char auxHoraDespegue[50];
	char auxHoraLlegada[50];
	eVuelo* aux;

	ret = -1;

	if(pFile != NULL && pListaVuelos != NULL)
	{
		ret = 0;

		fscanf(pFile , "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n" , auxVuelo , auxAvion , auxPiloto , auxFecha , auxDestino , auxCantPasajeros , auxHoraDespegue , auxHoraLlegada) ;

		while(!feof(pFile))
		{
			if(fscanf(pFile , "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n" , auxVuelo , auxAvion , auxPiloto , auxFecha , auxDestino , auxCantPasajeros , auxHoraDespegue , auxHoraLlegada) == 8)
			{
				//printf("%s -- %s -- %s -- %s \n" , auxId , auxNombre , auxHoras , auxSueldo);

				aux = flightNewParameters(auxVuelo, auxAvion, auxPiloto, auxFecha, auxDestino, auxCantPasajeros, auxHoraDespegue, auxHoraLlegada);

				if(aux != NULL)
				{
					ll_add(pListaVuelos , aux);
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
				break;
			}

		}

	}

    return ret;
}

//----------------------------------------------------------------------------------------------------


