/*
 * Controller.h
 *
 *  Created on: 22 ene 2022
 *      Author: caand
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Nexo.h"

int controller_loadUsers(eUser* userList , int userListLen , int* userId);
int controller_loadProduct(eProduct* productList , int productListLen , int* productId , eUser* userList, int userLen);

int controller_modUser(eUser* userList , int userListLen);



#endif /* CONTROLLER_H_ */
