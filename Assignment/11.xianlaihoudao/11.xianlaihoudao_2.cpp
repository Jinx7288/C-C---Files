#include<cstdio>
#include<algorithm>
using namespace std;
int ca[100010]={0};
int ans[1010] = {0};
int main()
{
    int n, m,templ,tempr;
    scanf("%d %d", &n, &m);
    ca[0] = 0;
    ca[m] = 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &templ, &tempr);
        if (ca[templ-1]==0&&ca[tempr+1]==0)
        {
            ans[i] = 1;
            for (int i = templ; i < tempr; i++)
            {
                ca[i] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (ans[i]==1)
        {
            printf("ACCEPTED\n");
        } else
        {
            printf("REJECTED\n");
        }
    }
    
}