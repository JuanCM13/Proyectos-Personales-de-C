/*
 ============================================================================
 Name        : PracticaParcialProgramacion2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define LARGOARRAY 5
#define NUEVOTAM 10

int main(void)
{
	setbuf(stdout, NULL);
	int i;
	int* arrayDinamico;
	int* reallocArray;

	arrayDinamico = (int*) malloc(sizeof(int) * LARGOARRAY);

	if(arrayDinamico != NULL)
	{
		for(i=0 ; i<LARGOARRAY ; i++)
		{
			printf("Ingrese un numero\n");
			scanf("%d",(arrayDinamico+i));
		}

		for(i=0 ; i<LARGOARRAY ; i++)
		{
			printf("%d\n",*(arrayDinamico+i));
		}

		reallocArray = realloc(arrayDinamico , sizeof(int)*NUEVOTAM);

		if(reallocArray != NULL)
		{
			arrayDinamico = reallocArray;

			for(i=LARGOARRAY ; i<NUEVOTAM ; i++)
			{
				printf("Ingrese un numero\n");
				scanf("%d",arrayDinamico+i);
			}

			for(i=0 ; i<NUEVOTAM ; i++)
			{
				printf("%d\n",*(arrayDinamico+i));
			}

			free(arrayDinamico);

		}

	}

	//----------------------------------------------------------



}

//------------------------------------------------------------

int guardarEnArchivoBinario(ePendrive* pendrive , char* path)
{
	int ret;
	FILE* aux;

	ret = -1;

	if(pendrive != NULL && path != NULL)
	{
		aux = fopen(path , "r");

		ret = -2; //no abre

		if(aux != NULL)
		{
			ret = 0;

			fwrite(pendrive , sizeof(ePendrive) , 1 , aux);
			fclose(aux);
		}
	}

	return ret;
}

//-------------------------------------------------------------------------

int leerDesdeArchivo( char* path)
{
	int ret;
	FILE* aux;
	ePendrive* auxiliarPendrive;

	ret = -1;

	if(path != NULL)
	{
		aux = fopen(path , "r");

		ret = -2; //no abre

		if(aux != NULL)
		{
			ret = 0;

			while(!feof(aux))
			{
				auxiliarPendrive = new_pendrive();

				if(auxiliarPendrive != NULL)
				{
					fread(auxiliarPendrive , sizeof(ePendrive) , 1 , aux);
				}

			}
			fclose(aux);
		}

	}

	return ret;
}

//-------------------------------------------------------------------------
