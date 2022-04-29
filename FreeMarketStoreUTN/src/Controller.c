#include "Controller.h"

int controller_loadUsers(eUser* userList , int userListLen , int* userId)
{
	int ret;
	int programFlow;

	ret = -1;
	if(userList != NULL && userListLen > 0 && userId != NULL)
	{
		ret = 0;

		programFlow = loadUser(userList , userListLen , userId);
		switch(programFlow)
		{
			case 0:
				printf("El usuario fue cargado de manera exitosa..\n");
			break;
			case -1:
				printf("Algo fallo, reintente..\n");
			break;
			case -2:
				printf("No hay mas lugar en la lista, puede dar de baja un usuario y asi volver a cargar otro..\n");
			break;
			case -3:
				printf("Operacion cancelada..\n");
			break;
		}
	}
	return ret;
}

int controller_modUser(eUser* userList , int userListLen)
{
	int ret;
	int programFlow;

	ret = -1;
	if(userList != NULL && userListLen > 0)
	{
		if(isThereAnyLoadUser(userList, userListLen) == 0)
		{
			ret = 0;

			programFlow = modUser(userList , userListLen);
			switch(programFlow)
			{
				case 0:
					printf("El usuario fue modificado de manera exitosa..\n");
				break;
				case -1:
					printf("Algo fallo, reintente..\n");
				break;
				case -2:
					printf("Ese usuario no se encontro en la lista, reintente..\n");
				break;
				case -3:
					printf("Operacion cancelada..\n");
				break;
			}
		}
		else
		{
			printf("Para ingresar a esta opcion debe haber al menos 1 cliente cargado..\n");
		}
	}
	return ret;
}


int controller_loadProduct(eProduct* productList , int productListLen , int* productId , eUser* userList, int userLen)
{
	int ret;
	int programFlow;

	ret = -1;

	if(productList != NULL && productListLen > 0 && productId != NULL)
	{
		ret = 0;
		printf("Entre...\n");
		if(isThereAnyLoadUser(userList, userLen) == 0)
		{
			programFlow = loadProduct(productList , productListLen , productId , userList, userLen);
			switch(programFlow)
			{
				case 0:
					printf("El producto fue cargado de manera exitosa..\n");
				break;
				case -1:
					printf("Algo fallo, reintente..\n");
				break;
				case -2:
					printf("No hay mas lugar en la lista, puede dar de baja un producto y asi volver a cargar otro..\n");
				break;
				case -3:
					printf("Operacion cancelada..\n");
				break;
				case -4:
					printf("El id del usuario ingresado no existe, reintente..\n");
				break;

			}
		}
		else
		{
			printf("Para ingresar a este campo, debe haber ingresado almenos 1 cliente en la lista..\n");
		}
	}
	return ret;
}
