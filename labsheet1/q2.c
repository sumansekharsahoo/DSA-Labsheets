#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int subarr(int arr[], int sub[], int sz, int bz) // returns index of 1st element if "sub" is subarray of "arr" else returns -1
{

    int ct = 0;
    for (int i = 0; i <= (bz - sz); i++)
    {
        if (arr[i] == sub[0])
        {
            ct++;
            for (int j = 1; j < sz; j++)
            {
                if (arr[i + j] == sub[j])
                {
                    ct++;
                }
                else
                {
                    ct = 0;
                    break;
                }
            }
            if (ct == sz)
            {
                return i;
            }
        }
    }
    return -1;
}

// howmuch similar
int hmsimilar(int bar[][], int sar[][], int m, int n, int p, int q)
{
    int val = 0;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int pos = subarr(bar[j], sar[i], q, n);
            if (pos >= 0)
            {
                if (i == 0 && (j + p) <= m)
                {
                    for (int k = 1; k < p; k++)
                    {
                        if (subarr(bar[j + k], sar[k], q, n) == pos)
                        {
                            return INT_MAX;
                        }
                        else
                        {
                            val++;
                        }
                    }
                }
                val++;
            }
        }
    }
    if (val > 0)
    {
        return val;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int m, n, p, q;
    scanf("%d %d", &m, &n);
    int rar[m][n];
    int car[n][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &rar[i][j]);
            car[j][i] = rar[i][j];
        }
    }

    scanf("%d %d", &p, &q);
    int frar[p][q];
    int fcar[q][p];
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            scanf("%d", &frar[i][j]);
            fcar[j][i] = frar[i][j];
        }
    }

    int resr = hmsimilar(rar, frar, m, n, p, q);
    int resc = hmsimilar(car, fcar, n, m, q, p);
    if (resc < 0 && resr < 0)
    {
        printf("NO");
    }
    else if (resr == INT_MAX)
    {
        printf("YES");
    }
    else
    {
        printf("PARTIAL");
    }

    return 0;
}