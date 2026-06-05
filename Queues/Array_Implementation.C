#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

int IsFull()
{
    if (rear == MAX - 1)
        return 1;
    else
        return 0;
}


int IsEmpty()
{
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

void Push(int data)
{
    if (IsFull())
    {
        printf("Queue is full\n");
    }
    else
    {
        rear++;
        queue[rear] = data;
        if (front == -1)
        {
            front = 0;
        }
    }
}

int Pop()
{
    int data;
    if (IsEmpty())
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        data = queue[front];
        front++;
        return data;
    }
}

int main()
{

        Push(10);
        Push(20);
        Push(30);
        printf("Popped element: %d\n", Pop());
        printf("Popped element: %d\n", Pop());
        
    return 0;
}