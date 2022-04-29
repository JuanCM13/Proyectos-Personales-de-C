/*
 * Users.h
 *
 *  Created on: 21 ene 2022
 *      Author: caand
 */

#ifndef USERS_H_
#define USERS_H_

#include "input.h"
#include "nombres.h"

#define TAMNAME 51
#define TAMLASTNAME 51
#define TAMLOCALITY 51
#define TAMEMAIL 100
#define TAMTEL 9
#define TAMADRESS 50

typedef struct
{
	int userId;
	char userName[TAMNAME];
	char userLastName[TAMLASTNAME];
	char userLocality[TAMLOCALITY];
	char userEmail[TAMEMAIL];
	char userPhone[TAMTEL];
	char userAdress[TAMADRESS];
	int isEmpty;
}eUser;

int initUserArray(eUser* userList , int listLen);
int getFreeIndexUser(eUser* userList , int listLen);
int isThereAnyLoadUser(eUser* userList , int listLen);


int loadUser(eUser* userList , int listLen , int* idUser);
eUser generateUser(void);
int modUser(eUser* userList , int listLen);


int selectUserId(eUser* userList , int listLen);
void printUserBasicInfo(eUser user);
int findUserIndexById(eUser* userList , int listLen , int userIdToFind);


#endif /* USERS_H_ */
