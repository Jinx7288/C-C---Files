#include<stdio.h>
int cache[100010]={0};
int main()
{
    int n, m;
    int ansnum=0;
    int temp;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp);
        cache[temp] += 1;
        if (cache[temp]==3)
        {
            ansnum += 1;
            cache[temp] = 0;
        }
    }
    int frca = 0;
    for (int i = m; i < n; i++)
    {
        scanf("%d", &temp);
        cache[temp] += 1;
        if (cache[temp]==3)
        {
            ansnum += 1;
            cache[temp] = 0;
        }
    }
    
    printf("%d", ansnum);
    return 0;
}