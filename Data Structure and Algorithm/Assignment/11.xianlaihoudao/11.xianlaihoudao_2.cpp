#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int n, m;
    int x, y;
    cin >> n >> m;
    set<int>s;//0,m+1;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (i == 0) {
            for (int j = x; j <= y; j++) {
             s.insert(j); }
            cout << "ACCEPTED" << endl;
        }
        else {
            set<int>::iterator it = s.lower_bound(x);
            if (it != s.end() && (*it) <= y) {
                cout << "REJECTED" << endl; 
            }
            else {
                cout << "ACCEPTED" << endl;
                for (int j = x; j <= y; j++) {
                    s.insert(j);
                }
            }
        }
    }
        return 0;
    
}