/*
 ============================================================================
 Ejercicio 4-2:
Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit ,
 validando que las temperaturas ingresadas estén entre el punto de congelación y
 ebullición del agua para cada tipo de escala.
Las validaciones se hacen en una biblioteca.
Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra biblioteca.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int get_Float(float* temperatura,char mensaje[], char mensajeError[],int minimo, int maximo, int reintentos);

int main(void)
{
	setbuf(stdout, NULL);

	float fahrenheit;
	float celsius;
	int opcion;
	float celsiusAfahrenheit;
	int verificacionC;
	int verificacionF;

	printf("Ingrese 1 si desea hacer una conversion de celsius a fahrenheit, si desea de fahrenheit a celsius  ingrese 2\n");
	scanf("%d",&opcion);

	while(opcion != 1 || opcion != 0)
	{
		printf("Error reingrese entre los paremetros dichos: \n");
		scanf("%d",&opcion);
	}

	if(opcion == 1)
	{
		if(get_Float(&celsius, "Ingrese la temperatura en grados celsius.. entre 0 y 100 grados\n","Error\n",0,100,3))
		{
		 verificacionC = conversorCelsiusAfahrenheit(&celsiusAfahrenheit , celsius);
		}

	}
	else
	{
		get_Float(&fahrenheit, "Ingrese la temperatura en grados fahrenheit, entre 32 y 212 grados\n", "Error\n", 32, 212, 3)
	}



}

int get_Float(float* temperatura,char mensaje[], char mensajeError[],int minimo, int maximo, int reintentos)
{

	float buffer;
	int retorno;
	int i;

	retorno = 0;

	if(temperatura != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		i = 0;
	do
	{

		printf("%s",mensaje);
		scanf("%f",&buffer);

		if(buffer <= maximo && buffer >= minimo)
		{
			retorno = 0;
			*temperatura = buffer;
			break;
		}
		else
		{
			printf("%s",mensajeError);
			i++;
		}

	}while(i < reintentos+1);

	}

	return retorno;
}

int celsiusAfahrenheit (float* resultadoConversion , float gradosCelsius)
{
	float buffer;
	int retorno;

	retorno = 0;

	if(gradosCelsius != NULL)
	{
		buffer = (gradosCelsius * 9/5) + 32;
		*resultadoConversion = buffer;
	}

}
