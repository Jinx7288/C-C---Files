#include<cstdio>
#include<algorithm>
using namespace std;
long vl[100010];
bool cmp(long a,long b) {
    return a > b;
}
int main()
{
    int m, n,l,r;
    long ans = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        scanf("%ld", &vl[i]);
    }
    sort(vl, vl + 100010,cmp);
    for (int i = 0; i < m; i++)
    {
        l = upper_bound(vl + i + 1, vl + m, abs(n - vl[i])) - vl;
        r = lower_bound(vl + i + 1, vl + m, n + vl[i]) - vl;
        ans += r - l;
    }
    printf("%ld", ans);
}