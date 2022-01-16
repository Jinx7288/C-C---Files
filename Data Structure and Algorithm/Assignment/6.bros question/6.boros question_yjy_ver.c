#include <stdio.h>
int main()
{
    int i, f = 0, num;
    double li[205], sum = 0;
    char symbol, a;
    scanf("%d ", &num);
    li[f] = 1.0 * num;
    while (!0)
    {
        scanf("%c %d%c", &symbol, &num, &a);
        if (symbol == '+')
        {
            f++;
            li[f] = 1.0 * num;
        }
        if (symbol == '-')
        {
            f++;
            li[f] = -1.0 * num;
        }
        if (symbol == '*')
        {
            li[f] = li[f] * (num * 1.0);
        }
        if (symbol == '/')
        {
            li[f] = li[f] / (num * 1.0);
        }
        if (a != ' ')
        {
            break;
        }
    }
    for (i = 0; i <= f; i++)
    {
        sum += li[i];
    }
    printf("%.2lf", sum);
}