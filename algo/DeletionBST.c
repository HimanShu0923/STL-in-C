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
    return n;
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

struct node *inOrder_Pre(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deletenode(struct node *root, int value)
{
    struct node *iPre;

    // Base Condition
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL) // we got the leaf node
    {
        free(root);
        return NULL; // returning NULL in its place bcoz we have deleted it .
    }

    // Strategy to implement the deletion code

    if (value < root->data) // if value is less than root's data , which means it is in left subtree
    {
        root->left = deletenode(root->left, value); //  returning new left subtree after deletion.
    }
    else if (value > root->data) // if value is greater than root's data , which means it is in right subtree
    {
        root->right = deletenode(root->right, value); // returning new right subtree after deletion.
    }
    else // if we find the desired node to be deleted
    {
        iPre = inOrder_Pre(root);
        root->data = iPre->data;
        root->left = deletenode(root->left, iPre->data);
    }
    return root;
}

int main()
{
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(2);
    struct node *p3 = createnode(3);
    struct node *p4 = createnode(4);
    struct node *p5 = createnode(5); // here p5 is root
    struct node *p6 = createnode(6);

    p5->right = p6;
    p5->left = p2;
    p2->right = p3;
    p2->left = p1;
    p3->right = p4;

    printf("\n\nIn-Order Taversal of Tree :\n");
    InOrder_traverse(p5);

    p5 = deletenode(p5, 5);

    printf("\n\nIn-Order Taversal of Tree :\n");
    InOrder_traverse(p5);

    return 0;
}