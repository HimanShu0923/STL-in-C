#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef long long lint;
#define get(i) get[i]
#define maxn 1000000
#define String char *
//...............Inputs..................................//
char *nextLine()
{
    char *temp = (char *)malloc(sizeof(char *) * maxn);
    scanf("%s", temp);
    return temp;
}
long long nextInt()
{
    lint t;
    scanf("%lld", &t);
    return t;
}
double nextDouble()
{
    double t;
    scanf("%lf", &t);
    return t;
}

//.......................................................//
//...............ArrayList...............................//
typedef struct
{
    long long *get;
    int length;
    int len;
} ArrayList;

int Lower_bound(ArrayList *arr, long long val, int s, int e)
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

int main()
{
    ArrayList arr2 = new_ArrayList();
    ArrayList arr = new_ArrayList();
    new_ArrayList(&arr);
    new_ArrayList(&arr2);
    printf("size: %d\n", arr.length);
    ArrayList_add(&arr, 1);
    ArrayList_add(&arr, 2);
    ArrayList_add(&arr2, 3);
    ArrayList_add(&arr2, 4);

    printf("size: %d\n", arr.length);
    for (int i = 0; i < arr.length; i++)
    {
        printf("arr: %lld", arr.get(i));
        printf("arr2: %lld", arr2.get(i));
    }
    printf("\n");
    String s1 = nextLine();
    int d = nextInt();
    printf("d : %d\n", d);
    printf("s1 : %s\n", s1);
    String s2 = nextLine();
    printf("s2 : %s\n", s2);
    printf("s1 : %s\n", s1);
}