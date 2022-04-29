#include "User.h"

//--------------------------------------------------------------------------------------------------------------------------------------

eUser* newUser(void)
{
	eUser* aux;

	return aux = (eUser*) calloc(1,sizeof(eUser));

}

//--------------------------------------------------------------------------------------------------------------------------------------

eUser* newUser_parameters(char* userId , char* userNick , char* userPopularity )
{
	eUser* userAux;

	int auxUserId;
	char auxUserNick[TAMNICK];
	int auxUserPopularity;

	userAux = NULL;

	if(userId != NULL && userNick != NULL && userPopularity != NULL)
	{
		userAux = newUser();

		if(userAux != NULL)
		{
			auxUserId = atoi(userId);
			auxUserPopularity = atoi(userPopularity);
			strncpy(auxUserNick , userNick , sizeof(auxUserNick));

			setIdUser(userAux, auxUserId);
			setUserPopularity(userAux, auxUserPopularity);
			setUserNick(userAux, auxUserNick);

		}


	}

	return userAux;
}

//--------------------------------------------------------------------------------------------------------------------------------------
															//SETTERS
//--------------------------------------------------------------------------------------------------------------------------------------

int setIdUser(eUser* this , int idUser)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->idUser = idUser;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------

int setUserPopularity(eUser* this , int userPopularity)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->userPopularity = userPopularity;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------

int setUserNick(eUser* this , char* userNick)
{
	int ret;

	ret = -1;

	if(this != NULL && userNick != NULL)
	{
		ret = 0;
		strncpy(this->userNick , userNick , sizeof(this->userNick));
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------
															// SETTERS END
//--------------------------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------------------------
															// GETTERS
//--------------------------------------------------------------------------------------------------------------------------------------

int getUserNick(eUser* this , char* userNick)
{
	int ret;

	ret = -1;

	if(this != NULL && userNick != NULL)
	{
		ret = 0;
		strcpy(userNick , this->userNick);
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------

int getIdUser(eUser* this , int* idUser)
{
	int ret;

	ret = -1;

	if(this != NULL && idUser != NULL)
	{
		ret = 0;
		*idUser = this->idUser;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------

int getUserPopularity(eUser* this , int* userPopularity)
{
	int ret;

	ret = -1;

	if(this != NULL && userPopularity != NULL)
	{
		ret = 0;
		*userPopularity = this->userPopularity;
	}

	return ret;
}

//--------------------------------------------------------------------------------------------------------------------------------------
															//END GETTERS
//--------------------------------------------------------------------------------------------------------------------------------------

eUser* findUserById(LinkedList* userList , int idToFind)
{
	eUser* ret;
	eUser* aux;
	int i;
	int userListLen;
	int idRelation;

	ret = NULL;

	if(userList != NULL)
	{
		userListLen = ll_len(userList);

		if(userList > 0)
		{
			for(i=0 ; i<userListLen ; i++)
			{
				aux = ll_get(userList, i);
				getIdUser(aux, &idRelation);

				if(idRelation == idToFind)
				{
					ret = aux;
					break;
				}
			}
		}
	}

	return ret;
}


//--------------------------------------------------------------------------------------------------------------------------------------

int orderByUserPopularity(void* elementA , void* elementB)
{
	int ret;

	eUser* firstElement;
	eUser* secondElement;
	int popularityFirstElement;
	int popularitySecondElement;

	ret = 0;

	if(elementA != NULL && elementB != NULL)
	{
		firstElement = (eUser*) elementA;
		secondElement = (eUser*) elementB;

		getUserPopularity(firstElement, &popularityFirstElement);
		getUserPopularity(secondElement, &popularitySecondElement);


		if(popularityFirstElement > popularitySecondElement)
		{
			ret = 1;
		}
		else
		{
			if(popularityFirstElement < popularitySecondElement)
			{
				ret = -1;
			}
		}
	}

	return ret;
}

int compareByNick(void* elemento1, void* elemento2)
{
	int ret;
	eUser* userUno;
	eUser* userDos;

	char nickUno[TAMNICK];
	char nickDos[TAMNICK];

	if(elemento1 != NULL && elemento2 != NULL)
	{
		userUno = (eUser*) elemento1;
		userDos = (eUser*) elemento2;

		if( getUserNick(userUno, nickUno) && (getUserNick(userDos, nickDos) == 0) )
		{
			ret = strcmp(nickUno , nickDos);
		}
	}

	return ret;
}

