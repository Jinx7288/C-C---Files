#include<stdio.h>
int li[1000100];
int cache[1000100]={0};
int main()
{
    int n, m,count,i,last;
    int ansnum=0;
    // int temp;
    scanf("%d %d", &n, &m);
    count = 0;
    for (i = 0; i < m; i++)
    {    
        scanf("%d", &li[i]);
        if (count==0)
        {
            last = li[i];
        }
        if (cache[li[i]]+1==3)
        {
            cache[li[i]]= 0;
            ansnum += 1;
            count -= 2;
        } else
        {
            cache[li[i]] += 1;
            count += 1;
        }
    }
    for (i = m; i < n; i++)
    {
        scanf("%d", &li[i]);
        if (count==0)
        {
            last = li[i];
        }
        if (count==m)
        {
            if (cache[li[i]]+1==3)
            {
                cache[li[i]]= 0;
                ansnum += 1;
                count -= 2;
            } else
            {
                cache[li[i]] += 1;
                cache[last] -= 1;
            }
        } else
        {
            if (cache[li[i]]+1==3)
            {
                cache[li[i]]= 0;
                ansnum += 1;
                count -= 2;
            }
            else
            {
                cache[li[i]] += 1;
                count += 1;
            } 
        }  
    }
    printf("%d", ansnum);
    return 0;
}