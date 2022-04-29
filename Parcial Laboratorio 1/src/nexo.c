#include "nexo.h"
#define PENDIENTE 0
#define CARGADO 1

//----------------------------------------------------------

int get_pedido(eCliente listaClientes[] , int rangoClientes , ePedidos listaPedidos[] , int rangoPedidos , int* idPedidos)
{
    int ret;
    int idClienteSeleccionado;
    int indexIdClienteSeleccionado;

    ret = -1;

    if(listaClientes != NULL && rangoClientes > 0 && listaPedidos != NULL && rangoPedidos > 0 && idPedidos != NULL)
    {
        if(get_id(listaClientes , rangoClientes , &idClienteSeleccionado , "Ingrese el id del cliente a generar el pedido..\n","Error, el id debe ser mayor a cero...\n") == 0)
        {
            indexIdClienteSeleccionado = encontrarId(listaClientes , rangoClientes , idClienteSeleccionado);

            if(indexIdClienteSeleccionado > -1 )
            {
                //printf("INDEX VALE: %d\n",indexIdClienteSeleccionado);
                if(preCarga(listaPedidos , rangoPedidos , idPedidos , idClienteSeleccionado) == 0)
                {
                    ret = 0; //Se cargo bien la pre carga... el id de realacion es: idPedidos
                    //printf("Id pedido : %d\n Id cliente relacionado: %d\n",listaPedidos[*idPedidos].idPedidos , listaPedidos[*idPedidos].idCliente);
                }
            }
            else
            {
                ret = -2; //ESE ID NO ESTA EN LA LISTA..
            }
        }

    }
    return ret;
}


//----------------------------------------------------------

int bajaCliente(ePedidos listaPedidos[] , int rangoPedidos , eCliente listaClientes[] , int rangoClientes)
{
    int idClienteAborrar;
    int indexClienteAborrar;
    int indexIdPedidoRelacion;
    int ret;

    ret = -1;

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0)
    {
        if(get_id(listaClientes , rangoClientes , &idClienteAborrar , "Ingrese el id a eliminar...", "Error, el id debe ser mayor a cero..\n") == 0 )
        {
            indexClienteAborrar = encontrarId(listaClientes , rangoClientes , idClienteAborrar);

            if(indexClienteAborrar != -1)
            {
                if(QueresSeguir("Esta seguro de borrar este cliente?? s/n..\n") == 0)
                {
                    listaClientes[indexClienteAborrar].isEmpty = 1;

                    ret = 0; // se dio de baja el cliente

                    if(darDeBajaPedido(listaPedidos , rangoPedidos , idClienteAborrar) != 0)
                    {
                        ret = 1;  //se dio de baja el cliente pero no los pedidos por que no le cargo ninguno todavia..
                    }
                }
                else
                {
                    ret = -3; //cancelo la operacion..
                }
            }
            else
            {
                ret = -2; //ese id no existe..
            }
        }
    }

    return ret;
}

//----------------------------------------------------------


int imprimirClientesConPedidosPendientes(eCliente listaClientes[] , int rangoClientes , ePedidos listaPedidos[] , int rangoPedidos)
{
    int i;
    int ret;
    int contadorPendientes;

    ret = -1;

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0)
    {
        for(i=0 ; i<rangoClientes ; i++)
        {
            if(listaClientes[i].isEmpty == 0)
            {
                contadorPendientes = contadorDePedidosPendientesPorCliente(listaPedidos , rangoPedidos , listaClientes[i].id);
                if(contadorPendientes > -1)
                {
                    ret = 0;
                    printf("\nID: %d -- NOMBRE: %5s -- CUIT: %11s -- DIRECCION: %4s -- LOCALIDAD: %4s --  PEDIDOS PENDIENTES: %4d\n", listaClientes[i].id ,
                                listaClientes[i].nombreEmpresa, listaClientes[i].cuit , listaClientes[i].direccion ,
                                listaClientes[i].localidad , contadorPendientes);
                }
            }
        }
    }

    return ret;
}


//----------------------------------------------------------

