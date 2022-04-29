#include "Employee.h"

//-------------------------------------------------------------------------------------------------------------------

/** \brief Imprime menu de opciones y devuelve la opcion seleccionada
 *
 * \param int* respuesta
 * \return int 0 si sale todo ok, -1 fallan nulls
 *
 */

int desplegarMenu(int* respuesta)
{
    int aux;
    int ret;

    ret = -1;

    if(respuesta != NULL)
    {
    	ret = 0;
        printf("\n\n|----------------------------------------MENU--------------------------------------------------|\n");
        printf("|   1) Cargar los datos de los empleados desde el archivo data.csv (modo texto).               |\n");
        printf("|   2) Cargar los datos de los empleados desde el archivo data.bin (modo binario).             |\n");
        printf("|   3) Alta de empleado                                                                        |\n");
        printf("|   4) Modificar datos de empleado                                                             |\n");
        printf("|   5) Baja de empleado                                                                        |\n");
        printf("|   6) Listar empleados                                                                        |\n");
        printf("|   7) Ordenar empleados                                                                       |\n");
        printf("|   8) Guardar los datos de los empleados en el archivo data.csv (modo texto).                 |\n");
        printf("|   9) Guardar los datos de los empleados en el archivo data.csv (modo binario).               |\n");
        printf("|   10) Salir                                                                                  |\n");
        printf("|----------------------------------------------------------------------------------------------|\n\n");

        Get_numeroConLimites("SELECCIONE UNA OPCION..", "ERROR, INGRESE UNA OPCION ENTRE LAS MOSTRADAS..",1,11,&aux);
        *respuesta = aux;
    }

    return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief retorna puntero de tipo Employee
 *
 * \return Employee*  o NULL
 *
 */

Employee* employee_new()
{
	Employee* empleado;

	empleado = NULL;

	empleado = (Employee*) calloc( 1 , sizeof(Employee));

	return empleado;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Retorna puntero a empleado y settea en este estructura tipo empleado
 *
 * \param char* idStr
 * param char* nombreStr
 * param char* horasTrabajadasStr
 * param char* sueldoSrt
 * \return return Employee* o NULL
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr , char* sueldoSrt )
{

	Employee* empleadoAux;
	int id;
	int sueldo;
	int horasTrabajadas;
	char nombre[MAXNOMBRE];

	empleadoAux = NULL;

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoSrt != NULL)
	{
		empleadoAux = employee_new();

		if(empleadoAux != NULL)
		{
			if( (esNumero(idStr , strlen(nombreStr)) == 0)
			&& (sonLetrasConGuion(nombreStr , strlen(nombreStr)) == 0)
			&& (esNumero(horasTrabajadasStr , strlen(horasTrabajadasStr)) == 0)
			&& (esNumero(sueldoSrt , strlen(sueldoSrt)) == 0) )
			{
				//if(OrdenarNombre(nombreStr , strlen(nombreStr)) == 0)
				//{
					id = atoi(idStr);
					horasTrabajadas = atoi(horasTrabajadasStr);
					sueldo = atoi(sueldoSrt);
					strcpy(nombre , nombreStr);

					employee_setId( empleadoAux , id);
					employee_setNombre( empleadoAux , nombre);
					employee_setHorasTrabajadas(empleadoAux , horasTrabajadas);
					employee_setSueldo(empleadoAux , sueldo);

				//}

			}
		}
	}

	return empleadoAux;

}

//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Carga empleado por fuera del archivo, ingresa los datos el usuario
 *
 * \param int* idAnterior
 * \return int 0 si sale todo ok, -1 //FALLO LA CARGA DE ALGUN CAMPO
 *
 */

