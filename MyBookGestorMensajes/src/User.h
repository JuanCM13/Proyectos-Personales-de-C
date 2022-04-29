/*
 * User.h
 *
 *  Created on: 15 dic 2021
 *      Author: caand
 */

#ifndef USER_H_
#define USER_H_

#include "input.h"
#include "nombres.h"

#define TAMNICK 100

typedef struct
{
	int idUser;
	char userNick[TAMNICK];
	int userPopularity;
}eUser;


eUser* newUser(void);
eUser* newUser_parameters(char* userId , char* userNick , char* userPopularity);


//SETTERS
int setIdUser(eUser* this , int idUser);
int setUserPopularity(eUser* this , int userPopularity);
int setUserNick(eUser* this , char* userNick);


// GETTERS
int getUserNick(eUser* this , char* userNick);
int getIdUser(eUser* this , int* idUser);
int getUserPopularity(eUser* this , int* userPopularity);


eUser* findUserById(LinkedList* userList , int idToFind);
int orderByUserPopularity(void* elementA , void* elementB);
int compareByNick(void* elemento1, void* elemento2);

#endif /* USER_H_ */
