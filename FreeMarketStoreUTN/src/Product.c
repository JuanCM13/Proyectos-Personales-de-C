#include "Product.h"

/**
 * @brief Inicializa el listado de productos, en vacio, para poder ser cargados
 * @param productList* Array de tipo eProduct
 * @param listLen largo del array
 * @return Retorna -1 si hubo un error en los nulls, 0 si inicializa de manera correcta
 */
int initProductArray(eProduct* productList , int listLen)
{
	int ret;

	ret = -1;
	if(productList != NULL && listLen > 0)
	{
		for(int i=0 ; i<listLen ; i++)
		{
			productList[i].isEmpty = 1;
		}
	}
	return ret;
}

//-------------------------------------------------------------------------

/**
 * @brief Busca y devuelve posicion libre de array de tipo eProduct
 * @param productList* Array de tipo eProduct
 * @param listLen largo del array
 * @return Retorna -2 si hubo un error en los nulls, -1 si no hay lugar disponible , sino devuelve la posicion libre
 */
int getFreeIndexProduct(eProduct* productList , int listLen)
{
	int ret;

	ret = -1; //fallan nulls

	if(productList != NULL && listLen > 0)
	{
		ret = -2; //No hay lugar disponible

		for(int i=0 ; i<listLen ; i++)
		{
			if(productList[i].isEmpty == 1)
			{
				ret = i;
				break;
			}
		}
	}

	return ret;
}


//-------------------------------------------------------------------------

/**
 * @brief Genera un dato del tipo eUser con sus campos llenos
 * @return Retorna el usuario creado
 */
eProduct generateProduct(void)
{
	eProduct aux;

	Get_nombre("Ingrese el nombre del producto, solo letras..", "Error, solo se admiten letras.." , aux.nombre , sizeof(aux.nombre));
	OrdenarNombre(aux.nombre , sizeof(aux.nombre));

	Get_floatConLimites("Ingrese el precio del producto", "Error, debe estar entre 0 y 500000..", 0 , 500000 , &aux.precio);

	Get_numeroConLimites("Ingrese el stock disponible..", "Error, debe ser mayor a cero", 1 , INT_MAX , &aux.stock);

	return aux;
}
