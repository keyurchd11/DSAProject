
// linked list template

// Basically we may use to store all the  followers of a id..
// eg. B is a friend A
// So, it helps to remove the user(B) from the friend list form another user(A).. when an user(B) unregister 

// code consist:  
/* 1. innitializing a linked list.
   2.adding elements to the intialized list.
   3.deleting an element from the list.
   4. printing the lsit. */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node Node;
typedef struct node *link;

Node *createTerm()
{
    Node *P;
    P = (struct node *)malloc(sizeof(struct node));
    assert(P != NULL);
    P->next = NULL;
    return P;
}

void AddData(link P, int data)
{
    link temp;
    while (P->next != NULL)
    {
        P = P->next;
    }
    if (P->next == NULL)
    {
        temp = createTerm();
        temp->data = data;
        P->next = temp;
    }
}

void Delete(link P, int data) // delet is pending
{
    link prev;
    while (P->next != NULL && P->next->data != data)
    {
        prev = P->next;
        P = P->next;
    }

    if (P->next == NULL)
    {
        printf("%d -->ID DOES NOT EXIT\n", data);
    }
    else
    {

        prev = P->next;
        P->next = P->next->next;
        free(prev);
        printf("%d sucessfully deleted\n", data);
    }
}
void Display(link P)
{
    link temp = P->next;
    if (temp == NULL)
    {
        printf("empty list");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main()
{

    Node *head, *Newnode, *temp;
    link T;
    T = createTerm();
    AddData(T, 4);
    AddData(T, 14);
    AddData(T, 24);
    AddData(T, 45);
    AddData(T, 43);
    AddData(T, 67);
    AddData(T, 84);
    Display(T);
    Delete(T, 45);
    Delete(T, 45);
    Delete(T, 4);
    Display(T);
}
