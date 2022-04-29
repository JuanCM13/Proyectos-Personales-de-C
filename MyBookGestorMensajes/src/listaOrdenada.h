
#ifndef LISTAORDENADA_H_
#define LISTAORDENADA_H_

#include "nexo.h"

typedef struct
{
	int idPostFeed;
	char postMessege[TAMMESSEGE];
	int postPopularity;
	int userId;
	char userNick[TAMNICK];
	int userPopularity;

}eFeed;



#endif /* LISTAORDENADA_H_ */
