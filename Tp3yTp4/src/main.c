#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);

    int option = 0;
    int respuestaCargaCsv;
    int respuestaCargaBinaria;
    int respuestaImprimirLista;
    int respuestaModificacionEmpleado;
    int respuestaEliminarEmpleado;
    int respuestaSaveText;
    int respuestaSaveBinary;
    int respuestaOrdenamiento;


    int banderaControl;

    LinkedList* listaEmpleados = ll_newLinkedList();

    banderaControl = 0;

    do{

    	desplegarMenu(&option);

        switch(option)
        {
			case 1:

				if(banderaControl == 0)
				{
					respuestaCargaCsv = controller_loadFromText("data.csv",listaEmpleados);

					switch(respuestaCargaCsv)
					{
						case 0:

							printf("--La carga de datos del archivo -data.csv- , fue exitosa..\n");
							banderaControl = 1;

						break;

						case -1:

							printf("--Fatal error , reintente..\n");

						break;

						case -2:

							printf("--Error no se pudieron recuperar los datos del archivo data.csv..\n");

						break;

						case -3:

							printf("--Error no encontro el archivo data.csv..\n");

						break;
					}
            	}
				else
				{
					printf("--Un archivo ya se encuentra cargado en la lista, reinicie el programa para volver a cargar \nrecuerde antes guardar los cambios en la opcion 8, de lo contrario el progreso sera borrado..\n");
				}

            break;

			case 2:

				if(banderaControl == 0)
				{
					respuestaCargaBinaria = controller_loadFromBinary("data.bin",listaEmpleados);

					switch(respuestaCargaBinaria)
					{
						case 0:

							printf("--La carga de datos del archivo -data.bin- , fue exitosa..\n");
							banderaControl = 1;

						break;

						case -1:

							printf("--Fatal error , reintente..\n");

						break;

						case -2:

							printf("--Error no se pudieron recuperar los datos del archivo data.csv..\n");

						break;

						case -3:

							printf("--Error no encontro el archivo data.bin..\n");

						break;
					}
            	}
				else
				{
					printf("--Un archivo ya se encuentra cargado en la lista, reinicie el programa para volver a cargar, recuerde antes guardar los cambios en la opcion 8, de lo contrario el progreso sera borrado..\n");
				}

            break;

            case 3:

				 if(controller_addEmployee(listaEmpleados) == 0)
				 {
					 printf("--El alta de empleado se realizo de forma exitosa..\n");
				 }
				 else
				 {
					 printf("--Algo fallo en la carga del empleado, reintente..\n");
				 }

            break;

            case 4:

				respuestaModificacionEmpleado = controller_editEmployee(listaEmpleados);

				switch(respuestaModificacionEmpleado)
				{
					case 0:

					printf("--La modificacion se realizo con exito..\n");

					break;

					case -1:

						printf("--Fallo la modificacion del empleado, reintente..\n");

					break;

					case -2:

						printf("--La operacion fue cancelada..\n");

					break;

					case -3:

						printf("--La lista se encuentra vacia..\n");

					break;
				}


            break;

            case 5:

				respuestaEliminarEmpleado = controller_removeEmployee(listaEmpleados);

				switch(respuestaEliminarEmpleado)
				{
					case 0:

					printf("--La baja de empleado se realizo con exito..\n");

					break;

					case -1:

						printf("--Fallo la baja del empleado, reintente..\n");

					break;

					case -2:

						printf("--La operacion fue cancelada..\n");

					break;

					case -3:

						printf("--La lista se encuentra vacia..\n");

					break;
				}

            break;

            case 6:

				respuestaImprimirLista = controller_ListEmployee(listaEmpleados);
				switch(respuestaImprimirLista)
				{
					case -1:

						printf("--Fallo la ejecucion de la opcion, reintente..");

					break;

					case -2:

						printf("--Fallo la impresion del listado, reintente..");

					break;

					case -3:

						printf("--La lista se encuentra vacia..");

					break;
				}

            break;

            case 7:

            	respuestaOrdenamiento = controller_sortEmployee(listaEmpleados);

            	switch(respuestaOrdenamiento)
            	{
            		case 0:

            			printf("--Se ordeno de manera exitosa..\n");

            		break;

            		case -1:

            			printf("--El ordenamiento fallo..\n");

            		break;

            		case -2:

            			printf("--La lista se encuentra vacia..\n");

            		break;
            	}

            break;

            case 8:

            	if(banderaControl == 1)
				{
					respuestaSaveText = controller_saveAsText("data.csv" , listaEmpleados);
					switch(respuestaSaveText)
					{
						case 0:

							printf("--El archivo fue guardado con exito..\n");

						break;
						case -1:

							printf("--Algo fallo reintente..\n");

						break;
						case -2:

							printf("--Hubo un error con el archivo, reintente..\n");

						break;
					}
				}
				else
				{
					printf("--Para ingresar a esta opcion se debe traer los datos de algun archivo antes, acceda a la opcion 1 o 2 previamente..\n");
				}

			break;

            case 9:

            	if(banderaControl == 1)
				{
            		respuestaSaveBinary = controller_saveAsBinary("data.bin" , listaEmpleados);
					switch(respuestaSaveBinary)
					{
						case 0:

							printf("--El archivo fue guardado con exito..\n");

						break;
						case -1:

							printf("--Algo fallo reintente..\n");

						break;
						case -2:

							printf("--Hubo un error con el archivo, reintente..\n");

						break;
					}
				}
				else
				{
					printf("--Para ingresar a esta opcion se debe traer los datos de algun archivo antes, acceda a la opcion 1 o 2 previamente..\n");
				}

			break;

            case 10:

            	if(QueresSeguir("Seguro que desea salir del programa? s/n \n--Recuerde que si no guardo los cambios en la opcion 8 o 9 se perderan...") == 0)
            	{
            		option = 10;
            	}
            	else
            	{
            		option = 11;
            		printf("--Operacion cancelada..\n");
            	}

            break;
        }

    }while(option != 10);


    printf("\n\n----------------------------------------------------------PROGRAMA TERMINADO------------------------------------------------------------");

    return 0;
}

