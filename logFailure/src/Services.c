#include "Services.h"

eService* newService(void)
{
	eService* aux;

	return aux = (eService*) calloc(1,sizeof(eService));

}

//------------------------------------------------------------------------------------------------------

eService* newService_parameters(char* id , char* name , char* mail)
{
	eService* aux;

	int idAux;
	char nameAux[TAMNAME];
	char mailAux[TAMEMAIL];

	aux = NULL;

	if(id != NULL && name != NULL && mail != NULL)
	{
		aux = newService();
		if(aux != NULL)
		{
			idAux = atoi(id);
			strcpy(nameAux , name);
			strcpy(mailAux , mail);

			setId(aux, idAux);
			setName(aux, nameAux);
			setEmail(aux, mailAux);

		}
	}

	return aux;
}

//------------------------------------------------------------------------------------------------------

int getId(eService* this , int* id)
{
	int ret;

	ret = -1;

	if(this != NULL && id != NULL)
	{
		ret = 0;
		*id = this->id;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int getName(eService* this , char* name)
{
	int ret;

	ret = -1;

	if(this != NULL && name != NULL)
	{
		ret = 0;
		strcpy(name , this->name);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int getEmail(eService* this , char* email)
{
	int ret;

	ret = -1;

	if(this != NULL && email != NULL)
	{
		ret = 0;
		strcpy(email , this->email);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int setId(eService* this , int id)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->id = id;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int setName(eService* this , char* name)
{
	int ret;

	ret = -1;

	if(this != NULL && name != NULL)
	{
		ret = 0;
		strcpy(this->name , name);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int setEmail(eService* this , char* email)
{
	int ret;

	ret = -1;

	if(this != NULL && email != NULL)
	{
		ret = 0;
		strcpy(this->email , email);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

eService* findIdRelation(LinkedList* service , int idToFind)
{
	eService* ret;
	int i;
	int listLen;
	eService* aux;
	int serviceId;

	ret = NULL;

	if(service != NULL)
	{
		listLen = ll_len(service);
		if(listLen > 0)
		{
			for(i=0 ; i<listLen ; i++)
			{
				aux = ll_get(service, i);
				getId(aux, &serviceId);
				if(serviceId == idToFind)
				{
					ret = aux;
					break;
				}
			}
		}
	}

	return ret;
}
