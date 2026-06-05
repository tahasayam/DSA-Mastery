#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
    struct node *prev;
};

struct node *Add_ToEmptyList(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;

    head = temp;
    return head; // New head of the list
}

struct node *addAtBeg(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    temp->prev = NULL;
    head->prev = temp; // Update the previous head's prev pointer
    head = temp;
    return head;
}

void Add_At_End(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
}

void ReverseList(struct node **head)
{
    if (*head == NULL)
    {
        printf("List is empty, nothing to reverse.\n");
        return;
    }
    else
    {
        struct node *ptr1 = *head;
        struct node *ptr2 = ptr1->next;
        ptr1->next = NULL;
        ptr1->prev = ptr2;
        while (ptr2 != NULL)
        {
            ptr2->prev = ptr2->next;
            ptr2->next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr2->prev;
        }
        *head = ptr1;
    }
}
main()
{
    struct node *head = NULL;
    struct node *ptr;
    head = Add_ToEmptyList(head, 10);
    head = addAtBeg(head, 5);
    Add_At_End(head, 15);
    Add_At_End(head, 20);
    ReverseList(&head);

     ptr = head;

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
