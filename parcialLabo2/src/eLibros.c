#include "eLibros.h"

//------------------------------------------------------------------------------------------------------------------


/** \brief Crea un dato de tipo eLibro* en memoria dinamica
 *
 * \param void
 * \return el auxiliar creado o NULL si no se consiguio espacio
 *
 */
eLibro* newBook(void)
{
	eLibro* auxiliar;

	return auxiliar = (eLibro*) calloc(1,sizeof(eLibro));
}

//------------------------------------------------------------------------------------------------------------------


/** \brief crea un dato de tipo eLibro* y completa sus campos..
 *
 * \param char* id (id del libro)
 * \param char* titulo (titulo del libro)
 * \param char* autor (autor del libro)
 * \param char* precio (precio del libro)
 * \param char*idEditorial (id de la editorial)
 * \return el auxiliar creado o NULL si no se logro crear
 *
 */
eLibro* newBookParameters(char* id , char* titulo , char* autor , char* precio , char*idEditorial)
{
	eLibro* aux;
	int auxId;
	int auxIdEditorial;
	float auxPrecio;
	char auxTitulo[TAMNOMBRELIBRO];
	char auxAutor[TAMNOMBREAUTOR];

	aux = NULL;

	if(id != NULL && titulo != NULL && autor != NULL && precio != NULL && idEditorial != NULL)
	{
		//printf("Entre a newBook\n");

		aux = newBook();

		if(aux != NULL)
		{
			//----------------------------------------------------------INICIO PARSEOS

			auxId = atoi(id);
			//printf("id: %d\n",auxId);

			auxIdEditorial = atoi(idEditorial);
			//printf("idEditorial: %d\n",auxIdEditorial);

			auxPrecio = atof(precio);
			//printf("Precio: %d\n",auxPrecio);

			strncpy(auxTitulo , titulo , sizeof(auxTitulo));
			//printf("Titulo: %s\n",auxTitulo);

			strncpy(auxAutor , autor , sizeof(auxAutor));
			//printf("Autor: %s\n",auxAutor);

			//--------------------------------------------------------- INICIO SETTEOS

			setBookId(aux , auxId);
			//printf("id: %d\n",aux->id);
			setBookidEditorial(aux , auxIdEditorial);
			//printf("idEditorial: %d\n",aux->idEditorial);
			setBookPrecio(aux , auxPrecio);
			//printf("Titulo: %d\n",aux->precio);
			setBookTitulo(aux , auxTitulo);
			//printf("Titulo: %s\n",aux->titulo);
			setBookAutor(aux , auxAutor);
			//printf("Autor: %s\n",aux->autor);

		}
	}

	return aux;
}

//------------------------------------------------------------------------------------------------------------------




					//*********************************SETTERS***********************************



//------------------------------------------------------------------------------------------------------------------


