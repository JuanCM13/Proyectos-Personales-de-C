#include "Inform.h"


int loadClient_Controller(eOwner* ownerList , int arrayLen , int* idOwner)
{
	int ret;
	int loadInform;

	ret = -1;

	if(ownerList != NULL)
	{
		ret = 0;

		loadInform = loadOwner(ownerList , arrayLen , idOwner);
		switch(loadInform)
		{
			case 0:
				printf("El cliente fue cargado de manera exitosa..\n");
			break;
			case -1:
				printf("Algo fallo, reintente..\n");
			break;
			case -2:
				printf("La lista de clientes se encuentra momentaneamente llena....\n");
			break;
			case -3:
				printf("La operacion fue cancelada..\n");
			break;
		}
	}

	return ret;
}

int loadPet_Controller(ePet* petList , int arrayLen , eOwner* ownerList , int ownerArrayLen , int* idPet)
{
	int ret;
	int loadInform;

	ret = -1;

	if(petList != NULL)
	{
		ret = 0;

		loadInform = getPetLoad(petList , arrayLen , ownerList , ownerArrayLen , idPet);
		switch(loadInform)
		{
			case 0:
				printf("La mascota fue cargada de manera exitosa..\n");
			break;
			case -1:
				printf("Algo fallo, reintente..\n");
			break;
			case -2:
				printf("La lista de mascotas se encuentra momentaneamente llena....\n");
			break;
			case -3:
				printf("La operacion fue cancelada..\n");
			break;
		}
	}

	return ret;
}

void showClientList_Controller(eOwner* ownerList , int ownerListLen , ePet* petList , int petListLen)
{
	int printInform;

	if(ownerList != NULL && petList != NULL && ownerListLen > 0 && petListLen > 0)
	{
		if(isThereAnyLoadedOwner(ownerList , ownerListLen) == 0 && isThereAnyLoadedPet(petList , petListLen) == 0)
		{
			printInform = printClients(ownerList , ownerListLen , petList , petListLen);
			switch(printInform)
			{
				case -1:
					printf("Fallaron los nulls..\n");
				break;
				case -2:
					printf("Fallo el printeo de datos..\n");
				break;
			}
		}
		else
		{
			printf("Para ingresar a esta opcion, debe haber almenos un cliente cargado junto con su mascota...\n");
		}

	}
}

int showOwnerSpaceAvailable(eOwner* ownerList , int ownerListLen)
{
	int ret;
	int spaceAvailable;

	ret = -1;

	if(ownerList != NULL  && ownerListLen > 0)
	{
		if(isThereAnyLoadedOwner(ownerList , ownerListLen) == 0)
		{
			spaceAvailable = countOwnersLoaded(ownerList , ownerListLen);

			if(spaceAvailable > 0)
			{
				spaceAvailable = ownerListLen - spaceAvailable;
				printf("Espacio disponible de la lista de dueños: %d\n",spaceAvailable);
				ret = 0;
			}
		}
		else
		{
			printf("Para ingresar a esta opcion, debe haber almenos un cliente cargado junto con su mascota...\n");
		}
	}

	return ret;
}

int eliminateOwner(eOwner* ownerList , int ownerListLen , ePet* petList , int tamPetList)
{
	int ret;
	int eliminateOwnerFlowControl;

	ret = -1;

	if(ownerList != NULL && ownerListLen > 0 && petList != NULL && tamPetList > 0)
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList , ownerListLen) == 0 && isThereAnyLoadedPet(petList, tamPetList) == 0)
		{
			eliminateOwnerFlowControl = eliminateOwnerWithPets(ownerList , ownerListLen , petList , tamPetList);
			switch(eliminateOwnerFlowControl)
			{
				case 1:
					printf("El cliente fue dado de baja del listado..\n");
				break;
				case 0:
					printf("El cliente junto con sus mascotas fueron dados de baja del listado..\n");
				break;
				case -1:
					printf("Algo fallo, reintente..\n");
				break;
				case -2:
					printf("No se encontro ese id, reintente...\n");
				break;
				case -3:
					printf("No se pudo dar de baja las mascotas de ese id, fallo, reintente..\n");
				break;
				case -4:
					printf("Cancelo la operacion...\n");
				break;
			}
		}
	}
	else
	{
		printf("Para ingresar a esta opcion, debe haber almenos un cliente cargado junto con su mascota...\n");
	}

	return ret;
}

