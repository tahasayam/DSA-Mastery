

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
void Del_End(struct node **head)
{
    if (*head == NULL)
        return;

    if ((*head)->link == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct node *curr = *head;
    struct node *prev = NULL;
    while (curr->link != NULL)
    {
        prev = curr;
        curr = curr->link;
    }
    prev->link = NULL;
    free(curr);
}

void DEl_Pos(struct node **head, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct node *curr = *head;
    struct node *prev = NULL;

    if (pos == 1) // delete first node
    {
        *head = curr->link;
        free(curr);
        return;
    }

    int i = 1;
    while (curr != NULL && i < pos)
    {
        prev = curr;
        curr = curr->link;
        i++;
    }

    if (curr == NULL)
    {
        printf("Position out of range.\n");
        return;
    }

    prev->link = curr->link;
    free(curr);
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
    // Del_End(head);
    DEl_Pos(&head, 2);

    tail = head;
    while (tail != NULL)
    {
        printf("%d ", tail->data);
        tail = tail->link;
    }
}



























