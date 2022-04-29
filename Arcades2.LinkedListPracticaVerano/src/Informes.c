#include "Informes.h"

void optionOne(LinkedList* lista , int* flagControl)
{
	int resp;

	resp = controller_LoadArcadesData(lista);
	switch(resp)
	{
		case 0:
			*flagControl = 1;
			printf("El archivo fue cargado con exito!\n");
		break;
		case -1:
			printf("Falla a nivel nullidad, reintente\n");
		break;
		case -2:
			printf("Uno de los datos del archivo no pudo ser validado, reintente\n");
		break;
		case -3:
			printf("No se encontro espacio en memoria para el Arcade..., reintente\n");
		break;
		case -4:
			printf("Uno de los datos del archivo vino mal..., reintente\n");
		break;
		case -5:
			printf("No se encontro el archivo ingresado, reintente..");
		break;
	}
}

void optionTwo(LinkedList* lista , int* flagControl)
{
	int resp;

	resp = controller_LoadSoundData(lista);
	switch(resp)
	{
		case 0:
			*flagControl = 1;
			printf("El archivo fue cargado con exito!\n");
		break;
		case -1:
			printf("Falla a nivel nullidad, reintente\n");
		break;
		case -2:
			printf("Uno de los datos del archivo no pudo ser validado, reintente\n");
		break;
		case -3:
			printf("No se encontro espacio en memoria para el Arcade..., reintente\n");
		break;
		case -4:
			printf("Uno de los datos del archivo vino mal..., reintente\n");
		break;
		case -5:
			printf("No se encontro el archivo ingresado, reintente..");
		break;
	}
}

void optionThree(LinkedList* listaArcades)
{
	int resp;

	resp = controllerGenerateNewArcade(listaArcades);
	switch(resp)
	{
		case 0:
			printf("El arcade fue cargado con exito!\n");
		break;
		case -1:
			printf("Falla a nivel nullidad, reintente\n");
		break;
		case -2:
			printf("La operacion fue cancelada..\n");
		break;
		case -3:
			printf("Fallo la actualizacion del archivo\n");
		break;
		case -4:
			printf("Uno de los datos del archivo vino mal..., reintente\n");
		break;
		case -5:
			printf("No se encontro el archivo ingresado, reintente..");
		break;
	}
}

void optionFour(LinkedList* pListArcades , LinkedList* pListSound)
{
	int respuesta;

	respuesta = controller_PrintArcades(pListArcades, pListSound);
	switch(respuesta)
	{
		case -1:
			printf("No pudo printearse la data, reintente..");
		break;
	}

}

void optionFive(LinkedList* pListArcades , LinkedList* pListSound)
{
	int respuesta;

	respuesta = Controller_ModArcade(pListArcades, pListSound);
	switch(respuesta)
	{
		case 0:
			printf("El elemento fue modificado con exito..");
		break;
		case -1:
			printf("Algo fallo, reintente..");
		break;
		case -2:
			printf("No se encontro el id ingresado, ingrese un id del listado mostrado..");
		break;
		case -3:
			printf("Opcion cancelada..");
		break;
		case -4:
			printf("No pudo actualizarse el archivo, reintente reiniciando el programa y controle que el archivo sea el correcto a guardar");
		break;
	}
}

void optionSix(LinkedList* pListArcades , LinkedList* pListSound)
{
	int respuesta;

	respuesta = Controller_DeleteArcade(pListArcades, pListSound);
	switch(respuesta)
	{
		case 0:
			printf("El elemento fue eliminado con exito..");
		break;
		case -1:
			printf("Algo fallo, reintente....");
		break;
		case -2:
			printf("No se encontro el id ingresado, ingrese un id del listado mostrado..");
		break;
		case -3:
			printf("Opcion cancelada..");
		break;
		case -4:
			printf("No pudo actualizarse el archivo, reintente reiniciando el programa y controle que el archivo sea el correcto a guardar");
		break;
	}
}

void optionSeven(LinkedList* pListArcades , LinkedList* pListSound)
{
	int respuesta;

	respuesta = Controller_SortArcades(pListArcades, pListSound);
	switch(respuesta)
	{
		case 1:
			printf("La lista fue ordenada con exito, puede verla a travez de la opcion 4 cuando lo desee....");
		break;
		case -1:
			printf("Algo fallo, reintente..");
		break;
	}
}

void optionEight(LinkedList* pListArcades , LinkedList* pListSound)
{
	int respuesta;

	respuesta = Controller_GamesListAtTheMoment(pListArcades, pListSound);
	switch(respuesta)
	{
		case 0:
			printf("La lista fue ordenada con exito, puede encontrarla con el nombre con el que guardo el archivo....");
		break;
		case -1:
			printf("Algo fallo, reintente..");
		break;
		case -2:
			printf("no se pudo crear el archivo..");
		break;
		case -3:
			printf("no se pudo generar el listado..");
		break;
	}
}

void optionNine(LinkedList* pListArcades , LinkedList* pListSound)
{
	int respuesta;

	respuesta = Controller_MultiplayerGamesList(pListArcades, pListSound);
	switch(respuesta)
	{
		case 0:
			printf("La lista fue ordenada con exito, puede encontrarla con el nombre con el que guardo el archivo....");
		break;
		case -1:
			printf("Algo fallo, reintente..");
		break;
		case -2:
			printf("no se pudo crear el archivo..");
		break;
		case -3:
			printf("no se pudo generar el listado..");
		break;
	}
}

void optionTen(LinkedList* pListArcades , LinkedList* pListSound)
{
	int respuesta;

	respuesta = Controller_UpdateArcadeCoins(pListArcades, pListSound);
	switch(respuesta)
	{
		case -1:
			printf("Algo fallo, reintente..");
		break;
		case 1:
			printf("Las monedas de los arcades, fueron actualizadas con exito!..");
		break;
	}
}
