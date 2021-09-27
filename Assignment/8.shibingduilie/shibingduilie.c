#include <stdio.h>
int a[5010];
int b[5010];
int process(int m)
{
    int temp = m;
    int count = m;

    for (int i = 0; i < m; i++)
    {
        a[i] = i;
        b[i] = 1;
    }
    while (temp>3)
    {
        temp = count;
        for (int i = 1,k=0; i < temp+1; i++)
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
        for (int i = 1,k=0; i < temp+1; i++)
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
    }
    for (int i = 0; i < temp; i++)
    {
        printf("%d", a[i]);
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