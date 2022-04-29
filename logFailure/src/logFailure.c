/*
 ============================================================================
 Name        : logFailure.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Controller.h"


int main(void)
{
	setbuf(stdout,NULL);
	int option;
	int flagFiles;
	int informationProcesedControl;

	LinkedList* logsList;
	LinkedList* servicesList;

	logsList = ll_newLinkedList();
	servicesList = ll_newLinkedList();

	if(logsList != NULL && servicesList != NULL)
	{
		flagFiles = 0;
		do
		{
			printMenu(&option);
			switch(option)
			{
				case 1:

					if(controller_loadDataFromText(logsList , servicesList) == 0)
					{
						flagFiles = 1;
						printf("La carga de archivos: log.txt // service.txt fueron cargados con exito..\n");
					}
					else
					{
						printf("La carga de archivos fallo, reintente..\n");
					}

				break;

				case 2:

					if(flagFiles == 1)
					{
						informationProcesedControl = controllerEvaluateSeverity(logsList , servicesList);
						switch(informationProcesedControl)
						{
							case 0:
								printf("La carga de archivos fue realizada con exito, podra encontrar los archivos con los nombres: logsHighRiskErrors.txt // logsWarningsFile.txt \n");
							break;
							case -1:
								printf("Fallaron nulls\n");
							break;
							case -2:
								printf("Fallo la carga del archivo de wsarnings\n");
							break;
							case -3:
								printf("Fallo el printeo de errores medios\n");
							break;
							case -4:
								printf("Fallo la carga del archivo de errores graves\n");
							break;
						}
					}
					else
					{
						printf("Deben estar cargados tanto el archivo de logs.txt como el de services.txt, reintente..\n");
					}

				break;

				case 3:

					if(flagFiles == 1)
					{
						if(controllerStatics(logsList , servicesList) != 0)
						{
							printf("No pudo realizarse el control de estadisticas, reintente..\n");
						}
					}
					else
					{
						printf("Deben estar cargados tanto el archivo de logs.txt como el de services.txt, reintente..\n");
					}

				break;
			}

		}while(option != 4);
	}
}
