#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

//=====================================================================//

int main(){
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