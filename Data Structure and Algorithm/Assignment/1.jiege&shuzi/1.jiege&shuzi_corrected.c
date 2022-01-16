#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int *getList(int n)
{
    int list[100010];
    // int list2[100010];
    int i = 0;
    int temp;
    while (n)
    {
        temp = n % 10;
        n = n / 10;
        list[i] = temp;
        i++;
    }
    return list;
}
int main()
{
    int in;
    int ans = 0;
    scanf("%d", in);
    for (int i = 1; i <= sqrt(in); i++)
    {
        if (in%i==0)
        {
            
        }
        
    }
    
}