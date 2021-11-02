#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n,temp1,temp2,ans;
    set<int> left;
    set<int> right;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &n);
        ans = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d %d", &temp1, &temp2);
            if (left.count(temp1)!=0&&right.count(temp2)!=0)
            {
                ans--;
            }
            if (left.count(temp1)!=0)
            {
                ans++;
                right.insert(temp2);
            }
            if (right.count(temp2)!=0)
            {
                ans++;
                left.insert(temp1);
            }
            if (left.count(temp1)==0 && right.count(temp2)==0)
            {
                left.insert(temp1);
                right.insert(temp2);
            }
        }
        printf("%d\n", ans);
        left.clear();
        right.clear();
    }
    
}