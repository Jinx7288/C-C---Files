#include<stdio.h>
#include<stdlib.h>
int sum[10000010];
int s[10000010];
int main()
{
    int n,m,a;
    int ans,maxn;
    scanf("%d %d", &n, &m);
    sum[0] = s[0] = 0;
    ans = 0;
    maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        sum[i] = sum[i - 1] + a;
        s[i] = s[i - 1] + sum[i];
    }
    for(int i=m;i<=n;i++)
    {
        ans=m*sum[i]-(s[i-1]-s[i-1-m]);
        if(ans>maxn)
            maxn=ans;
    }
    
    printf("%d", maxn);
    return 0;
}