int informMdPet(eOwner* ownerList , int ownerListLen , ePet* petList , int tamPetList)
{
	int ret;
	int petModResult;

	ret = -1;

	if(ownerList != NULL && ownerListLen > 0 && petList != NULL && tamPetList > 0)
	{
		if(isThereAnyLoadedOwner(ownerList , ownerListLen) == 0 && isThereAnyLoadedPet(petList, tamPetList) == 0)
		{
			ret = 0;

			petModResult = modificatePet(petList, tamPetList);
			switch(petModResult)
			{
				case 0:
					printf("La mascota seleccionada, fue modificada con exito..\n");
				break;
				case -1:
					printf("Algo fallo, reintente..\n");
				break;
				case -2:
					printf("No se encontro ese id, reintente y seleccione uno de la lista..\n");
				break;
				case -3:
					printf("La operacion fue cancelada...\n");
				break;

			}
		}
	}
	else
	{
		printf("Para ingresar a esta opcion, debe haber almenos un cliente cargado junto con su mascota...\n");
	}

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------

int eliminatePet(eOwner* ownerList , int ownerListLen , ePet* petList , int tamPetList)
{
	int ret;
	int eliminatePetResp;

	ret = -1;

	if(ownerList != NULL && ownerListLen > 0 && petList != NULL && tamPetList > 0)
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList , ownerListLen) == 0 && isThereAnyLoadedPet(petList, tamPetList) == 0)
		{
			eliminatePetResp = eliminatePetfromList(petList , tamPetList);
			switch(eliminatePetResp)
			{
				case 0:
					printf("La mascota fue borrada de la lista de manera exitosa..\n");
				break;
				case -1:
					printf("Algo fallo, reintente...\n");
				break;
				case -2:
					printf("El id ingresado no se encuentra registrado, ingrese uno del listado mostrado..\n");
				break;
				case -3:
					printf("Cancelo la operacion...\n");
				break;
			}
		}
	}
	else
	{
		printf("Para ingresar a esta opcion, debe haber almenos un cliente cargado junto con su mascota...\n");
	}

	return ret;
}

int addLocality(eLocality* localityList , int tamLocality , int* idLoc , eOwner* ownerList , int tamOwner)
{
	int ret;
	int loadLocality;

	ret = -1;

	if(localityList != NULL && tamLocality > 0)
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList, tamOwner) == 0)
		{
			loadLocality = loadLoc(localityList , tamLocality , idLoc);
			switch(loadLocality)
			{
				case 0:
					printf("La localidad fue cargada de manera exitosa..\n");
				break;
				case -1:
					printf("Algo fallo, reintente..\n");
				break;
				case -2:
					printf("La lista de localidades se encuentra momentaneamente llena....\n");
				break;
				case -3:
					printf("La operacion fue cancelada..\n");
				break;
			}
		}
		else
		{
			printf("Debe haber ingresado almenos 1 dueño para entrar a esta opcion..\n");
		}
	}

	return ret;
}

int organicePetListByName(ePet* petList , int tamPet , eOwner* ownerList , int tamOwner)
{
	int ret;
	int printInfo;

	ret = -1;

	if(petList != NULL && tamPet > 0 && ownerList != NULL && tamOwner > 0)
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList, tamOwner) == 0 && isThereAnyLoadedPet(petList, tamPet) == 0)
		{
			if(sortByName(petList , tamPet , 1) == 0)
			{
				printInfo = printPetsWithOwner(petList , tamPet , ownerList , tamOwner);
				switch(printInfo)
				{
					case -1:
						printf("Algo fallo reintente..\n");
					break;
					case -3:
						printf("No se logro encontrar el dueño de una mascota, verifique...\n");
					break;
				}
			}
			else
			{
				printf("No se pudo ordenar la lista, reintente..\n");
			}
		}
		else
		{
			printf("Debe haber ingresado almenos 1 dueño para entrar a esta opcion..\n");
		}
	}

	return ret;
}

int modificateClient(eOwner* ownerList , int tamOwner)
{
	int ret;
	int modResult;

	ret = -1;

	if(ownerList != NULL && tamOwner > 0)
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList, tamOwner) == 0)
		{
			modResult = modClient(ownerList, tamOwner);
			switch(modResult)
			{
				case 0:
					printf("El cliente fue modificado con exito..\n");
				break;
				case -1:
					printf("Algo fallo, reintente..\n");
				break;
				case -2:
					printf("No se encontro el id ingresado, ingrese uno de la lista..\n");
				break;
				case -3:
					printf("Operacion cancelada..\n");
				break;
			}

		}
		else
		{
			printf("Debe haber ingresado almenos 1 dueño para entrar a esta opcion..\n");
		}
	}

	return ret;
}

int petCounterByClient(ePet* petList , int tamPet , eOwner* ownerList , int tamOwner)
{
	int ret;

	ret = -1;

	if(petList != NULL && tamPet > 0 && ownerList != NULL && tamOwner > 0)
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList, tamOwner) == 0 && isThereAnyLoadedPet(petList, tamPet) == 0)
		{
			printf("Clientes con mas de 1 mascota cargadas al momento: \n");
			if(countOwnerPets(petList , tamPet , ownerList , tamOwner) == -2)
			{
				printf("No se encontro ningun cliente con mas de 1 mascota cargada al momento..\n");
			}

		}
		else
		{
			printf("Debe haber ingresado almenos 1 dueño para entrar a esta opcion..\n");
		}
	}

	return ret;
}


