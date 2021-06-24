#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define MAP_SIZE 2
typedef long long ll;
#define get(i) get[i]
#define Max_String 200
#define maxn 100000
#define String char *
//_________________________Header_Inputs____________________________________//
char *nextLine()
{
    char *temp = (char *)malloc(sizeof(char *) * Max_String);
    scanf("%s", temp);
    return temp;
}
long long nextInt()
{
    ll t;
    scanf("%lld", &t);
    return t;
}
double nextDouble()
{
    double t;
    scanf("%lf", &t);
    return t;
}
//___________________________Header_Arrays_____________________________//

int Lower_bound(ll *arr, ll val, int s, int e)
{
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == val)
            return mid;
        if (arr[mid] > val)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return e + 1;
}
ll Array_sort(ll *arr, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    ll inv1 = Array_sort(arr, s, mid);
    ll inv2 = Array_sort(arr, mid + 1, e);
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
                arr2[pos] = arr[i];
                pos++;
            }
            break;
        }
        if (po2 == e + 1)
        {
            for (int i = po1; i <= mid; i++)
            {
                arr2[pos] = arr[i];
                pos++;
            }
            break;
        }
        if (arr[po1] <= arr[po2])
        {
            arr2[pos] = arr[po1];
            po1++;
            pos++;
        }
        else
        {
            arr2[pos] = arr[po2];
            po2++;
            pos++;
            temp += (mid - po1 + 1);
        }
    }
    for (int i = 0, j = s; j <= e; i++, j++)
    {
        arr[j] = arr2[i];
    }

    return inv1 + inv2 + temp;
}
void Array_rev(ll *arr, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        ll temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

//______________________________Header_ArrayList____________________________//
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
//________________________Header_StringList___________________________//
typedef struct
{
    char **get;
    int length;
    int len;
} StringList;

ll StringList_sort(StringList *arr, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    ll inv1 = StringList_sort(arr, s, mid);
    ll inv2 = StringList_sort(arr, mid + 1, e);
    ll temp = 0;
    char *arr2[e - s + 1];
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
        if (strcmp(arr->get(po1), arr->get(po2)) <= 0)
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

StringList new_StringList()
{
    StringList arr;
    arr.get = (char **)calloc(1, Max_String);
    arr.len = 1;
    arr.length = 0;
    return arr;
}
void StringList_pop(StringList *arr)
{
    arr->length = arr->length - 1;
}
void StringList_add(StringList *arr, char *n)
{
    if (arr->length + 1 == arr->len)
    {
        arr->get = (char **)realloc(arr->get, Max_String * arr->len * 2);
        arr->len = arr->len * 2;
    }
    arr->get[arr->length++] = n;
}
void StringList_rev(StringList *arr)
{
    int n = arr->length;
    for (int i = 0; i < n / 2; i++)
    {
        char *temp = arr->get[i];
        arr->get[i] = arr->get[n - i - 1];
        arr->get[n - i - 1] = temp;
    }
}
//_________________________Header_HashMap________________________________//
typedef struct List
{
    char *key;
    char *val;
    struct List *next;
} List;
List *HashMap[MAP_SIZE];

long hash(char *str)
{
    long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;
    return hash % MAP_SIZE;
}

void map_add(char *key, char *val)
{
    List *temp = malloc(sizeof(List *) * 1);
    temp->key = key;
    temp->val = val;
    int ind = hash(temp->key);
    if (HashMap[ind] == NULL)
    {
        HashMap[ind] = temp;
    }
    else
    {
        temp->next = HashMap[ind];
        HashMap[ind] = temp;
    }
    return;
}
bool map_contains(char *inkey)
{
    int ind = hash(inkey);
    if (HashMap[ind] == NULL)
    {
        return false;
    }
    {
        List *temp = HashMap[ind];
        while (temp)
        {
            if (temp->key == inkey)
                return true;
            temp = temp->next;
        }
    }
    return false;
}

char *map_get(char *key)
{
    int ind = hash(key);
    if (HashMap[ind] == NULL)
    {
        return "";
    }
    else
    {
        List *temp = HashMap[ind];
        while (temp)
        {
            if (temp->key == key)
                return temp->val;
            temp = temp->next;
        }
    }
    return "";
}
void erase(StringList arr)
{
    for (int i = 0; i < arr.length; i++)
    {
        int ind = hash(arr.get(i));
        if (HashMap[ind] == NULL)
            continue;
        HashMap[ind] = NULL;
    }
}
//___________________________Header_Queue________________________________//
typedef struct
{
    ll *arr;
    int size;
    int start;
} Queue;

Queue new_Queue()
{
    Queue q;
    q.arr = (ll *)malloc(maxn * sizeof(ll *));
    q.size = 0;
    q.start = 0;
    return q;
}

void Queue_add(Queue *q, ll n)
{
    q->arr[q->size] = n;
    q->size++;
}

ll Queue_remove(Queue *q)
{
    if (q->start == q->size)
    {
        return 0;
    }
    ll res = q->arr[q->start];
    q->start++;
    return res;
}
ll Queue_peek(Queue *q)
{
    if (q->start == q->size)
        return 0;
    return q->arr[q->start];
}

//_____________________________Header_Stack_________________________//
typedef struct
{
    ll *arr;
    int size;
} Stack;

Stack new_Stack()
{
    Stack stack;
    stack.arr = (ll *)malloc(maxn * sizeof(ll *));
    stack.size = 0;
    return stack;
}

void Stack_add(Stack *stack, ll n)
{
    stack->arr[stack->size] = n;
    stack->size++;
}

ll Stack_pop(Stack *stack)
{
    ll res = stack->arr[stack->size - 1];
    stack->size--;
    return res;
}
ll Stack_peek(Stack *stack)
{
    return stack->arr[stack->size - 1];
}

//__________________________Header_PriorityQueue____________________//
typedef struct
{
    ll *arr;
    int size;
} PriorityQueue;

PriorityQueue new_PriorityQueue()
{
    PriorityQueue pq;
    pq.arr = (ll *)malloc(maxn * sizeof(ll *));
    pq.size = 0;
    return pq;
}

void pq_up(PriorityQueue *pq, int pos)
{
    if (pos == 0 || pq->arr[pos] > pq->arr[pos / 2])
    {
        return;
    }
    ll temp = pq->arr[pos / 2];
    pq->arr[pos / 2] = pq->arr[pos];
    pq->arr[pos] = temp;
    pq_up(pq, pos / 2);
}

void pq_add(PriorityQueue *pq, ll n)
{
    pq->arr[pq->size] = n;
    pq_up(pq, pq->size);
    pq->size++;
}

ll pq_peek(PriorityQueue *pq)
{
    return pq->arr[0];
}
void pq_down(PriorityQueue *pq, int pos)
{
    int left = pos * 2 + 1;
    int right = pos * 2 + 2;
    if (pq->size < left)
        return;
    if (pq->size < right)
    {
        if (pq->arr[pos] < pq->arr[left])
        {
            return;
        }
        ll temp = pq->arr[left];
        pq->arr[left] = pq->arr[pos];
        pq->arr[pos] = temp;
        return;
    }
    if (pq->arr[left] < pq->arr[right])
    {
        ll temp = pq->arr[left];
        pq->arr[left] = pq->arr[pos];
        pq->arr[pos] = temp;
        pq_down(pq, left);
    }
    else
    {
        ll temp = pq->arr[right];
        pq->arr[right] = pq->arr[pos];
        pq->arr[pos] = temp;
        pq_down(pq, right);
    }
}

ll pq_poll(PriorityQueue *pq)
{
    ll res = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size];
    pq->size--;
    pq_down(pq, 0);
    return res;
}
//____________________________________________________________________________//

int main()
{
    int t = nextInt();
    while (t--)
    {
        StringList arr = new_StringList();
        int n = nextInt();
        for (int i = 0; i < n; i++)
        {
            String(s1) = nextLine();
            StringList_add(&arr, s1);
        }
        for (int i = 0; i < n; i++)
        {
            printf("%s ", arr.get(i));
        }
        printf("\n");
        StringList_sort(&arr, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            printf("%s ", arr.get(i));
        }
        printf("\n");
        StringList_rev(&arr);
        for (int i = 0; i < n; i++)
        {
            printf("%s ", arr.get(i));
        }
        printf("\n");
    }
    return 0;
}