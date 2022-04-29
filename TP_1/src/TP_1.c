/*
 * TRABAJO PRACTICO NUMERO 1 , CALCULADORA
 *
 * ALUMNO: Mendez Juan Cruz
 * DIV: 1C
 * DNI: 40423224
*/
#include <stdio.h>
#include "calculadora.h"

int main()
{

	setbuf(stdout , NULL);

    int banderaPresentacion;
    float numeroUno;
    float numeroDos;
    int opcion;
    int banderaNumUno;
    int banderaNumDos;
    int banderaTres;
    float suma;
    float resta;
    float division;
    float multiplo;
    long long int factorialUno;
    long long int factorialDos;
    int verificacionUno;
    int verificacionDos;
    int resultadoA;
    int resultadoB;
    int resultadoC;
    int resultadoD;
    int resultadoE;
    int resultadoF;


    banderaNumUno = 0;
    banderaNumDos = 0;
    banderaTres = 0;
    banderaPresentacion = 0;

    do
    {
        if(banderaPresentacion == 0)
        {
            printf("\n \t\t\t\t BIENVENIDO\n\n\n");
            printf("Para operar, digite el numero con la opcion que desee seleccionar del siguiente menu, al ingresar el numero presione enter..\n\n");
            banderaPresentacion = 1;
        }

        Desplegar_menu(&opcion);

        switch(opcion)
        {
            case 1:
                if(Get_numero("Ingrese un numero: ", &numeroUno) != 0)
                {
                	printf("\n\t\tHubo un error en el ingreso del numero..\n");
                }
                else
                {
                	banderaNumUno = 1;
                }
            break;
            case 2:
            	if(banderaNumUno == 1)
            	{
            		if(Get_numero("Ingrese el segundo operando..\n",&numeroDos) != 0)
            		{
            			printf("\n\n\t\tHubo un error en la carga del operando 2..\n");
            		}
            		else
            		{
            			banderaNumDos = 1;
            		}
            	}
            	else
            	{
					printf("\n\n\t\tNo podes continuar sin haber ingresado el primer valor..\n");
				}

            break;
            case 3:
                if(banderaNumUno == 1 && banderaNumDos == 1)
                {
                    banderaTres = 1;

                    resultadoA = Get_suma(numeroUno , numeroDos , &suma);

                    //------------

                    resultadoB = Get_resta(numeroUno , numeroDos , &resta);

                    //------------

                    resultadoC = Get_division(numeroUno , numeroDos , &division);

                    //------------

                    resultadoD = Get_multiplo(numeroUno , numeroDos , &multiplo);

                    //------------

                    resultadoE = Get_factorial(numeroUno , &factorialUno , &verificacionUno);

                    //------------

                    resultadoF = Get_factorial(numeroDos , &factorialDos , &verificacionDos);

                    printf("\n\n\t\t--Se han calculado de manera correcta los resultados..\n\n");

                }
                else
                {
                    printf("\n\n\t\tFaltan datos ingresados asegurese de haber ingresado ambos operandos..\n\n");
                }

            break;
            case 4:
                if(banderaNumUno == 1 && banderaNumDos == 1 && banderaTres == 1)
                {
                    printf("----------------------------------------RESULTADOS------------------------------------------------------------\n\n");

                    if(resultadoA == 0)
                    {
                        printf("\n\n(A)\t\tEl resultado de %.2f + %.2f es: %.2f",numeroUno , numeroDos ,suma);
                    }
                    else
                    {
                        printf("\n\n(A)\t\tAlgo salio mal.. no se pudo calcular la suma..\n");
                    }

                    //------------

                    if(resultadoB == 0)
                    {
                        printf("\n\n(B)\t\tEl resultado de %.2f - %.2f es: %.2f",numeroUno , numeroDos ,resta);
                    }
                    else
                    {
                        printf("\n\n(B)\t\tAlgo salio mal.. no se pudo calcular la resta..\n");
                    }

                    //------------

                    if(resultadoC == 0)
                    {
                        printf("\n\n(C)\t\tEl resultado de %.2f / %.2f es: %.2f",numeroUno , numeroDos ,division);
                    }
                    else
                    {
                        printf("\n\n(C)\t\tNo se puede dividir por cero...\n");
                    }

                    //------------

                    if(resultadoD == 0)
                    {
                        printf("\n\n(D)\t\tEl resultado de %.2f * %.2f es: %.2f",numeroUno , numeroDos ,multiplo);
                    }
                    else
                    {
                        printf("\n\n(D)\t\tNo se pudo calcular la multiplicacion...\n");
                    }

                    //------------

                    if(resultadoE == 0 && resultadoF == 0)
                    {
                        if(verificacionUno == 0 && verificacionDos == 0)
                        {
                            printf("\n\n(E)\t\tEl factorial de %d es:  %I64u y el factorial de %d es:  %I64u\n",(int)numeroUno,factorialUno, (int)numeroDos , factorialDos);
                        }
                        else
                        {
                            if(verificacionUno == -1 || verificacionDos == -1)
                            {
                                printf("\n\n(E)\t\tAmbos numeros deben ser mayores a cero y enteros..\n");
                            }
                            else
                            {
                                if(verificacionUno == -2 || verificacionDos == -2)
                                {
                                    printf("\n\n(E)\t\tLo sentimos pero por el momento nuestra \n\t\tcalculadora solo llega a calcular el factorial \n\t\tde numeros menores a 19..\n");
                                }
                            }
                        }
                    }
                    else
                    {
                        printf("\n\n(E)\t\tHubo una falla al conseguir el factorial..\n");
                    }
                }
                else
                {
                    printf("\n\n(E)\t\tAsegurese de inicializar las opciones 1,2 y 3 del menu para continuar..\n");
                }

                printf("\n\n--------------------------------------------------------------------------------------------------------------\n\n");
        }

    }while(opcion != 5);


    printf("\n\n\n-----------------------------------------LA EJECUCION DEL PROGRAMA FINALIZO--------------------------------------------------------");

    return 0;
}

