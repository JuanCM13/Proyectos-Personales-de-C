
#ifndef INFORMES_H_
#define INFORMES_H_

#include "ArrayEmployees.h"

           //INFORMES DEL MAIN

/**
 * @brief Llama varias funciones dentro que permiten conseguir dar de alta o no un empleado
 * @param list: Recibe la lista de empleados
 * @param range: Recibe el tamaño del array de la lista
 * @param idAnterior: Recibe por valor el ultimo valor actualizado de id de empleados
 * @param idActual: Recibe por referencia la direccion de memoria donde va a almacenar el valor del nuevo id generado
 */
void informeAlta(Employee list[] , int range , int idAnterior, int* idActual);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Llama varias funciones dentro que permiten conseguir modificar los campos: nobre, apellido , salario o sector de un empleado
 * @param list: Recibe la lista de empleados
 * @param range: Recibe el tamaño del array de la lista
 */
void informeMod(Employee list[] , int range);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Llama varias funciones dentro que permiten dar de baja un empleado
 * @param list: Recibe la lista de empleados
 * @param range: Recibe el tamaño del array de la lista
 */
void informeBaja(Employee list[] , int range);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Llama varias funciones dentro que permiten calcular y mostrar el array ordenado de manera ascendente o descendente o promedio de sueldos y
 *        empleados que superan este
 * @param list: Recibe la lista de empleados
 * @param range: Recibe el tamaño del array de la lista
 */
void informeResultadosOrdenamientoYpromedios(Employee list[] , int range);
//-----------------------------------------------------------------------------------------------------------------------


#endif /* INFORMES_H_ */
