#include "owner.h"

//-------------------------------------------------------------------------

int inityOwnerList(eOwner* ownerArray , int arrayLen)
{
	int ret;

	ret = -1;

	if(ownerArray != NULL)
	{
		for(int i=5 ; i<arrayLen ; i++)
		{
			ownerArray[i].isEmpty = 1;
		}
	}
	return ret;
}


//-------------------------------------------------------------------------

int getFreeIndexOwner(eOwner* ownerArray , int arrayLen)
{
	int ret;

	ret = -2; //fallan nulls

	if(ownerArray != NULL && arrayLen > 0)
	{
		ret = -1; //No hay lugar disponible

		for(int i=0 ; i<arrayLen ; i++)
		{
			if(ownerArray[i].isEmpty == 1)
			{
				ret = i;
				break;
			}
		}
	}

	return ret;
}

//---------------------------------------------------------------------------

int loadOwner(eOwner* ownerArray , int arrayLen , int* idOwner)
{
	int ret;
	int freeIndex;
	eOwner ownerToLoad;

	ret = -1;

	if(ownerArray != NULL)
	{
		ret = -2; // no hay lugar en la lsita

		freeIndex = getFreeIndexOwner(ownerArray , arrayLen);
		if(freeIndex > -1)
		{
			ret = -3; //Cancelo la operacion
			ownerToLoad = generateOwner();

			if(QueresSeguir("Seguro que desea cargar este usuario? s/n") == 0)
			{
				ret = 0;

				*idOwner = *idOwner+1;
				ownerToLoad.idOwner = *idOwner;
				printf("El id del usuario es: %d\n",ownerToLoad.idOwner);
				ownerToLoad.isEmpty = 0;
				ownerArray[freeIndex] = ownerToLoad;
			}
		}
	}

	return ret;

}

//-----------------------------------------------------------------------------

eOwner generateOwner(void)
{
	eOwner aux;

	Get_NombreEmpresa("Ingrese el nombre del cliente..", "Error, solo se admiten letras..", aux.ownerName , sizeof(aux.ownerName));
	OrdenarNombre(aux.ownerName , sizeof(aux.ownerName));

	Get_NombreEmpresa("Ingrese el apellido del cliente..", "Error, solo se admiten letras..", aux.ownerLastName , sizeof(aux.ownerLastName));
	OrdenarNombre(aux.ownerLastName , sizeof(aux.ownerLastName));

	Get_numeroConLimites("Ingrese La localidad:\n1.Lanus\n2.Lomas\n3.Avellaneda", "Error, ingrese una opcion entre las dadas..", 1 , 3 , &aux.idLocality);

	Get_numeroConLimites("Ingrese el telefono de contacto", "Error, solo se admiten numeros..", 0 , 10000000, &aux.contactPhone);

	Get_numeroConLimites("Ingrese la edad del cliente..", "Error, ingrese una edad entre los valores 12 y 120 años..", 12 , 120 , &aux.ownerAge);

	Get_numeroConLimites("Ingrese el sexo del cliente\n1-HOMBRE\n2-Mujer\n3-Otro..", "Error, ingrese 1 para hombre 2 para mujer y 3 para otro..", 1 , 3 , &aux.clientSex);

	return aux;
}

//------------------------------------------------------------------------------

int isThereAnyLoadedOwner(eOwner* ownerArray , int arrayLen)
{
	int ret;
	int i;

	ret = -1; //no hay cargado

	if(ownerArray != NULL && arrayLen > 0)
	{
		for(i=0 ; i<arrayLen ; i++)
		{
			if(ownerArray[i].isEmpty == 0)
			{
				ret = 0; //hay uno cargado
				break;
			}
		}
	}

	return ret;
}


int pickOwnerId(eOwner* ownerArray , int arrayLen)
{
	int ret;
	int i;
	int idAux;

	ret = -1;

	if(ownerArray != NULL && arrayLen > 0)
	{
		printf("LISTADO CLIENTES: \n\n");
		for(i=0 ; i<arrayLen ; i++)
		{
			if(ownerArray[i].isEmpty == 0)
			{
				printf("ID CLIENTE: %d -- NOMBRE: %s -- APELLIDO: %s -- TELEFONO: %d \n",ownerArray[i].idOwner , ownerArray[i].ownerName ,
																								ownerArray[i].ownerLastName  , ownerArray[i].contactPhone);
			}
		}
		Get_numeroConLimites("Ingrese el id a conectar", "Error, el numero no puede ser tan grande..", 0 , INT_MAX , &idAux);
		ret = idAux;
	}

	return ret;
}


int thatIdExist(eOwner* ownerArray , int arrayLen , int idToFind)
{
	int ret;
	int i;

	ret = -1;

	if(ownerArray != NULL && arrayLen > 0 && idToFind > 0 )
	{
		ret = -2; //no se encontro
		for(i=0 ; i<arrayLen ; i++)
		{
			if(ownerArray[i].idOwner == idToFind)
			{
				ret = i;
				break;
			}
		}
	}

	return ret;
}

int countOwnersLoaded( eOwner* ownerArray , int arrayLen )
{
	int ret;
	int i;
	int counter;

	ret = -1;

	if(ownerArray != NULL && arrayLen > 0)
	{
		counter = 0;
		for(i=0 ; i<arrayLen ; i++)
		{
			if(ownerArray[i].isEmpty == 0)
			{
				counter++;
			}
		}

		ret = counter;
	}

	return ret;
}

