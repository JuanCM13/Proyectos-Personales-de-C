#include "FilesManage.h"

//---------------------------------------------------------------------------------------

int saveAsWarningOrErrorFile(LinkedList* dataToSave , LinkedList* service , char* path)
{
	int ret;
	FILE* warningsFile;
	int listLen;
	int i;

	char dateAux[TAMDATE];
	char timeAux[TAMTIME];
	char serviceName[TAMNAME];
	char errorMsgAux[TAMMSG];
	char serviceMail[TAMEMAIL];

	int logIdAux;
	eService* auxService;
	eLogEntry* auxLog;

	ret = -1;

	if(dataToSave != NULL && service != NULL && path != NULL)
	{
		ret = -2; //mo se pudo guardar el archivo--

		warningsFile = fopen(path , "w+");

		if(warningsFile != NULL)
		{
			listLen = ll_len(dataToSave);

			for(i=0 ; i<listLen ; i++)
			{
				ret = -3; //No se encontro la relacion con service list
				auxLog = ll_get(dataToSave, i);
				getServiceId(auxLog, &logIdAux);

				auxService = findIdRelation(service, logIdAux);

				if(auxService != NULL)
				{
					ret = 0;
					getDate(auxLog, dateAux);
					getTime(auxLog, timeAux);
					getName(auxService, serviceName);
					getMsg(auxLog, errorMsgAux);
					getEmail(auxService, serviceMail);
					//printf("guarde\n");
					fprintf(warningsFile , "%s ; %s ; %s ; %s ; %s\n", dateAux , timeAux , serviceName , errorMsgAux , serviceMail);
				}
				else
				{
					printf("---------Id relacion: %d no encontrado---------\n",logIdAux);
				}
			}
		}

		fclose(warningsFile);
	}
	return ret;
}

