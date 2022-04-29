#include <stdio.h>
#include "calculadora.h"

//----------------------------------------------------------------------------------------------------------------

/**
* \brief La funcion desplega el menu de opciones y retorna por referencia una opcion
* \ int* opcion es la direccion donde va a ser guardada la opcion elegida por el usuario
*/

void Desplegar_menu(int* opcion)
{
    int buffer;

    if(opcion != NULL)
    {
        do
        {
            printf("\t|-----------------------------------------------|");
            printf("\n\t|\t<1> Ingresar 1er operando\t\t|\n");
            printf("\t|\t<2> Ingresar 2do operando\t\t|\n");
            printf("\t|\t<3> Calcular todas las operaciones: \t|\n");
            printf("\t|\t<A> Calcular la suma      \t\t|\n");
            printf("\t|\t<B> Calcular la resta      \t\t|\n");
            printf("\t|\t<C> Calcular la division\t\t|\n");
            printf("\t|\t<D> Calcular la multiplicacion\t\t|\n");
            printf("\t|\t<E> Calcular el factorial\t\t|\n");
            printf("\t|\t<4> Informar resultados\t\t\t|\n");
            printf("\t|\t<5> Salir\t\t\t\t|");
            printf("\n\t|");
            printf("-----------------------------------------------|");
            printf("\n\n\t\tIngrese la opcion que desee ejecutar?\n\n");
            scanf("\n%d",&buffer);

            if(buffer < 6 && buffer > 0)
            {
                *opcion = buffer;
                break;
            }

            printf("\n\nError, ingrese una opcion entra las planteadas..\n\n");

        }while(1);
    }
}

//----------------------------------------------------------------------------------------------------------------

/**
* \brief la funcion pide un numero flotante
* \char[] mensaje es el mensaje a imprimir
* \float* numero direccion de memoria para guardar el flotante
* \return -1 si no se pudo calcular, 0 si se pudo..
*/

int Get_numero(char mensaje[], float* numero )
{
	int retorno = -1;
	float buffer;

	if(mensaje != NULL && numero != NULL)
	{
		printf("%s\n",mensaje);
		scanf("%f",&buffer);

		*numero = buffer;
		retorno = 0;
	}

	return retorno;
}

//----------------------------------------------------------------------------------------------------------------

/**
* \brief La funcion recibe 2 flotantes y los suma
* \ float primerOperador primer valor a sumar
* \float segundoOperador segundo valor a sumar
* \float* resultado donde se almacena el resultado
* \return -1 si no se pudo calcular, 0 si se pudo..
*/

int Get_suma(float primerOperador , float segundoOperador , float* resultado)
{
    int retorno;
    float buffer;

    retorno = -1;

    if(resultado != NULL)
    {
        buffer = primerOperador + segundoOperador;
        *resultado = buffer;

        retorno = 0;
    }

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------
/**
* \brief La funcion recibe 2 flotantes y los resta
* \ float primerOperador primer valor a restar
* \float segundoOperador segundo valor a restar
* \float* resultado donde se almacena el resultado
* \return -1 si no se pudo calcular, 0 si se pudo..
*/

int Get_resta(float primerOperador , float segundoOperador , float* resultado)
{
    int retorno;
    float buffer;

    retorno = -1;

    if(resultado != NULL)
    {
        buffer = primerOperador - segundoOperador;
        *resultado = buffer;

        retorno = 0;
    }

    return retorno;

}

//----------------------------------------------------------------------------------------------------------------
/**
* \brief La funcion recibe 2 flotantes y los divide
* \ float primerOperador primer valor a dividir
* \float segundoOperador segundo dividendo (tiene que ser distinto a cero)
* \float* resultado donde se almacena el resultado
* \return -1 si no se pudo calcular o si el segundoOperador fue igual a cero, 0 si se pudo..
*/

int Get_division(float primerOperador , float segundoOperador , float* resultado)
{
    int retorno;
    float buffer;

    retorno = -1;

    if(resultado != NULL)
    {
        if(segundoOperador != 0)
        {
            buffer = primerOperador / segundoOperador;
            *resultado = buffer;
            retorno = 0;
        }
    }

    return retorno;

}

//----------------------------------------------------------------------------------------------------------------
/**
* \brief La funcion recibe 2 flotantes y los multiplica
* \ float primerOperador primer valor a multiplicar
* \float segundoOperador segundo valor a multiplicar
* \float* resultado donde se almacena el resultado
* \return -1 si no se pudo calcular , 0 si se pudo..
*/

int Get_multiplo(float operadorUno , float operadorDos , float* resultado)
{
    int retorno;
    float buffer;

    retorno = -1;

    if(resultado != NULL)
    {
        buffer = operadorUno * operadorDos;
        *resultado = buffer;
        retorno = 0;
    }

    return retorno;
}


//----------------------------------------------------------------------------------------------------------------
/**
* \brief La funcion calcula el factorial de un entero menor a 19 y mayor a 0
* \ float operador numero a calcular
* \long long int* factorial donde se almacena el resultado del factorial
* \int* verificacion variable por referencia de control, -1 ES NUMERO DECIMAL O MENOR A 1 , -2 si ES MAYOR A 18 , 0 SI SE PUDO CALCULAR BIEN
* \return -1 si no se pudo calcular, 0 si se pudo..
*/

int Get_factorial(float operador , long long int* factorial , int* verificacion)
{
    int retorno;
    int i;
    long long int bufferAcumulador;
    int chequeo;

    retorno = -1;

    if(factorial != NULL)
    {
        retorno = 0;
        bufferAcumulador = 1;

        if(Es_factorial(operador) == 0)
        {
            if((int)operador < 19)
            {
                chequeo = 0;

                for(i=(int)operador ; i>1 ; i--)
                {
                    bufferAcumulador *= i;
                }
            }
            else
            {
                chequeo = -2; //ES MAYOR A 18
            }
        }
        else
        {
            chequeo = -1; //ES NUMERO DECIMAL O MAYOR A CERO
        }
    }

        *verificacion = chequeo;
        *factorial = bufferAcumulador;

    return retorno;
}

//----------------------------------------------------------------------------------------------------------------
/**
* \brief La funcion chequea si al numero ingresado se le puede calcular el factorial
* \ float operador numero a verificar
* \return -1 si no se puede calcular , 0 si se puede..
*/

int Es_factorial(float operador)
{
    int retorno;
    float buffer;

    retorno = -1;
    buffer = operador - (int)operador;

    if(buffer == 0 && operador > 0)
    {
        retorno = 0;
    }

    return retorno;
}



