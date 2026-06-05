#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *AtEnd(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    head->link = temp;
    return temp;
}

void AtPos(struct node **head, int data, int pos)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    // Case 1: Insert at beginning
    if (pos == 1)
    {
        temp->link = *head;
        *head = temp;
        return;
    }

    struct node *ptr = *head;
    int i = 1;

    // Move to (pos-1) node
    while (ptr != NULL && i < pos - 1)
    {
        ptr = ptr->link;
        i++;
    }

    // Case 2: Invalid position
    if (ptr == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    // Insert node
    temp->link = ptr->link;
    ptr->link = temp;
}

main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *ptr = head;
    ptr = AtEnd(ptr, 20);
    ptr = AtEnd(ptr, 30);
    ptr = AtEnd(ptr, 40);
    ptr = AtEnd(ptr, 50);
    ptr = AtEnd(ptr, 60);
    ptr = AtEnd(ptr, 80);
    
    AtPos(head, 70, 7);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}