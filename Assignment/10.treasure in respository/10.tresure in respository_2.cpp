#include<cstdio>
#include<algorithm>
using namespace std;
int li[1000010];

int main()
{
    int n,d,temp;
    float ans;
    bool odd;
    scanf("%d", &n);
    int sumca=0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &li[i]);
        sumca += li[i];
    }
    scanf("%d", &d);
    for (int i = 0; i < d; i++)
    {
        scanf("%d", &temp);
        while (true)
        {
            if (li[n-temp]!=0)
            {
                li[n - temp] -= 1;
                sumca -= 1;
                break;
            } else
            {
                temp += 1;
            }
        }
        int ans = 0;
        int odd = sumca % 2 == 0 ? 0 : 1;
        for (int i = 0; i < n; i++)
        {
            if (ans+li[i]>=sumca/2)
            {
                if (odd)
                {
                    printf("%.1f", (float)i + 1);
                } else
                {
                    printf("%.1f", (float)i + 3.0 / 2.0);
                }
                break;
            }
            ans += li[i];
        }
        
    }
    

}