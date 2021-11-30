#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> db;
vector<db> data;
set<string> data_set;
int main()
{
    int q, n, temp1, temp2, ans,count;
    int minus = 0;
    scanf("%d", &q);
    map<int, int> left;
    map<int, int> right;
    map<string, int> depre;
    for (int k = 0; k < q; k++)
    {
        scanf("%d", &n);
        ans = 0;
        for (int mj = 0; mj < n; mj++)
        {
            scanf("%d %d", &temp1, &temp2);
            db c = make_pair(temp1, temp2);
            data.push_back(c);
            string cc = to_string(temp1).append(to_string(temp2));
            if (data_set.count(cc)!=0)
            {
                if (depre[cc]!=0)
                {
                    depre[cc]++;
                } else
                {
                    depre[cc] = 1;
                }
            } else
            {
                data_set.insert(cc);
            }
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
        for (map<string,int>::iterator iter = depre.begin(); iter!=depre.end(); iter++)
        {
            int sss = iter->second+1;
            ans -=sss*(sss-1)/2;
        }
        printf("%d\n", ans);
        data.clear();
        data_set.clear();
        left.clear();
        right.clear();
        depre.clear();
    }
    return 0;
}