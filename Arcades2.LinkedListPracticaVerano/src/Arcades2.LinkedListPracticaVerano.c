 /*
 ============================================================================
 Name        : LinkedListPracticaVerano.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Informes.h"

int main(void) {

	setbuf(stdout, NULL);
	int option;
	int flagControlArcades = 0;
	int flagControlSonido = 0;
	char controlSalida;

	LinkedList* listaArcades;
	LinkedList* listaSonido;

	listaArcades = ll_newLinkedList();
	listaSonido = ll_newLinkedList();

	if(listaArcades != NULL && listaSonido != NULL)
	{
		controlSalida = 's';
		do
		{
			imprimirMenu(&option);

			switch(option)
			{
				case 1:
					if(flagControlArcades == 0)
					{
						optionOne(listaArcades, &flagControlArcades);
					}
					else
					{
						printf("Error, usted ya ha cargado un archivo de tipo Arcades en el sistema...\n");
					}
				break;
				case 2:
					if(flagControlSonido == 0)
					{
						optionTwo(listaSonido, &flagControlSonido);
					}
					else
					{
						printf("Error, usted ya ha cargado un archivo de tipo Sonido en el sistema...\n");
					}
				break;
				case 3:
					if(flagControlArcades == 1 && flagControlSonido == 1)
					{
						optionThree(listaArcades);
					}
					else
					{
						printf("Error, debe haber cargado las primeras 2 opciones para ingresar");
					}
				break;
				case 4:
					if(flagControlArcades == 1 && flagControlSonido == 1)
					{
						optionFour(listaArcades, listaSonido);
					}
					else
					{
						printf("Error, debe haber cargado las primeras 2 opciones para ingresar");
					}
				break;
				case 5:
					if(flagControlArcades == 1 && flagControlSonido == 1)
					{
						optionFive(listaArcades, listaSonido);
					}
					else
					{
						printf("Error, debe haber cargado las primeras 2 opciones para ingresar");
					}
				break;
				case 6:
					if(flagControlArcades == 1 && flagControlSonido == 1)
					{
						optionSix(listaArcades, listaSonido);
					}
					else
					{
						printf("Error, debe haber cargado las primeras 2 opciones para ingresar");
					}
				break;
				case 7:
					if(flagControlArcades == 1 && flagControlSonido == 1)
					{
						optionSeven(listaArcades, listaSonido);
					}
					else
					{
						printf("Error, debe haber cargado las primeras 2 opciones para ingresar");
					}
				break;
				case 8:
					if(flagControlArcades == 1 && flagControlSonido == 1)
					{
						optionEight(listaArcades, listaSonido);
					}
					else
					{
						printf("Error, debe haber cargado las primeras 2 opciones para ingresar");
					}
				break;
				case 9:
					if(flagControlArcades == 1 && flagControlSonido == 1)
					{
						optionNine(listaArcades, listaSonido);
					}
					else
					{
						printf("Error, debe haber cargado las primeras 2 opciones para ingresar");
					}
				break;
				case 10:
					if(flagControlArcades == 1 && flagControlSonido == 1)
					{
						optionTen(listaArcades, listaSonido);
					}
					else
					{
						printf("Error, debe haber cargado las primeras 2 opciones para ingresar");
					}
				break;
				case 11:
					if(QueresSeguir("Seguro que desea finalizar el programa? s/n") == 0)
					{
						controlSalida = 'n';
					}
				break;
			}
		}while(controlSalida != 'n');
	}

	printf("--------------------PROGRAMA TERMINADO");
}
