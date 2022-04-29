#include "Sonido.h"

eSound* newSound(void)
{
	return (eSound*) calloc(1 , sizeof(eSound));
}

eSound* newSound_Parameters(char* idSound, char* soundType)
{
	eSound* aux;
	int auxId;
	char auxTipo[TAMSOUND];

	aux = NULL;
	if(idSound != NULL && soundType != NULL)
	{
		aux = newSound();

		if(aux != NULL)
		{
			auxId = atoi(idSound);
			strncpy(auxTipo , soundType , sizeof(auxTipo));

			setIdSound(aux, auxId);
			setSoundTypeSound(aux, auxTipo);
		}
	}

	return aux;
}

//-----------------------------GETTERS
int getSoundId(eSound* this , int* id)
{
	int ret;

	ret = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->soundId;
		ret = 0;
	}

	return ret;
}

int getSoundType(eSound* this , char* soundType)
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

//-----------------------------SETTERS

int setIdSound(eSound* this , int idSonido)
{
	int ret;

	ret = -1;
	if(this != NULL)
	{
		this->soundId = idSonido;
		ret = 0;
	}
	return ret;
}

int setSoundTypeSound(eSound* this , char* tipo)
{
	int ret;

	ret = -1;
	if(this != NULL && tipo != NULL)
	{
		strcpy(this->soundType , tipo);
		ret = 0;
	}

	return ret;
}

int findSoundIndexById(LinkedList* listaSonido , int idToFind)
{
	int ret;
	eSound* auxS;
	int id;

	ret = -1; //Error de nulls o no se encontro el id

	if(listaSonido != NULL)
	{
		for(int i=0; i<ll_len(listaSonido); i++)
		{
			auxS = ll_get(listaSonido, i);
			getSoundId(auxS, &id);

			if(id == idToFind)
			{
				ret = i;
				break;
			}
		}
	}

	return ret;
}
