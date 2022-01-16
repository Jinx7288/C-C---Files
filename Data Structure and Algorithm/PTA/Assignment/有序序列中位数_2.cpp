#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    int n, temp;
    // int flag = 0;
    queue<int> a;
    queue<int> b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        a.push(temp);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&temp);
        b.push(temp);
    }
    for (int i = 0; i < n-1; i++)
    {
        if (a.front() >= b.front())
        {
            b.pop();
        }
        else
        {
            a.pop();
        }
    }
    if (a.front() >= b.front())
    {
        printf("%d", b.front());
    }
    else
    {
        printf("%d", a.front());

    }
}