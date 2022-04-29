

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "parser.h"

#define TAMARCHIVO 100

int controller_readPostFile(LinkedList* this);
int controller_readUserFile(LinkedList* this);

int controller_printPosts(LinkedList* postList , LinkedList* userList);
int controller_printPriority(LinkedList* postList , LinkedList* userList);

int generateFeedFile(LinkedList* listaUsuarios , LinkedList* listaPosts , LinkedList* listaFeed);


#endif /* CONTROLLER_H_ */
