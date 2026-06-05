

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
void Del_End(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    else if (head->link == NULL)
    {
        // Only one node in the list
        free(head);
        head = NULL;
        return;
    }
    else
    {
        struct node *curr = head;
        struct node *prev = head;
        while (curr->link != NULL)
        {
            prev = curr;
            curr = curr->link;
        }
        free(curr);
        prev->link = NULL;
    }
}

void Reverse(struct node **head)
{
    struct node *prev = NULL;
    struct node *next = NULL;
    struct node *curr = *head;

    while (curr != NULL)
    {
        next = curr->link;  // store next node
        curr->link = prev;  // reverse link
        prev = curr;        // move prev forward
        curr = next;        // move curr forward
    }

    *head = prev; // update head to new first node
}
main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 10;
    head->link = NULL;

    struct node *tail = head;
    tail = AtEnd(tail, 20);
    tail = AtEnd(tail, 30);
    tail = AtEnd(tail, 40);
    tail = AtEnd(tail, 50);
    tail = AtEnd(tail, 60);
    Del_End(head);

    tail = head;
    while (tail != NULL)
    {
        printf("%d ", tail->data);
        tail = tail->link;
    }
}