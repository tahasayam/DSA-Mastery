#include <stdio.h>
#include <stdlib.h>
#define MAX 4
int Arr_Stack[MAX];
int top = -1;

// Note:  if max is 4 then last index will be 3, so we have to check top<MAX-1 for stack overflow

// IsFull function to check if the stack is full
int IsFull()
{
    if (top == MAX - 1)
    {

        return 1;
    }
    return 0;
}

// IsEmpty function to check if the stack is empty
int IsEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

//  Push function to add an element to the stack
void push(int data)
{
    if (IsFull())
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    Arr_Stack[top] = data;
}

// Pop function to remove an element from the stack

int pop()
{
    int value;
    if (IsEmpty())
    {
        printf("Stack underflow\n");
        return 0; // failure
    }

    return value = Arr_Stack[top--];
}
int peek(){
    if (IsEmpty())
    {
        printf("Stack underflow\n");
        return 0; // failure
    }

    return Arr_Stack[top];
}

main()
{
    int value;
    push(1);
    push(2);
    push(3);
    push(4);
    // push(5); // overflow

    printf("Top element: %d\n", peek()); // should return 4
    printf("Popped value: %d\n", pop()); 
    printf("Popped value: %d\n", pop()); 
    printf("Top element: %d\n", peek()); // should return 2
     printf("Popped value: %d\n", pop()); 
    
}