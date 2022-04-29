
#include "controller.h"

#define POSTFILE "mensajes.csv"
#define USERSFILE "usuarios.csv"

//------------------------------------------------------------------------------------------------------------------------------------------

int controller_readPostFile(LinkedList* this)
{
	int ret;
	FILE* archivo;

	ret = -1;

	if(this != NULL)
	{
		ret = -4; // no se encontro el archivo-

		archivo = fopen(POSTFILE , "r");

		if(archivo != NULL)
		{
			printf("Abrio el csv\n");
			ret = parser_postsFromText(archivo , this);
		}

		fclose(archivo);

	}

	return ret;

}

//------------------------------------------------------------------------------------------------------------------------------------------

int controller_readUserFile(LinkedList* this)
{
	int ret;
	FILE* archivo;

	ret = -1;

	if(this != NULL)
	{
		printf("Abrio el csv\n");
		ret = -4; // no se encontro el archivo-

		archivo = fopen(USERSFILE , "r");

		if(archivo != NULL)
		{
			printf("Abrio el csv\n");
			ret = parser_usersFromText(archivo, this);
		}

		fclose(archivo);

	}

	return ret;

}

//--------------------------------------------------------------------------------------------------------------------
/*
int generateFeedFile(LinkedList* listaUsuarios , LinkedList* listaPosts , LinkedList* listaFeed)
{
	int ret;

	ret = -1;

	if(listaUsuarios != NULL && listaPosts != NULL && listaFeed != NULL)
	{
		ret = parserFeedList(listaPosts , listaUsuarios , listaFeed);
	}

	return ret;
}
*/
//--------------------------------------------------------------------------------------------------------------------

int controller_printPosts(LinkedList* postList , LinkedList* userList)
{
	int ret;

	ret = -1;

	if(postList != NULL && userList != NULL)
	{
		if(showPosts(postList , userList) == 0)
		{
			ret = 0;
		}
	}

	return ret;

}


//--------------------------------------------------------------------------------------------------------------------

int controller_printPriority(LinkedList* postList , LinkedList* userList)
{
	int ret;


	ret = -1;

	if(postList != NULL && userList != NULL)
	{
		if(ll_sort2(userList, postList, orderByUserPopularity , orderByPostPopularity) == 0)
		{
			ret = 0;
			/*if(QueresSeguir("Desea imprimir la lista ordenada??\n") == 0)
			{
				showPosts(postList , userList);
			}*/
		}
	}

	return ret;

}
