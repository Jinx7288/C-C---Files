#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> db;
vector<db> data;
int main()
{
    int q, n,temp1,temp2,ans;
    set<int> left;
    set<int> right;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &n);
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &temp1, &temp2);
            db c = make_pair(temp1, temp2);
            data.push_back(c);
        }
        for (int i = n-1; i >0; i--)
        {
            for (int j = i-1; j >=0; j--)
            {
                int ca1 = data[i].first;
                int ca2 = data[j].second;
                if (left.count(ca1)!=0&&right.count(ca2)!=0)
                {
                    ans--;
                }
                if (left.count(ca1)!=0)
                {
                    ans++;
                    right.insert(ca2);
                }
                if (right.count(ca2)!=0)
                {
                    ans++;
                    left.insert(ca1);
                }
                if (left.count(ca1)==0 && right.count(ca2)==0)
                {
                    left.insert(ca1);
                    right.insert(ca2);
                }
            }
        }
        printf("%d\n", ans);
        left.clear();
        right.clear();
        data.clear();
    }
}