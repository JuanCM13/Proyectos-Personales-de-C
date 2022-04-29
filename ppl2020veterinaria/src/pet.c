#include "pet.h"

int isThereAnyLoadedPet(ePet* petsArray , int arrayLen)
{
	int ret;
	int i;

	ret = -1;

	if(petsArray != NULL && arrayLen > 0)
	{
		for(i=0 ; i<arrayLen ; i++)
		{
			if(petsArray[i].isEmpty == 0)
			{
				ret = 0;
				break;
			}
		}
	}
	return ret;
}

int inityPetsList(ePet* petsArray , int arrayLen)
{
	int ret;
	int i;

	ret = -1;

	if(petsArray != NULL && arrayLen > 0)
	{
		ret = 0;
		for(i=11 ; i<arrayLen ; i++)
		{
			petsArray[i].isEmpty = 1;
		}
	}
	return ret;
}

int getFreeIndexPet(ePet* petsArray , int arrayLen)
{
	int ret;
	int i;

	ret = -1;

	if(petsArray != NULL && arrayLen > 0)
	{
		ret = -2; //no hay lugar disponible
		for(i=0 ; i<arrayLen ; i++)
		{
			if(petsArray[i].isEmpty == 1)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}

ePet generatePet(void)
{
	ePet aux;

	Get_NombreEmpresa("Ingrese el nombre de la mascota..", "Error el nombre no puede contener letras, solo numeros.. ", aux.petName , sizeof(aux.petName));
	OrdenarNombre(aux.petName, sizeof(aux.petName));

	Get_numeroConLimites("Ingrese el tipo de animal:\n1.Perro\n2.Gato\n3.Otro", "Error, ingrese una opcion entre las dadas..", 1 , 3 , &aux.type);

	Get_NombreEmpresa("Ingrese la raza..", "Error no puede ser tan grande..", aux.race, sizeof(aux.race));

	Get_numeroConLimites("Ingrese la edad del animal entre 0 y 40 años", "Error, ingrese un numero dentro del rango..", 0 , 40 , &aux.petAge);

	Get_floatConLimites("Ingrese el peso del animal, hasta 200kg", "Error, ingrese un numero dentro del rango..", 1 , 200 , &aux.petWeight);

	Get_numeroConLimites("Ingrese el sexo de animal:\n1.Macho\n2.Hembra", "Error, ingrese una opcion entre las dadas..", 1 , 2 , &aux.petSex);

	return aux;
}

int loadPet(ePet* petArray , int arrayLen , int* petId , int ownerIdToRelationate)
{
	int ret;
	int indexToAlocate;
	ePet petAux;

	ret = -1;

	if(petArray != NULL && petId != NULL && arrayLen > 0)
	{
		ret = -2; //no hay mas lugar
		indexToAlocate = getFreeIndexPet(petArray , arrayLen);
		if(indexToAlocate > -1)
		{
			ret = -3; //cancelo
			petAux = generatePet();

			if(QueresSeguir("Seguro que desea cargar esta mascota en la lista?? s/n") == 0)
			{
				ret = 0;

				*petId = *petId + 1;
				petAux.idPet = *petId;
				petAux.idForeinKey = ownerIdToRelationate;
				petArray[indexToAlocate] = petAux;
			}
		}
	}

	return ret;
}


int freeOwnerPets(ePet petsArray[] , int petsArrayLen , int idRelation)
{
	int ret;
	int i;

	ret = -1;

	if(petsArray != NULL && petsArrayLen > 0)
	{
		ret = 1; //el cliente no tiene cargado ninguna mascota al momento

		for(i=0 ; i<petsArrayLen ; i++)
		{
			if(petsArray[i].isEmpty == 0 && petsArray[i].idForeinKey == idRelation)
			{
				ret = 0;
				petsArray[i].isEmpty = 1;
			}
		}
	}
	return ret;
}

int modificatePet(ePet* petArray , int petLen)
{
	int ret;
	int petIdToModificate;
	int indexPet;
	int fieldToModificate;

	ret = -1;

	if(petArray != NULL && petLen > 0)
	{
		ret = -2; //no se encontro ese id seleccionado
		pickPetId(petArray , petLen , &petIdToModificate);
		indexPet = thatPetIdExist(petArray , petLen , petIdToModificate);

		if(indexPet > -1)
		{
			Get_numeroConLimites("Ingrese el campo a modificar..\n1.NOMBRE\n2.TIPO\n3.RAZA\n4.EDAD\n5.PESO\n6.SEXO\n", "Error, elija dentro de las opciones", 1, 6, &fieldToModificate);

			ret = -3; //cancelo
			if(QueresSeguir("Seguro que desea modificar el campo?? s/n") == 0)
			{
				ret = 0;
				switch(fieldToModificate)
				{
					case 1:
						Get_NombreEmpresa("Ingrese el nombre de la mascota..", "Error el nombre no puede contener letras, solo numeros.. ", petArray[indexPet].petName , sizeof(petArray[indexPet].petName));
						OrdenarNombre(petArray[indexPet].petName, sizeof(petArray[indexPet].petName));
					break;
					case 2:
						Get_numeroConLimites("Ingrese el tipo de animal:\n1.Perro\n2.Gato\n3.Otro", "Error, ingrese una opcion entre las dadas..", 1 , 3 , &petArray[indexPet].type);
					break;
					case 3:
						Get_NombreEmpresa("Ingrese la raza..", "Error no puede ser tan grande..",petArray[indexPet].race, sizeof(petArray[indexPet].race));
					break;
					case 4:
						Get_numeroConLimites("Ingrese la edad del animal entre 0 y 40 años", "Error, ingrese un numero dentro del rango..", 0 , 40 , &petArray[indexPet].petAge);
					break;
					case 5:
						Get_floatConLimites("Ingrese el peso del animal, hasta 200kg", "Error, ingrese un numero dentro del rango..", 1 , 200 , &petArray[indexPet].petWeight);
					break;
					case 6:
						Get_numeroConLimites("Ingrese el sexo de animal:\n1.Macho\n2.Hembra", "Error, ingrese una opcion entre las dadas..", 1 , 2 , &petArray[indexPet].petSex);
					break;
				}
			}
		}
	}
	return ret;
}

int pickPetId(ePet* petArray , int petLen , int* petId)
{
	int ret;
	int i;
	char type[51];
	int idOption;

	ret = -1;

	if(petArray != NULL && petLen > 0)
	{
		ret = 0;
		for(i=0 ; i<petLen ; i++)
		{
			if(petArray[i].isEmpty == 0)
			{
				switch(petArray[i].type)
				{
					case 1:
						strcpy(type , "Perro");
					break;
					case 2:
						strcpy(type , "Gato");
					break;
					case 3:
						strcpy(type , "Otro");
					break;

				}
				printf("ID: %d -- NOMBRE: %s -- TIPO: %s -- RAZA: %s -- EDAD: %d \n",petArray[i].idPet , petArray[i].petName , type , petArray[i].race , petArray[i].petAge);
			}
		}

		Get_numeroConLimites("Ingrese el id de la mascota..", "Error, debe ser mayor a cero y menor a 600000", 0, INT_MAX, &idOption);
		*petId = idOption;
	}

	return ret;
}

int thatPetIdExist(ePet* petArray , int petLen , int idRelation)
{
	int ret;
	int i;

	ret = -1;

	if(petArray != NULL && petLen > 0)
	{
		ret = -2; // no se encontro ese id

		for(i=0 ; i<petLen ; i++)
		{
			if(petArray[i].isEmpty == 0 && petArray[i].idPet == idRelation)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}

int eliminatePetfromList(ePet* petArray , int petLen)
{
	int ret;
	int idSelect;
	int index;

	ret = -1;

	if(petArray != NULL && petLen > 0)
	{
		ret = -2; //no se encontro el id
		if(pickPetId(petArray , petLen , &idSelect) == 0)
		{
			index = thatPetIdExist(petArray , petLen , idSelect);
			if(index > -1)
			{
				ret = -3; //cancelo
				if(QueresSeguir("Seguro que desea eliminar esta mascota?? s/n") == 0)
				{
					ret = 0;
					petArray[index].isEmpty = 1;
				}
			}
		}
	}

	return ret;
}

int printPetById(ePet petsArray[] , int petsArrayLen , int idOwnerRelation)
{
	int ret;
	int i;
	char type[50];
	char sex[50];

	ret = -1;

	if(petsArray != NULL && petsArrayLen > 0)
	{
		ret = -2; //Ese cliente no tiene cargadas mascotas todavia
		for(i=0 ; i<petsArrayLen ; i++)
		{
			if(petsArray[i].isEmpty == 0 && petsArray[i].idForeinKey == idOwnerRelation)
			{
				ret = 0;
				switch(petsArray[i].type)
				{
					case 1:
						strcpy(type , "Perro");
					break;
					case 2:
						strcpy(type , "Gato");
					break;
					case 3:
						strcpy(type , "Otro");
					break;
				}

				if(petsArray[i].petSex == 1)
				{
					strcpy(sex , "Macho");
				}
				else
				{
					strcpy(sex , "Hembra");
				}

				printf("ID: %d -- NOMBRE: %s -- TIPO: %s -- RAZA: %s -- EDAD: %d -- SEXO: %s \n",petsArray[i].idPet , petsArray[i].petName , type , petsArray[i].race , petsArray[i].petAge , sex);

			}
		}
	}

	return ret;
}

int sortByName(ePet* petArray , int petArrayLen , int order)
{
	int ret;
	int i;
	int j;
	ePet aux;

	ret = -1;

	if(petArray != NULL && petArrayLen > 0)
	{
		for(i=0 ; i<petArrayLen-1 ; i++)
		{
			for(j=i+1 ; j<petArrayLen ; j++)
			{
				puts(petArray[i].petName);
				puts(petArray[j].petName);
				if((strcmp(petArray[i].petName , petArray[j].petName) > 0 && order == 1))
				{
					printf("Entre\n");
					ret = 0;
					aux = petArray[i];
					petArray[i] = petArray[j];
					petArray[j] = aux;
				}
				else
				{
					if(strcmp(petArray[i].petName , petArray[j].petName) < 0 && order == 0)
					{
						printf("Entre\n");
						ret = 0;
						aux = petArray[i];
						petArray[i] = petArray[j];
						petArray[j] = aux;
					}
				}
			}
		}
	}
	printf("Retorno vale: %d\n",ret);
	return ret;
}




int countPetsByOwnerId(ePet* petList , int petListLen , int ownerIdRelation)
{
	int counter;
	int i;

	counter = -1;

	if(petList != NULL && petListLen > 0)
	{
		counter = 0;
		for(i=0 ; i<petListLen ; i++)
		{
			if(petList[i].isEmpty == 0 && petList[i].idForeinKey == ownerIdRelation)
			{
				counter++;
			}
		}
	}

	return counter;
}

float petAgeAcumulator(ePet* petList , int petListLen , int type)
{
	float ret;
	int i;

	ret = -1;

	if(petList != NULL && petListLen > 0)
	{
		ret = 0;

		for(i=0 ; i<petListLen ; i++)
		{
			if(petList[i].isEmpty == 0 && (type == 0 || type == petList[i].type))
			{
				ret += petList[i].petAge;
			}
		}
	}
	return ret;
}

int petCounter(ePet* petList , int petListLen , int type)
{
	int ret;
	int i;

	ret = -1;

	if(petList != NULL && petListLen > 0)
	{
		ret = 0;

		for(i=0 ; i<petListLen ; i++)
		{
			if(petList[i].isEmpty == 0 && (type == 0 || type == petList[i].type))
			{
				ret++;
			}
		}
	}
	return ret;
}


