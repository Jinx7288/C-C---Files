#include<stdio.h>
int cache[100010]={0};
int li[100010];
int main()
{
    int n, m,i,j;
    int ansnum=0;
    int sum = 0;
    // count = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &li[i]);
    }
    sum = m;
    for (i = 0; i < m; i++)
    {
        if (cache[li[i]]+1==3)
        {
            cache[li[i]]= 0;
            ansnum += 1;
            sum -= 3;
        } else
        {
            cache[li[i]] += 1;
            sum += 1;
        }
    }
    for (i = m; i < n; i++)
    {
        cache[li[i]] += 1;
        if (cache[li[i]]==3)
        {
            cache[li[i]]= 0;
            ansnum += 1;
            sum += 1;
        }
        if (sum==m)
        {
            for (j = i - m; j < i; j++)
            {
                if (cache[li[j]]!=0)
                {
                    cache[li[j]] -= 1;
                    sum -= 1;
                    break;
                } 
            }
        }
    }
    printf("%d\n", ansnum);
    return 0;
}