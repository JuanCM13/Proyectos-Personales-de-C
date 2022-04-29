#include "cliente.h"

int inicializarArray(eCliente lista[] , int rango)
{
    int ret;
    int i;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        ret = 0;
        //4 para el hardcodeo
        for(i=4 ; i<rango ; i++)
        {
            lista[i].isEmpty = 1;
        }
    }

    return ret;
}

//--------------------------------------------------------

int desplegarMenu(int* respuesta)
{
    int aux;
    int ret;

    ret = -1;

    if(respuesta != NULL)
    {
        printf("\n\n|----------------------------------------MENU--------------------------------------------------|\n");
        printf("|   1) Alta de cliente                                                                         |\n");
        printf("|   2) Modificar datos de cliente:                                                             |\n");
        printf("|   3) Baja de cliente:                                                                        |\n");
        printf("|   4) Crear pedido de recolección:                                                            |\n");
        printf("|   5) Procesar residuos:                                                                      |\n");
        printf("|   6) Imprimir Clientes:                                                                      |\n");
        printf("|   7) Imprimir Pedidos pendientes:                                                            |\n");
        printf("|   8) Imprimir Pedidos procesados:                                                            |\n");
        printf("|   9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad |\n");
        printf("|   10) Cantidad de kilos de polipropileno reciclado promedio por cliente.                     |\n");
        printf("|   0)  SALIR                                                                                  |\n");
        printf("|----------------------------------------------------------------------------------------------|\n\n");

        if(Get_numeroConLimites("SELECCIONE UNA OPCION..", "ERROR, INGRESE UNA OPCION ENTRE LAS MOSTRADAS..",0,10,&aux) == 0)
        {
            ret = 0;
            *respuesta = aux;
        }
    }

    return ret;
}

//----------------------------------------------------------------------------------------------

int isEmptyClientes(eCliente lista[] , int rango)
{
    int i;
    int ret;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                ret = 0;
                break;
            }
        }
    }

    return ret;
}

//----------------------------------------------------------------------------------------------

int hayLugar(eCliente lista[] , int rango)
{
    int i;
    int ret;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                ret = 0;
                break;
            }
        }
    }

    return ret;
}

//----------------------------------------------------------------------------------------------

eCliente generarCliente(int* id)
{
    eCliente auxiliar;
    int resultadoId;

    if(Get_NombreEmpresa("Ingrese el nombre de la empresa.." , "El nombre de la empresa no puede ser tan grande.." , auxiliar.nombreEmpresa , sizeof(auxiliar.nombreEmpresa)) != 0)
    {
        printf("No se pudo cargar el nombre de la empresa, reintente..\n");
    }
    else
    {
        OrdenarNombre(auxiliar.nombreEmpresa , sizeof(auxiliar.nombreEmpresa));
    }

    if(Get_cuit("Ingrese el cuit, 11 numeros sin guiones ni espacios..", "Respete el formato del ejemplo: EJ: 20123456789", auxiliar.cuit , sizeof(auxiliar.cuit)) != 0)
    {
        printf("Algo fallo con la carga.. por favor reintente..\n");
    }


    if(Get_cadena("Ingrese la direccion donde vive...", "Error, la direccion no puede ser tan larga, reingrese..",auxiliar.direccion, sizeof(auxiliar.direccion)) != 0)
    {
        printf("Algo fallo con la carga.. por favor reintente..\n");
    }
    else
    {
        OrdenarNombre(auxiliar.direccion , sizeof(auxiliar.direccion));
    }

    if(Get_cadena("Ingrese la localidad donde reside...", "Error, la localidad no puede ser tan larga, reingrese..",auxiliar.localidad, sizeof(auxiliar.localidad)) != 0)
    {
        printf("Algo fallo con la carga.. por favor reintente..\n");
    }
    else
    {
        OrdenarNombre(auxiliar.localidad , sizeof(auxiliar.localidad));
    }

    if(QueresSeguir("Esta seguro de cargar este empleado? s/n...") == 0)
    {
        resultadoId = incrementarId(id);

        if(resultadoId != -1)
        {
            auxiliar.id = resultadoId;
            auxiliar.isEmpty = 0;
            printf("\nEl cliente fue cargado con exito.\nSu id para identificarlo es:  %d\n",*id);
            printf("\n---Si se equivoco en el ingreso de algun dato, podra modificarlo luego en la opcion 2 del menu..\n");
        }
        else
        {
            printf("Algo fallo con la carga del id, reintente..\n");
        }
    }

    return auxiliar;
}