Employee* cargarEmpladoPorTeclado(int* idAnterior)
{

	Employee* aux;
	int idAux;
	char nombreAux[MAXNOMBRE];
	int horasAux;
	int sueldoAux;
	int sePuede;


	if(idAnterior != NULL)
	{
		sePuede = 0;

		if(Get_nombre("Ingrese el nombre del empleado.." , "Error, el nombre no puede ser tan largo.." , nombreAux , sizeof(nombreAux)) == 0)
		{
			if(OrdenarNombre(nombreAux , sizeof(nombreAux)) != 0)
			{
				sePuede = -1; //FALLO LA CARGA DE ALGUN CAMPO
			}
		}

		idAux = *idAnterior + 1;

		*idAnterior = idAux;

		if(Get_numeroConLimites("Ingrese las horas trabajadas por el empleado.." , "Error, solo se admiten numeros.." , 0 , INT_MAX , &horasAux) != 0)
		{
			sePuede = -1; //FALLO LA CARGA DE ALGUN CAMPO
		}

		if(Get_numeroConLimites("Ingrese el sueldo del empleado.." , "Error, solo se admiten numeros.." , 0 , INT_MAX , &sueldoAux) != 0)
		{
			sePuede = -1; //FALLO LA CARGA DE ALGUN CAMPO
		}

		if(sePuede == 0)
		{
			aux = employee_new();

			if(aux != NULL)
			{
				//printf("Guardo bien..\n");
				employee_setId(aux , idAux);
				employee_setNombre( aux , nombreAux);
				employee_setHorasTrabajadas(aux , horasAux);
				employee_setSueldo(aux , sueldoAux);
			}
			else
			{
				printf("No anda bien..\n");
			}
		}
		else
		{
			printf("No se pudo wey..\n");
		}

	}

	return aux;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Elimina un empleado de la linkedList
 *
 * \param Employee* empleado
 * \return int 0 si sale todo ok, -1 //FALLO Nulls
 *
 */

int employee_delete(Employee* empleado)
{
	int ret;

	ret = -1;

	if(empleado != NULL)
	{
		free(empleado);
		//printf("Borro bien..");
		ret = 0;
	}

	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------



//****************************************************SETTERS**************************************************************

//ID:

/** \brief Carga id en el campo id de un empleado
 *
 * \param Employee* this
 * * \param int id
 * \return int 0 si sale todo ok, -1 //FALLO Nulls
 *
 */

int employee_setId(Employee* this , int id)
{
	int ret;

	ret = -1; //si fallan nulls

	if(this != NULL)
	{
		this->id = id;

		ret = 0;
	}

	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

//NOMBRE:

/** \brief Carga nombre en el campo nombre de un empleado
 *
 * \param Employee* this
 * * \param char* nombre
 * \return int 0 si sale todo ok, -1 //FALLO Nulls , -2; //es muy largo el nombre
 *
 */

int employee_setNombre(Employee* this , char* nombre)
{
	int ret;
	int largo;

	ret = -1;

	if(this != NULL && nombre != NULL)
	{
		ret = -2;

		largo = strlen(nombre);

		if(largo < sizeof(this->nombre))
		{
			strcpy(this->nombre , nombre);
			ret = 0;
		}
	}

	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

//HORAS TRABAJADAS:

/** \brief Carga cantidad horas trabajadas en el campo horasTrabajadas de un empleado
 *
 * \param Employee* this
 * * \param int horasTrabajadas
 * \return int 0 si sale todo ok, -1 //FALLO Nulls
 *
 */

int employee_setHorasTrabajadas(Employee* this , int horasTrabajadas)
{
	int ret;

	ret = -1;

	if(this != NULL && horasTrabajadas > -1)
	{
		this->horasTrabajadas = horasTrabajadas;

		ret = 0;
	}

	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

//SUELDO:

/** \brief Carga sueldo en el campo sueldo de un empleado
 *
 * \param Employee* this
 * * \param int sueldo
 * \return int 0 si sale todo ok, -1 //FALLO Nulls
 *
 */

int employee_setSueldo(Employee* this , int sueldo)
{
	int ret;

	ret = -1; //si fallan nulls

	if(this != NULL && sueldo > -1)
	{
		this->sueldo = sueldo;

		ret = 0;
	}

	return ret;
}


//-----------------------------------------------------------------------------------------------------------------------------------------------



//*******************************************************GETTERS*********************************************************************************:


//ID:

/** \brief Devuelve el id de un empleado
 *
 * \param Employee* this
 * * \param int* id
 * \return int 0 si sale todo ok, -1 //FALLO Nulls
 *
 */

int employee_getId(Employee* this , int* id)
{
	int ret;

	ret = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		ret = 0;
	}

	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

//NOMBRE:

/** \brief Devuelve el nombre de un empleado
 *
 * \param Employee* this
 * * \param char* nombre
 * \return int 0 si sale todo ok, -1 //FALLO Nulls
 *
 */

int employee_getNombre(Employee* this,char* nombre)
{
	int ret;

	ret = -1;

	if(this != NULL && nombre != NULL)
	{
		ret = 0;

		strcpy(nombre , this->nombre);

	}

	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

//HORAS TRABAJADAS:

/** \brief Devuelve la cantidad de horas trabajadas de un empleado
 *
 * \param Employee* this
 * * \param int* horasTrabajadas
 * \return int 0 si sale todo ok, -1 //FALLO Nulls
 *
 */

int employee_getHorasTrabajadas(Employee* this , int* horasTrabajadas)
{
	int ret;

	ret = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		ret = 0;
	}

	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

//SUELDO:

/** \brief Devuelve el sueldo de un empleado
 *
 * \param Employee* this
 * * \param int* sueldo
 * \return int 0 si sale todo ok, -1 //FALLO Nulls
 *
 */

int employee_getSueldo(Employee* this , int* sueldo)
{
	int ret;

	ret = -1;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		ret = 0;
	}

	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Imprime un empleado
 *
 * \param Employee* empleado
 * \return int 0 si sale todo ok, -1 //FALLO Nulls
 *
 */

int imprimirUnEmpleado(Employee* empleado)
{
	int ret;
	int id;
	int horasTrabajadas;
	int sueldo;
	char nombre[MAXSTRING];

	ret = -1;

	if(empleado != NULL)
	{
		if( (employee_getId(empleado , &id) == 0 ) &&
			(employee_getHorasTrabajadas(empleado , &horasTrabajadas) == 0 ) &&
			(employee_getSueldo(empleado, &sueldo) == 0 ) &&
			(employee_getNombre(empleado, nombre) == 0 ) )
		{
			ret = 0;
			printf("|   %-10d %-20s %-10d %-10d             |\n",id , nombre , horasTrabajadas , sueldo);
		}

	}

	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Modifica campo seleccionado de un empleado
 *
 * \param LinkedList* listaEmpleados
 * \return int 0 si sale todo ok, -1 //FALLO Nulls , -2; //Cancelo la operacion. ,-3; //la lista esta vacia
 *
 */

int modificarEmpleado(LinkedList* listaEmpleados)
{
	int ret;
	int index;
	int campo;
	int respuestaCampo;


	Employee* aux;

	ret = -1;

	if(listaEmpleados != NULL)
	{
		if(imprimirEmpleados(listaEmpleados) == 0)
		{
			do
			{
				Get_numeroConLimites("Ingrese el id del empleado a modificar..","Error el maximo numero admitido es: 2,147,483,647",INT_MIN , INT_MAX , &index);

				aux = findEmployee(listaEmpleados , index);

				if(aux != NULL)
				{
					Get_numeroConLimites("Ingrese el campo del empleado a modificar: \n1.Nombre\n2.Horas trabajadas\n3.Sueldo","Error, ingrese un campo entre los dados..",1,3,&campo);

					respuestaCampo = modificarCampo(aux , campo);
					switch(respuestaCampo)
					{
						case 0:
							ret = 0;
						break;
						case -2:
							ret = -2;
						break;
					}

					break;
				}


				if(QueresSeguir("El id ingresado no se encontro en la lista, desea volver a intentar? s/n") != 0)
				{
					ret = -2;
					break;
				}

			}while(1);
		}
		else
		{
			ret = -3; //la lista esta vacia
		}
	}

	return ret;
}



//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Imprime lista de empleados
 *
 * \param LinkedList* listaEmpleados
 * \return int 0 si sale todo ok, -1 //FALLO Nulls , -2 no se pudo imprimir el empleado -3; //la lista esta vacia--
 *
 */

int imprimirEmpleados(LinkedList* listaEmpleados)
{
	int ret;
	int i;
	int largo;
	Employee* aux;

	ret = -1;

	if(listaEmpleados != NULL)
	{
		ret = 0;

		largo = ll_len(listaEmpleados);

		if(largo > 0)
		{
			ret = 0;

			printf("|---------------------------------------------------------------------|\n");
			printf("|   ID         NOMBRE               H/T        SUELDO		      |\n");
			printf("|---------------------------------------------------------------------|\n");

			for(i=0 ; i<largo ; i++)
			{
				aux = (Employee*) ll_get(listaEmpleados , i);

				if(imprimirUnEmpleado(aux) != 0)
				{
					ret = -2;
					break;
				}
			}

			printf("|---------------------------------------------------------------------|\n");
		}
		else
		{
			ret = -3; //la lista esta vacia--
		}
	}

	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Modifica campo de un empleado seleccionado por el usuario
 *
 * \param Employee* this
 *  param int campoAactualizar
 * \return int 0 si sale todo ok, -1 //FALLO Nulls , -2 cancelo la operacion
 *
 */

int modificarCampo(Employee* this , int campoAactualizar)
{
	int ret;
	char nombreAux[MAXNOMBRE];
	int sueldoAux;
	int horasAux;

	ret = -1;

	if(this != NULL && campoAactualizar > 0 && campoAactualizar < 4)
	{
		ret = -2;

		switch(campoAactualizar)
		{
			case 1:

				Get_nombre("Ingrese el nombre del empleado.." , "Error, el nombre no puede ser tan largo.." , nombreAux , sizeof(nombreAux));

				OrdenarNombre(nombreAux , sizeof(nombreAux));

				if(QueresSeguir("Seguro que queres modificar el nombre del empleado? s/n") == 0)
				{
					if(employee_setNombre(this , nombreAux ) == 0)
					{
						ret = 0;
					}
				}

			break;

			case 2:

				Get_numeroConLimites("Ingrese las horas trabajadas por el empleado.." , "Error, la cantidad de horas no puede ser tan grande.." , 0 , INT_MAX , &horasAux);

				if(QueresSeguir("Seguro que queres modificar las horas trabajadas del empleado? s/n") == 0)
				{
					if(employee_setHorasTrabajadas(this , horasAux ) == 0)
					{
						ret = 0;
					}
				}

			break;

			case 3:

				Get_numeroConLimites("Ingrese el sueldo del empleado.." , "Error, el sueldo no puede ser tan grande.." , 0 , INT_MAX , &sueldoAux);

				if(QueresSeguir("Seguro que queres modificar el sueldo del empleado? s/n") == 0)
				{
					if(employee_setSueldo(this , sueldoAux ) == 0)
					{
						ret = 0;
					}
				}

			break;
		}
	}

	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Busca un empleado por id y retorna el puntero a ese empleado
 *
 * \param LinkedList* listaEmpleados
 *  param int idAencontrar
 * \return Employee*
 *
 */

Employee* findEmployee(LinkedList* listaEmpleados , int idAencontrar)
{
	Employee* indexAux;
	Employee* aux;
	int i;
	int largo;
	int idAcomparar;

	if(listaEmpleados != NULL)
	{
		indexAux = NULL;

		largo = ll_len(listaEmpleados);

		for(i=0 ; i<largo ; i++)
		{
			aux = ll_get(listaEmpleados , i);

			if(aux != NULL)
			{
				employee_getId(aux , &idAcomparar);

				if(idAcomparar == idAencontrar)
				{
					indexAux = aux;
					break;
				}
			}
		}
	}

	return indexAux;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Elimina un empleado de la lista
 *
 * \param LinkedList* listaEmpleados
 * \return int 0 si sale todo ok, -1 //FALLO Nulls , -2 cancelo la operacion , -3; //la lista esta vacia
 *
 */

int eliminarEmpleado(LinkedList* listaEmpleados)
{
	Employee* aux;
	int indexAborrar;
	int index;
	int ret;

	ret = -1;

	if(listaEmpleados != NULL)
	{
		if(imprimirEmpleados(listaEmpleados) == 0)
		{
			ret = -2;

			do
			{
				Get_numeroConLimites("Ingrese el id del empleado a eliminar..","Error el maximo numero admitido es: 2,147,483,647",INT_MIN , INT_MAX , &indexAborrar);

				aux = findEmployee(listaEmpleados , indexAborrar);

				if(aux != NULL)
				{
					index = ll_indexOf(listaEmpleados , aux);

					if(QueresSeguir("Esta seguro de eliminar al empleado de la lista? s/n") == 0)
					{

						ll_remove(listaEmpleados , index);
						employee_delete(aux);

						ret = 0;
						break;
					}
				}


				if(QueresSeguir("El id ingresado no se encontro en la lista, desea volver a intentar? s/n") != 0)
				{
					break;
				}

			}while(1);
		}
		else
		{
			ret = -3; //la lista esta vacia
		}
	}

	return ret;
}


//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Ordena lista de empleados ascendente o descendentemente segun el campo seleccionado
 *
 * \param LinkedList* listaEmpleados
 * \return int 0 si sale todo ok, -1 //FALLO Nulls -2; //la lista ta vacia
 *
 */

int ordenarEmpleados(LinkedList* listaEmpleados)
{
	int ret;
	int respuesta;
	int orden;
	int largo;

	ret = -1;

	if(listaEmpleados != NULL)
	{
		largo = ll_len(listaEmpleados);

		if(largo > 0)
		{
			Get_numeroConLimites("Por que campo desea ordenar? \n1-Nombre\n2-IDs\n3-Horas Trabajadas\n4-Sueldo","Error, ingrese una opcion entre las dadas..",1,4,&respuesta);

			Get_numeroConLimites("Ingrese 1 para ordenar de manera ascendente o 0 para ordenar de manera descendente..","Error, ingrese una opcion entre las dadas..",0,1,&orden);

			switch(respuesta)
			{
				case 1:

					//printf("Entre\n");
					ll_sort(listaEmpleados, compararEmpleadosPorNombre, orden);
					ret = 0;

				break;

				case 2:

					ll_sort(listaEmpleados, compararEmpleadosPorId, orden);

					ret = 0;

				break;

				case 3:

					ll_sort(listaEmpleados, compararEmpleadosPorHorasTrabajadas, orden);

					ret = 0;

				break;

				case 4:

					ll_sort(listaEmpleados, compararEmpleadosPorSueldo, orden);

					ret = 0;

				break;
			}
		}
		else
		{
			ret = -2; //la lista ta vacia
		}
	}


	return ret;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief Compara dos empleados por nombre
 *
 * \param void* primerElemento
 *  param void* segundoElemento
 * \return int 0 si son iguales, -1 el primero es mayor , 1 el segundo es mayor
 *
 */

int compararEmpleadosPorNombre(void* primerElemento , void* segundoElemento)
{
	int ret;
	Employee* empleadoUno;
	Employee* empleadoDos;
	char nombreUno[MAXNOMBRE];
	char nombreDos[MAXNOMBRE];

	ret = -1;

	if(primerElemento != NULL && segundoElemento != NULL)
	{

		empleadoUno = (Employee*) primerElemento;
		empleadoDos = (Employee*) segundoElemento;

		employee_getNombre(empleadoUno , nombreUno);
		employee_getNombre(empleadoDos , nombreDos);

		//puts(nombreUno);
		//puts(nombreDos);

		ret = strcmp(nombreUno , nombreDos);

	}

	return ret;

}

//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief compara dos empleados por el campo id
 *
 * \param void* primerElemento
 * \param void* segundoElemento
 * \return int 0 si son iguales, -1 mayor a menor  , 1 Menor a mayor
 *
 */

int compararEmpleadosPorId(void* primerElemento , void* segundoElemento)
{
	int ret;
	Employee* empleadoUno;
	Employee* empleadoDos;
	int numeroUno;
	int numeroDos;

	if(primerElemento != NULL && segundoElemento != NULL)
	{
		ret = 0; //Si son iguales

		empleadoUno = (Employee*) primerElemento;
		empleadoDos = (Employee*) segundoElemento;

		employee_getId(empleadoUno , &numeroUno);
		employee_getId(empleadoDos , &numeroDos);

		if(numeroUno > numeroDos)
		{
			ret = 1; //Menor a mayor
		}
		else
		{
			if(numeroUno < numeroDos)
			{
				ret = -1; //Mayor a menor
			}
		}
	}

	return ret;

}

//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief compara dos empleados por el campo horas trabajadas
 *
 * \param void* primerElemento
 * \param void* segundoElemento
 * \return int 0 si son iguales, -1 //Mayor a menor , 1 Menor a mayor
 *
 */

int compararEmpleadosPorHorasTrabajadas(void* primerElemento , void* segundoElemento)
{
	int ret;
	Employee* empleadoUno;
	Employee* empleadoDos;
	int horasEmpleadoUno;
	int horasEmpleadoDos;

	if(primerElemento != NULL && segundoElemento != NULL)
	{
		ret = 0; //Si son iguales

		empleadoUno = (Employee*) primerElemento;
		empleadoDos = (Employee*) segundoElemento;

		employee_getHorasTrabajadas(empleadoUno , &horasEmpleadoUno);
		employee_getHorasTrabajadas(empleadoDos , &horasEmpleadoDos);

		if(horasEmpleadoUno > horasEmpleadoDos)
		{
			ret = 1; //Menor a mayor
		}
		else
		{
			if(horasEmpleadoUno < horasEmpleadoDos)
			{
				ret = -1; //Mayor a menor
			}
		}
	}

	return ret;

}

//-----------------------------------------------------------------------------------------------------------------------------------------------

/** \brief compara dos empleados por el campo sueldo
 *
 * \param void* primerElemento
 * \param void* segundoElemento
 * \return int 0 si son iguales, -1 //Mayor a menor , 1 Menor a mayor
 *
 */

int compararEmpleadosPorSueldo(void* primerElemento , void* segundoElemento)
{
	int ret;
	Employee* empleadoUno;
	Employee* empleadoDos;
	int sueldoEmpleadoUno;
	int sueldoEmpleadoDos;

	if(primerElemento != NULL && segundoElemento != NULL)
	{
		ret = 0; //Si son iguales

		empleadoUno = (Employee*) primerElemento;
		empleadoDos = (Employee*) segundoElemento;

		employee_getSueldo(empleadoUno , &sueldoEmpleadoUno);
		employee_getSueldo(empleadoDos , &sueldoEmpleadoDos);

		if(sueldoEmpleadoUno > sueldoEmpleadoDos)
		{
			ret = 1; //Menor a mayor
		}
		else
		{
			if(sueldoEmpleadoUno < sueldoEmpleadoDos)
			{
				ret = -1; //Mayor a menor
			}
		}
	}

	return ret;

}
