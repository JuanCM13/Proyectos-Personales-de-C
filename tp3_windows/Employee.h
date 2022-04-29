#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define MAXSTRING 150
#define MAXNOMBRE 128


#include "input.h"
#include "nombres.h"
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


Employee* employee_new();

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr , char* sueldoSrt);

int employee_delete(Employee* idAborrar);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

//-----------------------------------------------------------------------------------------------------------------------------------
//NUEVAS FUNCIONES MIAS

int imprimirUnEmpleado(Employee* empleado);

Employee* cargarEmpladoPorTeclado(int* idAnterior);

int modificarEmpleado(LinkedList* listaEmpleados);

int imprimirEmpleados(LinkedList* listaEmpleados);

int modificarCampo(Employee* this , int campoAactualizar);

Employee* findEmployee(LinkedList* listaEmpleados , int idAencontrar);

int eliminarEmpleado(LinkedList* listaEmpleados);

int ordenarEmpleados(LinkedList* listaEmpleados);

int compararEmpleadosPorNombre(void* primerElemento , void* segundoElemento);

int compararEmpleadosPorId(void* primerElemento , void* segundoElemento);

int compararEmpleadosPorHorasTrabajadas(void* primerElemento , void* segundoElemento);

int compararEmpleadosPorSueldo(void* primerElemento , void* segundoElemento);

int desplegarMenu(int* respuesta);
//------------------------------------------------------------------------------------------------------------------------------------
#endif // employee_H_INCLUDED
