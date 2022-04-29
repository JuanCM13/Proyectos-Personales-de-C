#include "Nexo.h"

//-----------------------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Muestra menu de opciones y pide la opcion seleccionada
 * @param int* respuesta: Espacio de memoria para guardar la opcion seleccionada
 * @return Retorna -1 si hubo un error en el pedido o los nulls, 0 si se obtuvo correctamente la opcion
 */
int printMenu(int* option)
{
	int ret;

	ret = -1;

	if(option != NULL)
	{
		ret = 0;

		printf("|----------------------------------------------------------|\n");
		printf("|	1) Alta Usuario                                   |\n");
		printf("|	2) Modificar datos del usuario                    |\n");
		printf("|	3) Publicar Producto                              |\n");
		printf("|	4) Baja Usuario                                   |\n");
		printf("|	5) Modificar Publicacion                          |\n");
		printf("|	6) Cancelar Publicacion                           |\n");
		printf("|	7) Comprar Producto                               |\n");
		printf("|	8) Listar Publicaciones del Usuario               |\n");
		printf("|	9) Listar Publicaciones                           |\n");
		printf("|	10) Listar Usuarios                               |\n");
		printf("|	11) Salir                                         |\n");
		printf("|----------------------------------------------------------|\n");

		Get_numeroConLimites("Ingrese una opcion del menu..", "Error, reingrese..", 1, 11 , option);
	}

	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------


//-------------------------------------------------------------------------

/**
 * @brief Carga un usuario en el array de eUsers
 * @param userList* Array de tipo eUser
 * @param listLen largo del array
 * @param *idUser puntero a la variable de id del usuario
 * @return Retorna -1 si hubo un error en los nulls, -2 si no hay lugar disponible , -3 si cancela la operacion, 0 si todo ok
 */
int loadProduct(eProduct* productList , int listLen , int* idProduct , eUser* userList , int userListLen)
{
	int ret;
	int freeIndex;
	eProduct aux;
	int userId;
	int userIdIndex;

	ret = -1; //fallan nulls
	if(productList != NULL && listLen > 0 && idProduct != NULL)
	{
		ret = -2; //No hay lugar disponible

		freeIndex = getFreeIndexProduct(productList, listLen);
		if(freeIndex > -1)
		{
			ret = -4; //no se emcontro ese id...

			userId = selectUserId(userList , userListLen);
			userIdIndex = findUserIndexById(userList , userListLen , userId);

			if(userIdIndex > -1)
			{
				ret = -3; //cancelo operacion
				aux = generateProduct();

				if(QueresSeguir("Seguro que desea cargar este producto?? s/n") == 0)
				{
					ret = 0;
					*idProduct = *idProduct+1;
					aux.idProduct = *idProduct;
					aux.isEmpty = 0;
					aux.idRelation = userId;
					productList[freeIndex] = aux;
				}
			}
		}
	}

	return ret;
}