int countPetsThreeYearsOrMore(ePet* petList , int tamPet , eOwner* ownerList , int tamOwner)
{
	int ret;

	ret = -1;

	if(petList != NULL && tamPet > 0 && ownerList != NULL && tamOwner > 0)
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList, tamOwner) == 0 && isThereAnyLoadedPet(petList, tamPet) == 0)
		{
			printf("Listado de mascotas mayores a 3 años: \n");
			if(showPetsWithMoreThanThreeYears(petList , tamPet , ownerList , tamOwner) == -2)
			{
				printf("No se encontro ninguna mascota con mas de 3 años..\n");
			}
		}
		else
		{
			printf("Debe haber ingresado almenos 1 dueño para entrar a esta opcion..\n");
		}
	}

	return ret;
}


int sortPetsByType(ePet* petList , int tamPet , eOwner* ownerList , int tamOwner)
{
	int ret;

	ret = -1;

	if(petList != NULL && tamPet > 0 && ownerList != NULL && tamOwner > 0)
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList, tamOwner) == 0 && isThereAnyLoadedPet(petList, tamPet) == 0)
		{
			if(showPetsByType(petList , tamPet , ownerList , tamOwner) != 0)
			{
				printf("No se pudo filtrar la lista, reintente..\n");
			}
		}
		else
		{
			printf("Debe haber ingresado almenos 1 dueño para entrar a esta opcion..\n");
		}
	}

	return ret;
}

int printOwnersByPetsCant(ePet* petList , int tamPet , eOwner* ownerList , int tamOwner , int whatOption)
{
	int ret;
	int i;
	int option;
	int optionSortName;

	ret = -1;

	if(petList != NULL && tamPet > 0 && ownerList != NULL && tamOwner > 0 && (whatOption == 1 || whatOption == 2) )
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList, tamOwner) == 0 && isThereAnyLoadedPet(petList, tamPet) == 0)
		{
			Get_numeroConLimites("Ingrese el orden como ordenar la lista por cantidad de mascotas: \n1.Ascendente\n2.Descendente", "Error, elija una opcion entre las dadas..", 1, 2, &option);
			if(sortOwnersByPetsCant(ownerList, tamOwner , petList , tamPet , option) == 0)
			{
				if(whatOption == 2)
				{
					Get_numeroConLimites("Ingrese el orden como ordenar la lista por orden de nombre de dueño: \n1.Ascendente\n2.Descendente", "Error, elija una opcion entre las dadas..", 1, 2, &optionSortName);
					sortOwnersByName(ownerList , tamOwner , optionSortName);
				}

				printf("Dueños ordenados: \n");
				for(i=0 ; i<tamOwner ; i++)
				{
					if(ownerList[i].isEmpty == 0)
					{
						printf("%s %s \n",ownerList[i].ownerName , ownerList[i].ownerLastName);
					}
				}
			}
			else
			{
				printf("No se pudo ordenar el listado, reintente..\n");
			}
		}
		else
		{
			printf("Debe haber ingresado almenos 1 dueño para entrar a esta opcion..\n");
		}
	}
	return ret;
}

int petsAgeProm(ePet* petList , int tamPet , eOwner* ownerList , int tamOwner)
{
	int ret;
	float ageAcumulator;
	int petCant;
	float prom;

	ret = -1;

	if(petList != NULL && tamPet > 0 && ownerList != NULL && tamOwner > 0)
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList, tamOwner) == 0 && isThereAnyLoadedPet(petList, tamPet) == 0)
		{
			ageAcumulator = petAgeAcumulator(petList , tamPet , 0);
			petCant = petCounter(petList , tamPet , 0);

			if(petCant > 0)
			{
				prom = ageAcumulator/petCant;
				printf("El promedio de edades de mascotas es de: %.2f años de edad..\n",prom);
			}
			else
			{
				printf("No se pudo calcular el promedio de edades... reintente..\n");
			}
		}
		else
		{
			printf("Debe haber ingresado almenos 1 dueño para entrar a esta opcion..\n");
		}
	}
	return ret;
}

