#include<stdio.h>
int main()
{
    int m = 7;
    printf("%d", m % 2 == 0 ? m / 2 : m / 2 + 1);
    return 0;
}