#include "Controller.h"

#define TAMARCHIVO 200
//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Carga los datos de libros desde archivo ingresado por el usuario (modo texto).
 *
 * \param pArrayBookList LinkedList*
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se consigue lugar para cargar la lista , -2;
 * //FALLO EL PARSEO DE DATOS ,-4 No se encontro ese archivo
 *
 */

int controller_loadBooksFromText(LinkedList* pArrayBookList)
{
	int ret;
	char archivo[TAMARCHIVO];
	FILE* pFile;

	ret = -1;

	if(pArrayBookList != NULL)
	{
		ret = -4;

		Get_cadena("Ingrese el nombre del archivo a gestionar..","Error el nombre del archivo no puede ser tan grande..",archivo , TAMARCHIVO);

		pFile = fopen(archivo , "r");

		if(pFile != NULL)
		{
			ret = parser_bookFromText(pFile , pArrayBookList);
			fclose(pFile);
		}

	}

    return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Carga los datos de editoriales desde archivo seleccionado por el usuario (modo texto).
 *
 * \param pArrayEditorialsList LinkedList*
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se consigue lugar para cargar la lista , -2;
 * //FALLO EL PARSEO DE DATOS ,-4 No se encontro ese arc
 *
 */

int controller_loadEditorialsFromText(LinkedList* pArrayEditorialsList)
{
	int ret;
	char archivo[TAMARCHIVO];
	FILE* pFile;

	ret = -1;

	if(pArrayEditorialsList != NULL)
	{
		ret = -4;

		Get_cadena("Ingrese el nombre del archivo a gestionar..","Error el nombre del archivo no puede ser tan grande..",archivo , TAMARCHIVO);

		pFile = fopen(archivo , "r");

		if(pFile != NULL)
		{
			ret = parser_editorialsFromText(pFile , pArrayEditorialsList);
			fclose(pFile);
		}

	}

    return ret;
}


//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Ordena la lista de libros con respecto a los autores, de manera ascendente
 * \param this LinkedList*
 * \return int 0 si ordeno bien, != 0 si fallo el ordenamiento
 *
 */
int controller_organizeAutors(LinkedList* this)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = ll_sort(this , ordenarPorAutor , 1);
	}

	return ret;
}


//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Imprime la lista de libros junto con su debida editorial
 * \param this1 LinkedList* (lista libros)
 * \param this2 LinkedList* (lista editoriales)
 * \return -1 si imprimio mal
 *
 */
int controller_printBooks(LinkedList* this1 , LinkedList* this2)
{
	int ret;

	ret = -1;

	if(this1 != NULL && this2 != NULL)
	{
		printf("Entre al controller..\n");
		ret = imprimirLibros(this1 , this2);
	}

	return ret;
}


//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief genera un archivo de lista de libros de la editorial Minotauro
 * \param listaLibros LinkedList* (lista libros)
 * \param listaEditoriales LinkedList* (lista editoriales)
 * \return -1 si imprimio mal , 1 si creo bien y decide mostrar la lista, 0 si creo bien pero no decidio mostrar la lista
 *
 */
int controller_generateMinotauroList(LinkedList* listaLibros , LinkedList* listaEditoriales)
{
	int ret;
	LinkedList* listaGenerada;

	ret = -1;

	if(listaLibros != NULL && listaEditoriales != NULL)
	{
		listaGenerada = (LinkedList*) ll_filter(listaLibros , filtroEditorial);

		if(listaGenerada != NULL)
		{
			if(controller_saveBookAsText(listaGenerada) == 0)
			{
				ret = 0;

				if(QueresSeguir("Desea imprimir la lista generada? s/n \n") == 0)
				{
					ret = 1; //ASI EN EL SWITCH DEL MAIN NO MUESTRO EL MENSAJE DE QUE SE CONSIGUIO BIEN LA LISTA..
					imprimirLibros(listaGenerada , listaEditoriales);
				}
			}
		}

	}

	return ret;
}


//---------------------------------------------------------------------------------------------------------------------------------------------


/** \brief Guarda lista pasada por parametro en un archivo, en este caso lo guarda en el archivo creado o pisado Listado_Minotauro.csv
 *
 * \param pListaLibros LinkedList*
 * \return int 0 si sale todo ok, -1 fallan nulls , -2 No se pudo cargar el archivo
 *
 */

int controller_saveBookAsText(LinkedList* pListaLibros)
{
	int ret;
	int i;
	int largo;

	//auxiliares datos
	int idAux;
	int idRelacionAux;
	char tituloAux[TAMNOMBRELIBRO];
	char autorAux[TAMNOMBREAUTOR];
	float precioAux;

	FILE* pFile;
	eLibro* libroAux;

	ret = -1;

	if(pListaLibros != NULL)
	{
		ret = -2; //Fallo la carga del archivo

		pFile = fopen(NOMBREARCHIVOMINOTAURO,"w");

		if(pFile != NULL)
		{
			largo = ll_len(pListaLibros);

			for(i=0 ; i<largo ; i++)
			{
				libroAux = ll_get(pListaLibros , i);

				getBookId(libroAux , &idAux);
				getBookIdEditorial(libroAux, &idRelacionAux);
				getBookTitle(libroAux, tituloAux);
				getBookAuthor(libroAux, autorAux);
				getBookPrice(libroAux, &precioAux);

				fprintf(pFile , "%d,%s,%s,%f,%d", idAux , tituloAux , autorAux , precioAux , idRelacionAux);
				ret = 0;

			}

			fclose(pFile);
		}

	}

	if(ret == -2) //si no se pudo cargar el archivo por x elimino la lista de minotauro creada
	{
		ll_deleteLinkedList(pListaLibros);
	}

    return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

int controllerDescount(LinkedList* listaLibros , LinkedList* listaEditoriales)
{
	int ret;
	LinkedList* listaGenerada;
	ret = -1;

	if(listaLibros != NULL)
	{
		listaGenerada = ll_map(listaLibros , funcionDescuentoPorEditorial);

		if(listaGenerada != NULL)
		{
			ret = 0;
			imprimirLibros(listaGenerada, listaEditoriales);
			controller_saveDescountListAsText(listaGenerada);
		}

	}

	return ret;
}

//-------------------------------------------------------------------------------------------------------------------------------------------



int controller_saveDescountListAsText(LinkedList* pListaLibros)
{
	int ret;
	int i;
	int largo;

	//auxiliares datos
	int idAux;
	int idRelacionAux;
	char tituloAux[TAMNOMBRELIBRO];
	char autorAux[TAMNOMBREAUTOR];
	float precioAux;

	FILE* pFile;
	eLibro* libroAux;

	ret = -1;

	if(pListaLibros != NULL)
	{
		ret = -2; //Fallo la carga del archivo

		pFile = fopen("Lista_librosConDescuento.csv","w");

		if(pFile != NULL)
		{
			largo = ll_len(pListaLibros);

			for(i=0 ; i<largo ; i++)
			{
				libroAux = ll_get(pListaLibros , i);

				getBookId(libroAux , &idAux);
				getBookIdEditorial(libroAux, &idRelacionAux);
				getBookTitle(libroAux, tituloAux);
				getBookAuthor(libroAux, autorAux);
				getBookPrice(libroAux, &precioAux);

				fprintf(pFile , "%d,%s,%s,%f,%d", idAux , tituloAux , autorAux , precioAux , idRelacionAux);
				ret = 0;

			}

			fclose(pFile);
		}

	}

	if(ret == -2) //si no se pudo cargar el archivo por x elimino la lista de minotauro creada
	{
		ll_deleteLinkedList(pListaLibros);
	}

    return ret;
}
