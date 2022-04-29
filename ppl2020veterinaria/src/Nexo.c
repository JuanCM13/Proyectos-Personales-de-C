#include "Nexo.h"

int printMenu(int* optionToComplete)
{
	int ret;

	ret = -1;

	if(optionToComplete != NULL)
	{
		ret = 0;

		printf("|----------------------------------------------------------|\n");
		printf("|	1) Carga Cliente                                  |\n");
		printf("|	2) Carga Mascota                                  |\n");
		printf("|	3) Mostrar clientes con sus mascotas              |\n");
		printf("|	4) Mostrar cantidad de espacio para dueños        |\n");
		printf("|	5) Baja Cliente                                   |\n");
		printf("|	6) Modificar Mascota                              |\n");
		printf("|	7) Baja Mascota                                   |\n");
		printf("|	8) Agregar Localidad                              |\n");
		printf("|	9) Ordenar listado por nombre mascota             |\n");
		printf("|	10) Modificar Dueño                               |\n");
		printf("|	11) Listar clientes con mas de 1 mascota          |\n");
		printf("|	12) Listar mascotas con mas de 3 años             |\n");
		printf("|	13) Listar mascotas por tipo                      |\n");
		printf("|	14) Ordenar dueños por cant de mascotas           |\n");
		printf("|	15) Ordenar dueños por cant de mascotas y nombre  |\n");
		printf("|	16) Promedio de edad de todas las mascotas        |\n");
		printf("|	17) Promedio de edad de mascotas por tipo         |\n");
		printf("|	18) Promedio de edad de mujeres y hombres         |\n");
		printf("|	19) Promedio de mujeres sobre el total de clientes|\n");
		printf("|	20) Mostrar clientes con mascotas del mismo sexo  |\n");
		printf("|	21) Mostrar clientes por localidad                |\n");
		printf("|	25) Salir                                         |\n");
		printf("|----------------------------------------------------------|\n");

		Get_numeroConLimites("Ingrese una opcion del menu..", "Error, reingrese..", 1, 25 , optionToComplete);

	}

	return ret;
}

int getPetLoad(ePet* petArray , int petArrayLen , eOwner* ownerList , int ownerArrayLen , int* counterIdPet)
{
	int ret;
	int ownerIdAux;

	ret = -1;

	if(petArray != NULL && petArrayLen > 0 && ownerList != NULL && ownerArrayLen > 0)
	{
		ret = -2; //no se encontro el id...

		ownerIdAux = pickOwnerId(ownerList , ownerArrayLen);

		if(thatIdExist(ownerList , ownerArrayLen , ownerIdAux) == 0)
		{
			ret = loadPet(petArray , petArrayLen , counterIdPet , ownerIdAux);
		}
	}

	return ret;
}

int printClients(eOwner* ownerList , int ownerArrayLen , ePet* petArray , int petArrayLen)
{
	int ret;
	int i;

	ret = -1;

	if(petArray != NULL && petArrayLen > 0 && ownerList != NULL && ownerArrayLen > 0)
	{
		ret = -2; // No se pudo imprimir la lista, reintente
		for(i=0 ; i<ownerArrayLen ; i++)
		{
			 if(ownerList[i].isEmpty == 0)
			 {
				 ret = 0;
				 printf("Cliente: %s , %s\n",ownerList[i].ownerName , ownerList[i].ownerLastName);

				 if(printPetById(petArray , petArrayLen , ownerList[i].idOwner) != 0)
				 {
					 printf("El Cliente no tiene cargado ninguna mascota todavia..\n");
				 }
			 }
		}

	}

	return ret;
}

int eliminateOwnerWithPets(eOwner* ownerList , int ownerArrayLen , ePet* petArray , int petArrayLen)
{
	int ret;
	int indexToEliminate;
	int idToEliminate;
	int freePetsRespons;

	ret = -1;

	if(petArray != NULL && petArrayLen > 0 && ownerList != NULL && ownerArrayLen > 0)
	{
		ret = -2;//no se encontro el id..

		idToEliminate = pickOwnerId(ownerList, ownerArrayLen);
		indexToEliminate = thatIdExist(ownerList, ownerArrayLen, idToEliminate); //verifico que el id seleccionado se encuentre en la lista de ids cargados al momento

		if(indexToEliminate > -1)
		{
			ret = -4; //cancelo la operacion
			if(QueresSeguir("Seguro que desea dar de baja el cliente? , todas sus mascotas a su nombre seran eliminadas... s/n") == 0)
			{
				ret = -3; //no se pudo dar de baja las mascotas de ese id
				freePetsRespons = freeOwnerPets(petArray , petArrayLen , idToEliminate);
				if(freePetsRespons > -1)
				{
					ret = freePetsRespons;
					ownerList[indexToEliminate].isEmpty = 1;
				}
			}
		}
	}

	return ret;
}


