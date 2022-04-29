/*
 * Nexo.h
 *
 *  Created on: 21 ene 2022
 *      Author: caand
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "Users.h"
#include "Product.h"

int printMenu(int*);

int loadProduct(eProduct* productList , int listLen , int* idProduct , eUser* userList , int userListLen);



#endif /* NEXO_H_ */
