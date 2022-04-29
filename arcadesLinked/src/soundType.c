#include "soundType.h"

//----------------------------------------------------------------------------------------------------------------------------

eSoundType* newSoundParameters(int id, char* sonido)
{
	eSoundType* aux;

	aux = NULL;

	if(sonido != NULL)
	{
		aux = (eSoundType*) calloc(1 , sizeof(eSoundType));

		if(aux != NULL)
		{
			aux->soundId = id;
			strcpy(aux->soundType , sonido);
		}
	}

	return aux;
}

//----------------------------------------------------------------------------------------------------------------------------

int getSoundId(eSoundType* this , int* soundId)
{
	int ret;

	ret = -1;

	if(this != NULL && soundId != NULL)
	{
		*soundId = this->soundId;
		ret = 0;
	}

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------------

int getSoundType(eSoundType* this , char* soundType)
{
	int ret;

	ret = -1;

	if(this != NULL && soundType != NULL)
	{
		strcpy(soundType , this->soundType);
		ret = 0;
	}

	return ret;
}

//----------------------------------------------------------------------------------------------------------------------------

int findIdSound(LinkedList* listaSonido , int idAencontrar)
{
	int ret;
	int i;
	int largo;
	eSoundType* auxSonido;
	int idSonido;

	ret = -1;

	if(listaSonido != NULL)
	{
		largo = ll_len(listaSonido);

		for(i=0 ; i<largo ; i++)
		{
			auxSonido = ll_get(listaSonido, i);
			getSoundId(auxSonido, &idSonido);

			if(idSonido == idAencontrar)
			{
				ret = i;
				break;
			}
		}
	}

	return ret;
}
