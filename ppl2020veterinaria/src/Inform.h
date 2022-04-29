
#ifndef INFORM_H_
#define INFORM_H_

#include "Nexo.h"

int loadClient_Controller(eOwner* ownerList , int arrayLen , int* idOwner);
int loadPet_Controller(ePet* petList , int arrayLen , eOwner* ownerList , int ownerArrayLen , int* idPet);
void showClientList_Controller(eOwner* ownerList , int ownerListLen , ePet* petList , int petListLen);
int showOwnerSpaceAvailable(eOwner* ownerList , int ownerListLen);
int eliminateOwner(eOwner* ownerList , int ownerListLen , ePet* petList , int tamPetList);
int informMdPet(eOwner* ownerList , int ownerListLen , ePet* petList , int tamPetList);
int eliminatePet(eOwner* ownerList , int ownerListLen , ePet* petList , int tamPetList);
int addLocality(eLocality* localityList , int tamLocality , int* idLoc , eOwner* ownerList , int tamOwner);
int organicePetListByName(ePet* petList , int tamPet , eOwner* ownerList , int tamOwner);
int modificateClient(eOwner* ownerList , int tamOwner);
int petCounterByClient(ePet* petList , int tamPet , eOwner* ownerList , int tamOwner);
int countPetsThreeYearsOrMore(ePet* petList , int tamPet , eOwner* ownerList , int tamOwner);
int sortPetsByType(ePet* petList , int tamPet , eOwner* ownerList , int tamOwner);
int printOwnersByPetsCant(ePet* petList , int tamPet , eOwner* ownerList , int tamOwner , int whatOption);
int petsAgeProm(ePet* petList , int tamPet , eOwner* ownerList , int tamOwner);
int petsAgePromPerType(ePet* petList , int tamPet , eOwner* ownerList , int tamOwner);
int ownersAgePromBetwenWomanAndMen(eOwner* ownerList , int tamOwner , ePet* petList , int tamPet);
int womanPorcentBetwenAllClients(eOwner* ownerList , int tamOwner , ePet* petList , int tamPet);
int showOwnersWithSameSexPets(eOwner* ownerList , int tamOwner , ePet* petList , int tamPet);
int showOwnersByLocality(eLocality* localityList , int localityLen , eOwner* ownerList , int tamOwner);



#endif /* INFORM_H_ */
