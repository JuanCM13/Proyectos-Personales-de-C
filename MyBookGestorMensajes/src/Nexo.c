#include "Nexo.h"

//---------------------------------------------------------------------------------------------------------------------------------

int showPosts(LinkedList* postList , LinkedList* userList)
{
	int ret;
	int i;
	int postsLen;

	eMessege* postAux;
	int auxUserId;

	eUser* userAux;

	ret = -1;

	if(postList != NULL && userList != NULL)
	{
		postsLen = ll_len(postList);

		printf("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
		printf("|ID                        POST CONTENT                                                                POPU       USID       USER NICK            FOLLOWERS                 |\n");
		printf("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
		for(i=0 ; i<postsLen ; i++)
		{
			//printf("Entre..\n");
			postAux = ll_get(postList, i);
			getUserId(postAux, &auxUserId);

			userAux = findUserById(userList, auxUserId);
			if(userAux != NULL)
			{
				ret = 0;
				printPostsInfo(postAux , userAux);
			}
		}
		printf("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------

int printPostsInfo(eMessege* messege , eUser* user)
{
	int ret;

	//Messege info
	int idMessege;
	char postCont[TAMMESSEGE];
	int postPopularity;


	//Post info
	int userId;
	char userNick[TAMNICK];
	int userFollowers;

	ret = -1;

	if(messege != NULL && user != NULL)
	{
		ret = 0;

		getPostId(messege, &idMessege);
		getPostContent(messege, postCont);
		getPopurality(messege, &postPopularity);

		getIdUser(user, &userId);
		getUserNick(user, userNick);
		getUserPopularity(user, &userFollowers);

		printf("|%-10d %-90s %-10d %-10d %-20s %-25d |\n",idMessege,postCont,postPopularity,userId,userNick,userFollowers);
		printf("|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------------
