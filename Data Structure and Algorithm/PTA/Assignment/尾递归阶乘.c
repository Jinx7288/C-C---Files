#include<stdio.h>

int factTR(int n, int a)
{
    if (n == 0)
        return 
a
;
    return factTR(n - 1, a*n);/*尾递归*/
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", factTR(n, 1));
    return 0;
}