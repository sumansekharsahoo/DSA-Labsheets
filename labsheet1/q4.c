#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkreq(int arr[], int neg)
{
    for (int i = 0; i < neg; i++)
    {
        if (arr[i] > 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int neg = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] < 0)
        {
            neg++;
        }
    }

    int temp;
    while (!(checkreq(arr, neg)))
    {
        for (int i = 0; i < n - 1; i++)
        {

            if (arr[i] > 0 && arr[i + 1] < 0)
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