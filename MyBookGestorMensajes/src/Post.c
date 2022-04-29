#include "Post.h"

//------------------------------------------------------------------------------------------------------------------------------

eMessege* newPost(void)
{
	eMessege* aux;

	return aux = (eMessege*) calloc(1 , sizeof(eMessege));

}
//------------------------------------------------------------------------------------------------------------------------------

eMessege* newPost_parameters(char* postId , char* messege , char* popularity , char* userId)
{
	eMessege* aux;

	//AUXILIARES
	int postIdAux;
	char messegeAux[TAMMESSEGE];
	int popularityAux;
	int userIdAux;

	aux = NULL;

	if(postId != NULL && messege != NULL && popularity != NULL && userId != NULL)
	{
		aux = newPost();

		if(aux != NULL)
		{
			postIdAux = atoi(postId);
			popularityAux = atoi(popularity);
			userIdAux = atoi(userId);
			strncpy(messegeAux , messege , sizeof(messegeAux));

			//setters
			setPostId(aux, postIdAux);
			setPopularity(aux, popularityAux);
			setUserId(aux, userIdAux);
			setPostContent(aux, messegeAux);
		}
	}

	return aux;
}

//------------------------------------------------------------------------------------------------------------------------------

											//GETTERS
//------------------------------------------------------------------------------------------------------------------------------

int getPostId(eMessege* this , int* postId)
{
	int ret;

	ret = -1;

	if(this != NULL && postId != NULL)
	{
		ret = 0;
		*postId = this->idMessege;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------

int getPopurality(eMessege* this , int* popularity)
{
	int ret;

	ret = -1;

	if(this != NULL && popularity != NULL)
	{
		ret = 0;
		*popularity = this->popularity;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------

int getUserId(eMessege* this , int* userId)
{
	int ret;

	ret = -1;

	if(this != NULL && userId != NULL)
	{
		ret = 0;
		*userId = this->userId;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------

int getPostContent(eMessege* this , char* postContent)
{
	int ret;

	ret = -1;

	if(this != NULL && postContent != NULL)
	{
		ret = 0;
		strcpy(postContent , this->postContent);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------
															//GETTERS END
//------------------------------------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------------------------------------
															//SETTERS
//------------------------------------------------------------------------------------------------------------------------------


int setPostContent(eMessege* this , char* postContent)
{
	int ret;

	ret = -1;

	if(this != NULL && postContent != NULL)
	{
		ret = 0;
		strcpy(this->postContent , postContent);
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------

int setPostId(eMessege* this , int postId)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->idMessege = postId;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------

int setPopularity(eMessege* this , int popularity)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->popularity = popularity;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------

int setUserId(eMessege* this , int userId)
{
	int ret;

	ret = -1;

	if(this != NULL)
	{
		ret = 0;
		this->userId = userId;
	}

	return ret;
}

//------------------------------------------------------------------------------------------------------------------------------
												// SETTERS END
//------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------------------

int orderByPostPopularity(void* elementA , void* elementB)
{
	int ret;

	eMessege* firstElement;
	eMessege* secondElement;
	int popularityFirstElement;
	int popularitySecondElement;

	ret = 0;

	if(elementA != NULL && elementB != NULL)
	{
		firstElement = (eMessege*) elementA;
		secondElement = (eMessege*) elementB;

		getPopurality(firstElement, &popularityFirstElement);;
		getPopurality(secondElement, &popularitySecondElement);
		if(popularityFirstElement < popularitySecondElement)
		{
			ret = 1;
		}
		else
		{
			if(popularityFirstElement > popularitySecondElement)
			{
				ret = -1;
			}
		}
	}

	return ret;
}
