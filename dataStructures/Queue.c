#include<stdio.h>
#include<stdlib.h>

#define maxn 1000000
typedef long long ll;

// =======================Queue=========================//
typedef struct{
	ll* arr;	
	int size;
	int start;
}Queue;

Queue new_Queue(){
	Queue q;
	q.arr = (ll*)malloc(maxn * sizeof(ll*));
	q.size = 0;
	q.start = 0;
	return q;
}

void Queue_add(Queue *q, ll n){
	q->arr[q->size] = n;
	q->size++;
}

ll Queue_remove(Queue *q ){
	if(q->start==q->size){
		return 0;
	}
	ll res = q->arr[q->start];
	q->start++;
	return res;
}
ll Queue_peek(Queue *q){
	if(q->start==q->size)return 0;
	return q->arr[q->start];
}

int main(){
	Queue q = new_Queue();
	Queue_add(&q, 1);
	Queue_add(&q, 2);
	Queue_add(&q, 3);
	Queue_add(&q, 4);
	printf("Peek: %lld\n", Queue_peek(&q));
	printf("Remove: %lld\n", Queue_remove(&q));
	printf("Remove: %lld\n", Queue_remove(&q));
	printf("Remove: %lld\n", Queue_remove(&q));
}