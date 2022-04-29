/*
 * eLibros.h
 *
 *  Created on: 24 nov 2021
 *      Author: caand
 */

#ifndef ELIBROS_H_
#define ELIBROS_H_
#define TAMNOMBRELIBRO 100
#define TAMNOMBREAUTOR 50

#include "input.h"


typedef struct
{
	int id;
	char titulo[TAMNOMBRELIBRO];
	char autor[TAMNOMBREAUTOR];
	float precio;
	int idEditorial;

}eLibro;

//----------------------------------------------------

/** \brief Crea un nuevo eLibro en memoria de manera dinamica
 *
 *  \param void
 *  \return eLibro* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
eLibro* newBook(void);

//----------------------------------------------------

eLibro* newBookParameters(char* id , char* titulo , char* autor , char* precio , char*idEditorial);

int setBookId(eLibro* this , int id);
int setBookidEditorial(eLibro* this , int idEditorial);
int setBookPrecio(eLibro* this , float precio);
int setBookTitulo(eLibro* this , char* titulo);
int setBookAutor(eLibro* this , char* autor);

int getBookId(eLibro* this , int* id);
int getBookIdEditorial(eLibro* this , int* idBookEditorial);
int getBookPrice(eLibro* this , float* bookPrice);
int getBookTitle(eLibro* this , char* bookName);
int getBookAuthor(eLibro* this , char* bookAuthor);

int ordenarPorAutor(void* elementoUno , void* elementoDos);


int funcionDescuentoPorEditorial(void* pElement);

int filtroEditorial(void* pElement);

#endif /* ELIBROS_H_ */
