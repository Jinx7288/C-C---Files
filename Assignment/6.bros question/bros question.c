#include<stdio.h>
int s[600100];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    int *p;
    p = s;
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        flag = 1;
        for (int j = i+1; flag==1 && *(p+j); j++)
        {
            if (*(p+j)>=*(p+i))
            {
                printf("%d ", j);
                flag = 0;
                break;
            }
        }
        if (flag==1)
            {
                printf("%d ", -1);
            }
    }
    return 0;
}