int printPetsWithOwner(ePet* petArray , int petArrayLen , eOwner* ownerList , int ownerArrayLen)
{
	int ret;
	int i;
	int indexOwner;

	ret = -1;

	if(petArray != NULL && petArrayLen > 0 && ownerList != NULL && ownerArrayLen > 0)
	{
		ret = -2; //no hay ninguna mascota cargada
		for(i=0 ; i<petArrayLen ; i++)
		{
			if(petArray[i].isEmpty == 0)
			{
				ret = 0;
				indexOwner = thatIdExist(ownerList , ownerArrayLen , petArray[i].idForeinKey);
				if(indexOwner > -1)
				{
					printOnePetAndOwner(petArray[i] , ownerList[indexOwner]);
				}
				else
				{
					ret = -3; //no se encontro el dueño
					break;
				}
			}
		}
	}
	return ret;
}

void printOnePetAndOwner(ePet pet , eOwner owner)
{
	char type[51];


	switch(pet.type)
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
	printf("DUEÑO: %s,%s -- MASCOTA: %s -- TIPO: %s -- RAZA: %s -- EDAD: %d -- PESO: %.2f \n",owner.ownerName , owner.ownerLastName ,
																pet.petName , type , pet.race , pet.petAge , pet.petWeight);

}

int countOwnerPets(ePet* petArray , int petArrayLen , eOwner* ownerList , int ownerArrayLen)
{
	int ret;
	int i;

	ret = -1;

	if(petArray != NULL && petArrayLen > 0 && ownerList != NULL && ownerArrayLen > 0)
	{
		ret = -2; //no se encontro ninguno con mas de 1 cargado
		for(i=0 ; i<ownerArrayLen ; i++)
		{
			if(ownerList[i].isEmpty == 0)
			{
				if(countPetsByOwnerId(petArray , petArrayLen , ownerList[i].idOwner) > 1)
				{
					ret = 0;
					printf("%s %s\n", ownerList[i].ownerName , ownerList[i].ownerLastName);
				}
			}
		}
	}

	return ret;
}

int showPetsWithMoreThanThreeYears(ePet* petArray , int petArrayLen , eOwner* ownerList , int ownerArrayLen)
{
	int ret;
	int i;
	int indexOwner;

	ret = -1;

	if(petArray != NULL && ownerList != NULL && petArrayLen > 0 && ownerArrayLen > 0)
	{
		ret = -2; //no hay mascotas con mas de 3 años
		for(i=0 ; i<petArrayLen ; i++)
		{
			if(petArray[i].isEmpty == 0 && petArray[i].petAge > 3)
			{
				ret = 0;

				indexOwner = thatIdExist(ownerList , ownerArrayLen , petArray[i].idForeinKey);
				if(indexOwner > -1)
				{
					printOnePetAndOwner(petArray[i] , ownerList[indexOwner]);
				}
			}
		}
	}
	return ret;
}


int showPetsByType(ePet* petArray , int petArrayLen , eOwner* ownerList , int ownerArrayLen)
{
	int ret;
	int option;

	ret = -1;

	if(petArray != NULL && ownerList != NULL && petArrayLen > 0 && ownerArrayLen > 0)
	{
		ret = 0;
		Get_numeroConLimites("Ingrese el tipo de mascota a listar...\n1.Perro\n2.Gato\n3.Otro", "Error, ingrese una opcion entre las dadas..", 1, 3 , &option);

		printByType(petArray , petArrayLen , ownerList , ownerArrayLen , option);
	}
	return ret;
}


