#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *root = NULL;

// Stack of Node Pointers
struct Stack
{
    int size;
    int top;
    struct Node **S;
};

// Create Stack
void create(struct Stack *st)
{
    st->size = 100;
    st->top = -1;

    st->S = (struct Node **)malloc(st->size * sizeof(struct Node *));
}

// Push
void push(struct Stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

// Pop
struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;

    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->S[st->top];
        st->top--;
    }

    return x;
}

// Peek
struct Node *peek(struct Stack st, int pos)
{
    int index = st.top - pos + 1;

    if (index < 0)
    {
        printf("Invalid Position\n");
        return NULL;
    }

    return st.S[index];
}

// Stack Top
struct Node *stackTop(struct Stack st)
{
    if (st.top == -1)
        return NULL;

    return st.S[st.top];
}

// Is Empty
int isEmpty(struct Stack st)
{
    return st.top == -1;
}

// Is Full
int isFull(struct Stack st)
{
    return st.top == st.size - 1;
}

// Display Stack
void display(struct Stack st)
{
    int i;

    printf("Stack Elements:\n");

    for (i = st.top; i >= 0; i--)
    {
        printf("%d ", st.S[i]->data);
    }

    printf("\n");
}

void GenerateBSTfrom_preorder(int arr[], int n)
{
    struct Stack st;
    create(&st);
    struct Node *t;
    struct Node *p;
    int i = 0;

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = arr[i++];
    root->lchild = root->rchild = NULL;
    p = root;
    while (i < n)
    {
        if (arr[i] < p->data)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = arr[i++];
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            push(&st, p);
            p = t;
        }
        else
        {
            if (arr[i] > p->data && (isEmpty(st) || arr[i] < stackTop(st)->data))
            {
                t = (struct Node *)malloc(sizeof(struct Node));
                t->data = arr[i++];
                t->lchild = t->rchild = NULL; 
                p->rchild = t;
                p = t;
            }
           else
            {
                p = pop(&st);
            }
        }
    }
}

void preorder(struct Node *p)
{
    if (p)
    {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main()
{
    int pre[] = {30, 20, 10, 15, 25, 40, 50, 45};
    int n = sizeof(pre) / sizeof(pre[0]);

    GenerateBSTfrom_preorder(pre, n);

    preorder(root);
    return 0;
}