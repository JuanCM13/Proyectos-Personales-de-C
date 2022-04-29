#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#define STRING_MAX 200

//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se pudo leer el archivo , -2; //FALLO EL PARSEO DE DATOS
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int ret;
	FILE* pFile;

	ret = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		ret = -3;

		pFile = fopen(path , "r");

		if(pFile != NULL)
		{
			if(parser_EmployeeFromText(pFile , pArrayListEmployee) == 0)
			{
				ret = 0;
				fclose(pFile);
			}
			else
			{
				ret = -2;
			}
		}

	}

    return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si esta todo ok , -1 fallaron nulls ,-3; //No se pudo leer el archivo , -2; //FALLO EL PARSEO DE DATOS
 *
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret;
	FILE* pFile;

	ret = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		ret = -3;
		pFile = fopen(path , "rb");

		if(pFile != NULL)
		{
			if(parser_EmployeeFromBinary(pFile , pArrayListEmployee) == 0)
			{
				ret = 0;
				//printf("\nGuardo bien\n");
			}
			else
			{
				ret = -2;
			}

			fclose(pFile);
		}
	}

    return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int -1 fallan nulls, 0 si esta todo ok
 *
 */

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int ret;
	Employee* aux;
	FILE* pContador;
	int id;

	ret = -1;

	if(pArrayListEmployee != NULL)
	{
		pContador = fopen("Contador.txt" , "r");

		if(pContador == NULL)
		{
			pContador = fopen("Contador.txt" , "w");
			fprintf(pContador , "1000");

			fclose(pContador);

			fopen("Contador.txt" , "r");
			//No lo cierro asi si no llega a estar creado pasa al prox if y hace la operacion
		}


		if(pContador != NULL)
		{
			if(parserCounter(pContador , &id) == 0)
			{
				//printf("Pude convertir algo..\n");
				//printf("Id vale: %d\n",id);
				fclose(pContador);
			}

			aux = cargarEmpladoPorTeclado(&id);

			if(aux != NULL)
			{
				ret = 0;
				ll_add(pArrayListEmployee , aux);

				pContador = fopen("Contador.txt" , "w");

				fprintf(pContador , "%d", id);

				fclose(pContador);
			}
		}
	}

    return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si sale todo ok, -1 fallan nulls , -2 se cancelo la operacion , -3 fallo la modificacion
 *
 */

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int ret;

	ret = -1;

	if(pArrayListEmployee != NULL)
	{
		ret = modificarEmpleado(pArrayListEmployee);

	}

    return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si sale todo ok, -1 fallan nulls , -2 se cancelo la operacion
 *
 */

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int ret;

	ret = -1;

	if(pArrayListEmployee != NULL)
	{
		ret = eliminarEmpleado(pArrayListEmployee);

	}

    return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int  0 si sale todo ok, -1 fallan nulls , -2 fallo la muestra de empleados
 *
 */

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int ret;

	ret = -1;

	if(pArrayListEmployee != NULL)
	{
		ret = imprimirEmpleados(pArrayListEmployee);
	}

    return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si sale todo ok, -1 fallan nulls
 *
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int ret;

	ret = -1;

	if(pArrayListEmployee != NULL)
	{
		ret = ordenarEmpleados(pArrayListEmployee);
	}

    return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si sale todo ok, -1 fallan nulls , -2 No se pudo cargar el archivo
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int ret;
	int i;
	int largo;
	int auxId;
	int auxSueldo;
	int auxHoras;
	char auxNombre[MAXNOMBRE];

	FILE* pFile;
	Employee* aux;

	aux = NULL;
	ret = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		ret = -2;
		largo = 0;

		pFile = fopen( path , "w");

		if(pFile != NULL)
		{
			largo = ll_len(pArrayListEmployee);
			fprintf(pFile , "Id,Nombre,Horas Trabajadas,Sueldo\n");
			for(i=0 ; i<largo ; i++)
			{
				aux = (Employee*) ll_get(pArrayListEmployee , i);

				employee_getId(aux , &auxId);
				employee_getNombre(aux , auxNombre);
				employee_getHorasTrabajadas(aux , &auxHoras);
				employee_getSueldo(aux , &auxSueldo);

				fprintf(pFile , "%d,%s,%d,%d\n", auxId , auxNombre , auxHoras , auxSueldo);
			}

			ret = 0;
		}

		fclose(pFile);
	}

    return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si sale todo ok, -1 fallan nulls , -2 No se pudo cargar el archivo
 *
 */

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret;
	int i;
	int largo;
	FILE* pFile;
	Employee* aux;

	ret = -1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		aux = NULL;
		ret = -2;

		pFile = fopen( path , "wb");

		if(pFile != NULL)
		{
			largo = ll_len(pArrayListEmployee);
			//printf("Largo: %d\n",largo);
			for(i=0 ; i<largo ; i++)
			{
				aux = (Employee*) ll_get(pArrayListEmployee , i);
				//printf("%d , %s , %d , %d\n", aux->id , aux->nombre , aux->horasTrabajadas , aux->sueldo);

				if(aux != NULL)
				{
					fwrite( aux , sizeof(Employee) , 1 , pFile);
				}

			}

			ret = 0;
		}

		fclose(pFile);
	}

    return ret;
}

