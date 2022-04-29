#include "Users.h"

/**
 * @brief Inicializa el listado de usuarios, en vacio, para poder ser cargados
 * @param userList* Array de tipo eUser
 * @param listLen largo del array
 * @return Retorna -1 si hubo un error en los nulls, 0 si inicializa de manera correcta
 */
int initUserArray(eUser* userList , int listLen)
{
	int ret;

	ret = -1;
	if(userList != NULL && listLen > 0)
	{
		for(int i=0 ; i<listLen ; i++)
		{
			userList[i].isEmpty = 1;
		}
	}
	return ret;
}

//-------------------------------------------------------------------------

/**
 * @brief Busca y devuelve posicion libre de array de tipo eUser
 * @param userList* Array de tipo eUser
 * @param listLen largo del array
 * @return Retorna -2 si hubo un error en los nulls, -1 si no hay lugar disponible , sino devuelve la posicion libre
 */
int getFreeIndexUser(eUser* userList , int listLen)
{
	int ret;

	ret = -1; //fallan nulls

	if(userList != NULL && listLen > 0)
	{
		ret = -2; //No hay lugar disponible

		for(int i=0 ; i<listLen ; i++)
		{
			if(userList[i].isEmpty == 1)
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
 * @brief Carga un usuario en el array de eUsers
 * @param userList* Array de tipo eUser
 * @param listLen largo del array
 * @param *idUser puntero a la variable de id del usuario
 * @return Retorna -1 si hubo un error en los nulls, -2 si no hay lugar disponible , -3 si cancela la operacion, 0 si todo ok
 */
int loadUser(eUser* userList , int listLen , int* idUser)
{
	int ret;
	int freeIndex;
	eUser aux;

	ret = -1; //fallan nulls
	if(userList != NULL && listLen > 0 && idUser != NULL)
	{
		ret = -2; //No hay lugar disponible

		freeIndex = getFreeIndexUser(userList, listLen);
		if(freeIndex > -1)
		{
			ret = -3; //cancelo operacion
			aux = generateUser();

			if(QueresSeguir("Seguro que desea cargar este usuario?? s/n") == 0)
			{
				ret = 0;
				*idUser = *idUser+1;
				aux.userId = *idUser;
				aux.isEmpty = 0;
				userList[freeIndex] = aux;
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
eUser generateUser(void)
{
	eUser aux;

	Get_nombre("Ingrese su nombre/s: ", "Error, solo se admiten letras..", aux.userName , sizeof(aux.userName));
	OrdenarNombre(aux.userName , sizeof(aux.userName));

	Get_nombre("Ingrese su apellido/s: ", "Error, solo se admiten letras..", aux.userLastName , sizeof(aux.userLastName));
	OrdenarNombre(aux.userLastName , sizeof(aux.userLastName));

	Get_cadena("Ingrese la localidad donde reside: ", "Error, la localidad no puede ser tan grande..", aux.userLocality , sizeof(aux.userLocality));
	OrdenarNombre(aux.userLocality , sizeof(aux.userLocality));

	Get_cadena("Ingrese su numero de telefono..: ", "Error, no debe superar los 8 numeros..", aux.userPhone , sizeof(aux.userPhone));

	Get_cadena("Ingrese su email: ", "Error, el email no puede ser tan grande..", aux.userEmail , sizeof(aux.userEmail));
	return aux;
}

int modUser(eUser* userList , int listLen)
{
	int ret;
	int userId;
	int indexUser;
	int field;

	ret = -1; //fallan nulls
	if(userList != NULL && listLen > 0)
	{
		ret = -2; //No se encontro el usuario

		userId = selectUserId(userList , listLen);
		indexUser = findUserIndexById(userList , listLen , userId);

		if(indexUser > -1)
		{
			ret = -3; //cancelo operacion

			Get_numeroConLimites("Seleccione el campo a modificar:\n1.NOMBRE\n2.APELLIDO\n3.MAIL\n4.TELEFONO\n5.DIRECCION", "Error, elija una opcion entre las dadas...", 1, 5, &field);

			if(QueresSeguir("Seguro que desea modificar este usuario?? s/n") == 0)
			{
				ret = 0;
				switch(field)
				{
					case 1:
						Get_nombre("Ingrese su nombre/s: ", "Error, solo se admiten letras..", userList[indexUser].userName , sizeof(userList[indexUser].userName));
						OrdenarNombre(userList[indexUser].userName , sizeof(userList[indexUser].userName));
					break;
					case 2:
						Get_nombre("Ingrese su apellido/s: ", "Error, solo se admiten letras..", userList[indexUser].userLastName , sizeof(userList[indexUser].userLastName));
						OrdenarNombre(userList[indexUser].userLastName , sizeof(userList[indexUser].userLastName));
					break;
					case 3:
						Get_cadena("Ingrese su email: ", "Error, el email no puede ser tan grande..", userList[indexUser].userEmail , sizeof(userList[indexUser].userEmail));
					break;
					case 4:
						Get_cadena("Ingrese su numero de telefono..: ", "Error, no debe superar los 8 numeros..", userList[indexUser].userPhone , sizeof(userList[indexUser].userPhone));
					break;
					case 5:
						Get_cadena("Ingrese la localidad donde reside: ", "Error, la localidad no puede ser tan grande..", userList[indexUser].userLocality , sizeof(userList[indexUser].userLocality));
						OrdenarNombre(userList[indexUser].userLocality , sizeof(userList[indexUser].userLocality));
					break;
				}
			}
		}
	}

	return ret;
}

int selectUserId(eUser* userList , int listLen)
{
	int ret;
	int option;

	ret = -1;

	if(userList != NULL && listLen > 0)
	{
		printf("\n|---------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|ID         NOMBRE                         APELLIDO                       MAIL                                     PHONE    |\n");
		printf("|---------------------------------------------------------------------------------------------------------------------------|\n");
		for(int i=0 ; i<listLen ; i++)
		{
			if(userList[i].isEmpty == 0)
			{
				printUserBasicInfo(userList[i]);
			}
		}
		printf("|---------------------------------------------------------------------------------------------------------------------------|\n");

		Get_numeroConLimites("Ingrese el id a obtener..", "Error, solo se admiten numeros..", 1 , INT_MAX, &option);
		ret = option;

	}
	return ret;
}

void printUserBasicInfo(eUser user)
{
	printf("|%-10d %-30s %-30s %-40s %-9s|\n", user.userId , user.userName , user.userLastName , user.userEmail , user.userPhone);
}

int findUserIndexById(eUser* userList , int listLen , int userIdToFind)
{
	int ret;

	ret = -1;

	if(userList != NULL && listLen > 0)
	{
		for(int i=0 ; i<listLen ; i++)
		{
			if(userList[i].isEmpty == 0 && userList[i].userId == userIdToFind)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}

int isThereAnyLoadUser(eUser* userList , int listLen)
{
	int ret;

	ret = -1;

	if(userList != NULL && listLen > 0)
	{
		for(int i=0 ; i<listLen ; i++)
		{
			if(userList[i].isEmpty == 0)
			{
				ret = 0;
				break;
			}
		}
	}
	return ret;
}