int mostrarPedidosPendientesConClientes(ePedidos listaPedidos[] , int rangoPedidos , eCliente listaClientes[] , int rangoClientes)
{
    int ret;
    int i;
    int index;

    ret = -1;

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0)
    {
        ret = -2; //No hay pedidos pendientes todavia....

        for(i=0 ; i<rangoPedidos ; i++)
        {
            if(listaPedidos[i].isEmpty == 0 && listaPedidos[i].estadoPedido == PENDIENTE)
            {
                index = encontrarId(listaClientes , rangoClientes , listaPedidos[i].idCliente);

                if(index > -1)
                {
                    ret = 0;
                    printf("ID PEDIDO: %4d -- CUIT CLIENTE: -%14s -- DIRECCION: %-20s -- KILOS A RECOLECTAR: %.2f ---PENDIENTE\n", listaPedidos[i].idPedidos , listaClientes[index].cuit ,
                                                                                                listaClientes[index].direccion , listaPedidos[i].kilosTotales);
                }

            }
        }
    }

    return ret;
}


//----------------------------------------------------------

int mostrarPedidosProcesadosConClientes(ePedidos listaPedidos[] , int rangoPedidos , eCliente listaClientes[] , int rangoClientes)
{
    int ret;
    int i;
    int index;

    ret = -1;

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0)
    {
        ret = -2; //No hay pedidos procesados todavia....

        printf("Pedidos procesados: \n");
        for(i=0 ; i<rangoPedidos ; i++)
        {
            if(listaPedidos[i].isEmpty == 0 && listaPedidos[i].estadoPedido == CARGADO)
            {
                index = encontrarId(listaClientes , rangoClientes , listaPedidos[i].idCliente);

                if(index > -1)
                {
                    ret = 0;
                    printf("ID PEDIDO: %4d -- CUIT CLIENTE: %14s -- DIRECCION: %10s -- HDPE: %.2f -- LDPE: %.2f -- PP: %.2f -- RESTOS: %.2f\n", listaPedidos[i].idPedidos , listaClientes[index].cuit ,
                                                                                                listaClientes[index].direccion , listaPedidos[i].kilosHdpe , listaPedidos[i].kilosLdpe ,
                                                                                                listaPedidos[i].kilosPp , listaPedidos[i].kilosRestantes);
                }

            }
        }
    }

    return ret;
}


//----------------------------------------------------------

int pedidosPendientesPorLocalidad(ePedidos listaPedidos[] , int rangoPedidos , eCliente listaClientes[] , int rangoClientes)
{
    int ret;
    int i;
    char auxiliar[51];
    int index;
    int contador;

    contador = 0;
    ret = -1;

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0)
    {
        ret = -2; //No se encontro esa ubicacion

        if(Get_cadena("Ingrese la localidad donde reside...", "Error, la localidad no puede ser tan larga, reingrese..", auxiliar , sizeof(auxiliar)) == 0)
        {
            for(i=0 ; i<rangoClientes ; i++)
            {
                if(strcmp(listaClientes[i].localidad , auxiliar) == 0)
                {
                    ret = -3; //No hay pedidos pendientes para esa localidad

                    contador += estaPendiente(listaPedidos , rangoPedidos , listaClientes[i].id);

                    if(contador > 0)
                    {
                        ret = 0;
                    }
                }
            }
        }

        if(contador > 0)
        {
            ret = contador;
        }
    }

    return ret;
}

//----------------------------------------------------------

int mostrarTotalPpPorCliente(eCliente listaClientes[] , int rangoClientes , ePedidos listaPedidos[] , int rangoPedidos)
{
    int i;
    int ret;
    float acumulador;
    int contadorClientesCargados;
    float promedio;

    ret = -1;

    if(listaPedidos != NULL && listaClientes != NULL && rangoClientes > 0 && rangoPedidos > 0)
    {
        for(i=0 ; i<rangoClientes ; i++)
        {
            if(listaClientes[i].isEmpty == 0)
            {
                if(acumuladorPlasticosPorCliente(listaPedidos , rangoPedidos , listaClientes[i].id , &acumulador) == 0)
                {
                    if(contadorTotalClientes(listaClientes , rangoClientes , &contadorClientesCargados) == 0)
                    {
                        if(get_promedio(acumulador , contadorClientesCargados , &promedio) == 0)
                        {
                            printf("El promedio de plastico PP reciclado del cliente id: %d nombre: %s cuit: Nª%s es: %.2f\n" , listaClientes[i].id ,listaClientes[i].nombreEmpresa , listaClientes[i].cuit ,promedio);
                            ret = 0;
                        }
                    }
                }
            }
        }
    }

    return ret;
}
