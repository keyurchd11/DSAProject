
#include "string_hashing.c"
#include <stdio.h>
#include <stdlib.h>

/* Hyerabad                Mumbai             chennai            Kolkota           Delhi

    1,5,10                  44,55               21,88,101         99,77             255,355
    2,6,11                  22,19.21            111
*/

#define size 101

void PrintTree(Node Q)
{
    if (Q == NULL)
        return;
    else
    {
        PrintTree(Q->left);
        printf("%d\n", Q->data);

        PrintTree(Q->right);
    }
}

int main()
{
    Hash_table H;
    H = init_hash(101);

    Insert_string(H, "hyderabad", 5);
    Insert_string(H, "hyderabad", 2);
    Insert_string(H, "hyderabad", 1);
    Insert_string(H, "hyderabad", 10);
    Insert_string(H, "hyderabad", 6);
    Insert_string(H, "hyderabad", 11);
    Insert_string(H, "Mumbai", 44);

    string_node Q = Find_in_string(H, "hyderabad");
    printf("%s: \n",Q->string_name);
    printf("%d\n",Q->root->data);
    PrintTree(Q->root);
}
