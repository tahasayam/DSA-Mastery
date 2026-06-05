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

void DEl_List(struct node **head)
{
    struct node *temp = *head;
    while (temp != NULL)
    {
        temp = temp->link;
        free(*head);
        *head = temp;
    }
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

    DEl_List(&head);
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}