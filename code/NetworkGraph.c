// We store the followers and following list of a user in this graph
// We make a hashmap of users using separate chaining. In each node of the
// chain, the UserID,followers and following list is present

#include<stdlib.h>
#include "DSA_Project.h"
#include "AVL.c"
#include "Followers.c"

/////////////////////////////////////////////////////////////////////////////
// structure   : User
// data stored : UserID, following&followers list, ptr to next node
struct User
{
    // the unique ID of the user for whom the data is being stored
    int UserID;

    //a linked list which stores all followers of the user
    Followers Follower;

    //an AVL which stores all users follower by the user
    Node Friend;

    // pointer to next node in separate chaining
    struct User *NextUser;
};

/////////////////////////////////////////////////////////////////////////////
//HashMap for storing the Graph
#define GraphHTSize 10000
struct User *GraphHT[GraphHTSize];


/////////////////////////////////////////////////////////////////////////////
// function : InitGraphHT()
// result   :Initialise all ptrs in hashmap to NULL
void InitGraphHT()
{
    for (int i = 0; i < GraphHTSize; i++)
        GraphHT[i] = NULL;
}


/////////////////////////////////////////////////////////////////////////////
// function: GraphHashFunction
// input   : ID of the user for whom hash key is to be found
// output  : the hash key corresponding to the UserID
int GraphHashFunction(int UserID)
{
    return UserID % GraphHTSize;
}


/////////////////////////////////////////////////////////////////////////////
// function: InsertInGraph
// input   : UserID of the user to be inserted in the graph
// result  : a new node corresponding to the UserID is created at that hash key
//           it can store the list of friends and followers
void InsertInGraphHT(int UserID)
{
    int HashKey = GraphHashFunction(UserID);
    struct User *NewNode = (struct User *)malloc(sizeof(struct User));
    NewNode->NextUser = NULL;
    NewNode->UserID = UserID;
    NewNode->Friend=NULL;
    NewNode->Follower=NULL;
    if (GraphHT[HashKey] == NULL)
    {
        GraphHT[HashKey] = NewNode;
    }
    else
    {
        struct User *Walk = GraphHT[HashKey];
        while (Walk->NextUser != NULL)
        {
            Walk = Walk->NextUser;
        }
        Walk->NextUser = NewNode;
    }
}


/////////////////////////////////////////////////////////////////////////////
// function : GetUser(UserID)
// input    : UserID for which we have to get node
// Output   : pointer to the side chain node corresponding to the UserID
struct User *GetUser(int UserID)
{
    int HashKey = GraphHashFunction(UserID);
    struct User *UserPtr = GraphHT[HashKey];
    if (UserPtr->UserID == UserID)
    {
        return UserPtr;
    }
    else
    {
        while (UserPtr->UserID != UserID)
        {
            UserPtr = UserPtr->NextUser;
        }
        return UserPtr;
    }
}


/////////////////////////////////////////////////////////////////////////////
// function : DeleteUser(UserID)
// input    : UserID of the user who is unregistering
// result   : Remove the user from following list of all followers
//            Delete side chain node corresponding to the unregistering user
void DeleteUser(int UserID)
{
    int HashKey = GraphHashFunction(UserID);
    struct User *Walk = GraphHT[HashKey];
    if (Walk->UserID == UserID)
    {
        //change the AVL of others
        //delete the node
    }
}


//////////////////////////////////////////////////////////////////////////////
// function : AddFriend(ID1,ID2)
// input    : unique ID corresponding to the 2 users
// result   : adds user2 in following list of user1
//            adds user 1 in followers list of user2
void AddFriend(int UserID1,int UserID2)
{
    struct User* User1=GetUser(UserID1);
    insert(User1->Friend,UserID2);
    struct  User* User2= GetUser(UserID2);
    Followers NewNode=NULL;
    NewNode=(Followers)malloc(sizeof(struct Followers_));
    NewNode->data=UserID1;
    NewNode->next=User2->Follower;
    User2->Follower=NewNode;
}