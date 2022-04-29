
#include "parser.h"

/** \brief Parsea los datos de los libros desde el archivo pasado por parametro (modo texto).
 *
 * \param pFile FILE* (archivo)
 * \param pArrayListBooks LinkedList* (lista libros)
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se consigue lugar para cargar la lista , -2;
 * /FALLO EL PARSEO DE DATOS ,-4 No se encontro ese archivo
 */
int parser_logsFromText(FILE* pFile , LinkedList* pArrayListLogs)
{

	int ret;
	char dateAux[100];
	char timeAux[100];
	char serviceIdAux[100];
	char severityAux[100];
	char msgAux[100];
	eLogEntry* aux;

	ret = -1;

	if(pFile != NULL && pArrayListLogs != NULL)
	{
		//printf("Entre al parser..\n");
		ret = 0;

		while(!feof(pFile))
		{
			if(fscanf(pFile , "%[^;]; %[^;]; %[^;]; %[^;]; %[^\n]\n" , dateAux , timeAux , serviceIdAux , severityAux , msgAux) == 5)
			{
				//printf(" %s  %s  %s  %s %s \n", dateAux , timeAux , serviceIdAux , severityAux , msgAux);

				if(controlLogsEntry(dateAux , timeAux , serviceIdAux , severityAux) == 0)
				{

					aux = newLog_parameters(dateAux, timeAux, serviceIdAux, severityAux, msgAux);

					if(aux != NULL)
					{
						//printf(" %s  %s  %d  %d %s \n", aux->date , aux->time , aux->serviceId , aux->severity , aux->msg);
						ll_add( pArrayListLogs , aux);
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


//----------------------------------------------------------------------------------------------------

/** \brief Parsea los datos de los libros desde el archivo pasado por parametro (modo texto).
 *
 * \param pFile FILE* (archivo)
 * \param pArrayListBooks LinkedList* (lista libros)
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se consigue lugar para cargar la lista , -2;
 * /FALLO EL PARSEO DE DATOS ,-4 No se encontro ese archivo
 */
int parser_servicesFromText(FILE* pFile , LinkedList* pArrayListServices)
{

	int ret;
	char idAux[100];
	char nameAux[100];
	char emailAux[100];
	eService* aux;

	ret = -1;

	if(pFile != NULL && pArrayListServices != NULL)
	{
		//printf("Entre al parser..\n");
		ret = 0;
		while(!feof(pFile))
		{
			if(fscanf(pFile , "%[^;]; %[^;]; %[^\n]\n" , idAux , nameAux , emailAux) == 3)
			{
				//printf(" %s  %s  %s \n", idAux , nameAux , emailAux);

				if(controlServicesEntry(idAux) == 0)
				{
					aux = newService_parameters(idAux, nameAux, emailAux);

					if(aux != NULL)
					{
						//printf(" %d  %s  %s \n", aux->id , aux->name , aux->email);
						ll_add( pArrayListServices , aux);
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
int controlLogsEntry(char* date , char* time , char* serviceId , char* severity)
{
	int ret;

	ret = -1;

	if(date != NULL && time != NULL && serviceId != NULL && severity != NULL)
	{

		if(esFecha(date) == 0)
		{
			//printf("Parse bien el id\n");
			ret = 0;
		}
		ret = -1;

		if(esHora(time) == 0)
		{
			//printf("Parse bien el id de la editorial\n");
			ret = 0;
		}
		ret = -1;

		if(esNumero(serviceId, strlen(serviceId)) == 0)
		{
			//printf("Parse bien el precio\n");
			ret = 0;
		}
		ret = -1;

		if(esNumero(severity, strlen(severity)) == 0)
		{
			//printf("Parse bien el precio\n");
			ret = 0;
		}
	}

	return ret;
}

//---------------------------------------------------------------------------------------

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
int controlServicesEntry(char* id)
{
	/*Por el apuro no pude crear funciones que validen el mail y el nombre con numeros etc, despues lo hago..*/
	int ret;

	ret = -1;

	if(id != NULL)
	{
		if(esNumero(id, strlen(id)) == 0)
		{
			//printf("Parse bien el precio\n");
			ret = 0;
		}
	}

	return ret;

}


