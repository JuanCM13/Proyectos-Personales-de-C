 /*
 ============================================================================
Mendez juan cruz div 1-c
40423224
Laboratorio 1 Parcial 2
 ============================================================================
 */

#include "LinkedList.h"
#include "nexo.h"
#include "controller.h"
#include "input.h"

#define LIBROS "MOCK_DATA-_2_.csv"
#define EDITORIALES "Editoriales.csv.csv"

int main(void)
{
	setbuf(stdout , NULL);
	int opcionMenu;
	int respuestaCargaLibros;
	int respuestaCargaEditoriales;
	int banderaControlLibros;
	int banderaControlEditoriales;
	int respuestaGenerarListaMinotauro;

	LinkedList* listaLibros;
	LinkedList* listaEditoriales;

	listaLibros = ll_newLinkedList();
	listaEditoriales = ll_newLinkedList();

	if(listaLibros != NULL && listaEditoriales != NULL)
	{
		banderaControlLibros = 0;
		banderaControlEditoriales = 0;

		do
		{
			imprimirMenu(&opcionMenu);

			switch(opcionMenu)
			{
				case 1:

					if(banderaControlLibros == 0)
					{
						respuestaCargaLibros = controller_loadBooksFromText(listaLibros);
						switch(respuestaCargaLibros)
						{
							case 0:

								banderaControlLibros = 1;
								printf("La carga de libros fue exitosa..\n");

							break;
							case -1:

								printf("Algo fallo con la carga, reintente..\n");

							break;
							case -2:

								printf("La carga de libros fallo, uno de los datos de algun libro esta mal ingresado..\n");

							break;
							case -3:

								printf("No se logro conseguir espacio para cargar la lista, reintente..\n");

							break;
							case -4:

								printf("No se encontro ese archivo, reintente..\n");

							break;

						}
					}
					else
					{
						printf("El archivo ya fue cargado, reinicie el programa para volver a cargarlo..\n");
					}

				break;

				case 2:

					if(banderaControlEditoriales == 0)
					{
						respuestaCargaEditoriales = controller_loadEditorialsFromText(listaEditoriales);
						switch(respuestaCargaEditoriales)
						{
							case 0:

								banderaControlEditoriales = 1;
								printf("La carga de editoriales fue exitosa..\n");

							break;
							case -1:

								printf("Algo fallo con la carga, reintente..\n");

							break;
							case -2:

								printf("La carga de editoriales fallo, uno de los datos de alguna editorial esta mal ingresado..\n");

							break;
							case -3:

								printf("No se logro conseguir espacio para cargar la lista, reintente..\n");

							break;
							case -4:

								printf("No se encontro ese archivo, reintente..\n");

							break;

						}
					}
					else
					{
						printf("El archivo de editoriales ya fue cargado, reinicie el programa para volver a cargarlo..\n");
					}

				break;

				case 3:

					if(banderaControlLibros == 1 && banderaControlEditoriales == 1)
					{
						if(controller_organizeAutors(listaLibros) == 0)
						{
							printf("La lista se ordeno de manera exitosa..\n");
						}
						else
						{
							printf("Fallo el ordenamiento de la lista..\n");
						}
					}
					else
					{
						printf("No se puede ingresar a esta opcion sin antes cargar ambos archivos (libros y editoriales).. \n");
					}

				break;

				case 4:

					if(banderaControlLibros == 1 && banderaControlEditoriales == 1)
					{
						if(controller_printBooks(listaLibros , listaEditoriales) != 0)
						{
							printf("Algo fallo al mostrar la lista, reintente..\n");
						}
					}
					else
					{
						printf("No se puede ingresar a esta opcion sin antes cargar ambos archivos (libros y editoriales).. \n");
					}

				break;

				case 5:

					if(banderaControlLibros == 1 && banderaControlEditoriales == 1)
					{
						respuestaGenerarListaMinotauro = controller_generateMinotauroList(listaLibros , listaEditoriales);
						switch(respuestaGenerarListaMinotauro)
						{
							case 0:

								printf("La lista de libros de editorial Minotauro fue generada con exito..\n");
								printf("Podra encontrar el archivo con el siguiente nombre:  %s\n",NOMBREARCHIVOMINOTAURO);

							break;
							case 1:

								printf("Podra encontrar el archivo con el siguiente nombre:  %s\n",NOMBREARCHIVOMINOTAURO);

							break;
							case -1:

								printf("Algo salio mal al generar la lista, reintente.. \n");

							break;
							case -2:

								printf("Fallo el guardado del archivo, reintente..\n");

							break;
						}
					}
					else
					{
						printf("No se puede ingresar a esta opcion sin antes cargar ambos archivos (libros y editoriales).. \n");
					}

				break;

				case 6:

					if(controllerDescount(listaLibros , listaEditoriales) == 0)
					{
						printf("La lista fue generada con exito..\n");
					}
					else
					{
						printf("Algo fallo con el calculo..\n");
					}

				break;

			}

		}while(opcionMenu != 7);
	}


	printf("\n\n\n-------------------------------------PROGRAMA TERMINADO---------------------------------------------------------");

	return 0;
}
