#include "ePedidos.h"
#define PENDIENTE 0
#define CARGADO 1
#define SINASIGNAR -1

int inicializarArrayPedidos(ePedidos lista[] , int rango)
{
    int ret;
    int i;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        ret = 0;

        for(i=0 ; i<rango ; i++)
        {
            lista[i].estadoPedido = SINASIGNAR;
            lista[i].isEmpty = 1;
            lista[i].kilosTotales = 0;
            lista[i].kilosRestantes = 0;
            lista[i].idCliente = 0;
        }
    }

    return ret;
}

//------------------------------------------------------------------------------

int isEmptyPedidos(ePedidos lista[] , int rango)
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


//------------------------------------------------------------------------------

int hayAlgunPedidoCargado(ePedidos lista[] , int rango)
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


//------------------------------------------------------------------------------

int getIndexPedido(ePedidos lista[] , int rango)
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
                ret = i;
                break;
            }
            else
            {
                ret = -2;
            }
        }
    }

    return ret;
}


//------------------------------------------------------------------------------

int preCarga(ePedidos lista[] , int rango , int* id , int idClienteSeleccionado)
{
    int ret;
    float aux;
    int index;

    ret = -1;

    if(lista != NULL && rango > 0 && id != NULL)
    {
        index = getIndexPedido(lista , rango);

        if(index > -1)
        {
            lista[index].kilosHdpe = 0;
            lista[index].kilosLdpe = 0;
            lista[index].kilosPp = 0;
            lista[index].isEmpty = 0;
            lista[index].estadoPedido = PENDIENTE;

            if(Get_floatConLimites("Ingrese la cantidad de kilos totales a procesar , no puede superar los 250000 kilos..","Error la cantidad de kilos no puede ser tan grande ni cero...", 1 , FLT_MAX , &aux) == 0)
            {
                lista[index].kilosTotales = aux;
                lista[index].idPedidos = *id + 2;
                lista[index].idCliente = idClienteSeleccionado;
                *id = lista[index].idPedidos;
                ret = 0 ;
                printf("\n **  Su ID para reconocer el pedido es: %d  **\n",lista[index].idPedidos);
            }
        }
        else
        {
            if(index == -2)
            {
                ret = -2; //ya no hay lugar disponible en la lista de pedidos
            }
        }
    }

    return ret;
}

//------------------------------------------------------------------------------

int mostrarPedidos(ePedidos lista[], int rango)
{
    int ret;
    int i;

    ret = -1;

    for(i=0 ; i<rango ; i++)
    {
        if(lista[i].isEmpty == 0)
        {

                ret = 0;
                printf("\n\nID PEDIDO: %d KILOS TOTALES: %.2f KILOS HDPE: %.2f KILOS LDPE: %.2f KILOS PP: %.2f  KILOS RESTANTES: %.2f ESTADO: %d\n",lista[i].idPedidos , lista[i].kilosTotales,
                                                                                                                    lista[i].kilosHdpe, lista[i].kilosLdpe ,lista[i].kilosPp ,
                                                                                                                   lista[i].kilosRestantes , lista[i].estadoPedido);
        }
    }

    return ret;
}

//------------------------------------------------------------------------------

int darDeBajaPedido(ePedidos lista[], int rango , int idAborrar)
{
    int i;
    int ret;

    ret = -1;

    if(lista != NULL)
    {
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].idCliente == idAborrar)
            {
                lista[i].isEmpty = 1;
                ret = 0;
            }
        }
    }

    return ret;
}

//------------------------------------------------------------------------------

int encontrarIdRelacion(ePedidos lista[], int rango , int idAencontrar)
{
    int ret;
    int i;

    ret = -1;

    if(lista != NULL && rango > 0 && idAencontrar > 0)
    {
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                if(lista[i].idCliente == idAencontrar)
                {
                    ret = i;
                }
            }
        }
    }

    return ret;
}

//------------------------------------------------------------------------------

int encontrarIdPedido(ePedidos lista[], int rango , int idAencontrar)
{
    int ret;
    int i;

    ret = -1;

    if(lista != NULL && rango > 0 && idAencontrar > 0)
    {
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                if(lista[i].idPedidos == idAencontrar)
                {
                    ret = i;
                }
            }
        }
    }

    return ret;
}

//------------------------------------------------------------------------------

