#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,less<int>> que;
int main()
{
    int n,temp;
    int ans = 0;
    int sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&temp);
        sum += temp;
        que.push(temp);
    }
    // printf("%d\n", ans);
    ans = sum;
    while(que.size()>2)
    {
        ans +=(sum-que.top());
        sum = sum - que.top();
        // printf("%d\n", ans);
        que.pop();
    }
    printf("%d\n", ans);
}