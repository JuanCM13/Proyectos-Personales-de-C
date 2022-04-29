/*
 ============================================================================
 Name        : MyBookMesseges.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "input.h"
#include <LinkedList.h>

int main(void)
{
	setbuf(stdout , NULL);

	LinkedList* postList;
	LinkedList* usersList;

	int option;



	postList = ll_newLinkedList();
	usersList = ll_newLinkedList();

	if(postList != NULL && usersList != NULL)
	{
		do
		{

		}while(option != 20);
	}
}
