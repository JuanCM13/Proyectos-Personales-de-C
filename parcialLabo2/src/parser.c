#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eEditoriales.h"
#include "eLibros.h"
#include "parser.h"

/** \brief Parsea los datos de los libros desde el archivo pasado por parametro (modo texto).
 *
 * \param pFile FILE* (archivo)
 * \param pArrayListBooks LinkedList* (lista libros)
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se consigue lugar para cargar la lista , -2;
 * /FALLO EL PARSEO DE DATOS ,-4 No se encontro ese archivo
 */
int parser_bookFromText(FILE* pFile , LinkedList* pArrayListBooks)
{

	int ret;
	char auxiliarId[10];
	char auxiliarIdEditorial[100];
	char auxiliarPrecio[100];
	char auxiliarTitulo[100];
	char auxiliarAutor[100];
	eLibro* aux;

	ret = -1;

	if(pFile != NULL && pArrayListBooks != NULL)
	{
		//printf("Entre al parser..\n");
		ret = 0;

		fscanf(pFile , "%[^,], %[^,], %[^,], %[^,], %[^\n]\n" , auxiliarId , auxiliarTitulo , auxiliarAutor , auxiliarPrecio , auxiliarIdEditorial);

		while(!feof(pFile))
		{
			if(fscanf(pFile , "%[^,], %[^,], %[^,], %[^,], %[^\n]\n"  , auxiliarId , auxiliarTitulo , auxiliarAutor , auxiliarPrecio , auxiliarIdEditorial) == 5)
			{
				//printf(" %s  %s  %s  %s %s \n", auxiliarId , auxiliarTitulo , auxiliarAutor , auxiliarPrecio , auxiliarIdEditorial);

				if(validarParametrosLibro(auxiliarId,auxiliarTitulo ,auxiliarAutor , auxiliarPrecio , auxiliarIdEditorial) == 0)
				{

					aux = newBookParameters(auxiliarId , auxiliarTitulo , auxiliarAutor , auxiliarPrecio , auxiliarIdEditorial);

					if(aux != NULL)
					{
						//printf(" %d  %s  %s  %d %d \n", aux->id , aux->titulo , aux->autor , aux->precio , aux->idEditorial);
						ll_add( pArrayListBooks , aux);
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


/** \brief Parsea los datos de las editoriales desde el archivo pasado por parametro (modo texto).
 *
 * \param pFile FILE* (archivo)
 * \param pArrayListEditorials LinkedList* (lista editoriales)
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se consigue lugar para cargar la lista , -2;
 * /FALLO EL PARSEO DE DATOS ,-4 No se encontro ese archivo
 */
int parser_editorialsFromText(FILE* pFile , LinkedList* pArrayListEditorials)
{
	int ret;
	char auxIdEditorial[100];
	char auxNombreEditorial[100];
	eEditorial* auxEdit;

	ret = -1;

	if(pFile != NULL && pArrayListEditorials != NULL)
	{
		ret = 0;

		fscanf(pFile , "%[^,], %[^\n]\n",auxIdEditorial , auxNombreEditorial);

		while(!feof(pFile))
		{
			if(fscanf(pFile , "%[^,],%[^\n]\n",auxIdEditorial , auxNombreEditorial) == 2)
			{
				//printf("idEditorial:%s -- nombre: %s -- \n",auxIdEditorial, auxNombreEditorial);

				if(validarParametrosEditorial(auxIdEditorial , auxNombreEditorial) == 0)
				{
					auxEdit = newEditorialParameters(auxIdEditorial , auxNombreEditorial);

					if(auxEdit != NULL)
					{
						ll_add(pArrayListEditorials , auxEdit);
					}
					else
					{
						ret = -3;
					}
				}
				else
				{
					ret = -4;
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

//----------------------------------------------------------------------------------------------------


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
int validarParametrosLibro(char* id , char* titulo , char* autor , char* precio , char*idEditorial)
{
	int ret;

	ret = -1;

	if(id != NULL && titulo != NULL && autor != NULL && precio != NULL && idEditorial != NULL)
	{

		if(esNumero(id,strlen(id)) == 0)
		{
			//printf("Parse bien el id\n");
			ret = 0;
		}
		ret = -1;

		if(esNumero(idEditorial , strlen(idEditorial)))
		{
			//printf("Parse bien el id de la editorial\n");
			ret = 0;
		}
		ret = -1;

		if(esFloat(precio , strlen(precio)) == 0)
		{
			//printf("Parse bien el precio\n");
			ret = 0;
		}
		ret = -1;

		if(sonLetras(titulo , strlen(titulo)) == 0)
		{
			//printf("Parse bien el titulo\n");
			ret = 0;
		}

		ret = -1;

		if(sonLetras(autor , strlen(autor)) == 0)
		{
			//printf("Parse bien el autor\n");
			ret = 0;
		}

	}

	return ret;
}

//---------------------------------------------------------------------------------------


/** \brief Valida si los parametros recibidos sacados del archivo de editoriales estan bien cargados (que sean solo numeros, etc).
 *
 * \param char* idEditorial
 * \param char* nombreEditorial
 * \return 0 si los datos estan ok , -1 fallan nulls o algun dato esta mal validado
 *
 */
int validarParametrosEditorial(char* idEditorial , char* nombreEditorial)
{
	int ret;

	ret = -1;

	if(idEditorial != NULL && nombreEditorial != NULL)
	{
		if(esNumero(idEditorial,strlen(idEditorial)) == 0)
		{
			//printf("Parse bien el id\n");
			ret = 0;
		}
		ret = -1;


		if(sonLetras(nombreEditorial , strlen(nombreEditorial)) == 0)
		{
			//printf("Parse bien el autor\n");
			ret = 0;
		}

	}

	return ret;
}