int modClient(eOwner* ownerArray , int arrayLen)
{
	int ret;
	int idToModificate;
	int indexOfOwner;
	int fieldToMod;

	ret = -1;

	if(ownerArray != NULL && arrayLen > 0)
	{
		ret = -2; //no se encontro el id
		idToModificate = pickOwnerId(ownerArray, arrayLen);
		indexOfOwner = thatIdExist(ownerArray, arrayLen, idToModificate);
		if(indexOfOwner > -1)
		{
			ret = -3; //cancelo la op
			Get_numeroConLimites("Ingrese el campo a modificar:\n1.Nombre\n2.Apellido\n3.Num Telefonico\n4.Edad\n5.Sexo\n6.Localidad\n", "Error, ingrese una opcion entre las dadas..", 1 , 6 , &fieldToMod);

			if(QueresSeguir("Seguro que desea modificar el campo seleccionado? s/n") == 0)
			{
				ret = 0;
				switch(fieldToMod)
				{
					case 1:
						Get_NombreEmpresa("Ingrese el nombre del cliente..", "Error, solo se admiten letras..", ownerArray[indexOfOwner].ownerName , sizeof(ownerArray[indexOfOwner].ownerName));
						OrdenarNombre(ownerArray[indexOfOwner].ownerName , sizeof(ownerArray[indexOfOwner].ownerName));
					break;
					case 2:
						Get_NombreEmpresa("Ingrese el apellido del cliente..", "Error, solo se admiten letras..", ownerArray[indexOfOwner].ownerLastName , sizeof(ownerArray[indexOfOwner].ownerLastName));
						OrdenarNombre(ownerArray[indexOfOwner].ownerLastName , sizeof(ownerArray[indexOfOwner].ownerLastName));
					break;
					case 3:
						Get_numeroConLimites("Ingrese el sexo del cliente\n1-HOMBRE\n2-Mujer\n3-Otro..", "Error, ingrese 1 para hombre 2 para mujer y 3 para otro..", 1 , 3 , &ownerArray[indexOfOwner].clientSex);
					break;
					case 4:
						Get_numeroConLimites("Ingrese el telefono de contacto", "Error, solo se admiten numeros..", 0 , 10000000, &ownerArray[indexOfOwner].contactPhone);
					break;
					case 5:
						Get_numeroConLimites("Ingrese la edad del cliente..", "Error, ingrese una edad entre los valores 12 y 120 años..", 12 , 120 , &ownerArray[indexOfOwner].ownerAge);
					break;
					case 6:
						Get_numeroConLimites("Ingrese la localidad\n1-Lanus\n2-Lomas\n3-Avellaneda..", "Error, ingrese 1 para hombre 2 para mujer y 3 para otro..", 1 , 3 , &ownerArray[indexOfOwner].idLocality);
					break;
				}
			}
		}
	}

	return ret;
}

int sortOwnersByName(eOwner* ownerList , int ownerLen , int order)
{
	int ret;
	eOwner aux;
	int i;
	int j;
	char nameOne[TAMOWNERNAME];
	char nameTwo[TAMOWNERNAME];

	ret = -1;

	if(ownerList != NULL && ownerLen > 0 && (order == 1 || order == 2))
	{
		ret = 0;
		for(i=0 ; i<ownerLen-1 ; i++)
		{
			for(j=i+1 ; j<ownerLen ; j++)
			{
				if(ownerList[i].isEmpty == 0 && ownerList[j].isEmpty == 0)
				{
					strncpy(nameOne , ownerList[i].ownerName , sizeof(nameOne));
					strncpy(nameTwo , ownerList[j].ownerName , sizeof(nameTwo));

					if( (order == 1 && strcmp(nameOne , nameTwo) > 0) || (order == 2 &&  strcmp(nameOne , nameTwo) < 0) )
					{
						aux = ownerList[i];
						ownerList[i] = ownerList[j];
						ownerList[j] = aux;
					}
				}
			}
		}
	}
	return ret;
}

float ownerAgeAcumulatorWomanAndMen(eOwner* ownerList , int ownerListLen)
{
	float ret;
	int i;

	ret = -1;

	if(ownerList != NULL && ownerListLen > 0)
	{
		ret = 0;

		for(i=0 ; i<ownerListLen ; i++)
		{
			if(ownerList[i].isEmpty == 0 && (ownerList[i].clientSex == 1 || ownerList[i].clientSex == 2))
			{
				ret += ownerList[i].ownerAge;
			}
		}
	}
	return ret;
}

int ownerCounter(eOwner* ownerList , int ownerListLen , int sex)
{
	int ret;
	int i;

	ret = -1;

	if(ownerList != NULL && ownerListLen > 0)
	{
		ret = 0;

		for(i=0 ; i<ownerListLen ; i++)
		{
			//0 cuenta todos, sino el tipo especificado de sexo, 1 , 2 o 3
			if(ownerList[i].isEmpty == 0 && (sex == 0 || sex == ownerList[i].clientSex))
			{
				ret++;
			}
		}
	}
	return ret;
}
