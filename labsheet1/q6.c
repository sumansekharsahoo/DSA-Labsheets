#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int max = 0;
    int indx;
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = a; i <= b; i++)
    {
        if (isPrime(i))
        {
            int temp;
            int no = i;
            while (no != 0)
            {
                temp = no % 10;
                no /= 10;
                arr[temp]++;
                if (arr[temp] > max)
                {
                    max = arr[temp];
                    indx = temp;
                }
            }
        }
    }
    printf("%d %d ", indx, max);
    return 0;
}