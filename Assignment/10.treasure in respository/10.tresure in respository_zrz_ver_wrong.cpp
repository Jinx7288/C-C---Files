#include <cstdio>
double midnum(int a[], int sum)
{
    double s;
    if (sum % 2 != 0)
        return a[(sum - 1) / 2];
    else
    {
        s = (a[sum / 2] + a[sum / 2 - 1]) / 2.0;
        return s;
    }
}
int main()
{
    int n, i, j, sum = 0;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int b[sum], s = 0, q, p;
    for (i = 0; i < n; i++)
    {
        for (j = s; j < a[i] + s; j++)
        {
            b[j] = i + 1;
        }
        s += a[i];
    }
    scanf("%d", &q);
    while (q)
    {
        scanf("%d", &p);
        for (i = sum - p; i < sum; i++)
            b[i] = b[i + 1];
        sum--;
        printf("%.1lf\n", midnum(b, sum));
        q--;
    }
}