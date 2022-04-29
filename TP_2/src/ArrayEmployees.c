
#include <stdio.h>
#include <string.h>


 #include "ArrayEmployees.h"

//--------------------------------------------------------------------------------------------------------------------
int initEmployees(Employee list[] , int range)
{
    int ret;
    int i;

    ret = -1;

    if(list != NULL && range > 0)
    {
        ret = 0;

        for(i=0 ; i<range ; i++)
        {
            list[i].isEmpty = 1;
        }
    }

    return ret;
}
//--------------------------------------------------------------------------------------------------------------------
int addEmployee(Employee list[], int range , int id , char name[] , char lastName[] , float salary , int sector)
{
    int ret;
    int i;
    Employee aux;

    ret = -1; //ALGO FALLO VUELVA A INTENTAR

    if(list != NULL && name != NULL && lastName != NULL && range > 0)
    {
        aux.id = id;
        strcpy(aux.name , name);
        strcpy(aux.lastName , lastName);
        aux.salary = salary;
        aux.sector = sector;
        aux.isEmpty = 0;

        for(i=0 ; i<range ; i++)
        {
            if(list[i].isEmpty == 1)
            {
                list[i] = aux;
                printf("\n---Si se equivoco en el ingreso de algun dato, podra modificarlo luego en la opcion 2 del menu..\n");
                ret = 0; //SE CARGO BIEN
                break;
            }
            else
            {
                ret = -2; //NO HABIA LUGAR EN EL ARRAY
            }
        }
    }

    return ret;
}

//--------------------------------------------------------------------------------------------------------------------
int loadEmployee(Employee list[] , int range, int idViejo , int* idNuevo)
{
    Employee auxiliar;
    int addEmployeeRespuesta;
    int sePuede;
    int idContador;

    sePuede = 0;
    addEmployeeRespuesta = -2;

    if(Get_NombreOapellido("Ingrese el nombre del empleado.." , "El nombre no puede ser tan largo.." , auxiliar.name , sizeof(auxiliar.name)) != 0)
    {
        printf("No se pudo cargar el nombre reintente..\n");
    }

    if(Get_NombreOapellido("Ingrese el apellido del empleado.." , "El apellido no puede ser tan largo.." , auxiliar.lastName , sizeof(auxiliar.lastName)) != 0)
    {
        printf("No se pudo cargar el apellido reintente..\n");
    }

    if(Get_floatConLimites("Ingrese el sueldo del empleado..","Error el sueldo no puede estar compuesto por letras ni mas de 1 punto...",INT_MIN,INT_MAX, &auxiliar.salary) != 0)
    {
        printf("No se pudo cargar el sueldo... reintente\n");
    }

    if(Get_numeroConLimites("Ingrese el sector en el que trabaja el empleado.. 1 , 2 , 3", "Error reingrese..",1,3,&auxiliar.sector) != 0)
    {
        printf("Algo salio mal vuelva a intentar...");
    }

    for(int i=0 ; i<range ; i++)
    {
        if(list[i].isEmpty == 1)
        {
            sePuede = 1;
            idViejo = incrementId(idViejo); //ASI RECIBE 2 PARAMETROS, EL ID VIEJO QUE INICIA EN CERO Y LA DIRECCION DE MEMORIA DEL NUEVO QUE
            auxiliar.id = idViejo;              //SE REEMPLAZA POR EL VALOR YA INCREMENTADO, DESPUES EN EL MAIN LE ASIGNO AL A ID VIEJA EL VALOR
            *idNuevo = idViejo;                 //DEL ID NUEVO , ASI SIEMPRE SE VA ACTUALIZANDO
            break;
        }
    }

    if(sePuede == 1)
    {
        addEmployeeRespuesta = addEmployee(list , range , auxiliar.id , auxiliar.name , auxiliar.lastName , auxiliar.salary , auxiliar.sector);
    }

    return addEmployeeRespuesta;

}

//--------------------------------------------------------------------------------------------------------------------
int incrementId(int id)
{
    int ret;

    ret = id + 1;

    return ret;
}

