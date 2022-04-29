
#include "eEditoriales.h"

//------------------------------------------------------------------------------------------------------------


/** \brief Crea un dato de tipo eEditorial* en memoria dinamica
 *
 * \param void
 * \return el auxiliar creado o NULL si no se consiguio espacio
 *
 */

eEditorial* newEditorial(void)
{
	eEditorial* aux;

	return aux = (eEditorial*) calloc(1,sizeof(eEditorial));

}

//------------------------------------------------------------------------------------------------------------


/** \brief crea un dato de tipo eEditorial* y completa sus campos..
 *
 * \param idEditorial (id de la editorial)
 * \param nombreEditorial (nombre de la editorial)
 * \return el auxiliar creado o NULL si no se logro crear
 *
 */
eEditorial* newEditorialParameters(char* idEditorial , char* nombreEditorial)
{
	eEditorial* aux;
	int auxIdEditorial;

	aux = NULL;

	if(idEditorial != NULL && nombreEditorial != NULL)
	{
		aux = newEditorial();

		if(aux != NULL)
		{
			auxIdEditorial = atoi(idEditorial);

			setIdEditorial(aux, auxIdEditorial);
			setNombreEditorial(aux , nombreEditorial);
		}
	}

	return aux;
}

//------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------




					//*********************************SETTERS***********************************



//------------------------------------------------------------------------------------------------------------------

/** \brief asigna el id de la editorial a un dato de tipo eEditorial..
 *
 * \param eEditorial* this (dato de tipo eEditorial)
 * \param idEditorial (id de la editorial)
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */
int setIdEditorial(eEditorial* this , int idEditorial)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		this->idEditorial = idEditorial;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------


/** \brief asigna el nombre de la editorial a un dato de tipo eEditorial..
 *
 * \param eEditorial* this (dato de tipo eEditorial)
 * \param nombreEditorial (nombre de la editorial)
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */
int setNombreEditorial(eEditorial* this , char* nombreEditorial)
{
	int ret;

	ret = -1;

	if(this != NULL && nombreEditorial != NULL)
	{
		strcpy(this->nombre , nombreEditorial);
		ret = 0;
	}

	return ret;
}


//------------------------------------------------------------------------------------------------------------------
//**********************************************FIN SETTEOS*********************************************************
//------------------------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------------------------




					//*********************************GETTERS***********************************



//------------------------------------------------------------------------------------------------------------------


/** \brief retorna el nombre de la editorial del dato de tipo eEditorial pasado por parametro...
 *
 * \param eEditorial* this (dato de tipo eEditorial)
 * \param *nombreEditorial (espacio donde se va a almacenar y retornar el nombre)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */
int getNombreEditorial(eEditorial* this , char* nombreEditorial)
{
	int ret;

	ret = -1;

	if(this != NULL && nombreEditorial != NULL)
	{
		ret = 0;
		strcpy(nombreEditorial , this->nombre);
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------


/** \brief retorna el id de la editorial del dato de tipo eEditorial pasado por parametro...
 *
 * \parameEditorial* this (dato de tipo eEditorial)
 * \param *idEditorial (espacio donde se va a almacenar y retornar el id)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */
int getIdEditorial(eEditorial* this , int* idEditorial)
{
	int ret;

	ret = -1;

	if(this != NULL && idEditorial != NULL)
	{
		ret = 0;
		*idEditorial = this->idEditorial;
		//printf("El id de la editorial es: %d\n",idEditorial);
	}

	return ret;
}


//----------------------------------------------------------------------------------------------------------------


/** \brief Busca el idEditorial en la lista de editoriales, si lo encuentra corta y devuelve ese dato de tipo eEditorial ...
 *
 * \param LinkedList* this (lista de editoriales)
 * \param idRelacion (id a buscar)
 * \return NULL si fallan nulls o no se encuentra el id , sino devuelve el dato de tipo eEditorial
 *
 */
eEditorial* buscarEditorialPorIdRelacion(LinkedList* this , int idRelacion)
{
	eEditorial* aux;
	int i;
	int largo;
	int auxId;

	aux = NULL;

	if(this != NULL)
	{
		largo = ll_len(this);

		for(i=0 ; i<largo ; i++)
		{
			aux = ll_get(this , i);
			getIdEditorial(aux , &auxId);

			if(auxId == idRelacion)
			{
				break;
			}
		}
	}

	return aux;
}
