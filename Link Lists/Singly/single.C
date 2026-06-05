#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void count(struct node *head)
{
    int count = 0;
    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }

}

int main()
{
    // Creating the first node
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    // Creating the second node
    struct node *current = malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    head->link = current;

    // Creating the third node (reusing the current pointer)
    current = malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;

    // Linking the second node to the third node via the head pointer
    head->link->link = current;

    return 0;
}