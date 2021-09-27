#include<stdio.h>
int cache[100010]={0};
int li[100010];
int main()
{
    int n, m,i;
    int ansnum=0;
    // count = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &li[i]);
    }
    for (i = 0; i < m; i++)
    {
        cache[li[i]] += 1;
        if (cache[li[i]]==3)
        {
            cache[li[i]]= 0;
            ansnum += 1;
        }
    }
    // printf("%d\n", ansnum);
    for (i = m; i < n; i++)
    {
        cache[li[i]] += 1;
        if (cache[li[i]]==3)
        {
            cache[li[i]]= 0;
            ansnum += 1;
        }
        if (cache[li[i - m]]!=cache[li[i]])
        {
            cache[li[i - m]] -= 1;
        }
    }
    printf("%d", ansnum);
    return 0;
}