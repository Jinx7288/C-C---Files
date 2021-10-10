#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
int li[1000];
int main()
{
    int n;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &li[i]);
    }
    sort(li,li+n);
    for (int i = 0; i < n; i+=2)
    {
        // printf("%d ", li[i]);
        ans += li[i + 1] - li[i];
    }
    printf("%d", ans);
    return 0;
}