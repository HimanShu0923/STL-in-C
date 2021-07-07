#include<stdio.h>
#include<stdlib.h>


//...............ArrayList...............................//
#define get(i) get[i]

typedef struct
{
    long long *get;
    int length;
    int len;
} ArrayList;

int lower_bound(ArrayList *arr, long long val, int s, int e)
{
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr->get(mid) == val)
            return mid;
        if (arr->get(mid) > val)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return e + 1;
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
void ArrayList_remove(ArrayList *arr, int idx)
{
	for(int i=idx;i<arr->length-1;i++){
		arr->get[i] = arr->get[i+1];
	}
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
//............................................................//

int main(){
    ArrayList arr2 = new_ArrayList();
    ArrayList arr = new_ArrayList();
    printf("size: %d\n", arr.length);
    ArrayList_add(&arr, 1);
    ArrayList_add(&arr, 2);
    ArrayList_add(&arr, 3);
    ArrayList_add(&arr, 4);
    // ArrayList_add(&arr2, 3);
    // ArrayList_add(&arr2, 4);

    printf("size: %d\n", arr.length);
    for (int i = 0; i < arr.length; i++)
    {
        printf("arr: %lld", arr.get(i));
        // printf(" arr2: %lld", arr2.get(i));
    	// printf("\n");
    }
    printf("\n");
    ArrayList_remove(&arr, 2);
    for (int i = 0; i < arr.length; i++)
    {
        printf("arr: %lld", arr.get(i));
        // printf(" arr2: %lld", arr2.get(i));
    	// printf("\n");
    }
    printf("\n");
    ArrayList_pop(&arr);
    for (int i = 0; i < arr.length; i++)
    {
        printf("arr: %lld", arr.get(i));
        // printf(" arr2: %lld", arr2.get(i));
    	// printf("\n");
    }
    printf("\n");
    ArrayList_add(&arr, 69);
    for (int i = 0; i < arr.length; i++)
    {
        printf("arr: %lld", arr.get(i));
        // printf(" arr2: %lld", arr2.get(i));
    	// printf("\n");
    }

    printf("\n");
}
