/*
 * Services.h
 *
 *  Created on: 18 dic 2021
 *      Author: caand
 */

#ifndef SERVICES_H_
#define SERVICES_H_

#include "input.h"
#include "nombres.h"

#define TAMNAME 33
#define TAMEMAIL 65

typedef struct
{
	int id;
	char name[TAMNAME];
	char email[TAMEMAIL];

}eService;

eService* newService(void);
eService* newService_parameters(char* id , char* name , char* mail);

int getId(eService* this , int* id);
int getName(eService* this , char* name);
int getEmail(eService* this , char* email);

int setId(eService* this , int id);
int setName(eService* this , char* name);
int setEmail(eService* this , char* email);

eService* findIdRelation(LinkedList* service , int idToFind);


#endif /* SERVICES_H_ */
