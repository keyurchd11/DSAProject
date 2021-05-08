#ifndef __MENU_C
#define __MENU_C

#include <stdlib.h>
#include <stdio.h>
#include "GUI.c"
#include <stdio.h>
#include "NetworkGraph.c"
// #include "UsersList.h"
#include "UsersList.c"
// #include "Followers.c"
#include "mybfs.c"
// #include "AVL.c"
#include "GUI.c"
#include "Menu.c"

struct System //Controls the entire program
{
    int NoOfUsers;        //stores total users registered
    int NextID;           //stores what should be the ID if a new user joins
    Node UnregisteredIDs; //BST to store the ID of the unregistered users
    int NoOfUnregisteredUsers;
    Hash *Users; //hashmap to store the user and their ids
};
struct System *Control;

void WelcomePage();
int MenuPage();
void AddNewUser();
void DisplayUserDetails();
void MakeFriends();

void DisplayUserDetails()
{
    system("clear");
    border_with_delay();
    gotoxy(23, 4);
    blueBG("IIIT-H Friends Recommendation System");
    MidBox();
    gotoxy(30, 7);
    printYellow("View Details of an user");
    gotoxy(17, 9);
    printWhite("Enter the User ID of the user: ");
    int UserId;
    scanf("%d", &UserId);
    char BufferCleaner;
    scanf("%c", &BufferCleaner);
    PtrToUser CurrUser = NULL;
    CurrUser = SearchUser(Control->Users, UserId);
    if (CurrUser == NULL)
    {
        gotoxy(17, 10);
        printRed("WARNING!!!");
        gotoxy(17, 11);
        printRed("No user found in database with given UserID");
    }
    else
    {
        gotoxy(17, 10);
        printWhite("1. User's Name         : ");
        printWhite(CurrUser->Name);
        gotoxy(17, 11);
        printWhite("2. User's Age          : ");
        printf("%d", CurrUser->Age);
        gotoxy(17, 12);
        printWhite("3. User's Organisation : ");
        printWhite(CurrUser->Organization);
        gotoxy(17, 13);
        printWhite("4. User's City         : ");
        printWhite(CurrUser->City);
    }
    gotoxy(30, 18);
    printWhite("Click [ENTER] to continue");
    char Option = 'a';
    while (Option != 10)
    {
        printf("\e[38;2;0;0;0m");
        gotoxy(30, 17);
        scanf("%c", &Option);
    }
    system("clear");
}
/////////////////////////////////////////////////////////////////////////////
// function: main
// purpose : controls the entire working of the project
int main(void)
{
    Control = (struct System *)malloc(sizeof(struct System));
    Control->NoOfUsers = 0;
    Control->NextID = 1;
    Control->NoOfUsers = 0;
    Control->Users = (Hash *)malloc(100 * sizeof(Hash));
    InitGraphHT();
    WelcomePage();
    int Option = 'K';
    while (Option != 10)
    {
        while (Option > 10 || Option < 1)
        {
            system("clear");
            Option = MenuPage();
        }
        if (Option == 1)
            AddNewUser();
        else if (Option == 2)
            DisplayUserDetails();
        else if (Option == 3)
            MakeFriends();
        else if(Option==4)
        {

        }

        Option = -1;
    }
    gotoxy(0, 24);
}

/////////////////////////////////////////////////////////////////////////////
// function: MakeFriends()
// purpose : Make user1 follow user2
void MakeFriends()
{
    int User1, User2;
    system("clear");
    border_with_delay();
    gotoxy(23, 4);
    blueBG("IIIT-H Friends Recommendation System");
    MidBox();
    gotoxy(30, 7);
    printYellow("Make User1 follow User2");
    gotoxy(17, 9);
    printWhite("Enter the UserID of User1 : ");
    scanf("%d", &User1);
    gotoxy(17,10);
    printWhite("Enter the UserID of User2 : ");
    scanf("%d", &User2);
    AddFriend(User1, User2);
}

/////////////////////////////////////////////////////////////////////////////
// function: WelcomePage()
// purpose : Displays the welcome page
void WelcomePage()
{
    char Option = 'a';
    system("clear");
    border_with_delay();
    gotoxy(12, 13);
    printWhite("Team 55:");
    gotoxy(22, 13);
    printWhite("Nandini Reddy (2020101038)");
    gotoxy(22, 14);
    printWhite("Rohit Lingala (2020102035)");
    gotoxy(22, 15);
    printWhite("Harshavardhan (2020101106)");
    gotoxy(22, 16);
    printWhite("Surya Teja    (2020101042)");
    gotoxy(22, 17);
    printWhite("Keyur Ganesh  (2020101100)");
    gotoxy(22, 20);
    printWhite("Click [ENTER] to continue....");
    gotoxy(17, 4);
    blueBG("Welcome to IIIT-H Friends Recommendation System");
    gotoxy(52, 20);
    while (Option != 10)
        scanf("%c", &Option);
    //exiting the program with cmd line down
}

/////////////////////////////////////////////////////////////////////////////
// function: WelcomePage()
// purpose : Displays the initial menu
// output  : Option selected by the user
int MenuPage()
{
    system("clear");
    border_with_delay();
    gotoxy(23, 4);
    blueBG("IIIT-H Friends Recommendation System");
    MidBox();
    gotoxy(38, 7);
    printYellow("MENU");
    gotoxy(17, 9);
    printWhite("1. Add New User");
    gotoxy(17, 10);
    printWhite("2. Get Details of a User from UserID");
    gotoxy(17, 11);
    printWhite("3. Make Friends");
    gotoxy(17, 12);
    printWhite("4. Show Friends of a User");
    gotoxy(17, 13);
    printWhite("5. Show Friends Recommendation for a User");

    gotoxy(17, 18);
    printWhite("Your Option: ");

    int Option = 'a';
    scanf("%d", &Option);
    return Option;
}

/////////////////////////////////////////////////////////////////////////////
// function: AddNewUser()
// purpose : provides the GUI for registering a new user
// outcome : a new user is added the hash table defined in UserList.c file
void AddNewUser()
{
    system("clear");
    border_with_delay();
    gotoxy(23, 4);
    blueBG("IIIT-H Friends Recommendation System");
    MidBox();
    gotoxy(38, 7);
    printYellow("Add a new user");
    gotoxy(17, 9);
    printWhite("1. User's Name         : ");
    gotoxy(17, 10);
    printWhite("2. User's Age          : ");
    gotoxy(17, 11);
    printWhite("3. User's Organisation : ");
    gotoxy(17, 12);
    printWhite("4. User's City         : ");
    int NewUserID = 0, Age = 0;
    char Name[32], City[20], Organization[30];
    gotoxy(42, 9);
    scanf("%s", Name);
    gotoxy(42, 10);
    scanf("%d", &Age);
    gotoxy(42, 11);
    scanf("%s", Organization);
    gotoxy(42, 12);
    scanf("%s", City);

    if (Control->NoOfUnregisteredUsers != 0)
    {
        NewUserID = findMin(Control->UnregisteredIDs);
        Control->NoOfUnregisteredUsers--;
    }
    else
    {
        NewUserID = Control->NextID;
    }
    RegisterNewUser(Control->Users, NewUserID, Age, Name, City, Organization);
    Control->NoOfUsers++;
    Control->NextID++;
    InsertInGraphHT(NewUserID);
}

#endif