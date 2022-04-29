

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define TAMNAME 51
#define TAMLASTNAME 51



#include "input.h"
#include "nombres.h"
#include <limits.h>

typedef struct
{
    int id;
    char name[TAMNAME];
    char lastName[TAMLASTNAME];
    float salary;
    int sector;
    int isEmpty;

}Employee;

//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Inicializa un array de estructura Employee modificando la variable isEmpty en 1 (indicando que estan vacios)
 * @param list: Array de tipo Employee
 * @param range: Largo de la cadena de Employee
 * @return Retorna -1 si hubo algun error en la inicializacion , 0 si se inicializo bien
 */
int initEmployees(Employee list[] , int range);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Crea un empleado auxiliar y verifica si hay lugar disponible o no, si hay llama a la funcion addEmployee y carga el empleado pasandole los campos completos
 * @param list: Array de tipo Employee
 * @param range: Largo de la cadena de Employee
 * @param idViejo: Numero de ID del ultimo empleado cargado
 * @param int* idNuevo: Nuevo id generado
 * @return Retorna la respuesta de addEmployee (0 si cargo bien, -1 si hubo error , -2 si no habia lugar para guardar)
 */
int loadEmployee(Employee list[] , int range, int idViejo , int* idNuevo);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Carga un empleado dentro de una listade tipo Employee solo si encuentra lugar disponible
 * @param list: Array de tipo Employee
 * @param range: Largo de la cadena de Employee
 * @param id: Numero de ID del empleado
 * @param name: Nombre del empleado
 * @param lastName: Apellido del empleado
 * @param salary: Salario del empleado
 * @param sector: Sector donde trabaja el empleado
 * @return Retorna -1 si hubo algun error en los nulls , 0 si se cargo bien , -2 si no habia lugar disponible
 */
int addEmployee(Employee list[], int range , int id , char name[] , char lastName[] , float salary , int sector);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Muestra menu de opciones y pide la opcion seleccionada
 * @param int* respuesta: Espacio de memoria para guardar la opcion seleccionada
 * @return Retorna -1 si hubo un error en el pedido o los nulls, 0 si se obtuvo correctamente la opcion
 */
int DeployMenu(int* respuesta);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Genera un nuevo id escalonado
 * @param id: id anterior, a incrementar
 * @return Retorna ret (el nuevo id generado)
 */
int incrementId(int id);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Busca un empleado a travez del id y devuelve su posicion en el array
 * @param list: Array de tipo Employee
 * @param range: Largo de la cadena de Employee
 * @param idToFind: Numero de id a encontrar
 * @return Retorna -1 si no encuentra el id, tambien abarca si fue eliminado el empleado de la lista , Si lo encontro retorna el indice
 */
int findEmployeeById(Employee list[], int range,int idToFind);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Remueve a un empleado por Id (Le cambia el valor a 0 de la variable isEmpty)
 * @param list: Array de tipo Employee
 * @param range: Largo de la cadena de Employee
 * @param idEmployeeToRemove: Numero de id a borrar
 * @return Retorna -1 si hay error con los nulls, -2 si cancelo la operacion , -3 si no encontro ese id, 0 si se dio de baja correctamente
 */
int removeEmployee(Employee list[], int range,int idEmployeeToRemove);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Pide un el ingreso de un id al usuario
 * @param list: Array de tipo Employee
 * @param range: Largo de la cadena de Employee
 * @param iddelate: Referencia de variable donde se va a guardar el id
 * @param men: Mensaje
 * @param menE: Mensaje de error
 * @return Retorna -1 si hay error con los nulls o el pedido, 0 si consigue bien el id
 */
int get_idToDelate(Employee list[] , int range , int* idToDelate , char men[] , char menE[]);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Imprime la lista de empleados (solo los que estan cargados)
 * @param list: Array de tipo Employee
 * @param range: Largo de la cadena de Employee
 * @return Retorna -1 si hay error con los nulls , 0 si imprime bien el listado
 */
