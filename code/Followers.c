/////////////////////////////////////////////////////////////////////////////////
// linked lists to store the followers of user A
// purpose: in case user A decides to unregister,we can go to all followers
//          and remove A from their list

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Followers_
{
    int data;
    struct node *next;
};
typedef struct Followers_* Followers;