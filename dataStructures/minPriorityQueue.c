#include<stdio.h>
#include<stdlib.h>

#define maxn 1000000
typedef long long ll;

// =======================Min Heap/PriorityQueue=========================//
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
    if (pos == 0 || pq->arr[pos] > pq->arr[(pos - 1) / 2])
    {
        return;
    }
    ll temp = pq->arr[(pos - 1) / 2];
    pq->arr[(pos - 1) / 2] = pq->arr[pos];
    pq->arr[pos] = temp;

    pq_up(pq, (pos - 1) / 2);
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
    if (pq->size <= left)
        return;
    if (pq->size <= right)
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
    if (pq->size == 0)
        return -1;
    ll res = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    pq_down(pq, 0);
    return res;
}


//===============================================================//

int main(){
	PriorityQueue pq = new_PriorityQueue();
	pq_add(&pq, 4);
	pq_add(&pq, 3);
	pq_add(&pq, 5);
	pq_add(&pq, 7);
	pq_add(&pq, 1);
	printf("%lld", pq_peek(&pq));
	printf("\nRemove: %lld\n", 	pq_poll(&pq));
	printf("%lld", pq_peek(&pq));

	return 0;
}
