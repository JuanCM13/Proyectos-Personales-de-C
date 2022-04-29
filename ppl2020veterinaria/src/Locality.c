#include "Locality.h"

int loadLoc(eLocality* locArray , int arrayLen , int* locId)
{
	int ret;
	int freeIndex;
	eLocality locToLoad;

	ret = -1;

	if(locArray != NULL)
	{
		ret = -2; // no hay lugar en la lsita

		freeIndex = getFreeIndexLoc(locArray , arrayLen);
		if(freeIndex > -1)
		{
			ret = -3; //Cancelo la operacion
			locToLoad = generateLoc();

			if(QueresSeguir("Seguro que desea cargar esta localidad? s/n") == 0)
			{
				ret = 0;

				*locId = *locId+1;
				locToLoad.idLocality = *locId;
				printf("El id de la localidad es: %d\n",locToLoad.idLocality);
				locToLoad.isEmpty = 0;
				locArray[freeIndex] = locToLoad;
			}
		}
	}

	return ret;

}
eLocality generateLoc(void)
{
	eLocality aux;

	Get_NombreEmpresa("Ingrese la provincia donde reside..", "Error, solo se admiten letras..", aux.state , sizeof(aux.state));
	OrdenarNombre(aux.state , sizeof(aux.state));

	Get_numeroConLimites("Ingrese La localidad:\n1.Lanus\n2.Lomas\n3.Avellaneda", "Error, ingrese una opcion entre las dadas..", 1 , 3 , &aux.locality);

	Get_numeroConLimites("Ingrese el codigo postal", "Error, solo se admiten numeros....", 0 , INT_MAX , &aux.postalCode);

	return aux;
}


int getFreeIndexLoc(eLocality* locArray , int arrayLen)
{
	int ret;

	ret = -2; //fallan nulls

	if(locArray != NULL && arrayLen > 0)
	{
		ret = -1; //No hay lugar disponible

		for(int i=0 ; i<arrayLen ; i++)
		{
			if(locArray[i].isEmpty == 1)
			{
				ret = i;
				break;
			}
		}
	}

	return ret;
}

int inityLocList(eLocality* locArray , int arrayLen)
{
	int ret;

	ret = -1;

	if(locArray != NULL)
	{
		for(int i=3 ; i<arrayLen ; i++)
		{
			locArray[i].isEmpty = 1;
		}
	}
	return ret;
}

int isThereAnyLoadedLoc(eLocality* locArray , int arrayLen)
{
	int ret;
	int i;

	ret = -1; //no hay cargado

	if(locArray != NULL && arrayLen > 0)
	{
		for(i=0 ; i<arrayLen ; i++)
		{
			if(locArray[i].isEmpty == 0)
			{
				ret = 0; //hay uno cargado
				break;
			}
		}
	}

	return ret;
}
int findLocalityByOwnerId(eLocality* locArray , int arrayLen , int idToFind)
{
	int ret;
	int i;

	if(locArray != NULL && arrayLen > 0 )
	{
		for(i=0 ; i<arrayLen ; i++)
		{
			if(locArray[i].isEmpty == 0 && locArray[i].idLocality == idToFind)
			{
				ret = locArray[i].locality;
				break;
			}
		}
	}
	return ret;
}




