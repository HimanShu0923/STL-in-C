#include <stdio.h>
#include <stdlib.h>

//...............ArrayList...............................//
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
void ArrayList_add(ArrayList *arr, ll n)
{
    int n1 = arr->length;
    int n2 = arr->len;
    if (n1 + 1 == n2)
    {
        arr->get = (long long *)realloc(arr->get, sizeof(ll *) * n2 * 2);
        arr->len = n2 * 2;
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

int ArrayList_upper(ArrayList *arr, long long val, int s, int e)
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

//............................................................//

int main()
{
    ArrayList arr = new_ArrayList();
    ArrayList_add(&arr, 10);
    ArrayList_add(&arr, 10);
    ArrayList_add(&arr, 10);
    ArrayList_add(&arr, 2);
    ArrayList_add(&arr, 41);
    ArrayList_add(&arr, 5);
    printf("Hello");
    printf("size: %d\n", arr.length);
    for (int i = 0; i < arr.length; i++)
    {
        printf("%lld ", arr.get(i));
    }
    printf("\n");
    printf("Sorted Array\n");

    ArrayList_sort(&arr, 0, arr.length - 1);
    for (int i = 0; i < arr.length; i++)
    {
        printf("%lld ", arr.get(i));
    }
    printf("\n");

    printf("Upper Bound 11: %lld\n", arr.get(ArrayList_upper(&arr, 11, 0, arr.length - 1)));

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
    free(arr.get);
    return 0;
}
