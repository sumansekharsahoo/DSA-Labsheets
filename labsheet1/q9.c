#include <stdio.h>
#include <stdlib.h>

int incorrect(int arr[], int ct, int mid)
{
    if (arr[ct] != mid)
    {
        return 1;
    }
    else
    {
        for (int i = 0; i < ct; i++)
        {
            if (arr[i] > mid)
            {
                return 1;
            }
        }
        return 0;
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &k, &n);
    int mid = (1 + k) / 2;
    int arr[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] < mid)
        {
            count++;
        }
    }
    int temp;
    while (incorrect(arr, count, mid))
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > mid && arr[i + 1] <= mid)
            {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
            else if (arr[i] == mid && arr[i + 1] < mid)
            {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}