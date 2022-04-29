/*
 ============================================================================
 Name        : ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 51

typedef struct
{

	int cantidadGoles;
	int cantidadPartidos;
	char nombreJugador[TAM];
	float promedioGoles;
}eJugadores;

void cargar_datos(eJugadores*, int);
int get_int(char[]);
int get_string(char[], char[], char[], int);
int funcion_mostrarEstructura(eJugadores);

int main(void)
{
	setbuf(stdout , NULL);
	eJugadores jugadorUno;

	cargar_datos(&jugadorUno , TAM);

	//printf("la cantidad de goles de jugadorUno son: %d\n",jugadorUno.cantidadGoles);

	funcion_mostrarEstructura(jugadorUno);
	return EXIT_SUCCESS;
}

void cargar_datos(eJugadores* jugador, int cantidadCaracteresArray)
{
	jugador->cantidadGoles = get_int("Ingrese la cantidad de goles del jugador..");
	//printf("la cantidad de goles de jugadorUno son: %d\n",jugador -> cantidadGoles);
	jugador->cantidadPartidos = get_int("Ingrese la cantidad de partidos jugados..");
	if(get_string("Ingrese el nombre del jugador..","Error, el nombre es muy largo..", jugador->nombreJugador , cantidadCaracteresArray) != 0)
	{
		printf("No se pudo cargar el nombre..\n");
	}

	if(get_promedio(jugador->promedioGoles, jugador->cantidadGoles , jugador->cantidadPartidos) != 0)
	{

	}
}

int get_int(char mensaje[])
{
	int buffer;

	if(mensaje != NULL)
	{
		printf("%s\n",mensaje);
		scanf("%d",&buffer);
	}

	return buffer;
}

int get_string(char mensaje[], char mensajeError[], char string[], int maximoCaracteres)
{
	int retorno = -1;
	char buffer[10000];

	do
	{
		printf("%s\n",mensaje);
		fflush(stdin);
		fgets(buffer, sizeof(buffer) , stdin);

		if(strlen(buffer) < maximoCaracteres)
		{
			strcpy(string , buffer);
			retorno = 0;
			break;
		}

		printf("%s\n",mensajeError);

	}while(1);

	return retorno;
}

int funcion_mostrarEstructura(eJugadores jugador)
{
	printf("El nombre del jugador a verificar es: %s\n",jugador.nombreJugador);
	printf("La cantidad de goles del jugador son: %d\n" , jugador.cantidadGoles);
	printf("La cantidad de partidos jugados fue de: %d\n",jugador.cantidadPartidos);
	if(jugador.promedioGoles > 0)
	{
		printf("El promedio de goles fue de: %.2f\n",jugador.promedioGoles);
	}
	else
	{
		printf("El promedio de goles es de cero o no se pudo calcular..\n");
	}
}

int get_promedio(float* resultado , int acumulador , int divisor)
{
	float buffer;
	int bandera;
	int retorno;

	retorno = -1;
	bandera = 0;

	if(resultado != NULL && divisor > 0)
	{
		bandera = 1;
		buffer = (float)acumulador / divisor;
	}

	if(bandera > 0)
	{
		*resultado = buffer;
		retorno = 0;
	}

	return retorno;
}
