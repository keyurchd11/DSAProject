#ifndef _FRIENDS
#define _FRIENDS

#define M 100003

typedef struct UserDetails UserDetails;
typedef UserDetails* PtrToUser;
typedef UserDetails* Hash;

struct UserDetails             //stores the details of the Users registered on our system
{
    int UserId;
    int Age;
    char* Name;
    char* City;
    char* Organization;
    PtrToUser Next;
    //int* Table;
};
struct System                  //Controls the entire program 
{
    int NoOfUsers;             //stores total users registered
    int NextID;                //stores what should be the ID if a new user joins
                               //BST to store the ID of the unregistered users
                               //hashmap to store the user and their ids
};

int HashFn(int X);
PtrToUser InitUserNode(int UserID , int Age , char* UserName , char* UserCity , char* UserOrganization);
void RegisterNewUser(Hash UsersList[] , int UserID , int Age , char* UserName , char* UserCity , char* UserOrganization);
PtrToUser SearchUser(Hash UsersList[] , int UserID);
void UnregisterUser(Hash UsersList[] , int UserID);


#endif