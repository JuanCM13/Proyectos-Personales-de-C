/*
 * Product.h
 *
 *  Created on: 25 ene 2022
 *      Author: caand
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_

#include "input.h"
#include "nombres.h"

#define TAMNOMBREPRODUCTO 100

typedef struct
{
	int idRelation;
	int idProduct;
	char nombre[TAMNOMBREPRODUCTO];
	float precio;
	int stock;
	int isEmpty;
}eProduct;

int initProductArray(eProduct* productList , int listLen);
int getFreeIndexProduct(eProduct* productList , int listLen);

eProduct generateProduct(void);

#endif /* PRODUCT_H_ */
