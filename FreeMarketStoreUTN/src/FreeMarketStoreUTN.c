/*
 ============================================================================
 Name        : FreeMarketStoreUTN.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Controller.h"

#define TAMUSERLIST 100
#define TAMPRODUCT 1000

int main(void)
{
	setbuf(stdout,NULL);
	eUser usersList[TAMUSERLIST];
	eProduct productList[TAMPRODUCT];

	int option;
	int productIdCounter;
	int userIdCounter;

	userIdCounter = 0;
	productIdCounter = 0;

	initUserArray(usersList, TAMUSERLIST);
	initProductArray(productList, TAMPRODUCT);

	do
	{
		printMenu(&option);
		switch(option)
		{
			case 1:
				if(controller_loadUsers(usersList , TAMUSERLIST , &userIdCounter) == -1)
				{
					printf("Algo fallo, reintente..\n");
				}
			break;
			case 2:
				if(controller_modUser(usersList , TAMUSERLIST) == -1)
				{
					printf("Algo fallo, reintente..\n");
				}
			break;
			case 3:
				//if(controller_modUser(usersList , TAMUSERLIST) == -1)

			break;
			case 4:
				if(controller_loadProduct(productList , TAMPRODUCT , &productIdCounter , usersList , TAMUSERLIST) == -1)
				{
					printf("Algo fallo, reintente..\n");
				}
			break;
		}


	}while(option != 11);

}
