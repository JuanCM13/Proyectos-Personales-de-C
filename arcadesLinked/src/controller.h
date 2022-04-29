

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Nexo.h"
#include "parser.h"

#define TAMARCHIVO 100

int controller_readArcadesCsv(LinkedList* this);
int controller_readSoundCsv(LinkedList* this);


int controller_loadNewArcade(LinkedList* this);
int controller_saveAsText(LinkedList* pArrayListArcades);


int controller_mostrarArcade(LinkedList* listaArcades , LinkedList* listaSonido);
int controller_modificarArcade(LinkedList* listaArcades , LinkedList* listaSonido);
int controller_eliminarArcade(LinkedList* listaArcades , LinkedList* listaSonido);
int controller_ordenarListaArcadesAscendentemente(LinkedList* listaArcades , LinkedList* listaSonido);
int controller_generarArchivoJuegos(LinkedList* listaArcades);
int controller_generarListaMultijugadores(LinkedList* listaArcades , LinkedList* listaSonido);
int controller_duplicarFichas(LinkedList* listaArcades , LinkedList* listaSonido);


#endif /* CONTROLLER_H_ */
