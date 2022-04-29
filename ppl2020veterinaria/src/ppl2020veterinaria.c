/*
 ============================================================================
 Name        : ppl2020veterinaria.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Inform.h"

#define TAMOWNER 10
#define TAMPET 20
#define TAMLOCALITYLIST 10

int main(void)
{
	setbuf(stdout, NULL);
	int option;
	int idOwner;
	int idPets;
	int idLocality;

	eOwner ownerList[TAMOWNER] = {
									{1, 1 , "Juan" , "Perez" ,  124525 , 25 , 1 , 0},
									{2, 2 , "Pedro" , "Mendez", 124525 , 26 , 1 , 0},
									{3, 3 , "Carlos" , "Roca" , 124525 , 27 , 1 , 0},
									{4, 1 , "Maria" , "Asin" , 124525 , 23 , 2 , 0},
									{5, 2 , "Josefina" , "Ollas" , 124525 , 24 , 2 , 0}
								};


	ePet petList[TAMPET] = {
								{1, 1 , "Churro" , 1 , "Labrador" , 4 , 24 , 1 , 0},
								{2, 1 , "Pepe" , 1 , "Labrador" , 5 , 27 , 1 , 0},
								{3, 1 , "Bruce" , 2 , "Naranjon" , 1 , 6 , 1 , 0},
								{4, 4 , "Mansa" , 2 , "Negro" , 4 , 4 , 2 , 0},
								{5, 4 , "Pupa" , 2 , "Negro" , 5 , 5 , 2 , 0},
								{6, 5 , "Dana" , 3 , "Iguana" , 20 , 2 , 2 , 0},
								{7, 5 , "Choco" , 1 , "Pitbull" , 6 , 54 , 1 , 0},
								{8, 2 , "Mani" , 1 , "Labrador" , 2 , 25 , 1 , 0},
								{9, 3 , "Salame" , 2 , "Negro" , 4 , 6 , 2 , 0},
								{10, 3 , "Salmon" , 2 , "Blanco" , 3 , 4 , 1 , 0},
								{11, 3 , "Cabeza" , 1 , "Bulldog" , 8 , 14 , 1 , 0}
							};

	eLocality localityList[TAMLOCALITYLIST] = {
												{1, "Buenos Aires" , 1824 , 1 , 0},
												{2, "Rio Cuarto" , 1645 , 1 , 0},
												{3, "Panama" , 3294 , 3 , 0}
											  };


	idOwner = 5;
	idPets = 11;
	idLocality = 3;

	inityOwnerList(ownerList, TAMOWNER);
	inityPetsList(petList, TAMPET);
	inityLocList(localityList, TAMLOCALITYLIST);

	do
	{
		printMenu(&option);

		switch(option)
		{
			case 1:
				if(loadClient_Controller(ownerList, TAMOWNER , &idOwner) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 2:
				if(loadPet_Controller(petList , TAMPET , ownerList , TAMOWNER , &idPets) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 3:
				showClientList_Controller(ownerList , TAMOWNER , petList , TAMPET);
			break;
			case 4:
				if(showOwnerSpaceAvailable(ownerList , TAMOWNER) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 5:
				if(eliminateOwner(ownerList, TAMOWNER , petList , TAMPET) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 6:
				if(informMdPet(ownerList, TAMOWNER , petList , TAMPET) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 7:
				if(eliminatePet(ownerList, TAMOWNER , petList , TAMPET) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 8:
				if(addLocality(localityList , TAMLOCALITYLIST , &idLocality , ownerList , TAMOWNER) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 9:
				if(organicePetListByName(petList , TAMPET , ownerList , TAMOWNER) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 10:
				if(modificateClient(ownerList , TAMOWNER) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 11:
				if(petCounterByClient(petList , TAMPET , ownerList , TAMOWNER) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 12:
				if(countPetsThreeYearsOrMore(petList , TAMPET , ownerList , TAMOWNER) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 13:
				if(sortPetsByType(petList , TAMPET , ownerList , TAMOWNER) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 14:
				if(printOwnersByPetsCant(petList , TAMPET , ownerList , TAMOWNER , 1) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 15:
				if(printOwnersByPetsCant(petList , TAMPET , ownerList , TAMOWNER , 2) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 16:
				if(petsAgeProm(petList , TAMPET , ownerList , TAMOWNER) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 17:
				if(petsAgePromPerType(petList , TAMPET , ownerList , TAMOWNER) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 18:
				if(ownersAgePromBetwenWomanAndMen(ownerList , TAMOWNER , petList , TAMPET) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 19:
				if(womanPorcentBetwenAllClients(ownerList , TAMOWNER , petList , TAMPET) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 20:
				if(showOwnersWithSameSexPets(ownerList , TAMOWNER , petList , TAMPET) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
			case 21:
				if(showOwnersByLocality(localityList , TAMLOCALITYLIST , ownerList , TAMOWNER) != 0)
				{
					printf("Todo lo que podia fallar, fallo..\n");
				}
			break;
		}

	}while(option != 25);

	printf("\n\n\n-----------------------------------PROGRAMA FINALIZADO-----------------------------------\n");

}
