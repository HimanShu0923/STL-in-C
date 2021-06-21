#include<stdio.h>
#include<stdlib.h>


//...............ArrayList...............seg error................//
#define get(i) get[i]
typedef long long ll;
typedef struct
{
    long long *get;
    int length;
    int len;
} ArrayList;

ArrayList new_ArrayList()
{
    ArrayList arr;
    arr.get = (long long *)calloc(2, sizeof(long long *));
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
        arr->get = (long long *)realloc(arr->get, arr->len * 2);
        arr->len = arr->len * 2;
    }
    arr->get[arr->length++] = n;
}

void ArrayList_rev(ArrayList *arr){
	int n = arr->length;
	for(int i=0;i<n/2;i++){
		ll temp = arr->get[i];
		arr->get[i] = arr->get[n-i-1];
		arr->get[n-i-1] = temp;
	}
}

void ArrayList_merge(ArrayList *arr, int start, int end){
	if(start==end){
		return;
	}
	int mid = start+(end-start)/2;
	ArrayList_merge(arr, start, mid);
	ArrayList_merge(arr, mid+1, end);

	// Merge
	int p1 = start;
	int p2 = mid+1;
	int cur = 0;

	ll temp[end-start+1];
	for(int i=0;i<end-start+1;i++){
		temp[i] = 0;
	}

	while(p1<=mid && p2<=end){
		if(arr->get[p1]<arr->get[p2]){
			temp[cur++] = arr->get[p1];
			p1++;
		}
		else{
			temp[cur++] = arr->get[p2];
			p2++;
		}
	}
	while(p1<=mid){
		temp[cur++] = arr->get[p1++];
	}
	while(p2<=end){
		temp[cur++] = arr->get[p2++];
	}

	cur = 0;
	for(int i=start;i<=end;i++){
		arr->get[i] = temp[cur++];
	}
}

void ArrayList_sort(ArrayList *arr){
	ArrayList_merge(arr, 0, arr->length-1);
}
//............................................................//

int main(){
    ArrayList arr = new_ArrayList();
    ArrayList_add(&arr, 10);
    ArrayList_add(&arr, 2);
    ArrayList_add(&arr, 41);
    ArrayList_add(&arr, 5);

    printf("size: %d\n", arr.length);
    for (int i = 0; i < arr.length; i++)
    {
        printf("%lld ", arr.get(i));
    }
    printf("\n");
    printf("Sorted Array\n");

	ArrayList_sort(&arr);
    for (int i = 0; i < arr.length; i++)
    {
        printf("%lld ", arr.get(i));
    }
    printf("\n");
    printf("Reversed Array\n");

	ArrayList_rev(&arr);
    printf("size: %d\n", arr.length);
    for (int i = 0; i < arr.length; i++)
    {
        printf("%lld ", arr.get(i));
    }
    printf("\n");

	ArrayList_pop(&arr);
    for (int i = 0; i < arr.length; i++)
    {
        printf("%lld ", arr.get(i));
    }
	return 0;
}
