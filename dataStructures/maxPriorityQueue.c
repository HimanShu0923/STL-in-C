#include<stdio.h>
#include<stdlib.h>

#define maxn 1000000
typedef long long ll;

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
	if(pos==0 || pq->arr[pos]<pq->arr[(pos-1)/2]){
		return ;
	}
	ll temp = pq->arr[(pos-1)/2];
	pq->arr[(pos-1)/2] = pq->arr[pos];
	pq->arr[pos] = temp;
	max_pq_up(pq, (pos-1)/2);
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
	if(pq->size<=left)return ;
	if(pq->size<=right){
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
    if(pq->size==0){
        return -1;
    }
	ll res = pq->arr[0];
	pq->arr[0] = pq->arr[pq->size-1];
	pq->size--;
	max_pq_down(pq, 0);
	return res;
}
//============================================================================//

int main(){
	maxPriorityQueue pq = new_maxPriorityQueue();
	max_pq_add(&pq, 4);
	max_pq_add(&pq, 3);
	max_pq_add(&pq, 5);
	max_pq_add(&pq, 7);
	max_pq_add(&pq, 1);
	printf("%lld", max_pq_peek(&pq));
	printf("\nRemove: %lld\n", 	max_pq_poll(&pq));
	printf("%lld", max_pq_peek(&pq));

	return 0;
}
