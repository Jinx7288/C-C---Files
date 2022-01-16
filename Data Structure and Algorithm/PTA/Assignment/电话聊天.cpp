#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string temp1, temp2;
    scanf("%d", &n);
    map<string, int> dict;
    vector<string> ans;
    for (int i = 1; i <= n; i++)
    {
        // scanf("%s %s", temp1, temp2);
        cin >> temp1 >> temp2;
        if (!dict.count(temp1))
            dict[temp1] = 1;
        else
            dict[temp1]++;
        if (!dict.count(temp2))
            dict[temp2] = 1;
        else
            dict[temp2]++;
    }
    map<string, int>::iterator iter;
    map<int, int> dict2;
    for (iter = dict.begin(); iter != dict.end(); iter++)
    {
        if (!dict2.count(iter->second))
            dict2[iter->second] = 1;
        else
            dict2[iter->second] += 1;
    }
    map<int, int>::iterator iter2;
    iter2 = dict2.lower_bound(0);
    for (map<int,int>::iterator  i = dict2.begin(); i != dict2.end(); i++)
    {
        if (i->first>iter2->first)
        {
            iter2 = i;
        }
    }
    // cout << iter2->first << " " << iter2->second << endl;
    for (iter = dict.begin(); iter != dict.end(); iter++)
    {
        if (iter->second == iter2->first && iter2->second == 1)
        {
            // printf("%s %d",iter->first,iter->second);
            cout << iter->first << " " << iter->second << endl;
            break;
        }
        if(iter->second == iter2->first && iter2->second!=1)
        {
            cout << iter->first << " " << iter->second << " " << iter2->second << endl;
            break;
            // printf("%s %d %d",iter->first,iter->second,iter2->second);
        }
    }
}
