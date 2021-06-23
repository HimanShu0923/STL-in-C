#include <stdio.h>
typedef long long ll;
//___________________________Header_Arrays_____________________________//

int Arrays_upper(ll *arr, ll val, int s, int e)
{
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == val)
            return mid;
        if (arr[mid] > val)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return e + 1;
}
ll Arrays_sort(ll *arr, int s, int e)
{
    if (s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    ll inv1 = Arrays_sort(arr, s, mid);
    ll inv2 = Arrays_sort(arr, mid + 1, e);
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
                arr2[pos] = arr[i];
                pos++;
            }
            break;
        }
        if (po2 == e + 1)
        {
            for (int i = po1; i <= mid; i++)
            {
                arr2[pos] = arr[i];
                pos++;
            }
            break;
        }
        if (arr[po1] <= arr[po2])
        {
            arr2[pos] = arr[po1];
            po1++;
            pos++;
        }
        else
        {
            arr2[pos] = arr[po2];
            po2++;
            pos++;
            temp += (mid - po1 + 1);
        }
    }
    for (int i = 0, j = s; j <= e; i++, j++)
    {
        arr[j] = arr2[i];
    }

    return inv1 + inv2 + temp;
}
void Arrays_reverse(ll *arr, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        ll temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

//====================================================================//
int main(){
	ll arr[10] = {5, 2,45,6,3,1,5,7,3,2};
	for(int i=0;i<10;i++){
		printf("%lld ", arr[i]);
	}
	printf("\n");
	Arrays_sort(&arr[0], 0, 9);
	for(int i=0;i<10;i++){
		printf("%lld ", arr[i]);
	}
	printf("\n");
	return 0;
}