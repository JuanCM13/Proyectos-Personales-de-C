/*
 ============================================================================
 Name        : MyBookGestorMensajes.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "controller.h"

int main(void)
{
	setbuf(stdout, NULL);

	LinkedList* messageList;
	LinkedList* usersList;

	//LinkedList* listaOrdenada;

	messageList = ll_newLinkedList();
	usersList = ll_newLinkedList();
	//listaOrdenada = ll_newLinkedList();

	if(messageList != NULL && usersList != NULL)
	{
		if(controller_readPostFile(messageList) == 0)
		{
			if(controller_readUserFile(usersList) == 0)
			{
				if(controller_printPriority(messageList , usersList) == 0)
				{
					if(controller_printPosts(messageList , usersList) != 0)
					{
						printf("Rompi todo de nuevo\n ");
					}
				}
				else
				{
					printf("Ordeno mal--\n");
				}
			}
			else
			{
				printf("Rompio la lectura de users..\n");
			}
		}
		else
		{
			printf("Rompio la lectura de posts..\n");
		}
	}


	return 0;
}
