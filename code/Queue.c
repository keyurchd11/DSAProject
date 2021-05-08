#include <stdio.h>
#include <stdlib.h>

struct Q_Node
{
    int data;
    struct Q_Node *Next;
};
typedef struct Q_Node *QNode;
struct Q_
{
    struct Q_Node *Front;
    struct Q_Node *Rear;
    int size;
};
typedef struct Q_ *Queue;

QNode InitQNode(int val)
{
    QNode newNode=(QNode)malloc(sizeof(struct Q_Node));
    newNode->data=val;
    newNode->Next=NULL;
}
Queue InitQ()
{
    Queue newQ = (Queue)malloc(sizeof(struct Q_));
    newQ->Front = NULL;
    newQ->Rear = NULL;
    newQ->size = 0;
    return newQ;
}
Queue Enque(Queue q, int value)
{
    QNode newNode = InitQNode(value);
    if (q->size == 0)
    {
        q->Rear = newNode;
        q->Front = newNode;
        q->size = 1;
        return q;
    }
    q->Rear->Next = newNode;
    q->Rear = q->Rear->Next;
    q->size++;
    return q;
}
Queue Deque(Queue q)
{
    if (q->size == 0)
        return q;
    QNode temp = q->Front;
    q->Front = q->Front->Next;
    free(temp);
    if (q->size == 1)
    {
        q->Rear = NULL;
    }
    q->size--;
    return q;
}
