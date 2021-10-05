#include<stdio.h>
int a[108];
int b[108];
int ans[108];
int main() 
{
    int n,temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", temp);
        a[i] = temp;
        b[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", ans[i]);
    }
    
}