
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef long long ll;
#define get(i) get[i]

//____________________________ArrayList________________________//
typedef struct
{
    long long *get;
    int length;
    int len;
} ArrayList;

ll ArrayList_sort(ArrayList *arr, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    ll inv1 = ArrayList_sort(arr, s, mid);
    ll inv2 = ArrayList_sort(arr, mid + 1, e);
    ll temp = 0;
    ll arr2[e - s + 1];
    int po1 = s, po2 = mid + 1, pos = 0;
    while (1)
    {
        if (po1 == mid + 1 && po2 == e + 1)
            break;
        if (po1 == mid + 1)
        {
            for (int i = po2; i <= e; i++)
            {
                arr2[pos] = arr->get(i);
                pos++;
            }
            break;
        }
        if (po2 == e + 1)
        {
            for (int i = po1; i <= mid; i++)
            {
                arr2[pos] = arr->get(i);
                pos++;
            }
            break;
        }
        if (arr->get(po1) <= arr->get(po2))
        {
            arr2[pos] = arr->get(po1);
            po1++;
            pos++;
        }
        else
        {
            arr2[pos] = arr->get(po2);
            po2++;
            pos++;
            temp += (mid - po1 + 1);
        }
    }
    for (int i = 0, j = s; j <= e; i++, j++)
    {
        arr->get(j) = arr2[i];
    }

    return inv1 + inv2 + temp;
}

ArrayList new_ArrayList()
{
    ArrayList arr;
    arr.get = (long long *)calloc(1, sizeof(long long));
    arr.len = 1;
    arr.length = 0;
    return arr;
}
void ArrayList_pop(ArrayList *arr)
{
    arr->length = arr->length - 1;
}
void ArrayList_add(ArrayList *arr, int n)
{
    if (arr->length + 1 == arr->len)
    {
        arr->get = (long long *)realloc(arr->get, sizeof(long long) * arr->len * 2);
        arr->len = arr->len * 2;
    }
    arr->get[arr->length++] = n;
}
void ArrayList_rev(ArrayList *arr)
{
    int n = arr->length;
    for (int i = 0; i < n / 2; i++)
    {
        ll temp = arr->get[i];
        arr->get[i] = arr->get[n - i - 1];
        arr->get[n - i - 1] = temp;
    }
}
//=================================================================//

typedef struct TreeNode
{
	int d;			// data
	int c;			// 1-red, 0-black
	struct TreeNode *p; // parent
	struct TreeNode *r; // right-child
	struct TreeNode *l; // left child
	int size;		// size of treeset
} TreeSet;

struct TreeNode *bst(struct TreeNode *trav, struct TreeNode *temp, bool *flag)
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

void rightrotate(struct TreeNode **root, struct TreeNode *temp)
{
	struct TreeNode *left = temp->l;
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
void leftrotate(struct TreeNode **root, struct TreeNode *temp)
{
	struct TreeNode *right = temp->r;
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
void fixup(struct TreeNode **root, struct TreeNode *pt)
{
	struct TreeNode *parent_pt = NULL;
	struct TreeNode *grand_parent_pt = NULL;

	while ((pt != *root) && (pt->c != 0) && (pt->p->c == 1))
	{
		parent_pt = pt->p;
		grand_parent_pt = pt->p->p;
		if (parent_pt == grand_parent_pt->l)
		{

			struct TreeNode *uncle_pt = grand_parent_pt->r;
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
			struct TreeNode *uncle_pt = grand_parent_pt->l;
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
void inorder(struct TreeNode *trav)
{
	if (trav == NULL)
		return;
	inorder(trav->l);
	printf("%d ", trav->d);
	inorder(trav->r);
}

void TreeSet_itr_helper(struct TreeNode *trav, ArrayList* arr)
{
	if (trav == NULL)
		return;
	TreeSet_itr_helper(trav->l, arr);
	ArrayList_add(arr, trav->d);
	// printf("%d ", trav->d);
	TreeSet_itr_helper(trav->r, arr);
}

ArrayList TreeSet_itr(struct TreeNode* trav){
	ArrayList arr =new_ArrayList();
	TreeSet_itr_helper(trav, &arr);
	return arr;
}


void TreeSet_add(struct TreeNode **root, ll val)
{
	struct TreeNode *temp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
	temp->r = NULL;
	temp->l = NULL;
	temp->p = NULL;
	temp->d = val;
	temp->c = 1;
	temp->size = (*root) == NULL ? 0 : (*root)->size;
	bool flag[1];
	flag[0] = false;
	struct TreeNode *haha = bst(*root, temp, &flag[0]);
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
struct TreeNode *new_TreeSet()
{
	struct TreeNode *temp = (struct TreeNode*)malloc(sizeof(struct TreeNode *));
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
	// inorder(root);
	ArrayList arr = TreeSet_itr(root);

	for(int i=0;i<arr.length;i++){
		printf("%lld ", arr.get(i));
	}
	printf("\n");

	return 0;
}
