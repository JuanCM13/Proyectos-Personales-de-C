#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si esta todo okey , -1 si fallan nulls , -2 si no pudo cargar algun elemento , -3 no se consiguio espacio en la memoria dinamica
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int ret;
	char auxId[100];
	char auxSueldo[100];
	char auxHoras[100];
	char auxNombre[MAXNOMBRE];
	Employee* auxiliar;

	ret = -1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		ret = 0;

		fscanf(pFile , "%[^,], %[^,], %[^,], %[^\n]\n" , auxId , auxNombre , auxHoras , auxSueldo);

		while(!feof(pFile))
		{
			if(fscanf(pFile , "%[^,], %[^,], %[^,], %[^\n]\n" , auxId , auxNombre , auxHoras , auxSueldo) == 4)
			{
				//printf("%s -- %s -- %s -- %s \n" , auxId , auxNombre , auxHoras , auxSueldo);

				auxiliar = employee_newParametros(auxId , auxNombre , auxHoras , auxSueldo);

				if(auxiliar != NULL)
				{
					ll_add( pArrayListEmployee , auxiliar);
				}
				else
				{
					ret = -3;
					break;
				}

			}
			else
			{
				ret = -2;
				break;
			}

		}

	}

    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si esta todo okey , -1 si fallan nulls , -2 si no pudo parsear algun elemento
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret;
	Employee* aux;

	ret = -1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		ret = 0;


		while(!feof(pFile))
		{
			aux = employee_new();

			if(aux != NULL)
			{
				fread( aux , sizeof(Employee) , 1 ,  pFile);

				if(feof(pFile)) //ASI NO ROMPE EL PROGRAMA, SINO AL LEERLO COMO BINARIO ME ITERABA 1 VEZ MAS, Y ESO LO GUARDABA TODOO CON 0
				{
					break;
				}

				ll_add( pArrayListEmployee , aux);
				//printf("%d , %s , %d , %d\n", aux->id , aux->nombre , aux->horasTrabajadas , aux->sueldo);
			}
			else
			{
				ret = -2;
				break;
			}
		}

	}

    return ret;
}

//----------------------------------------------------------------------------------------------------


/** \brief Parsea los datos del archivo contador.txt (controlador contador).
 *
 * \param path char*
 * \param int* contador
 * \return int 0 si esta todo ok , -1 si falan nulls
 *
 */

int parserCounter(FILE* pFile , int* contador)
{
	char contadorAux[ESPACIOCONTADORID];
	int aux;
	int ret;

	ret = -1;

	if(pFile != NULL && contador != NULL)
	{
		fscanf(pFile , "%[^ ] " , contadorAux);

		aux = atoi (contadorAux);

		*contador = aux;
		ret = 0;
	}

	return ret;
}
