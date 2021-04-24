///////////////////////////////////////////////////////////////////////////////
// Implementation of AVL Tree for int
// usage:
//        1) to store the list of users a person follows
//        2) to store the IDs of unregistered users so that they can be reused
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//utility function
int max(int x, int y)
{
    return (x > y) ? x : y;
}

struct AVLNode
{
    int data;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
};

typedef struct AVLNode *Node;

// check if tree is empty()
bool isEmpty(Node root)
{
    return (root == NULL) ? true : false;
}

//////////////////////////
// function: height(t)
// input: a node
// output: height of that height
int height(Node t)
{
    return (t == NULL) ? 0 : t->height;
}
/////////////////////////
// function: getBalance(t)
// input: node of which we have to calculate balance
// output: balance of the node
int getBalance(Node t)
{
    return (t == NULL) ? 0 : (height(t->left) - height(t->right));
}

//////////////////////////////
// function: InitAVLNode
// input : value of the new node
// output: a node pointer with value stored
Node InitAVLNode(int val)
{
    Node temp = NULL;
    temp = (Node)malloc(sizeof(struct AVLNode));
    temp->data = val;
    temp->height = 0;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
/////////////////////////////////
//RotateLeft (node Pivot)
// if the tree is not balanced,and heavy towards right side
Node RotateLeft(Node Pivot)
{
    Node y = Pivot->right;
    Node t2 = y->left;
    //rotation part
    y->left = Pivot;
    Pivot->right = t2;
    //new heights
    Pivot->height = max(height(Pivot->left), height(Pivot->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}
/////////////////////////////////
//RotateRight (node Pivot)
// if the tree is not balanced,and heavy towards left side
Node RotateRight(Node Pivot)
{
    Node x = Pivot->left;
    Node t2 = x->right;
    //right rotation
    x->right = Pivot;
    Pivot->left = t2;

    Pivot->height = max(height(Pivot->left), height(Pivot->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

////////////////////////////////////
//function: insert(root,val): inserts the val in the tree with given root
//input: root of tree, value to be inserted
//output: returns the tree after the insertion of the given value
Node insert(Node Root, int val)
{

    if (Root == NULL)
    {
        return createNode(val);
    }
    else if (val < Root->data)
    {
        Root->left = insert(Root->left, val);
    }
    else if (val > Root->data)
    {
        Root->right = insert(Root->right, val);
    }
    else
        return Root; // duplicate entry

    Root->height = max(height(Root->left), height(Root->right)) + 1;

    int balance = getHightBalance(Root);

    if (balance > 1 && val < Root->left->data)
        return rotateRight(Root);

    if (balance < -1 && val > Root->right->data)
        return rotateLeft(Root);

    if (balance > 1 && val > Root->left->data)
    {
        Root->left = rotateLeft(Root->left);
        return rotateRight(Root);
    }

    if (balance < -1 && val < Root->right->data)
    {
        Root->right = rotateRight(Root->right);
        return rotateLeft(Root);
    }

    return Root;
}

////////////////////////////////////////////////////////////////
//go as left as possible and get smallest number in the AVL
int findMin(Node t)
{
    Node temp = t;
    if (temp == NULL)
        return -1;
    if (temp->left == NULL)
        return temp->data;
    else
        return findMin(temp->left);
}

////////////////////////////////////////////////////////////////
//go as right as possible and get the largest number in the AVL
int findMax(Node t)
{
    Node temp = t;
    if (temp == NULL)
        return -1;
    if (temp->right == NULL)
        return temp->data;
    else
        return findMax(temp->right);
}

////////////////////////////////////////////
//Delete the entire AVL
// input: the root node
void DeleteAVL(Node root)
{
    // collapse_tree(root);
    if (root != NULL)
    {
        collapse_tree(root->left);
        collapse_tree(root->right);
        free(root);
    }
}


//////////////////////////////////////////////
// function: search(t,val)
// t-> root , val-> value to be searched
// output-> if found or not
bool search(Node t, int val)
{
    Node temp = t;

    if (temp == NULL)
        return false;
    else if (val < temp->data)
        search(temp->left, val);
    else if (val > temp->data)
        search(temp->right, val);
    else if (val == temp->data)
    {
        return true;
    }
    else
        return false;
}

////////////////////////////////////////////
// function: remove_node
// input: t->root , val->value to be deleted
// output: root of the tree after removing the value
Node remove_node(Node t, int val)
{
    if (t == NULL)
        return;
    else if (val < t->data)
    {
        t->left = remove_node(t->left, val);
    }
    else if (val > t->data)
    {
        t->right = remove_node(t->right, val);
    }
    else if (val == t->data)
    {
        if (t->right != NULL && t->left != NULL)
        {
            t->data = findMin(t->right);
            t->right = remove_node(t->right, t->data);
        }
        else if (t->right == NULL || t->left == NULL)
        {
            Node old = (t->left) ? (t->left) : t->right;
            if (old == NULL)
            {
                old = t;
                t = NULL;
            }
            else
                t = old;
            // free old node
            free(old);
        }
        else
            ;
    }

    if (t == NULL)
        return t;

    t->height = max(height(t->left), height(t->right)) + 1;
    int balance = getHightBalance(t);

    if (balance > 1 && getHightBalance(t->left) >= 0)
        return rotateRight(t);

    if (balance > 1 && getHightBalance(t->left) < 0)
    {
        t->left = rotateLeft(t->left);
        return rotateRight(t);
    }

    if (balance < -1 && getHightBalance(t->right) <= 0)
        return rotateLeft(t);

    if (balance < -1 && getHightBalance(t->right) > 0)
    {
        t->right = rotateRight(t->right);
        return rotateLeft(t);
    }

    return t;
}