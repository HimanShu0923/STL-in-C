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

struct node *searchBST(struct node *root, int key) // Recursive function for searching in BST
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    else if (root->data > key)
    {
        return BSTsearch(root->left, key);
    }

    else
    {
        return BSTsearch(root->right, key);
    }
}

int main()
{
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(2);
    struct node *p3 = createnode(3);
    struct node *p4 = createnode(4);
    struct node *p5 = createnode(5);

    p1->right = p2;
    p1->left = p3;
    p2->right = p4;
    p4->left = p5;

    struct node *temp = searchBST(p1 , 10);

    if(temp == NULL)
    {
        printf("\nKey is not found in BST\n\n");
    }
    else
    {
        printf("\n%d Key is found in BST\n\n",temp->data);
    }

    return 0;
}