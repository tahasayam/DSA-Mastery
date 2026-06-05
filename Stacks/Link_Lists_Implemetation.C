// ----------------------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------------------------------------

// Q: Why link list Pressentation in stack?
//  Ans=> use link list when size of stack is not known  in advance and we want to avoid overflow and underflow condition.

// Q: Why we should prefer the beginning of the linked list  as top of the stack?
// Ans => One of the most common reason is that In a linked list, adding or removing a node at the beginning (head) takes O(1) time because you just change pointers.
// If you use the end as the top, you would have to traverse the whole list to reach it, which takes O(n) time.So, for a stack where push and pop should be fast, the beginning of the linked list is ideal.
// ----------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL; // same as struct Node* top = NULL;

void Push(int data)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    if (NewNode == NULL)
    {
        printf("Stack overflow\n");
        return;
    }
    NewNode->data = data;
    NewNode->next = top;
    top = NewNode;
}

int Pop()
{
    int value;
    if (top == NULL)
    {
        printf("stack is underflowed\n");
        return 0;
    }

    struct Node *curr = top;
    value = curr->data;
    top = top->next;
    free(curr);
    curr = NULL;
    return value;
}

int IsEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int Peek(){
    return top->data;
}



void print()
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
main()
{
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    print();
    printf("\nPopped element is : %d\n", Pop());
    print();
    printf("\nTop element is %d\n", Peek());
    // printf("Top element is %d\n", top->data);
}