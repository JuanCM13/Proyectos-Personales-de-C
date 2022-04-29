#include "Controller.h"

#define TAMARCHIVO 200

//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Carga los datos de libros desde archivo ingresado por el usuario (modo texto).
 *
 * \param pArrayBookList LinkedList*
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se consigue lugar para cargar la lista , -2;
 * //FALLO EL PARSEO DE DATOS ,-4 No se encontro ese archivo
 *
 */

int controller_loadDataFromText(LinkedList* pArrayListLogs , LinkedList* pArrayListServices)
{
	int ret;
	FILE* pFileLogs;
	FILE* pFileServices;

	ret = -1;

	if(pArrayListLogs != NULL && pArrayListServices != NULL)
	{
		ret = -4;

		pFileLogs = fopen(LOGSFILE , "r");
		pFileServices = fopen(SERVICEFILE , "r");

		if(pFileLogs != NULL && pFileServices != NULL)
		{
			if(parser_logsFromText(pFileLogs , pArrayListLogs) == 0 && parser_servicesFromText(pFileServices, pArrayListServices) == 0)
			{
				ret = 0;
			}
		}

		fclose(pFileLogs);
		fclose(pFileServices);
	}

    return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

int controllerEvaluateSeverity(LinkedList* logsList , LinkedList* servicesList)
{
	int ret;
	int dataFlowFlag;

	LinkedList* logsWarningsList;
	LinkedList* logsHighRiskList;
	LinkedList* logsMidRiskList;

	ret = -1;

	if(logsList != NULL && servicesList != NULL)
	{
		dataFlowFlag = 0;

		logsWarningsList = ll_filter(logsList, filtByLowRiskError);
		if(logsWarningsList != NULL)
		{
			if(saveAsWarningOrErrorFile(logsWarningsList , servicesList , WARNINGSFILE) != 0)
			{
				dataFlowFlag = -2; //Guarda mal el archivo de errores leves
			}
		}

		logsMidRiskList = ll_filter(logsList, filtByMidRiskError);
		if(logsMidRiskList != NULL)
		{
			showMedSeverityErrors(logsMidRiskList , servicesList);
		}


		logsHighRiskList = ll_filter(logsList, filtByHighRiskError);
		if(logsHighRiskList != NULL)
		{
			if(saveAsWarningOrErrorFile(logsHighRiskList , servicesList , HIGHRISKERRORSFILE) != 0)
			{
				dataFlowFlag = -3; //Guarda mal el archivo de errores graves
			}
		}

		ret = dataFlowFlag;
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

int controllerStatics(LinkedList* logsList , LinkedList* serviceList)
{
	int ret;
	int lowRiskCounter;
	int midRiskCounter;
	int highRiskCounter;
	char errorServiceName[TAMNAME];
	ret = -1;

	if(logsList != NULL && serviceList != NULL)
	{
		ret = 0;

		if(findServiceWithMoreErrors(logsList , serviceList , errorServiceName) == 0)
		{
			printf("Service con mas Errores: %59s\n",errorServiceName);
		}

		lowRiskCounter = ll_count(logsList, filtByLowRiskError);
		if(lowRiskCounter > 0)
		{
			printf("La cantidad de Errores con una gravedad menor a 3 es: %20d\n",lowRiskCounter);
		}
		else
		{
			printf("No hay errores de gravedad menor a 3 al momento..\n");
		}

		midRiskCounter = ll_count(logsList, filtByMidRiskError);
		if(midRiskCounter > 0)
		{
			printf("La cantidad de Errores con una gravedad entre 4 y 7 inclusive es: %8d\n",midRiskCounter);
		}
		else
		{
			printf("No hay errores de gravedad entre 4 y 7 inclusive al momento..\n");
		}

		highRiskCounter = ll_count(logsList, filtByHighRiskError);
		if(highRiskCounter > 0)
		{
			printf("La cantidad de Errores con una gravedad mayor a 7 es: %20d\n",highRiskCounter);
		}
		else
		{
			printf("No hay errores de gravedad  mayor a 7 al momento..\n");
		}
	}

	return ret;
}
