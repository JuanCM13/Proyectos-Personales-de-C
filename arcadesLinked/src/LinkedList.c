#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{

    LinkedList* this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this-> pFirstNode = NULL;
    	this-> size = 0;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    	//printf("Cantidad de nodos: %d\n",this->size);
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int i;
	Node* ret;
	int largo;
	Node* referencia;

	largo = ll_len(this);
	ret = NULL;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < largo)
	{
		referencia = this->pFirstNode;

		for(i=0 ; i<nodeIndex ; i++)
		{
			referencia = referencia->pNextNode;
		}

		ret = referencia;
	}

    return ret;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux;
	int largo;
	Node* auxiliarUno;
	Node* anterior;

	returnAux = -1;

	largo = ll_len(this);

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= largo)
	{
		auxiliarUno = (Node*) calloc(1 , sizeof(Node));

		if(auxiliarUno != NULL)
		{
			auxiliarUno->pElement = pElement;
			auxiliarUno->pNextNode = NULL;

			if(nodeIndex == 0)
			{
				auxiliarUno->pNextNode = this->pFirstNode;
				this->pFirstNode = auxiliarUno;
			}
			else
			{
				anterior = getNode(this , nodeIndex-1);
				auxiliarUno->pNextNode = anterior->pNextNode;
				anterior->pNextNode = auxiliarUno;

			}
			this->size = this->size + 1;
			returnAux = 0;
		}
	}

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int largo;

    if(this != NULL)
    {
    	largo = ll_len(this);

    	returnAux = addNode(this, largo , pElement);
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int largo;
    Node* aux;

    largo = ll_len(this);

    if(this != NULL && index >= 0 && index < largo)
    {
    	aux = getNode(this , index);

    	if(aux != NULL)
    	{
    		returnAux = aux->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int largo;
    Node* aux;

    largo = ll_len(this);

    if(this != NULL && index >= 0 && index < largo)
    {
    	aux = getNode(this , index);
    	aux->pElement = pElement;

    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int largo;
    Node* nodoAeliminar;
    Node* nodoAnterior;

    largo = ll_len(this);

    if(this != NULL && index >= 0 && index < largo)
    {
    	nodoAeliminar = getNode(this , index);

    	if(index == 0)
    	{
    		this->pFirstNode = nodoAeliminar->pNextNode;	//si es el primer nodo, tengo que atar la cabeza de la linkedList al next del que voy a borrar
    	}
    	else
    	{
    		nodoAnterior = getNode(this , index -1); //necesito el anterior del que borro asi enlazo el anterior del que borro con el proximo del que borro
			nodoAnterior->pNextNode = nodoAeliminar->pNextNode;
    	}

    	this->size--;
    	returnAux = 0;
    	free(nodoAeliminar);

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int largo;

    if(this != NULL)
    {
        largo = ll_len(this);

        for(i=largo-1 ; i>=0 ; i--)		//ir del ultimo al primero asi cuando llega al primero el pNextNode (posicion 1) ya no existe...
        {
        	if(ll_remove(this , i) == 0)
        	{
        		returnAux = 0;
        	}
        }
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_clear(this) == 0)
    	{
    		free(this);
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int largo;
    int i;

    if(this != NULL)
    {
    	largo = ll_len(this);

    	for(i=0 ; i<largo ; i++)
    	{
    		if(ll_get(this , i) == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 1; //La lista estaria vacia

    	if(this->size > 0)
    	{
    		returnAux = 0; //No ewsta vacia
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int largo;

    largo = ll_len(this);

    if(this != NULL && index > -1 && index <= largo)
    {
    	returnAux = addNode(this , index , pElement);
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int largo;

    largo = ll_len(this);

    if(this != NULL && index >= 0 && index < largo)
	{
    	returnAux = ll_get(this , index);
    	ll_remove(this , index);
	}

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;

    	if(ll_indexOf(this , pElement) != -1)
    	{
    		returnAux = 1;
    	}

    }


    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    Node* auxDos;
    int largoDos;
    int i;

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;

    	largoDos = ll_len(this2);

    	for(i=0 ; i<largoDos ; i++ )
    	{
    		auxDos = ll_get(this2 , i);

    		if(ll_contains(this ,auxDos) == 0)
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    int largo;

    largo = ll_len(this);

    if(this != NULL && from >= 0 && from <= largo && to > from && to <= largo && largo >= 0) //preguntar si validar que largo sea >= 0 esta bien
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
    		for(i=from ; i<to ; i++)
    		{
    			if(ll_add(cloneArray , ll_get(this , i)) != 0)
    			{
    				cloneArray = NULL;
    				break;
    			}
    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int largo;

    largo = ll_len(this);

    cloneArray = ll_subList(this , 0 , largo);

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux = -1;
	int i;
	int j;
	int largo;
    void* auxSwap;
    void* auxUnoPelement;
    void* auxDosPelement;

	if(this != NULL && pFunc != NULL && (order == 1 || order == 0) )
	{
		largo = ll_len(this);

		for(i=0 ; i<largo-1 ; i++)
		{
			//auxUnoPelement = ll_get(this , i); //ACORDARSE QUE ESTE TIENE QUE IR SI O SI DENTRO DEL SEGUNDO FOR, SINO NUNCA SE ACTUALIZA
			//ACORDARSE QUE ME ROMPI LA CABEZA 2 DIAS POR ESTO!!!!!!!!!!!!!!!!!
			for(j=i+1 ; j<largo ; j++)
			{
				auxUnoPelement = ll_get(this , i);
				auxDosPelement = ll_get(this , j);

				if( (order == 1 && pFunc(auxUnoPelement , auxDosPelement) > 0) || (order == 0 && pFunc(auxUnoPelement , auxDosPelement) < 0) )
				{
					auxSwap = auxUnoPelement;
					ll_set(this , i , auxDosPelement);
					ll_set(this , j , auxSwap);
				}

			}
		}

		returnAux = 0;
	}

	return returnAux;
}

//---------------------------------------------------------------

/** \brief Genera una lista y guarda el elemento segun el resultado de fn() si devuelve 1 guarda si devuelve 0 no..
 * \param pList LinkedList* Puntero a la lista
 * \param fn (*fn) Puntero a la funcion criterio
 * \return LinkedList* lista en caso de que se almacene algun elemento en la lista //
 * 						NULL si falla la nullidad o no se almacena ningun elemento en la lista
 */

LinkedList* ll_filter(LinkedList* this , int (*fn)(void*))
{
	LinkedList* segundaLista;
	int i;
	int largo;
	void* pElement;
	int bandera;

	segundaLista = NULL;

	if(this != NULL && fn != NULL)
	{
		bandera = 0;
		largo = ll_len(this);
		segundaLista = ll_newLinkedList();

		if(segundaLista != NULL)
		{
			for(i=0 ; i<largo ; i++)
			{
				pElement = ll_get(this, i);

				if(fn(pElement) == 1)
				{
					bandera = 1;
					ll_add(segundaLista , pElement);
				}
			}
		}
	}

	if(bandera == 0) //Si no llega a haber ningun elemento de el tipo indicado en la lista..
	{
		ll_deleteLinkedList(segundaLista);
		segundaLista = NULL;
	}

	return segundaLista;
}


//---------------------------------------------------------------

/** \brief Cuenta o almacena segun lo devuelto por la funcion criterio
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int acumulador;
	int i;
	int largo;
	void* pElement;

	acumulador = -1; //Fallan los nulls o la lista esta vacia

	if(this != NULL && fn != NULL)
	{
		largo = ll_len(this);

		if(largo > 0)
		{
			acumulador = 0;

			for(i=0 ; i<largo ; i++)
			{
				pElement = ll_get(this, i);
				acumulador += fn(pElement);
			}
		}
	}

	return acumulador;
}


//-------------------------------------------------------------------------------------------------

LinkedList* ll_map(LinkedList* this , int(*fn)(void* pElement) )
{
	int largo;
	int i;
	void* element;

	if(this != NULL && fn != NULL)
	{
		largo = ll_len(this);

		if(largo > 0)
		{
			for(i=0 ; i<largo ; i++)
			{
				element = ll_get(this , i);
				fn(element);

			}

		}

	}

	return this;
}

