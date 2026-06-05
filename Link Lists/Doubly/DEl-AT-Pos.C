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

void DEl_from_last(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    else
    {
        struct node *curr = head;
        struct node *prev = head;
        while (curr->next != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        free(curr);
        prev->next = NULL;
    }
}

void Del_At_Pos(struct node **head, int pos)
{
    // Case 1: Empty list
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *curr = *head;
    struct node *prev = NULL;
    int i = 1;

    // Move to desired position
    while (curr != NULL && i < pos)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }

    // Case 2: Invalid position
    if (curr == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    // Case 3: Delete first node
    if (prev == NULL)
    {
        *head = curr->next;
        if (*head != NULL)
            (*head)->prev = NULL;
    }
    // Case 4: Delete middle or last node
    else
    {
        prev->next = curr->next;
        if (curr->next != NULL)
            curr->next->prev = prev;
    }

    free(curr);
}
main()
{
    struct node *head = NULL;
    head = Add_ToEmptyList(head, 10);
    head = addAtBeg(head, 5);
    Add_At_End(head, 15);
    Add_At_End(head, 20);
    Add_At_End(head, 25);
    // DEl_from_last(head);
    DEL_At_Pos(&head, 5);

    struct node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
