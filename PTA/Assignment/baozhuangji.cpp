#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<stdio.h>
using namespace std;
int main()
{
    int n, m, s,temp;
    char tempc;
    scanf("%d %d %d", &n, &m, &s);
    char tdl[n + 3][m + 3];
    int index[n + 3] = {0};
    scanf("%c", &tempc);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%c", &tdl[i][j]);
        }
        scanf("%c", &tempc);
    }
    stack<char> stk;
    for (int i = 0; ;i++)
    {
        scanf("%d", &temp);
        if (temp==-1)
        {
            break;
        }
        if (temp==0)
        {
            if (!stk.empty()) 
            {
                printf("%c", stk.top());
                stk.pop();
            }
            continue;
        } else
        {
            if (stk.size()==(long long unsigned)s)
            {
                printf("%c", stk.top());
                stk.pop();
            }
            if (index[temp]<m)
            {
                index[temp] += 1;
                stk.push(tdl[temp-1][index[temp]-1]);
            }
        }
    }
}