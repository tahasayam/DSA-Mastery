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
    head = temp;
    return temp;
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

void Add_At_Pos(struct node **head, int data, int pos)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    // Case 1: Empty list
    if (*head == NULL)
    {
        if (pos == 1)
        {
            *head = temp;
        }
        else
        {
            printf("Invalid position\n");
        }
        return;
    }

    struct node *curr = *head;
    struct node *prev = NULL;
    int i = 1;

    // Move to position
    while (curr != NULL && i < pos)
    {
        prev = curr;
        curr = curr->next;
        i++;
    }

    // Case 2: Insert at beginning
    if (pos == 1)
    {
        temp->next = *head;
        (*head)->prev = temp;
        *head = temp;
    }
    // Case 3: Invalid position
    else if (i < pos)
    {
        printf("Invalid position\n");
    }
    // Case 4: Insert at end
    else if (curr == NULL)
    {
        prev->next = temp;
        temp->prev = prev;
    }
    // Case 5: Insert in middle
    else
    {
        temp->next = curr;
        temp->prev = prev;
        prev->next = temp;
        curr->prev = temp;
    }
}

main()
{
    struct node *head = NULL;
    struct node *ptr;
    head = Add_ToEmptyList(head, 10);
    head = addAtBeg(head, 5);
    Add_At_End(head, 15);
    Add_At_End(head, 25);
    Add_At_Pos(&head, 20, 4);

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
