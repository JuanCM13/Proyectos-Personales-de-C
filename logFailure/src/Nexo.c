#include "Nexo.h"

int showMedSeverityErrors(LinkedList* midRiskLosgs , LinkedList* services)
{
	int ret;
	int i;
	int listLen;

	int logIdAux;

	eLogEntry* logAux;
	eService* serviceAux;

	ret = -1;

	if(midRiskLosgs != NULL && services != NULL)
	{
		listLen = ll_len(midRiskLosgs);

		printf("\n|-----------------------------------------------------------------------------------------------------------------|\n");
		printf("|DATE            |TIME      |SERVICE NAME                        |ERROR                               |SEVERITY   |\n");
		printf("|-----------------------------------------------------------------------------------------------------------------|\n");
		printf("|-----------------------------------------------------------------------------------------------------------------|\n");
		for(i=0 ; i<listLen ; i++)
		{
			logAux = ll_get(midRiskLosgs, i);
			getServiceId(logAux, &logIdAux);

			serviceAux = findIdRelation(services , logIdAux);
			if(serviceAux != NULL)
			{
				ret = printfServiceError(logAux , serviceAux);
			}
		}
	}

	return ret;
}

//------------------------------------------------------------------

int printfServiceError(eLogEntry* logData , eService* serviceData)
{
	int ret;
	char dateAux[TAMDATE];
	char timeAux[TAMTIME];
	char serviceName[TAMNAME];
	char errorMsg[TAMMSG];
	int severityLevel;

	ret = -1;

	if(logData != NULL && serviceData != NULL)
	{
		ret = 0;

		getDate(logData, dateAux);
		getTime(logData, timeAux);
		getName(serviceData, serviceName);
		getMsg(logData, errorMsg);
		getSeverity(logData, &severityLevel);

		printf("|%-15s |%-9s |%-35s |%-35s |%-10d |\n", dateAux , timeAux , serviceName , errorMsg , severityLevel);
		printf("|-----------------------------------------------------------------------------------------------------------------|\n");
	}

	return ret;
}

//------------------------------------------------------------------

int findServiceWithMoreErrors(LinkedList* logsList , LinkedList* serviceList , char* serviceName)
{
	int ret;
	int i;
	int serviceLen;
	int serviceId;
	int acumulator;
	int biggestCount;
	int flag;
	char auxName[TAMNAME];

	eService* auxService;

	ret = -1;

	if(logsList != NULL && serviceList != NULL && serviceName != NULL)
	{
		flag = 0;
		serviceLen = ll_len(serviceList);
		for(i=0 ; i<serviceLen ; i++)
		{
			auxService = ll_get(serviceList, i);
			getId(auxService, &serviceId);

			acumulator = countByServiceId(logsList , serviceId);

			if(acumulator > -1)
			{
				if(flag == 0 || acumulator > biggestCount)
				{
					flag = 1;
					biggestCount = acumulator;
					getName(auxService, auxName);
				}
			}
		}
	}

	if(flag != 0)
	{
		ret = 0;
		strcpy(serviceName , auxName);
	}

	return ret;
}
