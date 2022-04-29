
#include "parser.h"

/** \brief Parsea los datos de los libros desde el archivo pasado por parametro (modo texto).
 *
 * \param pFile FILE* (archivo)
 * \param pArrayListBooks LinkedList* (lista libros)
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se consigue lugar para cargar la lista , -2;
 * /FALLO EL PARSEO DE DATOS ,-4 No se encontro ese archivo
 */
int parser_postsFromText(FILE* pFile , LinkedList* pArrayListPosts)
{

	int ret;
	char auxPostId[100];
	char auxUserId[100];
	char auxPopularity[100];
	char auxMessege[1500];
	eMessege* mesAux;

	ret = -1;

	if(pFile != NULL && pArrayListPosts != NULL)
	{
		//printf("Entre al parser..\n");
		ret = 0;

		fscanf(pFile , "%[^,], %[^,], %[^,], %[^\n]\n" , auxPostId , auxUserId , auxPopularity , auxMessege);

		while(!feof(pFile))
		{
			if(fscanf(pFile , "%[^,], %[^,], %[^,], %[^\n]\n" , auxPostId , auxUserId , auxPopularity , auxMessege) == 4)
			{
				//printf("Comprobo biejn..\n");
				//printf(" %s -- %s --  %s -- %s \n", auxPostId , auxUserId , auxPopularity , auxMessege);

				if(controlPostParameters(auxPostId , auxUserId , auxPopularity) == 0)
				{
					mesAux = newPost_parameters(auxPostId , auxMessege , auxPopularity , auxUserId);

					if(mesAux != NULL)
					{
						//printf(" %d -- %d --  %d -- %s \n", mesAux->idMessege , mesAux->popularity , mesAux->userId , mesAux->postContent);
						ll_add( pArrayListPosts , mesAux);
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
					printf("HAY ALGO FALLADITO..\n");
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

//-----------------------------------------------------------------------------------------------------------------------------------------
/*
int parserFeedList(LinkedList* listaPosts, LinkedList* listaUsers , LinkedList* listaFeed )
{
	int ret;

	ret = -1;

	if()
}
*/


/** \brief Parsea los datos de los libros desde el archivo pasado por parametro (modo texto).
 *
 * \param pFile FILE* (archivo)
 * \param pArrayListBooks LinkedList* (lista libros)
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se consigue lugar para cargar la lista , -2;
 * /FALLO EL PARSEO DE DATOS ,-4 No se encontro ese archivo
 */
int parser_usersFromText(FILE* pFile , LinkedList* pArrayListUsers)
{

	int ret;
	char auxUserPopularity[100];
	char auxIdUser[100];
	char auxUserNick[100];
	eUser* userAux;

	ret = -1;

	if(pFile != NULL && pArrayListUsers != NULL)
	{
		//printf("Entre al parser..\n");
		ret = 0;

		fscanf(pFile , "%[^,], %[^,], %[^\n]\n" , auxIdUser , auxUserNick , auxUserPopularity);

		while(!feof(pFile))
		{
			if(fscanf(pFile , "%[^,], %[^,], %[^\n]\n" , auxIdUser , auxUserNick , auxUserPopularity) == 3)
			{
				//printf(" %s -- %s --  %s --\n", auxIdUser , auxUserNick , auxUserPopularity);

				if(controlUserParameters(auxIdUser , auxUserNick , auxUserPopularity) == 0)
				{
					userAux = newUser_parameters(auxIdUser , auxUserNick , auxUserPopularity);

					if(userAux)
					{
						//printf(" %d -- %s --  %d --\n", userAux->idUser , userAux->userNick , userAux->userPopularity);
						ll_add( pArrayListUsers , userAux);
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

//---------------------------------------------------------------------------------------

int controlPostParameters(char* auxPostId , char* auxUserId , char* auxPopularity)
{
	int ret;

	ret = -1;

	if(auxPopularity != NULL && auxPostId != NULL && auxUserId != NULL)
	{
		if(esNumero(auxPopularity, sizeof(auxPopularity)) == 0)
		{
			ret = 0;
		}
		ret = -1;

		if(esNumero(auxPostId, sizeof(auxPostId)) == 0)
		{
			ret = 0;
		}
		ret = -1;

		if(esNumero(auxUserId, sizeof(auxUserId)) == 0)
		{
			ret = 0;
		}
	}

	return ret;
}

//---------------------------------------------------------------------------------------

int controlUserParameters(char* userId, char* userNick, char* userPopularity)
{
	int ret;

	ret = -1;

	if(userId != NULL && userNick != NULL && userPopularity != NULL)
	{
		if(esNumero(userId, sizeof(userId)) == 0)
		{
			ret = 0;
		}
		ret = -1;

		if(esNumero(userPopularity, sizeof(userPopularity)) == 0)
		{
			ret = 0;
		}
		ret = -1;

		if(sonLetras(userNick, sizeof(userNick)) == 0)
		{
			ret = 0;
		}
	}

	return ret;
}
