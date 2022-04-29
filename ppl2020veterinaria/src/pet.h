
#ifndef PET_H_
#define PET_H_

#include "input.h"
#include "nombres.h"

#define TAMPETNAME 51
#define TAMRACE 51
#define TAMTIPO 30

typedef struct
{
	int idPet;
	int idForeinKey;
	char petName[TAMPETNAME];
	int type;
	char race[TAMRACE];
	int petAge;
	float petWeight;
	int petSex;
	int isEmpty;

}ePet;


int isThereAnyLoadedPet(ePet* petsArray , int arrayLen);
int inityPetsList(ePet* petsArray , int arrayLen);
int getFreeIndexPet(ePet* petsArray , int arrayLen);

ePet generatePet(void);
int loadPet(ePet* petArray , int arrayLen , int* petId , int ownerIdToRelationate);


int freeOwnerPets(ePet petsArray[] , int petsArrayLen , int idRelation);
int modificatePet(ePet* petArray , int petLen);
int eliminatePetfromList(ePet* petArray , int petLen);


int thatPetIdExist(ePet* petArray , int petLen , int idRelation);
int pickPetId(ePet* petArray , int petLen , int* petId);
int printPetById(ePet petsArray[] , int petsArrayLen , int idRelation);
int sortByName(ePet* petArray , int petArrayLen , int order);


int countPetsByOwnerId(ePet* petList , int petListLen , int ownerIdRelation);
float petAgeAcumulator(ePet* petList , int petListLen , int type);
int petCounter(ePet* petList , int petListLen , int type);


#endif /* PET_H_ */

