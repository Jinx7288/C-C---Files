#include<cstdio>
#include<algorithm>
using namespace std;
int li[100010]={0};
int findindex(int li[],int n,int no)
{
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        if (m+li[i]>=no)
        {
            // printf("%d\n", li[i]);
            return i+1;
        }
        m += li[i];
    }
    return 0;
}
int main()
{
    int n,d,temp,sum,odd,mid;
    // float ans;
    // int j = 0;
    sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &li[i]);
        sum += li[i];
    }
    if (sum%2==0)
        odd = 0;
    else
        odd = 1;
    scanf("%d", &d);
        // printf("%.1f", (float)(findindex(li, n, 1)));

    for (int i = 0; i < d; i++)
    {
        scanf("%d", &temp);
        while (true)
        {
            if (li[n-temp]!=0)
            {
                li[n - temp]-=1;
                sum -= 1;
                odd = odd == 0 ? 1 : 0;
                break;
            } else
            {
                temp += 1;
            }
        }
        mid = sum / 2;
        if(odd==0)
        {
            printf("%d\n",findindex(li, n, mid));
            printf("%d\n",findindex(li, n, mid+1));
            printf("%.1f", ((float)(findindex(li, n, mid) +(float)findindex(li, n, mid+1)))/2);
        }
        else
            printf("%.1f", (float)findindex(li,n,mid+1));
    }
}