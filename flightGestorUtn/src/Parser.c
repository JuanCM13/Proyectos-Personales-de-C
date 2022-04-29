#include "Parser.h"

//---------------------------------------------------------------------------------------------------------------------------------------------

int parserFlights_fromText(LinkedList* flightsList , FILE* pFile)
{
	int ret;
	eFlight* aux;

	//auxs
	char idFlight[100];
	char idFly[100];
	char idPilot[100];
	char date[100];
	char destiny[100];
	char passengers[100];
	char desperty[100];
	char arrive[100];

	ret = -1;

	if(flightsList != NULL && pFile != NULL)
	{
		ret = -2; //cant read file
		fscanf(pFile ,  "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", idFlight , idFly , idPilot , date , destiny , passengers , desperty , arrive);

		while(!feof(pFile))
		{
			if(fscanf(pFile ,  "%[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", idFlight , idFly , idPilot , date , destiny , passengers , desperty , arrive) == 8)
			{
				ret = -3;//cant valid parameters
				if(controlFlightParameters(idFlight , idFly , idPilot , date , destiny , passengers , desperty , arrive) == 0)
				{
					aux = newFlight_parameters(idFlight , idFly , idPilot , date , destiny , passengers , desperty , arrive);
					if(aux != NULL)
					{
						printf("%d , %d , %d , %s , %s , %d , %d , %d\n",aux->idFly , aux->idFlight ,aux->idPilot , aux->date , aux->destiny , aux->passengersCant , aux->departureTime , aux->arriveTime);
						ret = 0; //everithing is just fine and smoth..
						ll_add(flightsList , aux);
					}
				}
				else
				{
					break; //if i cant valid one parameter i break;
				}
			}
			else
			{
				break; //if i cant read one flight i break;
			}
		}
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

int controlFlightParameters(char* idFlight , char* idFly , char* idPilot , char* date , char* destiny , char* passengers , char* desperty , char* arrive )
{
	int ret;

	ret = -1;
	if(idFlight != NULL && idFly != NULL && idPilot != NULL && date != NULL && destiny != NULL && passengers != NULL && desperty != NULL && arrive != NULL)
	{
		if(esNumero(idFlight, strlen(idFlight)) == 0)
		{
			ret = 0;
		}
		ret = -1;

		if(esNumero(idFly, strlen(idFly)) == 0)
		{
			ret = 0;
		}
		ret = -1;

		if(esNumero(idPilot, strlen(idPilot)) == 0)
		{
			ret = 0;
		}
		ret = -1;

		if(esFecha(date , strlen(date)) == 0)
		{
			ret = 0;
		}
		ret = -1;

		if(sonLetras(destiny, strlen(destiny)) == 0)
		{
			ret = 0;
		}
		ret = -1;

		if(esNumero(passengers, strlen(passengers)) == 0)
		{
			ret = 0;
		}
		ret = -1;

		if(esNumero(desperty, strlen(desperty)) == 0)
		{
			ret = 0;
		}
		ret = -1;

		if(esNumero(arrive, strlen(arrive)) == 0)
		{
			ret = 0;
		}
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

int parserPilots_fromText(LinkedList* pilotsList , FILE* pFile)
{
	int ret;
	ePilot* aux;

	//auxs
	char idFlight[100];
	char pilotName[100];

	ret = -1;

	if(pilotsList != NULL && pFile != NULL)
	{
		ret = -2; //cant read file
		fscanf(pFile ,  "%[^,] , %[^\n]\n", idFlight , pilotName);

		while(!feof(pFile))
		{
			if(fscanf(pFile ,  "%[^,] , %[^\n]\n", idFlight , pilotName) == 2)
			{
				ret = -3;//cant valid parameters
				if(controlPilotsParameters(idFlight , pilotName) == 0)
				{
					aux = newPilot_parameters(idFlight , pilotName);
					if(aux != NULL)
					{
						printf("%d , %s \n",aux->pilotId , aux->pilotName);
						ret = 0; //everithing is just fine and smoth..
						ll_add(pilotsList , aux);
					}
				}
				else
				{
					break; //if i cant valid one parameter i break;
				}
			}
			else
			{
				break; //if i cant read one flight i break;
			}
		}
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

int controlPilotsParameters(char* pilotId , char* pilotName)
{
	int ret;

	ret = -1;
	if(pilotId != NULL && pilotName != NULL)
	{
		if(esNumero(pilotId, strlen(pilotId)) == 0)
		{
			ret = 0;
		}
		ret = -1;

		if(sonLetras(pilotName, strlen(pilotName)) == 0)
		{
			ret = 0;
		}
	}

	return ret;
}
