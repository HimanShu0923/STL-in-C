#include <stdio.h>
#include <stdlib.h>
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

int Arrays_upper(ll *arr, ll val, int s, int e)
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
ll Arrays_sort(ll *arr, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    ll inv1 = Arrays_sort(arr, s, mid);
    ll inv2 = Arrays_sort(arr, mid + 1, e);
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
void Arrays_rev(ll *arr, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        ll temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}
//===========================================================================//

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

//===========================================================================//


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
//===========================================================================//


//_________________________Header_HashMap________________________________//
typedef struct Hentry{
	char* key;
	char* value;
	Hentry* next;
} Hentry;

typedef struct{
	Hentry **arr;
}HashMap;

HashMap new_HashMap(){
	HashMap map;
	map.arr = (Hentry**)malloc(MAP_SIZE*sizeof(Hentry**));

	for(int i=0;i<MAP_SIZE;i++){
		map.arr[i] = NULL;
	}
	return map;
}

// long num_hash(long n){
//     long hash = 5381;
//     int c;
// 	char s[1000]; 
// 	sprintf(s, "%d", n);
// 	char *str = &s[0];

//     while (c = *str++)
//         hash = ((hash << 5) + hash) + c; 

//     return hash%MAP_SIZE;
// }

ll hash(char *str){
    ll hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; 

    return hash%MAP_SIZE;
}

void HashMap_add(HashMap *map, char *key, char *val){
	Hentry* e = (Hentry*)malloc(sizeof(Hentry*));
	e->key = key;
	e->value = val;
	e->next = NULL;

	ll hash_key;
	hash_key = hash(key);

	if(!map->arr[hash_key]){
		map->arr[hash_key] = e;
	}
	else{
		Hentry* temp = map->arr[hash_key];
		while(temp->next){
			temp = temp->next;
		}
		temp->next = e;
	}
}
bool HashMap_containsKey(HashMap *map, char *key){
	ll hash_key = hash(key);
	if(!map->arr[hash_key]){
		return false;
	}
	Hentry* temp = map->arr[hash_key];
	
	while(temp && temp->key!=key){
		temp = temp->next;
	}
	if(!temp || temp->key!=key){
		return false;
	}
	return true;
}

char *HashMap_get(HashMap *map, char *key){
	ll hash_key = hash(key);
	if(!map->arr[hash_key]){
		return "";
	}
	Hentry* temp = map->arr[hash_key];
	while(temp && temp->key!=key){
		temp = temp->next;
	}
	if(!temp || temp->key!=key){
		return "";
	}
	return temp->value;
}

void HashMap_remove(HashMap *map, char* key)
{
	ll hash_key = hash(key);
	
	map->arr[hash_key] = NULL;
}
//======================================================================//

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

//__________________________Header_minPriorityQueue____________________//
typedef struct{
	ll* arr;	
	int size;
}minPriorityQueue;

minPriorityQueue new_minPriorityQueue(){
	minPriorityQueue pq;
	pq.arr = (ll*)malloc(maxn * sizeof(ll*));
	pq.size = 0;
	return pq;
}

void min_pq_up(minPriorityQueue *pq, int pos){
	if(pos==0 || pq->arr[pos]>pq->arr[pos/2]){
		return ;
	}
	ll temp = pq->arr[pos/2];
	pq->arr[pos/2] = pq->arr[pos];
	pq->arr[pos] = temp;
	min_pq_up(pq, pos/2);
}

void min_pq_add(minPriorityQueue *pq, ll n){
	pq->arr[pq->size] = n;
	min_pq_up(pq, pq->size);
	pq->size++;
}

ll min_pq_peek(minPriorityQueue* pq){
	return pq->arr[0];
}
void min_pq_down(minPriorityQueue*pq, int pos){
	int left = pos*2+1;
	int right = pos*2+2;
	if(pq->size<left)return ;
	if(pq->size<right){
		if(pq->arr[pos]<pq->arr[left]){
			return ;
		}
		ll temp = pq->arr[left];
		pq->arr[left] = pq->arr[pos];
		pq->arr[pos] = temp;
		return ;
	}
	if(pq->arr[left]<pq->arr[right]){
		ll temp = pq->arr[left];
		pq->arr[left] = pq->arr[pos];
		pq->arr[pos] = temp;
		min_pq_down(pq, left);
	}
	else{
		ll temp = pq->arr[right];
		pq->arr[right] = pq->arr[pos];
		pq->arr[pos] = temp;
		min_pq_down(pq, right);
	}
}

ll min_pq_poll(minPriorityQueue* pq){
	ll res = pq->arr[0];
	pq->arr[0] = pq->arr[pq->size];
	pq->size--;
	min_pq_down(pq, 0);
	return res;
}
//===========================================================================//

//______________________________maxPriorityQueue______________________________//
typedef struct{
	ll* arr;	
	int size;
}maxPriorityQueue;

maxPriorityQueue new_maxPriorityQueue(){
	maxPriorityQueue pq;
	pq.arr = (ll*)malloc(maxn * sizeof(ll*));
	pq.size = 0;
	return pq;
}

void max_pq_up(maxPriorityQueue *pq, int pos){
	if(pos==0 || pq->arr[pos]<pq->arr[pos/2]){
		return ;
	}
	ll temp = pq->arr[pos/2];
	pq->arr[pos/2] = pq->arr[pos];
	pq->arr[pos] = temp;
	max_pq_up(pq, pos/2);
}

void max_pq_add(maxPriorityQueue *pq, ll n){
	pq->arr[pq->size] = n;
	max_pq_up(pq, pq->size);
	pq->size++;
}

ll max_pq_peek(maxPriorityQueue* pq){
	return pq->arr[0];
}
void max_pq_down(maxPriorityQueue*pq, int pos){
	int left = pos*2+1;
	int right = pos*2+2;
	if(pq->size<left)return ;
	if(pq->size<right){
		if(pq->arr[pos]>pq->arr[left]){
			return ;
		}
		ll temp = pq->arr[left];
		pq->arr[left] = pq->arr[pos];
		pq->arr[pos] = temp;
		return ;
	}
	if(pq->arr[left]>pq->arr[right]){
		ll temp = pq->arr[left];
		pq->arr[left] = pq->arr[pos];
		pq->arr[pos] = temp;
		max_pq_down(pq, left);
	}
	else{
		ll temp = pq->arr[right];
		pq->arr[right] = pq->arr[pos];
		pq->arr[pos] = temp;
		max_pq_down(pq, right);
	}
}

ll max_pq_poll(maxPriorityQueue* pq){
	ll res = pq->arr[0];
	pq->arr[0] = pq->arr[pq->size];
	pq->size--;
	max_pq_down(pq, 0);
	return res;
}
//============================================================================//

//___________________________________Main_____________________________________//

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