int petsAgePromPerType(ePet* petList , int tamPet , eOwner* ownerList , int tamOwner)
{
	int ret;
	float ageAcumulator;
	int petCant;
	float prom;
	int petType;

	ret = -1;

	if(petList != NULL && tamPet > 0 && ownerList != NULL && tamOwner > 0)
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList, tamOwner) == 0 && isThereAnyLoadedPet(petList, tamPet) == 0)
		{
			Get_numeroConLimites("Ingrese el tipo de mascota a calcular..\n1.Perro\n2.Gato\n3.Otro", "Error, ingrese una opcion entre las dadas..", 1, 3 , &petType);

			ageAcumulator = petAgeAcumulator(petList , tamPet , petType);
			petCant = petCounter(petList , tamPet , petType);

			if(petCant > 0)
			{

				prom = ageAcumulator/petCant;
				printf("El promedio de edades de mascotas es de: %.2f años de edad..\n",prom);
			}
			else
			{
				printf("No hay mascotas de ese tipo cargadas al momento...\n");
			}
		}
		else
		{
			printf("Debe haber ingresado almenos 1 dueño para entrar a esta opcion..\n");
		}
	}
	return ret;
}

int ownersAgePromBetwenWomanAndMen(eOwner* ownerList , int tamOwner , ePet* petList , int tamPet)
{
	int ret;
	float ageAcumulator;
	int pplCant;
	float prom;

	ret = -1;

	if(petList != NULL && tamPet > 0 && ownerList != NULL && tamOwner > 0)
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList, tamOwner) == 0 && isThereAnyLoadedPet(petList, tamPet) == 0)
		{
			ageAcumulator = ownerAgeAcumulatorWomanAndMen(ownerList , tamOwner);
			pplCant = ownerCounter(ownerList , tamOwner , 0);

			if(pplCant > 0)
			{
				prom = ageAcumulator/pplCant;
				printf("El promedio de edades de mujeres y hombres es de: %.2f años de edad..\n",prom);
			}
			else
			{
				printf("No se pudo calcular el promedio de edades de varones y mujeres por el momento, reintente...\n");
			}
		}
		else
		{
			printf("Debe haber ingresado almenos 1 dueño para entrar a esta opcion..\n");
		}
	}
	return ret;
}

int womanPorcentBetwenAllClients(eOwner* ownerList , int tamOwner , ePet* petList , int tamPet)
{
	int ret;
	float wmanCant;
	int pplCant;
	float prom;

	ret = -1;

	if(petList != NULL && tamPet > 0 && ownerList != NULL && tamOwner > 0)
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList, tamOwner) == 0 && isThereAnyLoadedPet(petList, tamPet) == 0)
		{
			wmanCant = ownerCounter(ownerList , tamOwner , 1); //2
			pplCant = ownerCounter(ownerList , tamOwner , 0);

			if(pplCant > 0)
			{
				prom = wmanCant/pplCant*100;
				printf("El porcentaje de mujeres sobre el total de clientes es de: %% %.2f \n",prom);
			}
			else
			{
				printf("No se pudo calcular el promedio de edades de varones y mujeres por el momento, reintente...\n");
			}
		}
		else
		{
			printf("Debe haber ingresado almenos 1 dueño para entrar a esta opcion..\n");
		}
	}
	return ret;
}

int showOwnersWithSameSexPets(eOwner* ownerList , int tamOwner , ePet* petList , int tamPet)
{
	int ret;
	int sexToFind;

	ret = -1;

	if(petList != NULL && tamPet > 0 && ownerList != NULL && tamOwner > 0)
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList, tamOwner) == 0 && isThereAnyLoadedPet(petList, tamPet) == 0)
		{
			Get_numeroConLimites("Ingrese el sexo a buscar..\n1.Macho\n2.Hembra", "Error, ingrese una opcion entre las dadas..", 1 , 2 , &sexToFind);
			if(printOwnersWithSameSexPets(ownerList , tamOwner , petList , tamPet , sexToFind) != 0)
			{
				printf("Al momento no hay dueños con todas sus mascotas del sexo elegido..\n");
			}
		}
		else
		{
			printf("Debe haber ingresado almenos 1 dueño para entrar a esta opcion..\n");
		}
	}
	return ret;
}

int showOwnersByLocality(eLocality* localityList , int localityLen , eOwner* ownerList , int tamOwner)
{
	int ret;
	int localityToFind;

	ret = -1;

	if(localityList != NULL && localityLen > 0 && ownerList != NULL && tamOwner > 0)
	{
		ret = 0;
		if(isThereAnyLoadedOwner(ownerList, tamOwner) == 0 && isThereAnyLoadedLoc(localityList, localityLen) == 0)
		{
			Get_numeroConLimites("Ingrese la localidad a buscar..\n1.Lanus\n2.Lomas\n3.Avellaneda", "Error, ingrese una opcion entre las dadas..", 1 , 3 , &localityToFind);
			if(printOwnersByLocality(localityList , localityLen , ownerList , tamOwner , localityToFind) == -2)
			{
				printf("No hay clientes con esa localidad cargada al momento..\n");
			}
		}
		else
		{
			printf("Debe haber ingresado almenos 1 dueño para entrar a esta opcion..\n");
		}
	}
	return ret;
}
