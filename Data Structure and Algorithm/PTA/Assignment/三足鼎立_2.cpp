#include <algorithm>
#include <cstdio>
using namespace std;
long vl[100010];
int main()
{
    long m, n, ans,l,r;
    ans = 0;
    scanf("%d %d", &m, &n);
    for (long i = 0; i < m; i++)
    {
        scanf("%ld", &vl[i]);
    }
    sort(vl, vl + m);
    // printf("%ld", vl[2]);
    for (int i = 0; i < m; i++)
    {
        l = upper_bound(vl + i + 1, vl + m, abs(n - vl[i])) - vl;
        r = lower_bound(vl + i + 1, vl + m, n + vl[i]) - vl;
        ans += r-l;
    }
    printf("%d", ans);
    // return 0;
}