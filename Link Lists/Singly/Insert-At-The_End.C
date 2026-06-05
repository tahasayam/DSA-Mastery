#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void AddtoEnd(struct node **ptr, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL; // new node is tail

    (*ptr)->link = temp; // link current tail to new node
    *ptr = temp;         // update tail pointer
    // why we use 17 th line bcz in main we ahve to just traverse once to print the linked list and we can add at end in O(1) time complexity .The reason we update *ptr is to maintain a “tail pointer”:
    // When you add a node at the end of a linked list, you usually want to know where the last node is so the next insertion can happen in O(1) time.

    // struct node *ptr = head;  // tail pointer starts at head
    // AddtoEnd(&ptr, 98); // adds 98, updates ptr to point to new tail
    // AddtoEnd(&ptr, 3);  // adds 3, ptr now points to 3
    // AddtoEnd(&ptr, 34); // adds 34, ptr now points to 34
}

// there are 2 ways e create a function but in first way we have to triverse every(loop in function when we call it many times it can take more time we have to reduce time complexity ) time when we call in main that have complixty big O(n)
void AddAtEnd(struct node *head, int data)
{
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

// Other ways
struct node *Add_at_End(struct node *head, int data)
{
    struct node *temp, *ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    ptr = head;
    ptr->link = temp;
    return temp;
}
// you can see the benifit of second way is that we dont have to triverse every time we call the function we just have to triverse once and then we can add at end in O(1) time complexity..

main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    // if we use the first version of function then not ptr is reqired we can directly call the function in main but if we use the second version of function then we have to use ptr to store the return value of function because our function is returning the new tail of the linked list after adding a new node at the end. We create a new node, but it is pointing to new node we can set data at first node we have to pass head by refrence in function updated function is ...............
    struct node *ptr = head;
    AddtoEnd(&ptr, 98);
    // ptr = Add_at_End(ptr, 98);
    // ptr = Add_at_End(ptr, 3);
    // ptr = Add_at_End(ptr, 34);

    ptr = head; //for this verion     // ptr = Add_at_End(ptr, 34); and for printing data
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    // we have to just traverse once to print the linked list and we can add at end in O(1) time complexity
}










// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int data;
//     struct node *link;
// };

// // Add at end using pointer to pointer (pass by reference)
// void Add_at_End(struct node **tail, int data)
// {
//     struct node *temp = malloc(sizeof(struct node));
//     temp->data = data;
//     temp->link = NULL;      // new node is tail

//     (*tail)->link = temp;   // link current tail to new node
//     *tail = temp;           // update tail pointer
// }

// int main()
// {
//     struct node *head = malloc(sizeof(struct node));
//     head->data = 45;
//     head->link = NULL;

//     struct node *tail = head;  // maintain tail pointer

//     Add_at_End(&tail, 98);
//     Add_at_End(&tail, 3);
//     Add_at_End(&tail, 34);

//     // print list
//     struct node *ptr = head;
//     while(ptr != NULL) {
//         printf("%d ", ptr->data);
//         ptr = ptr->link;
//     }
//     printf("\n");

//     return 0;
// }