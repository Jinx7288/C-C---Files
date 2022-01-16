#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> db;
set<db> data;
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
            data.insert(c);
        }
        for (set<db>::iterator i = data.end(); i !=data.begin(); i--)
        {
            for (set<db>::iterator j = i; j !=data.begin(); j--)
            {
                int ca1 = i->first;
                int ca2 = j->second;
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