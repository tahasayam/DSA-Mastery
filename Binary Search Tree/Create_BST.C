#include <stdio.h>
#include <stdlib.h>
// root variable .
struct Node *root = NULL;

struct Node
{
    int data;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *createNode(int x)
{
    struct Node *t;

    t = (struct Node *)malloc(sizeof(struct Node));

    t->data = x;
    t->lchild = NULL;
    t->rchild = NULL;

    return t;
}

struct Node *insert(struct Node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->lchild = insert(root->lchild, key);

    else if (key > root->data)
        root->rchild = insert(root->rchild, key);

    return root;
}
// Iterative Insretion
struct Node *Insert(struct Node *root, int key)
{
    struct Node *r = NULL;
    struct Node *t = root; // t travels, root stays safe!
    struct Node *p;

    while (t != NULL)
    {
        r = t;
        if (key == t->data)
            return root;
        if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }

    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (r == NULL) // tree was empty
        return p;  // new node becomes root ✅
    else if (p->data < r->data)
        r->lchild = p;
    else
        r->rchild = p;

    return root; // original root returned ✅
}

struct Node *ReSearch(struct Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    if (key < root->data)
    {
        return ReSearch(root->lchild, key);
    }
    else
    {
        return ReSearch(root->rchild, key);
    }
}

// searh using Ietration loop

struct Node *ItReSearch(struct Node *root, int key)
{

    while (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            root = root->lchild;
        }
        else
        {
            root = root->rchild;
        }
    }
    return NULL; // key not found
}

void Inorder(struct Node *root)
{
    if (root != NULL)
    {
        Inorder(root->lchild);
        printf("%d ", root->data);
        Inorder(root->rchild);
    }
}

// inorder predecessor
struct Node *InPre(struct Node *p)
{
    while (p != NULL && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

// inorder successor
struct Node *InSucc(struct Node *p)
{
    while (p != NULL && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}
// height of the tree
int Height(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = Height(root->lchild);
    int right = Height(root->rchild);
    if (left > right)
    {
        return left + 1;
    }
    else
    {
        return right + 1;
    }
}

struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;

    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root) // checking if the node to be deleted is the root node
        {
            root = NULL;
        }
        free(p);
        return NULL;
    }

    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        // Node found

        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);

            p->data = q->data;

            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);

            p->data = q->data;

            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main()
{

    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 20);
    root = Insert(root, 8); // Iterative Insertion
    root = insert(root, 30);
    Inorder(root);

    struct Node *searchResult = ReSearch(root, 8);
    if (searchResult != NULL)
    {
        printf("\nElement %d found in the BST.\n", searchResult->data);
    }
    else
    {
        printf("\nElement not found in the BST.\n");
    }
    root=Delete(root, 20);
    printf("Inorder traversal after deletion: ");
    Inorder(root);
    return 0;
}