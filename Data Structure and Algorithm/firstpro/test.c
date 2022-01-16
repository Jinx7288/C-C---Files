#include<stdio.h>
int findindex(int li[],int n,int no)
{
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (m+li[i]>=no)
        {
            return i;
        }
        m += li[i];
    }
    return 0;
}
int main()
{
    int li[] = {2, 3, 1, 4, 2, 3, 6, 2, 4, 1, 6};
    for (int i = 0; i < 34; i++)
    {
        printf("%d\n", findindex(li, 11, i+1));
    }
    return 0;
}