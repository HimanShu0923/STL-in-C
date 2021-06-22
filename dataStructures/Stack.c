#include<stdio.h>
#include<stdlib.h>

#define maxn 1000000
typedef long long ll;

// =======================Stack=========================//
typedef struct{
	ll* arr;	
	int size;
}Stack;

Stack new_Stack(){
	Stack stack;
	stack.arr = (ll*)malloc(maxn * sizeof(ll*));
	stack.size = 0;
	return stack;
}

void Stack_add(Stack *stack, ll n){
	stack->arr[stack->size] = n;
	stack->size++;
}

ll Stack_pop(Stack *stack ){
	ll res = stack->arr[stack->size-1];
	stack->size--;
	return res;
}
ll Stack_peek(Stack *stack){
	return stack->arr[stack->size-1];
}

int main(){
	Stack stack = new_Stack();
	Stack_add(&stack, 1);
	Stack_add(&stack, 2);
	Stack_add(&stack, 3);
	Stack_add(&stack, 4);
	printf("Peek: %lld\n", Stack_peek(&stack));
	printf("Remove: %lld\n", Stack_pop(&stack));
	printf("Remove: %lld\n", Stack_pop(&stack));
	printf("Remove: %lld\n", Stack_pop(&stack));
}