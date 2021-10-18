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

bool checkBST(struct node *root)
{
     // initializing the static variable for recursive function to store prev node.
    static struct node *prev = NULL;  
  

    // if tree is not empty then we'll check for BST (using the concept of INORDER TRAVERSAL)
    if(root != NULL)  
    {
           // Checking for left subtree of each node recursively
        if(!isBST(root->left))
        {
            return false;
        }

        // storing the prev node of left subtree here and checking and checking whether parent root is greater than it or not
        if(prev != NULL && root->data <= prev->data) 
        {                                            
            return false;
        }

        prev = root;

        // ------> checking for right subtree 
        return isBST(root->right);
       
    }
    // if tree is empty we are returning it as BST
    else 
    {
        return true;;
    }
}

int main()
{
    struct node *p1 = createnode(1);
    struct node *p2 = createnode(2);
    struct node *p3 = createnode(3);
    struct node *p4 = createnode(4);
    struct node *p5 = createnode(5);

    p4->right = p5;
    p4->left = p2;
    p2->right = p3;
    p2->left = p1;

    bool res = checkBST(p4);

    if(res == true)
    {
        printf("\nThis is a BST\n");
    }
    else
    {
        printf("\nThis is not a BST\n");
    }

    printf("\n");

    return 0;
}