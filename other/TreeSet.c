
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef long long ll;


typedef struct node
{
	int d;			// data
	int c;			// 1-red, 0-black
	struct node *p; // parent
	struct node *r; // right-child
	struct node *l; // left child
	int size;		// size of treeset
} TreeSet;

struct node *bst(struct node *trav, struct node *temp, bool *flag)
{
	if (trav == NULL)
		return temp;

	if (temp->d < trav->d)
	{
		trav->l = bst(trav->l, temp, flag);
		trav->l->p = trav;
	}
	else if (temp->d > trav->d)
	{
		trav->r = bst(trav->r, temp, flag);
		trav->r->p = trav;
	}
	else
	{
		flag[0] = true;
	}
	return trav;
}

void rightrotate(struct node **root, struct node *temp)
{
	struct node *left = temp->l;
	temp->l = left->r;
	if (temp->l)
		temp->l->p = temp;
	left->p = temp->p;
	if (!temp->p)
		*root = left;
	else if (temp == temp->p->l)
		temp->p->l = left;
	else
		temp->p->r = left;
	left->r = temp;
	temp->p = left;
}
void leftrotate(struct node **root, struct node *temp)
{
	struct node *right = temp->r;
	temp->r = right->l;
	if (temp->r)
		temp->r->p = temp;
	right->p = temp->p;
	if (!temp->p)
		*root = right;
	else if (temp == temp->p->l)
		temp->p->l = right;
	else
		temp->p->r = right;
	right->l = temp;
	temp->p = right;
}
void fixup(struct node **root, struct node *pt)
{
	struct node *parent_pt = NULL;
	struct node *grand_parent_pt = NULL;

	while ((pt != *root) && (pt->c != 0) && (pt->p->c == 1))
	{
		parent_pt = pt->p;
		grand_parent_pt = pt->p->p;
		if (parent_pt == grand_parent_pt->l)
		{

			struct node *uncle_pt = grand_parent_pt->r;
			if (uncle_pt != NULL && uncle_pt->c == 1)
			{
				grand_parent_pt->c = 1;
				parent_pt->c = 0;
				uncle_pt->c = 0;
				pt = grand_parent_pt;
			}

			else
			{
				if (pt == parent_pt->r)
				{
					leftrotate(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->p;
				}
				rightrotate(root, grand_parent_pt);
				int t = parent_pt->c;
				parent_pt->c = grand_parent_pt->c;
				grand_parent_pt->c = t;
				pt = parent_pt;
			}
		}
		else
		{
			struct node *uncle_pt = grand_parent_pt->l;
			if ((uncle_pt != NULL) && (uncle_pt->c == 1))
			{
				grand_parent_pt->c = 1;
				parent_pt->c = 0;
				uncle_pt->c = 0;
				pt = grand_parent_pt;
			}
			else
			{
				if (pt == parent_pt->l)
				{
					rightrotate(root, parent_pt);
					pt = parent_pt;
					parent_pt = pt->p;
				}
				leftrotate(root, grand_parent_pt);
				int t = parent_pt->c;
				parent_pt->c = grand_parent_pt->c;
				grand_parent_pt->c = t;
				pt = parent_pt;
			}
		}
	}

	(*root)->c = 0;
}
void inorder(struct node *trav)
{
	if (trav == NULL)
		return;
	inorder(trav->l);
	printf("%d ", trav->d);
	inorder(trav->r);
}

void TreeSet_add(struct node **root, ll val)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->r = NULL;
	temp->l = NULL;
	temp->p = NULL;
	temp->d = val;
	temp->c = 1;
	temp->size = (*root) == NULL ? 0 : (*root)->size;
	bool flag[1];
	flag[0] = false;
	struct node *haha = bst(*root, temp, &flag[0]);
	int x = flag[0] ? 1 : 0;
	if (flag[0])
	{
		return;
	}
	*root = haha;
	(*root)->size++;
	int sizetemp = (*root)->size;

	fixup(root, temp);
	(*root)->size = sizetemp;
}
struct node *new_TreeSet()
{
	struct node *temp = (struct node*)malloc(sizeof(struct node *));
	temp = NULL;
	return temp;
}

int main()
{
	int n = 7;
	ll a[7] = {2, 1, 2, 1, 2, 1, 3};
	TreeSet *root = new_TreeSet();
	for (int i = 0; i < n; i++)
	{

		TreeSet_add(&root, a[i]);
	}
	printf("size : %d\n", root->size);
	printf("Inoder Traversal of Created Tree\n");
	inorder(root);

	return 0;
}
