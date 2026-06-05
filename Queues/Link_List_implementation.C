#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *Front = NULL;
struct Node *Rear = NULL;

int IsEmpty()
{
    if (Front == NULL)
        return 1;
    else
        return 0;
}

void Enqueue(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (Rear == NULL)
    {
        Front = Rear = newNode;
    }
    else
    {
        Rear->next = newNode;
        Rear = newNode;
    }
}

int Dequeue()
{
    if (IsEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        struct Node *temp = Front;
        int data = temp->data;
        Front = Front->next;
        free(temp);
        if (Front == NULL)
            Rear = NULL;
        return data;
    }
}

int peek()
{
    if (IsEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        return Front->data;
    }
}

int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    printf("Front element: %d\n", peek());
    printf("Dequeued element: %d\n", Dequeue());
    printf("Front element: %d\n", peek());

    return 0;
}