//--------------------------------------------------------------------------------------------------------------------
int DeployMenu(int* respuesta)
{
    int aux;
    int ret;

    ret = -1;

    if(respuesta != NULL)
    {
        printf("\n\n|------------------------MENU----------------------------|\n");
        printf("|   1. ALTA EMPLEADO                                     |\n");
        printf("|   2. MODIFICAR EMPLEADO                                |\n");
        printf("|   3. BAJA EMPLEADO                                     |\n");
        printf("|   4. INFORMAR:                                         |\n");
        printf("|   5. MOSTRAR EMPLEADOS CARGADOS                        |\n");
        printf("|   6. SALIR                                             |\n");
        printf("|--------------------------------------------------------|\n\n");
        if(Get_numeroConLimites("SELECCIONE UNA OPCION..", "ERROR, INGRESE UNA OPCION ENTRE LAS MOSTRADAS..",1,6,&aux) == 0)
        {
            ret = 0;
            *respuesta = aux;
        }
    }

    return ret;
}

//--------------------------------------------------------------------------------------------------------------------
int findEmployeeById(Employee list[], int range,int idToFind)
{
    int ret;
    int i;

    ret = -1;

    if(list != NULL && range > 0 && idToFind > 0)
    {
        for(i=0 ; i<range ; i++)
        {
            if(list[i].id == idToFind)
            {
                if(list[i].isEmpty == 0)
                {
                    ret = i;
                }
            }
        }
    }

    return ret;
}

//--------------------------------------------------------------------------------------------------------------------
int removeEmployee(Employee list[], int range,int idEmployeeToRemove)
{
    int ret;
    int iPositionToDelate;

    ret = -1; //--No entro al primer if

    if(list != NULL && range > 0)
    {
        iPositionToDelate = findEmployeeById(list , range , idEmployeeToRemove);

        if(iPositionToDelate != -1)
        {
            if(QueresSeguir("Esta seguro que desea eliminar este empleado? s/n") == 0)
            {
                list[iPositionToDelate].isEmpty = 1;
                ret = 0; // se dio de baja con exito
            }
            else
            {
                ret = -2; //cancelo la operacion
            }
        }
        else
        {
            ret = -3; // no se encontro ese id...
        }
    }

    return ret;
}


//--------------------------------------------------------------------------------------------------------------------
int get_idToDelate(Employee list[] , int range , int* idToDelate , char men[] , char menE[])
{
    int ret;
    int aux;

    ret = -1;

    if(idToDelate != NULL)
    {
        if(printEmployees(list, range) != 0)
        {
            printf("Algo salio mal..\n");
        }

        if(Get_numeroConLimites(men , menE, 0 ,INT_MAX , &aux) == 0)
        {
            *idToDelate = aux;
            ret = 0;
        }
    }

    return ret;
}
//--------------------------------------------------------------------------------------------------------------------
int printEmployees(Employee list[], int range)
{
    int ret;
    int i;

    ret = -1;

    if(list != NULL && range > 0)
    {
        ret = 0;
        printf("\n\n|----------------------------------------------------------------------------------------------------------------|\n");
        printf("|    ID                            NOMBRE                           APELLIDO              SALARIO       SECTOR   |\n");
        printf("|----------------------------------------------------------------------------------------------------------------|\n");
        for(i=0 ; i<range ; i++)
        {
            if(list[i].isEmpty == 0)
            {
                ret = 0;
                printf("| %7d    %30s     %30s    %16.2f    %6d     |\n",list[i].id ,list[i].name ,list[i].lastName,
                                                                                list[i].salary , list[i].sector);
            }
        }
        printf("|----------------------------------------------------------------------------------------------------------------|\n\n\n");
    }

    return ret;
}

//--------------------------------------------------------------------------------------------------------------------
int isEmpty(Employee list[] , int range)
{
    int i;
    int ret;

    ret = -1;

    if(list != NULL && range > 0)
    {
        for(i=0 ; i<range ; i++)
        {
            if(list[i].isEmpty == 0)
            {
                ret = 0;
                break;
            }
        }
    }

    return ret;
}

