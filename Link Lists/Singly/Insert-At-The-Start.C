#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *AddAtStart(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = head;
    head = temp;

    return head;
}
// our function is returning the new head of the linked list after adding a new node at the start. We create a new node, but it is pointing to new node we can set data at first node we have to pass head by refrence in function updated function is ...............

void Add_AtStart(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = *head;
    *head = temp;
}

main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = 98;
    temp->link = NULL;

    head->link = temp;

    head = AddAtStart(head, 3); // we have to update head pointer after adding at start because our function is returning the new head of the linked list after adding a new node at the start. We create a new node, but it is pointing to new node we can set data at first node we have to pass head by refrence in function updated function is ...............
    Add_AtStart(&head, 3);

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}