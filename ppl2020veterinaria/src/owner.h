
#ifndef OWNER_H_
#define OWNER_H_

#include "input.h"
#include "nombres.h"

#define TAMOWNERNAME 51
#define TAMOWNERLASTNAME 51
#define TAMPHONE 15

typedef struct
{
	int idOwner;
	int idLocality;
	char ownerName[TAMOWNERNAME];
	char ownerLastName[TAMOWNERLASTNAME];
	int contactPhone;
	int ownerAge;
	int clientSex;
	int isEmpty;

}eOwner;


int isThereAnyLoadedOwner(eOwner* ownerArray , int arrayLen);
int inityOwnerList(eOwner* ownerArray , int arrayLen);
int getFreeIndexOwner(eOwner* ownerArray , int arrayLen);


int loadOwner(eOwner* ownerArray , int arrayLen , int* idOwner);
eOwner generateOwner(void);

int pickOwnerId(eOwner* ownerArray , int arrayLen);
int thatIdExist(eOwner* ownerArray , int arrayLen , int idToFind);
int countOwnersLoaded( eOwner* ownerArray , int arrayLen );
int modClient(eOwner* ownerArray , int arrayLen);

int sortOwnersByName(eOwner* ownerList , int ownerLen , int order);
float ownerAgeAcumulatorWomanAndMen(eOwner* ownerList , int ownerListLen);
int ownerCounter(eOwner* ownerList , int ownerListLen , int sex);


#endif /* OWNER_H_ */
