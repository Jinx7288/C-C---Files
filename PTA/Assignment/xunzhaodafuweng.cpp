#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> li;
    int m, n,temp;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &temp);
        li.push_back(temp);
    }
    sort(li.begin(),li.end());
    vector<int>::iterator it=li.end();
    it--;
    for (int i = 0; i < n; i++)
    {
        if (i==n-1)
        {
            printf("%d\n", *it);
            it--;
        }else
        {
            printf("%d ", *it);
            it--;   
        }
    }
}