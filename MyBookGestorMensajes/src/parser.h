  /*
 * parser.h
 *
 *  Created on: 2 nov. 2021
 *      Author: caand
 */

#ifndef PARSER_H_
#define PARSER_H_

#define ESPACIOCONTADORID 100

#include "listaOrdenada.h"

int parser_postsFromText(FILE* pFile , LinkedList* pArrayListPosts);
int parser_usersFromText(FILE* pFile , LinkedList* pArrayListUsers);


int controlPostParameters(char* auxPostId , char* auxUserId , char* auxPopularity);
int controlUserParameters(char* userId, char* userNick, char* userPopularity);


#endif /* PARSER_H_ */
