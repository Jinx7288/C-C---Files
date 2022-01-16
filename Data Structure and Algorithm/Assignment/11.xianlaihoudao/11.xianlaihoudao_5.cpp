#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    set<int> li;
    int temp1, temp2;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &temp1, &temp2);
        if (i==0)
        {
            for (int j = temp1; j <= temp2; j++)
            {
                li.insert(j);
            }
            printf("ACCEPTED\n");
        } else
        {
            set<int>::iterator it = li.lower_bound(temp1);
            if (it!=li.end()&&(*it)<=temp2)
            {
                printf("REJECTED\n");
            } else
            {
                printf("ACCEPTED\n");
                for (int j = temp1; j <= temp2; j++)
                {
                    li.insert(j);
                }
                
            }
            
            
        }
    }
    return 0;
}