/*
 ============================================================================
 Name        : primerProyectoEclipse.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	setbuf(stdout,NULL);

	int jose;
	char jorge;
	float pepe;

	printf("Ingresate un numero: \n");
	scanf("%d",&jose);

	printf("Ingresate una letra: \n");
	fflush(stdin);
	scanf("%c",&jorge);

	printf("la letra es: %c\n",jorge);

}
