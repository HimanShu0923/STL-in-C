#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *createnode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    // printf("Node has been created\n");
    return n;
}

void InsertionBST(struct node *root, int key)
{
    struct node *prev = NULL;
    struct node *temp = createnode(key);

    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("\nCan't insert %d in BST again , already exist in BST\n", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    if (key < prev->data)
    {
        prev->left = temp;
    }
    else
    {
        prev->right = temp;
    }
}

void InOrder_traverse(struct node *root)
{
    if (root != NULL)
    {
        InOrder_traverse(root->left);
        printf("%d\t", root->data);
        InOrder_traverse(root->right);
    }
}

int main()
{
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(2);
    struct node *p3 = createnode(3);
    struct node *p4 = createnode(4); // p4 is root here
    struct node *p5 = createnode(5);

    p4->right = p5;
    p4->left = p2;
    p2->right = p3;
    p2->left = p1;

    printf("\n");
    InOrder_traverse(p4);

    InsertionBST(p4, 0);

    printf("\n");
    InOrder_traverse(p4);

    InsertionBST(p4, 8);

    printf("\n");
    InOrder_traverse(p4);

    InsertionBST(p4, 1);

    printf("\n");
    InOrder_traverse(p4);

    return 0;
}