int procesadoResiduos(ePedidos lista[] , int rango)
{
    int ret;
    int idAcompletar;
    int indexAuxiliar;
    float sumaKilos;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        if(mostrarPedidosPendientes(lista , rango) == 0)
        {
            if(Get_numeroConLimites("Ingrese el id del pedido a completar..","Error el id debe ser mayor a 0..",0, 255 , &idAcompletar) == 0)
            {
                indexAuxiliar = encontrarIdPedido(lista , rango , idAcompletar);

                if(indexAuxiliar > -1)
                {
                    sumaKilos = 0;
                    if(completarResiduos(&lista[indexAuxiliar].kilosHdpe , &lista[indexAuxiliar].kilosLdpe ,&lista[indexAuxiliar].kilosPp) == 0)
                    {
                        sumaKilos = lista[indexAuxiliar].kilosHdpe + lista[indexAuxiliar].kilosLdpe + lista[indexAuxiliar].kilosPp;

                        if(sumaKilos <= lista[indexAuxiliar].kilosTotales)
                        {
                            lista[indexAuxiliar].kilosRestantes = lista[indexAuxiliar].kilosTotales - sumaKilos;
                            lista[indexAuxiliar].estadoPedido = CARGADO;
                            ret = 0;
                        }
                        else
                        {
                            ret = -3; // LOS KILOS NO PUEDEN SUPERAR EL TOTAL DE KILOS..
                        }
                    }
                }
                else
                {
                    ret = -2; //ESE ID NO SE ENCONTRO EN LA LISTA..
                }
            }
        }
        else
        {
            ret = -4; //NO HAY PEDIDOS POR COMPLETAR..
        }
    }

    return ret;
}

//------------------------------------------------------------------------------

int completarResiduos(float* kilosHdpe , float* kilosLdpe , float* kilosPp)
{
    int ret;
    float auxiliarFloat;

    ret = -1;

        if(kilosHdpe != NULL && kilosLdpe != NULL && kilosPp != NULL)
        {
            if(Get_floatConLimites("Ingrese la cantidad de kilos de Polietileno de alta densidad -HDPE-","Error, la cantidad no pude superar los 250000 kilos",
                                    0 , 250000 , &auxiliarFloat) == 0)
            {
                *kilosHdpe = auxiliarFloat;
                ret = 0;
            }

            if(Get_floatConLimites("Ingrese la cantidad de kilos de Polietileno de baja densidad -LDPE-","Error, la cantidad no pude superar los 250000 kilos",
                                    0 , 250000 , &auxiliarFloat) == 0)
            {
                *kilosLdpe = auxiliarFloat;
                ret = 0;
            }

            if(Get_floatConLimites("Ingrese la cantidad de kilos de Polipropileno -PP-","Error, la cantidad no pude superar los 250000 kilos",
                                    0 , 250000 , &auxiliarFloat) == 0)
            {
                *kilosPp = auxiliarFloat;
                ret = 0;
            }
        }

    return ret;
}


//------------------------------------------------------------------------------

int mostrarPedidosPendientes(ePedidos lista[], int rango)
{
    int ret;
    int i;

    ret = -1;

    for(i=0 ; i<rango ; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            if(lista[i].estadoPedido == PENDIENTE)
            {
                ret = 0;
                printf("\n\nID PEDIDO: %d KILOS TOTALES: %.2f KILOS HDPE: %.2f KILOS LDPE: %.2f KILOS PP: %.2f  KILOS RESTANTES: %.2f ESTADO: %d\n",lista[i].idPedidos , lista[i].kilosTotales,
                                                                                                                    lista[i].kilosHdpe, lista[i].kilosLdpe ,lista[i].kilosPp ,
                                                                                                                        lista[i].kilosRestantes , lista[i].estadoPedido);

            }
        }
    }

    return ret;
}


//------------------------------------------------------------------------------

int contadorDePedidosPendientesPorCliente(ePedidos lista[] , int rango , int idAcontar)
{
    int ret;
    int i;

    ret = -1;

    if(lista != NULL && rango > 0)
    {
        ret = 0;
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                if(lista[i].idCliente == idAcontar)
                {
                    ret++;
                }
            }
        }
    }

    return ret;
}

//------------------------------------------------------------------------------

int estaPendiente(ePedidos lista[] , int rango, int idAencontrar)
{
    int ret;
    int i;
    int contadorAux;

    contadorAux = 0;
    ret = -1;

    if(lista != NULL && rango > 0)
    {
        ret = 0;
        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                if(lista[i].idCliente == idAencontrar && lista[i].estadoPedido == PENDIENTE)
                {
                    contadorAux++;
                }
            }
        }

        if(contadorAux > 0)
        {
            ret = contadorAux;
        }
    }

    return ret;
}


//------------------------------------------------------------------------------

int acumuladorPlasticosPorCliente(ePedidos lista[] , int rango , int idAencontrar , float* acumulado)
{
    int ret;
    int i;
    float auxiliar;

    ret = -1;

    if(lista != NULL && rango > 0 && acumulado != NULL)
    {
        auxiliar = 0;

        for(i=0 ; i<rango ; i++)
        {
            if(lista[i].isEmpty == 0 && lista[i].estadoPedido == CARGADO)
            {
                if(lista[i].idCliente == idAencontrar)
                {
                    auxiliar += lista[i].kilosPp;
                    ret = 0;
                }
            }
        }

        if(ret == 0)
        {
            *acumulado = auxiliar; // si no entra devuelve -1 (no acumulo o fallo por los nulls)
        }
    }

    return ret;
}