//----------------------------------------------------------------------------------------------

int cargarCliente (eCliente listaClientes[], int rango , int* id)
{
    int i;
    int retorno;
    retorno = -1;

    for(i=0;i<rango;i++)
    {
        if(listaClientes[i].isEmpty != 0)
        {
            listaClientes[i] = generarCliente(id);
            retorno = 0;
            break;
        }
    }

    return retorno;
}

//----------------------------------------------------------------------------------------------

int incrementarId(int* id)
{
    int ret;

    ret = -1;

    if(id != NULL)
    {
        ret = *id + 1;
        *id = ret;
    }

    return ret;
}

//----------------------------------------------------------------------------------------------

int Get_cuit(char mensaje[] , char mensajeError[] , char cadena[] , int rango)
{
    int ret;
    char auxiliar[11];
    int i;
    int j;
    int respuesta;

    ret = -1; //fallaron los nulls etc

    if(mensaje != NULL && mensajeError != NULL && cadena != NULL && rango > 0)
    {
        do
        {

            if(ingresarCuit(mensaje ,  auxiliar , 12) == 0)
            {
                if(strlen(auxiliar) == 11)
                {
                    if(esNumero(auxiliar , 11) == 0)
                    {
                        respuesta = 1;
                        break;
                    }
                    else
                    {
                        printf("El cuit debe estar compuesto solo por numeros...\n");
                    }
                }
                else
                {
                    printf("El cuit debe tener 11 numeros, ni mas ni menos.. reintente\n");
                }
            }
            else
            {
                printf("Algo fallo, reintente..\n");
            }


            printf("%s\n",mensajeError);


        }while(1);

            //printf("Sali del bucle..\n");
            if(respuesta == 1)
            {
                j=0;

                for(i=0 ; i < 13 ; i++)
                {
                    if(i != 2 && i != 11)
                    {
                        cadena[i] = auxiliar[j];
                        j++;
                        //printf("i vale: %d\n",i);
                        //printf("La cadena de cuil vale: %c\n",cadena[i]);
                    }
                    else
                    {
                        //printf("Entre aca\n");
                        cadena[i] = '-';
                    }
                }

                ret = 0; //se cargo bien
                //printf("La cadena de cuil vale: %s\n",cadena);
            }
    }

    return ret;
}
//----------------------------------------------------------------------------------------------

int ingresarCuit(char mensaje[] , char cadena[] , int rango)
{
    int ret;
    char auxiliar[1000];

    ret = -1;

    if(mensaje != NULL && cadena != NULL && rango > 0)
    {
            ret = 0;
            printf ("%s \n", mensaje);
            __fpurge (stdin);
            scanf ("%[^\n]", auxiliar);

            if(strlen(auxiliar) < rango)
            {
                strcpy(cadena , auxiliar);
            }
    }

    return ret;
}

//-----------------------------------------------------------------------------------------------

int mostrarClientes(eCliente lista[], int rango)
{
    int ret;
    int i;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        ret = 0;
        printf("-------------------------------------------------------------------------------------------------\n");
        printf( " ID         NOMBRE              DIRECCION            LOCALIDAD              CUIT                 \n");
        printf("-------------------------------------------------------------------------------------------------\n\n");
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                printf("\n%4d  %15s  %20s  %20s  %20s           \n ",lista[i].id ,lista[i].nombreEmpresa, lista[i].direccion,
                                                                      lista[i].localidad , lista[i].cuit);
            }
        }
        printf("-------------------------------------------------------------------------------------------------\n\n");
    }
    return ret;
}

//-----------------------------------------------------------------------------------------------

