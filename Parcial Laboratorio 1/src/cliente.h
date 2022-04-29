
#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "input.h"
#include "nombres.h"
#include "limits.h"


                    //CAMBIAR LOS DOXIGEN POR QUE ESTAN CON LA ESTRUCTURA EMPLEADO
#define TAMNOMBRE 100
#define TAMDIRECCION 100
#define TAMLOCALIDAD 100
#define TAMCUIT 14

typedef struct
{
    //un cliente puede tener varios pedidos...
    int id;
    char nombreEmpresa[TAMNOMBRE];
    char cuit[TAMCUIT];
    char direccion[TAMDIRECCION];
    char localidad[TAMLOCALIDAD];
    int isEmpty;
}eCliente;


/**
 * @brief Inicializa un array de estructura eCliente modificando la variable isEmpty en 1 (indicando que estan vacios)
 * @param lista: Listado de clientes
 * @param rango: Largo de la lista de clientes
 * @return Retorna -1 si hubo algun error en la inicializacion , 0 si se inicializo bien
 */
int inicializarArray(eCliente lista[] , int rango);

//----------------------------------------------------------------------------------------------------------

/**
 * @brief Muestra menu de opciones y pide la opcion seleccionada
 * @param int* respuesta: Espacio de memoria para guardar la opcion seleccionada
 * @return Retorna -1 si hubo un error en el pedido o los nulls, 0 si se obtuvo correctamente la opcion
 */
int desplegarMenu(int* respuesta);

//----------------------------------------------------------------------------------------------------------

/**
 * @brief Chequea si al menos hay un cliente cargado en la lista (campo isEmpty == 0)
 * @param list: Array de tipo cliente
 * @param range: Largo de la cadena de clientes
 * @return Retorna -1 si hay error con los nulls , 0 si al menos encontro un cliente cargado
 */
int isEmptyClientes(eCliente lista[] , int rango);

//----------------------------------------------------------------------------------------------------------

/**
 * @brief Chequea si al menos hay una posicion libre en la lista (campo isEmpty == 1)
 * @param list: Array de tipo cliente
 * @param range: Largo de la cadena de clientes
 * @return Retorna -1 si hay error con los nulls , 0 si al menos encontro un cliente cargado
 */
int hayLugar(eCliente lista[] , int rango);

//----------------------------------------------------------------------------------------------------------

/**
 * @brief carga un cliente en un auxiliar, si se verifica devuelve ese cliente con sus campos cargados..
 * @param id*: Referencia donde se almacena el id asignado
 * @return Retorna el cliente cargado..
 */
eCliente generarCliente(int* id);

//----------------------------------------------------------------------------------------------------------

/**
 * @brief carga un cliente en la lista de clientes..
 * @param list: Array de tipo cliente
 * @param range: Largo de la cadena de clientes
 * @param id*: Referencia donde se almacena el id
 * @return Retorna -1 si hay error con los nulls , 0 si carga bien el cliente
 */
int cargarCliente(eCliente listaClientes[] , int rango , int* id);

//----------------------------------------------------------------------------------------------------------

/**
 * @brief Genera un nuevo id incrementando el anterior
 * @param id*: Referencia donde se almacena el id
 * @return Retorna el id generado
 */
int incrementarId(int* id);

//----------------------------------------------------------------------------------------------------------


/**
 * @brief recibe una cadena cuit , verifica que esta correcto, le da formato y lo asigna a la cadena pasada..
 * @param mensaje: Mensaje de pedido de datos
 * @param mensajeError: Mensaje de error
 * @param cadena: cadena donde se va a asignar el cuit
 * @param range: Largo de la cadena de clientes
 * @return Retorna -1 si hay error con los nulls , 0 si carga bien el cuit
 */
int Get_cuit(char mensaje[] , char mensajeError[] , char cadena[] , int rango);

//----------------------------------------------------------------------------------------------------------

/**
 * @brief Pide una cadena como cuit
 * @param mensaje: Mensaje de pedido de datos
 * @param cadena: cadena donde se va a asignar el cuit
 * @param range: Largo de la cadena
 * @return Retorna -1 si hay error con los nulls , 0 si carga bien el cuit
 */
int ingresarCuit(char mensaje[] , char cadena[] , int rango);
//----------------------------------------------------------------------------------------------------------

/**
 * @brief Muestra la lista de clientes
 * @param lista: Listado de clientes
 * @param rango: Largo de la lista de clientes
 * @return Retorna -1 si hubo algun error en la muestra ,  0 si muestra bien
 */
int mostrarClientes(eCliente lista[], int rango);

//----------------------------------------------------------------------------------------------------------

/**
 * @brief Modifica la direccion o localidad del cliente
 * @param lista: Listado de clientes
 * @param rango: Largo de la lista de clientes
 * @param mensaje: Mensaje de pedido de datos
 * @param mensajeError: Mensaje de error
 * @return Retorna -1 si hubo algun error con nulls ,  0 si modifica bien, -2 cancelo operacion, -3 el id ingresado no existe...
 */
int modificarCliente(eCliente lista[] , int rango , char mensaje[] , char mensajeError[]);

//----------------------------------------------------------------------------------------------------------

/**
 * @brief Muestra la lista de clientes, y pide el id a seleccionar
 * @param lista: Listado de clientes
 * @param rango: Largo de la lista de clientes
 * @param *id: Referencia donde se almacena el id seleccionado
 * @param mensaje: Mensaje de pedido de datos
 * @param mensajeError: Mensaje de error
 * @return Retorna -1 si hubo algun error con nulls ,  0 si consiguio bien el id
 */
int get_id(eCliente lista[] , int rango , int* id , char mensaje[] , char mensajeError[]);

//----------------------------------------------------------------------------------------------------------

/**
 * @brief Busca y devuelve el indice en la lista de clientes de un id pasado por valor
 * @param lista: Listado de clientes
 * @param rango: Largo de la lista de clientes
 * @param idAencontrar: Id a encontrar
 * @return Retorna -1 si hubo algun error con nulls ,  sino devuelve el indice en el array del id pasado
 */
int encontrarId(eCliente lista[], int rango , int idAencontrar);

//----------------------------------------------------------------------------------------------------------

/**
 * @brief pide al usuario que elija entre valores pasados(en este caso sobre los campos a modificar)
 * @param mensaje: Mensaje de pedido de datos
 * @param minimo: valor minimo a tomar
 * @param maximo: valor maximo a tomar
 * @return Retorna la eleccion
 */
int queCampo(char mensaje[] , int minimo , int maximo);

//----------------------------------------------------------------------------------------------------------

/**
 * @brief Cuenta el total de clientes cargados al momento de llamarla..
 * @param lista: Listado de clientes
 * @param rango: Largo de la lista de clientes
 * @param *contador: Referencia donde va a guardar el total contado
 * @return Retorna -1 si hubo algun error con los nulls , o 0 si al menos conto 1 cliente cargado..
 */
int contadorTotalClientes(eCliente lista[] , int rango , int* contador);

//----------------------------------------------------------------------------------------------------------



#endif /* CLIENTE_H_ */
