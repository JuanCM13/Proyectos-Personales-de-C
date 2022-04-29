#include "Logs.h"

//------------------------------------------------------------------------------------------------------

eLogEntry* newLog(void)
{
	eLogEntry* aux;

	return aux = (eLogEntry*) calloc (1,sizeof(eLogEntry));
}

//------------------------------------------------------------------------------------------------------

eLogEntry* newLog_parameters(char* date, char* time, char* serviceId, char* severity, char* msg)
{
	eLogEntry* aux;

	char auxDate[TAMDATE];
	char timeAux[TAMTIME];
	int serviceIdAux;
	int severityAux;
	char msgAux[TAMMSG];

	aux = NULL;

	if(date != NULL && time != NULL && serviceId != NULL && severity != NULL && msg != NULL)
	{
		aux = newLog();
		if(aux != NULL)
		{
			strcpy(auxDate , date);
			strcpy(timeAux , time);
			serviceIdAux = atoi(serviceId);
			severityAux = atoi(severity);
			strcpy(msgAux , msg);

			setDate(aux, auxDate);
			setTime(aux, timeAux);
			setServiceId(aux, serviceIdAux);
			setSeverity(aux, severityAux);
			setMsg(aux, msgAux);
		}
	}

	return aux;
}

//------------------------------------------------------------------------------------------------------

int getDate(eLogEntry* this , char* auxDate)
{
	int ret;

	ret = -1;

	if(this != NULL && auxDate != NULL)
	{
		ret = 0;
		strcpy(auxDate , this->date);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int getTime(eLogEntry* this , char* auxTime)
{
	int ret;

	ret = -1;

	if(this != NULL && auxTime != NULL)
	{
		ret = 0;
		strcpy(auxTime , this->time);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int getServiceId(eLogEntry* this , int* serviceId)
{
	int ret;

	ret = -1;

	if(this != NULL && serviceId != NULL)
	{
		ret = 0;
		*serviceId = this->serviceId;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int getSeverity(eLogEntry* this , int* severity)
{
	int ret;

	ret = -1;

	if(this != NULL && severity != NULL)
	{
		ret = 0;
		*severity = this->severity;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int getMsg(eLogEntry* this , char* msg)
{
	int ret;

	ret = -1;

	if(this != NULL && msg != NULL)
	{
		ret = 0;
		strcpy(msg , this->msg);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int setDate(eLogEntry* this , char* date)
{
	int ret;

	ret = -1;

	if(this != NULL && date != NULL)
	{
		ret = 0;
		strcpy(this->date , date);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int setTime(eLogEntry* this , char* time)
{
	int ret;

	ret = -1;

	if(this != NULL && time != NULL)
	{
		ret = 0;
		strcpy(this->time , time);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int setServiceId(eLogEntry* this , int serviceId)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->serviceId = serviceId;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int setSeverity(eLogEntry* this , int severity)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->severity = severity;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int setMsg(eLogEntry* this , char* msg)
{
	int ret;

	ret = -1;

	if(this != NULL && msg != NULL)
	{
		ret = 0;
		strcpy(this->msg , msg);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int printMenu(int* option)
{
	int ret;

	ret = -1;

	if(option != NULL)
	{
		ret = 0;
		printf("\n\n|----------------------------------------------------------------|\n");
		printf("|	1.Leer log.txt y service.txt                             |\n");
		printf("|	2.Procesar informacion                                   |\n");
		printf("|	3.Mostrar estadisticas                                   |\n");
		printf("|	4.Salir                                                  |\n");
		printf("|----------------------------------------------------------------|\n\n");
		Get_numeroConLimites("Ingrese una opcion del menu..","Error, ingrese entre las opciones dadas..",1,4,option);
	}

	return ret;
}


//------------------------------------------------------------------------------------------------------

int filtByMidRiskError(void* element)
{
	int ret;
	eLogEntry* aux;
	int severity;

	ret = 0;

	if(element != NULL)
	{

		aux = (eLogEntry*) element;
		getSeverity(aux, &severity);

		if(severity > 3 && severity < 8)
		{
			ret = 1;
		}
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int filtByLowRiskError(void* element)
{
	int ret;
	eLogEntry* aux;
	int severity;
	int idToIgnore;

	ret = 0;

	if(element != NULL)
	{

		aux = (eLogEntry*) element;
		getSeverity(aux, &severity);

		if(severity == 3)
		{
			getServiceId(aux, &idToIgnore);
			if(idToIgnore != 45)
			{
				ret = 1;
			}
		}
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int filtByHighRiskError(void* element)
{
	int ret;
	eLogEntry* aux;
	int severity;

	ret = 0;

	if(element != NULL)
	{
		aux = (eLogEntry*) element;
		getSeverity(aux, &severity);

		if(severity > 7)
		{
			ret = 1;
		}
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------

int countByServiceId(LinkedList* logsList , int serviceIdRelation)
{
	int acumulator;
	int i;
	int logsListLen;
	eLogEntry* auxLog;
	int serviceId;

	acumulator = -1;

	if(logsList != NULL)
	{
		acumulator = 0;
		logsListLen = ll_len(logsList);

		for(i=0 ; i<logsListLen ; i++)
		{
			auxLog = ll_get(logsList, i);
			getServiceId(auxLog, &serviceId);

			if(serviceId == serviceIdRelation)
			{
				acumulator++;
			}
		}
	}

	return acumulator;
}