int modificarCliente(eCliente lista[] , int rango , char mensaje[] , char mensajeError[])
{
    int ret;
    int idCliente;
    int resultado;
    int campoAmodificar;

    ret = -1;

    if(lista != NULL && rango > 0 && mensaje != NULL && mensajeError != NULL)
    {
        if(get_id(lista, rango , &idCliente , "Ingrese el id del cliente a modificar.." , "Error, el id debe ser mayor a cero..") == 0)
        {
            resultado = encontrarId(lista , rango , idCliente);

            if(resultado != -1)
            {
                do
                {
                    campoAmodificar = queCampo(mensaje , INT_MIN , INT_MAX);

                    if(campoAmodificar > 0 && campoAmodificar < 3)
                    {
                        break;
                    }

                    printf("%s\n",mensajeError);

                }while(1);

                if(QueresSeguir("Seguro que queres modificar ese campo?  s/n \n") == 0)
                {
                    switch(campoAmodificar)
                    {
                        case 1:

                        if(Get_cadena("Ingrese la direccion donde vive...", "Error, la direccion no puede ser tan larga, reingrese..",lista[resultado].direccion, sizeof(lista[resultado].direccion)) != 0)
                        {
                            ret = -1;
                        }
                        else
                        {
                            OrdenarNombre(lista[resultado].direccion , sizeof(lista[resultado].direccion));
                            ret = 0;
                        }

                        break;

                        case 2:

                        if(Get_cadena("Ingrese la localidad donde reside...", "Error, la localidad no puede ser tan larga, reingrese..",lista[resultado].localidad, sizeof(lista[resultado].localidad)) != 0)
                        {
                            ret -1;
                        }
                        else
                        {
                            OrdenarNombre(lista[resultado].localidad , sizeof(lista[resultado].localidad));
                            ret = 1;
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
                ret = -3; //el id ingresado no existe...
            }
        }
    }

    return ret;
}

//-----------------------------------------------------------------------------------------------

int get_id(eCliente lista[] , int rango , int* id , char mensaje[] , char mensajeError[])
{
    int ret;
    int aux;

    ret = -1;

    if(id != NULL && mensaje != NULL && mensajeError != NULL && lista != NULL && rango > 0)
    {
        if(mostrarClientes(lista, rango) != 0)
        {
            printf("Algo salio mal..\n");
        }

        if(Get_numeroConLimites(mensaje , mensajeError, 0 ,INT_MAX , &aux) == 0)
        {
            *id = aux;
            ret = 0;
        }
    }

    return ret;
}

//-----------------------------------------------------------------------------------------------

int encontrarId(eCliente lista[], int rango , int idAencontrar)
{
    int ret;
    int i;

    ret = -1;

    if(lista != NULL && rango > 0 && idAencontrar > 0)
    {
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].id == idAencontrar)
            {
                if(lista[i].isEmpty == 0)
                {
                    ret = i;
                }
            }
        }
    }

    return ret;
}

//-----------------------------------------------------------------------------------------------

int queCampo(char mensaje[] , int minimo , int maximo)
{
    int ret;
    int aux;

    if(Get_numeroConLimites(mensaje , "" , minimo , maximo , &aux) == 0)
    {
        ret = aux;
    }

    return ret;
}

//-----------------------------------------------------------------------------------------------

int contadorTotalClientes(eCliente lista[] , int rango , int* contador)
{
    int ret;
    int aux;
    int i;

    ret = -1;

    if(lista != NULL && contador != NULL && rango > 0)
    {
        aux = 0;

        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                aux++;
            }
        }
    }

    if(aux > 0)
    {
        *contador = aux;
        ret = 0;
    }

    return ret;
}

//-----------------------------------------------------------------------------------------------
/*
int bajaCliente(ePedidos lista[] , int rangoPedidos , eCliente lista[] , int rangoClientes)
{
    int ret;
    int idAborrar;
    int indexId;

    if(lista != NULL && rango > 0)
    {
       if(get_id(lista , rango , &idAborrar , "Ingrese el id a eliminar...", "Error, el id debe ser mayor a cero..\n") == 0 )
       {
            indexId = encontrarId(lista , rango , idAborrar);

            if(indexId != -1)
            {
                if(QueresSeguir("Esta seguro de borrar este cliente?? s/n..\n") == 0)
                {
                    lista[indexId].isEmpty = 1;
                    ret = 0;
                }
                else
                {
                    ret = -2; //cancelo la operacion
                }
            }
            else
            {
                ret = -3; //no se encontro ese id...
            }
       }
    }

    return ret;
}*/

//-----------------------------------------------------------------------------------------------



