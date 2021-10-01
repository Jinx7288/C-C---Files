#include<stdio.h>
int a[2000020]={0};
int main() 
{
    int n,temp;
    int count = 0;
    int anc = 0;
    scanf("%d",&n);
    for (int i = 0; i < 2*n; i++)
    {
        scanf("%d", &temp);  
        if (a[temp+1000010]==0)
        {
            count++;
        }  
        a[temp+1000010] += 1;
    }
    // printf("%d", a[100001]);
    // printf("%d", count);
    for (int i = 0; i < 2000020; i++)
    {
        if (a[i]!=0)
        {
            anc += 1;
            if (anc==(count%2==0?count/2:(count+1)/2))
            {
                printf("%d", i-1000010);
            }
            // printf("%d", anc);
        }
    }
}