int printEmployees(Employee list[], int range);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Chequea si al menos hay un empleado cargado en la lista (campo isEmpty == 0)
 * @param list: Array de tipo Employee
 * @param range: Largo de la cadena de Employee
 * @return Retorna -1 si hay error con los nulls , 0 si al menos encontro un empleado cargado
 */
int isEmpty(Employee list[] , int range);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Ordena de manera ascendente o descendente con respecto al apellido o si es igual con respecto al sector
 * @param list: Array de tipo Employee
 * @param range: Largo de la cadena de Employee
 * @param order: Indica el orden en que se ordena, 0 de manera descendente // 1 de manera ascendente
 * @return Retorna -1 si hay error con los nulls , 0 si ordeno correctamente
 */
int sortEmployees(Employee list[], int range, int order);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Modifica el nombre, apellido , sueldo o sector de un empleado cargado (el usuario elige que modificar)
 * @param list: Array de tipo Employee
 * @param range: Largo de la cadena de Employee
 * @param mens: Mensaje de pedido de id a modificar
 * @param mensE: Mensaje de error del pedido del id
 * @return Retorna -1 si hay error con los nulls de alguna funcion llamada , 0 si modifico bien el nombre,
 *                  1 si modifico bien el apellido,2 si modifico bien el salario,3 si modifico bien el sector,
 *                  -2 si cancela la operacion , -3 si no se encontro ese id
 */
int ModifyEmployee(Employee list[] , int range, char mens[] , char mensE[]);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Pide un numero con rango y lo devuelve por return (este caso es en base a estructura employee)
 * @param mens: Mensaje de pedido
 * @param mensE: Mensaje de error
 * @param min: Rango minimo
 * @param max: Rango maximo
 * @return Retorna -1 si fallaron nulls , o retorna el numero ingresado
 */
int whatField(char mens[] , char mensE[] , int min , int max);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Pide un entero (en este caso pide como ordenar) y se lo pasa a la funcion sortEmployee
 * @param mens: Mensaje de pedido
 * @param mensE: Mensaje de error
 * @param min: Rango minimo
 * @param max: Rango maximo
 * @return Retorna -1 si fallaron nulls , 0 si ordeno adecuadamente
 */
int organizeEmployees(Employee list[] , int range , char mens[] , char mensE[] , int min , int max);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Acumula el total de sueldos cargados
 * @param list: Lista de empleados
 * @param range: Rango de la lista
 * @param acumulado*: Referencia de variable donde se guarda el acumulado
 * @return Retorna -1 si fallaron nulls , 0 calculo adecuadamente
*/
int get_acumuladoSueldos(Employee list[], int range , float* acumulado);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Cuenta la cantidad de empleados cargados
 * @param list: Lista de empleados
 * @param range: Rango de la lista
 * @param acumulado*: Referencia de variable donde se guarda la cantidad de empleados registrada
 * @return Retorna -1 si fallaron nulls o no hay empleados cargados , 0 si conto bien los empleados
*/
int contadorEmpleados(Employee list[], int range , int* acumulado);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Cuenta la cantidad de empleados que superan el sueldo promedio
 * @param list: Lista de empleados
 * @param range: Rango de la lista
 * @param sueldoPromedio: Indica el promedio de los sueldos
 * @return Retorna -1 si fallaron nulls , 0 si no hay empleados que superen el promedio y sino la cantidad de empleados que lo superan (+ de 0)
*/
int contadorEmpleadosSuperanPromedio(Employee list[] , int range , float sueldoPromedio);
//-----------------------------------------------------------------------------------------------------------------------

/**
 * @brief Imprime resultados de promedio de sueldosy cuantos empleados superan este
 * @param list: Lista de empleados
 * @param range: Rango de la lista
*/
void SalarysStatus(Employee list[] , int range);
//-----------------------------------------------------------------------------------------------------------------------

#endif /* ARRAYEMPLOYEES_H_ */