//--------------------------------------------------------------------------------------------------------------------
int sortEmployees(Employee list[], int range, int order)
{
    int i;
    int j;
    int ret;
    int comp;
    Employee aux;
    int auxSector;

    ret = -1;

    if(list != NULL && range > 0)
    {
        for(i=0 ; i<range-1 ; i++)
        {
            for(j=i+1 ; j<range ; j++)
            {
                if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    //ret = 0;
                    if(order == 1) // aca ingresa si elige de menor a mayor
                    {   comp = strcmp(list[i].lastName , list[j].lastName); //ordeno de menor a mayor
                        if(comp > 0)
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                            ret = 0;
                        }
                        else
                        {
                            if(comp == 0)
                            {
                                if(list[i].sector > list[j].sector) //ordeno de menor a mayor si se repite algun apellido
                                {
                                    aux = list[i];
                                    list[i] = list[j];
                                    list[j] = aux;
                                    ret = 0;
                                }
                            }
                        }
                    }
                    else // aca ingresa si elige de mayor a menor
                    {
                        comp = strcmp(list[i].lastName , list[j].lastName);
                        if(comp < 0) //ordeno de mayor a menor
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                            ret = 0;
                        }
                        else
                        {
                            if(comp == 0)
                            {
                                if(list[i].sector > list[j].sector) //ordeno de mayor a menor si se repite algun apellido
                                {
                                    aux = list[i];
                                    list[i] = list[j];
                                    list[j] = aux;
                                    ret = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
        return ret;
}

//--------------------------------------------------------------------------------------------------------------------
int ModifyEmployee(Employee list[] , int range, char mens[] , char mensE[])
{
    int ret;
    int i;
    int aux;
    int result;
    int fieldToModify;

    //------------------
    char auxName[TAMNAME];
    char auxLastName[TAMLASTNAME];
    float auxSalary;
    int auxSector;


    ret = -1;


    if(list != NULL && mens != NULL && mensE != NULL && range > 0)
    {
        if(get_idToDelate(list , range , &aux , mens , mensE ) == 0)
        {
            result = findEmployeeById(list , range , aux);

            if(result != -1)
            {
                fieldToModify = whatField("Ingrese el sector a modificar: 1- Nombre , 2- Apellido , 3- Salario , 4- Sector , 5-Cancelar operacion" ,
                                            "Error, ingrese una opcion valida..", 1 , 5);

                if(fieldToModify != -1 && fieldToModify != 5)
                {
                    if(QueresSeguir("Seguro que queres seguir? s/n") == 0)
                    {
                        switch(fieldToModify)
                        {
                            case 1:

                                if(Get_NombreOapellido("Ingrese el nombre de el empleado.." , "El nombre no puede ser tan largo.." , auxName , sizeof(auxName))== 0)
                                {
                                    if(OrdenarNombreApellidoMayusculas(auxName , sizeof(auxName)) == 0)
                                    {
                                        strcpy(list[result].name , auxName); //result por que ahi guarde la posicion que consegui con la funcion findEmployeeById

                                        ret = 0;
                                    }
                                }

                            break;
                            case 2:

                                if(Get_NombreOapellido("Ingrese el apellido de el empleado.." , "El apellido no puede ser tan largo.." , auxLastName , sizeof(auxLastName))== 0)
                                {
                                    if(OrdenarNombreApellidoMayusculas(auxLastName , sizeof(auxLastName)) == 0)
                                    {
                                        strcpy(list[result].lastName , auxLastName);

                                        ret = 1;
                                    }
                                }

                            break;
                            case 3:

                                if(Get_floatConLimites("Ingrese el sueldo del empleado..","Error el sueldo no puede ser menor a cero ni mayor a 2000000...",0,2000000, &auxSalary) == 0)
                                {
                                    list[result].salary = auxSalary;

                                    ret = 2;
                                }

                            break;
                            case 4:

                                if(Get_numeroConLimites("Ingrese el sector en el que trabaja el empleado.. 1 , 2 , 3", "Error reingrese..",1,3,&auxSector) == 0)
                                {
                                    list[result].sector = auxSector;

                                    ret = 3;
                                }

                            break;
                        }
                    }
                    else
                    {
                        ret = -2; //cancelo operacion
                    }
                }
                else
                {
                    if(fieldToModify == 5)
                    {
                        ret = -2; // //cancelo la operacion desde la funcion whatField al seleccionar el campo a modificar..
                    }
                }

            }
            else
            {
                ret = -3; // no se encontro ese id...
            }
        }
    }

    return ret;
}

//--------------------------------------------------------------------------------------------------------------------
int whatField(char mens[] , char mensE[] , int min , int max)
{
    int ret;
    int aux;

    ret = -1;

    if(Get_numeroConLimites(mens , mensE , min , max , &aux) == 0)
    {
        ret = aux;
    }

    return ret;

}
//--------------------------------------------------------------------------------------------------------------------
int organizeEmployees(Employee list[] , int range , char mens[] , char mensE[] , int min , int max)
{
    int ret;
    int respuestaSortEmployee;

    ret = -1;

    if(list != NULL && mens != NULL && mensE != NULL && range > 0)
    {
        if(Get_numeroConLimites(mens , mensE , min , max , &respuestaSortEmployee) == 0)
        {
            if(sortEmployees(list , range , respuestaSortEmployee) == 0)
            {
                ret = 0;
            }
        }
    }


    return ret;
}

//--------------------------------------------------------------------------------------------------------------------
int get_acumuladoSueldos(Employee list[], int range , float* acumulado)
{
    int i;
    float aux;
    int ret;
    int flag;

    ret = -1;
    flag = 1;

    if(list != NULL && range > 0 && acumulado != NULL)
    {
        aux = 0;

        for(i=0 ; i<range ; i++)
        {
            if(list[i].isEmpty == 0)
            {
                flag = 0;
                aux += list[i].salary;
            }
        }
    }

    if(flag == 0)
    {
        ret = 0;
        *acumulado = aux;
    }

    return ret;
}

//--------------------------------------------------------------------------------------------------------------------
int contadorEmpleados(Employee list[], int range , int* acumulado)
{
    int ret;
    int contadorAux;
    int i;

    contadorAux = 0;

    ret = -1;

    if(list != NULL && range > 0 && acumulado != NULL)
    {
        for(i=0 ; i<range ; i++)
        {
            if(list[i].isEmpty == 0)
            {
                contadorAux++;
            }
        }

        if(contadorAux > 0)
        {
            *acumulado = contadorAux;
            ret = 0;
        }
    }

    return ret;

}

//--------------------------------------------------------------------------------------------------------------------
int contadorEmpleadosSuperanPromedio(Employee list[] , int range , float sueldoPromedio)
{
    int i;
    int contador;

    contador = -1;

    if(list != NULL && range > 0 && sueldoPromedio > 0)
    {
        contador = 0;

        for(i=0 ; i<range ; i++)
        {
            if(list[i].isEmpty == 0 && list[i].salary > sueldoPromedio)
            {
                contador++;  //si entra aca ya devuelve al menos 1 empleado que supera el sueldo..
            }
        }
    }

    return contador;
}

//--------------------------------------------------------------------------------------------------------------------
void SalarysStatus(Employee list[] , int range)
{
    float acumulador;
    int cantidadDeEmpleadosCargados;
    int ret;
    float promedioSueldos;
    int cantidadEmpleSuperanPromedio;

    ret = -1;


    if(list != NULL && range > 0)
    {
        if(contadorEmpleados(list , range , &cantidadDeEmpleadosCargados) == 0)
        {
            if(get_acumuladoSueldos(list , range , &acumulador) != 0)
            {
                printf("Hubo problemas para calcular el promedio reintente..\n");
            }
            else
            {
                if(get_promedio(acumulador , cantidadDeEmpleadosCargados , &promedioSueldos) == 0)
                {
                    cantidadEmpleSuperanPromedio = contadorEmpleadosSuperanPromedio(list, range , promedioSueldos);
                    if(cantidadEmpleSuperanPromedio > 0)
                    {
                        printf("El promedio de sueldo de los empleados cargados es: $%.2f \nLa cantidad de empleados que superan el el sueldo promedio es de: %d empleado/s\n", promedioSueldos , cantidadEmpleSuperanPromedio);
                    }
                    else
                    {
                        if(cantidadEmpleSuperanPromedio == 0)
                        {
                            printf("Por el momento ninguno de los empleados cargados superan el promedio..\n");
                        }
                        else
                        {
                            printf("Hubo problemas para calcular el promedio reintente..\n");
                        }
                    }

                }
                else
                {
                    printf("Hubo problemas para calcular el promedio reintente..\n");
                }
                //printf("El acumulador dio: %.2f\n",acumulador);
            }
        }
        else
        {
            printf("Hubo problemas para calcular el promedio reintente..\n");
        }

    }
}
