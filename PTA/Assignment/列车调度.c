#include<stdio.h>
#include<stdlib.h>
int n, a[100010], m, q[100010];
void insert(int x)
{
    if (!m)
        q[++m] = x;
    else
    {
        if(q[m]<x)
            q[++m] = x;
    }
    int l = 1,r = m, mid, ans = 1;
    while (l<=r)
    {
        mid = (l + r) >> 1;
        if (q[mid]>=x)
        {
            ans = mid;
            r = mid - 1;
        } else
        {
            l = mid + 1;
        }
    }
    q[ans] = x;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    printf("%d", m);
}