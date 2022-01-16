#include<cstdio>
#include<algorithm>
using namespace std;
long vl[10010];
bool cmp(long a,long b) {
    return a > b;
}
int main()
{
    int m, n,ans;
    ans = 0;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        scanf("%ld", &vl[i]);
    }
    sort(vl, vl + 10010,cmp);
    // for (int i = 0; i < 100; i++)
    // {
    //     printf("%d", vl[i]);
    // }
    for (int i = 0; i < m; i++)
    {
        for (int j = i+1; j < m; j++)
        {
            if (vl[i]+vl[j]>n&&n+vl[j]>vl[i]&&vl[i]+n>vl[j])
            {
                ans += 1;
            }
            
        }
    }
    printf("%d", ans);
}