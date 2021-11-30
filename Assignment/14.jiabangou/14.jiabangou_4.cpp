#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> db;
vector<db> data;
set<db> data_set;
int main()
{
    int q, n, temp1, temp2, ans,count;
    int minus = 0;
    scanf("%d", &q);
    map<int, int> left;
    map<int, int> right;
    for (int k = 0; k < q; k++)
    {
        scanf("%d", &n);
        ans = 0;
        for (int mj = 0; mj < n; mj++)
        {
            scanf("%d %d", &temp1, &temp2);
            db c = make_pair(temp1, temp2);
            data.push_back(c);
            data_set.insert(c);
        }
        for (int i = 0; i < n; i++)
        {
            int ca1 = data[i].first;
            int ca2 = data[i].second;
            if (left.count(ca1)==0)
            {
                left[ca1] = 1;
            } else
            {
                left[ca1]++;
            }
            if (right.count(ca2)==0)
            {
                right[ca2] = 1;
            } else
            {
                right[ca2]++;
            }
        }
        for (map<int,int>::iterator ter1 = left.begin(); ter1 !=left.end(); ter1++)
        {
            int ca = ter1->second * (ter1->second - 1) / 2;
            ans += ca;
        }
        for (map<int,int>::iterator ter2 = right.begin(); ter2 !=right.end(); ter2++)
        {
            int ca = ter2->second * (ter2->second - 1) / 2;
            ans += ca;
        }
        int sss = data.size() - data_set.size()+1;
        ans -=sss*(sss-1)/2;
        printf("%d\n", ans);
        data.clear();
        data_set.clear();
        left.clear();
        right.clear();
    }
    
}