#ifndef __FriendsRecommendation_H
#define __FriendsRecommendation_H

//1. define the data structure which will store the details of the accounts of various users

// unique id for each user
// user details: city age name etc
// list of ppl the user follows

struct UserDetails             //stores the details of the Users registered on our system
{
    int UserId;
    int Age;
    char* Name;
    char* City;
    char* Organization;
};
struct System                  //Controls the entire program 
{
    int NoOfUsers;             //stores total users registered
    int NextID;                //stores what should be the ID if a new user joins
                               //BST to store the ID of the unregistered users
                               //hashmap to store the user and their ids
    // void AddNewUser()
    // {
    //     NewUser= InitUSer(NextID);
    // }
};


//2. Recommending friends
// for registered users
    //show k recommendations
    //BFS order. maintain a heirarchy of the ppl followed by friends.
// for new users
    // show top 10 recommendations based on common parameters

// 3. Friendship Status
    // check if A is a friend of B : either sets or binary search??

//4. UI : designing the user interface
//login page
//settings page
//find ppl page
//various menus


#endif
