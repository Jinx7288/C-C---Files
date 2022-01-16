#include <bits/stdc++.h>
using namespace std;
#define rep(i, k, n) for (int i = k; i <= n; i++)
const int N = 2e5 + 10;
int p[N], col[N], num[N];
int tol, ans;
std::vector<int> v[N];
int Find(int x)
{
    return p[x] == x ? x : p[x] = Find(p[x]);
}
void unite(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
        p[y] = x;
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, 1, n)
    {
        cin >> col[i];
    }
    rep(i, 1, n) p[i] = i;
    int l, r;
    rep(i, 1, m)
    {
        cin >> l >> r;
        unite(l, r); //把颜色需要相同先放到一个集合中
    }
    rep(i, 1, n)
    {
        if (p[i] == i)
            num[i] = ++tol; // 给集合编号
    }
    rep(i, 1, n)
    {
        v[num[Find(i)]].push_back(col[i]); //每个集合中加入颜色
    }
    rep(i, 1, tol)
    {
        int sz = v[i].size();
        int mx = 0;
        std::map<int, int> mp;
        rep(j, 0, sz - 1)
        {
            mp[v[i][j]]++;
            mx = max(mx, mp[v[i][j]]); //找到集合中颜色最多的 把剩下的元素变成该颜色即可
        }
        ans += (sz - mx);
    }
    cout << ans << endl;
    return 0;
}