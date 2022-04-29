/*
 ============================================================================
 Name        : practicaParcialLabo2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "input.h"
#include "Controller.h"

int main(void)
{
	setBuff(stdout , NULL);
	int opcion;
	int respuestaCaseUno;
	LinkedList* pLinkedList;

	pLinkedList = ll_newLinkedList();


	if(pLinkedList != NULL)
	{
		Get_numeroConLimites("Ingrese opcion","error",1,9,&opcion);

		switch(opcion)
		{
			case 1:

				controller_loadPilotsFile(pLinkedList);

			break;
		}
	}



	return 0;
}
