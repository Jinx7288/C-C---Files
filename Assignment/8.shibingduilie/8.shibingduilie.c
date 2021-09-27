#include <stdio.h>
int a[5010];
int b[5010];
int process(int m)
{
    int temp = m;
    int count = m;
    for (int i = 1; i < m+1; i++)
    {
        a[i] = i;
        b[i] = 1;
    }
    while (count>3)
    {
        temp = count;
        for (int i = 1,k=1; i < temp+1; i++)
        {
            if (i%2==0)
            {
                b[a[i]] = 0;
                count--;
            } else
            {
                a[k] = a[i];
                ++k;
            }
        }
        temp = count;
        // printf("%d\n", count);
        // for (int i = 0; i < m; i++)
        // {
        //     printf("%d ", a[i+1]);
        //     // printf("%d ", b[i]);
        // }
        if (count<=3)
        {
            break;
        }
        for (int i = 1,k=1; i < temp+1; i++)
        {
            if (i%3==0 && b[a[i]]==1)
            {
                b[a[i]] = 0;
                count--;
            } else
            {
                a[k] = a[i];
                ++k;
            }
        }
        //  printf("%d\n", count);
        // for (int i = 0; i < m; i++)
        // {
        //     printf("%d ", a[i+1]);
        // // printf("%d ", b[i]);
        // }

    }
    for (int i = 1; i <=count; i++)
    {
        if (i==count)
        {
            printf("%d\n", a[i]);
            break;
        }    
        printf("%d ", a[i]);
    }
    return 0;
}
int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &m);
        process(m);
    }
}