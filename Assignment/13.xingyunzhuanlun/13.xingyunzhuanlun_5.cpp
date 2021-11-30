#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;

const int T = 10007;

inline int read() {
    int flag = 1;
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch>'9') {
        if (ch == '-') {
            flag = -1;
        }
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0') {
        ans = (ans << 1) + (ans << 3) + (ch ^ 48);
        ch = getchar();
    }
    return ans * flag;
}

int cnt;
vector<int> a, d;

int b[1007];
int c[1000007];

signed main() {

    int n = read();

    for (int i = 1; i <= n; ++i) {
        a.push_back(-read());
    }

    for (int i = 1; i <= n; ++i) {
        b[i] = read();
    }

    for (int i = 1; i <= n * n; i += n) {
        int temp = read();
        for (int j = 1; j <= n; ++j) {
            c[i + j - 1] = temp * b[j];
        }
    }

    sort(c + 1, c + 1 + n * n);

    for (int i = 1; i <= n; ++i) {
        int temp = read();
        for (int j : a) {
            int t = temp + j;
            int t1 = lower_bound(1 + c, c + 1 + n * n, t) - c;
            if (c[t1] != t) {
                continue;
            }
            int t2 = upper_bound(1 + c, 1 + c + n * n, t) - c;
            cnt += t2 - t1;
        }
    }

    printf("%lld", cnt);
    return 0;
}