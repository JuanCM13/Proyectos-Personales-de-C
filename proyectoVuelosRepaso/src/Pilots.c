#include "Pilots.h"

ePilot* newPilot()
{
	return (ePilot*) calloc(1 , sizeof(ePilot));
}

ePilot* newPilot_Parameters(char* pilotId , char* pilotName)
{
	ePilot* auxPilot;
	int pilotIdAux;
	char pilotNameAux[TAMNAME];

	auxPilot = NULL;
	if(pilotId != NULL && pilotName != NULL)
	{
		auxPilot = newPilot();

		if(auxPilot != NULL)
		{
			pilotIdAux = atoi(pilotId);
			strcpy(pilotNameAux , pilotName);

			//setters
			setPilotId(auxPilot, pilotIdAux);
			setPilotName(auxPilot, pilotNameAux);
		}
	}

	return auxPilot;
}

//-----------------------------------getters

int getPilotId(ePilot* this , int* pilotId)
{
	int ret;

	ret = -1; //fallan nulls
	if(this != NULL && pilotId != NULL)
	{
		*pilotId = this->idPilot;
		ret = 0;
	}
	return ret;
}

int getPilotName(ePilot* this , char* pilotName)
{
	int ret;

	ret = -1; //fallan nulls
	if(this != NULL && pilotName != NULL)
	{
		strcpy(pilotName , this->pilotName); //esta igual es poco segura puede generar stack overfloat, usar strncpy
		ret = 0;
	}
	return ret;
}

//-----------------------------------setters

int setPilotId(ePilot* this , int pilotId)
{
	int ret;

	ret = -1;
	if(this != NULL)
	{
		this->idPilot = pilotId;
		ret = 0;
	}
	return ret;
}

int setPilotName(ePilot* this , char* pilotName)
{
	int ret;

	ret = -1;
	if(this != NULL && pilotName != NULL)
	{
		strncpy(this->pilotName , pilotName , sizeof(this->pilotName));
		ret = 0;
	}
	return ret;
}

int findPilotId(LinkedList* pArrayPilotsList , int idToFind)
{
	int ret;
	ePilot* auxP;
	int idPilot;

	ret = -1; //null o no existe ese id
	if(pArrayPilotsList != NULL)
	{
		for(int i=0 ; i<ll_len(pArrayPilotsList) ; i++)
		{
			auxP = ll_get(pArrayPilotsList, i);
			if(auxP != NULL)
			{
				getPilotId(auxP, &idPilot);
				if(idPilot == idToFind)
				{
					ret = i;
					break;
				}
			}
		}
	}

	return ret;
}

int printPilotsList(LinkedList* pilotsList)
{
	int ret;
	ePilot* pilot;
	int pilotId;
	char pilotName[TAMNAME];

	ret = -1;
	if(pilotsList != NULL)
	{
		for(int i=0 ; i<ll_len(pilotsList); i++)
		{
			ret = 0;
			pilot = (ePilot*) ll_get(pilotsList, i);
			getPilotId(pilot, &pilotId);
			getPilotName(pilot, pilotName);

			printf("ID PILOTO: %d\nNOMBRE PILOTO: %s\n",pilotId , pilotName);
		}
	}
	return ret;
}
