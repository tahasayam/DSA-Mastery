#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int height;
    struct Node *lchild;
    struct Node *rchild;
};

struct Node *root = NULL;

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->height = 1;
    newNode->lchild = NULL;
    newNode->rchild = NULL;

    return newNode;
}

int NodeHeight(struct Node *p)
{
    int hl, hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return (hl > hr) ? hl + 1 : hr + 1;
}

int NodeBalanceFactor(struct Node *p)
{
    int hl, hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

struct Node *RightRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
        root = pl;

    return pl;
}

struct Node *LeftRotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
        root = pr;

    return pr;
}

struct Node *LeftRightRotation(struct Node *p)
{
    p->lchild = LeftRotation(p->lchild);
    return RightRotation(p);
}

struct Node *RightLeftRotation(struct Node *p)
{
    p->rchild = RightRotation(p->rchild);
    return LeftRotation(p);
}

struct Node *Insert(struct Node *root, int key)
{
    if (root == NULL)
        return createNode(key);

    if (key < root->data)
        root->lchild = Insert(root->lchild, key);

    else if (key > root->data)
        root->rchild = Insert(root->rchild, key);

    root->height = NodeHeight(root);

    // LL Rotation
    if (NodeBalanceFactor(root) == 2 && NodeBalanceFactor(root->lchild) == 1)
    {
        return RightRotation(root);
    }

    // RR Rotation
    if (NodeBalanceFactor(root) == -2 && NodeBalanceFactor(root->rchild) == -1)
    {
        return LeftRotation(root);
    }

    // LR Rotation
    if (NodeBalanceFactor(root) == 2 && NodeBalanceFactor(root->lchild) == -1)
    {
        return LeftRightRotation(root);
    }

    // RL Rotation
    if (NodeBalanceFactor(root) == -2 && NodeBalanceFactor(root->rchild) == 1)
    {
        return RightLeftRotation(root);
    }

    return root;
}

// code for delete node from AVL tree
struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;

    if (p == NULL)
        return NULL;

    // Leaf node
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;

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

    // Update height
    p->height = NodeHeight(p);

    // LL Rotation
    if (NodeBalanceFactor(p) == 2 &&
        NodeBalanceFactor(p->lchild) >= 0)
    {
        return RightRotation(p);
    }

    // LR Rotation
    if (NodeBalanceFactor(p) == 2 &&
        NodeBalanceFactor(p->lchild) < 0)
    {
        return LeftRightRotation(p);
    }

    // RR Rotation
    if (NodeBalanceFactor(p) == -2 &&
        NodeBalanceFactor(p->rchild) <= 0)
    {
        return LeftRotation(p);
    }

    // RL Rotation
    if (NodeBalanceFactor(p) == -2 &&
        NodeBalanceFactor(p->rchild) > 0)
    {
        return RightLeftRotation(p);
    }

    return p;
}

void Inorder(struct Node *root)
{
    if (root)
    {
        Inorder(root->lchild);
        printf("%d ", root->data);
        Inorder(root->rchild);
    }
}

int main()
{

    int keys[] = {10, 20, 30, 25, 28, 27, 5};
    int n = 7;

    for (int i = 0; i < n; i++)
    {
        root = Insert(root, keys[i]);
    }

    Inorder(root);

    // root = Insert(root, 30);
    // root = Insert(root, 20);
    // root = Insert(root, 10);

    // Inorder(root);

    return 0;
}