/** \brief asigna el id del libro a un dato de tipo eLibro ..
 *
 * \param eLibro* this (dato de tipo eLibro)
 * \param id (id del libro)
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */
int setBookId(eLibro* this , int id)
{
	int ret;

	ret = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------


/** \brief asigna el idEditorial del libro a un dato de tipo eLibro ..
 *
 * \param eLibro* this (dato de tipo eLibro)
 * \param idEditorial (id de la editorial )
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */
int setBookidEditorial(eLibro* this , int idEditorial)
{
	int ret;

	ret = -1;

	if(this != NULL && idEditorial > 0)
	{
		this->idEditorial = idEditorial;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------


/** \brief asigna el precio del libro a un dato de tipo eLibro ..
 *
 * \param eLibro* this (dato de tipo eLibro)
 * \param precio (precio del libro )
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */
int setBookPrecio(eLibro* this , float precio)
{
	int ret;

	ret = -1;

	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------


/** \brief asigna el titulo del libro a un dato de tipo eLibro ..
 *
 * \param eLibro* this (dato de tipo eLibro)
 * \param titulo (titulo del libro )
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */
int setBookTitulo(eLibro* this , char* titulo)
{
	int ret;

	ret = -1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(this->titulo , titulo);
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------


/** \brief asigna el autor del libro a un dato de tipo eLibro ..
 *
 * \param eLibro* this (dato de tipo eLibro)
 * \param autor (autor del libro )
 * \return -1 si falla nulls , 0 si asigna bien
 *
 */
int setBookAutor(eLibro* this , char* autor)
{
	int ret;

	ret = -1;

	if(this != NULL && autor != NULL)
	{
		strcpy(this->autor , autor);
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


/** \brief retorna el id del libro del dato de tipo eLibro pasado por parametro...
 *
 * \param eLibro* this (dato de tipo eLibro)
 * \param *id (espacio donde se va a almacenar y retornar el id del libo)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */
int getBookId(eLibro* this , int* id)
{
	int ret;

	ret = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------


/** \brief retorna el idBookEditorial del libro del dato de tipo eLibro pasado por parametro...
 *
 * \param eLibro* this (dato de tipo eLibro)
 * \param *idBookEditorial (espacio donde se va a almacenar y retornar el idBookEditorial del libo)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */
int getBookIdEditorial(eLibro* this , int* idBookEditorial)
{
	int ret;

	ret = -1;

	if(this != NULL && idBookEditorial != NULL)
	{
		*idBookEditorial = this->idEditorial;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------


/** \brief retorna el precio del libro del dato de tipo eLibro pasado por parametro...
 *
 * \param eLibro* this (dato de tipo eLibro)
 * \param *bookPrice (espacio donde se va a almacenar y retornar el precio del libo)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */
int getBookPrice(eLibro* this , float* bookPrice)
{
	int ret;

	ret = -1;

	if(this != NULL && bookPrice != NULL)
	{
		*bookPrice = this->precio;
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------


/** \brief retorna el titulo del libro del dato de tipo eLibro pasado por parametro...
 *
 * \param eLibro* this (dato de tipo eLibro)
 * \param *bookName (espacio donde se va a almacenar y retornar el titulo del libo)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */
int getBookTitle(eLibro* this , char* bookName)
{
	int ret;

	ret = -1;

	if(this != NULL && bookName != NULL)
	{
		strcpy(bookName , this->titulo);
		ret = 0;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------


/** \brief retorna el autor del libro del dato de tipo eLibro pasado por parametro...
 *
 * \param eLibro* this (dato de tipo eLibro)
 * \param *bookAuthor (espacio donde se va a almacenar y retornar el autor del libo)
 * \return -1 si falla nulls , 0 si retorna bien
 *
 */
int getBookAuthor(eLibro* this , char* bookAuthor)
{
	int ret;

	ret = -1;

	if(this != NULL && bookAuthor != NULL)
	{
		strcpy(bookAuthor , this->autor);
		ret = 0;
	}

	return ret;
}


//------------------------------------------------------------------------------------------------------------------
//**********************************************FIN GETTERS*********************************************************
//------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------


/** \brief Compara dos elementos de tipo void* ...
 *
 * \param void* elementoUno
 * \param void* elementoDos
 * \return > 0 si ordena ascendente , < o descendente , 0 si es igual
 *
 */
int ordenarPorAutor(void* elementoUno , void* elementoDos)
{
	int ret;
	eLibro* elementoA;
	eLibro* elementoB;
	char autorUno[TAMNOMBREAUTOR];
	char autorDos[TAMNOMBREAUTOR];

	if(elementoUno != NULL && elementoDos != NULL)
	{
		elementoA = (eLibro*) elementoUno;
		elementoB = (eLibro*) elementoDos;

		if( getBookAuthor(elementoA , autorUno) == 0 && getBookAuthor(elementoB , autorDos) == 0 )
		{
			ret = strcmp(autorUno , autorDos);
		}
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------


/** \brief corrobora si el elemento pasado por parametro es del tipo editorial MINOTAURO ...
 *
 * \param void* pElemento
 * \return 0 si no es, 1 si es
 *
 */
int filtroEditorial(void* pElement)
{
	int ret;
	eLibro* aux;
	int idEditorial;

	ret = 0;

	if(pElement != NULL)
	{
		aux = (eLibro*) pElement;

		getBookIdEditorial(aux , &idEditorial);

		if(idEditorial == 4)
		{
			ret = 1;
		}
	}

	return ret;
}


//-----------------------------------------------------------------------------------------------------------------------

int funcionDescuentoPorEditorial(void* pElement)
{
	eLibro* libroAux;
	int ret;
	int edit;
	float precioSinDescuento;
	float descuento;
	float precioConDescuento;

	ret = -1;

	if(pElement != NULL)
	{
		libroAux = (eLibro*) pElement;

		getBookIdEditorial(libroAux , &edit);

		switch(edit)
		{
			case 1: //(Planeta)

				getBookPrice(libroAux , &precioSinDescuento);

				if(precioSinDescuento > 299)
				{
					descuento = precioSinDescuento * 20 / 100;
					precioConDescuento = precioSinDescuento - descuento;

					setBookPrecio(libroAux , precioConDescuento);

					pElement = &libroAux;

					ret = 0;
				}

			break;

			case 2: //(Siglo xx1)

				getBookPrice(libroAux , &precioSinDescuento);

				if(precioSinDescuento < 201)
				{
					descuento = precioSinDescuento * 10 / 100;
					precioConDescuento = precioSinDescuento - descuento;

					setBookPrecio(libroAux , precioConDescuento);

					pElement = &libroAux;

					ret = 0;
				}

			break;
		}

	}

	return ret;
}
