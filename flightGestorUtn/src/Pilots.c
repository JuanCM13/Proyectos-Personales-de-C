#include "Pilots.h"

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

ePilot* newPilot(void)
{
	ePilot* aux;

	return aux = (ePilot*) calloc(1, sizeof(ePilot));

}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

ePilot* newPilot_parameters(char* pilotId , char* pilotName)
{
	int idPilotAux;

	ePilot* aux;

	aux = NULL;

	if(pilotId != NULL && pilotName != NULL)
	{
		aux = newPilot();
		if(aux != NULL)
		{
			idPilotAux = atoi(pilotId);

			setIdFromPilot(aux, idPilotAux);
			setPilotName(aux, pilotName);
		}
	}
	return aux;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
											//setters
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int setIdFromPilot(ePilot* pilot , int pilotId)
{
	int ret;

	ret = -1;
	if(pilot != NULL)
	{
		ret = 0;
		pilot->pilotId = pilotId;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int setPilotName(ePilot* pilot , char* pilotName)
{
	int ret;

	ret = -1;
	if(pilot != NULL && pilotName != NULL)
	{
		ret = 0;
		strcpy(pilot->pilotName , pilotName);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
											//setters end
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
											//getters
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int getIdFromPilot(ePilot* pilot , int* pilotId)
{
	int ret;

	ret = -1;
	if(pilot != NULL && pilotId != NULL)
	{
		ret = 0;
		*pilotId = pilot->pilotId;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int getPilotName(ePilot* pilot , char* pilotName)
{
	int ret;

	ret = -1;
	if(pilot != NULL && pilotName != NULL)
	{
		ret = 0;
		strcpy(pilotName , pilot->pilotName);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

ePilot* findPilotById(LinkedList* pilotList , int idRelation)
{
	int i;
	int listLen;
	ePilot* aux;
	int pilotId;

	aux = NULL;
	if(pilotList != NULL)
	{
		listLen = ll_len(pilotList);

		if(listLen > 0)
		{
			for(i=0 ; i<listLen ; i++)
			{
				aux = NULL;
				aux = ll_get(pilotList, i);
				getIdFromPilot(aux, &pilotId);

				if(pilotId == idRelation)
				{
					break;
				}
			}
		}
	}

	return aux;
}


