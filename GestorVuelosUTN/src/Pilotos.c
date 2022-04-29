#include "Pilotos.h"

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Crea un dato de tipo ePiloto* en memoria dinamica
 *
 * \param void
 * \return el auxiliar creado o NULL si no se consiguio espacio
 *
 */

ePiloto* newPilot(void)
{
	ePiloto* ret;

	return ret = (ePiloto*) calloc(1,sizeof(ePiloto));

}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief crea un dato de tipo ePiloto* y completa sus campos..
 *
 * \param auxIdPiloto (id del piloto)
 * \param piloto (nombre del piloto)
 * \return el auxiliar creado o NULL si no se logro crear
 *
 */

ePiloto* newPilot_parameters(char* idPiloto, char* piloto)
{
	ePiloto* aux;
	int auxIdPiloto;
	char auxNombrePiloto[TAMPILOTOS];

	aux = NULL;

	if(idPiloto != NULL && piloto != NULL)
	{
		aux = newPilot();

		if(aux != NULL)
		{
			auxIdPiloto = atoi(idPiloto);
			printf("Id vale: %d\n",auxIdPiloto);

			strncpy(auxNombrePiloto , piloto , sizeof(auxNombrePiloto));
			printf("Nombre: %s\n",auxNombrePiloto);

			setIdPilot(aux, auxIdPiloto);
			setPilotName(aux, auxNombrePiloto);

		}
	}

	return aux;
}


//--------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------

//                        ************************************GETTERS*********************************
//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief retorna el id del piloto, sacado del dato de tipo ePiloto pasado por parametro...
 *
 * \param ePiloto* this (dato de tipo ePiloto)
 * \param *idPiloto (espacio donde se va a almacenar y retornar el id)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */

int getIdPilot(ePiloto* this , int* idPiloto)
{
	int ret;

	ret = -1;

	if(this != NULL && idPiloto != NULL)
	{
		ret = 0;
		*idPiloto = this->idPiloto;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief retorna el nombre del piloto, sacado del dato de tipo ePiloto pasado por parametro...
 *
 * \param ePiloto* this (dato de tipo ePiloto)
 * \param *nombrePiloto (espacio donde se va a almacenar y retornar el nombre)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */

int getPilotName(ePiloto* this , char* nombrePiloto)
{
	int ret;

	ret = -1;

	if(this != NULL && nombrePiloto != NULL)
	{
		ret = 0;
		strcpy(nombrePiloto , this->nombrePiloto);
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------
//                        ************************************SETTERS*********************************
//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief asigna el id del piloto a un dato de tipo ePiloto..
 *
 * \param ePiloto* this (dato de tipo ePiloto)
 * \param idPiloto (id del piloto)
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */

int setIdPilot(ePiloto* this , int idPiloto)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->idPiloto = idPiloto;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief asigna el nombre del piloto a un dato de tipo ePiloto..
 *
 * \param ePiloto* this (dato de tipo ePiloto)
 * \param nombrePiloto (nombre del piloto)
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */

int setPilotName(ePiloto* this , char* nombrePiloto)
{
	int ret;

	ret = -1;

	if(this != NULL && nombrePiloto != NULL)
	{
		ret = 0;
		strcpy(this->nombrePiloto , nombrePiloto);
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Busca el id del piloto en la lista de pilotos, si lo encuentra corta y devuelve ese dato de tipo ePiloto ...
 *
 * \param LinkedList* this (lista de pilotos)
 * \param idPiloto (id a buscar)
 * \return NULL si fallan nulls o no se encuentra el id , sino devuelve el dato de tipo eEditorial
 *
 */

ePiloto* findPilotId(LinkedList* this , int idPiloto)
{
	ePiloto* retorno;
	int i;
	int largo;
	ePiloto* aux;
	int idRelacion;

	retorno = NULL;

	if(this != NULL)
	{
		largo = ll_len(this);

		for(i=0 ; i<largo ; i++)
		{
			aux = ll_get(this, i);
			getIdPilot(aux, &idRelacion);
			if(idRelacion == idPiloto)
			{
				retorno = aux;
				break;

			}
		}
	}

	return retorno;

}
