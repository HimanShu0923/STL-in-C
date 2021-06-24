#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef long long ll;
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
//...............ArrayList...............................//
typedef struct
{
    long long *get;
    int length;
    int len;
} ArrayList;

ll ArrayList_sort(ArrayList *arr,int s,int e)
{
    if(s>=e)
    {
        return 0;
    }
    int mid  = (s+e)/2;
    ll inv1=ArrayList_sort(arr,s,mid);
    ll inv2=ArrayList_sort(arr,mid+1,e);
    ll temp=0;
    ll arr2[e-s+1];
    int po1=s,po2=mid+1,pos=0;
    while(1)
    {
        if(po1 == mid+1 && po2 == e+1)
            break;
        if(po1 == mid+1)
        {
            for(int i = po2;i<=e;i++)
            {
                arr2[pos] = arr->get(i);
                pos++;
            }
            break;
        }
        if(po2 == e+1)
        {
            for(int i=po1;i<=mid;i++)
            {
                arr2[pos] = arr->get(i);
                pos++;
            }
            break;
        }
        if(arr->get(po1)<=arr->get(po2))
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
            temp+= (mid-po1+1);
        }
    }
    for(int i=0,j=s;j<=e;i++,j++)
    {
        arr->get(j) = arr2[i];
    }

    return inv1+inv2+temp;
}
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
    ArrayList arr = new_ArrayList();
    // new_ArrayList(&arr);
    int n = nextInt();
    for(int i=0;i<n;i++)
        ArrayList_add(&arr, nextInt());
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ",arr.get(i));
    }
    printf("\n");

    ll inv = ArrayList_sort(&arr,0,n-1);
    for (int i = 0; i < arr.length; i++)
    {
        printf("%d ",arr.get(i));
    }
    printf("\n");
    printf("Inversions : %lld",inv);

}