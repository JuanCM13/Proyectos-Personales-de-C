

#ifndef NEXO_H_
#define NEXO_H_

#include "owner.h"
#include "pet.h"
#include "Locality.h"

int printMenu(int* optionToComplete);
int getPetLoad(ePet* petArray , int petArrayLen , eOwner* ownerList , int ownerArrayLen , int* counterIdPet);
int printClients(eOwner* ownerList , int ownerArrayLen , ePet* petArray , int petArrayLen);
int eliminateOwnerWithPets(eOwner* ownerList , int ownerArrayLen , ePet* petArray , int petArrayLen);
int printPetsWithOwner(ePet* petArray , int petArrayLen , eOwner* ownerList , int ownerArrayLen);
int countOwnerPets(ePet* petArray , int petArrayLen , eOwner* ownerList , int ownerArrayLen);
int showPetsWithMoreThanThreeYears(ePet* petArray , int petArrayLen , eOwner* ownerList , int ownerArrayLen);
void printOnePetAndOwner(ePet pet , eOwner owner);
int showPetsByType(ePet* petArray , int petArrayLen , eOwner* ownerList , int ownerArrayLen);
int printByType(ePet* petArray , int petArrayLen , eOwner* ownerList , int ownerArrayLen , int typeToFind);
int sortOwnersByPetsCant(eOwner* ownerArray , int ownerLen , ePet* petList , int petLen , int order);
int printOwnersWithSameSexPets(eOwner* ownerArray , int ownerLen , ePet* petList , int petLen , int sex);
int printOwnersByLocality(eLocality* localityList , int localityLen , eOwner* ownerArray , int ownerLen , int localityToFind);


#endif /* NEXO_H_ */
