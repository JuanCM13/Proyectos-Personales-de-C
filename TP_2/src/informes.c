


#include "informes.h"

//--------------------------------------------------------------------------------------------------------------------

void informeAlta(Employee list[] , int range , int idAnterior, int* idActual)
{
    int respuestaLoadEmployee;
    int aux;

        respuestaLoadEmployee = loadEmployee(list , range , idAnterior , &aux);

        switch(respuestaLoadEmployee)
        {
            case 0:
                *idActual = aux;
                printf("EL EMPLEADO FUE CARGADO CORRECTAMENTE..\n");
            break;
            case -1:
                printf("Algo inesperado sucedio con la carga, vuelva a intentarlo..\n");
            break;
            case -2:
                printf("La lista de trabajadores esta llena, de de baja un empleado para poder cargar otro..\n");
            break;
        }

}


//--------------------------------------------------------------------------------------------------------------------

void informeMod(Employee list[] , int range)
{
    int respuestaModifyEmployee;

    if(isEmpty(list , range) == 0)
    {
        respuestaModifyEmployee = ModifyEmployee(list , range , "Ingrese el id del empleado a modificar.." , "Error, el id debe ser mayor a cero..");

        switch(respuestaModifyEmployee)
        {
            case -3:
                printf("El id ingresado no existe.. vuelva a intentarlo\n");
            break;
            case -2:
                printf("Usted cancelo la operacion.. volvimos al menu\n");
            break;
            case -1:
                printf("Un error inesperado surgio en la modificacion del empleado, reintente..\n");
            break;
            case 0:
                printf("El nombre del empleado fue actualizado con exito!!\n");
            break;
            case 1:
                printf("El apellido del empleado fue actualizado con exito!!\n");
            break;
            case 2:
                printf("El sueldo del empleado fue actualizado con exito!!\n");
            break;
            case 3:
                printf("El sector donde trabaja el empleado fue actualizado con exito!!\n");
            break;
        }
    }
    else
    {
        printf("El listado se encuentra vacio, debe haber almenos un empleado cargado para entrar a este campo..\n");
    }

}

//--------------------------------------------------------------------------------------------------------------------

void informeBaja(Employee list[] , int range)
{
    int idAborrar;
    int respuestaRemoveId;

    if(isEmpty(list , range) == 0)
    {
        if(get_idToDelate(list , range , &idAborrar , "Ingrese el id a borrar...","Algo salio mal reintente..") == 0)
        {
            respuestaRemoveId = removeEmployee(list , range , idAborrar);

            switch(respuestaRemoveId)
            {
                case 0:
                    printf("El empleado fue dado de baja de manera exitosa..\n");
                break;
                case -1:
                    printf("Ocurrio un error inesperado, intente de nuevo..\n");
                break;
                case -2:
                    printf("La operacion se cancelo, volvimos al menu..\n");
                break;
                case -3:
                    printf("El id ingresado no existe, vuelva a intentarlo..\n");
                break;
            }

        }
    }
    else
    {
        printf("El listado se encuentra vacio, debe haber almenos un empleado cargado para entrar a este campo..\n");
    }


}

//--------------------------------------------------------------------------------------------------------------------

void informeResultadosOrdenamientoYpromedios(Employee list[] , int range)
{

    int respuestaResults;

    if(isEmpty(list , range) == 0)
    {
        printf("1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
        printf("2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio\n\n");

       if(Get_numeroConLimites("Ingrese 1 o 2 para mostrar" , "Error, ingrese solo 1 o 2..",1,2,&respuestaResults) == 0)
       {
            if(respuestaResults == 1)
            {
                //ORDENAMIENTO
               if(organizeEmployees(list , range , "Para ordenar de manera ascendente ingrese 1 , y de manera descendente 0..",
                                                    "Error, ingrese una opcion en le area marcada..", 0 , 1) == 0)
               {
                   //printf("El campo fue ordenado de manera exitosa..\n");
                   printEmployees(list , range);
               }
               else
               {
                   printf("Algo fallo en el ordenamiento.. reintente\n");
               }
            }
            else
            {
                //PROMEDIOS-....
                SalarysStatus(list , range);
            }
           //--------------------------------------------------------

       }
       else
       {
           printf("Algo fallo reintente..\n");
       }

    }
    else
    {
       printf("El listado se encuentra vacio, debe haber almenos un empleado cargado para entrar a este campo..\n");
    }
}

//--------------------------------------------------------------------------------------------------------------------
