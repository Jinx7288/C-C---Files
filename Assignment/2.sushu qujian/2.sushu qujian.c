#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Suornot(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    int k = sqrt(n);
    for (int i = 2; i < k + 1; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int totalTime;
    scanf("%d", &totalTime);
    int anss[100000];
    for (int i = 0; i < totalTime; i++)
    {
        int in;
        scanf("%d", &in);
        int left = in - 1;
        int right = in + 1;
        if (Suornot(in))
        {
            printf("0");
        }
        else
        {
            while (!Suornot(left))
            {
                left -= 1;
            }
            while (!Suornot(right))
            {
                right += 1;
            }
           anss[i]=right-left-1;
        }
    }
    for (int i = 0; i < totalTime; i++)
    {
        printf("%d\n", anss[i]);
    }
    
}
