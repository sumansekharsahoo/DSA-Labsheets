#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int arr[m][n];
    int brr[m][n];
    int prev;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
            if (i == 0 && j == 0)
            {
                brr[0][0] = arr[0][0];
            }
            else
            {
                brr[i][j] = arr[i][j] + prev;
            }
            prev = brr[i][j];
        }
    }

    int ri, ci, rh, ch;
    scanf("%d %d %d %d", &ri, &ci, &rh, &ch);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", brr[i][j]);
        }
        printf("\n");
    }

    if ((ri + rh) > m || (ci + ch) > n)
    {
        printf("NOT POSSIBLE");
        // printf("%d %d", (ri + ch), (ci + rh));
    }

    else
    {
        int sum = 0;
        for (int i = ri; i < (ri + rh); i++)
        {
            for (int j = ci; j < (ci + ch); j++)
            {
                sum += brr[i][j];
            }
        }
        printf("%d", sum);
    }

    return 0;
}