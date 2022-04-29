/*
 * Post.h
 *
 *  Created on: 15 dic 2021
 *      Author: caand
 */

#ifndef POST_H_
#define POST_H_

#include "input.h"
#include "nombres.h"

#define TAMMESSEGE 1500

typedef struct
{
	int idMessege;
	char postContent[TAMMESSEGE];
	int popularity;
	int userId;

}eMessege;

eMessege* newPost(void);
eMessege* newPost_parameters(char* postId , char* messege , char* popularity , char* userId);



//getters
int getPostId(eMessege* this , int* postId);
int getPopurality(eMessege* this , int* popularity);
int getUserId(eMessege* this , int* userId);
int getPostContent(eMessege* this , char* postContent);


//setters
int setPostContent(eMessege* this , char* postContent);
int setPostId(eMessege* this , int postId);
int setPopularity(eMessege* this , int popularity);
int setUserId(eMessege* this , int userId);

int orderByPostPopularity(void* elementA , void* elementB);

#endif /* POST_H_ */
