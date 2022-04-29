#include "nexo.h"

//-----------------------------------------------------------------------------------------------------------------------------------

/** \brief Imprime el menu de opciones y pide y retorna la opcion elegida por el usuario
 *
 * \param int* opcion (donde se retorna la opcion elegida)
 * \return 0 si esta todo ok , -1 fallaron nulls
 *
 */

int imprimirMenu(int* opcion)
{
	int ret;

	ret = -1;

	if(opcion != NULL)
	{

		ret = 0;
		printf("\n\n|---------------------------------------------MENU-----------------------------------------------------|\n");
		printf("|	1. Cargar archivo de libros                                                                    |\n");
		printf("|	2. Cargar archivo de editoriales                                                               |\n");
		printf("|	3. Ordenar lista con respecto a los autores de manera ascendente                               |\n");
		printf("|	4. Imprimir datos de libros                                                                    |\n");
		printf("|	5. Realizar listado de los libros de la editorial Minotauro                                    |\n");
		printf("|------------------------------------------------------------------------------------------------------|\n");

		Get_numeroConLimites("Ingrese la opcion del menu..","Error, ingrese una opcion entre las dadas..\n",1,7,opcion);
	}

	return ret;
}


//----------------------------------------------------------------------------------------------------------------------------------------


/** \brief Imprime la lista de libros pasada por parametro con su respectiva editorial
 *
 * \param LinkedList* listaLibros (lista libros)
 * \param LinkedList* listaEditoriales (lista editoriales)
 * \return 0 si imprime bien la lista , -1 fallaron nulls
 *
 */
int imprimirLibros(LinkedList* listaLibros , LinkedList* listaEditoriales)
{
	int ret;
	int largoLibros;
	int largoEditoriales;
	eLibro* auxLibro;
	int auxiliarIdEditorialDelLibro;
	eEditorial* auxEditorial;

	//---------------------


	ret = -1;

	if(listaLibros != NULL && listaEditoriales != NULL)
	{
		largoLibros = ll_len(listaLibros);
		largoEditoriales = ll_len(listaEditoriales);

		if(largoLibros > 0 && largoEditoriales > 0) //Si ambas listas tienen al menos un elemento cargado
		{

			printf("\n\n|------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
			printf("|ID			TITULO							AUTOR				PRECIO				  EDITORIAL	   |\n");
			printf("|------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");

			for(int i=0 ; i<largoLibros ; i++)
			{
				auxLibro = ll_get(listaLibros , i);

				if(auxLibro != NULL)
				{
					getBookIdEditorial(auxLibro , &auxiliarIdEditorialDelLibro);

					auxEditorial = buscarEditorialPorIdRelacion(listaEditoriales , auxiliarIdEditorialDelLibro);

					if(auxEditorial != NULL)
					{
						imprimirUnLibro(auxLibro , auxEditorial);
						ret = 0;
					}
					/*for(int j=0 ; j<largoEditoriales ; j++)
					{
						auxEditorial = ll_get(listaEditoriales , j);

						if(auxEditorial != NULL)
						{
							getIdEditorial(auxEditorial , &auxiliarIdEditorial);

							if(auxiliarIdEditorialDelLibro == auxiliarIdEditorial)
							{
								imprimirUnLibro(auxLibro , auxEditorial);
								ret = 0;

							}
						}
					}*/
				}
			}

			printf("\n|-----------------------------------------------------------------------------------------------------------------------------------------------------------------|\n\n");
		}
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Imprime un libros pasado por parametro con su respectiva editorial
 *
 * \param eLibro* this1  (dato de tipo eLibro)
 * \param eEditorial* this2  (dato de tipo eEditorial)
 * \return 0 si imprime bien , -1 fallaron nulls
 *
 */
int imprimirUnLibro(eLibro* this1 , eEditorial* this2)
{
	int ret;

	ret = -1;

	if(this1 != NULL && this2 != NULL)
	{
		ret = 0;
		printf("|%-10d 		%-50s 	%-30s $ %-10.2f  %30s 													|\n",this1->id ,
				this1->titulo , this1->autor , this1->precio , this2->nombre);
	}


	return ret;

}


//---------------------------------------------------------------------------------------------------------------------------------------------------------
