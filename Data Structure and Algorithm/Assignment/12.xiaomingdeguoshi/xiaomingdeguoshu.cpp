#include <iostream>  
#include <vector>    
#define maxn 100005  
using namespace std;    
vector<int> E[maxn], dp(maxn), v(maxn);    
int dfs(int u, int fa) {    
    int bo = (v[u] ? 1 : 0);    
    for(int i = 0; i < (int)E[u].size(); i++) {  
        int  t = E[u][i];
        if(t != fa) {
             if(dfs(t, u)) {  
                bo = 1;  
                dp[u] += dp[t] + 2;  
            }
        }    
    }   
    return bo;    
}    
int main(void) {    
    int n, m, s, t, k;  
    cin >> n >> m;  
    for(int i = 0; i < n - 1; i++) {  
        cin >> s >> t;  
        if(s > t) swap(s, t);
        E[s].push_back(t);    
        E[t].push_back(s);
    }   
    for(int i = 0; i < m; i++) {  
        cin >> k, v[k] = 1;  
    }  
    dfs(1, -1);
    cout << dp[1] << endl;    
    return 0;    
}    
 