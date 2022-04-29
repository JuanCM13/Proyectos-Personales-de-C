
#ifndef NEXO_H_
#define NEXO_H_

#include "cliente.h"
#include "ePedidos.h"

//-------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Llama varias funciones dentro para pre cargar un pedido y actualiza el id de pedidos (declarar los kilos totales)
 * @param listaClientes: Listado de clientes
 * @param rangoClientes: Largo de la lista de clientes
 * @param listaPedidos: Listado de pedidos
 * @param rangoPedidos: Largo de la lista de pedidos
 * @param *idPedidos: Referencia de variable de control idPedidos(manipula el valor del id de pedidos)
 * @return -1 si algo falla con los nulls, -2 si el id de cliente a cargar pedido no se encuentra en la lista , 0 si se cargo bien
 */
int get_pedido(eCliente listaClientes[] , int rangoClientes , ePedidos listaPedidos[] , int rangoPedidos , int* idPedidos);

//-------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Llama varias funciones dentro para dar de baja un cliente y en tal caso sus pedidos si tiene
 * @param listaPedidos: Listado de pedidos
 * @param rangoPedidos: Largo de la lista de pedidos
 * @param listaClientes: Listado de clientes
 * @param rangoClientes: Largo de la lista de clientes
 * @return -1 si algo falla con los nulls, -2 si el id de cliente a cargar pedido no se encuentra en la lista , -3 si cancela la operacion
 *          0 si se dio de baja el cliente bien junto con sus pedidos , 1 se dio de baja el cliente pero no los pedidos por que no le cargo ninguno todavia..
 */
int bajaCliente(ePedidos listaPedidos[] , int rangoPedidos , eCliente listaClientes[] , int rangoClientes);

//-------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Imprime la lista de clientes con sus pedidos en estado pendiente
 * @param listaClientes: Listado de clientes
 * @param rangoClientes: Largo de la lista de clientes
 * @param listaPedidos: Listado de pedidos
 * @param rangoPedidos: Largo de la lista de pedidos
 * @return -1 si algo falla con los nulls, 0 si muestra de manera correcta
 */
int imprimirClientesConPedidosPendientes(eCliente listaClientes[] , int rangoClientes , ePedidos listaPedidos[] , int rangoPedidos);

//-------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Imprime la lista de pedidos pendientes, junto con los datos del cliente relacionado
 * @param listaPedidos: Listado de pedidos
 * @param rangoPedidos: Largo de la lista de pedidos
 * @param listaClientes: Listado de clientes
 * @param rangoClientes: Largo de la lista de clientes
 * @return -1 si algo falla con los nulls, 0 si muestra de manera correcta
 */
int mostrarPedidosPendientesConClientes(ePedidos listaPedidos[] , int rangoPedidos , eCliente listaClientes[] , int rangoClientes);

//-------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Imprime la lista de pedidos procesados, junto con los datos del cliente relacionado y la cantidad de kilos de plasticos procesados
 * @param listaPedidos: Listado de pedidos
 * @param rangoPedidos: Largo de la lista de pedidos
 * @param listaClientes: Listado de clientes
 * @param rangoClientes: Largo de la lista de clientes
 * @return -1 si algo falla con los nulls, 0 si muestra de manera correcta ,  -2 si no hay pedidos procesados
 */
int mostrarPedidosProcesadosConClientes(ePedidos listaPedidos[] , int rangoPedidos , eCliente listaClientes[] , int rangoClientes);

//-------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Pide el ingreso de una localidad y devuelve por return la cantidad de pedidos pendientes para esa localidad
 * @param listaPedidos: Listado de pedidos
 * @param rangoPedidos: Largo de la lista de pedidos
 * @param listaClientes: Listado de clientes
 * @param rangoClientes: Largo de la lista de clientes
 * @return -1 si algo falla con los nulls, 0 si calcula de manera correcta ,  -2 si no se encuentra esa ubicacion,
 * -3 si no hay pedidos pendientes para esa localidad , retorna sino la cantidad de pedidos pendientes calculados
 */
int pedidosPendientesPorLocalidad(ePedidos listaPedidos[] , int rangoPedidos , eCliente listaClientes[] , int rangoClientes);

//-------------------------------------------------------------------------------------------------------------------------------------------------

/**
 * @brief Imprime el promedio de plastico PP por cliente sobre el total de clientes
 * @param listaClientes: Listado de clientes
 * @param rangoClientes: Largo de la lista de clientes
 * @param listaPedidos: Listado de pedidos
 * @param rangoPedidos: Largo de la lista de pedidos
 * @return -1 si algo falla con los nulls, 0 si imprime y calcula de manera correcta
 */
int mostrarTotalPpPorCliente(eCliente listaClientes[] , int rangoClientes , ePedidos listaPedidos[] , int rangoPedidos);


#endif /* NEXO_H_ */