int printByType(ePet* petArray , int petArrayLen , eOwner* ownerList , int ownerArrayLen , int typeToFind)
{
	int i;
	int ret;
	int indexOwner;
	int flagControl;

	ret = -1;
	if(petArray != NULL && ownerList != NULL && petArrayLen > 0 && ownerArrayLen > 0)
	{
		flagControl = 0;
		ret = 0;
		for(i=0 ; i<petArrayLen ; i++)
		{
			if(petArray[i].isEmpty == 0 && petArray[i].type == typeToFind)
			{
				indexOwner = thatIdExist(ownerList , ownerArrayLen , petArray[i].idForeinKey);
				if(indexOwner > -1)
				{
					flagControl = 1;
					printOnePetAndOwner(petArray[i] , ownerList[indexOwner]);
				}
			}
		}
		if(flagControl == 0)
		{
			printf("Aun no hay ninguna mascota de ese tipo cargada..\n");
		}
	}
	return ret;
}

int sortOwnersByPetsCant(eOwner* ownerArray , int ownerLen , ePet* petList , int petLen , int order)
{
	int ret;
	int i;
	int j;
	int counterI;
	int counterJ;
	eOwner aux;

	ret = -1;//fallo el ordenamiento/nulls
	if(ownerArray != NULL && ownerLen > 0 && petList != NULL && petLen > 0 && (order == 1 || order == 2))
	{
		ret = 0; //order just fine
		for(i=0 ; i<ownerLen-1 ; i++)
		{
			for(j= i+1 ; j<ownerLen ; j++)
			{
				if(petList[i].isEmpty == 0 && petList[j].isEmpty == 0)
				{
					counterI = countPetsByOwnerId(petList , petLen , ownerArray[i].idOwner);
					counterJ = countPetsByOwnerId(petList , petLen , ownerArray[j].idOwner);

					if( (order == 1 && counterJ < counterI) || (order == 2 && counterJ > counterI) )
					{
						aux = ownerArray[i];
						ownerArray[i] = ownerArray[j];
						ownerArray[j] = aux;
					}
				}
			}
		}
	}
	return ret;
}

int printOwnersWithSameSexPets(eOwner* ownerArray , int ownerLen , ePet* petList , int petLen , int sex)
{
	int ret;
	int i;
	int flagControl;

	ret = -1;//fallo el ordenamiento/nulls
	if(ownerArray != NULL && ownerLen > 0 && petList != NULL && petLen > 0 && (sex == 1 || sex == 2))
	{
		ret = -2; //No hay mascotas de ese sexo cargadas..

		switch(sex)
		{
			case 1:
				printf("Dueños de mascotas de sexo Macho: \n");
			break;
			case 2:
				printf("Dueños de mascotas de sexo Hembra: \n");
			break;
		}

		for(i=0 ; i<ownerLen ; i++)
		{
			if(ownerArray[i].isEmpty == 0)
			{
				for(int j=0 ; j<petLen ; j++) //hago todo aca asi puedo buscar las mascotas de cada usuario, sitiene mas de 1 se me complica hacerlo en otra funcion aparte..
				{
					if(petList[j].isEmpty == 0 && petList[j].idForeinKey == ownerArray[i].idOwner)
					{
						if(petList[j].petSex == sex)
						{
							flagControl = 0;
						}
						else
						{
							flagControl = 1;
							break;
						}
					}
				}
			}
			if(flagControl == 0)
			{
				ret = 0;
				printf("%s , %s\n",ownerArray[i].ownerName , ownerArray[i].ownerLastName);
			}
		}
	}
	return ret;
}

int printOwnersByLocality(eLocality* localityList , int localityLen , eOwner* ownerArray , int ownerLen , int localityToFind)
{
	int ret;
	int i;
	char locality[100];

	ret = -1;//fallo el ordenamiento/nulls
	if(ownerArray != NULL && ownerLen > 0 && localityList != NULL && localityLen > 0)
	{
		switch(localityToFind)
		{
			case 1:
				strncpy(locality , "Lanus" , sizeof(locality));
			break;
			case 2:
				strncpy(locality , "Lomas" , sizeof(locality));
			break;
			case 3:
				strncpy(locality , "Avellaneda" , sizeof(locality));
			break;
		}

		printf("Listado de clientes de la localidad %s:\n",locality);
		ret = -2; //No hay clientes con esa localidad cargada..
		for(i=0 ; i<ownerLen ; i++)
		{
			if(ownerArray[i].isEmpty == 0)
			{
				if(ownerArray[i].idLocality == localityToFind)
				{
					ret = 0;

					printf("%s , %s\n",ownerArray[i].ownerName , ownerArray[i].ownerLastName);
				}
			}
		}
	}
	return ret;
}
