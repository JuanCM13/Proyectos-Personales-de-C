
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


int desplegar_menu(int* opcion);
int Get_numero(char[] , int*);

int main()
{

	setbuf(stdout , NULL);

    int numeroUno;
    int numeroDos;
    int opcion;
    int banderaNumUno;
    int banderaNumDos;

    banderaNumUno = 0;
    banderaNumDos = 0;

    do
    {
        desplegar_menu(&opcion);

        switch(opcion)
        {
            case 1:
                if(Get_numero("Ingrese un numero: ", &numeroUno) != 0)
                {
                	printf("Hubo un error en el ingreso del numero..\n");
                }
                else
                {
                	banderaNumUno = 1;
                }
            break;
            case 2:
            	if(banderaNumUno != 1)
            	{
            		if(Get_numero("Ingrese el segundo operando..\n",&numeroDos) != 0)
            		{
            			printf("Hubo un error en la carga del operando 2..\n");
            		}
            		else
            		{
            			banderaNumDos = 1;
            		}
            	}
            	else
            	{
					printf("No podes continuar sin haber ingresado el primer valor..\n");
				}

            break;
            case 3:
                printf("Entre en la opcion 3\n");
            break;
            case 4:
                printf("Entre en la opcion 4\n");
            break;
        }

    }while(opcion != 5);


    return 0;
}

int desplegar_menu(int* opcion)
{
    int retorno;
    int buffer;

    retorno = -1;

    if(opcion != NULL)
    {
        do
        {
            printf("BIENVENIDO A CALCULADORA.2BV\n");
            printf("Para operar, digite el numero con la opcion que desee seleccionar del siguiente menu, al ingresar el numero presione enter..\n");
            printf("<1> Ingresar 1er operando\n");
            printf("<2> Ingresar 2do operando\n");
            printf("<3> Calcular todas las operaciones: \n");
            printf("<A> Calcular la suma (A+B)\n");
            printf("<B> Calcular la resta (A-B)\n");
            printf("<C> Calcular la division\n");
            printf("<D> Calcular la multiplicacion\n");
            printf("<E> Calcular el factorial\n");
            printf("<4> Informar resultados\n");
            printf("<5> Salir");
            printf("Ingrese la opcion que desee ejecutar?\n");
            scanf("%d",&buffer);

            if(buffer < 6 && buffer > 0)
            {
                *opcion = buffer;
                break;
            }

            printf("error, ingrese una opcion entra las planteadas..\n");


        }while(1);

        retorno = 0;
    }

/*1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir*/

    return retorno;
}

int Get_numero(char mensaje[], int* numero )
{
	int retorno = -1;
	int buffer;

	if(mensaje != NULL && numero != NULL)
	{
		printf("%s\n",mensaje);
		scanf("%d",&buffer);

		*numero = buffer;
		retorno = 0;
	}

	return retorno;
}
