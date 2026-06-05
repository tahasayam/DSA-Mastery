#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* next;
    int data;
    struct node* prev;
};

struct node * Add_ToEmptyList(struct node* head, int data){
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    temp->prev=NULL;

    head=temp;
    return head; // New head of the list
}


struct node * addAtBeg(struct node *head ,int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=head;
    temp->prev=NULL;
    head=temp;
    return temp;
}
main(){
    struct node *head = NULL;
    struct node* ptr;
    head = Add_ToEmptyList(head, 10);  
    head = addAtBeg(head, 5);

    ptr = head;
    while(ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

}

